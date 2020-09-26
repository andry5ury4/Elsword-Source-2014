
#include "ServerDefine.h"

//////////////////////////////////////////////////////////////////////////
// for visual assist

#ifndef EVENT_HANDLER
#define EVENT_HANDLER( eventid )
#endif

#ifndef EVENT_HANDLER_NOPARAM
#define EVENT_HANDLER_NOPARAM( eventid )
#endif

#ifndef _EVENT_HANDLER
#define _EVENT_HANDLER( eventid, structtype )
#endif


//////////////////////////////////////////////////////////////////////////
// 여기서 부터 이벤트 핸들러 정의!


EVENT_HANDLER( EGS_KNPROTECT_AUTH_CHECK_NOT );

EVENT_HANDLER_NOPARAM( EGS_AGREE_HACK_USER_REQ );
_EVENT_HANDLER( DBE_AGREE_HACK_USER_ACK, KEGS_AGREE_HACK_USER_ACK );
EVENT_HANDLER_NOPARAM( EGS_REPORT_HACK_USER_NOT );

// nProtect 해킹
EVENT_HANDLER_NOPARAM( EGS_NPROTECT_HACKING_USER_NOT );

//{{ 2009. 8. 18  최육사	hack shield	
EVENT_HANDLER( EGS_HACKSHIELD_CHECK_ACK );
//}}

//{{ 2009. 12. 29  최육사	NPCKILLALL해킹방지
EVENT_HANDLER_NOPARAM( EGS_DUNGEON_KILLALLNPC_CHECK_REQ );
_EVENT_HANDLER( ERM_DUNGEON_KILLALLNPC_CHECK_ACK, KEGS_DUNGEON_KILLALLNPC_CHECK_ACK );

EVENT_HANDLER_NOPARAM( EGS_REQUEST_HACKSHIELD_CHECK_NOT );
//}}

//{{ 2010. 05. 20  최육사	스크립트 파싱
#ifdef SERV_CLIENT_SCRIPT
EVENT_HANDLER( EGS_GET_CLIENT_SCRIPT_REQ );
#endif SERV_CLIENT_SCRIPT
//}}

//{{ 2012. 06. 04	김민성       서버 해킹 유저 체크 요청 응답으로 변경
#ifdef SERV_SERVER_CHECK_HACK_USER_REQ_ACK
//{{ 2010. 06. 17  최육사	오토핵 방지
#ifdef SERV_PROTECT_AUTO_HACK
_EVENT_HANDLER( ERM_SERVER_CHECK_HACK_USER_NOT, KEGS_SERVER_CHECK_HACK_USER_REQ );
#endif SERV_PROTECT_AUTO_HACK
//}}
#else
//{{ 2010. 06. 17  최육사	오토핵 방지
#ifdef SERV_PROTECT_AUTO_HACK
_EVENT_HANDLER( ERM_SERVER_CHECK_HACK_USER_NOT, KEGS_SERVER_CHECK_HACK_USER_NOT );
#endif SERV_PROTECT_AUTO_HACK
//}}
#endif SERV_SERVER_CHECK_HACK_USER_REQ_ACK
//}}

//{{ 2010. 10. 13	최육사	DLL Manager
#ifdef SERV_DLL_MANAGER
EVENT_HANDLER( EGS_MODULE_INFO_UPDATE_NOT );
#endif SERV_DLL_MANAGER
//}}

//{{ 2011. 03. 02	최육사	개인 거래 차단
#ifdef SERV_HACK_USER_TRADE_BLOCK
EVENT_HANDLER( ELG_TRADE_BLOCK_NOT );
#endif SERV_HACK_USER_TRADE_BLOCK
//}}

//{{ 2011. 05. 02  김민성	2차 보안 시스템
#ifdef SERV_SECOND_SECURITY
EVENT_HANDLER( DBE_GET_SECOND_SECURITY_INFO_ACK );
EVENT_HANDLER( EGS_AUTH_SECOND_SECURITY_REQ );
EVENT_HANDLER( DBE_SEUCCESS_SECOND_SECURITY_ACK );
_EVENT_HANDLER( DBE_FAILED_SECOND_SECURITY_ACK, int );
EVENT_HANDLER( EGS_CREATE_SECOND_SECURITY_REQ );
EVENT_HANDLER( DBE_CREATE_SECOND_SECURITY_ACK );
EVENT_HANDLER( EGS_DELETE_SECOND_SECURITY_REQ );
EVENT_HANDLER( EGS_DELETE_SECOND_SECURITY_VERIFY_REQ );
EVENT_HANDLER( DBE_DELETE_SECOND_SECURITY_ACK);
EVENT_HANDLER( EGS_CHANGE_SECOND_SECURITY_PW_REQ );
EVENT_HANDLER( DBE_CHANGE_SECOND_SECURITY_PW_ACK );
EVENT_HANDLER( EGS_COMPARE_SECOND_SECURITY_PW_REQ );
EVENT_HANDLER( EGS_CHECK_SECOND_SECURITY_PW_CHRACTER_LIST_REQ );
#endif SERV_SECOND_SECURITY
//}}

//{{ 2011. 08. 09	최육사	머신ID 블럭기능
#ifdef SERV_MACHINE_ID_BLOCK
EVENT_HANDLER( EGS_CHECK_MACHINE_ID_REQ );
_EVENT_HANDLER( ELG_CHECK_MACHINE_ID_ACK, KEGS_CHECK_MACHINE_ID_ACK );
#endif SERV_MACHINE_ID_BLOCK
//}}

//{{ 2012. 01. 27  김민성	해킹 프로세스 검사 기능
#ifdef SERV_HACKING_DLL_CHECK
EVENT_HANDLER( ELG_CHECK_MODULE_INFO_UPDATE_NOT );
#endif SERV_HACKING_DLL_CHECK
//}}

//{{ 2012. 06. 04	김민성       서버 해킹 유저 체크 요청 응답으로 변경
#ifdef SERV_SERVER_CHECK_HACK_USER_REQ_ACK
EVENT_HANDLER( EGS_SERVER_CHECK_HACK_USER_ACK );
#endif SERV_SERVER_CHECK_HACK_USER_REQ_ACK
//}}

#ifdef SERV_NPROTECT_CS_AUTH_30
EVENT_HANDLER( EGS_NPROTECT_CSAUTH3_RESPONE_NOT );
EVENT_HANDLER( EGS_NPROTECT_CSAUTH3_GAMEHACK_REPORT_NOT );
#endif SERV_NPROTECT_CS_AUTH_30

#ifdef SERV_USE_XTRAP
EVENT_HANDLER( EGS_XTRAP_ACK );
#endif SERV_USE_XTRAP

#ifdef SERV_FIX_NONE_NPC_DUNGEON_LINES// 작업날짜: 2013-05-22	// 박세훈
EVENT_HANDLER_NOPARAM( ERM_DUNGEON_KILLALLNPC_CHECK_NOT );
#endif // SERV_FIX_NONE_NPC_DUNGEON_LINES

#ifdef SERV_HACKING_USER_CHECK_COUNT// 작업날짜: 2013-06-02	// 박세훈
EVENT_HANDLER( DBE_HACKING_USER_CHECK_COUNT_INFO_ACK );
#endif // SERV_HACKING_USER_CHECK_COUNT

#ifdef SERV_HACKING_USER_PROCESS_NAME_RECORD// 작업날짜: 2013-06-03	// 박세훈
EVENT_HANDLER( EGS_HACKING_USER_PROCESS_NAME_RECORD_NOT );
#endif // SERV_HACKING_USER_PROCESS_NAME_RECORD

#ifdef SERV_ENTRY_POINT
EVENT_HANDLER_NOPARAM( EGS_GET_SECOND_SECURITY_INFO_REQ );
EVENT_HANDLER( DBE_GET_PURE_SECOND_SECURITY_INFO_ACK );
#endif SERV_ENTRY_POINT