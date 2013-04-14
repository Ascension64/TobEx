#ifndef UTILS_H
#define UTILS_H

#include "win32def.h"

const char* const months[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
const char* const days[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

#define GetEip(Eip) __asm {						\
	__asm mov eax, [ebp+4] /*return address*/	\
	__asm mov Eip, eax							\
}

#define GetThis(pThis) __asm mov pThis, ecx;

#define SetVT(obj, vt) (*(unsigned int*)obj = vt)
#define IENew new(0)
#define IENewA new[](0)

#ifdef _DEBUG 
//In _DEBUG, CSyncObject contains an extra CString, screwing up the sizes of game objects
class _CCriticalSection { //Size 20h
	DWORD* vt; //0h, AA61F8
	HANDLE m_hObject; //4h, from CSyncObject
	CRITICAL_SECTION cs; //8h
};
#endif

template <typename T> T SetFP(T pFunction, unsigned int nAddress) {
	if (sizeof(T) == 4) {
		*(unsigned int*)&pFunction = nAddress;
	}
	return pFunction;
}

//declares and defines a const function pointer to a ctor/dtor (no return value), and defines the function
#define DefineLibNoRetFunc(returnType, className, funcName, params, dummyName, funcptrName, args, address) \
	returnType (className::* const className ## _ ## funcptrName)params = SetFP(static_cast<returnType (className::* const)params>(&className::dummyName), address); \
	className::funcName params { (this->*className ## _ ## funcptrName)args; }

//declares and defines a const function pointer to a member function, and defines the function
#define DefineLibMemberFunc(returnType, className, funcName, params, dummyName, funcptrName, args, address) \
	returnType (className::* const className ## _ ## funcptrName)params = SetFP(static_cast<returnType (className::* const)params>(&className::dummyName), address); \
	returnType className::funcName params { return (this->*className ## _ ## funcptrName)args; }

//declares and defines a const function pointer to a friend function, and defines the function
#define DefineLibFriendFunc(returnType, callType, className, funcName, params, dummyName, funcptrName, args, address) \
	returnType (callType * const className ## _ ## funcptrName)params = SetFP(static_cast<returnType (callType * const)params>(&className ## _ ## dummyName), address); \
	returnType callType funcName params { return (*className ## _ ## funcptrName)args; }

//declares and defines a const function pointer to a static member function, and defines the function
#define DefineLibStaticFunc(returnType, callType, className, funcName, params, funcptrName, args, address) \
	returnType (callType * const className ## _ ## funcptrName)params = reinterpret_cast<returnType (callType *)params>(address); \
	returnType callType className::funcName params { return (*className ## _ ## funcptrName)args; }

//declares and defines a const function pointer to a global function
#define DefineGlobalFuncPtr(returnType, callType, funcName, params, address) \
	returnType (callType * const funcName)params = reinterpret_cast<returnType (callType *)params>(address);

//declares an extern function pointer Tramp_className_funcName(params) to a member function className::dummyName(params)
#define DeclareTrampMemberFunc(returnType, className, funcName, params, funcptrName) \
	extern returnType (className::* Tramp ## _ ## className ## _ ## funcptrName)params;

//declares an extern function pointer Tramp_className_funcName(params) to a static member function className::dummyName(params)
#define DeclareTrampStaticFunc(returnType, callType, className, funcName, params, funcptrName) \
	extern returnType (callType * Tramp ## _ ## className ## _ ## funcptrName)params;

//declares a function pointer Tramp_funcName(params) to a global function
#define DeclareTrampGlobalFuncPtr(returnType, callType, funcName, params) \
	extern returnType (callType * Tramp ## _ ## funcName)params;

//defines a function pointer Tramp_className_funcName(params) to a member function className::dummyName(params)
#define DefineTrampMemberFunc(returnType, className, funcName, params, dummyName, funcptrName, address) \
	returnType (className::* Tramp ## _ ## className ## _ ## funcptrName)params = SetFP(static_cast<returnType (className::*)params>(&className::dummyName), address);

//defines a function pointer Tramp_className_funcName(params) to a static member function className::dummyName(params)
#define DefineTrampStaticFunc(returnType, callType, className, funcName, params, funcptrName, address) \
	returnType (callType * Tramp ## _ ## className ## _ ## funcptrName)params = reinterpret_cast<returnType (callType *)params>(address);

//defines a function pointer Tranp_funcName(params) to a global function
#define DefineTrampGlobalFuncPtr(returnType, callType, funcName, params, address) \
	returnType (callType * Tramp ## _ ## funcName)params = reinterpret_cast<returnType (callType *)params>(address);

#endif //UTILS_H
