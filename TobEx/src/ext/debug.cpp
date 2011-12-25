#include "debug.h"

#include "chitin.h"
#include "sndcore.h"
#include "vidcore.h"
#include "rescore.h"
#include "msgcore.h"
#include "infgame.h"
#include "objcre.h"
#include "engine.h"
#include "console.h"
#include "network.h"
#include "tlkcore.h"
#include "cstringex.h"

void debug() {
/*
	console.write("CBaldurChitin ideal size 720Ch, actual size: %Xh\r\n", 1, sizeof(CBaldurChitin));
	console.write("CSoundMixer size 28DAh, actual size: %Xh\r\n", 1, sizeof(CSoundMixer));
	console.write("CVideo size 168h, actual size: %Xh\r\n", 1, sizeof(CVideo));
	console.write("CResHandler size 2A8h, actual size: %Xh\r\n", 1, sizeof(CResHandler));
	console.write("CGUIMain size 19E8h, actual size: %Xh\r\n", 1, sizeof(CBaldurChitin::CGUIMain));
	console.write("CBaldurMessage size 114h, actual size: %Xh\r\n", 1, sizeof(CMessageHandler));
	console.write("CTlkTbl size A6h, actual size: %Xh\r\n", 1, sizeof(CTlkTbl));

	console.write("CNetwork size F3Ah, actual size: %Xh\r\n", 1, sizeof(CNetwork));
	console.write("CNetworkWindow size 88h, actual size: %Xh\r\n", 1, sizeof(CNetworkWindow));

	console.write("CInfGame size 4DC8h, actual size: %Xh\r\n", 1, sizeof(CInfGame));
	console.write("CButtonArray size 1820h, actual size: %Xh\r\n", 1, sizeof(CInfGame::CButtonArray));

	console.write("CVideoMode size 732h, actual size: %Xh\r\n", 1, sizeof(CVideoMode));

	console.write("CCreatureObject size 6774h, actual size: %Xh\r\n", 1, sizeof(CCreatureObject));

	console.write("CSound size 6Ah, actual size: %Xh\r\n", 1, sizeof(CSound));

	console.write("CEngine size FEh, actual size: %Xh\r\n", 1, sizeof(CEngine));
	console.write("CCharGen size 148Ch, actual size: %Xh\r\n", 1, sizeof(CCharGen));
	console.write("CRecord size 1520h, actual size: %Xh\r\n", 1, sizeof(CRecord));
	console.write("CStore size 148ah, actual size: %Xh\r\n", 1, sizeof(CStore));

	//to check location of members, just replace the temp object type, member name and expected location
	//CBaldurChitin temp;
	//console.write("CBaldurChitin.u414e at u414e, actual location: %Xh\r\n", 1, (DWORD)(&temp.u414e) - (DWORD)(&temp));
*/
	return;
}