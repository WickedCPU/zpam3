#include maps\mp\gametypes\_callbacksetup;

Init()
{
	addEventListener("onConnected",     ::onConnected);
}

onConnected()
{
	if (!level.scr_diagonal_fix)
		return;

	self thread PreprareForFix();
}

// Called if cvar scr_diagonal_fix changes
cvarChanged()
{
		if (level.scr_diagonal_fix) // changed to 1
		{
				players = getentarray("player", "classname");
				for(i = 0; i < players.size; i++)
				{
						player = players[i];
						player onConnected();
				}
		}
}

reduceAngle(angle)
{
	while (angle >= 360) 	angle -= 360;
	while (angle < 0) 		angle += 360;

	return angle;
}

// Is also called on every player if cvar is changed in middle of game
PreprareForFix()
{
	self endon("disconnect");

	// In case player was doing diagonal right before map restart
	// leaning is disabled in next round, so we need to restore it
	// This cannot be called every time new round started, becase this can cancel writing to chat
	// We need to call this only if player is in movement

	// If player is not alive, wait
	while (!isAlive(self))
		wait level.fps_multiplier * 1;

	origin = self getOrigin();
	origin_old = origin;

	for (;;)
	{
		wait level.fps_multiplier * .1;

		origin = self getOrigin();

		dist = distance(origin, origin_old);

		if (dist > 1.0)
		{
			// Enable leaning in case leaning was disabled right before map restart
			self enableLeaning();

			// Run thread on player to avoid diagonal
			self thread diagonalFix();

			return;
		}

		origin_old = origin;
	}
}

diagonalFix()
{
	self endon("disconnect");

	origin = self getOrigin();
	origin_old = origin;
	time_in_movement = 0.0;
	leanBlocked = false;

	for (;;)
	{
		// Update every frame
		wait level.frame;

		// If player is not alive, wait more
		while (!isAlive(self))
			wait level.fps_multiplier * 1;

		// If diagonal was disabled via cvar
		if (!level.scr_diagonal_fix)
		{
			self enableLeaning();
			return;
		}

		// Get if player is moving forward + left/right + in ads
		origin = self getOrigin();
		inDiagonalMoving = self isDiagonalMovement(origin, origin_old);
		origin_old = origin;

		// Count how long player is moving that way
		if (inDiagonalMoving)
			time_in_movement += level.frame;
		else
			time_in_movement = 0;

		// Wait until we are 200ms in movement
		if (time_in_movement > level.fps_multiplier * 0.2)
		{
			// Block leaning left/right to avoid diagonal bug
			if (!leanBlocked)
				self disableLeaning();

			leanBlocked = true;
		}
		else
		{
			// Restore leaning
			if (leanBlocked)
				self enableLeaning();

			leanBlocked = false;
		}

	}
}

disableLeaning()
{
	/# self iprintln("^1Block diagonal!"); #/

	// Exec command on client side
	// If some menu is already opened:
	//	- by player (by ESC command) -> it will work well over already opened menu
	//  - by script (via openMenu()) -> that menu will be closed and exec_cmd will not be closed correctly
	//			(mouse will be visible with clear backgorund.... so closeMenu() is called to close that menu)
	self setClientCvar("exec_cmd", "+leanleft; +leanright");
	self openMenu(game["menu_exec_cmd"]);		// open menu via script
	self closeMenu();							// will only close menu opened by script
}

enableLeaning()
{
	/# self iprintln("^2 Diagonal ok"); #/

	// Exec command on client side
	// If some menu is already opened:
	//	- by player (by ESC command) -> it will work well over already opened menu
	//  - by script (via openMenu()) -> that menu will be closed and exec_cmd will not be closed correctly
	//			(mouse will be visible with clear backgorund.... so closeMenu() is called to close that menu)
	self setClientCvar("exec_cmd", "-leanleft; -leanright");
	self openMenu(game["menu_exec_cmd"]);		// open menu via script
	self closeMenu();							// will only close menu opened by script
}


isDiagonalMovement(origin, origin_old)
{
	// Must be in team, alive and on ground
	if (!((self.pers["team"] == "allies" || self.pers["team"] == "axis") && isAlive(self)) || !self isOnGround())
		return false;

	// Determine if player is moving based on last position and actual position
	dist = distance(origin, origin_old);
	// Distance examples:
	// Stand + forward + left/right + ads = 2-3
	// Crouch + forward + left/right + ads = 1-2

	if (dist < 1.5)
		return false;

	// Get direction angles
	movementAngle = vectorToAngles(origin - origin_old);

	// Compute angle of movement
	angles = self getplayerangles();	// yaw: left
	selfYaw = reduceAngle(angles[1]);				// <-180 ; 180>
	movementYaw = reduceAngle(movementAngle[1]);	//<0; 360>
	yawMovementDiff = reduceAngle(movementYaw - selfYaw);
/*					0 FORWARD
								|
								|
				LEFT		|		  RIGHT
		90----------|------------270  -90
								|
								|
								|
				   180 BACKWARD
	*/

	isMovingForwardLeft = ((yawMovementDiff >= 30 && yawMovementDiff < 65));
	isMovingForwardRight = ((yawMovementDiff >= 295 && yawMovementDiff < 330));

	if (!isMovingForwardLeft && !isMovingForwardRight)
		return false;

	// Not in zoom
	if(self playerAds() < 0.1)
		return false;

	return true;
}
