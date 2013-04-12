#include "EngineCommon.h"

#include "objcre.h"
#include "infgame.h"
#include "chitin.h"
#include "tlkcore.h"

void EngineCommon_ApplySoundset(CCreatureObject& cre) {

	IECString voiceset((LPTSTR)cre.voiceset);
	if (strcmp((LPTSTR)cre.voiceset, "") == 0) { //use default soundset

		char sex = cre.oBase.m_cGender;

		for (int nRow = 0; nRow < 100; nRow++) {
			STRREF ref = g_pChitin->pGame->GetCharSndStrRef(0, nRow, sex);
			cre.m_header.m_strrefSoundset[nRow] = ref;
			g_pChitin->m_TlkTbl.GetTlkString(ref, cre.soundset[nRow]);
		}

	} else {

		CRuleTable& csound = g_pChitin->pGame->CSOUND;

		for (int i = 1; i < csound.nCols; i++) {
			//check if soundset present in CSOUND.2DA
			IECString& colHeader = *(csound.pColHeaderArray + i);

			if (voiceset.Compare((LPCTSTR)colHeader) == 0) { //if present, add StrRefs to cre

				for (int j = 0; j < 100; j++) {
					if (j == 74) continue; //skip biography

					for (int k = 0; k < csound.nRows; k++) {
						IECString& rowHeader = *(csound.pRowHeaderArray + k);

						if ( atoi((LPCTSTR)rowHeader) == j ) {
							IECString value = csound.GetValue(colHeader, rowHeader);
							STRREF ref = atoi((LPCTSTR)value);

							if (ref) {
								cre.m_header.m_strrefSoundset[j] = ref;
								g_pChitin->m_TlkTbl.GetTlkString(ref, cre.soundset[j]);
							} else {
								cre.m_header.m_strrefSoundset[j] = -1;
								g_pChitin->m_TlkTbl.GetTlkString(-1, cre.soundset[j]);
							}

						} //atoi
					} //for k
				} //for j

				cre.voiceset = ""; //set to default soundset
			} //Compare

			//if not present, do nothing
		} //i
	}

}