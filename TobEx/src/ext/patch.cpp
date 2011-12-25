#include "patch.h"

#include <algorithm>
#include <vector>

#include "utils.h"
#include "scrcore.h"
#include "console.h"
#include "ScriptAction.h"
#include "InfGameCore.h"
#include "UserCommon.h"
#include "ChitinCore.h"

CRuleTable** ClassAbilityTable;

Data::Data() {
	dwAddress, nSize = 0;
	szBytes = NULL;
}

Data::Data(const Data& d) : dwAddress(d.dwAddress), nSize(d.nSize) {
	szBytes = new char[d.nSize];
	memcpy(szBytes, d.szBytes, d.nSize);
}

Data::Data(DWORD address, SIZE_T size, char bytes[]) : dwAddress(address), nSize(size) {
	szBytes = new char[size];
	memcpy(szBytes, bytes, size);
}

Data::~Data() {
	delete[] szBytes;
	szBytes = NULL;
}

DWORD Data::GetAddress() { return dwAddress; }
SIZE_T Data::GetSize() { return nSize; }
char* Data::GetBytes() { return szBytes; }

std::vector<Data> Patch::GetData() {
	return vData;
}

Patch::Patch(std::vector<Data> vData) : vData(vData) {}

void ApplyPatch(Data d) {
	void* address = reinterpret_cast<void*>(d.GetAddress());
	SIZE_T size = d.GetSize();
	DWORD oldProtect;
	VirtualProtect(address, size, PAGE_EXECUTE_READWRITE, &oldProtect);
	if ( !WriteProcessMemory(GetCurrentProcess(), address, d.GetBytes(), size, &size) ) {
		DWORD dwError = GetLastError();
		console.write("ApplyPatch(): WriteProcessMemory failed, address: 0x%x, error code: %d\r\n", 2, address, dwError);
	}
	VirtualProtect(address, size, oldProtect, &oldProtect);
	return;
}

void InitPatches() {
	std::vector<Patch> vPatchList;
	std::vector<Patch>::iterator vPatchItr;
	std::vector<Data> vDataList;

	//Charm patch
	if (GetIniValue("Engine", "Disable Silence On Charm")) {
		char bytes[] = {0xEB};
		vDataList.push_back( Data(0x8A11D4, 1, bytes) );
		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}
  
	//XP Patch
	if (GetIniValue("Engine", "Correct Experience Gain")) {
		char bytes[] = {0x64};
		vDataList.push_back( Data(0x6A97D5, 1, bytes) );
		vDataList.push_back( Data(0x6A9961, 1, bytes) );
		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}
  
	//Awaken opcode fix
	if (GetIniValue("Effect Opcodes", "Awaken Fix") || GetIniValue("Effect Opcodes", "Opcode Damage Mod")) {
		char bytes[] = {0x27};
		vDataList.push_back( Data(0x5035F4, 1, bytes) );
		vDataList.push_back( Data(0x50362C, 1, bytes) );
		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}

	//Cure Drunkenness opcode fix
	if (GetIniValue("Effect Opcodes", "Cure Drunk Fix")) {
		char bytes[] = {0x5E};
		vDataList.push_back( Data(0x52EB0E, 1, bytes) );
		vDataList.push_back( Data(0x52EB49, 1, bytes) );
		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}

	//Expand RND*.2DA
	if (GetIniValue("Engine", "Enable 99 Random Treasure Rows")) {
		char bytes[29] = {0x8B, 0x45, 0xF0, 0x36, 0x0F, 0xBE, 0x48, 0x06, 0x83, 0xE9, 0x30, 0x6B, 0xC9, 0x0A, 0x36, 0x02, 0x48, 0x07, 0x83, 0xE9, 0x31, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 };
	
		vDataList.push_back( Data(0x5A8607, 29, bytes) ); //RNDEQU
		vDataList.push_back( Data(0x5A8712, 29, bytes) ); //RNDTRE
		vDataList.push_back( Data(0x5A8829, 29, bytes) ); //RNDMAG
		vDataList.push_back( Data(0x5A8940, 29, bytes) ); //RNDWEP
		vDataList.push_back( Data(0x5A8A40, 29, bytes) ); //RNDSCR

		vDataList.push_back( Data(0x5A8E56, 29, bytes) ); //RNDEQU
		vDataList.push_back( Data(0x5A8F39, 29, bytes) ); //RNDTRE
		vDataList.push_back( Data(0x5A904F, 29, bytes) ); //RNDMAG
		vDataList.push_back( Data(0x5A9165, 29, bytes) ); //RNDSCR

		vDataList.push_back( Data(0x5A963A, 29, bytes) ); //RNDEQU
		vDataList.push_back( Data(0x5A971D, 29, bytes) ); //RNDTRE
		vDataList.push_back( Data(0x5A9833, 29, bytes) ); //RNDMAG
		vDataList.push_back( Data(0x5A9949, 29, bytes) ); //RNDWEP
		vDataList.push_back( Data(0x5A9A48, 29, bytes) ); //RNDSCR

		char bytes2[3] = { 0x90, 0x90, 0x90 };
		vDataList.push_back( Data(0x5A8656, 3, bytes2) ); //RNDEQU
		vDataList.push_back( Data(0x5A876D, 3, bytes2) ); //RNDTRE
		vDataList.push_back( Data(0x5A8884, 3, bytes2) ); //RNDMAG
		vDataList.push_back( Data(0x5A8984, 3, bytes2) ); //RNDTRE
		vDataList.push_back( Data(0x5A8A84, 3, bytes2) ); //RNDSCR

		vDataList.push_back( Data(0x5A8E9F, 3, bytes2) ); //RNDEQU
		vDataList.push_back( Data(0x5A8F94, 3, bytes2) ); //RNDTRE
		vDataList.push_back( Data(0x5A90AA, 3, bytes2) ); //RNDMAG
		vDataList.push_back( Data(0x5A91A9, 3, bytes2) ); //RNDSCR

		vDataList.push_back( Data(0x5A9683, 3, bytes2) ); //RNDEQU
		vDataList.push_back( Data(0x5A9778, 3, bytes2) ); //RNDTRE
		vDataList.push_back( Data(0x5A988E, 3, bytes2) ); //RNDMAG
		vDataList.push_back( Data(0x5A998D, 3, bytes2) ); //RNDTRE
		vDataList.push_back( Data(0x5A9A8C, 3, bytes2) ); //RNDSCR

		char bytes3[] = {0x8D};
		vDataList.push_back( Data(0x5A8625, 1, bytes3) ); //RNDEQU

		bytes3[0] = 0x8D;
		vDataList.push_back( Data(0x5A8730, 1, bytes3) ); //RNDTRE
		vDataList.push_back( Data(0x5A8847, 1, bytes3) ); //RNDMAG
		vDataList.push_back( Data(0x5A895E, 1, bytes3) ); //RNDWEP
		vDataList.push_back( Data(0x5A8A5E, 1, bytes3) ); //RNDWEP

		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}

	//Fix for setting CDerivedStats for permanent until death Improved Invisibility
	if (GetIniValue("Effect Opcodes", "Invisible Fix")) {
		char bytes2[] = {0x0A, 0x0B};
		vDataList.push_back( Data(0x5126F4, 2, bytes2) );
		vDataList.push_back( Data(0x512703, 2, bytes2) );
		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}
	
	//Failed pickpocket sends PickpocketFailed() trigger
	if (GetIniValue("Trigger", "Enable PickpocketFailed Trigger")) {
		char bytes[] = {0x22, 0x5F, 0xAA};
		vDataList.push_back( Data(0x9437B2, 3, bytes) );
		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}

	//No grey effect on stone skin
	if (GetIniValue("Effect Opcodes", "Disable Stoneskin Grey Colour")) {
		char bytes[] = {0x00};
		vDataList.push_back( Data(0x5399D4, 1, bytes) );
		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}

	//Correct dispel formula
	//Pseudocode
	//rand(); <--0 to 99
	//chance = 50
	//if (effectLevel < casterLevel) {
	//  chance += 10 * effectLevel - casterLevel <--brackets forgotten
	//} else {
	//  chance += 5 * (effectLevel - castLevel)
	//}
	//
	//if (rand = 0) {no dispel}
	//  elseif (rand > chance) {dispel}
	//    elseif (rand > 99) {dispel} <--change to 98, cannot roll > 100
	//      else {no dispel}
	if (GetIniValue("Effect Opcodes", "Dispel Formula Fix")) {
	    //fix brackets in formula when caster level > effect level
		char bytes[] = {0x8B, 0x4D, 0x1C, 0x81, 0xE1, 0xFF, 0x00, 0x00, 0x00, 0x2B, 0xC1, 0x6B, 0xC0, 0x0A};
		vDataList.push_back( Data(0x543F42, 14, bytes) );

		//correct 1% chance of always success
		char bytes2[] = {0x62};
		vDataList.push_back( Data(0x543FA6, 1, bytes2) );
	
		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}

	//Mirror image keeps caster level
	if (GetIniValue("Effect Opcodes", "Use Caster Level On Mirror Image")) {
	    //fix brackets in formula when caster level > effect level
		char bytes[] = {0x8B, 0x55, 0xD4, 0x8B, 0x4A, 0x48, 0x89, 0x48, 0x48, 0x83, 0xC0, 0x70, 0x83, 0xC2, 0x70, 0x8B, 0x4A, 0x54, 0x89, 0x48, 0x54, 0x8B, 0x4A, 0x5C, 0x89, 0x48, 0x5C, 0x90, 0x90, 0x90};
		vDataList.push_back( Data(0x521184, 30, bytes) );
	
		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}
	
	//Enlarge tooltip scroll
	if (GetIniValue("UI", "Enlarge Tooltip Scroll")) {
	    //fix brackets in formula when caster level > effect level
		char bytes[] = {0xE0};
		vDataList.push_back( Data(0x6739D9, 1, bytes) );
	
		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}
	
	//Apply 79 CASTINGLEVELBONUSMAGE and 80 CASTINGLEVELBONUSCLERIC casting level bonuses when casting spells
	if (GetIniValue("Engine", "Apply Casting Level Bonus")) {
		//spelltype PRIEST
		char bytes[26] = {0x8B, 0x4D, 0xE8, 0x0F, 0xBE, 0x91, 0xD0, 0x00, 0x00, 0x00, 0x03, 0xC2, 0x83, 0xF8, 0x01, 0x7E, 0x37, 0x89, 0x45, 0xB8, 0xEB, 0x39, 0x90, 0x90, 0x90, 0x90};
		vDataList.push_back( Data(0x951511, 26, bytes) );
		
		//spelltype WIZARD
		char bytes2[25] = {0x8B, 0x4D, 0xE0, 0x0F, 0xBE, 0x91, 0xCE, 0x00, 0x00, 0x00, 0x03, 0xC2, 0x83, 0xF8, 0x01, 0x7E, 0x37, 0x89, 0x45, 0xB4, 0xEB, 0x39, 0x90, 0x90, 0x90};
		vDataList.push_back( Data(0x9515B4, 25, bytes2) );

		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}

	//Correct random selection of animation soundsets
	if (GetIniValue("Sound", "Animation Sound Fix")) {
		//decrements the rand number so intervening sounds can be played correctly
		char bytes[7] = {0xF8, 0x49, 0x90, 0x90, 0x89, 0x4D, 0xF8};
		vDataList.push_back( Data(0x642E0D, 7, bytes) );
	
		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}

	//Correct 'periodic fidget' existance sound
	if (GetIniValue("Sound", "Existence Sound Fix")) {
		//correct func parameter to determine number of available EXISTANCE sounds
		char bytes[1] = {0x46};
		vDataList.push_back( Data(0x8A3B4A, 1, bytes) );

		//correct pointer to EXISTANCE soundset in m_BaseStats
		bytes[0] = 0xAA;
		vDataList.push_back( Data(0x8A3BB6, 1, bytes) );
	
		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}

	//Remove crash on alpha rendering of RLE-encoded BAMs
	if (GetIniValue("Video", "VVC Alpha Rendering Crash Fix")) {
		//PUSH 0 to skip AssertionFailedQuit()
		char bytes[1] = {0x00};
		vDataList.push_back( Data(0xA0F1EF, 1, bytes) );
		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}

	//Allow four weapon slots for all classes
	if (GetIniValue("UI", "Universal Four Inventory Weapon Slots")) {
		//2->4 (All playable classes except Fighter and those listed for 3 slots), 3->4 (Paladin, Ranger, Monk)
		char bytes[1] = {0x04};
		vDataList.push_back( Data(0x639C6F, 1, bytes) );
		vDataList.push_back( Data(0x639C78, 1, bytes) );
		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}

	//Allow up to 99 priest spells per level
	if (GetIniValue("Engine", "Allow 99 Priest Known Spells Per Level")) {
		char bytes[1] = {0x62};
		vDataList.push_back( Data(0x63358D, 1, bytes) );
		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}

	//Quintuple number of kits allowable
	//Externalises KitArray outside CInfGame object
	ClassAbilityTable = new ClAbTable();
	if (GetIniValue("UI", "Allow 1280 Total Kits")) {
		//for count
		char bytes[4] = {0x00, 0x05, 0x00, 0x00};
		vDataList.push_back( Data(0x6278AF, 4, bytes) );
		vDataList.push_back( Data(0x627A11, 4, bytes) );

		char bytes2[2] = {0x90, 0xB8};
		vDataList.push_back( Data(0x62796A, 2, bytes2) ); //EAX
		bytes2[1] = 0xBA;
		vDataList.push_back( Data(0x627993, 2, bytes2) ); //EDX
		vDataList.push_back( Data(0x627A3B, 2, bytes2) ); //EDX
		bytes2[1] = 0xB9;
		vDataList.push_back( Data(0x627A4E, 2, bytes2) ); //ECX

		//ptr to new ClassAbilityTable array
		char* bytes3 = reinterpret_cast<char*>(&ClassAbilityTable);
		vDataList.push_back( Data(0x62796C, 4, bytes3) );
		vDataList.push_back( Data(0x627995, 4, bytes3) );
		vDataList.push_back( Data(0x627A3D, 4, bytes3) );
		vDataList.push_back( Data(0x627A50, 4, bytes3) );

		char bytes4[7] = {0x89, 0x4C, 0x90, 0x04, 0x90, 0x90, 0x90};
		vDataList.push_back( Data(0x627973, 7, bytes4) );

		char bytes5[7] = {0x8B, 0x4C, 0x8A, 0x04, 0x90, 0x90, 0x90};
		vDataList.push_back( Data(0x627999, 7, bytes5) );

		char bytes6[8] = {0x83, 0x7C, 0x8A, 0x04, 0x00, 0x90, 0x90, 0x90};
		vDataList.push_back( Data(0x627A41, 8, bytes6) );

		char bytes7[7] = {0x8B, 0x54, 0x81, 0x04, 0x90, 0x90, 0x90};
		vDataList.push_back( Data(0x627A54, 7, bytes7) );

		//GetClassAbilityTable()
		char bytes8[1] = {0xBA};
		vDataList.push_back( Data(0x63A8DF, 1, bytes8) );

		//ptr to new ClassAbilityTable array
		char* bytes9 = reinterpret_cast<char*>(&ClassAbilityTable);
		vDataList.push_back( Data(0x63A8E0, 4, bytes9) );

		char bytes10[5] = {0x8B, 0x04, 0x8A, 0x90, 0x90};
		vDataList.push_back( Data(0x63A8E4, 5, bytes10) );

		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}

	//Enable logging of system, AREA-TRANSITION and AREA-INVENTORY messages
	if (GetIniValue("Debug", "Log More Messages")) {
		char bytes[] = {0x01};
		vDataList.push_back( Data(0xAB3BDC, 1, bytes) );
		vDataList.push_back( Data(0xAB3BE0, 1, bytes) );
		vDataList.push_back( Data(0xAB3BE4, 1, bytes) );
		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}

	//Fixes issue where the critical error message box doesn't display
	if (GetIniValue("Debug", "Critical Error Message Box Fix")) {
		//NOP, CALL
		char bytes[] = {0x90, 0xE8};
		vDataList.push_back( Data(0x9A5F63, 2, bytes) );
		vDataList.push_back( Data(0x9A5F9E, 2, bytes) );
		vDataList.push_back( Data(0x9A5FE5, 2, bytes) );

		//CALL address
		void* ptr = (void*)CBaldurChitin_MessageBox;
		DWORD address = (DWORD)ptr - 5  - 0x9A5F64;
		char* bytes2 = (char*)&address;
		vDataList.push_back( Data(0x9A5F65, 4, bytes2) );

		address = (DWORD)ptr - 5  - 0x9A5F9F;
		bytes2 = (char*)&address;
		vDataList.push_back( Data(0x9A5FA0, 4, bytes2) );

		address = (DWORD)ptr - 5  - 0x9A5FE6;
		bytes2 = (char*)&address;
		vDataList.push_back( Data(0x9A5FE7, 4, bytes2) );

		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}

	//Scrollable Level Up Mage Spell Selection
	if (GetIniValue("UI", "Scrollable Level Up Mage Spell Selection")) {
		//allow for loops for buttons to include new button
		char bytes[] = {0x18};
		vDataList.push_back( Data(0x6E0E1E, 1, bytes) );
		vDataList.push_back( Data(0x6E1229, 1, bytes) );
		vDataList.push_back( Data(0x6E4CCD, 1, bytes) );
		vDataList.push_back( Data(0x6E5722, 1, bytes) );
		vDataList.push_back( Data(0x6E9B08, 1, bytes) );
		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}

	/* alternate version of AttackSounds, but the specific attack sounds play instead of the standard ATTACK sound
	if (GetIniValue("AttackSounds")) {
		char bytes[2] = {0x4E, 0x2C};
		vDataList.push_back( Data(0x7F9E1F, 2, bytes) );
	
		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}*/

	//Remain invisible on successful pickpocket
	if (GetIniValue("Engine", "Remain Hidden On Pickpocket Success")) {
	    //always JMP the check for STATE_INVISIBLE
		char bytes[] = {0x90, 0xE9};
		vDataList.push_back( Data(0x943543, 2, bytes) );
	
		//JMP bgmain.943549 (backwards)
		char bytes2[6] = {0xE9, 0x7C, 0xFC, 0xFF, 0xFF, 0x90};
		vDataList.push_back( Data(0x9438C8, 6, bytes2) );
	
		//CALL
		char bytes3[8] = {0x8B, 0x85, 0x44, 0xFD, 0xFF, 0xFF, 0x50, 0xE8};
		vDataList.push_back( Data(0x943549, 8, bytes3) );
	
		//CALL address
		void* ptr = (void*)CCreatureObject_ForceVisible;
		DWORD address = (DWORD)ptr - 5  - 0x943550;
		char* bytes4 = (char*)&address;
		vDataList.push_back( Data(0x943551, 4, bytes4) );
	
		//JMP bgmain.9438CE (forwards)
		char bytes5[5] = {0xE9, 0x74, 0x03, 0x00, 0x00};
		vDataList.push_back( Data(0x943555, 5, bytes5) );
	
		//moved instructions to free up space for above JMP
		char bytes6[8] = {0x8B, 0x8D, 0x44, 0xFD, 0xFF, 0xFF, 0x8B, 0x11};
		vDataList.push_back( Data(0x9438CE, 8, bytes6) );
		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}
	
	//Externalize hardcoded race StrRefs to RACETEXT.2DA
	if (GetIniValue("UI", "Externalise Race Selection StrRef")) {
	
	    //1. during loading of a game
	    //2. CharGen buttons (loaded during game startup)
	    //3. <RACE> token (loaded on dialogue)
		//4. Record Screen Label (loaded on record screen) - note: indices here are one above the others
	    //5. IsGabber() action on CCreatureObject (loaded on action)
	
		//1, 3, 5. SWITCH 
		char bytes[1] = {0x9E};
		vDataList.push_back( Data(0x6A7BF7, 1, bytes) );
		vDataList.push_back( Data(0x7E419B, 1, bytes) );
		vDataList.push_back( Data(0x4B27CF, 1, bytes) );
	
		//1, 3, 4, 5. SWITCH 
		bytes[0] = 0x9F;
		vDataList.push_back( Data(0x6D8FA9, 1, bytes) );
	
		//4. DEC EDX
		bytes[0] = 0x4A;
		vDataList.push_back( Data(0x6D8FB2, 1, bytes) );
	
		//1-4. PUSH EDX, CALL
		char bytes2[] = {0x52, 0xE8};
		vDataList.push_back( Data(0x6A7C03, 2, bytes2) );
		vDataList.push_back( Data(0x73438C, 2, bytes2) );
		vDataList.push_back( Data(0x7E41A7, 2, bytes2) );
		vDataList.push_back( Data(0x6D8FB3, 2, bytes2) );
	
		//5. PUSH EAX, CALL
		bytes2[0] = 0x50;
		vDataList.push_back( Data(0x4B27DB, 2, bytes2) );
	
		//1-5. CALL address
		void* ptr = (void*)CInfGame_GetRaceText;
		DWORD address = (DWORD)ptr - 5  - 0x6A7C04;
		char* bytes3 = (char*)&address;
		vDataList.push_back( Data(0x6A7C05, 4, bytes3) );
		
		address = (DWORD)ptr - 5  - 0x73438D;
		bytes3 = (char*)&address;
		vDataList.push_back( Data(0x73438E, 4, bytes3) );
	
		address = (DWORD)ptr - 5  - 0x7E41A8;
		bytes3 = (char*)&address;
		vDataList.push_back( Data(0x7E41A9, 4, bytes3) );
	
		address = (DWORD)ptr - 5  - 0x6D8FB4;
		bytes3 = (char*)&address;
		vDataList.push_back( Data(0x6D8FB5, 4, bytes3) );
	
		address = (DWORD)ptr - 5  - 0x4B27DC;
		bytes3 = (char*)&address;
		vDataList.push_back( Data(0x4B27DD, 4, bytes3) );
	
		//1, 3. MOV LOCAL, EAX; JMP SHORT
		char bytes4[9] = {0x89, 0x85, 0x78, 0xFF, 0xFF, 0xFF, 0xEB, 0x6B, 0x90};
		vDataList.push_back( Data(0x6A7C09, 9, bytes4) );
		vDataList.push_back( Data(0x7E41AD, 9, bytes4) );
	
		//2. MOV LOCAL, EAX; JMP SHORT
		char bytes5[8] = {0x89, 0x45, 0x80, 0xEB, 0x64, 0x90, 0x90, 0x90};
		vDataList.push_back( Data(0x734392, 8, bytes5) );
	
		//4. MOV LOCAL, EAX; JMP SHORT
		char bytes6[8] = {0x89, 0x45, 0xF0, 0x90, 0xEB, 0x7F, 0x90, 0x90};
		vDataList.push_back( Data(0x6D8FB9, 8, bytes6) );
	
		//5. MOV LOCAL, EAX; JMP SHORT
		char bytes7[9] = {0x89, 0x45, 0x80, 0xEB, 0x53, 0x90, 0x90, 0x90, 0x90};
		vDataList.push_back( Data(0x4B27E1, 8, bytes7) );
	
		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}
	
	//Remove limit on SONGLIST.2DA size
	if (GetIniValue("Music", "Extended Songlist")) {
		//treat song entries as DWORD instead of signed byte
		//section that stops the music
		char bytes[] = {0x89};
	    vDataList.push_back( Data(0x4CC6F7, 1, bytes) );

		char bytes2[] = {0xA8, 0x8B, 0x4D, 0xA8, 0x89, 0x4D, 0xF4, 0x8B, 0x55, 0xFC, 0x90, 0x8B, 0x45, 0xF4, 0x90};
		vDataList.push_back( Data(0x4CC708, 15, bytes2) );

		char bytes3[] = {0x8B, 0x45, 0xF4, 0x90};
	    vDataList.push_back( Data(0x4CC735, 4, bytes3) );
	
		//CArea::ChangeSong()
		bytes[0] = 0x89;
	    vDataList.push_back( Data(0x4D4892, 1, bytes) );

		bytes3[0] = 0x8B; bytes3[1] = 0x45; bytes3[2] = 0xF8; bytes3[3] = 0x90;
	    vDataList.push_back( Data(0x4D489D, 4, bytes3) );
	
	    vPatchList.push_back( Patch(vDataList) );
	    vDataList.clear();
	}
	
	//Use FIRST_LEVEL on PROFSMAX.2DA
	if (GetIniValue("Engine", "Level One Proficiency Restrictions")) {
	    //changing PUSH arguments
		char bytes[] = {0x8B, 0x45, 0x08, 0x50, 0x90};
		vDataList.push_back( Data(0x6DC54F, 5, bytes) );
	
		//CALL address
		void* ptr = (void*)CRuleTables_GetMaxProfs;
		DWORD address = (DWORD)ptr - 5  - 0x6DC560;
		char* bytes2 = (char*)&address;
		vDataList.push_back( Data(0x6DC561, 4, bytes2) );
	
		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}
	
	//Video
	if (GetIniValue("Video", "Brighten On Disable Brightest No3d Fix")) {
		//JE -> JNZ
		//this causes Disable Brighten to work properly with no 3d, but causes blended objects to become green
		char bytes[] = {0x75};
		vDataList.push_back( Data(0x9F5953, 1, bytes) );
	
		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}

	if (GetIniValue("UI", "Externalise Mage Spell Hiding")) {
		//Converts all const ResRef to NULL
		char bytes[8] = {0, 0, 0, 0, 0, 0, 0, 0};
		vDataList.push_back( Data(0xB363D8, 8, bytes) ); //SPWI402
		//vDataList.push_back( Data(0xB36440, 8, bytes) ); //SPWI402, see below
		vDataList.push_back( Data(0xB33E4C, 8, bytes) ); //SPWI802
		vDataList.push_back( Data(0xB33E54, 8, bytes) ); //SPWI402
		//vDataList.push_back( Data(0xB33E5C, 8, bytes) ); //SPWI124
		vDataList.push_back( Data(0xB2BE40, 8, bytes) ); //SPWI802
		vDataList.push_back( Data(0xB2BE48, 8, bytes) ); //SPWI920
		vDataList.push_back( Data(0xB2BE50, 8, bytes) ); //SPWI921
		vDataList.push_back( Data(0xB2BE58, 8, bytes) ); //SPWI922
		vDataList.push_back( Data(0xB2BE60, 8, bytes) ); //SPWI923
		vDataList.push_back( Data(0xB2BE68, 8, bytes) ); //SPWI924
		vDataList.push_back( Data(0xB2BE70, 8, bytes) ); //SPWI925
		vDataList.push_back( Data(0xB2BE78, 8, bytes) ); //SPWI926
		vDataList.push_back( Data(0xB2BE80, 8, bytes) ); //SPWI402
		//vDataList.push_back( Data(0xB2BE88, 8, bytes) ); //SPWI124

		//Allow NEXT/DONE button even if not all spell slots filled
		//One specialist mage spell still must be chosen
		char bytes2[9] = {0xB8, 0x01, 0x00, 0x00, 0x00, 0x90, 0x90, 0x90, 0x90};
		vDataList.push_back( Data(0x72B2AE, 9, bytes2) );

		//Terminate SPLAUTOP iterations if the defaultVal is obtained
		//bytes[0] = 0x30;
		vDataList.push_back( Data(0xB36440, 8, bytes) ); //"SPWI402" -> "0"

		//JMP for termination
		char bytes3[4] = {0xAE, 0x00, 0x00, 0x00};
		vDataList.push_back( Data(0x72F7B6, 4, bytes3) );

		//Fix up the text box displaying 'Known Mage Spells'
		//MOV ECX, DWORD PTR SS:[EBP+8]
		//PUSH ECX
		//NOP NOP NOP
		char bytes4[7] = {0x8B, 0x4D, 0x08, 0x51, 0x90, 0x90, 0x90};
		vDataList.push_back( Data(0x719006, 7, bytes4) ); //Single player
		
		//MOV ECX, DWORD PTR SS:[EBP-5C]
		bytes[2] = 0xA4;
		vDataList.push_back( Data(0x7759BE, 7, bytes4) ); //Multiplayer

		//CALL address (single player)
		void* ptr = (void*)CRuleTables_HasKnownMageSpells;
		DWORD address = (DWORD)ptr - 5  - 0x71900D;
		char* bytes5 = (char*)&address;
		vDataList.push_back( Data(0x71900E, 4, bytes5) );

		//CALL address (multiplayer)
		ptr = (void*)CRuleTables_HasKnownMageSpells;
		address = (DWORD)ptr - 5  - 0x7759C5;
		bytes5 = (char*)&address;
		vDataList.push_back( Data(0x7759C6, 4, bytes5) );

		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}

	for (vPatchItr = vPatchList.begin(); vPatchItr != vPatchList.end(); vPatchItr++) {
		vDataList = vPatchItr->GetData();
		for_each(vDataList.begin(), vDataList.end(), ApplyPatch);
		vDataList.clear();
	}
	

	return;
}
