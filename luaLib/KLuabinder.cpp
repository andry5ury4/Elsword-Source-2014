#include "KLuabinder.h"

#include <iostream>

//#include "KSuperAssert.h"
//#include "KTDXErrorDefine.h"

//---------------------------------------------------------------------------
KLuabinder::KLuabinder()
: m_pkLuaState( NULL )
{
	Initialize();
}

//---------------------------------------------------------------------------
KLuabinder::~KLuabinder()
{
    Finalize();
}
//---------------------------------------------------------------------------
void KLuabinder::Initialize()
{
    m_pkLuaState = lua_open();

    // init Lua
    //luaopen_base(m_pkLuaState);
    //luaopen_table(m_pkLuaState);
    //luaopen_io(m_pkLuaState);
    //luaopen_string(m_pkLuaState);
    //luaopen_math(m_pkLuaState);
	luaL_openlibs( m_pkLuaState );

    lua_settop(m_pkLuaState, 0);

    // LuaTinker
    lua_tinker::init(m_pkLuaState);
}
//---------------------------------------------------------------------------
void KLuabinder::Finalize()
{
    // close Lua
    lua_close(m_pkLuaState);
}
//---------------------------------------------------------------------------
HRESULT KLuabinder::DoFile(const char* strFilename)
{
	if ( m_pkLuaState == NULL )
		return E_FAIL;

	// note!! .kom파일에 포함되지 않은 파일을 직접 참조할 때만 사용해야.
	bool bOK = lua_tinker::dofile( m_pkLuaState, strFilename );

	if( true == bOK )
		return S_OK;
	else
		return E_FAIL;
}
//---------------------------------------------------------------------------
HRESULT KLuabinder::DoString(const char* strBuf)
{
	if ( m_pkLuaState == NULL )
		return E_FAIL;

	bool bOK = lua_tinker::dostring( m_pkLuaState, strBuf );

	if( true == bOK )
		return S_OK;
	else
		return E_FAIL;
}

//---------------------------------------------------------------------------
void KLuabinder::Interpret()
{    
	/*
    while (true)
    {
        KCon << "> ";
        std::string strBuf = KCon.GetString();
        if (strBuf == "exit")
            break;

        DoString(strBuf);
    }
	*/
}
//---------------------------------------------------------------------------