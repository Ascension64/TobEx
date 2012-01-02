#ifndef DATATYPES_H
#define DATATYPES_H

#include "stdafx.h"
#include "resref.h"

//Bam, Bah
struct BamFileFrameEntry { //Size Ch
	short width;
	short height;
	short x;
	short y;
	unsigned int dwFlags;
};

//Bif
struct BifFileHeader { //Size 14h
	int dwFileType; //0h, of mmioFOURCC type
	int dwVersion; //4h
	int dwFiles; //8h
	int dwTiles; //ch
	int* pFiles; //10h
};

struct BifFileEntry { //Size 10h
	int dwResourceLocator; //0h
	int* pData; //4h
	int dwSize; //8h
	short dwFileType; //ch
	short eh; //eh
};

struct BifTileEntry { //Size 14h
	int dwResourceLocator; //0h
	int* pData; //4h
	int dwTiles; //8h
	int dwSize; //ch
	short dwFileType; //10h
	short u12; //12h
};

//Chu
struct ChuFileControlInfoBase { //Size Eh
	int id; //0h
	short posX; //4h
	short posY; //6h
	short width; //8h
	short height; //ah
	char type; //ch
	char ud; //dh
};

//Cre
struct ColorRangeValues { //Size 7h
	unsigned char colorMetal; //0h
	unsigned char colorMinor; //1h
	unsigned char colorMajor; //2h
	unsigned char colorSkin; //3h
	unsigned char colorLeather; //4h
	unsigned char colorArmor; //5h
	unsigned char colorHair; //6h
};

struct CreFileData { //Size 268h
	STRREF longNameStrRef; //0h, dialogue
	STRREF shortNameStrRef; //4h, strref tooltip
	unsigned int dwFlags; //8h
	int ExpWorth; //ch
	int currentExp; //10h
	int gold; //14h
	unsigned int stateFlags; //18h
	short currentHP; //1ch
	short maxHP; //1eh
	unsigned short animId; //20h
	short u22;
	ColorRangeValues colors; //24h
	char effType; //2bh, 0 = ITEM_EFFECT (Effect), 1 = CEffect
	ResRef smallPortrait; //2ch
	ResRef largePortrait; //34h
	char reputation; //3ch
	char hideInShadows;
	short ACNatural;
	short ACEffective; //40h
	short ACCrushingMod;
	short ACMissileMod;
	short ACPiercingMod;
	short ACSlashingMod;
	char THAC0;
	char numAttacks;
	char saveDeath; //4ch
	char saveWands;
	char savePoly;
	char saveBreath;
	char saveSpell; //50h
	char resistFire;
	char resistCold;
	char resistElectricity;
	char resistAcid;
	char resistMagic;
	char resistMagicFire;
	char resistMagicCold;
	char resistSlashing;
	char resistCrushing;
	char resistPiercing;
	char resistMissile;
	char detectIllusion;
	char setTraps;
	char lore;
	char lockpicking;
	char stealth; //60h
	char findTraps;
	char pickPockets;
	char fatigueLimit; //63h, fatigue above this value results in fatigue
	char intoxication;
	char luck; //65h
	char BG1ProfLSword; //66h, unused
	char BG1ProfSSword; //unused
	char BG1ProfBows; //unused
	char BG1ProfSpears; //unused
	char BG1ProfBlunt; //unused
	char BG1ProfSpiked; //unused
	char BG1ProfAxe; //unused
	char BG1ProfMissile; //unused
	char u6e;
	char u6f;
	char u70;
	char u71;
	char u72;
	char u73;
	char u74;
	char u75;
	char u76;
	char u77;
	char u78;
	char u79;
	char u7a;
	char tracking;
	char u7c[32];
	STRREF soundset[100]; //9ch
	char levelPrimary; //22ch
	char levelSecondary; //22dh
	char levelTertiary;
	unsigned char sex; //22fh
	char strength;
	char strengthEx;
	char intelligence;
	char wisdom;
	char dexterity;
	char constitution; //235h
	char charisma;
	char morale; //237h, range: 0-20, add -1 when PC dies
	char moraleBreak;
	char racialEnemy; //239h
	char moraleRecoveryTime;
	char u23b;
	unsigned short kit[2]; //23ch, [high WORD.low WORD]
	ResRef scriptOverride; //240h
	ResRef scriptClass;
	ResRef scriptRace; //250h
	ResRef scriptGeneral;
	ResRef scriptDefault; //260h
};

struct CreFileMemSpellLevel { //Size 10h
	short wLevel; //0h
	short wMaxMemSpells; //2h
	short wCurrMemSpells; //4h
	short type; //6h, 0 = priest, 1 = wizard, 2 = innate
	int index; //8h, of spell table
	int nNumSpells; //ch, count of spells
};

struct CreFileKnownSpell { //Size Ch
	ResRef name; //0h
	short level; //8h
	short type; //ah
};

struct CreFileMemSpell { //Size Ch
	ResRef name;

	//bit0: memorised
	//bit1: is a SPIN107, 108, 109, 110, 111 (a Paladin, Ranger, Druid special innate)
	unsigned short wFlags; //8h, bit0: MEMSPELL_MEMORIZED
	short ua; //pad
};

//Dlg
struct DlgFileState { //Size 10h
	STRREF strref; //0h
	int nResponseIdx; //4h, first response index
	int nResponses; //8h
	int nTriggerIdx; //ch
};

struct DlgFileResponse { //Size 20h
	unsigned int flags; //0h
	STRREF strref; //4h
	STRREF strrefJournal; //8h
	int nTriggerIdx; //ch
	int nActionIdx; //10h
	ResRef NextDialog; //14h
	int nNextDialogState; //1ch
};

//Eff
struct EffFileData { //size 108h
//AKA CGameEffectBase
	ResRef rHeader; //0h
	int nOpcode; //8h
	int nTarget; //ch
	unsigned int nSplLvl; //10h
	int nParam1; //14h
	int nParam2; //18h

	//note, 'set duration' will always set to a gameTime
	//0: convert to 1000, Apply now, set duration [sec]
	//1: Apply now, add to main effect list (permanent until death)
	//2: Apply now, add to equipped effect list (while equipped)
	//3: convert to 6, Apply later, set duration [sec]
	//4: convert to 7, Apply later, set duration [sec]
	//5: convert to 8, Apply later, set duration [sec]
	//6: if gameTime >= duration (ticks), convert to 1000, Apply now set duration [sec]
	//7: if gameTime >= duration (ticks), convert to 1, Apply now
	//8: if gameTime >= duration (ticks), convert to 2, Apply now
	//9: Apply now, will not be removed from CEffectList
	//10: convert to 1000, Apply now, set duration (duration in ticks)
	//1000: if gameTime < duration (ticks), Apply; else purge
	int nTiming; //1ch, in seconds (converted to ticks)

	unsigned int nDuration; //20h
	short wProbHigh; //24h
	short wProbLow; //26h
	ResRef rResource; //28h
	int nDice; //30h
	int nDieSides; //34h
	unsigned int nSaveType; //38h
	int nSaveBonus; //3ch
	BOOL bStoreLocalVariableParam; //40h
	int nType1; //44h
	int u4c; //48h
	int nLevelMin; //4ch
	int nLevelMax; //50h
		
	//bit0: CEFFECT_DISPELLABLE
	//bit1: CEFFECT_IGNORE_RESISTANCE
	//bit2: CEFFECT_IGNORE_SPELL_LVL_RESISTANCE (only for BounceSplLvl[Dec], ProtSplLvl[Dec], and SplLvlTrap; does not affect ProtSplLvl)
	unsigned int dwFlags; //54h, DispelResistFlags
		
	int nParam3; //58h
	int nParam4; //5ch
	int u64; //60h
	int u68; //64h
	ResRef rResource2; //68h
	ResRef rResource3; //70h
	POINT ptSource; //78h
	POINT ptDest; //80h
	int nParentResourceType; //88h, 0 = none, 1 = SPL, 2 = ITM
	ResRef rParentResource; //8ch
	unsigned int dwParentFlags; //94h, dwFlags of SplFileData or dwFlags of ItmFileAbility
	int nParentProjectile; //98h, PROJECTL.IDS
	int nParentItemSlot; //9ch
	char variable[32]; //a0h
	int nSourceCreLevel; //c0h
	BOOL bDoSingleUse; //c4h, all effects start with 1, some opcodes will check this, do once off stuff, and then set to 0
	int nType2; //c8h
	int ud0[15]; //cch
};

//Itm
struct ItmFileAbility { //Size 38h
	char attackType; //0h
	char idReq; //1h
	char loc; //2h
	char u3;
	ResRef useIcon; //4h
	char targetType; //ch
	char targetCnt; //dh
	short range; //eh
	short projType; //10h
	short speed; //12h
	short toHitBonus; //14h
	char sizeDice; //16h
	char nType1; //17h
	char nDice; //18h
	char nType2; //19h
	short damBonus; //1ah
	short damType; //1ch
	short nEffects; //1eh
	short offEffects; //20h
	short charges; //22h
	short chargeType; //24h
	unsigned int flags; //26h
	short projIdx; //2ah
	short meleeIdx[3]; //2ch
	short isArrow; //32h
	short isBolt; //34h
	short isMiscProj; //36h
};

struct ITEM_EFFECT { //Size 30h, ItmFileEffect, SplFileEffect
//Constructor: 0x4FFC3E
	short opcode; //0h
	char target; //2h
	char power; //3h
	int param1; //4h
	int param2; //8h
	char timing; //ch

	//bit0: Dispellable
	//bit1: Ignore Resistance
	unsigned char flags; //dh

	int duration; //eh
	char highProb; //12h
	char lowProb; //13h
	ResRef resource; //14h
	int numDiceOrMaxLevel; //1ch
	int sizeDiceOrMinLevel; //20h
	unsigned int saveType; //24h
	int saveBonus; //28h
	int u2c; //2ch
};

//Spl
struct SplFileAbility { //Size 28h
	char type; //0h
	char u1;
	char loc; //2h
	char u3;
	ResRef memIcon; //4h
	char targetType; //ch
	char targetNum; //dh
	short range; //eh
	short wMinLevel; //10h
	int castSpeed; //12h
	short sizeDice; //16h
	short nDice; //18h
	short enchanted; //1ah
	short damType; //1ch
	short wNumEffects; //1eh
	short wEffectIdx; //20h
	short nCharges; //22h
	short chargeType; //24h
	short projIdx; //26h
};

//Sto
struct StoFileData { //Size 94h
	int type; //0h
	STRREF name; //4h
	unsigned int flags; //8h
	int nSellPercent; //ch
	int nBuyPercent; //10h
	int nDepreciationRate; //14h
	short nStealFailPercent; //18h
	short nMaxItems; //1ah
	long u1c[2]; //1ch
	int* pItemTypesBought; //24h
	int nItemTypesBought; //28h
	int* pItemsSold; //2ch
	int nItemsSold; //30h
	int nLore; //34h
	int nPriceID; //38h
	ResRef RumoursTavern; //3ch
	int* pDrinks; //40h
	int nDrinks; //48h
	ResRef RumoursTemple; //4ch
	int flagsRoom; //54h
	int nPriceRoomPeasant; //58h
	int nPriceRoomMerchant; //5ch
	int nPriceRoomNoble; //60h
	int nPriceRoomRoyal; //64h
	int* pCures; //68h
	int nCures; //6ch
	int u70[9];
};

struct StoFileBuyType { //Size 4h
	int type;
};

struct StoFileDrink { //Size 14h
//corresponds to 'Drinks for sale' extended header
	ResRef rumour; //0h
	STRREF name; //8h
	int price; //ch
	int drinkStrength; //10h
};

struct StoFileItem { //Size 1Ch
//corresponds to 'Item for sale' extended header
	ResRef name; //0h
	short m_wWear; //8h, 0xFF + time until recharge in absolute game hours
	short m_wUsage1; //ah
	short m_wUsage2; //ch
	short m_wUsage3; //eh
	unsigned int dwFlags; //10h
	int m_nNumInStock; //14h
	BOOL m_bInfinite; //18h
};

struct StoFileSpell { //Size 10h
//corresponds to 'Cures for sale' extended header
	ResRef spell; //0h
	int price; //8h
};

//Vef
struct VefFileComponent { //Size E0h
	int nStartDelay; //0h, CVisualEffect frame to start
	//the specific AiUpdate to reload the animation
	//i.e. compares to CVisualEffect.u272, when u272 == this, then is reloaded

	int u4; //unused
	int nRestartTime; //8h, how many ticks to reload
	//if 0, purge this VefComponent; otherwise, u0+=u8

	int type; //ch, 1 = load Vvc/Bam, 2 = CreateVisualEffect() from resref (Vef/Vvc/Bam), else = play sound in resref
	ResRef resource; //10h, vvc/bam/wav
	unsigned int dwFlags; //18h, bit0: multicycle, sets uae of CVefVidCell
	int u1c[49]; //unmarshalled but unused?
};

//Vvc
struct VvcFileData { //Size 1E4h
	ResRef nameAnim1; //0h
	ResRef nameAnim2; //8h
	unsigned int displayFlags; //10h
	int u14;
	unsigned int seqFlags; //18h
	int u1c;
	POINT ptOffset; //20h
	BOOL bUseOrientation; //28h
	int nFrameRate; //2ch
	int nOrientations; //30h
	int nBaseOrientation; //34h
	unsigned int posFlags; //38h
	ResRef nameBitmapPalette; //3ch
	int zPos; //44h
	POINT ptCentre; //48h
	int glowBrightness; //50h
	int duration; //54h
	ResRef name; //58h, unused
	int animCycleBegin; //60h
	int animCycleMiddle; //64h
	int currCycle; //68h
	BOOL bMultiCycle; //unused
	ResRef soundBegin; //70h
	ResRef soundMiddle; //78h
	ResRef nameAnim3; //80h
	int cycleAnimEnd; //88h
	ResRef soundEnd; //8ch
	char u94[0x150]; //unused
};

#endif //DATATYPES_H