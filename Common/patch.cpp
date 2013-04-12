#include "patch.h"

#include "console.h"
#include "log.h"

//Data implementation
Data::Data() : dwAddress(0), nSize(0), szBytes(NULL), szSrc(NULL) {}

Data::Data(const Data& d) : dwAddress(d.dwAddress), nSize(d.nSize) {
	if (d.nSize > 0) {
		szBytes = new char[d.nSize];
		memcpy(szBytes, d.szBytes, d.nSize);
		if (d.szSrc) {
			szSrc = new char[d.nSize];
			memcpy(szSrc, d.szSrc, d.nSize);
		} else szSrc = NULL;
	} else {
		szBytes = NULL;
		szSrc = NULL;
	}
}

Data::Data(DWORD address, SIZE_T size, char bytes[]) : dwAddress(address), nSize(size) {
	if (bytes) {
		szBytes = new char[size];
		memcpy(szBytes, bytes, size);
	} else {
		szBytes = NULL;
		nSize = 0;
	}
	szSrc = NULL;
}

Data::Data(DWORD address, SIZE_T size, char bytes[], char src[]) : dwAddress(address), nSize(size) {
	if (bytes) {
		szBytes = new char[size];
		memcpy(szBytes, bytes, size);
	} else {
		szBytes = NULL;
		nSize = 0;
	}

	if (src) {
		szSrc = new char[size];
		memcpy(szSrc, src, size);
	} else szSrc = NULL;
}

Data::~Data() {
	if (szBytes) {
		delete[] szBytes;
		szBytes = NULL;
	}
	if (szSrc) {
		delete[] szSrc;
		szSrc = NULL;
	}
}

Data& Data::operator=(const Data& d) {
	dwAddress = d.dwAddress;
	nSize = d.nSize;

	if (szBytes) {
		delete[] szBytes;
		szBytes = NULL;
	}
	if (szSrc) {
		delete[] szSrc;
		szSrc = NULL;
	}
	if (nSize > 0) {
		szBytes = new char[nSize];
		memcpy(szBytes, d.szBytes, nSize);
		if (d.szSrc) {
			szSrc = new char[d.nSize];
			memcpy(szSrc, d.szSrc, nSize);
		}
	}

	return *this;
}

DWORD Data::GetAddress() { return dwAddress; }
SIZE_T Data::GetSize() { return nSize; }
char* Data::GetBytes() { return szBytes; }
char* Data::GetSrc() { return szSrc; }

//Patch implementation
Patch::Patch() : szName(NULL) {}

Patch::Patch(const Patch& p) {
	vData = p.vData;
	if (p.szName) {
		size_t size = strlen(p.szName);
		if (size > 0) {
			szName = new char[size + 1];
			strcpy_s(szName, size + 1, p.szName);
		}
	} else szName = NULL;
}

Patch::Patch(std::vector<Data> vData) : vData(vData), szName(NULL) {}

Patch::Patch(std::vector<Data> vData, const char* sz) : vData(vData) {
	if (sz) {
		size_t size = strlen(sz);
		if (size > 0) {
			szName = new char[size + 1];
			strcpy_s(szName, size + 1, sz);
		} else szName = NULL;
	} else szName = NULL;
}

Patch::~Patch() {
	vData.clear();

	if (szName) {
		delete[] szName;
		szName = NULL;
	}
}

Patch& Patch::operator=(const Patch& p) {
	vData.clear();
	vData = p.vData;

	if (szName) {
		delete[] szName;
		szName = NULL;
	}
	if (p.szName) {
		size_t size = strlen(p.szName);
		if (size > 0) {
			szName = new char[size + 1];
			strcpy_s(szName, size + 1, p.szName);
		}
	}

	return *this;
}

char* Patch::GetName() { return szName; }
std::vector<Data> Patch::GetData() { return vData; }

//function implementation
bool CheckPatch(Data& d) {
	bool b = true;

	if ( d.GetSrc() != NULL ) {
		void* address = reinterpret_cast<void*>(d.GetAddress());
		SIZE_T size = d.GetSize();
		SIZE_T sizeTemp;
		DWORD oldProtect;
		VirtualProtect(address, size, PAGE_READONLY, &oldProtect);

		char* szSrc = d.GetSrc();
		char* szBuf = new char[size +  1];
		szBuf[size] = 0;
		if (ReadProcessMemory(GetCurrentProcess(), address, szBuf, size, &sizeTemp)) {
			if (memcmp(szSrc, szBuf, size)) {
				LPCTSTR lpsz = "ApplyPatch(): source memory differs from source data at address 0x%x\r\n";
				console.writef(CONSOLEFORECOLOR_WARNING, lpsz, address);
				L.timestamp();
				L.appendf(lpsz, address);

				b = false;
			}
		} else {
			LPCTSTR lpsz = "ApplyPatch(): ReadProcessMemory failed, address: 0x%x, error code: %d\r\n";
			DWORD dwError = GetLastError();
			console.writef(CONSOLEFORECOLOR_WARNING, lpsz, address, dwError);
			L.timestamp();
			L.appendf(lpsz, address, dwError);

			b = false;
		}
		delete[] szBuf;
		szBuf = NULL;

		VirtualProtect(address, size, oldProtect, &oldProtect);
	}

	return b;
}

void ApplyPatch(Data& d) {
	void* address = reinterpret_cast<void*>(d.GetAddress());
	SIZE_T size = d.GetSize();
	SIZE_T sizeTemp;
	DWORD oldProtect;
	VirtualProtect(address, size, PAGE_EXECUTE_READWRITE, &oldProtect);

	if ( !WriteProcessMemory(GetCurrentProcess(), address, d.GetBytes(), size, &sizeTemp) ) {
		LPCTSTR lpsz = "ApplyPatch(): WriteProcessMemory failed, address: 0x%x, error code: %d\r\n";
		DWORD dwError = GetLastError();
		console.writef(CONSOLEFORECOLOR_WARNING, lpsz, address, dwError);
		L.timestamp();
		L.appendf(lpsz, address, dwError);
	}
	VirtualProtect(address, size, oldProtect, &oldProtect);
	return;
}

void InitUserPatches(std::vector<Patch>* pvPatchList, std::vector<Data>* pvDataList) {
	WIN32_FIND_DATA w32fd = {0};
	LPCSTR szRegexp = "./TobEx_ini/patch/*.patch";
	DWORD nErrorCode;
	HANDLE hFind;

	hFind = FindFirstFile(szRegexp, &w32fd);
	nErrorCode = GetLastError();
	if (nErrorCode == ERROR_FILE_NOT_FOUND ||
		nErrorCode == ERROR_PATH_NOT_FOUND) {
		//do nothing
	} else if (nErrorCode != ERROR_SUCCESS) {
		LPCTSTR lpsz = "InitUserPatches(): FindFirstFile() failed (error code %d)\r\n";
		console.writef(lpsz, nErrorCode);
		L.timestamp();
		L.appendf(lpsz, nErrorCode);
	} else {
		do {
			LPCSTR szDir = "./TobEx_ini/patch/";
			char* szFile = new char[MAX_PATH];
			int i = 0;
			while (i < MAX_PATH) szFile[i++] = 0;
			strcpy_s(szFile, MAX_PATH, szDir);
			strcat_s(szFile, MAX_PATH, w32fd.cFileName);

			OFSTRUCT opf;

			HANDLE hFile = (HANDLE)OpenFile(szFile, &opf, OF_READ);
			nErrorCode = GetLastError();
			if (nErrorCode) {
				LPCTSTR lpsz = "InitUserPatches(): unable to open %s. Error code %d.\r\n";
				console.writef(lpsz, w32fd.cFileName, nErrorCode);
				L.timestamp();
				L.appendf(lpsz, w32fd.cFileName, nErrorCode);
			} else {
				DWORD dwBytesRead;
				if (w32fd.nFileSizeLow > 0) {
					LPSTR szBuf = new char[w32fd.nFileSizeLow + 1];
					szBuf[w32fd.nFileSizeLow] = 0;
					if (ReadFile(hFile, (LPVOID)szBuf, w32fd.nFileSizeLow, &dwBytesRead, NULL)) {
						CString sBuf(szBuf);

						int nLineNumber = -1;
						CString sName;
						bool bInComment = false;
						bool bInName = false;
						bool bEnabled = false;
						bool bHasAddress = false;
						DWORD dwAddress = 0;
						DWORD dwPatchSize = 0;
						char* ptrSource = NULL;
						char* ptrTarget = NULL;

						int nIndex = 0;
						while (!sBuf.IsEmpty()) {
							CString sLine;
							if (sBuf.Find('\n') == -1) {
								//last line
								sLine = sBuf;
								sBuf.Empty();
							} else {
								sLine = sBuf.Left(sBuf.Find('\n'));
								sBuf = sBuf.Right(sBuf.GetLength() - sBuf.Find('\n') - 1);
							}

							sLine.TrimLeft();
							sLine.TrimRight();
							nLineNumber++;

							//remove comments
							if (sLine.Find("*/") != -1 && bInComment) {
								sLine = sLine.Right(sLine.GetLength() - sLine.Find("*/") - 2);
								bInComment = false;
							}
							if (bInComment) continue;
							if (sLine.Left(2).Compare("//") == 0) continue;
							while (sLine.Find("/*") != -1 &&
								sLine.Find("*/", sLine.Find("/*") + 2) != -1) {
								sLine = sLine.Left(sLine.Find("/*")) + sLine.Right(sLine.GetLength() - sLine.Find("*/") - 2);
							}
							if (sLine.Find("//") != -1) sLine = sLine.Left(sLine.Find("//"));
							if (sLine.Find("/*") != -1) {
								sLine = sLine.Left(sLine.Find("/*"));
								bInComment = true;
							}
					
							if (sLine.IsEmpty()) continue;
					
							//name
							if (sLine.GetAt(0) == '[') {
								if (bInName) {
									//reset
									if (!pvDataList->empty()) {
										pvPatchList->push_back( Patch(*pvDataList, (LPCTSTR)sName) );
										pvDataList->clear();
									}
									bInName = false;
									bEnabled = false;
									bHasAddress = false;
								}

								sLine = sLine.Right(sLine.GetLength() - 1);
								if (sLine.Find(']') == -1) {
									LPCTSTR lpsz = "%s,%d: missing ']' in patch name\r\n";
									console.writef(lpsz, w32fd.cFileName, nLineNumber);
									L.timestamp();
									L.appendf(lpsz, w32fd.cFileName, nLineNumber);

									sName = sLine;
								} else {
									sName = sLine.Left(sLine.Find(']'));
								}
								sName.TrimLeft();
								sName.TrimRight();
								if (!sName.IsEmpty()) {
									bInName = true;
								} else {
									LPCTSTR lpsz = "%s,%d: empty name in [], will ignore\r\n";
									console.writef(lpsz, w32fd.cFileName, nLineNumber);
									L.timestamp();
									L.appendf(lpsz, w32fd.cFileName, nLineNumber);
								}
								continue;
							}

							//field
							if (sLine.Find('=', 1) != -1) {
								if (!bInName) {
									LPCTSTR lpsz = "%s,%d: found field (expected name)\r\n";
									console.writef(lpsz, w32fd.cFileName, nLineNumber);
									L.timestamp();
									L.appendf(lpsz, w32fd.cFileName, nLineNumber);

									continue;
								}

								int nIndexEquals = sLine.Find('=');
								CString sLeft = sLine.Left(nIndexEquals);
								sLeft.TrimRight();

								CString sRight = sLine.Right(sLine.GetLength() - nIndexEquals - 1);
								sRight.TrimLeft();

								if (sLeft.CompareNoCase("Enabled") == 0) {
									bEnabled = (bool)atoi(sRight.GetBuffer(0));
									continue;
								}

								if (sLeft.CompareNoCase("Address") == 0) {
									if (bHasAddress) {
										LPCTSTR lpsz = "%s,%d: address already specified, will overwrite\r\n";
										console.writef(lpsz, w32fd.cFileName, nLineNumber);
										L.timestamp();
										L.appendf(lpsz, w32fd.cFileName, nLineNumber);
									}

									if (sRight.GetAt(0) == 'v' ||
										sRight.GetAt(0) == 'V') {
										//virtual address
										dwAddress = 0;
									}
									else if (sRight.GetAt(0) == 'b' ||
										sRight.GetAt(0) == 'B') {
										//base address
										dwAddress = 0x400000;
									} else {
										LPCTSTR lpsz = "%s,%d: no address specifier\r\n";
										console.writef(lpsz, w32fd.cFileName, nLineNumber);
										L.timestamp();
										L.appendf(lpsz, w32fd.cFileName, nLineNumber);
										continue;
									}
									sRight = sRight.Right(sRight.GetLength() - 1);

									DWORD dwOffset;
									sscanf_s(sRight.GetBuffer(0), "%x", &dwOffset);
									dwAddress += dwOffset;
									bHasAddress = true;

									continue;
								} //address

								if (sLeft.CompareNoCase("Source") == 0) {
									if (!bHasAddress) {
										LPCTSTR lpsz = "%s,%d: found source (expected address)\r\n";
										console.writef(lpsz, w32fd.cFileName, nLineNumber);
										L.timestamp();
										L.appendf(lpsz, w32fd.cFileName, nLineNumber);
										continue;
									}
									if (!bEnabled) continue;
									if (ptrSource) {
										LPCTSTR lpsz = "%s,%d: source already specified, will overwrite\r\n";
										console.writef(lpsz, w32fd.cFileName, nLineNumber);
										L.timestamp();
										L.appendf(lpsz, w32fd.cFileName, nLineNumber);

										delete ptrSource;
										ptrSource = NULL;
									}

									while (sRight.Find(',') != -1) sRight.Delete(sRight.Find(','));

									dwPatchSize = sRight.GetLength() / 2;
									if (dwPatchSize > 0) {
										ptrSource = new char[dwPatchSize + 1];
										ptrSource[dwPatchSize] = 0;
										int i = 0;
										while (i < dwPatchSize) {
											int n;
											sscanf_s(sRight.Left(2).GetBuffer(0), "%x", &n);
											ptrSource[i] = n;
											sRight = sRight.Right(sRight.GetLength() - 2);
											i++;
										}
									} else {
										LPCTSTR lpsz = "%s,%d: source patch size is zero\r\n";
										console.writef(lpsz, w32fd.cFileName, nLineNumber);
										L.timestamp();
										L.appendf(lpsz, w32fd.cFileName, nLineNumber);
									}
									continue;
								} //source

								if (sLeft.CompareNoCase("Target") == 0) {
									if (!bHasAddress) {
										LPCTSTR lpsz = "%s,%d: found target (expected address)\r\n";
										console.writef(lpsz, w32fd.cFileName, nLineNumber);
										L.timestamp();
										L.appendf(lpsz, w32fd.cFileName, nLineNumber);
										continue;
									}
									if (!bEnabled) {
										bHasAddress = false;
										if (ptrSource) {
											delete[] ptrSource;
											ptrSource = NULL;
										}
										if (ptrTarget) {
											delete[] ptrTarget;
											ptrTarget = NULL;
										}
										continue;
									}
									/*if (ptrSource == NULL) {
										LPCTSTR lpsz = "%s,%d: found target (expected source)\n";
										console.writef(lpsz, w32fd.cFileName, nLineNumber);
										L.timestamp();
										L.appendf(lpsz, w32fd.cFileName, nLineNumber);
										continue;
									}*/
									if (ptrSource &&
										dwPatchSize != sRight.GetLength() / 2) {
										LPCTSTR lpsz = "%s,%d: target and source patch sizes do not match, will skip\r\n";
										console.writef(lpsz, w32fd.cFileName, nLineNumber);
										L.timestamp();
										L.appendf(lpsz, w32fd.cFileName, nLineNumber);

										bHasAddress = false;
										dwPatchSize = 0;
										delete[] ptrSource;
										ptrSource = NULL;
										continue;
									}
									if (ptrTarget) {
										LPCTSTR lpsz = "%s,%d: target already specified, will overwrite\r\n";
										console.writef(lpsz, w32fd.cFileName, nLineNumber);
										L.timestamp();
										L.appendf(lpsz, w32fd.cFileName, nLineNumber);

										delete[] ptrTarget;
										ptrTarget = NULL;
									}

									while (sRight.Find(',') != -1) sRight.Delete(sRight.Find(','));

									dwPatchSize = sRight.GetLength() / 2;
									if (dwPatchSize > 0) {
										ptrTarget = new char[dwPatchSize + 1];
										ptrTarget[dwPatchSize] = 0;
										int i = 0;
										while (i < dwPatchSize) {
											int n;
											sscanf_s(sRight.Left(2).GetBuffer(0), "%x", &n);
											ptrTarget[i] = n;
											sRight = sRight.Right(sRight.GetLength() - 2);
											i++;
										}

										pvDataList->push_back( Data(dwAddress, dwPatchSize, ptrTarget, ptrSource) );

										bHasAddress = false;
										dwPatchSize = 0;
										if (ptrSource) {
											delete[] ptrSource;
											ptrSource = NULL;
										}
										if (ptrTarget) {
											delete[] ptrTarget;
											ptrTarget = NULL;
										}

									} else {
										LPCTSTR lpsz = "%s,%d: target size is zero\r\n";
										console.writef(lpsz, w32fd.cFileName, nLineNumber);
										L.timestamp();
										L.appendf(lpsz, w32fd.cFileName, nLineNumber);
									}
									continue;
								} //target
							} //field

							LPCTSTR lpsz = "%s,%d: unknown instruction\r\n";
							console.writef(lpsz, w32fd.cFileName, nLineNumber);
							L.timestamp();
							L.appendf(lpsz, w32fd.cFileName, nLineNumber);
						} //while

						//clean up
						if (!pvDataList->empty()) {
							pvPatchList->push_back( Patch(*pvDataList, (LPCTSTR)sName) );
							pvDataList->clear();
						}

						if (bInComment) {
							LPCTSTR lpsz = "%s: reached EOF (expected end of comment)\r\n";
							console.writef(lpsz, w32fd.cFileName);
							L.timestamp();
							L.appendf(lpsz, w32fd.cFileName);
						}
						if (bHasAddress) {
							LPCTSTR lpsz = "%s: reached EOF (expected source/target)\r\n";
							console.writef(lpsz, w32fd.cFileName);
							L.timestamp();
							L.appendf(lpsz, w32fd.cFileName);
						}
						if (ptrSource) {
							LPCTSTR lpsz = "%s: reached EOF (expected target)\r\n";
							console.writef(lpsz, w32fd.cFileName);
							L.timestamp();
							L.appendf(lpsz, w32fd.cFileName);

							delete[] ptrSource;
							ptrSource = NULL;
						}
						if (ptrTarget) {
							LPCTSTR lpsz = "%s: reached EOF (before target cleared)\r\n";
							console.writef(lpsz, w32fd.cFileName);
							L.timestamp();
							L.appendf(lpsz, w32fd.cFileName);

							delete[] ptrTarget;
							ptrTarget = NULL;
						}

					} else {
						LPCTSTR lpsz = "InitUserPatches(): could not read from %s (error code %d)\r\n";
						console.writef(lpsz, w32fd.cFileName, GetLastError());
						L.timestamp();
						L.appendf(lpsz, w32fd.cFileName, GetLastError());
					}

					delete[] szBuf;
					szBuf = NULL;
				} //dwFileSize > 0
				CloseHandle(hFile);
			}

			delete[] szFile;
		} while (FindNextFile(hFind, &w32fd));

		if (!FindClose(hFind)) {
			LPCTSTR lpsz = "InitUserPatches(): FindClose() failed (error code %d)\r\n";
			console.writef(lpsz, nErrorCode);
			L.timestamp();
			L.appendf(lpsz, nErrorCode);
		}
	}

	return;
}
