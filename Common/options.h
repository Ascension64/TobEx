#ifndef OPTIONS_H
#define OPTIONS_H

#include "stdafx.h"
#include <hash_map>

struct hash_cmp_str { bool operator()(const char *a, const char *b) const { return std::strcmp(a, b) < 0; } };

class CGameOptionsEx {
public:
	CGameOptionsEx() {}
	~CGameOptionsEx();
	void SetOption(LPCTSTR szOption, LPCTSTR szSection, LPCTSTR szKey, LPCTSTR szDefault = 0);
	int GetOption(LPCTSTR szOption);
	stdext::hash_map<LPCTSTR, int, stdext::hash_compare<LPCTSTR, hash_cmp_str>> GetMap();

protected:
	stdext::hash_map<LPCTSTR, int, stdext::hash_compare<LPCTSTR, hash_cmp_str>> m_hmOptions;
};

int GetCoreIniValue(LPCTSTR szSection, LPCTSTR szKey, LPCTSTR szDefault = 0);
int GetTweakIniValue(LPCTSTR szSection, LPCTSTR szKey, LPCTSTR szDefault = 0);

#endif //OPTIONS_H