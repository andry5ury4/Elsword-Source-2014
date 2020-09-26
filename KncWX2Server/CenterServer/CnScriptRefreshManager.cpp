#include "CnScriptRefreshThread.h"
#include "CnScriptRefreshManager.h"
#include "KncSend.h"
#include "KAutoPath.h"


//{{ 2010. 06. 15  최육사	실시간 스크립트 갱신
#ifdef SERV_REALTIME_SCRIPT

ImplPfID( KCnScriptRefreshManager, PI_NULL );

ImplementSingleton( KCnScriptRefreshManager );

KCnScriptRefreshManager::KCnScriptRefreshManager() :
m_pRefreshLuaState( NULL )
{
}

KCnScriptRefreshManager::~KCnScriptRefreshManager()
{
	if( m_pRefreshLuaState != NULL )
	{
		lua_close( m_pRefreshLuaState );
		//{{ 2010. 8. 30	최육사	서버 정상 종료 처리		
		m_pRefreshLuaState = NULL;
		//}}
	}
}

void KCnScriptRefreshManager::Init()
{
	// 스크립트 갱신 전용 lua_state 생성!
	m_pRefreshLuaState = lua_open();

	_JIF( m_pRefreshLuaState != NULL, return );

	luaL_openlibs( m_pRefreshLuaState );
	lua_settop( m_pRefreshLuaState, 0 );

	{
		// enum.lua 파싱
		std::string strFile = "Enum.lua";
		KAutoPath kAutoPath;
		kAutoPath.GetPullPath( strFile );
		if( 0 != LUA_DOFILE( m_pRefreshLuaState, strFile.c_str() ) )
		{
			START_LOG( cerr, L"CnScriptRefreshManager : Enum 정보 로드 실패.!" );
			return;
		}
	}

	{
		// enum.lua 파싱
		std::string strFile = "DungeonEnum.lua";
		KAutoPath kAutoPath;
		kAutoPath.GetPullPath( strFile );
		if( 0 != LUA_DOFILE( m_pRefreshLuaState, strFile.c_str() ) )
		{
			START_LOG( cerr, L"CnScriptRefreshManager : DungeonEnum 정보 로드 실패.!" );
			return;
		}
	}

	// 스레드는 무조건 1개만 생성!
	KThreadManager::Init( 1 );

	// 스레드 시작!
	KThreadManager::BeginThread();

	START_LOG( cout, L"스크립트 리프레쉬 스레드 시작!" );
}

KThread* KCnScriptRefreshManager::CreateThread()
{
	return new KCnScriptRefreshThread;
}

#endif SERV_REALTIME_SCRIPT
//}}


