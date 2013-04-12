#include "options.h"

#include "utils.h"

static LPCTSTR s_szDefault = "0";
static const DWORD s_nBufSize = 8;
static char s_szBuf[s_nBufSize] = { 0 };
static LPCTSTR s_szFileCore = "./TobEx_ini/TobExCore.ini";
static LPCTSTR s_szFileTweak = "./TobEx_ini/TobExTweak.ini";

CGameOptionsEx::~CGameOptionsEx() {
	m_hmOptions.clear();
}

void CGameOptionsEx::SetOption(LPCTSTR szOption, LPCTSTR szSection, LPCTSTR szKey, LPCTSTR szDefault) {
	strcmp(szSection, "Tweak")
		? (m_hmOptions[szOption] = GetCoreIniValue(szSection, szKey, szDefault))
		: (m_hmOptions[szOption] = GetTweakIniValue("Tweak", szKey, szDefault));
	return;
}

int CGameOptionsEx::GetOption(LPCTSTR szOption) {
	return (m_hmOptions.find(szOption) == m_hmOptions.end()) ? 0 : m_hmOptions[szOption];  
}

stdext::hash_map<LPCTSTR, int, stdext::hash_compare<LPCTSTR, hash_cmp_str>> CGameOptionsEx::GetMap() {
	return m_hmOptions;
}

int GetCoreIniValue(LPCTSTR szSection, LPCTSTR szKey, LPCTSTR szDefault) {
	int n = 0;
	GetPrivateProfileString(szSection, szKey, szDefault, s_szBuf, s_nBufSize, s_szFileCore);
	sscanf_s(s_szBuf, "%d", &n);
	return n;
}

int GetTweakIniValue(LPCTSTR szSection, LPCTSTR szKey, LPCTSTR szDefault) {
	int n = 0;
	GetPrivateProfileString(szSection, szKey, szDefault, s_szBuf, s_nBufSize, s_szFileTweak);
	sscanf_s(s_szBuf, "%d", &n);
	return n;
}
