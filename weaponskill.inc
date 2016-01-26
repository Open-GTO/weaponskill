/*

	About: weapon skill functions
	Author: ziggi

*/

#if !defined _samp_included
	#error "Please include a_samp or a_npc before weaponskill"
#endif

#if defined _weaponskill_included
	#endinput
#endif

#define _weaponskill_included
#pragma library weaponskill

/*
	Defines
*/

#if !defined MAX_WEAPON_SKILLS
	#define MAX_WEAPON_SKILLS 11
#endif

/*
	Vars
*/

static const
	gWeaponSkills[] = {
		WEAPONSKILL_PISTOL, // 22
		WEAPONSKILL_PISTOL_SILENCED, // 23
		WEAPONSKILL_DESERT_EAGLE, // 24
		WEAPONSKILL_SHOTGUN, // 25
		WEAPONSKILL_SAWNOFF_SHOTGUN, // 26
		WEAPONSKILL_SPAS12_SHOTGUN, // 27
		WEAPONSKILL_MICRO_UZI, // 28
		WEAPONSKILL_MP5, // 29
		WEAPONSKILL_AK47, // 30
		WEAPONSKILL_M4, // 31
		WEAPONSKILL_MICRO_UZI, // 32
		WEAPONSKILL_SNIPERRIFLE, // 33
		WEAPONSKILL_SNIPERRIFLE // 34
	};

static
	gPlayerWeaponSkill[MAX_PLAYERS][MAX_WEAPON_SKILLS];

/*
	GivePlayerSkillLevel
*/

stock GivePlayerSkillLevel(playerid, skill, amount)
{
	if (skill < 0 || skill > sizeof(gPlayerWeaponSkill[]) - 1) {
		return 0;
	}

	gPlayerWeaponSkill[playerid][skill] += amount;

	return
		SetPlayerSkillLevel(playerid, skill, gPlayerWeaponSkill[playerid][skill]);
}

/*
	SetPlayerSkillLevel
*/

stock WS_SetPlayerSkillLevel(playerid, skill, level)
{
	if (skill < 0 || skill > sizeof(gPlayerWeaponSkill[]) - 1) {
		return 0;
	}

	gPlayerWeaponSkill[playerid][skill] = level;

	return
		SetPlayerSkillLevel(playerid, skill, level);
}
#if defined _ALS_SetPlayerSkillLevel
	#undef SetPlayerSkillLevel
#else
	#define _ALS_SetPlayerSkillLevel
#endif
 
#define SetPlayerSkillLevel WS_SetPlayerSkillLevel

/*
	GetPlayerSkillLevel
*/

stock GetPlayerSkillLevel(playerid, skill)
{
	if (skill < 0 || skill > sizeof(gPlayerWeaponSkill[]) - 1) {
		return -1;
	}

	return gPlayerWeaponSkill[playerid][skill];
}

/*
	GetPlayerSkillLevelArray
*/

stock GetPlayerSkillLevelArray(playerid, array[MAX_WEAPON_SKILLS])
{
	array = gPlayerWeaponSkill[playerid];
}

/*
	SetPlayerSkillLevelArray
*/

stock SetPlayerSkillLevelArray(playerid, array[MAX_WEAPON_SKILLS])
{
	gPlayerWeaponSkill[playerid] = array;

	for (new skill = 0; skill < sizeof(gPlayerWeaponSkill[]); skill++) {
		SetPlayerSkillLevel(playerid, skill, array[skill]);
	}
}

/*
	GetWeaponSkillName
*/

stock GetWeaponSkillName(skill, name[], const size = sizeof(name))
{
	if (skill < 0 || skill > MAX_WEAPON_SKILLS - 1) {
		return 0;
	}

	return
		GetWeaponName(skill + 22, name, size);
}

/*
	GetWeaponSkillID
*/

stock GetWeaponSkillID(weaponid)
{
	new index = weaponid - 22;

	if (index < 0 || index > sizeof(gWeaponSkills) - 1) {
		return -1;
	}

	return gWeaponSkills[index];
}
