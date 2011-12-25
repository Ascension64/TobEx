#include "ObjectStats.h"

#include "chitin.h"
#include "console.h"
#include "log.h"

CDerivedStats& (CDerivedStats::*Tramp_CDerivedStats_OpAdd)(CDerivedStats&) =
	SetFP(static_cast<CDerivedStats& (CDerivedStats::*)(CDerivedStats&)>	(&CDerivedStats::OpAdd),	0x470945);

CDerivedStats& DETOUR_CDerivedStats::DETOUR_OpAdd(CDerivedStats& cds) {
	float fNumAttacks = CDerivedStats_NumAttacksShortToFloat(numAttacks) + CDerivedStats_NumAttacksShortToFloat(cds.numAttacks);
	numAttacks = 0;
	cds.numAttacks = CDerivedStats_NumAttacksFloatToShort(fNumAttacks);

	return (this->*Tramp_CDerivedStats_OpAdd)(cds);
}

float CDerivedStats_NumAttacksShortToFloat(short s) {
	bool bNegative = s < 0 ? true : false;
	if (bNegative) s = -s;
	float f = (float)s;

	if (f >= 0.0 && f <= 5.0) {
	} else {
		if (f >= 6.0 && f <= 10.0) {
			f -= 5.5;
		} else {
			LPCTSTR lpsz = "CDerivedStats_NumAttacksShortToFloat(): Number of attacks out of range (%d)\r\n";
			console.write(lpsz, 1, s);
			L.timestamp();
			L.append(lpsz, 1, s);
			f = 0.0;
		}
	}

	if (bNegative) f = -f;
	return f;
}

short CDerivedStats_NumAttacksFloatToShort(float f) {
	short s;

	bool bNegative = f < 0.0 ? true : false;
	if (bNegative) f = -f;

	if (f > 5.0) f = 5.0;
	if (f < 0.0) f = 0.0;

	if (f == 0.0 ||
		f == 1.0 ||
		f == 2.0 ||
		f == 3.0 ||
		f == 4.0 ||
		f == 5.0) {
		s = (short)f;
	} else {
		if (f == 0.5 ||
			f == 1.5 ||
			f == 2.5 ||
			f == 3.5 ||
			f == 4.5) {
			s = (short)(f + 5.5);
		} else {
			LPCTSTR lpsz = "CDerivedStats_NumAttacksFloatToShort(): I got a strange number of attacks value (%f)\r\n";
			console.write(lpsz, 1, f);
			L.timestamp();
			L.append(lpsz, 1, f);
			s = 0;
		}
	}

	if (bNegative) s = -s;
	return s;
}