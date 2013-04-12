//TobExEE
#ifndef CHITINCORE_H
#define CHITINCORE_H

#include "chitin.h"

//CBaldurChitin
DeclareTrampMemberFunc(CBaldurChitin&, CBaldurChitin, Construct, (int argc, char* argv[]), Construct);
DeclareTrampMemberFunc(void, CBaldurChitin, DoExit, (unsigned int dwLine, const char* szFile, const char* szReason), DoExit);

class DETOUR_CBaldurChitin : public CBaldurChitin {
public:
	CBaldurChitin& DETOUR_Construct(int argc, char* argv[]);
	void DETOUR_DoExit(unsigned int dwLine, const char* szFile, const char* szReason);
};

#endif //CHITINCORE_H