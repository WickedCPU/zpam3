# New zPAM3.1

Mod zPAM3.1 is new version of PAM mode for COD2.
It is based on latest zPAM2.07 version and implements new features and bug fixes.

Work on this pam was iniciated by me in 2015 a was not never fully finished. Now in corona days i decided to finish it.

<br>

## Main changes
* Clip / Prone-peak bug fixed
* Double kills fixed
* Fast-reload shot bug fixed
* Missing textures fixed
* Shotgun rebalance
* Auto demo recording
* Auto overtime mode for MR12
* New functions for STRAT mode (bots, path recording)
* Adjustable vertical / horizontal sensitivity
* GUI improvements (menu, hud)
* Ability to change map / pam_mode / kick player directly from menu
* <del>Diagonal bug fix</del> (canceled - the way it was fixed does not like most of the people)
* <del>Changable FOV</del> (canceled - too big change)

*And much more - see full list down below*

<br>

## Installation
### zPAM3.1 BETA
In order to sucessfully install pam on your server, follow this steps:
- Download and copy files <b>zpam310_beta.iwd</b> and <b>pbsvuser.cfg</b> into following locations:</b>
    - COD2\zpam310_beta\zpam310_beta.iwd
    - COD2\pb\pbsvuser.cfg

<br>

## Bug report
Do you know about some bugs that are not mentioned here?

Write message on discord <b>CyberGamer Europe</b> in <b>#cod2-zpam-3</b> channel.<br>
Or add me on discord <b>eyza#7930</b>
Or write me on email <b>kratas.tom@seznam.cz</b>

<br>

## List of changes

### 1. Fixed game bugs
<sub>
[1.1] Clip fix / Prone-peak fix<br>
<a href="/images/clip.gif"><img src="/images/clip.gif" height="130" /></a><br>
[1.2] Texture fixes (adding xmodel)<br>
<a href="/images/toujane_jump.jpg"><img src="/images/toujane_jump.jpg" height="130" /></a><br>
<a href="/images/toujane_axis_roof.jpg"><img src="/images/toujane_axis_roof.jpg" height="130" /></a><br><br>
<a href="/images/toujane_jump_2.jpg"><img src="/images/toujane_jump_2.jpg" height="130" /></a><br>
<a href="/images/toujane_allies_window.jpg"><img src="/images/toujane_allies_window.jpg" height="130" /></a><br><br>
<a href="/images/carentan_stairs_1.jpg"><img src="/images/carentan_stairs_1.jpg" height="130" /></a><br>
<a href="/images/carentan_stairs_2.jpg"><img src="/images/carentan_stairs_2.jpg" height="130" /></a><br><br>
[1.3] Collision box / killtrigger<br>
<a href="/images/burgundy_jump.jpg"><img src="/images/burgundy_jump.jpg" height="130" /></a><br>
<a href="/images/dawnville_jump.jpg"><img src="/images/dawnville_jump.jpg" height="130" /></a><br>
[1.4] Fast reload bug (when you fire, press R to reload and then you scroll down 2x, you are able to shoot faster) -&gt; fixed<br>
[1.5] Bind to stop actually playing sound -&gt; fixed
</sub>

### 2. Fixed script bugs
#### 2.1 Weapons (complete weapon system rewrited)
<sub>
[2.1.1] limited weapons (sniper, shotgun) can be picked up by another player and can be saved to next round -&gt; fixed<br>
[2.1.2] if you change weapon for example from mp_44 to kar98 in starttime, you are not able to pickup mp_44 from ground until round ends -&gt; fixed<br>
[2.1.3] if limited weapon is selected, for all other players it is not correctly indicated in menu -&gt; fixed<br>
[2.1.4] weapon is dropped if player change a team in start time (can be exploited if player change team to spectator and back during strattime) -&gt; fixed<br>
[2.1.5] when player kills somebody with grenade while he is using MG - shows MG icon instead of grenade in killfeed-&gt; fixed<br>
[2.1.6] if player is killed while he cooks grenade/smoke, cooked grenade/smoke is throwed and second grenade/smoke is dropped to ground -&gt; fixed
</sub>

#### 2.2 Timeout
<sub>
[2.2.1] when timeout is canceled, player can not use quickmessages anymore until round/map ends -&gt; fixed<br>
[2.2.2] in sd, timeout is executed at the end of the round with no ability to walk -&gt; fixed, timeout is now executed always at the start of the new round
</sub><br>

#### 2.3 Other
<sub>
[2.3.1] in sd, when last player dies, all players in defeated team are in spectator mode, but they can not move -&gt; fixed<br>
[2.3.2] when max team limit is reached and other player disconnect, other players was unable to select team -&gt; fixed<br>
[2.3.3] fixed bash pam mode (only pistols are allowed, disabled planting)<br>
[2.3.4] a lot of code rewrited, removed unnessesary things (splitscreen, xbox codes, ...)<br>
</sub>


### 3. Improvements already done
#### 3.1 Ready-up
<sub>
[3.1.1] added ability to stop killing in readyup mode<br>
[3.1.2] if you change weapon in readyup mode, you will not get new grenades (only if you die)<br>
[3.1.3] ready-up now starts when there is atleast one player (useful when you need to test something on server alone)<br>
[3.1.4] no team limit for teams in ready-up mode (you can select whatever team you want in readyup mode)<br>
[3.1.5] when you are in spectator and you are following some player, now you can see really "Your status" instead of followed player status<br>
[3.1.6] added voice sound when all players are ready in readyup / halftime / timeout<br>
</sub>

#### 3.2 Weapons
<sub>
[3.2.1] primary weapon can be dropped if you have 2 main weapons (except limited weapons, like scopes) <br>
[3.2.2] recoded system for saving weapons at the end of the round - now its not exploitable<br>
[3.2.3] improved weapon menu - selected weapon is highlighted, used weapons are grayed out correctly, number of grenades under weapon image shows correctly, + added text who is using limited weapon <br>
    <a href="/images/gui_weapon.jpg"><img src="/images/gui_weapon.jpg" height="200" /></a>
</sub>

#### 3.3 New stuff
<sub>
[3.3.1] double kills - you are now able to shot thru players<br>
[3.3.2] added demo recording functionality <br>
<del>- when match is starting, text "Hold F to start recording a demo" is shown - when player holds F, demo start recording in format "XvX_map_team1_team2__ID.dm_1"</del><br>
    - demo starts recording automatically after ready-up is over + is recorded again every map (in format XvX_map_team1_team2__ID.dm_1)<br>
[3.3.3] added <del>"Kill me"</del> (removed) and "Start recording" to quick-messages<br>
[3.3.4] some new cvar forces, like dx9 shadows forced off, duplicate packet forced off, ...<br>
[3.3.5] abillity to spawn bot in strat mode<br>
[3.3.6] <del>abillity to change FOV (filed-of-view)</del> <strong>(canceled)</strong><br>
[3.3.7] add new info to scoreboard at the end of the round (how long you are playing + rounds to halftime)<br>
[3.3.8] <del>show weapon instead of headshot in killfeed in match pam mode</del> <strong>(removed)</strong><br>
[3.3.9] Shotgun rebalance - long shots and close range hits are balanced by new system of counting damage<br>
    <a href="/images/shotgun.png"> <img src="/images/shotgun.png" alt="" height="1000" /> </a><br><br>
[3.3.10] Match info - menu with information about team names, score, scores in halfs, total played time, ...<br>
    <a href="/images/matchinfo.jpg"> <img src="/images/matchinfo.jpg" alt="" height="200" /> </a><br>
[3.3.11] Match info server cvars - basic information like team names, scores, round can be showed via HLSW for example<br>
    <a href="/images/matchinfo_hlsw.jpg"> <img src="/images/matchinfo_hlsw.jpg" alt="" height="150" /> </a><br>
</sub>

#### 3.4 Other
<sub>
[3.4.1] <del>New LOD force - all models are rendered in high details (this fixes ussues that enemy can be spotted behind tank from far distances, or bucket on toujane is not visible from far distance)<br>
    <a href="/images/lod.gif"><img src="/images/lod.gif" height="200" /></a>
    <a href="/images/toujane_bucket.jpg"><img src="/images/toujane_bucket.jpg" height="200" /></a><br>
    (this may be applyed only for toujane)</del><br>
    <b>Canceled - this caused significant FPS drops on some spots</b><br><br>
[3.4.2] New bomb explosion radius + fixed explosion effect <br>
  <img src="/images/bomb_damage.jpg" alt="" width="345" height="198" /><br>
[3.4.3] when bomb explodes and kills someone, kill is assigned to planter<br>
[3.4.4] fixed bug when grenade icon is not visible in scope zoom - it depends on "cg_hudGrenadeIconInScope" - so now pam force value of this cvar to "1"<br>
[3.4.5] in overtime mode (for mr3, mr10, mr12, mr15 modes) - if match ends with draw, teams are automaticly switched over and over untill one team wins <br>
[3.4.6] when team is changed, team is changed immediately (before - team was changed after weapon choose)<br>
[3.4.7] all hud text are animated (small fadein and fadeout translations) and adapted to widescreen ratio<br>
[3.4.8] when you connect to match in progress, there is image of map in background - so player can not see anything and also is spawned outside map, so he can not hear anything (inspiration from COD4)<br>
    <a href="/images/blackout.jpg"><img src="/images/blackout.jpg" height="200" /></a><br>
[3.4.9] Added check if player has downloaded mod (mod needs to be downloaded or bug fixes described above will not work) <br>
    <a href="/images/mod_download.jpg"><img src="/images/mod_download.jpg" height="200" /></a><br>
[3.4.10] Added check to "fs_game" if pam is installed correctly (if all servers with new pam will be installed in same folder, players will not have to downloading mod again on other servers)<br>
[3.4.11] Added new cvar system - all cvars (sv_, g_, scr_) are monitored against change (not all cvars was monitored in old pam) + added warning in readyup if cvars are not equal to league rules<br>
[3.4.12] Removed anoying music at the and of the map<br>
[3.4.13] Removed anoying music from main menu<br>
</sub>

### 4. IDEAS
<sub>
[4.1] player / server options (player settings, all rcon commands, new commands like set/reset score, move player to team, ...) <strong>(in-progress)</strong> <br>
    <a href="/images/gui_player_server_options.jpg"> <img src="/images/gui_player_server_options.jpg" alt="" height="200" /></a><br>
[4.2] add more info in shoutcaster mode (weapon, grenades..., like in CS:GO) (+ keybindings for players, map overview)  <br>
[4.3] new binds for taking weapon class -&gt; like when the bind is pressed, player gets Thompson, MP44, or PPSh based on actual team&nbsp;<br>  
[4.4] increase sv_fps? <br>
[4.5] remove quickmessages (like "Follow me", "Move in!") in match pam mode  <br>
[4.6] remove "Explosives planted" voice sound for planter (just for planter, retain for rest of team) to avoid ninja defuse <a href="https://www.youtube.com/watch?v=SfRdlWHzUWQ"> https://www.youtube.com/watch?v=SfRdlWHzUWQ </a>&nbsp; <br>
[4.7] suggestion to drop smoke instead of nade if sg gets killed before smoke was used  <br>
[4.8] get Russians back with modified ppsh <br>
[4.9] Spectator - keep following player from previsous round in new round (in current pam when new round started, spectator is moved to default position even if he was following some player...)<br>
</sub>


### 5. KNOWN BUGS
<sub>
[5.1] Slide bug (when player hits the ground he can not stop moving. It looks like he is "sliding" on the ground) <br>
[5.2] Defusing with F12 (player can defuse outside plant area when screenshot bind and F is pressed at one time) <br>
[5.3] Smoke is not visible if player press F12 or game window is minimized <br>
[5.4] When some player plays with BAR weapon, all other players can hearing sounds of changing weapon on their side (happends when player with BAR is switching between BAR and pistol) <br>
[5.5] When player is defusing and he use binoculars - its seems like he is not defunsing and zooming with weapon (but weapon is not visible) <br>
[5.6] bind MOUSE1 "+attack;+smoke" -&gt; this bind silences gun<br>
[5.7] toujane bug - you get stuck in "link" if you crouch next to the wall  <br>
    <a href="/images/toujane_cigan.jpg"> <img src="/images/toujane_cigan.jpg" alt="" height="150" /> </a><br>
[5.8] Carentan MG house at doors. Prone push  <br>
    <a href="/images/carentan_mg_house_bug1.jpg"> <img src="/images/carentan_mg_house_bug1.jpg" alt="" height="150" /> </a> <br>
    <a href="/images/carentan_mg_house_bug2.jpg"> <img src="/images/carentan_mg_house_bug2.jpg" alt="" height="150" /> </a><br>
[5.9] Dawnville: Bug in last apartment <br>
    <a href="/images/dawnville_apartment_bug.jpg"> <img src="/images/dawnville_apartment_bug.jpg" alt="" height="150" /> </a><br>
[5.10] too hight mg sensitivity <br>
[5.11] switching from scope to other player while dead, you keep hearing the "scopeshot" <br>
[5.12] r_picmip can be abused, find a way to make sure picmip 3 cant be used <br>
[5.13] Carentan: make sure people cant jump on the B bombsite from sandbags with 333fps or from boxhouse.<br>
[5.14] Carentan: complaining about a bug behind the B bomb, the fences are bugged while scoping<br>
[5.15] MG clip bug - if you prone behind MG and press F to take it, enemy see you with a delay<br>
[5.16] You cannot hear sounds of players that are far away from you. In some spots you cannot hear sounds of players just around a corner. This is caused by map portals - every map is split up to portals. Only portals that you can see from your location are rendered by game engine. Unforcenetly players are also not rendered. Thats why you cannot hear your teammate shooting on A bombsite while you are on allies spawn for example.<br>
[5.17] Bash bug - you cannot bust while reload animation (untill weapon chamber is not fully refilled -> bash is blocked)<br>
[5.18] Burgundy low sky box - grenades are removed from game if you throw them above you with jump<br>
[5.19] Matmata jungle texture bug <br>
    <a href="/images/matmata_bug_1.jpg"><img src="/images/matmata_bug_1.jpg" alt="" height="150" /> </a>
    <a href="/images/matmata_bug_2.jpg"><img src="/images/matmata_bug_2.jpg" alt="" height="150" /> </a><br>
[5.20] Tanks - some tanks dont have solid tank wheels - shots go throught them
 </sub>
