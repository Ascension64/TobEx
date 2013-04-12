#ifndef FILEGAM_H
#define FILEGAM_H

#include "stdafx.h"
#include "resref.h"

#define MAX_NUM_POENTIAL_PLAYER_CHARACTERS          24

#define CGAMESAVE_NUM_QUICK_FORMATIONS          5
#define CGAMESAVE_FORMATION_FOLLOW              0
#define CGAMESAVE_FORMATION_T                   1
#define CGAMESAVE_FORMATION_GATHER              2
#define CGAMESAVE_FORMATION_4AND2               3
#define CGAMESAVE_FORMATION_3BY2                4
#define CGAMESAVE_FORMATION_PROTECT             5
#define CGAMESAVE_FORMATION_2BY3                6
#define CGAMESAVE_FORMATION_RANK                7
#define CGAMESAVE_FORMATION_V                   8
#define CGAMESAVE_FORMATION_WEDGE               9
#define CGAMESAVE_FORMATION_S                   10
#define CGAMESAVE_FORMATION_LINE                11
#define CGAMESAVE_FORMATION_NONE                12

#define CGAMESAVE_GROUP_INVENTORY_SIZE          100

// bit pair flags
#define WEATHER_WEATHER_MASK                                    0x0003
#define WEATHER_RAINSNOW_LEVEL_MASK                             0x000c
#define WEATHER_WIND_MASK                                       0x0030
#define WEATHER_LIGHTNING_MASK                                  0x00c0

#define CINFINITY_WEATHER_TYPE_NOWEATHER                        0x0000
#define CINFINITY_WEATHER_TYPE_RAIN                             0x0001
#define CINFINITY_WEATHER_TYPE_SNOW                             0x0002
#define CINFINITY_WEATHER_TYPE_FOG                              0x0003

#define CINFINITY_WEATHER_RAINLEVEL_NORAIN                      0x0000
#define CINFINITY_WEATHER_RAINLEVEL_LIGHTRAIN                   0x0004
#define CINFINITY_WEATHER_RAINLEVEL_MEDIUMRAIN                  0x0008
#define CINFINITY_WEATHER_RAINLEVEL_HEAVYRAIN                   0x000C

#define CINFINITY_WEATHER_SNOWLEVEL_NOSNOW                      CINFINITY_WEATHER_RAINLEVEL_NORAIN
#define CINFINITY_WEATHER_SNOWLEVEL_LIGHTSNOW                   CINFINITY_WEATHER_RAINLEVEL_LIGHTRAIN
#define CINFINITY_WEATHER_SNOWLEVEL_MEDIUMSNOW                  CINFINITY_WEATHER_RAINLEVEL_MEDIUMRAIN
#define CINFINITY_WEATHER_SNOWLEVEL_HEAVYSNOW                   CINFINITY_WEATHER_RAINLEVEL_HEAVYRAIN

#define CINFINITY_WEATHER_WINDLEVEL_NOWIND                      0x0000
#define CINFINITY_WEATHER_WINDLEVEL_LIGHTWIND                   0x0010
#define CINFINITY_WEATHER_WINDLEVEL_MEDIUMWIND                  0x0020
#define CINFINITY_WEATHER_WINDLEVEL_HEAVYWIND                   0x0030

#define CINFINITY_WEATHER_LIGHTNINGFREQUENCY_NOLIGHTNING        0x0000
#define CINFINITY_WEATHER_LIGHTNINGFREQUENCY_RARELIGHTNING      0x0040
#define CINFINITY_WEATHER_LIGHTNINGFREQUENCY_REGULARLIGHTNING   0x0080
#define CINFINITY_WEATHER_LIGHTNINGFREQUENCY_FREQUENTLIGHTNING  0x00C0

#define CINFINITY_WEATHER_STORM_INCREASING                      0x0100

#define CSAVEDGAMEHEADER_FLAGS_AI_OFF                           0x00000001
#define CSAVEDGAMEHEADER_FLAGS_PANEL_MEDIUM                     0x00000002
#define CSAVEDGAMEHEADER_FLAGS_PANEL_LARGE                      0x00000004
#define CSAVEDGAMEHEADER_FLAGS_INTERFACE_HIDDEN                 0x00000010
#define CSAVEDGAMEHEADER_FLAGS_INTERFACE_LEFT                   0x00000020
#define CSAVEDGAMEHEADER_FLAGS_INTERFACE_RIGHT                  0x00000040
#define CSAVEDGAMEHEADER_FLAGS_HIDE_AREA_NOTES                  0x00000080

#define CSAVEDGAMEHEADER_VERSION_BALDUR                         0x00000000
#define CSAVEDGAMEHEADER_VERSION_BALDURMP1                      0x00000001
#define CSAVEDGAMEHEADER_VERSION_BALDURMP2                      0x00000002
#define CSAVEDGAMEHEADER_VERSION_BALDUR2                        0x00000003
#define CSAVEDGAMEHEADER_VERSION_BALDUR2_ADDIN                  0x00000004
#define CSAVEDGAMEHEADER_VERSION_BALDUR2_ADDON                  0x00000005

struct GamFileHeader {
        DWORD       m_worldTime;
        SHORT       m_curFormation;
        SHORT       m_quickFormations[CGAMESAVE_NUM_QUICK_FORMATIONS];
        DWORD       m_nPartyGold;

        WORD        m_nPCAreaViewed;
        WORD        m_wWeatherFlags;

        DWORD       m_partyCreatureTableOffset;
        DWORD       m_partyCreatureTableCount;
        DWORD       m_partyInventoryTableOffset;
        DWORD       m_partyInventoryTableCount;
        DWORD       m_globalCreatureTableOffset;
        DWORD       m_globalCreatureTableCount;
        DWORD       m_globalVariablesOffset;
        DWORD       m_globalVariablesCount;
        RESREF      m_currentWorldArea;
        DWORD       m_currentLink; // editor: set to -1
        DWORD       m_journalEntriesCount;
        DWORD       m_journalEntriesOffset;
        LONG        m_reputation;
        RESREF      m_masterArea;
        DWORD       m_dwFlags;
        DWORD       m_versionNumber; // 0-BG 1-MP etc...
        DWORD       m_familiarsOffset;
        DWORD       m_storedLocationsOffset;
        DWORD       m_storedLocationsCount;
        DWORD       m_gameTime;

		DWORD       m_storedLocationsOffsetPocketPlane;
        DWORD       m_storedLocationsCountPocketPlane;

        DWORD       m_notUsed[13];
};

#define NUM_ALIGNMENTS 9
#define FAMILIAR_MAX_LEVEL 9
// do not use CAIOBJECTTYPE_NONE in editor
// use  index = (alignment/16-1)*3 + alignment%16-1;
#define CAIOBJECTTYPE_NONE                        0x00
#define CAIOBJECTTYPE_LAWFUL_GOOD                 0x11
#define CAIOBJECTTYPE_LAWFUL_NEUTRAL              0x12
#define CAIOBJECTTYPE_LAWFUL_EVIL                 0x13
#define CAIOBJECTTYPE_NEUTRAL_GOOD                0x21
#define CAIOBJECTTYPE_NEUTRAL                     0x22
#define CAIOBJECTTYPE_NEUTRAL_EVIL                0x23
#define CAIOBJECTTYPE_CHAOTIC_GOOD                0x31
#define CAIOBJECTTYPE_CHAOTIC_NEUTRAL             0x32
#define CAIOBJECTTYPE_CHAOTIC_EVIL                0x33

struct GamFileFamiliars {
        RESREF      m_resrefDefault[NUM_ALIGNMENTS];
        DWORD       m_resrefOffset; // at which is a list of RESREF's
        DWORD       m_resrefCount[NUM_ALIGNMENTS][FAMILIAR_MAX_LEVEL];
};

struct GamFileJournalEntry {
        STRREF  m_strEntry;
        DWORD   m_time;
        BYTE    m_chapter;
        BYTE    m_read;      // which characters have not read this entry
        BYTE    m_type;
        BYTE    m_character; // which character this entry is associated with (multiplayer)
};

#define GAME_PARTYCREATURE_SELECTED    0x0001
#define GAME_PARTYCREATURE_NO_AREA     0x8000   // editor: always set to zero.

#define CGAMESAVECHARACTER_NUM_QUICK_WEAPONS       4
#define CGAMESAVECHARACTER_NUM_QUICK_SPELLS        3
#define CGAMESAVECHARACTER_NUM_QUICK_ITEMS         3

#define CGAMESAVECHARACTER_NUM_STATS_SPELLS       4
#define CGAMESAVECHARACTER_NUM_STATS_WEAPONS      4

struct GamFilePartyCreature {
        WORD        m_wFlags;           // editor: These two members have been separated
        WORD        m_portraitId;       // editor: These two members have been separated
        DWORD       m_creatureOffset;
        DWORD       m_creatureSize;
        RESREF      m_creatureResRef;
        DWORD       m_creatureFacing;
        RESREF      m_areaName;
        WORD        m_posX;
        WORD        m_posY;
        WORD        m_posViewX;
        WORD        m_posViewY;
        WORD        m_nModalState;
        SHORT       m_nHappiness;
        LONG        m_nNumberOfTimesInteractedWith[MAX_NUM_POENTIAL_PLAYER_CHARACTERS];
        SHORT       m_quickWeaponsItemNum[CGAMESAVECHARACTER_NUM_QUICK_WEAPONS];
        SHORT       m_quickWeaponsAbilityNum[CGAMESAVECHARACTER_NUM_QUICK_WEAPONS];
        RESREF      m_quickSpellsSpellId[CGAMESAVECHARACTER_NUM_QUICK_SPELLS];
        SHORT       m_quickItemsItemNum[CGAMESAVECHARACTER_NUM_QUICK_ITEMS];
        SHORT       m_quickItemsAbilityNum[CGAMESAVECHARACTER_NUM_QUICK_ITEMS];
        SCRIPTNAME  m_name;
        DWORD       m_numberTimesTalkedTo;

        STRREF      m_strStrongestKillName;
        DWORD       m_nStrongestKillXPValue;
        ULONG       m_nPreviousTimeWithParty;
        ULONG       m_nJoinPartyTime;
        BOOLEAN     m_bWithParty;
		char		m_pad1[2];
		char		m_cFirstResSlot;
        DWORD       m_nChapterKillsXPValue;
        DWORD       m_nChapterKillsNumber;
        DWORD       m_nGameKillsXPValue;
        DWORD       m_nGameKillsNumber;

        RESREF      m_lSpellStatsName[CGAMESAVECHARACTER_NUM_STATS_SPELLS];
        SHORT       m_lSpellStatsCount[CGAMESAVECHARACTER_NUM_STATS_SPELLS];
        RESREF      m_lWeaponStatsName[CGAMESAVECHARACTER_NUM_STATS_WEAPONS];
        SHORT       m_lWeaponStatsCount[CGAMESAVECHARACTER_NUM_STATS_WEAPONS];

		RESREF		m_secondarySounds;
};

struct GamFileStoredLocation { // for storing my location from a dream
        RESREF      m_areaName;
        WORD        m_xPos;
        WORD        m_yPos;
};

#endif //FILEGAM_H