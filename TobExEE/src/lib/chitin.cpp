//TobExEE
#include "chitin.h"
#include "p_chitin.h"

#include "stdafx.h"

CBaldurChitin* g_pChitin = NULL;

DefineLibNoRetFunc(CBaldurChitin&, CBaldurChitin, CBaldurChitin, (int argc, char* argv[]), Construct, Construct, (argc, argv), CBALDURCHITIN_CONSTRUCT);
DefineLibMemberFunc(CInfGame&, CBaldurChitin, GetInfGame, (), GetInfGame, GetInfGame, (), CBALDURCHITIN_GETINFGAME);

DefineLibMemberFunc(void, CBaldurChitin, DoExit, (unsigned int dwLine, const char* szFile, const char* szReason), DoExit, DoExit, (dwLine, szFile, szReason), CBALDURCHITIN_DOEXIT);
