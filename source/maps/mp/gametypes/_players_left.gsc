#include maps\mp\gametypes\global\_global;

init()
{
	addEventListener("onCvarChanged", ::onCvarChanged);

	registerCvar("scr_show_players_left", "BOOL", 1);	    // level.scr_show_players_left // NOTE: after reset

	if(game["firstInit"])
	{
		precacheString2("STRING_ALLIES_LEFT", &"Allies Left");
		precacheString2("STRING_AXIS_LEFT", &"Axis Left");

		precacheString2("STRING_ALLIES_ELIMINATED", &"Allies Eliminated");
		precacheString2("STRING_AXIS_ELIMINATED", &"Axis Eliminated");
	}


	addEventListener("onConnected",             ::onConnected);

	if (!level.scr_show_players_left)
		return;

	level.axis_alive = -1;
	level.allies_alive = -1;

	level.allies_names = [];
	level.axis_names = [];

	level.player_alive_history = "";


	// Updating score:
	addEventListener("onDisconnect",            ::onDisconnect);
	addEventListener("onPlayerKilled",          ::onPlayerKilled);
	addEventListener("onSpawned",               ::onSpawned);
	addEventListener("onJoinedTeam",    ::onJoinedTeam);
}

// This function is called when cvar changes value.
// Is also called when cvar is registered
// Return true if cvar was handled here, otherwise false
onCvarChanged(cvar, value, isRegisterTime)
{
	switch(cvar)
	{
		case "scr_show_players_left": 		level.scr_show_players_left = value; return true;
	}
	return false;
}

onConnected()
{
	if (level.scr_show_players_left)
	{
		self thread createHUD();

		// Enable player list by default, can be overwritten by player settings
		self.pers["playersleft_list"] = true;
	}
	else
		self hide(); // hide is set from previous map
}

onDisconnect()
{
	level thread updatePlayersCount();
}

onPlayerKilled(eInflictor, attacker, iDamage, sMeansOfDeath, sWeapon, vDir, sHitLoc, psOffsetTime, deathAnimDuration)
{
	level thread updatePlayersCount();
}

onSpawned()
{
	level thread updatePlayersCount();
}

onJoinedTeam(teamName)
{
	self updateEnemyList();
}



createHUD()
{
	self endon("disconnect");

	// X coorinate is due to text chanigng references on multiple places
	level.playersLeft_myTeam_X = -275;
	level.playersLeft_enemy_X = -185;

	self.playersLeft_myTeam_num = addHUDClient(self, -280, 479, 1.3, undefined, "right", "bottom", "right");
	self.playersLeft_myTeam = addHUDClient(self, level.playersLeft_myTeam_X, 479, 1.2, undefined, "left", "bottom", "right");

	self.playersLeft_enemy_num = addHUDClient(self, -190, 479, 1.3, undefined, "right", "bottom", "right");
	self.playersLeft_enemy = addHUDClient(self, level.playersLeft_enemy_X, 479, 1.2, undefined, "left", "bottom", "right");

	self.playersLeft_myTeam_num.archived = false;
	self.playersLeft_myTeam.archived = false;
	self.playersLeft_enemy_num.archived = false;
	self.playersLeft_enemy.archived = false;
}


updatePlayersCount()
{
	// This will make sure this function is called only once in single frame
	level notify("playersleft_update");
	level endon("playersleft_update");

	wait level.frame; // wait a frame to process a player disconnection

	allies_alive = 0;
	axis_alive = 0;

	allies_names = [];
	axis_names = [];

	players = getentarray("player", "classname");
	for(i = 0; i < players.size; i++)
	{
		player = players[i];

		if(player.sessionstate == "playing")
		{
			if(player.pers["team"] == "allies")
			{
				allies_alive++;
				allies_names[allies_names.size] = player;
			}
			else if(player.pers["team"] == "axis")
			{
				axis_alive++;
				axis_names[axis_names.size] = player;
			}
		}
	}

	alliesChanged = allies_alive != level.allies_alive;
	axisChanged = axis_alive != level.axis_alive;

	alliesKills = level.allies_alive - allies_alive;
	axisKills = level.axis_alive - axis_alive;

	level.axis_alive = axis_alive;
	level.allies_alive = allies_alive;

	level.allies_names = allies_names;
	level.axis_names = axis_names;

	if (alliesChanged || axisChanged)
	{
		// Update HUD to all players
		for(i = 0; i < players.size; i++)
		{
			player = players[i];
			player thread updateHUD(alliesChanged, axisChanged);

			player thread updateEnemyList();
		}
	}

	// Update history for spectators
	if (alliesKills != 0 || axisKills != 0)
	{
		level.player_alive_history += "  " + allies_alive + "v" + axis_alive;
	}
}


updateHUD(alliesChanged, axisChanged)
{
	self endon("disconnect");


	teamLeft = "allies";
	teamRight = "axis";

	// If match info is enabled, ensure teams are in correct sides
	if (self.pers["team"] == "spectator")
	{
		if (game["scr_matchinfo"] == 1 || game["scr_matchinfo"] == 2)
		{
			if (game["match_team1_side"] == "axis")
			{
				teamLeft = "axis";
				teamRight = "allies";
			}
		}
	}
	else if (self.pers["team"] == "axis")
	{
		teamLeft = "axis";
		teamRight = "allies";
	}



	if (teamLeft == "axis")
	{
		if (level.axis_alive > 0)
		{
			self.playersLeft_myTeam.alignX = "left";
			self.playersLeft_myTeam setText(game["STRING_AXIS_LEFT"]);
			self.playersLeft_myTeam_num.alpha = 1;
		}
		else
		{
			self.playersLeft_myTeam.alignX = "center";
			self.playersLeft_myTeam setText(game["STRING_AXIS_ELIMINATED"]);
			self.playersLeft_myTeam_num.alpha = 0;
		}

		if (level.allies_alive > 0)
		{
			self.playersLeft_enemy setText(game["STRING_ALLIES_LEFT"]);
			self.playersLeft_enemy_num.alpha = 1;
			self.playersLeft_enemy.x = level.playersLeft_enemy_X;
		}
		else
		{
			self.playersLeft_enemy setText(game["STRING_ALLIES_ELIMINATED"]);
			self.playersLeft_enemy_num.alpha = 0;
			self.playersLeft_enemy.x = level.playersLeft_enemy_X - 20;
		}

		self.playersLeft_myTeam_num setValue(level.axis_alive);
		self.playersLeft_enemy_num setValue(level.allies_alive);

		// Bounce animation
		if (alliesChanged && self.pers["team"] == "axis")
		{
			self thread doBounceAnimation(self.playersLeft_enemy_num);
			if (level.allies_alive == 0)
				self thread doBounceAnimation(self.playersLeft_enemy);
		}
	}
	else // allies on left
	{
		if (level.allies_alive > 0)
		{
			self.playersLeft_myTeam.alignX = "left";
			self.playersLeft_myTeam setText(game["STRING_ALLIES_LEFT"]);
			self.playersLeft_myTeam_num.alpha = 1;
		}
		else
		{
			self.playersLeft_myTeam.alignX = "center";
			self.playersLeft_myTeam setText(game["STRING_ALLIES_ELIMINATED"]);
			self.playersLeft_myTeam_num.alpha = 0;
		}

		if (level.axis_alive > 0)
		{
			self.playersLeft_enemy setText(game["STRING_AXIS_LEFT"]);
			self.playersLeft_enemy_num.alpha = 1;
			self.playersLeft_enemy.x = level.playersLeft_enemy_X;
		}
		else
		{
			self.playersLeft_enemy setText(game["STRING_AXIS_ELIMINATED"]);
			self.playersLeft_enemy_num.alpha = 0;
			self.playersLeft_enemy.x = level.playersLeft_enemy_X - 20;
		}

		self.playersLeft_myTeam_num setValue(level.allies_alive);
		self.playersLeft_enemy_num setValue(level.axis_alive);

		// Bounce animation
		if (axisChanged && self.pers["team"] == "allies")
		{
			self thread doBounceAnimation(self.playersLeft_enemy_num);
			if (level.axis_alive == 0)
				self thread doBounceAnimation(self.playersLeft_enemy);
		}
	}

	if (self.pers["team"] == "spectator")
	{
		self.playersLeft_myTeam.color = (1,1,1);
		self.playersLeft_myTeam_num.color = (1,1,1);
		self.playersLeft_enemy.color = (1,1,1);
		self.playersLeft_enemy_num.color = (1,1,1);
	}
	else
	{
		self.playersLeft_myTeam.color = (.580,.961,.573);
		self.playersLeft_myTeam_num.color = (.580,.961,.573);
		self.playersLeft_enemy.color = (.055,.855,.996);
		self.playersLeft_enemy_num.color = (.055,.855,.996);
	}
}


doBounceAnimation(element)
{
	self endon("disconnect");

	if (isDefined(element.inBounce))
		return;

	// Up down animation
	element moveovertime(0.1);
	element.y = 469;
	element.inBounce = true;

	wait level.fps_multiplier * 0.12222;

	element moveovertime(0.2);
	element.y = 479;
	element.inBounce = undefined;

}







isEnabled()
{
	return isDefined(self.pers["playersleft_list"]) && self.pers["playersleft_list"];
}

enable()
{
	self.pers["playersleft_list"] = true;
	if (level.scr_show_players_left)
		self show();
}

disable()
{
	self.pers["playersleft_list"] = false;
	if (level.scr_show_players_left)
		self hide();
}

toggle()
{
	if (isEnabled())
		self disable();
	else
		self enable();
}

// Show hud element
show()
{
	updateEnemyList();
}
// Hide hud element
hide()
{
	updateEnemyList();
}







// Called also from scoreboard menu
updateEnemyList()
{
	//self iprintln("updating...");
	if (game["is_public_mode"] || !level.scr_show_players_left || self isEnabled() == false)
	{
		self setClientCvarIfChanged("ui_playersleft_list", "");
		return;
	}


	str = "";

	if (self.pers["team"] == "allies" || self.pers["team"] == "axis")
	{
		playerList = level.allies_names;
		if (self.pers["team"] == "allies")
			playerList = level.axis_names;

		nameList = [];
		for(i = 0; i < playerList.size; i++)
		{
			if (!isDefined(playerList[i])) // player disconnects
				continue;

			// Add color according to selected color via scoreboard menu
			name = "";
			if (isDefined(playerList[i].pers["scoreboard_color"]))
			{
				if (playerList[i].pers["scoreboard_color"] == 1)
					name += "^1"; // red
				else if (playerList[i].pers["scoreboard_color"] == 2)
					name += "^4"; // blue
			}

			name += removeColorsFromString(playerList[i].name);

			nameList[nameList.size] = name;
		}

		maxSize = 0;
		for(i = 0; i < nameList.size; i++)
		{
			if (nameList[i].size > maxSize)
				maxSize = nameList[i].size;
		}

		for(i = 0; i < nameList.size; i++)
		{
			// Move to right is player names are too long
			if (maxSize < 20)
				str+= "      ";
			if (maxSize < 26)
				str+= "        ";
			str+= "       ";

			str += nameList[i] + "\n^7";
		}

		// Align text to bottom
		for (i = nameList.size; i <= 6; i++)
			str = "\n" + str;
	}

	self setClientCvarIfChanged("ui_playersleft_list", str);
}
