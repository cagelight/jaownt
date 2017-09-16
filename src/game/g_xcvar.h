/*
===========================================================================
Copyright (C) 1999 - 2005, Id Software, Inc.
Copyright (C) 2000 - 2013, Raven Software, Inc.
Copyright (C) 2001 - 2013, Activision, Inc.
Copyright (C) 2013 - 2015, OpenJK contributors

This file is part of the OpenJK source code.

OpenJK is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License version 2 as
published by the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, see <http://www.gnu.org/licenses/>.
===========================================================================
*/

#ifdef XCVAR_PROTO
	#define XCVAR_DEF( name, defVal, update, flags, announce ) extern vmCvar_t name;
#endif

#ifdef XCVAR_DECL
	#define XCVAR_DEF( name, defVal, update, flags, announce ) vmCvar_t name;
#endif

#ifdef XCVAR_LIST
	#define XCVAR_DEF( name, defVal, update, flags, announce ) { & name , #name , defVal , update , flags , announce },
#endif

XCVAR_DEF( capturelimit,				"8",			NULL,				CVAR_SERVERINFO|CVAR_ARCHIVE|CVAR_NORESTART,	qtrue )
XCVAR_DEF( com_optvehtrace,				"0",			NULL,				CVAR_NONE,										qtrue )
XCVAR_DEF( d_altRoutes,					"0",			NULL,				CVAR_CHEAT,										qfalse )
XCVAR_DEF( d_asynchronousGroupAI,		"0",			NULL,				CVAR_CHEAT,										qfalse )
XCVAR_DEF( d_break,						"0",			NULL,				CVAR_CHEAT,										qfalse )
XCVAR_DEF( d_JediAI,					"0",			NULL,				CVAR_CHEAT,										qfalse )
XCVAR_DEF( d_noGroupAI,					"0",			NULL,				CVAR_CHEAT,										qfalse )
XCVAR_DEF( d_noroam,					"0",			NULL,				CVAR_CHEAT,										qfalse )
XCVAR_DEF( d_npcai,						"0",			NULL,				CVAR_CHEAT,										qfalse )
XCVAR_DEF( d_npcaiming,					"0",			NULL,				CVAR_CHEAT,										qfalse )
XCVAR_DEF( d_npcfreeze,					"0",			NULL,				CVAR_CHEAT,										qfalse )
XCVAR_DEF( d_noIntermissionWait,		"0",			NULL,				CVAR_NONE,										qfalse )
XCVAR_DEF( d_patched,					"0",			NULL,				CVAR_CHEAT,										qfalse )
XCVAR_DEF( d_perPlayerGhoul2,			"0",			NULL,				CVAR_CHEAT,										qtrue )
XCVAR_DEF( d_powerDuelPrint,			"0",			NULL,				CVAR_NONE,										qtrue )
XCVAR_DEF( d_projectileGhoul2Collision,	"1",			NULL,				CVAR_CHEAT,										qtrue )
XCVAR_DEF( d_saberAlwaysBoxTrace,		"0",			NULL,				CVAR_CHEAT,										qtrue )
XCVAR_DEF( d_saberBoxTraceSize,			"0",			NULL,				CVAR_CHEAT,										qtrue )
XCVAR_DEF( d_saberCombat,				"0",			NULL,				CVAR_CHEAT,										qfalse )
XCVAR_DEF( d_saberGhoul2Collision,		"1",			NULL,				CVAR_CHEAT,										qtrue )
XCVAR_DEF( d_saberInterpolate,			"0",			NULL,				CVAR_CHEAT,										qtrue )
XCVAR_DEF( d_saberKickTweak,			"1",			NULL,				CVAR_NONE,										qtrue )
XCVAR_DEF( d_saberSPStyleDamage,		"1",			NULL,				CVAR_ARCHIVE,									qfalse )
XCVAR_DEF( d_saberStanceDebug,			"0",			NULL,				CVAR_NONE,										qfalse )
XCVAR_DEF( d_siegeSeekerNPC,			"0",			NULL,				CVAR_CHEAT,										qtrue )
XCVAR_DEF( dedicated,					"0",			NULL,				CVAR_NONE,										qfalse )
XCVAR_DEF( developer,					"0",			NULL,				CVAR_NONE,										qfalse )
XCVAR_DEF( dmflags,						"0",			NULL,				CVAR_SERVERINFO|CVAR_ARCHIVE,					qtrue )
XCVAR_DEF( duel_fraglimit,				"10",			NULL,				CVAR_SERVERINFO|CVAR_ARCHIVE|CVAR_NORESTART,	qtrue )
XCVAR_DEF( fraglimit,					"20",			NULL,				CVAR_SERVERINFO|CVAR_ARCHIVE|CVAR_NORESTART,	qtrue )
XCVAR_DEF( g_adaptRespawn,				"1",			NULL,				CVAR_NONE,										qtrue )
XCVAR_DEF( g_allowDuelSuicide,			"1",			NULL,				CVAR_ARCHIVE,									qtrue )
XCVAR_DEF( g_allowHighPingDuelist,		"1",			NULL,				CVAR_NONE,										qtrue )
XCVAR_DEF( g_allowNPC,					"1",			NULL,				CVAR_CHEAT,										qtrue )
XCVAR_DEF( g_allowTeamVote,				"1",			NULL,				CVAR_ARCHIVE,									qfalse )
XCVAR_DEF( g_allowVote,					"-1",			NULL,				CVAR_ARCHIVE,									qfalse )
XCVAR_DEF( g_antiFakePlayer,			"1",			NULL,				CVAR_ARCHIVE,									qfalse )
XCVAR_DEF( g_armBreakage,				"0",			NULL,				CVAR_NONE,										qtrue )
XCVAR_DEF( g_austrian,					"0",			NULL,				CVAR_ARCHIVE,									qfalse )
XCVAR_DEF( g_autoMapCycle,				"0",			NULL,				CVAR_ARCHIVE|CVAR_NORESTART,					qtrue )
XCVAR_DEF( g_banIPs,					"",				NULL,				CVAR_ARCHIVE,									qfalse )
XCVAR_DEF( g_charRestrictRGB,			"1",			NULL,				CVAR_ARCHIVE,									qfalse )
XCVAR_DEF( g_duelWeaponDisable,			"1",			NULL,				CVAR_SERVERINFO|CVAR_ARCHIVE|CVAR_LATCH,		qtrue )
XCVAR_DEF( g_debugAlloc,				"0",			NULL,				CVAR_NONE,										qfalse )
XCVAR_DEF( g_debugDamage,				"0",			NULL,				CVAR_NONE,										qfalse )
XCVAR_DEF( g_debugMelee,				"0",			NULL,				CVAR_SERVERINFO,								qtrue )
XCVAR_DEF( g_debugMove,					"0",			NULL,				CVAR_NONE,										qfalse )
XCVAR_DEF( g_debugSaberLocks,			"0",			NULL,				CVAR_CHEAT,										qfalse )
XCVAR_DEF( g_debugServerSkel,			"0",			NULL,				CVAR_CHEAT,										qfalse )
#ifdef _DEBUG
XCVAR_DEF( g_disableServerG2,			"0",			NULL,				CVAR_NONE,										qtrue )
#endif
XCVAR_DEF( g_dismember,					"0",			NULL,				CVAR_ARCHIVE,									qtrue )
XCVAR_DEF( g_doWarmup,					"0",			NULL,				CVAR_NONE,										qtrue )
//XCVAR_DEF( g_engineModifications,		"1",			NULL,				CVAR_ARCHIVE,									qfalse )
XCVAR_DEF( g_ff_objectives,				"0",			NULL,				CVAR_CHEAT|CVAR_NORESTART,						qtrue )
XCVAR_DEF( g_filterBan,					"1",			NULL,				CVAR_ARCHIVE,									qfalse )
XCVAR_DEF( g_forceBasedTeams,			"0",			NULL,				CVAR_SERVERINFO|CVAR_ARCHIVE|CVAR_LATCH,		qfalse )
XCVAR_DEF( g_forceClientUpdateRate,		"250",			NULL,				CVAR_NONE,										qfalse )
XCVAR_DEF( g_forceDodge,				"1",			NULL,				CVAR_NONE,										qtrue )
XCVAR_DEF( g_forcePowerDisable,			"0",			NULL,				CVAR_SERVERINFO|CVAR_ARCHIVE|CVAR_LATCH,		qtrue )
XCVAR_DEF( g_forceRegenTime,			"200",			NULL,				CVAR_ARCHIVE,									qtrue )
XCVAR_DEF( g_forceRespawn,				"60",			NULL,				CVAR_NONE,										qtrue )
XCVAR_DEF( g_fraglimitVoteCorrection,	"1",			NULL,				CVAR_ARCHIVE,									qtrue )
XCVAR_DEF( g_friendlyFire,				"0",			NULL,				CVAR_ARCHIVE,									qtrue )
XCVAR_DEF( g_friendlySaber,				"0",			NULL,				CVAR_ARCHIVE,									qtrue )
XCVAR_DEF( g_g2TraceLod,				"3",			NULL,				CVAR_NONE,										qtrue )
XCVAR_DEF( g_gametype,					"0",			NULL,				CVAR_SERVERINFO|CVAR_LATCH,						qfalse )
XCVAR_DEF( g_gravity,					"800",			G_Phys_Upd_Grav,	CVAR_NONE,										qtrue )
XCVAR_DEF( g_inactivity,				"0",			NULL,				CVAR_NONE,										qtrue )
XCVAR_DEF( g_jediVmerc,					"0",			NULL,				CVAR_SERVERINFO|CVAR_LATCH|CVAR_ARCHIVE,		qtrue )
XCVAR_DEF( g_knockback,					"1000",			NULL,				CVAR_NONE,										qtrue )
XCVAR_DEF( g_locationBasedDamage,		"1",			NULL,				CVAR_NONE,										qtrue )
XCVAR_DEF( g_log,						"games.log",	NULL,				CVAR_ARCHIVE,									qfalse )
XCVAR_DEF( g_logClientInfo,				"0",			NULL,				CVAR_ARCHIVE,									qtrue )
XCVAR_DEF( g_logSync,					"0",			NULL,				CVAR_ARCHIVE,									qfalse )
XCVAR_DEF( g_maxConnPerIP,				"3",			NULL,				CVAR_ARCHIVE,									qfalse )
XCVAR_DEF( g_maxForceRank,				"7",			NULL,				CVAR_SERVERINFO|CVAR_ARCHIVE|CVAR_LATCH,		qfalse )
XCVAR_DEF( g_maxGameClients,			"0",			NULL,				CVAR_SERVERINFO|CVAR_LATCH|CVAR_ARCHIVE,		qfalse )
XCVAR_DEF( g_maxHolocronCarry,			"3",			NULL,				CVAR_LATCH,										qfalse )
XCVAR_DEF( g_phys_resolution,			"125",			G_Phys_Upd_Res,		CVAR_ARCHIVE|CVAR_SERVERINFO,					qtrue )
XCVAR_DEF( g_projectilelife,			"10000",		NULL,				CVAR_ARCHIVE,									qtrue )
XCVAR_DEF( g_motd,						"",				NULL,				CVAR_NONE,										qfalse )
XCVAR_DEF( g_needpass,					"0",			NULL,				CVAR_SERVERINFO|CVAR_ROM,						qfalse )
XCVAR_DEF( g_noSpecMove,				"0",			NULL,				CVAR_SERVERINFO,								qtrue )
XCVAR_DEF( g_npcspskill,				"0",			NULL,				CVAR_ARCHIVE|CVAR_INTERNAL,						qfalse )
XCVAR_DEF( g_password,					"",				NULL,				CVAR_NONE,										qfalse )
XCVAR_DEF( g_powerDuelEndHealth,		"90",			NULL,				CVAR_ARCHIVE,									qtrue )
XCVAR_DEF( g_powerDuelStartHealth,		"150",			NULL,				CVAR_ARCHIVE,									qtrue )
XCVAR_DEF( g_privateDuel,				"1",			NULL,				CVAR_ARCHIVE,									qtrue )
XCVAR_DEF( g_randFix,					"1",			NULL,				CVAR_ARCHIVE,									qtrue )
XCVAR_DEF( g_restarted,					"0",			NULL,				CVAR_ROM,										qfalse )
XCVAR_DEF( g_saberBladeFaces,			"1",			NULL,				CVAR_NONE,										qtrue )
XCVAR_DEF( g_saberDamageScale,			"1",			NULL,				CVAR_ARCHIVE,									qtrue )
#ifdef DEBUG_SABER_BOX
XCVAR_DEF( g_saberDebugBox,				"0",			NULL,				CVAR_CHEAT,										qfalse )
#endif
#ifndef FINAL_BUILD
XCVAR_DEF( g_saberDebugPrint,			"0",			NULL,				CVAR_CHEAT,										qfalse )
#endif
XCVAR_DEF( g_saberDmgDelay_Idle,		"350",			NULL,				CVAR_ARCHIVE,									qtrue )
XCVAR_DEF( g_saberDmgDelay_Wound,		"0",			NULL,				CVAR_ARCHIVE,									qtrue )
XCVAR_DEF( g_saberDmgVelocityScale,		"0",			NULL,				CVAR_ARCHIVE,									qtrue )
XCVAR_DEF( g_saberLockFactor,			"2",			NULL,				CVAR_ARCHIVE,									qtrue )
XCVAR_DEF( g_saberLocking,				"1",			NULL,				CVAR_ARCHIVE,									qtrue )
XCVAR_DEF( g_saberLockRandomNess,		"2",			NULL,				CVAR_ARCHIVE,									qfalse )
XCVAR_DEF( g_saberRealisticCombat,		"0",			NULL,				CVAR_CHEAT,										qfalse )
XCVAR_DEF( g_saberRestrictForce,		"0",			NULL,				CVAR_ARCHIVE,									qfalse )
XCVAR_DEF( g_saberTraceSaberFirst,		"0",			NULL,				CVAR_ARCHIVE,									qtrue )
XCVAR_DEF( g_saberWallDamageScale,		"0.4",			NULL,				CVAR_NONE,										qfalse )
XCVAR_DEF( g_securityLog,				"1",			NULL,				CVAR_ARCHIVE,									qfalse )
XCVAR_DEF( g_showDuelHealths,			"0",			NULL,				CVAR_SERVERINFO,								qfalse )
XCVAR_DEF( g_siegeRespawn,				"20",			NULL,				CVAR_ARCHIVE,									qtrue )
XCVAR_DEF( g_siegeTeam1,				"none",			NULL,				CVAR_ARCHIVE|CVAR_SERVERINFO,					qfalse )
XCVAR_DEF( g_siegeTeam2,				"none",			NULL,				CVAR_ARCHIVE|CVAR_SERVERINFO,					qfalse )
XCVAR_DEF( g_siegeTeamSwitch,			"1",			NULL,				CVAR_SERVERINFO|CVAR_ARCHIVE,					qfalse )
XCVAR_DEF( g_slowmoDuelEnd,				"0",			NULL,				CVAR_ARCHIVE,									qtrue )
XCVAR_DEF( g_smoothClients,				"1",			NULL,				CVAR_NONE,										qfalse )
XCVAR_DEF( g_spawnInvulnerability,		"3000",			NULL,				CVAR_ARCHIVE,									qtrue )
XCVAR_DEF( g_speed,						"250",			NULL,				CVAR_NONE,										qtrue )
XCVAR_DEF( g_startingweapons,			"16",			NULL,				CVAR_ARCHIVE,									qtrue )
XCVAR_DEF( g_statLog,					"0",			NULL,				CVAR_ARCHIVE,									qfalse )
XCVAR_DEF( g_statLogFile,				"statlog.log",	NULL,				CVAR_ARCHIVE,									qfalse )
XCVAR_DEF( g_stepSlideFix,				"1",			NULL,				CVAR_SERVERINFO,								qtrue )
XCVAR_DEF( g_synchronousClients,		"0",			NULL,				CVAR_SYSTEMINFO,								qfalse )
XCVAR_DEF( g_teamAutoJoin,				"0",			NULL,				CVAR_ARCHIVE,									qfalse )
XCVAR_DEF( g_teamForceBalance,			"0",			NULL,				CVAR_ARCHIVE,									qfalse )
XCVAR_DEF( g_timeouttospec,				"70",			NULL,				CVAR_ARCHIVE,									qfalse )
XCVAR_DEF( g_userinfoValidate,			"25165823",		NULL,				CVAR_ARCHIVE,									qfalse )
XCVAR_DEF( g_useWhileThrowing,			"1",			NULL,				CVAR_NONE,										qtrue )
XCVAR_DEF( g_voteDelay,					"3000",			NULL,				CVAR_NONE,										qfalse )
XCVAR_DEF( g_warmup,					"20",			NULL,				CVAR_ARCHIVE,									qtrue )
XCVAR_DEF( g_weaponDisable,				"0",			NULL,				CVAR_SERVERINFO|CVAR_ARCHIVE|CVAR_LATCH,		qtrue )
XCVAR_DEF( g_weaponRespawn,				"5",			NULL,				CVAR_NONE,										qtrue )
XCVAR_DEF( gamedate,					__DATE__,		NULL,				CVAR_ROM,										qfalse )
XCVAR_DEF( gamename,					GAMEVERSION,	NULL,				CVAR_SERVERINFO|CVAR_ROM,						qfalse )
XCVAR_DEF( pmove_fixed,					"0",			NULL,				CVAR_SYSTEMINFO|CVAR_ARCHIVE,					qtrue )
XCVAR_DEF( pmove_float,					"0",			NULL,				CVAR_SYSTEMINFO|CVAR_ARCHIVE,					qtrue )
XCVAR_DEF( pmove_msec,					"8",			NULL,				CVAR_SYSTEMINFO|CVAR_ARCHIVE,					qtrue )
XCVAR_DEF( RMG,							"0",			NULL,				CVAR_NONE,										qtrue )
XCVAR_DEF( sv_cheats,					"1",			NULL,				CVAR_NONE,										qfalse )
XCVAR_DEF( sv_fps,						"40",			NULL,				CVAR_ARCHIVE|CVAR_SERVERINFO,					qtrue )
XCVAR_DEF( sv_maxclients,				"8",			NULL,				CVAR_SERVERINFO|CVAR_LATCH|CVAR_ARCHIVE,		qfalse )
XCVAR_DEF( timelimit,					"0",			NULL,				CVAR_SERVERINFO|CVAR_ARCHIVE|CVAR_NORESTART,	qtrue )


// WEAPON CVARS

// Wookiee Bowcaster
XCVAR_DEF( weap_bowcasterAltBounceCount,		"20",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_bowcasterAltProjectileLife,		"10",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_bowcasterAltRange,				"0.3",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_bowcasterAltSpread,				"5.0",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_bowcasterBounceCount,			"0",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_bowcasterChargeUnit,			"200",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_bowcasterDamage,				"50",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_bowcasterHitboxSize,			"2",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_bowcasterProjectileLife,		"10",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_bowcasterSplashDamage,			"0",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_bowcasterSplashRadius,			"0",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_bowcasterVelocity,				"1300",		NULL,				CVAR_NONE,	qtrue )

// Bryar Pistol
XCVAR_DEF( weap_bryarPistolAltBounceCount,		"8",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_bryarPistolAltBouncy,			"0",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_bryarPistolAltDamage,			"10",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_bryarPistolAltProjectileLife,	"10",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_bryarPistolAltVelocity,			"1600",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_bryarPistolBounceCount,			"8",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_bryarPistolBouncy,				"0",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_bryarPistolChargeUnit,			"200.0",	NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_bryarPistolDamage,				"10",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_bryarPistolHitboxSize,			"1.0",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_bryarPistolProjectileLife,		"10",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_bryarPistolVelocity,			"1600",		NULL,				CVAR_NONE,	qtrue )

// Concussion Rifle
XCVAR_DEF( weap_concussionAltDamage,			"25",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_concussionAltPenetration,		"3",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_concussionBounceCount,			"8",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_concussionBouncy,				"0",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_concussionDamage,				"75",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_concussionProjectileLife,		"10",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_concussionSplashDamage,			"40",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_concussionSplashRadius,			"300",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_concussionVelocity,				"3000",		NULL,				CVAR_NONE,	qtrue )

// DEMP2
XCVAR_DEF( weap_demp2AltBounceCount,			"0",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_demp2AltDamage,					"8",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_demp2AltRadius,					"80000",	NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_demp2AltRange,					"4096",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_demp2AltSplashRadius,			"256",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_demp2BounceCount,				"8",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_demp2Bouncy,					"0",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_demp2ChargeUnit,				"700.0",	NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_demp2Damage,					"35",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_demp2HitboxSize,				"2",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_demp2ProjectileLife,			"10",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_demp2Velocity,					"1800",		NULL,				CVAR_NONE,	qtrue )

// Detonation Pack
XCVAR_DEF( weap_detpackAutoTimer,				"300",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_detpackDamage,					"100",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_detpackMaxCount,				"100",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_detpackSplashDamage,			"200",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_detpackSplashRadius,			"200",		NULL,				CVAR_NONE,	qtrue )

// Tenloss Disruptor
XCVAR_DEF( weap_disruptorAltDamage,				"100",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_disruptorAltPenetration,		"3",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_disruptorChargeUnit,			"50",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_disruptorMainDamage,			"30",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_disruptorMainDamage_Siege,		"50",		NULL,				CVAR_NONE,	qtrue )

// E11 Blaster
XCVAR_DEF( weap_e11AltBounceCount,				"8",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_e11AltBouncy,					"0",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_e11AltDamage,					"20",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_e11AltProjectileLife,			"10",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_e11AltSpread,					"1.6",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_e11AltVelocity,					"2300",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_e11BounceCount,					"8",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_e11Bouncy,						"0",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_e11Damage,						"20",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_e11ProjectileLife,				"10",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_e11Velocity,					"2300",		NULL,				CVAR_NONE,	qtrue )

// Golan Arms Flechette
XCVAR_DEF( weap_flechetteAltBounceCount,		"50",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_flechetteAltCount,				"2",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_flechetteAltDamage,				"60",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_flechetteAltHitboxSize,			"6",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_flechetteAltMaxVelocity,		"700",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_flechetteAltMinVelocity,		"700",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_flechetteAltMaxLife,			"6",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_flechetteAltMinLife,			"1.5",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_flechetteAltSplashDamage,		"60",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_flechetteAltSplashRadius,		"128",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_flechetteBounceCountMin,		"5",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_flechetteBounceCountMax,		"8",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_flechetteCount,					"5",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_flechetteDamage,				"15",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_flechetteHitboxSize,			"1",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_flechetteMaxLife,				"4",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_flechetteMinLife,				"3",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_flechetteMineRadiusCheck,		"256",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_flechetteSpread,				"4.0",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_flechetteVelocity,				"3500",		NULL,				CVAR_NONE,	qtrue )

// Melee
XCVAR_DEF( weap_meleeSwing1Damage,				"10",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_meleeSwing2Damage,				"12",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_meleeRange				,		"8",		NULL,				CVAR_NONE,	qtrue )

// Heavy Repeater
XCVAR_DEF( weap_repeaterAltBounceCount,			"8",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_repeaterAltBouncy,				"0",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_repeaterAltDamage,				"60",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_repeaterAltHitboxSize,			"3",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_repeaterAltProjectileLife,		"10",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_repeaterAltSplashDamage,		"60",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_repeaterAltSplashRadius,		"128",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_repeaterAltSplashRadius_Siege,	"80",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_repeaterAltVelocity,			"1100",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_repeaterBounceCount,			"8",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_repeaterBouncy,					"0",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_repeaterDamage,					"14",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_repeaterProjectileLife,			"10",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_repeaterSpread,					"1.4",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_repeaterVelocity,				"1600",		NULL,				CVAR_NONE,	qtrue )

// Rocket Launcher
XCVAR_DEF( weap_rocketAltThinkTime,				"0.1",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_rocketBounceCount,				"0",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_rocketDamage,					"100",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_rocketHitboxSize,				"3",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_rocketProjectileLife,		"10",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_rocketSplashDamage,				"100",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_rocketSplashRadius,				"160",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_rocketVelocity,					"900",		NULL,				CVAR_NONE,	qtrue )

// Stun Baton
XCVAR_DEF( weap_stunBatonAltDamage,				"20",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_stunBatonDamage,				"20",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_stunBatonRange,					"8",		NULL,				CVAR_NONE,	qtrue )

// Thermal Detonator
XCVAR_DEF( weap_thermalDetBounceCount,			"5",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_thermalDetDamage,				"70",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_thermalDetMinCharge,			"0.15",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_thermalDetSplashDamage,			"90",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_thermalDetSplashRadius,			"128",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_thermalDetTimer,				"3",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_thermalDetVelocity,				"900",		NULL,				CVAR_NONE,	qtrue )

// Trip Mine
XCVAR_DEF( weap_tripmineActivateDelay,			"1000",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_tripmineAutoTimer,				"300",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_tripmineDamage,					"100",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_tripmineDelayTime,				"0.05",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_tripmineHitboxSize,				"1.5",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_tripmineMaxCount,				"100",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_tripmineSplashRadius,			"256.0",	NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_tripmineSplashDamage,			"105",		NULL,				CVAR_NONE,	qtrue )
XCVAR_DEF( weap_tripmineVelocity,				"900.0",	NULL,				CVAR_NONE,	qtrue )


#undef XCVAR_DEF
