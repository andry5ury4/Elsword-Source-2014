///////////////////////////////////////////////////////////////////////////////
//
//  Module: CrashRpt.cpp
//
//    Desc: See CrashRpt.h
//
// Copyright (c) 2003 Michael Carruth
//
///////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CrashRpt.h"
#include "CrashHandler.h"

#ifdef _DEBUG
#define CRASH_ASSERT(pObj)          \
   if (!pObj || sizeof(*pObj) != sizeof(CCrashHandler))  \
      DebugBreak()                                       
#else
#define CRASH_ASSERT(pObj)
#endif // _DEBUG

CRASHRPTAPI LPVOID Install(LPGETLOGFILE pfn, LPCTSTR lpcszTo, LPCTSTR lpcszSubject)
{
//	TCHAR email[256] = {0,};

//	GetPrivateProfileString("SETUP", "E-MAIL","ERROR", email, 256, "./CrashReport.ini");
	CCrashHandler *pImpl = new CCrashHandler(pfn, lpcszTo, lpcszSubject);
//	KSystemAnalysis temp;
//	temp.StoreMySystemAnalysis();
	CRASH_ASSERT(pImpl);

	return pImpl;
}

CRASHRPTAPI void Uninstall(LPVOID lpState)
{
   CCrashHandler *pImpl = (CCrashHandler*)lpState;
   CRASH_ASSERT(pImpl);

   delete pImpl;
}

CRASHRPTAPI void AddFile(LPVOID lpState, LPCTSTR lpFile, LPCTSTR lpDesc)
{
   CCrashHandler *pImpl = (CCrashHandler*)lpState;
   CRASH_ASSERT(pImpl);

   pImpl->AddFile(lpFile, lpDesc);
}

CRASHRPTAPI void GenerateErrorReport(LPVOID lpState, PEXCEPTION_POINTERS pExInfo)
{
   CCrashHandler *pImpl = (CCrashHandler*)lpState;
   CRASH_ASSERT(pImpl);

   pImpl->GenerateErrorReport(pExInfo);
}

CRASHRPTAPI void SetEMailSubjectPrefix(LPVOID lpState, LPCTSTR szPrefix )
{
	CCrashHandler *pImpl = (CCrashHandler*)lpState;
	CRASH_ASSERT(pImpl);

	pImpl->SetMailSubjectPrefix( szPrefix );
}