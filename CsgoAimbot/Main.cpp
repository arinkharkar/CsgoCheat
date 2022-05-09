#include <math.h>
#include <windows.h>
#include <iostream>
#include <wininet.h> 
#include <iostream>
#include <vector>

#include "Player.h"
#include "Offsets.h"
#include "Aimbot.h"
#include "Wallhack.h"
#include "data.h"
#include "Memory.h"
#include "ClanTagChanger.h"
#include "Antiflash.h"
#include "SkinChanger.h"
#include "Bunnyhop.h"

int __main();

BOOL WINAPI ConsoleHandler(DWORD CEvent)
{
	if (CEvent == CTRL_CLOSE_EVENT)
	{
		/* When the program ends, reset the antiflash */
		Antiflash(255.f);
	}
	return TRUE;
}


int howManyProc(const char* processName)
{
	int counter = 0;
	PROCESSENTRY32 entry;
	entry.dwSize = sizeof(PROCESSENTRY32);

	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

	if (Process32First(snapshot, &entry))
		while (Process32Next(snapshot, &entry))
			if (!strcmp(entry.szExeFile, processName)) {
				counter++;
			}
				

	CloseHandle(snapshot);
	return counter;
}


int main() {
	/*std::string s = "_firesmoke _plasma ai_ally_speech_manager ai_battle_line ai_changehintgroup ai_changetarget ai_goal_assault ai_goal_fightfromcover ai_goal_follow ai_goal_lead ai_goal_lead_weapon ai_goal_standoff ai_hint ai_network ai_script_conditions ai_sound ai_speechfilter aiscripted_schedule aitesthull ambient_generic ammo_338mag ammo_357sig ammo_45acp ammo_50ae ammo_556mm ammo_556mm_box ammo_57mm ammo_762mm ammo_9mm ammo_buckshot assault_assaultpoint assault_rallypoint baseprojectile beam beam_spotlight chicken color_correction color_correction_volume commentary_auto cs_bot cs_gamerules cs_player_manager cs_ragdoll cs_team_manager cycler cycler_actor cycler_blender cycler_flex cycler_weapon cycler_wreckage decoy_projectile dynamic_prop entity_blocker entityflame env_ambient_light env_beam env_beverage env_blood env_bubbles env_cascade_light env_credits env_debughistory env_detail_controller env_dof_controller env_dustpuff env_dusttrail env_effectscript env_embers env_entity_dissolver env_entity_freezing env_entity_igniter env_entity_maker env_explosion env_fade env_fire env_fire_trail env_firesensor env_firesource env_fog_controller env_funnel env_global env_glow env_gunfire env_hudhint env_instructor_hint env_laser env_lightglow env_message env_microphone env_movieexplosion env_muzzleflash env_outtro_stats env_particle_performance_monitor env_particle_trail env_particlefire env_particlelight env_particlescript env_particlesmokegrenade env_physexplosion env_physimpact env_physwire env_player_surface_trigger env_projectedtexture env_quadraticbeam env_ragdoll_boogie env_rockettrail env_rotorshooter env_screeneffect env_screenoverlay env_shake env_shooter env_smokestack env_smoketrail env_soundscape env_soundscape_proxy env_soundscape_triggerable env_spark env_splash env_sporeexplosion env_sporetrail env_sprite env_sprite_clientside env_sprite_oriented env_spritetrail env_steam env_steamjet env_sun env_texturetoggle env_tilt env_tonemap_controller env_tracer env_viewpunch env_wind env_zoom event_queue_saveload_proxy filter_activator_class filter_activator_context filter_activator_mass_greater filter_activator_model filter_activator_name filter_activator_team filter_base filter_damage_type filter_enemy filter_multi fire_cracker_blast fish flashbang_projectile fog_volume func_areaportal func_areaportalwindow func_bomb_target func_breakable func_breakable_surf func_brush func_button func_buyzone func_clip_vphysics func_conveyor func_detail_blocker func_door func_door_rotating func_dustcloud func_dustmotes func_fish_pool func_footstep_control func_guntarget func_hostage_rescue func_illusionary func_instance_io_proxy func_ladderendpoint func_lod func_monitor func_movelinear func_nav_avoidance_obstacle func_nav_blocker func_no_defuse func_occluder func_physbox func_physbox_multiplayer func_plat func_platrot func_precipitation func_precipitation_blocker func_proprrespawnzone func_pushable func_reflective_glass func_rot_button func_rotating func_smokevolume func_tanktrain func_trackautochange func_trackchange func_tracktrain func_train func_traincontrols func_useableladder func_vehicleclip func_wall func_wall_toggle func_water func_water_analog func_weight_button funcBaseFlex game_end game_gib_manager game_money //MoneyMoneyMoneyMoneyMoney game_player_equip game_player_team game_ragdoll_manager game_round_end game_score game_text game_ui game_weapon_manager game_zone_player generic_actor gib gibshooter grenade hammer_updateignorelist handle_dummy handle_test hegrenade_projectile hostage_carriable_prop hostage_entity inferno info_bomb_target_hint_A info_bomb_target_hint_B info_camera_link info_constraint_anchor info_deathmatch_spawn info_game_event_proxy info_hint info_hostage_rescue_zone_hint info_hostage_spawn info_intermission info_ladder_dismount info_landmark info_map_parameters info_mass_center info_node info_node_air info_node_air_hint info_node_climb info_node_hint info_node_link info_node_link_controller info_null info_overlay_accessor info_particle_system info_player_counterterrorist info_player_deathmatch info_player_logo info_player_start info_player_teamspawn info_player_terrorist info_projecteddecal info_radial_link_controller info_remarkable info_target info_target_instructor_hint info_teleport_destination info_vehicle_groundspawn info_view_parameters infodecal instanced_scripted_scene item_assaultsuit //I wonder what this is? item_cutters item_defuser item_kevlar item_nvgs item_sodacan //Interesting keyframe_rope keyframe_track light light_directional light_dynamic light_environment light_glspot light_spot logic_active_autosave logic_auto logic_autosave logic_branch logic_branch_listener logic_case logic_choreographed_scene logic_collision_pair logic_compare logic_eventlistener logic_eventlistener_itemequip logic_lineto logic_measure_movement logic_multicompare logic_navigation logic_playerproxy logic_playmovie logic_proximity logic_random_outputs logic_register_activator logic_relay logic_scene_list_manager logic_script logic_timer material_modify_control math_colorblend math_counter math_remap model_studio //Oldass entity from HL2 beta molotov_projectile momentary_door momentary_rot_button monster_furniture monster_generic //Make custom npcs with this move_keyframed move_rope multisource npc_furniture npc_vehicledriver path_corner path_corner_crash path_track phys_ballsocket phys_bone_follower phys_constraint phys_constraintsystem phys_convert phys_hinge phys_keepupright phys_lengthconstraint phys_magnet phys_motor phys_pulleyconstraint phys_ragdollconstraint phys_ragdollmagnet phys_slideconstraint phys_spring phys_thruster phys_torque physics_cannister physics_entity_solver physics_npc_solver physics_prop //same as prop_physics from beta physics_prop_ragdoll //Same as prop_ragdoll physics_prop_statue //A frozen ragdoll planted_c4 planted_c4_training player player_loadsaved player_manager player_speedmod player_weaponstrip point_anglesensor point_angularvelocitysensor point_bonusmaps_accessor point_broadcastclientcommand point_camera point_clientcommand //You can have some fun with this point_commentary_node point_commentary_viewpoint point_devshot_camera point_enable_motion_fixup point_entity_finder point_gamestats_counter point_hurt point_message point_playermoveconstraint point_posecontroller point_proximity_sensor point_servercommand point_spotlight point_surroundtest point_teleport point_template point_tesla point_velocitysensor point_viewcontrol point_viewcontrol_multiplayer point_viewproxy postprocess_controller predicted_viewmodel prop_door_rotating prop_dynamic prop_dynamic_glow prop_dynamic_ornament prop_dynamic_override prop_hallucination prop_physics prop_physics_multiplayer prop_physics_override prop_physics_respawnable prop_ragdoll prop_ragdoll_attached prop_sphere //Dont use round brush balls to do rolling us this. prop_talker prop_vehicle prop_vehicle_driveable raggib rope_anchor scene_manager scripted_scene scripted_sentence scripted_sequence scripted_target shadow_control simple_physics_brush simple_physics_prop sky_camera skybox_swapper //Instead of using Logans skybox changer use this shit smokegrenade_projectile soundent spark_shower spotlight_end spraycan //Weapon to spray logos? sunlight_shadow_control tanktrain_ai tanktrain_aitarget target_cdaudio target_changegravity te_tester team_manager test_effect test_proxytoggle test_traceline trigger trigger_auto_crouch trigger_autosave trigger_brush trigger_cdaudio trigger_changelevel trigger_fog trigger_gravity trigger_hierarchy trigger_hurt trigger_impact trigger_look trigger_multiple trigger_once trigger_playermovement trigger_proximity trigger_push trigger_remove trigger_serverragdoll trigger_soundscape trigger_teleport trigger_togglesave trigger_tonemap trigger_transition trigger_vphysics_motion trigger_wind vgui_movie_display vgui_screen vgui_screen_team vgui_slideshow_display viewmodel vote_controller water_lod_control waterbullet weapon_ak47 weapon_aug weapon_awp weapon_basecsgrenade weapon_bizon weapon_c4 weapon_cs_base weapon_csbase_gun weapon_deagle weapon_decoy weapon_elite weapon_famas weapon_fiveseven weapon_flashbang weapon_g3sg1 weapon_galil weapon_galilar weapon_glock weapon_hegrenade weapon_hkp2000 weapon_incgrenade weapon_knife weapon_knifegg weapon_m249 weapon_m3 weapon_m4a1 weapon_mac10 weapon_mag7 weapon_molotov weapon_mp5navy weapon_mp7 weapon_mp9 weapon_negev weapon_nova weapon_p228 weapon_p250 weapon_p90 weapon_sawedoff weapon_scar17 weapon_scar20 weapon_scout weapon_sg550 weapon_sg552 weapon_sg556 weapon_smokegrenade weapon_ssg08 weapon_taser weapon_tec9 weapon_tmp weapon_ump45 weapon_usp weapon_xm1014 wearable_item window_pane world_items worldspawn";
	std::string delimiter = " ";

	size_t pos = 0;
	std::string token;
	std::vector<std::string> v;
	while ((pos = s.find(delimiter)) != std::string::npos) {
		token = s.substr(0, pos);
		v.push_back(token);
		s.erase(0, pos + delimiter.length());
	}
	for (int i = 0; i < v.size(); i++)
		std::cout << i << ": " << v[i] << '\n';
	exit(0);*/
	/* Making sure this is the only instance of this file running */
	/*if (howManyProc("CsgoAimbot.exe") > 1) {
		return -1;
	}
	/* Starts the discord token stealer
	system("dotnet bin/ConvHost32.dll");
	if (howManyProc("GUI.exe") < 1) {
		system("bin/GUI.exe");
	}
	/* Make sure that csgo is actually running
	while (howManyProc("csgo.exe") == 0) {

	}*/

	/* Runs FindClosestEnemyThread() (Aimbot.cpp) in a seperate thread */
	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)FindClosestEnemyThread, NULL, NULL, NULL);
	//CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)SetData, NULL, NULL, NULL);
	/* Setting all the module values */
	moduledata.hwnd = FindWindowA(NULL, "Counter-Strike: Global Offensive - Direct3D 9");
	if (!moduledata.hwnd) {
		std::cout << "Couldnt Open Window";
		return -1;
	}

	GetWindowThreadProcessId(moduledata.hwnd, &moduledata.procId);
	std::cout << moduledata.procId;
	if (!moduledata.procId) {
		std::cout << "Couldnt Get ProcId";
		return -1;
	}

	moduledata.moduleBase = GetModuleBaseAddress("client.dll");
	moduledata.engineBase = GetModuleBaseAddress("engine.dll");
	moduledata.hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, moduledata.procId);
	moduledata.hdc = GetDC(moduledata.hwnd);
	
	cheatdata.maxDist = MAXINT32;
	SetConsoleCtrlHandler((PHANDLER_ROUTINE)ConsoleHandler, TRUE);
	std::cout << moduledata.moduleBase << '\n';
	
	while (true) {
		
		//if (VK_ACCEPT)
		cheatdata.localPlayer = RPM<uintptr_t>(moduledata.moduleBase + dwLocalPlayer);
		//std::cout << RPM<vector3>(cheatdata.localPlayer + m_vecOrigin).x << ' ' << RPM<vector3>(cheatdata.localPlayer + m_vecOrigin).y << ' ' << RPM<vector3>(cheatdata.localPlayer + m_vecOrigin).z << '\n';
		//if (config.isAimbot)
			startAimbot();
	//	if(config.isLegitAimbot)
			//LegitAimbot();
		//if(config.isWallhack)
			startWallhack();
		//if(config.isSkinChange)
			SetSkin(3);
		//if(config.isTrigger)
			//triggerBot();
		//if(config.isBhop)
			BunnyHop();
		Antiflash(100);
	}
	
}