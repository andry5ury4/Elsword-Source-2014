#include "StdAfx.h"
#include "Util.h"

void ConvertCharToWCHAR(std::wstring& dest, const char* pSrc, int iCodePage)
{
	dest.clear();

	if( pSrc == NULL )
		return;

	int len = (int)strlen(pSrc);

	if( len != -1 && len <= 0 ) // florist. 0이어도 통과시키지 말자.
		return;

	// figure out how many wide characters we are going to get 
	int nChars = MultiByteToWideChar( iCodePage , 0 , pSrc , len , NULL , 0 ) ; 
	if ( len == -1 )
		-- nChars ; 
	if ( nChars == 0 )
		return;

	// convert the narrow string to a wide string 
	// nb: slightly naughty to write directly into the string like this
	dest.resize( nChars ) ; 
	MultiByteToWideChar( iCodePage , 0 , pSrc , len , 
		const_cast<wchar_t*>(dest.c_str()) , nChars ) ; 
}

void ConvertWCHARToChar( std::string& dest, const std::wstring& src, int iCodePage )
{
	dest.clear();
	if( src.empty() )
		return; 

	int iSrcLength = (int) src.length();
	if ( iSrcLength <= 0 )
	{
		dest = "";
		return;
	}//if

	int iDestSize = ::WideCharToMultiByte( iCodePage, 0, src.c_str(), iSrcLength, NULL, 0, NULL, NULL );
	if ( iDestSize <= 0 )
	{
		dest = "";
		return;
	}//if

	char* pszConv = (char*) _alloca( iDestSize * sizeof(char) );
	ASSERT( pszConv != NULL );
	int iNewSize = ::WideCharToMultiByte( iCodePage, 0, src.c_str(), iSrcLength, pszConv, iDestSize, NULL, NULL );
	ASSERT( iNewSize == iDestSize );
	dest.assign( pszConv, iNewSize );
}