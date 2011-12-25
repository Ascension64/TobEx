#ifndef DATATYPES_H
#define DATATYPES_H

#include "utils.h"
#include "resref.h"

//Bam, Bah
struct BamFileFrameEntry { //Size Ch
	WORD width;
	WORD height;
	WORD x;
	WORD y;
	DWORD dwFlags;
};

//Chu
struct ChuFileControlInfoBase { //Size Eh
	DWORD id; //0h
	WORD posX; //4h
	WORD posY; //6h
	WORD width; //8h
	WORD height; //ah
	BYTE type; //ch
	BYTE ud; //dh
};

//Cre
struct ColorRangeValues { //Size 7h
	BYTE colorMetal; //0h
	BYTE colorMinor; //1h
	BYTE colorMajor; //2h
	BYTE colorSkin; //3h
	BYTE colorLeather; //4h
	BYTE colorArmor; //5h
	BYTE colorHair; //6h
};

struct CreFileData { //Size 268h
	STRREF longNameStrRef; //0h, dialogue
	STRREF shortNameStrRef; //4h, strref tooltip
	DWORD dwFlags; //8h
	DWORD ExpWorth; //ch
	DWORD currentExp; //10h
	DWORD gold; //14h
	DWORD stateFlags; //18h
	WORD currentHP;
	WORD maxHP;
	WORD animID; //20h
	WORD u22;
	ColorRangeValues colors; //23h
	BYTE effType; //2ah, 0 = ITEM_EFFECT (Effect), 1 = CEffect
	ResRef smallPortrait; //2ch
	ResRef largePortrait; //34h
	BYTE reputation; //3ch
	BYTE hideInShadows;
	WORD ACNatural;
	WORD ACEffective; //40h
	WORD ACCrushingMod;
	WORD ACMissileMod;
	WORD ACPiercingMod;
	WORD ACSlashingMod;
	BYTE THAC0;
	BYTE numAttacks;
	BYTE saveDeath;
	BYTE saveWands;
	BYTE savePolymorph;
	BYTE saveBreath;
	BYTE saveSpells; //50h
	BYTE resistFire;
	BYTE resistCold;
	BYTE resistElectricity;
	BYTE resistAcid;
	BYTE resistMagic;
	BYTE resistMagicFire;
	BYTE resistMagicCold;
	BYTE resistSlashing;
	BYTE resistCrushing;
	BYTE resistPiercing;
	BYTE resistMissile;
	BYTE detectIllusion;
	BYTE setTraps;
	BYTE lore;
	BYTE lockpicking;
	BYTE stealth; //60h
	BYTE findTraps;
	BYTE pickPockets;
	BYTE fatigue;
	BYTE intoxication;
	BYTE luck;
	BYTE BG1ProfLSword; //unused
	BYTE BG1ProfSSword; //unused
	BYTE BG1ProfBows; //unused
	BYTE BG1ProfSpears; //unused
	BYTE BG1ProfBlunt; //unused
	BYTE BG1ProfSpiked; //unused
	BYTE BG1ProfAxe; //unused
	BYTE BG1ProfMissile; //unused
	BYTE u6e;
	BYTE u6f;
	BYTE u70;
	BYTE u71;
	BYTE u72;
	BYTE u73;
	BYTE u74;
	BYTE u75;
	BYTE u76;
	BYTE u77;
	BYTE u78;
	BYTE u79;
	BYTE u7a;
	BYTE tracking;
	BYTE u7c[32];
	STRREF soundset[100]; //9ch
	BYTE levelPrimary; //22ch
	BYTE levelSecondary; //22dh
	BYTE levelTertiary;
	BYTE sex;
	BYTE strength;
	BYTE strengthPercent;
	BYTE intelligene;
	BYTE wisdom;
	BYTE dexterity;
	BYTE constitution;
	BYTE charisma;
	BYTE morale; //237h, range: 0-20, add -1 when PC dies
	BYTE moraleBreak;
	BYTE racialEnemy; //239h
	BYTE moraleRecoveryTime;
	BYTE u23b;
	WORD kit[2]; //23ch
	ResRef scriptOverride; //240h
	ResRef scriptClass;
	ResRef scriptRace; //250h
	ResRef scriptGeneral;
	ResRef scriptDefault; //260h
};

struct CreFileMemSpellLevel { //Size 10h
	WORD level;
	WORD numSpellsMemMax;
	WORD numSpellsMemCurrent;
	WORD type; //0 = priest, 1 = wizard, 2 = innate
	DWORD index; //of spell table
	DWORD num; //count of spells
};

struct CreFileKnownSpell { //Size Ch
	ResRef name; //0h
	WORD level; //8h
	WORD type; //ah
};

struct CreFileMemSpell { //Size Ch
	ResRef name;
	WORD wFlags; //8h, bit0: memorised, bit1: is a SPIN107, 108, 109, 110, 111 (a Paladin, Ranger, Druid special innate)
	WORD ua; //pad
};

//Dlg
struct DlgFileState { //Size 10h
	STRREF strref; //0h
	DWORD nResponseIdx; //4h, first response index
	DWORD nResponses; //8h
	DWORD nTriggerIdx; //ch
};

struct DlgFileResponse { //Size 20h
	DWORD flags; //0h
	STRREF strref; //4h
	STRREF strrefJournal; //8h
	DWORD nTriggerIdx; //ch
	DWORD nActionIdx; //10h
	ResRef NextDialog; //14h
	DWORD nNextDialogState; //1ch
};

//Eff
struct EffFileData { //size 108h
//AKA CGameEffectBase
	ResRef rHeader; //0h
	DWORD nOpcode; //8h
	DWORD nTarget; //ch
	DWORD nSplLvl; //10h
	DWORD nParam1; //14h
	DWORD nParam2; //18h

	//0: convert to 1000, Apply now, set duration (duration in sec)
	//3: convert to 6, Apply later, set duration (duration in sec)
	//6: if gameTime >= duration (ticks), convert to 1000, Apply now set duration (duration in sec)
	//4: convert to 7, Apply later, set duration (duration in sec)
	//7: if gameTime >= duration (ticks), convert to 1, Apply now
	//5: convert to 8, Apply later, set duration (duration in sec)
	//8: if gameTime>= duration (ticks), convert to 2, Apply now
	//9: will not be removed from CPtrListEffect
	//10: convert to 1000, Apply now, set duration (duration in ticks)
	//1000: if gameTime < duration (ticks), Apply; else purge
	DWORD nTiming; //1ch, in seconds (converted to ticks)

	DWORD nDuration; //20h
	WORD wProbHigh; //24h
	WORD wProbLow; //26h
	ResRef rResource; //28h
	DWORD nDice; //30h
	DWORD nDieSides; //34h
	DWORD nSaveType; //38h
	DWORD nSaveBonus; //3ch
	DWORD u44; //40h
	DWORD nType1; //44h
	DWORD u4c; //48h
	DWORD nLevelMin; //4ch
	DWORD nLevelMax; //50h
		
	//bit 0 = CGAMEEFFECT_DISPELLABLE
	//bit 1 = CGAMEEFFECT_IGNORE_RESISTANCE
	//bit 2 = CGAMEEFFECT_IGNORE_SPELL_LEVL_RESISTANCE (only for BounceSplLvl[Dec], ProtSplLvl[Dec], and SplLvlTrap; does not affect ProtSplLvl)
	DWORD dwFlags; //54h, DispelResistFlags
		
	DWORD nParam3; //58h
	DWORD nParam4; //5ch
	DWORD u64; //60h
	DWORD u68; //64h
	ResRef rVVC; //68h
	ResRef rResource2; //70h
	POINT ptSource; //78h
	DWORD nDestX; //80h
	DWORD nDestY; //84h
	DWORD nParentResourceType; //88h, 1 = SPL
	ResRef rParentResource; //8ch
	DWORD nParentResourceFlags; //94h
	DWORD nParentProjectile; //98h, PROJECTL.IDS
	DWORD nParentItemSlot; //9ch
	char variable[32]; //a0h
	DWORD nSourceCreLevel; //c0h, inherits 0ah for a global effect of an item equipped by a Sprite
	DWORD uc8; //c4h
	DWORD nType2; //c8h
	DWORD ud0[15]; //cch
};

//Itm
struct ItmFileAbility { //Size 38h
	BYTE attackType; //0h
	BYTE idReq; //1h
	BYTE loc; //2h
	BYTE u3;
	ResRef useIcon; //4h
	BYTE targetType; //ch
	BYTE targetCnt; //dh
	WORD range; //eh
	WORD projType; //10h
	WORD speed; //12h
	WORD toHitBonus; //14h
	WORD sizeDice; //16h
	WORD nDice; //18h
	WORD damBonus; //1ah
	WORD damType; //1ch
	WORD nEffects; //1eh
	WORD offEffects; //20h
	WORD charges; //22h
	WORD chargeType; //24h
	WORD flags; //26h
	WORD u28;
	WORD projIdx; //2ah
	WORD meleeIdx[3]; //2ch
	WORD isArrow; //32h
	WORD isBolt; //34h
	WORD isMiscProj; //36h
};

struct ITEM_EFFECT { //Size 30h, ItmFileEffect, SplFileEffect
//Constructor: 0x4FFC3E
	WORD opcode; //0h
	BYTE target; //2h
	BYTE power; //3h
	DWORD param1; //4h
	DWORD param2; //8h
	BYTE timing; //ch

	//bit0: Dispellable
	//bit1: Ignore Resistance
	BYTE flags; //dh

	DWORD duration; //eh
	BYTE highProb; //12h
	BYTE lowProb; //13h
	ResRef resource; //14h
	DWORD numDiceOrMaxLevel; //1ch
	DWORD sizeDiceOrMinLevel; //20h
	DWORD saveType; //24h
	DWORD saveBonus; //28h
	DWORD u2c; //2ch
};

//Spl
struct SplFileAbility { //Size 28h
	BYTE type; //0h
	BYTE u1;
	BYTE loc; //2h
	BYTE u3;
	ResRef memIcon; //4h
	BYTE targetType; //ch
	BYTE targetNum; //dh
	WORD range; //eh
	WORD levelReq; //10h
	DWORD castSpeed; //12h
	WORD sizeDice; //16h
	WORD nDice; //18h
	WORD enchanted; //1ah
	WORD damType; //1ch
	WORD nEffects; //1eh
	WORD offEffects; //20h
	WORD nCharges; //22h
	WORD chargeType; //24h
	WORD projIdx; //26h
};

//Vef
struct VefFileComponent { //Size E0h
	DWORD nStartDelay; //0h, CVisualEffect frame to start
	//the specific AiUpdate to reload the animation
	//i.e. compares to CVisualEffect.u272, when u272 == this, then is reloaded

	DWORD u4; //unused
	DWORD nRestartTime; //8h, how many ticks to reload
	//if 0, purge this VefComponent; otherwise, u0+=u8

	DWORD type; //ch, 1 = load Vvc/Bam, 2 = CreateVisualEffect() from resref (Vef/Vvc/Bam), else = play sound in resref
	ResRef resource; //10h, vvc/bam/wav
	DWORD dwFlags; //18h, bit0: sets uae of CVefVidCell (continuous cycles)
	DWORD u1c[49]; //unmarshalled but unused?
};

//Vvc
struct VvcFileData { //Size 1E0h
//as per VVC file without char[8] header
	ResRef nameAnim1; //0h
	ResRef nameAnim2; //8h
	DWORD displayFlags; //10h
	DWORD u14;
	DWORD seqFlags; //18h
	DWORD u1c;
	POINT ptOffset; //20h
	BOOL bUseOrientation;
	DWORD nFrameRate; //2ch
	DWORD nOrientations; //30h
	DWORD nBaseOrientation; //34h
	DWORD posFlags; //38h
	ResRef nameBitmapPalette; //3ch
	DWORD zPos; //44h
	DWORD centreX; //48h
	DWORD centreY; //4ch
	DWORD glowBrightness; //50h
	DWORD duration; //54h
	ResRef name; //58h, unused
	DWORD cycleAnim1; //60h
	DWORD cycleAnim2; //64h
	DWORD cycleAnimCurrent; //68h
	BOOL bMultiCycle; //unused
	ResRef sound1; //70h
	ResRef sound2; //78h
	ResRef nameAnim3; //80h
	DWORD cycleAnim3; //88h
	ResRef sound3; //8ch
	char u90[0x150]; //unused
};

#endif //DATATYPES_H