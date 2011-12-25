#include "patch.h"

#include <algorithm>
#include <vector>

#include "stdafx.h"
#include "options.h"
#include "scrcore.h"
#include "console.h"
#include "log.h"
#include "ChitinCore.h"
#include "InfGameCore.h"
#include "ItemCommon.h"
#include "ScriptAction.h"
#include "ScriptTrigger.h"
#include "UserCommon.h"
#include "ObjectCreature.h"

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

void ApplyPatch(Data& d) {
	void* address = reinterpret_cast<void*>(d.GetAddress());
	SIZE_T size = d.GetSize();
	DWORD oldProtect;
	VirtualProtect(address, size, PAGE_EXECUTE_READWRITE, &oldProtect);
	if ( !WriteProcessMemory(GetCurrentProcess(), address, d.GetBytes(), size, &size) ) {
		LPCTSTR lpsz = "ApplyPatch(): WriteProcessMemory failed, address: 0x%x, error code: %d\r\n";
		DWORD dwError = GetLastError();
		console.write(lpsz, 2, address, dwError);
		L.timestamp();
		L.append(lpsz, 2, address, dwError);
	}
	VirtualProtect(address, size, oldProtect, &oldProtect);
	return;
}

void InitPatches() {
	std::vector<Patch> vPatchList;
	std::vector<Patch>::iterator vPatchItr;
	std::vector<Data> vDataList;

	if (pGameOptionsEx->bActionAddKitFix) {
		//AddKit()
		//edx: i, ecx: pCCreatureObject
		//mov eax,edx
		//shr eax,10
		//and edx,0FFFF
		//mov word ptr ds:[ecx+632],ax
		//mov word ptr ds:[ecx+634],dx
		//nop
		char bytes[] = {0x8B, 0xC2,
						0xC1, 0xE8, 0x10,
						0x81, 0xE2, 0xFF, 0xFF, 0x00, 0x00,
						0x66, 0x89, 0x81, 0x32, 0x06, 0x00, 0x00,
						0x66, 0x89, 0x91, 0x34, 0x06, 0x00, 0x00,
						0x90};
		vDataList.push_back( Data(0x8E460C, 26, bytes) );

		//AddSuperKit()
		//ecx: i, eax: pCCreatureObject
		//mov edx,ecx
		//shr edx,10
		//and ecx,0FFFF
		//mov word ptr ds:[eax+632],dx
		//mov word ptr ds:[eax+634],cx
		//nop
		char bytes2[] = {0x8B, 0xD1,
						0xC1, 0xEA, 0x10,
						0x81, 0xE1, 0xFF, 0xFF, 0x00, 0x00,
						0x66, 0x89, 0x90, 0x32, 0x06, 0x00, 0x00,
						0x66, 0x89, 0x88, 0x34, 0x06, 0x00, 0x00,
						0x90};
		vDataList.push_back( Data(0x8E49F8, 26, bytes2) );

		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}

	if (pGameOptionsEx->bActionEquipRangedFix) {
		//mov al,byte ptr ds:[edx]
		//cmp al,2 (TYPE_RANGED)
		//jnz short 0094FAAE
		//mov ecx,dword ptr ss:[ebp-8]
		//call CItem::GetFlags()
		//and eax,2 (ITEMFLAG_TWOHANDED)
		//test eax,eax
		//je short 0094FA6A
		//mov ecx,dword ptr ss:[ebp-C]
		//nop
		//mov dl,byte ptr ds:[ecx+10]
		//cmp dl,3 (PROJTYPE_BULLET)
		char bytes[] = {0x8A, 0x02,
						0x3C, 0x02,
						0x75, 0x65,
						0x8B, 0x4D, 0xF8,
						0xE8, 0x40, 0xBB, 0xC5, 0xFF,
						0x83, 0xE0, 0x02,
						0x85, 0xC0,
						0x74, 0x12,
						0x8B, 0x4D, 0xF4,
						0x90,
						0x8A, 0x51, 0x10,
						0x80, 0xFA, 0x03};
		vDataList.push_back( Data(0x94FA43, 31, bytes) );

		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}
	

	if (pGameOptionsEx->bDebugCriticalMsgBoxFix) {
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

	if (pGameOptionsEx->bDebugLogMissingRes) {
		//in KeyTable::FindKey()
		char bytes[] = {0x90, 0x90, 0x90, 0x90, 0x90, 0x90};
		vDataList.push_back( Data(0x99B12D, 6, bytes) );
	}
	
	//Enable logging of system, AREA-TRANSITION and AREA-INVENTORY messages
	if (pGameOptionsEx->bDebugLogMore) {
		char bytes[] = {0x01};
		vDataList.push_back( Data(0xAB3BDC, 1, bytes) );
		vDataList.push_back( Data(0xAB3BE0, 1, bytes) );
		vDataList.push_back( Data(0xAB3BE4, 1, bytes) );
		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}

	if (pGameOptionsEx->bDebugRestoreCombatInfoText) {

		//1. In TryHit()
		//LEA EDX, int PTR SS:[EBP-20]
		//PUSH EDX
		char bytes[] = {
			0x8D, 0x55, 0xE0, \
			0x52
		};
		vDataList.push_back( Data(0x90B928, 4, bytes) );

		//MOV EDX, int PTR SS:[EBP-294]
		//PUSH EDX
		char bytes2[] = {
			0x8B, 0x95, 0x6C, 0xFD, 0xFF, 0xFF, \
			0x52
		};
		vDataList.push_back( Data(0x90B92C, 7, bytes2) );

		//CALL
		char bytes3[] = {0xE8};
		vDataList.push_back( Data(0x90B933, 1, bytes3) );

		//CALL address
		void* ptr = (void*)CCreatureObject_PrintExtraCombatInfoText;
		DWORD address = (DWORD)ptr - 5  - 0x90B933;
		char* bytes4 = (char*)&address;
		vDataList.push_back( Data(0x90B934, 4, bytes4) );

		char bytes5[] = {0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90};
		vDataList.push_back( Data(0x90B938, 8, bytes5) );

		//2. In DoDamage
		/*lea ecx,dword ptr ss:[ebp-24]
		push ecx
		mov ecx,dword ptr ss:[ebp-198]
		push ecx
		call*/
		char bytes6[] = {
			0x8D, 0x4D, 0xDC, \
			0x51, \
			0x8B, 0x8D, 0x68, 0xFE, 0xFF, 0xFF, \
			0x51, \
			0xE8
		};
		vDataList.push_back( Data(0x90DE6A, 12, bytes6) );

		//CALL address
		ptr = (void*)CCreatureObject_PrintExtraCombatInfoText;
		address = (DWORD)ptr - 5  - 0x90DE75;
		char* bytes7 = (char*)&address;
		vDataList.push_back( Data(0x90DE76, 4, bytes7) );

		char bytes8[] = {0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90};
		vDataList.push_back( Data(0x90DE7A, 10, bytes8) );

		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}

	if (pGameOptionsEx->bEffAwakenFix) {
		char bytes[] = {0x27};
		vDataList.push_back( Data(0x5035F4, 1, bytes) );
		vDataList.push_back( Data(0x50362C, 1, bytes) );
		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}

	if (pGameOptionsEx->bEffDamageBypassMirrorImageConfig) {
		/*mov ecx,dword ptr ss:[ebp-38]
		mov ecx,dword ptr ds:[ecx+98]
		and ecx,1000000
		test ecx,ecx
		jnz BGMain.0050803E
		movsx ecx,word ptr ds:[eax+1404]
		push ecx
		add edx,1
		push edx
		nop*/
		char bytes[] = {
			0x8B, 0x4D, 0xC8, \
			0x8B, 0x89, 0x98, 0x00, 0x00, 0x00, \
			0x81, 0xE1, 0x00, 0x00, 0x00, 0x01, \
			0x85, 0xC9, \
			0x0F, 0x85, 0x44, 0x01, 0x00, 0x00, \
			0x0F, 0xBF, 0x88, 0x04, 0x14, 0x00, 0x00, \
			0x51, \
			0x83, 0xC2, 0x01, \
			0x52, \
			0x90
		};
		vDataList.push_back( Data(0x507EE3, 36, bytes) );

		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}


	if (pGameOptionsEx->bEffCureDrunkFix) {
		char bytes[] = {0x5E};
		vDataList.push_back( Data(0x52EB0E, 1, bytes) );
		vDataList.push_back( Data(0x52EB49, 1, bytes) );
		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}

	if (pGameOptionsEx->bEffStoneskinDisableColour) {
		char bytes[] = {0x00};
		vDataList.push_back( Data(0x5399D4, 1, bytes) );
		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}

	if (pGameOptionsEx->bEffDispelFix) {
		/*Pseudocode
		rand(); <--0 to 99
		difficulty = 50
		if (nEffectLevel > nDispelLevel) {
			difficulty += 10 * nEffectLevel - nDispelLevel <--brackets forgotten
		} else {
			difficulty -= 5 * (nDispelLevel - nEffectLevel)
		}
	
		if (rand == 0) {no dispel}
		elseif (rand > difficulty) {dispel}
		    elseif (rand > 99) {dispel} <--change to 98, cannot roll > 100
				else {no dispel}*/
		
		//fix brackets in formula when caster level > effect level
		char bytes[] = {0x8B, 0x4D, 0x1C, 0x81, 0xE1, 0xFF, 0x00, 0x00, 0x00, 0x2B, 0xC1, 0x6B, 0xC0, 0x0A};
		vDataList.push_back( Data(0x543F42, 14, bytes) );

		//correct 1% chance of always success
		char bytes2[] = {0x62};
		vDataList.push_back( Data(0x543FA6, 1, bytes2) );
	
		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}

	if (pGameOptionsEx->bEffForbidItemTypeFix) {
		char bytes[] = {0x90, 0x90};
		vDataList.push_back( Data(0x530756, 2, bytes) );
		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}

	//Fix for setting CDerivedStats for permanent until death Improved Invisibility
	if (pGameOptionsEx->bEffInvisibleFix) {
		char bytes2[] = {0x0A, 0x0B};
		vDataList.push_back( Data(0x5126F4, 2, bytes2) );
		vDataList.push_back( Data(0x512703, 2, bytes2) );
		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}

	if (pGameOptionsEx->bEffMirrorImageUseCastLevel) {
	    //fix brackets in formula when caster level > effect level
		char bytes[] = {0x8B, 0x55, 0xD4, 0x8B, 0x4A, 0x48, 0x89, 0x48, 0x48, 0x83, 0xC0, 0x70, 0x83, 0xC2, 0x70, 0x8B, 0x4A, 0x54, 0x89, 0x48, 0x54, 0x8B, 0x4A, 0x5C, 0x89, 0x48, 0x5C, 0x90, 0x90, 0x90};
		vDataList.push_back( Data(0x521184, 30, bytes) );
	
		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}

	//Limit SAVE_NONE to char in itm/spl/eff feature blocks
	if (true) {
		char bytes[] = {0x80};
		vDataList.push_back( Data(0x501EED, 1, bytes) );
		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}

	if (pGameOptionsEx->bEnginePriestKnownSpellsExtend) {
		char bytes[] = {0x62};
		vDataList.push_back( Data(0x63358D, 1, bytes) );
		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}

	if (pGameOptionsEx->bEngineAllowEquipArmorCombat) {
		//jle -> jmp
		char bytes[] = {0xEB};
		vDataList.push_back( Data(0x69BEDF, 1, bytes) );
		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}

	if (pGameOptionsEx->bEngineAllowDualClassAll) {
		//nop a jnz
		char bytes[] = {0x90, 0x90};
		vDataList.push_back( Data(0x6ED934, 2, bytes) );
		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}
	
	if (pGameOptionsEx->bEngineCastingLevelBonus) {
		//spelltype PRIEST
		char bytes[26] = {0x8B, 0x4D, 0xE8, 0x0F, 0xBE, 0x91, 0xD0, 0x00, 0x00, 0x00, 0x03, 0xC2, 0x83, 0xF8, 0x01, 0x7E, 0x37, 0x89, 0x45, 0xB8, 0xEB, 0x39, 0x90, 0x90, 0x90, 0x90};
		vDataList.push_back( Data(0x951511, 26, bytes) );
		
		//spelltype WIZARD
		char bytes2[25] = {0x8B, 0x4D, 0xE0, 0x0F, 0xBE, 0x91, 0xCE, 0x00, 0x00, 0x00, 0x03, 0xC2, 0x83, 0xF8, 0x01, 0x7E, 0x37, 0x89, 0x45, 0xB4, 0xEB, 0x39, 0x90, 0x90, 0x90};
		vDataList.push_back( Data(0x9515B4, 25, bytes2) );

		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}

	if (pGameOptionsEx->bEngineExpandedStats) {
		//je short BGMain.008A7311
		//add ecx, 0B0A
		//jmp short BGMain.008A7317
		//add ecx, 13C2
		//mov dword ptr ss:[ebp-DC], ecx
		//push 0C9
		//mov ecx, dword ptr ss:[ebp-DC]
		//call CDerivedStats::GetStat(index)
		//cmp eax, 0
		//nop
		char bytes[] = {0x74, 0x08,
						0x81, 0xC1, 0x0A, 0x0B, 0x00, 0x00,
						0xEB, 0x06,
						0x81, 0xC1, 0xC2, 0x13, 0x00, 0x00,
						0x89, 0x8D, 0x24, 0xFF, 0xFF, 0xFF,
						0x68, 0xC9, 0x00, 0x00, 0x00,
						0x8B, 0x8D, 0x24, 0xFF, 0xFF, 0xFF,
						0xE8, 0x35, 0xBE, 0xBC, 0xFF,
						0x83, 0xF8, 0x00,
						0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90};
		vDataList.push_back( Data(0x8A7307, 52, bytes) );

		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}
	
	if (pGameOptionsEx->bEngineAssBHPenaltyKit) {
		//1. CRecord::LevelUpPanelOnLoad()
		char bytes[] = {0x25, 0x00, 0x00, 0x08, 0x00,
						0x85, 0xC0,
						0x90, 0x90, 0x90, 0x90,
						0x74, 0x25,
						0x8A, 0x8D, 0xC0, 0xF6, 0xFF, 0xFF,
						0x8A, 0x95, 0xBC, 0xF6, 0xFF, 0xFF,
						0x81, 0xE1, 0xFF, 0x00, 0x00, 0x00,
						0x2A, 0xCA};
		vDataList.push_back( Data(0x6DF0B4, 33, bytes) );

		char bytes2[] = {0x25, 0x00, 0x00, 0x04, 0x00,
						0x85, 0xC0,
						0x90, 0x90, 0x90, 0x90,
						0x74, 0x25,
						0x8A, 0x8D, 0xC0, 0xF6, 0xFF, 0xFF,
						0x8A, 0x95, 0xBC, 0xF6, 0xFF, 0xFF,
						0x81, 0xE1, 0xFF, 0x00, 0x00, 0x00,
						0x2A, 0xCA};
		vDataList.push_back( Data(0x6DF0EE, 33, bytes2) );

		//2. CCharGen::SkillsBG1PanelOnLoad()
		char bytes3[] = {0x25, 0x00, 0x00, 0x08, 0x00,
						0x85, 0xC0,
						0x90, 0x90, 0x90,
						0x74, 0x26,
						0x6A, 0x04};
		vDataList.push_back( Data(0x71CDD0, 14, bytes3) );

		char bytes4[] = {0x25, 0x00, 0x00, 0x04, 0x00,
						0x85, 0xC0,
						0x90, 0x90, 0x90,
						0x74, 0x26,
						0x6A, 0x04};
		vDataList.push_back( Data(0x71CE0A, 14, bytes4) );

		//3. CEffectLevelDrain::ApplyEffect()
		char bytes5[] = {0x25, 0x00, 0x00, 0x08, 0x00,
						0x85, 0xC0,
						0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
						0x74, 0x3F,
						0x8B, 0x95, 0x4C, 0xEE, 0xFF, 0xFF,
						0x2B, 0x95, 0x48, 0xEE, 0xFF, 0xFF,
						0x6B, 0xD2, 0x14,
						0x39, 0x95, 0x6C, 0xEE, 0xFF, 0xFF,
						0x7D, 0x0E,
						0x8B, 0x85, 0x6C, 0xEE, 0xFF, 0xFF,
						0x89, 0x85, 0x2C, 0xEE, 0xFF, 0xFF,
						0xEB, 0x1A,
						0x8B, 0x8D, 0x4C, 0xEE, 0xFF, 0xFF,
						0x2B, 0x8D, 0x48, 0xEE, 0xFF, 0xFF,
						0x6B, 0xC9, 0x14,
						0x89, 0x8D, 0x2C, 0xEE, 0xFF, 0xFF,
						0xE9, 0x9F, 0x00, 0x00, 0x00,
						0x8B, 0x4D, 0x08,
						0xE8, 0x3F, 0x7E, 0x3A, 0x00,
						0x25, 0x00, 0x00, 0x04, 0x00,
						0x85, 0xC0,
						0x74, 0x48};
		vDataList.push_back( Data(0x5387D4, 97, bytes5) );

		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}
	
	if (pGameOptionsEx->bEngineClericRangerHLAFix) {
		//CLASS_RANGER -> CLASS_CLERIC
		char bytes[] = {0x66};
		vDataList.push_back( Data(0x62D0DB, 1, bytes) );
		vDataList.push_back( Data(0x62D179, 1, bytes) );
		vDataList.push_back( Data(0x62D18F, 1, bytes) );

		//CLASS_CLERIC -> CLASS_RANGER
		char bytes2[] = {0x6F};
		vDataList.push_back( Data(0x62D12D, 1, bytes2) );
		vDataList.push_back( Data(0x62D1A5, 1, bytes2) );
		vDataList.push_back( Data(0x62D1BA, 1, bytes2) );

		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}
	
	if (pGameOptionsEx->bEngineExperienceFix) {
		char bytes[] = {0x64};
		vDataList.push_back( Data(0x6A97D5, 1, bytes) );
		vDataList.push_back( Data(0x6A9961, 1, bytes) );
		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}

	/*if (pGameOptionsEx->nEngineContingencyTriggerDelay > 0) {
		//Frees up the high word of nParam2
		//mov ecx,dword ptr ds:[edx+1C]
		//and ecx,0FFFF
		//cmp ecx,0B
		//nop
		char bytes1[] = {0x8B, 0x4A, 0x1C,
						 0x81, 0xE1, 0xFF, 0xFF, 0x00, 0x00,
						 0x83, 0xF9, 0x0B,
						 0x90, 0x90, 0x90, 0x90};
		vDataList.push_back( Data(0x53B207, 16, bytes1) );
		
		char bytes2[] = {0x90, 0x90, 0x90, 0x90, 0x90, 0x90};
		vDataList.push_back( Data(0x53B21D, 6, bytes2) );
		vDataList.push_back( Data(0x53B46A, 6, bytes2) );

		//Frees up the high word of nParam1
		//mov edx,dword ptr ds:[eax+18]
		//and edx,0FFFF
		//cmp edx,3
		//nop
		char bytes3[] = {0x8B, 0x50, 0x18,
						 0x81, 0xE2, 0xFF, 0xFF, 0x00, 0x00,
						 0x83, 0xFA, 0x03,
						 0x90, 0x90, 0x90, 0x90};
		vDataList.push_back( Data(0x53B458, 16, bytes3) );
		
		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}*/

	if (pGameOptionsEx->bEngineDisableInvPauseSP) {
		char bytes[] = {0xEB};
		//void CInventory::Init()
		vDataList.push_back( Data(0x7402A8, 1, bytes) );

		//void CInventory::DeInit()
		vDataList.push_back( Data(0x7403D0, 1, bytes) );

		char bytes2[] = {0x90, 0x90};
		vDataList.push_back( Data(0x74912B, 2, bytes2) );

		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}
	
	if (pGameOptionsEx->bEngineCharmSilenceRemoval) {
		char bytes[] = {0xEB};
		vDataList.push_back( Data(0x8A11D4, 1, bytes) );
		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}

	if (pGameOptionsEx->bEngineExternEncumbrance) {
		//1. some animation thing depending on encumbrance

		//push edx
		//mov ecx,dword ptr ss:[ebp-44]
		//push ecx
		//call
		char bytes[] = {0x52,
						0x8B, 0x4D, 0xBC,
						0x51,
						0xE8};
		vDataList.push_back( Data(0x8ECAED, 6, bytes) );

		//CALL address
		void* ptr = (void*)CRuleTables_IsHighEncumbrance;
		DWORD address = (DWORD)ptr - 5  - 0x8ECAF2;
		char* bytes2 = (char*)&address;
		vDataList.push_back( Data(0x8ECAF3, 4, bytes2) );

		//test eax,eax
		//mov edx,dword ptr ss:[ebp-40] <-- nTotalWeightAllowance for next condition
		//nop
		//je short 8ECB6B
		char bytes3[] = {0x85, 0xC0,
						0x8B, 0x55, 0xC0,
						0x90, 0x90, 0x90,
						0x74, 0x6A};
		vDataList.push_back( Data(0x8ECAF7, 10, bytes3) );

		//push edx
		//push ecx
		//call
		char bytes4[] = {0x52,
						0x51,
						0xE8};
		vDataList.push_back( Data(0x8ECB6E, 3, bytes4) );

		//CALL address
		ptr = (void*)CRuleTables_IsLowEncumbrance;
		address = (DWORD)ptr - 5  - 0x8ECB70;
		char* bytes5 = (char*)&address;
		vDataList.push_back( Data(0x8ECB71, 4, bytes5) );

		//test eax,eax
		//nop
		//je 8ECC41
		//mov edx,dword ptr ss:[ebp-880]
		//add edx,2C4A
		//mov dword ptr ss:[ebp-3CC],edx
		//mov eax,dword ptr ss:[ebp-3CC]
		//cmp dword ptr ds:[eax],0
		//jnz short BGMain.008ECBB5
		//push 0
		//push B04B38
		//push B04B10
		//push 830
		//call AssertionFailedQuit
		//add esp,10
		//mov ecx,dword ptr ss:[ebp-3CC]
		//mov ecx,dword ptr ds:[ecx]
		//mov edx,dword ptr ds:[ecx]
		char bytes6[] = {0x85, 0xC0,
						0x90, 0x90,
						0x0F, 0x84, 0xC2, 0x00, 0x00, 0x00,
						0x8B, 0x95, 0x80, 0xF7, 0xFF, 0xFF,
						0x81, 0xC2, 0x4A, 0x2C, 0x00, 0x00,
						0x89, 0x95, 0x34, 0xFC, 0xFF, 0xFF,
						0x8B, 0x85, 0x34, 0xFC, 0xFF, 0xFF,
						0x83, 0x38, 0x00,
						0x75, 0x19,
						0x6A, 0x00,
						0x68, 0x38, 0x4B, 0xB0, 0x00,
						0x68, 0x10, 0x4B, 0xB0, 0x00,
						0x68, 0x30, 0x08, 0x00, 0x00,
						0xE8, 0xBA, 0x24, 0x0B, 0x00,
						0x83, 0xC4, 0x10,
						0x8B, 0x8D, 0x34, 0xFC, 0xFF, 0xFF,
						0x8B, 0x09,
						0x8B, 0x11};
		vDataList.push_back( Data(0x8ECB75, 74, bytes6) );

		//2. settings of encumbrance in CDerivedStats

		//push edx
		//mov ecx,dword ptr ss:[ebp-11c]
		//push ecx
		//call
		char bytes7[] = {0x52,
						0x8B, 0x8D, 0xE4, 0xFE, 0xFF, 0xFF,
						0x51,
						0xE8};
		vDataList.push_back( Data(0x8EFDCF, 9, bytes7) );

		//CALL address
		ptr = (void*)CRuleTables_IsHighEncumbrance;
		address = (DWORD)ptr - 5  - 0x8EFDD7;
		char* bytes8 = (char*)&address;
		vDataList.push_back( Data(0x8EFDD8, 4, bytes8) );

		//test eax,eax
		//nop
		//je 8EFE7D
		char bytes9[] = {0x85, 0xC0,
						0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
						0x0F, 0x84, 0x90, 0x00, 0x00, 0x00};
		vDataList.push_back( Data(0x8EFDDC, 17, bytes9) );

		//mov edx,dword ptr ss:[ebp-118]
		//push edx
		//mov ecx,dword ptr ss:[ebp-11c]
		//push ecx
		//call
		char bytes10[] = {0x8B, 0x95, 0xE8, 0xFE, 0xFF, 0xFF,
						0x52,
						0x8B, 0x8D, 0xE4, 0xFE, 0xFF, 0xFF,
						0x51,
						0xE8};
		vDataList.push_back( Data(0x8EFE7D, 15, bytes10) );

		//CALL address
		ptr = (void*)CRuleTables_IsLowEncumbrance;
		address = (DWORD)ptr - 5  - 0x8EFE8B;
		char* bytes11 = (char*)&address;
		vDataList.push_back( Data(0x8EFE8C, 4, bytes11) );

		//test eax,eax
		//je 8EFF7D
		//nop
		//mov eax,dword ptr ds:[B773CC]
		//mov ecx,dword ptr ss:[eax+42BA]
		//mov eax,dword ptr ds:[ecx+4302]
		char bytes12[] = {0x85, 0xC0,
						0x0F, 0x84, 0xE5, 0x00, 0x00, 0x00,
						0x90, 0x90,
						0xA1, 0xCC, 0x73, 0xB7, 0x00,
						0x36, 0x8B, 0x88, 0xBA, 0x42, 0x00, 0x00,
						0x8B, 0x81, 0x02, 0x43, 0x00, 0x00};
		vDataList.push_back( Data(0x8EFE90, 28, bytes12) );

		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}

	if (pGameOptionsEx->bEngineProficiencyRestrictions) {
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

	if (pGameOptionsEx->bEnginePickpocketRemainHidden) {
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

	if (pGameOptionsEx->bEngineRestSpawnsAdvanceTime) {
		//mov ecx,dword ptr ds:[<TICKS_EIGHT_HOURS>]
		//imul ecx,dword ptr ss:[ebp-CC]
		//add ecx,dword ptr ss:[ebp-E0]
		//push ecx
		//mov ecx,dword ptr ss:[ebp-3F8]
		//add ecx,1DD0
		//call CWorldTimer::AdvanceByTime
		//mov edx,dword ptr ds:[<TICKS_EIGHT_HOURS>]
		//imul edx,dword ptr ss:[ebp-CC]
		//add edx,dword ptr ss:[ebp-E0]
		//push edx
		//push 7
		//mov ecx,dword ptr ss:[ebp-3F8]
		//call CInfGame::PrintEvaluatedMessage
		//cmp dword ptr ss:[ebp-CC],0
		//jle BGMain.006ABC61
		char bytes[] = {0x8B, 0x0D, 0xCC, 0x0F, 0xB8, 0x00,
						0x0F, 0xAF, 0x8D, 0x34, 0xFF, 0xFF, 0xFF,
						0x03, 0x8D, 0x20, 0xFF, 0xFF, 0xFF,
						0x51,
						0x8B, 0x8D, 0x08, 0xFC, 0xFF, 0xFF,
						0x81, 0xC1, 0xD0, 0x1D, 0x00, 0x00,
						0xE8, 0x28, 0xDE, 0xF9, 0xFF,
						0x8B, 0x15, 0xCC, 0x0F, 0xB8, 0x00,
						0x0F, 0xAF, 0x95, 0x34, 0xFF, 0xFF, 0xFF,
						0x03, 0x95, 0x20, 0xFF, 0xFF, 0xFF,
						0x52,
						0x6A, 0x07,
						0x8B, 0x8D, 0x08, 0xFC, 0xFF, 0xFF,
						0xE8, 0x3F, 0x32, 0x00, 0x00,
						0x83, 0xBD, 0x34, 0xFF, 0xFF, 0xFF, 0x00,
						0x0F, 0x8E, 0xBA, 0x09, 0x00, 0x00};
		vDataList.push_back( Data(0x6AB254, 83, bytes) );
		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}

	if (pGameOptionsEx->bEngineTargetDeadFix) {
		//NOTE: this is an incomplete fix since it only applies to objects existing in LIST_FRONT

		//1. for all before posSource

		//mov edx,dword ptr ss:[ebp-5c]
		//push edx
		//call
		char bytes[] = {0x8B, 0x55, 0xA4,
						0x52,
						0xE8};
		vDataList.push_back( Data(0x4BA3DD, 5, bytes) );

		//CALL address
		void* ptr = (void*)CCreatureObject_IsDeadInFrontVerticalList;
		DWORD address = (DWORD)ptr - 5  - 0x4BA3E1;
		char* bytes2 = (char*)&address;
		vDataList.push_back( Data(0x4BA3E2, 4, bytes2) );

		//test eax,eax
		//je short 4BA3FA
		//mov dword ptr ss:[ebp-3c],0
		//jmp 4BA4E3
		//nop
		//mov ecx,dword ptr ss:[ebp-5c]
		//call CCreatureObject::GetDerivedStats()
		//nop
		//mov dword ptr ss:[ebp-ac],eax
		char bytes3[] = {0x85, 0xC0,
						0x74, 0x10,
						0xC7, 0x45, 0xC4, 0x00, 0x00, 0x00, 0x00,
						0xE9, 0xED, 0x00, 0x00, 0x00,
						0x90, 0x90, 0x90, 0x90,
						0x8B, 0x4D, 0xA4,
						0xE8, 0x2E, 0xB2, 0xFD, 0xFF,
						0x90,
						0x89, 0x85, 0x54, 0xFF, 0xFF, 0xFF};
		vDataList.push_back( Data(0x4BA3E6, 35, bytes3) );

		//2. for all after posSource

		//mov edx,dword ptr ss:[ebp-5c]
		//push edx
		//call
		char bytes4[] = {0x8B, 0x55, 0xA4,
						0x52,
						0xE8};
		vDataList.push_back( Data(0x4BA862, 5, bytes4) );

		//CALL address
		ptr = (void*)CCreatureObject_IsDeadInFrontVerticalList;
		address = (DWORD)ptr - 5  - 0x4BA866;
		char* bytes5 = (char*)&address;
		vDataList.push_back( Data(0x4BA867, 4, bytes5) );

		//test eax,eax
		//je short 4BA87F
		//mov dword ptr ss:[ebp-3c],0
		//jmp 4BA968
		//nop
		//mov ecx,dword ptr ss:[ebp-5c]
		//call CCreatureObject::GetDerivedStats()
		//nop
		//mov dword ptr ss:[ebp-ac],eax
		char bytes6[] = {0x85, 0xC0,
						0x74, 0x10,
						0xC7, 0x45, 0xC4, 0x00, 0x00, 0x00, 0x00,
						0xE9, 0xED, 0x00, 0x00, 0x00,
						0x90, 0x90, 0x90, 0x90,
						0x8B, 0x4D, 0xA4,
						0xE8, 0xA9, 0xAD, 0xFD, 0xFF,
						0x90,
						0x89, 0x85, 0x28, 0xFF, 0xFF, 0xFF};
		vDataList.push_back( Data(0x4BA86B, 35, bytes6) );

		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}

	if (pGameOptionsEx->bItemsBackstabRestrictionsConfig ||
		pGameOptionsEx->bEffBackstabEveryHitConfig) {
		/*mov eax,dword ptr ss:[ebp+24]
		push eax
		mov eax,dword ptr ss:[ebp+20]
		push eax
		mov eax,dword ptr ss:[ebp+1C]
		push eax
		mov eax,dword ptr ss:[ebp-38]
		push eax
		mov eax,dword ptr ss:[ebp-50]
		push eax
		mov eax,dwort ptr ss:[ebp-1c]
		push eax
		mov eax,dword ptr ss:[ebp-198]
		push eax
		CALL*/
		char bytes[] = {
			0x8B, 0x45, 0x24, \
			0x50, \
			0x8B, 0x45, 0x20, \
			0x50, \
			0x8B, 0x45, 0x1c, \
			0x50, \
			0x8B, 0x45, 0xC8, \
			0x50, \
			0x8B, 0x45, 0xB0, \
			0x50, \
			0x8B, 0x45, 0xE4, \
			0x50, \
			0x8B, 0x85, 0x68, 0xFE, 0xFF, 0xFF, \
			0x50, \
			0xE8
		};
		vDataList.push_back( Data(0x90D1B2, 32, bytes) );

		//CALL address
		void* ptr = (void*)CCreatureObject_TryBackstab;
		DWORD address = (DWORD)ptr - 5  - 0x90D1D1;
		char* bytes2 = (char*)&address;
		vDataList.push_back( Data(0x90D1D2, 4, bytes2) );

		//TEST EAX, EAX
		//JE 90D655
		//JMP 90D48D
		//NOP
		char bytes3[] = {
			0x85, 0xC0, \
			0x0F, 0x84, 0x77, 0x04, 0x00, 0x00, \
			0xE9, 0xAA, 0x02, 0x00, 0x00, \
			0x90
		};
		vDataList.push_back( Data(0x90D1D6, 14, bytes3) );

	}
  
	if (pGameOptionsEx->bItemsCriticalHitAversionConfig) {
		//MOV EDX, int PTR SS:[EBP+8]
		//PUSH EDX
		char bytes[] = {0x8B, 0x55, 0x08, 0x52, 0x90, 0x90, 0x90};
		vDataList.push_back( Data(0x90B9A3, 7, bytes) );

		//CALL
		char bytes2[] = {0xE8};
		vDataList.push_back( Data(0x90B9AA, 1, bytes2) );

		//CALL address
		void* ptr = (void*)CCreatureObject_ShouldAvertCriticalHit;
		DWORD address = (DWORD)ptr - 5  - 0x90B9AA;
		char* bytes3 = (char*)&address;
		vDataList.push_back( Data(0x90B9AB, 4, bytes3) );

		//TEST EAX, EAX
		//NOP
		char bytes4[] = {0x85, 0xC0, 0x90, 0x90, 0x90, 0x90};
		vDataList.push_back( Data(0x90B9AF, 6, bytes4) );

		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}

	//Expand RND*.2DA
	if (pGameOptionsEx->bItemsRandomTreasureExtend) {
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

	if (pGameOptionsEx->bItemsExternCreExcl) {
		//modify je address
		char bytes[] = {0xE3, 0x02};
	    vDataList.push_back( Data(0x69CB6E, 2, bytes) );

		//mov eax,dword ptr ss:[ebp+14]
		//push eax
		//mov ecx,dword ptr ss:[ebp+10]
		//mov edx,dword ptr ds:[ecx]
		//push edx
		//movsx eax,word ptr ss:[ebp+C]
		//push eax
		//mov ecx,dword ptr ss:[ebp-48]
		//push ecx
		//call ...
		char bytes3[] = {0x8B, 0x45, 0x14,
						0x50,
						0x8B, 0x4D, 0x10,
						0x8B, 0x11,
						0x52,
						0x0F, 0xBF, 0x45, 0x0C,
						0x50,
						0x8B, 0x4D, 0xB8,
						0x51,
						0xE8};
	    vDataList.push_back( Data(0x69CB72, 20, bytes3) );

		//CALL address
		void* ptr4 = (void*)CRuleTables_DoesEquipSlotPassCreExclude;
		DWORD address4 = (DWORD)ptr4 - 5  - 0x69CB85;
		char* bytes4 = (char*)&address4;
		vDataList.push_back( Data(0x69CB86, 4, bytes4) );

		//test eax,eax
		//jnz BGMain.0069CE55
		//mov dword ptr ss:[ebp-54],0
		//jmp BGMain.0069CE55
		char bytes5[] = {0x85, 0xC0,
						0x0F, 0x85, 0xC3, 0x02, 0x00, 0x00,
						0xC7, 0x45, 0xAC, 0x00, 0x00, 0x00, 0x00,
						0xE9, 0xB7, 0x02, 0x00, 0x00,
						0x90, 0x90, 0x90, 0x90};
	    vDataList.push_back( Data(0x69CB8A, 24, bytes5) );

		//mov ecx,dword ptr ss:[ebp+14]
		//push ecx
		//mov eax,dword ptr ss:[ebp+c]
		//mov ecx,dword ptr ds:[eax]
		//push ecx
		//movsx ecx,word ptr ss:[ebp+10]
		//push ecx
		//mov edx,dword ptr ss:[ebp-1C]
		//push edx
		//call ...
		char bytes6[] = {0x8B, 0x4D, 0x14,
						0x51,
						0x8B, 0x45, 0x0C,
						0x8B, 0x08,
						0x51,
						0x0F, 0xBF, 0x4D, 0x10,
						0x51,
						0x8B, 0x55, 0xE4,
						0x52,
						0xE8};
	    vDataList.push_back( Data(0x69FF65, 20, bytes6) );

		//CALL address
		void* ptr7 = (void*)CRuleTables_DoesInvSlotPassCreExclude;
		DWORD address7 = (DWORD)ptr7 - 5  - 0x69FF78;
		char* bytes7 = (char*)&address7;
		vDataList.push_back( Data(0x69FF79, 4, bytes7) );

		//test eax,eax
		//jnz BGMain.006A006D
		//mov dword ptr ss:[ebp-20],0
		//jmp BGMain.006A006D
		char bytes8[] = {0x85, 0xC0,
						0x0F, 0x85, 0xE8, 0x00, 0x00, 0x00,
						0xC7, 0x45, 0xE0, 0x00, 0x00, 0x00, 0x00,
						0xE9, 0xDC, 0x00, 0x00, 0x00};
	    vDataList.push_back( Data(0x69FF7D, 20, bytes8) );

		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}

	if (pGameOptionsEx->bItemsNonAmmoLauncherDamageFix) {
		//mov ecx,dword ptr ss:[ebp+c]
		//push ecx
		//nop
		char bytes[] = {0x8B, 0x4D, 0x0C,
						0x51,
						0x90};
	    vDataList.push_back( Data(0x90C946, 5, bytes) );

		//CALL address
		void* ptr = (void*)CItem_GetFirstLauncherAbility;
		DWORD address = (DWORD)ptr - 5  - 0x90C94B;
		char* bytes2 = (char*)&address;
		vDataList.push_back( Data(0x90C94C, 4, bytes2) );

		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}
	
	if (pGameOptionsEx->bItemsUseAnimPercentThrowingWeapons) {
		//these changes significantly reduce the amount of CMessageSetAnimationSequence objects sent during a round because throwing weapons are not matching SEQ_SHOOT

		//push ecx
		//call
		char bytes[] = {0x51,
						0xE8};
		vDataList.push_back( Data(0x90636E, 2, bytes) );

		//CALL address
		void* ptr = (void*)CCreatureObject_HasThrowingWeaponEquippedHumanoidOnly;
		DWORD address = (DWORD)ptr - 5  - 0x90636F;
		char* bytes2 = (char*)&address;
		vDataList.push_back( Data(0x906370, 4, bytes2) );

		//test eax, eax
		//jnz 90648F
		//mov edx, dword ptr ss:[ebp-B8]
		//mov al, byte ptr ds:[edx]
		//cmp al, 2
		char bytes3[] = {0x85, 0xC0,
						0x0F, 0x85, 0x13, 0x01, 0x00, 0x00,
						0x8B, 0x95, 0x48, 0xFF, 0xFF, 0xFF,
						0x8A, 0x02,
						0x3C, 0x02};
		vDataList.push_back( Data(0x906374, 18, bytes3) );

		//mov eax,dword ptr ss:[ebp-614]
		//push eax
		//call
		char bytes4[] = {0x8B, 0x85, 0xEC, 0xF9, 0xFF, 0xFF,
						0x50,
						0xE8};
		vDataList.push_back( Data(0x90979C, 8, bytes4) );

		//CALL address
		ptr = (void*)CCreatureObject_HasThrowingWeaponEquippedHumanoidOnly;
		address = (DWORD)ptr - 5  - 0x9097A3;
		char* bytes5 = (char*)&address;
		vDataList.push_back( Data(0x9097A4, 4, bytes5) );

		//test eax,eax
		//jnz 9098C0
		//mov ecx,dword ptr ss:[ebp-B8]
		//mov dl,byte ptr ds:[ecx]
		//cmp dl,2
		//jnz 9098C0
		//mov al,byte ptr ss:[ebp-AC]
		//mov cl,8
		//cmp al,cl
		//nop
		char bytes6[] = {0x85, 0xC0,
						0x0F, 0x85, 0x10, 0x01, 0x00, 0x00,
						0x8B, 0x8D, 0x48, 0xFF, 0xFF, 0xFF,
						0x8A, 0x11,
						0x80, 0xFA, 0x02,
						0x0F, 0x85, 0xFF, 0x00, 0x00, 0x00,
						0x8A, 0x85, 0x54, 0xFF, 0xFF, 0xFF,
						0xB1, 0x08,
						0x3A, 0xC1,
						0x90, 0x90};
		vDataList.push_back( Data(0x9097A8, 37, bytes6) );

		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}

	if (pGameOptionsEx->bMusicSonglistExtend) {
		//treat song entries as int instead of signed byte
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

	//Correct random selection of animation soundsets
	if (pGameOptionsEx->bSoundAnimSoundFix) {
		//decrements the rand number so intervening sounds can be played correctly
		char bytes[7] = {0xF8, 0x49, 0x90, 0x90, 0x89, 0x4D, 0xF8};
		vDataList.push_back( Data(0x642E0D, 7, bytes) );
	
		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}

	if (pGameOptionsEx->bSoundDlgGreetingSubtitles) {
		//bPrintToConsole in CCreatureObject::PlaySound()
		char bytes[] = {0x1};
		vDataList.push_back( Data(0x8D1EF0, 1, bytes) );
		vDataList.push_back( Data(0x8D1F02, 1, bytes) );
		//bPrintToConsole in CMessagePlaySoundset
		vDataList.push_back( Data(0x8D1F7E, 1, bytes) );
		vDataList.push_back( Data(0x8D2019, 1, bytes) );
	
		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}

	//Correct 'periodic fidget' existance sound
	if (pGameOptionsEx->bSoundExistenceFix) {
		//correct func parameter to determine number of available EXISTANCE sounds
		char bytes[1] = {0x46};
		vDataList.push_back( Data(0x8A3B4A, 1, bytes) );

		//correct pointer to EXISTANCE soundset in m_BaseStats
		bytes[0] = 0xAA;
		vDataList.push_back( Data(0x8A3BB6, 1, bytes) );
	
		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}

	if (pGameOptionsEx->bSpellsTargetInvisConfig) {
		//mov edx,dword ptr ss:[ebp+8]
		//mov ecx,dword ptr ss:[ebp-764]
		//push edx
		//push ecx
		//call ...
		char bytes[] = {0x8B, 0x8D, 0x9C, 0xF8, 0xFF, 0xFF,
						0x52,
						0x51,
						0xE8};
		vDataList.push_back( Data(0x911EA7, 9, bytes) );

		//CALL address
		void* ptr = (void*)CCreatureObject_IsValidSpellTarget_CheckInvisible;
		DWORD address = (DWORD)ptr - 5  - 0x911EAF;
		char* bytes2 = (char*)&address;
		vDataList.push_back( Data(0x911EB0, 4, bytes2) );

		//test eax,eax
		//je 911FA7
		//jmp 91222F
		char bytes3[] = {0x85, 0xC0,
						0x0F, 0x84, 0xEB, 0x00, 0x00, 0x00,
						0xE9, 0x6E, 0x03, 0x00, 0x00};
		vDataList.push_back( Data(0x911EB4, 13, bytes3) );

		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}

	if (pGameOptionsEx->bTriggerKitFix) {
		//push eax
		//lea ecx, dword ptr ss:[ebp-5c]
		//call Trigger::GetI()
		//push eax
		//call ...
		char bytes[] = {0x50,
						0x8D, 0x4D, 0xA4,
						0xE8, 0xB6, 0xC0, 0x00, 0x00,
						0x50,
						0xE8};
		vDataList.push_back( Data(0x488331, 11, bytes) );

		//CALL address
		void* ptr = (void*)CCreatureObject_EvaluateTrigger_Kit;
		DWORD address = (DWORD)ptr - 5  - 0x48833B;
		char* bytes2 = (char*)&address;
		vDataList.push_back( Data(0x48833C, 4, bytes2) );
		
		//mov ecx, eax
		char bytes3[] = {0x8B, 0xC8,
						0x90, 0x90, 0x90, 0x90, 0x90,
						0x90, 0x90,
						0x90, 0x90};
		vDataList.push_back( Data(0x488340, 11, bytes3) );

		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}

	if (pGameOptionsEx->bTriggerPickpocketFailed) {
		char bytes[] = {0x22, 0x5F, 0xAA};
		vDataList.push_back( Data(0x9437B2, 3, bytes) );
		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}

	//Quintuple number of kits allowable
	//Externalises KitArray outside CInfGame object
	ClassAbilityTable = new ClAbTable();
	if (pGameOptionsEx->bUserKitsExtend) {
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
	
	if (pGameOptionsEx->bUserLargerTooltipScroll) {
	    //fix brackets in formula when caster level > effect level
		char bytes[] = {0xE0};
		vDataList.push_back( Data(0x6739D9, 1, bytes) );
	
		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}

	if (pGameOptionsEx->bUserExternMageSpellHiding) {
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
		//MOV ECX, int PTR SS:[EBP+8]
		//PUSH ECX
		//NOP NOP NOP
		char bytes4[7] = {0x8B, 0x4D, 0x08, 0x51, 0x90, 0x90, 0x90};
		vDataList.push_back( Data(0x719006, 7, bytes4) ); //Single player
		
		//MOV ECX, int PTR SS:[EBP-5C]
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

	if (pGameOptionsEx->bUserExternRaceSelectionText) {
	
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

	if (pGameOptionsEx->bUserRecordMageSpellScroll) {
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

	if (pGameOptionsEx->bUserFourInventorySlots) {
		//2->4 (All playable classes except Fighter and those listed for 3 slots), 3->4 (Paladin, Ranger, Monk)
		char bytes[1] = {0x04};
		vDataList.push_back( Data(0x639C6F, 1, bytes) );
		vDataList.push_back( Data(0x639C78, 1, bytes) );
		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}

	if (pGameOptionsEx->bVideoDisableBrightestFix) {
		//JE -> JNZ
		//this causes Disable Brighten to work properly with no 3d, but causes blended objects to become green
		char bytes[] = {0x75};
		vDataList.push_back( Data(0x9F5953, 1, bytes) );
	
		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}

	if (pGameOptionsEx->bVideoIWDAnimAttack3Fix) {
		//ASCII "2" -> "3" in "A2E"
		char bytes[] = {0x33};
		vDataList.push_back( Data(0xB4F875, 1, bytes) );
	
		vPatchList.push_back( Patch(vDataList) );
		vDataList.clear();
	}
	
	//Remove crash on alpha rendering of RLE-encoded BAMs
	if (pGameOptionsEx->bVideoVvcAlphaCrashFix) {
		//PUSH 0 to skip AssertionFailedQuit()
		char bytes[1] = {0x00};
		vDataList.push_back( Data(0xA0F1EF, 1, bytes) );
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
