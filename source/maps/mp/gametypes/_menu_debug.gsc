#include maps\mp\gametypes\global\_global;

// This is called only if developer_script is set to 1
init()
{
	addEventListener("onMenuResponse",  ::onMenuResponse);
}

/*
Called when command scriptmenuresponse is executed on client side
self is player that called scriptmenuresponse
Return true to indicate that menu response was handled in this function
*/
onMenuResponse(menu, response)
{
	if (self.pers["rcon_logged_in"])
	{
		self setClientCvar2("debug", 1);
	}
	else
	{
		self setClientCvar2("debug", 0);
	}


	if (response == "debug") {

		if (self.pers["rcon_logged_in"])
		{
			self closeMenu();
			self closeInGameMenu();
			self openMenu(game["menu_debugString"]);
		}
		else
			self iprintln("You need to log in before using debug menu.");
	}

	if (self.pers["rcon_logged_in"])
	{

		if(menu == game["menu_debugString"])
		{
			switch(response)
			{
			case "open":
				self thread menuOpened();
				break;
			case "close":
				self thread menuClosed();
				break;
			}
		}


		if (response == "end_round") {
			level thread maps\mp\gametypes\sd::endRound(self.pers["team"]);
		}
		if (response == "next_round") {
			level thread maps\mp\gametypes\sd::endRound(self.pers["team"]);
			map_restart(true);
		}
		if (response == "do_halftime") {
			game["roundsplayed"] = level.halfround-1;
			level thread maps\mp\gametypes\sd::endRound(self.pers["team"]);
		}
		if (response == "skip_readyup") {
			game["Do_Ready_up"] = 0;
			game["readyup_first_run"] = 0;
			level.in_readyup = 0;
			map_restart(true);
		}
		if (response == "overtime") {
			level thread maps\mp\gametypes\sd::endRound("draw");
			game["roundsplayed"] = level.matchround;
			game["allies_score"] = game["axis_score"];
			game["is_halftime"] = true;
		}
		if (response == "intermission")
		{
			level notify("round_ended");
			level.roundended = true;

			game["state"] = "intermission";
			level notify("intermission");

			// Spawn each player into intermission
			players = getentarray("player", "classname");
			for(i = 0; i < players.size; i++)
			{
				player = players[i];

				player closeMenu();
				player closeInGameMenu();

				player [[level.spawnIntermission]]();
			}
		}
	}
}

menuOpened()
{
    self notify("kill_debug");
    //wait level.frame;
    if (self.pers["rcon_logged_in"] || getCvar("debug") == "1")
    {
	    self thread debugBasics();
        //level thread debugCvars();
    }
}

menuClosed()
{

    self notify("kill_debug");
}


debugBasics()
{
	self endon("disconnect");
    self endon("kill_debug");

    //self waittill("spawned_player");


    for (i = 1; i <= 30; i++)
        self setClientCvar2("debug_line_"+i, " ");
    for (i = 1; i <= 30; i++)
        self setClientCvar2("debug_row_2_line_"+i, " ");






	while(1)
	{

		self setClientCvar2("debug_line_1", "self.name           = " + self.name);
		self setClientCvar2("debug_line_2", "self.sessionteam    = " + self.sessionteam);
		self setClientCvar2("debug_line_3", "self.sessionstate   = " + self.sessionstate);
		self setClientCvar2("debug_line_4", "self.health         = " + self.health);
		self setClientCvar2("debug_line_5", "isAlive(self)       = " + isAlive(self));

		origin = self getOrigin();
		self setClientCvar2("debug_line_7", "self.origin   = " + "["+origin[0]+", "+origin[1]+", "+origin[2]+"] ");
		angles = self getplayerangles();
		self setClientCvar2("debug_line_8", "self.angles   = " + "["+angles[0]+", "+angles[1]+", "+angles[2]+"] [pitch, yaw, roll]");

		head_pos = self.headTag getOrigin();
		self setClientCvar2("debug_line_9", "self.tag_head = " + "["+head_pos[0]+", "+head_pos[1]+", "+head_pos[2]+"]" + distance((0, 0, head_pos[2]), (0, 0, self.origin[2])));

		self setClientCvar2("debug_line_10", "self.isMoving   = " + self.isMoving + "  (diff: " + self.movingDifference + ")");




		self setClientCvar2("debug_line_18", "level.in_readyup      = " + level.in_readyup);
		self setClientCvar2("debug_line_19", "level.in_timeout      = " + level.in_timeout);
		self setClientCvar2("debug_line_20", "level.in_strattime    = " + level.in_strattime);

	        if (level.gametype == "sd")
	        {
	            	self setClientCvar2("debug_line_21", "level.roundstarted    = " + level.roundstarted);
	    		self setClientCvar2("debug_line_22", "level.roundended      = " + level.roundended);
	    		self setClientCvar2("debug_line_23", "level.bombplanted     = " + level.bombplanted);
	    		self setClientCvar2("debug_line_24", "level.bombexploded    = " + level.bombexploded);
	        }

		maps\mp\gametypes\_teamname::refreshTeamName("allies");
    		maps\mp\gametypes\_teamname::refreshTeamName("axis");
		maps\mp\gametypes\_teamname::refreshTeamName("");

		self setClientCvar2("debug_line_26", "allies name   = " + 		 level.teamname_allies);
		self setClientCvar2("debug_line_27", "axis name     = " + 		 level.teamname_axis);

		/*
		self setClientCvar2("debug_line_17", "allies_called_timeouts = " + game["allies_called_timeouts"]);
		self setClientCvar2("debug_line_18", "allies_called_timeouts_half = " + game["allies_called_timeouts_half"]);
		self setClientCvar2("debug_line_19", "axis_called_timeouts = " + game["axis_called_timeouts"]);
		self setClientCvar2("debug_line_20", "axis_called_timeouts_half = " + game["axis_called_timeouts_half"]);

		self setClientCvar2("debug_line_21", "timeout_called_team = " + game["timeout_called_team"]);
*/

		self setClientCvar2("debug_row_2_line_1", "getWeaponSlotWeapon(primary)   = " + 	 self getWeaponSlotWeapon("primary"));
		self setClientCvar2("debug_row_2_line_2", "getWeaponSlotWeapon(primaryb)  = " + 	 self getWeaponSlotWeapon("primaryb"));
		self setClientCvar2("debug_row_2_line_3", "getCurrentWeapon()             = " + 	 self getCurrentWeapon());



        weapon = self getCurrentWeapon();
        class = "?";
        limit = "?";
        allies_limited = "?";
        axis_limited = "?";
        if (isDefined(level.weapons[weapon]))
        {
            class = level.weapons[weapon].classname;
            limit = level.weaponclass[class].limit;
            allies_limited = level.weaponclass[class].allies_limited;
            axis_limited = level.weaponclass[class].axis_limited;
        }

        self setClientCvar2("debug_row_2_line_5", "class             = " + 	 class);
        self setClientCvar2("debug_row_2_line_6", "limit             = " + 	 limit + " / per team");
        self setClientCvar2("debug_row_2_line_7", "axis_limited      = " + 	 allies_limited);
        self setClientCvar2("debug_row_2_line_8", "allies_limited    = " + 	 axis_limited);


		//spawnweapon = "?";
		//if (isDefined(self.pers["spawnweapon"])) spawnweapon = self.pers["spawnweapon"];
		weapon = "?";
		if (isDefined(self.pers["weapon"])) weapon = self.pers["weapon"];
		weapon1 = "?";
		if (isDefined(self.pers["weapon1"])) weapon1 = self.pers["weapon1"];
		weapon2 = "?";
		if (isDefined(self.pers["weapon2"])) weapon2 = self.pers["weapon2"];


		//self setClientCvar2("debug_row_2_line_10", "self.pers[spawnweapon]  = " + spawnweapon);
		self setClientCvar2("debug_row_2_line_11", "self.pers[weapon]       = " + weapon);
		self setClientCvar2("debug_row_2_line_12", "self.pers[weapon1]      = " + weapon1);
		self setClientCvar2("debug_row_2_line_13", "self.pers[weapon2]      = " + weapon2);


		self setClientCvar2("debug_row_2_line_15", "self.dropped_weapons   = " + 		 self.dropped_weapons);
        self setClientCvar2("debug_row_2_line_16", "self.taked_weapons     = " + 		 self.taked_weapons);



        self setClientCvar2("debug_row_2_line_21", "HUD getArchivedCount       = " + 	self maps\mp\gametypes\global\hud_system::getArchivedCount());
        self setClientCvar2("debug_row_2_line_22", "HUD getNonArchivedCount    = " + 	self maps\mp\gametypes\global\hud_system::getNonArchivedCount());

	self setClientCvar2("debug_row_2_line_24", "self attackbuttonpressed()       = " + 	self attackbuttonpressed());
	self setClientCvar2("debug_row_2_line_25", "self isOnGround()                = " + 	self isOnGround());
	self setClientCvar2("debug_row_2_line_26", "self playerAds()                 = " + 	self playerAds());

        //self setClientCvar2("debug_row_2_line_14", "self.dropped_weapons   = " + 		 self.dropped_weapons);




		wait level.frame;
	}

}


debugCvars()
{

	for(i = 0; i < game["cvarnames"].size; i++)
	{
		cvar = game["cvars"][game["cvarnames"][i]]; // array

		color = "";
		if (cvar["value"] != cvar["defaultValue"])
			color = "*CHANGED* ";

        min = "?";
        if (isDefined(cvar["minValue"]) && isString(cvar["minValue"]))
            min = cvar["minValue"];

        max = "?";
        if (isDefined(cvar["maxValue"]) && isString(cvar["maxValue"]))
            max = cvar["maxValue"];

		println(color + cvar["name"] + " = " + cvar["value"] + "   (d:" + cvar["defaultValue"] + ", <" + min + "; " + max + ">)");


    }

}
