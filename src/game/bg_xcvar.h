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

#ifdef _CGAME
#ifdef XCVAR_LIST
	#define XCVAR_DEF( name, defVal, update, flags, announce ) { & name , #name , defVal , update , flags },
#endif
#endif

#ifdef _GAME
#ifdef XCVAR_LIST
	#define XCVAR_DEF( name, defVal, update, flags, announce ) { & name , #name , defVal , update , flags , announce },
#endif
#endif

//Ammo
XCVAR_DEF( ammo_blasterMax,				"300",			updateAmmoBlasterMax,				CVAR_NONE,					qtrue )
XCVAR_DEF( ammo_detpackMax,				"10",			updateAmmoDetpackMax,				CVAR_NONE,					qtrue )
XCVAR_DEF( ammo_emplacedMax,			"800",			updateAmmoEmplacedMax,				CVAR_NONE,					qtrue )
XCVAR_DEF( ammo_forceMax,				"100",			updateAmmoForceMax,					CVAR_NONE,					qtrue )
XCVAR_DEF( ammo_metalBoltsMax,			"300",			updateAmmoMetalBoltsMax,			CVAR_NONE,					qtrue )
XCVAR_DEF( ammo_powercellMax,			"300",			updateAmmoPowercellMax,				CVAR_NONE,					qtrue )
XCVAR_DEF( ammo_rocketsMax,				"25",			updateAmmoRocketsMax,				CVAR_NONE,					qtrue )
XCVAR_DEF( ammo_thermalMax,				"10",			updateAmmoThermalMax,				CVAR_NONE,					qtrue )
XCVAR_DEF( ammo_tripmineMax,			"10",			updateAmmoTripmineMax,				CVAR_NONE,					qtrue )


//Other sfutt
XCVAR_DEF( bg_aircontrol,				"1",			NULL,				CVAR_SYSTEMINFO|CVAR_ARCHIVE,					qtrue ) // TODO
XCVAR_DEF( bg_aircontrolzerog,			"1",			NULL,				CVAR_SYSTEMINFO|CVAR_ARCHIVE,					qtrue )
XCVAR_DEF( bg_fighterAltControl,		"0",			NULL,				CVAR_SYSTEMINFO,								qtrue )
XCVAR_DEF( bg_infammo,					"0",			NULL,				CVAR_SYSTEMINFO|CVAR_ARCHIVE,					qtrue )
XCVAR_DEF( bg_phys_clfric_move,			"0.3",			NULL,				CVAR_SYSTEMINFO|CVAR_ARCHIVE,					qtrue )
XCVAR_DEF( bg_phys_clfric_stop,			"2.5",			NULL,				CVAR_SYSTEMINFO|CVAR_ARCHIVE,					qtrue )
XCVAR_DEF( bg_superweapons,				"1",			NULL,				CVAR_SYSTEMINFO|CVAR_ARCHIVE,					qtrue )
XCVAR_DEF( bg_oldmove,					"0",			NULL,				CVAR_SYSTEMINFO|CVAR_ARCHIVE,					qtrue )


//Ammo indexes
XCVAR_DEF( weap_blasterAmmoIndex,			"2",		Upd_blasterAmmoIndex,					CVAR_NONE,					qtrue )
XCVAR_DEF( weap_bowcasterAmmoIndex,			"3",		Upd_bowcasterAmmoIndex,					CVAR_NONE,					qtrue )
XCVAR_DEF( weap_bryarPistolAmmoIndex,		"2",		Upd_bryarPistolAmmoIndex,				CVAR_NONE,					qtrue )
XCVAR_DEF( weap_concussionAmmoIndex,		"4",		Upd_concussionAmmoIndex,				CVAR_NONE,					qtrue )
XCVAR_DEF( weap_demp2AmmoIndex,				"3",		Upd_demp2AmmoIndex,						CVAR_NONE,					qtrue )
XCVAR_DEF( weap_detpackAmmoIndex,			"9",		Upd_detpackAmmoIndex,					CVAR_NONE,					qtrue )
XCVAR_DEF( weap_disruptorAmmoIndex,			"3",		Upd_disruptorAmmoIndex,					CVAR_NONE,					qtrue )
XCVAR_DEF( weap_e11AmmoIndex,				"2",		Upd_e11AmmoIndex,						CVAR_NONE,					qtrue )
XCVAR_DEF( weap_flechetteAmmoIndex,			"4",		Upd_flechetteAmmoIndex,					CVAR_NONE,					qtrue )
XCVAR_DEF( weap_forceAmmoIndex,				"0",		Upd_forceAmmoIndex,						CVAR_NONE,					qtrue )
XCVAR_DEF( weap_meleeAmmoIndex,				"0",		Upd_meleeAmmoIndex,						CVAR_NONE,					qtrue )
XCVAR_DEF( weap_repeaterAmmoIndex,			"4",		Upd_repeaterAmmoIndex,					CVAR_NONE,					qtrue )
XCVAR_DEF( weap_rocketsAmmoIndex,			"5",		Upd_rocketsAmmoIndex,					CVAR_NONE,					qtrue )
XCVAR_DEF( weap_saberAmmoIndex,				"0",		Upd_saberAmmoIndex,						CVAR_NONE,					qtrue )
XCVAR_DEF( weap_stunBatonAmmoIndex,			"3",		Upd_stunBatonAmmoIndex,					CVAR_NONE,					qtrue )
XCVAR_DEF( weap_thermalAmmoIndex,			"7",		Upd_thermalAmmoIndex,					CVAR_NONE,					qtrue )
XCVAR_DEF( weap_tripmineAmmoIndex,			"8",		Upd_tripmineAmmoIndex,					CVAR_NONE,					qtrue )


#undef XCVAR_DEF
