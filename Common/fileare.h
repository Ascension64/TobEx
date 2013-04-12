#ifndef FILEARE_H
#define FILEARE_H

#include "stdafx.h"
#include "resref.h"

#define AREA_EDGEFLAGS_PARTYREQUIRED	1
#define AREA_EDGEFLAGS_PARTYENABLED		2

#define AREA_AREATYPE_OUTDOOOR		1
#define AREA_AREATYPE_DAYNIGHT		2
#define AREA_AREATYPE_WEATHER		4
#define AREA_AREATYPE_CITY			8
#define AREA_AREATYPE_FOREST		16
#define AREA_AREATYPE_DUNGEON		32
#define AREA_AREATYPE_EXTENDEDNIGHT	64
#define AREA_AREATYPE_CANRESTOTHER	128

#define AREA_AREAFLAGS_NOSAVE		0x00000001
#define AREA_AREAFLAGS_TUTORIALAREA 0x00000002
#define AREA_AREAFLAGS_NONCOMBAT	0x00000004
#define AREA_AREAFLAGS_BROWNSCALE	0x00000008

struct AreFileHeader { //Size 4Ch
	RESREF m_rAeaName; //0h, used for LM, LN, HT, wed, Nwed
	DWORD m_dwLastSaved; //8h, in game time (script rounds)
	DWORD m_dwFlags; //ch
	RESREF m_rAreaEdgeNorth; //10h
	DWORD m_dwFlagsEdgeNorth; //18h
	RESREF m_rAreaEdgeEast; //1ch
	DWORD m_dwFlagsEdgeEast; //24h
	RESREF m_rAreaEdgeSouth; //28h
	DWORD m_dwFlagsEdgeSouth; //30h
	RESREF m_rAreaEdgeWest; //34h
	DWORD m_dwFlagsEdgeWest; //3ch
	WORD m_wAreaType; //40h
	WORD m_wRainProbability; //42h
	WORD m_wSnowProbability; //44h
	WORD m_wFogProbability; //46h
	WORD m_wLightningProbability; //48h
	WORD m_wBaseWindSpeed; //4ah
};

struct AreFileOffsets {
	DWORD m_dwCreatureTableOffset;
	WORD m_wCreatureTableCount;
	WORD m_wTriggerObjectListCount;
	DWORD m_dwTriggerObjectListOffset;
	DWORD m_dwRandomMonsterSpawningPointTableOffset;
	DWORD m_dwRandomMonsterSpawningPointTableCount;
	DWORD m_dwCharacterEntryPointTableOffset;
	DWORD m_dwCharacterEntryPointTableCount;
	DWORD m_dwContainerListOffset;
	WORD m_dwContainerListCount;
	WORD m_wItemObjectsCount;
	DWORD m_dwItemObjectsOffset;
	DWORD m_dwPointsOffset;
	WORD m_wPointsCount;
	WORD m_wSoundObjectCount;
	DWORD m_dwSoundObjectOffset;
	DWORD m_dwAreaScriptVariablesOffset;
	WORD m_wAreaScriptVariablesCount;
	WORD m_wTiledObjectFlagsCount;
	DWORD m_dwTiledObjectFlagsOffset;
	RESREF m_rScript;
	DWORD m_dwVisibilityMapCount;
	DWORD m_dwVisibilityMapOffset;
	DWORD m_dwDoorObjectListCount;
	DWORD m_dwDoorObjectListOffset;
	DWORD m_dwStaticObjectListCount;
	DWORD m_dwStaticObjectListOffset;
	DWORD m_dwTiledObjectListCount;
	DWORD m_dwTiledObjectListOffset;
	DWORD m_dwAreaSoundsAndMusicOffset;
	DWORD m_dwRestingEncounterOffset;
	DWORD m_dwUserMapNotesOffset;
	DWORD m_dwUserMapNotesCount;
	DWORD m_dwProjectileTableOffset;
	DWORD m_dwProjectileTableCount;
	RESREF m_rRestMovieDay;
	RESREF m_rRestMovieNight;
	DWORD m_dwNotUsed[14];
};

#define AREAFILECREATURE_TYPE_NORMAL	0
#define AREAFILECREATURE_TYPE_RANDOM	1

#define AREAFILECREATURE_FLAGS_ENABLED		1
#define AREAFILECREATURE_FLAGS_HASSEENPARTY	2
#define AREAFILECREATURE_FLAGS_INVULNERABLE	4
#define AREAFILECREATURE_FLAGS_NAMEOVERRIDE	8

struct AreFileCreature {
	SCRIPTNAME m_szScriptName;   // set to creature scriptname if there, otherwise resref
	WORD m_wPosX;
	WORD m_wPosY;
	WORD m_wStartingPosX;
	WORD m_wStartingPosY;
	DWORD m_dwFlags;  //enabled by default
	WORD m_wType;
	char m_cFirstResSlot; //The resref of my first character
	BYTE m_cStructureAlignment1[1];
	DWORD m_dwAnimationType;  // this is only needed by editor to drastically speed up load times.
	WORD m_wFacing;
	BYTE m_cStructureAlignment2[2];
	DWORD m_dwExpirationTime;
	WORD m_wHuntingRange;
	WORD m_wFollowRange;
	DWORD m_dwTimeOfDayVisible;
	DWORD m_dwNumberTimesTalkedTo;
	RESREF m_rDialogOverride;
	RESREF m_rOverrideScriptOverride;
	RESREF m_rGeneralScriptOverride;
	RESREF m_rClassScriptOverride;
	RESREF m_rRaceScriptOverride;
	RESREF m_rDefaultScriptOverride;
	RESREF m_rSpecificScriptOverride;
	RESREF m_rCreatureData;
	DWORD m_dwCreatureOffset;
	DWORD m_dwCreatureSize;
	DWORD m_dwNotUsed[32];
};

#define AREFILERESTENCOUNTER_NUM_RANDOM 10

struct AreFileRestEncounter { //Size E4h
	SCRIPTNAME m_szScriptName;
	STRREF m_strrefRandomCreatureString[AREFILERESTENCOUNTER_NUM_RANDOM];
	RESREF m_rRandomCreature[AREFILERESTENCOUNTER_NUM_RANDOM];
	WORD m_wRandomCreatureNum;
	WORD m_wDifficulty;
	DWORD m_dwLifeSpan;
	WORD m_wHuntingRange;
	WORD m_wFollowRange;
	WORD m_wMaxTypeNum;
	WORD m_wActivated;
	WORD m_wProbDay; // per hour
	WORD m_wProbNight; // per hour
	DWORD m_dwNotUsed[14];
};

#define AREFILERANDOMMONSTERSPAWNINGPOINT_NUM_RANDOM	10

#define AREFILERANDOMMONSTERSPAWNINGPOINT_FLAGS_NOTCONTINOUS		0x0001
#define AREFILERANDOMMONSTERSPAWNINGPOINT_FLAGS_DEACTIVATEONSPAWN	0x0002
#define AREFILERANDOMMONSTERSPAWNINGPOINT_FLAGS_SPAWNED			0x0004  // not an editor flag

struct AreFileRandomMonsterSpawningPoint { //Size C8h
	SCRIPTNAME m_szScriptName;
	WORD m_wPosX;
	WORD m_wPosY;
	RESREF m_rRandomCreature[AREFILERANDOMMONSTERSPAWNINGPOINT_NUM_RANDOM];
	WORD m_wRandomCreatureNum;
	WORD m_wDifficulty;
	WORD m_wSpawningRate;
	WORD m_wFlags;
	DWORD m_dwLifeSpan;
	WORD m_wHuntingRange;
	WORD m_wFollowRange;
	WORD m_wMaxTypeNum;
	WORD m_wActivated;
	DWORD m_dwTimeOfDayVisible;
	WORD m_wProbDay;      // 1-100, 0 => 100
	WORD m_wProbNight;    // 1-100, 0 => 100
	DWORD m_dwNotUsed[14];
};

#define FACING_DIR_S     0
#define FACING_DIR_SW    2
#define FACING_DIR_W     4
#define FACING_DIR_NW    6
#define FACING_DIR_N     8
#define FACING_DIR_NE   10
#define FACING_DIR_E    12
#define FACING_DIR_SE   14
#define FACING_DIR_SSW   1
#define FACING_DIR_SWW   3
#define FACING_DIR_NWW   5
#define FACING_DIR_NNW   7
#define FACING_DIR_NNE   9
#define FACING_DIR_NEE  11
#define FACING_DIR_SEE  13
#define FACING_DIR_SSE  15

struct AreFileCharacterEntryPoint {
	SCRIPTNAME m_szEntryName;
	WORD m_wStartX;
	WORD m_wStartY;
	DWORD m_dwFacing;
	DWORD m_dwNotUsed[16];
};

#define AREA_CONTAINERTYPE_BAG			0x0001
#define AREA_CONTAINERTYPE_CHEST		0x0002
#define AREA_CONTAINERTYPE_DRAWER		0x0003
#define AREA_CONTAINERTYPE_PILE			0x0004
#define AREA_CONTAINERTYPE_TABLE		0x0005
#define AREA_CONTAINERTYPE_SHELF		0x0006
#define AREA_CONTAINERTYPE_ALTAR		0x0007
#define AREA_CONTAINERTYPE_NONVISIBLE	0x0008
#define AREA_CONTAINERTYPE_SPELLBOOK	0x0009
#define AREA_CONTAINERTYPE_BODY			0x000A
#define AREA_CONTAINERTYPE_BARREL		0x000B
#define AREA_CONTAINERTYPE_CRATE		0x000C

#define AREA_CONTAINERFLAGS_LOCKED				0x0001
#define AREA_CONTAINERFLAGS_DISABLEIFNOOWNER	0x0002
#define AREA_CONTAINERFLAGS_MAGICALLYLOCKED		0x0004
#define AREA_CONTAINERFLAGS_TRAPRESET			0x0008
#define AREA_CONTAINERFLAGS_REMOVEONLY			0x0010
#define AREA_CONTAINERFLAGS_DISABLED			0x0020

struct AreFileContainer {
	SCRIPTNAME m_szScriptName;
	WORD m_wPosX;
	WORD m_wPosY;
	WORD m_wContainerType;
	WORD m_wLockDifficulty;	   // 0 - 100
	DWORD m_dwFlags;
	WORD m_wTrapDetectionDifficulty;  // 0 - 100
	WORD m_wTrapRemovalDifficulty;   // 0 - 100
	WORD m_wTrapActivated;
	WORD m_wTrapDetected;
	WORD m_wPosXTrapOrigin;
	WORD m_wPosYTrapOrigin;
	WORD m_wBoundingRectLeft;
	WORD m_wBoundingRectTop;
	WORD m_wBoundingRectRight;
	WORD m_wBoundingRectBottom;
	DWORD m_dwStartingItem;
	DWORD m_dwItemCount;
	RESREF m_rScript;
	DWORD m_dwPickPointStart;
	WORD m_wPickPointCount;
	WORD m_wTriggerRange;
	SCRIPTNAME m_szOwnedBy;		  // ScriptName of Owner
	RESREF m_rKeyType;		  // Item required to Unlock
	DWORD m_dwBreakDifficulty;
	STRREF m_strrefNotPickable;
	DWORD m_dwNotUsed[14];
};

#define AREFILE_SOUNDOBJECT_NUM					10

#define AREFILE_SOUNDOBJECTFLAG_ACTIVATED			0x0001
#define AREFILE_SOUNDOBJECTFLAG_LOOPING				0x0002
#define AREFILE_SOUNDOBJECTFLAG_NOTRANGED			0x0004
#define AREFILE_SOUNDOBJECTFLAG_RANDOMPICK			0x0008
#define AREFILE_SOUNDOBJECTFLAG_DISABLELOWMEMORY	0x0010

struct AreFileSoundObject { //Size D4h
	SCRIPTNAME m_szScriptName; // FirstSixCharacters is the AREANAME
	WORD m_wPosX;
	WORD m_wPosY;
	WORD m_wRange;
	BYTE m_cStructureAlignment1[2];
	DWORD m_dwPitchVariance;
	WORD m_wVolumeVariance;
	WORD m_wVolume;
	RESREF m_rSoundObject[AREFILE_SOUNDOBJECT_NUM];
	WORD m_wSoundObjectNum;
	BYTE m_cStructureAlignment2[2];
	DWORD m_dwPeriod;
	DWORD m_dwPeriodVariance;   // + or - to period
	DWORD m_dwTimeOfDayActive;  // bits 0 - 23 denote hours
	DWORD m_dwFlags;
	DWORD m_dwNotUsed[16];
};

struct AreSoundsAndMusic { //Size 90h
	DWORD m_dwDayMusic; //0h
	DWORD m_dwNightMusic; //4h
	DWORD m_dwBattleWinningMusic; //8h
	DWORD m_dwBattleStandOffMusic; //ch
	DWORD m_dwBattleLosingMusic; //10h
	DWORD m_dwAlt1Music0; //14h
	DWORD m_dwAlt1Music1; //18h
	DWORD m_dwAlt1Music2; //1ch
	DWORD m_dwAlt1Music3; //20h
	DWORD m_dwAlt1Music4; //24h

	RESREF m_rDayAmbient; //28h
	RESREF m_rDayAmbientExtended; //30h
	DWORD m_dwDayAmbientVolume; //38h
	RESREF m_rNightAmbient; //3ch
	RESREF m_rNightAmbientExtended; //44h
	DWORD m_dwNightAmbientVolume; //4ch
	DWORD m_dwNotUsed[16]; //50h
};

// exclusive
#define AREA_TRIGGEROBJECTTYPE_PROXIMITYTRIGGER	0x0000
#define AREA_TRIGGEROBJECTTYPE_INFO				0x0001
#define AREA_TRIGGEROBJECTTYPE_TRAVEL			0x0002

// bit flags
#define AREA_TRIGGEROBJECTFLAGS_KEYMUSTBEINPOSSESION    0x0001
#define AREA_TRIGGEROBJECTFLAGS_TRAPRESET				0x0002
#define AREA_TRIGGEROBJECTFLAGS_PARTYREQUIRED			0x0004
#define AREA_TRIGGEROBJECTFLAGS_TRAPDETECTABLE			0x0008
#define AREA_TRIGGEROBJECTFLAGS_MONSTERACTIVATED		0x0010
//New trap flags
#define AREA_TRIGGEROBJECTFLAGS_TUTORIAL		0x0020
#define AREA_TRIGGEROBJECTFLAGS_ALLCREATURES	0x0040
#define AREA_TRIGGEROBJECTFLAGS_NOSTRING		0x0080
//Area transition flag
#define AREA_TRIGGEROBJECTFLAGS_DISABLED		0x0100
#define AREA_TRIGGEROBJECTFLAGS_PARTYONLY		0x0200
#define AREA_TRIGGEROBJECTFLAGS_ENABLEWALKTO	0x0400
#define AREA_TRIGGEROBJECTFLAGS_DOORCLOSED		0x0800

struct AreFileTriggerObject {
	SCRIPTNAME m_szScriptName;
	WORD m_wTriggerType;
	WORD m_wBoundingRectLeft;
	WORD m_wBoundingRectTop;
	WORD m_wBoundingRectRight;
	WORD m_wBoundingRectBottom;
	WORD m_wPickPointCount;
	DWORD m_dwPickPointStart;
	DWORD m_dwTriggerValue;
	DWORD m_dwCursorType;
	RESREF m_rNewArea;
	SCRIPTNAME m_szNewEntryPoint;
	DWORD m_dwFlags;
	STRREF m_strrefDescription;
	WORD m_wTrapDetectionDifficulty;
	WORD m_wTrapDisarmingDifficulty;
	WORD m_wTrapActivated;
	WORD m_wTrapDetected;
	WORD m_wPosXTrapOrigin;
	WORD m_wPosYTrapOrigin;
	RESREF m_rKeyType;
	RESREF m_rScript;
	WORD m_wTransitionWalkToX;
	WORD m_wTransitionWalkToY;
	DWORD m_dwNotUsed[15];
};

// bit flags
#define AREA_DOOROBJECTFLAGS_DOOROPEN			0x0001
#define AREA_DOOROBJECTFLAGS_DOORLOCKED			0x0002
#define AREA_DOOROBJECTFLAGS_TRAPRESET			0x0004
#define AREA_DOOROBJECTFLAGS_TRAPDETECTABLE		0x0008
#define AREA_DOOROBJECTFLAGS_BROKEN				0x0010
#define AREA_DOOROBJECTFLAGS_CANTCLOSE			0x0020
//#define AREA_DOOROBJECTFLAGS_DETECTED			0x0040
#define AREA_DOOROBJECTFLAGS_SECRET				0x0080
#define AREA_DOOROBJECTFLAGS_DETECTEDSECRET		0x0100
#define AREA_DOOROBJECTFLAGS_GATE				0x0200     // means you can see though it
#define AREA_DOOROBJECTFLAGS_USEUPKEY			0x0400     // Subtract a use from the key every time that you toggle door
#define AREA_DOOROBJECTFLAGS_DONTCHECKCLOSED	0x0800     // don't check obstacles when closing door

struct AreFileDoorObject {
	SCRIPTNAME m_szScriptName;
	RESREF m_rDoorID;
	DWORD m_dwFlags;
	DWORD m_dwOpenSelectionPointStart;  // Open and Closed Polys
	WORD m_wOpenSelectionPointCount;
	WORD m_wClosedSelectionPointCount;
	DWORD m_dwClosedSelectionPointStart;
	WORD m_wOpenBoundingRectLeft;
	WORD m_wOpenBoundingRectTop;
	WORD m_wOpenBoundingRectRight;
	WORD m_wOpenBoundingRectBottom;
	WORD m_wClosedBoundingRectLeft;
	WORD m_wClosedBoundingRectTop;
	WORD m_wClosedBoundingRectRight;
	WORD m_wClosedBoundingRectBottom;
	DWORD m_dwOpenSearchSquaresStart;   // Open and Closed Search Squares.
	WORD m_wOpenSearchSquaresCount;   //  Stored in Point List
	WORD m_wClosedSearchSquaresCount;
	DWORD m_dwClosedSearchSquaresStart;
	SHORT m_wHitPoints;
	SHORT m_wArmourClass;
	RESREF m_rOpenSound;
	RESREF m_rCloseSound;
	DWORD m_dwCursorType;
	WORD m_wTrapDetectionDifficulty;
	WORD m_wTrapDisarmingDifficulty;
	WORD m_wTrapActivated;
	WORD m_wTrapDetected;
	WORD m_wPosXTrapOrigin;
	WORD m_wPosYTrapOrigin;
	RESREF m_rKeyType;
	RESREF m_rScript;
	DWORD m_dwDetectionDifficulty;
	DWORD m_dwLockDifficulty; // 0 - 100
	WORD m_wPosXWalkTo1;
	WORD m_wPosYWalkTo1;
	WORD m_wPosXWalkTo2;
	WORD m_wPosYWalkTo2;
	STRREF m_strrefNotPickable;
	SCRIPTNAME m_szTriggerName;
	DWORD m_dwNotUsed[3];
};

#define AREA_TILEDOBJECT_SECONDARYSTATE	0x00000001
#define AREA_TILEDOBJECT_GATE			0x00000002  // means you can see through it

struct AreFileTiledObject {
	SCRIPTNAME m_szScriptName;
	RESREF m_rTileID;
	DWORD m_dwFlags;
	DWORD m_dwPrimarySearchSquaresStart;   // Open and Closed Search Squares.
	WORD m_wPrimarySearchSquaresCount;   //  Stored in Point List
	WORD m_wSecondarySearchSquaresCount;
	DWORD m_dwSecondarySearchSquaresStart;
	DWORD m_dwNotUsed[12];
};

// bit flags
#define AREA_STATICOBJECTFLAGS_ENABLED					0x0001
#define AREA_STATICOBJECTFLAGS_GLOWING					0x0002
#define AREA_STATICOBJECTFLAGS_ALLOWTINT				0x0004
#define AREA_STATICOBJECTFLAGS_STOPPED					0x0008
#define AREA_STATICOBJECTFLAGS_STARTATBEGINNING			0x0010    // animation starts with first frame (versus random frame)
#define AREA_STATICOBJECTFLAGS_USESTARTRANGE			0x0020    // animation starts with random frame in start range
#define AREA_STATICOBJECTFLAGS_IGNORECLIPPING			0x0040
#define AREA_STATICOBJECTFLAGS_DISABLEONSLOWMACHINES	0x0080
#define AREA_STATICOBJECTFLAGS_BACKLIST					0x0100
#define AREA_STATICOBJECTFLAGS_SEQUENCEALL				0x0200
#define AREA_STATICOBJECTFLAGS_PALETTE					0x0400
#define AREA_STATICOBJECTFLAGS_MIRROR					0x0800
#define AREA_STATICOBJECTFLAGS_NEVERDISABLE				0x1000

struct AreFileStaticObject { //Size 4Ch
	SCRIPTNAME m_szScriptName;
	WORD m_wPosX;
	WORD m_wPosY;
	DWORD m_dwTimeOfDayVisible;
	RESREF m_resref;
	DWORD m_dwSequence;
	DWORD m_dwFlags;
	short m_wHeight;
	WORD m_wTranslucency;
	WORD m_wStartFrameRange;
	BYTE m_cProbability;  // 1 to 100, default 100
	BYTE m_cPeriod; // 0 to 255, in seconds
	RESREF m_rPaletteResref;
	DWORD m_dwNotUsed[1];
};

struct AreFileProjectileObject {
	RESREF m_resref;
	DWORD m_dwEffectListOffset;
	WORD m_wEffectListCount;
	WORD m_wProjectileID;
	SHORT m_wDelayCount;
	SHORT m_wRepetitionCount;
	WORD m_wPosX;
	WORD m_wPosY;
	WORD m_wPosZ;
	BYTE m_cTargetType;
	char m_cPortraitNum;
};

struct ArePoint {
	WORD m_wXPos;
	WORD m_wYPos;
};

#define AREA_AREASCRIPTVARIABLES_TYPE_INT			0x0000
#define AREA_AREASCRIPTVARIABLES_TYPE_FLOAT			0x0001
#define AREA_AREASCRIPTVARIABLES_TYPE_SCRIPTNAME	0x0002
#define AREA_AREASCRIPTVARIABLES_TYPE_RESREF		0x0003
#define AREA_AREASCRIPTVARIABLES_TYPE_STRREF		0x0004
#define AREA_AREASCRIPTVARIABLES_TYPE_DWORD			0x0005

struct AreVariable {
	SCRIPTNAME m_szName;
	WORD m_wType;
	WORD m_wResRefType;
	DWORD m_dwValue;
	LONG m_nValue;
	double m_dFloatValue;
	SCRIPTNAME m_szStringValue;
};

#define AREA_USERNOTEFLAGS_DESIGNER  0x00000001
#define AREA_USERNOTEFLAGS_ICONMASK  0x11110000 /*this is where we store which icon to use*/

struct CAreaUserNote {
	WORD m_wStartX;
	WORD m_wStartY;
	STRREF m_strrefNote;
	DWORD m_dwflags;
	DWORD m_dwId; // for crossreferencing the buttons
	DWORD m_dwNotUsed[9];
};

#endif //FILEARE_H