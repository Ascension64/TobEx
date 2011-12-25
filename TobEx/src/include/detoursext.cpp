#include "detoursext.h"

#include "detours.h"

//goes from TARGET -> MIDDLE -> DETOUR
void ThisToStd(BYTE* target) {
	//not deleted
	BYTE* middle = reinterpret_cast<BYTE*>(new BYTE[8]);

	//write the middle bit (to jump to detour function)
	DWORD detour = static_cast<DWORD>(*(reinterpret_cast<DWORD*>(target + 1))) + reinterpret_cast<DWORD>(target) + 5;
	DWORD jump = detour - reinterpret_cast<DWORD>(middle + 3 + 5);
	middle[0] = 0x58;	// pop eax
	middle[1] = 0x51;	// push ecx
	middle[2] = 0x50;	// push eax
	middle[3] = 0xE9;	// jmp
	*(reinterpret_cast<DWORD*>(middle + 4)) = jump;

	//write into the target function (to jump to middle bit)
	jump = static_cast<DWORD>(middle - target - 5);
	DWORD dwBack;
	VirtualProtect(target, 5, PAGE_READWRITE, &dwBack);
	*(reinterpret_cast<DWORD*>(target + 1)) = jump;
	VirtualProtect(target, 5, dwBack, &dwBack);

	return;
}

void DetourMemberFunctionOld(PVOID* pTargetFunc, PVOID detourFunc, PVOID targetFunc) {
	DetourTransactionBegin();
	DetourAttach(pTargetFunc, detourFunc);
	DetourTransactionCommit();
	ThisToStd(reinterpret_cast<BYTE*>(targetFunc));
	return;
}