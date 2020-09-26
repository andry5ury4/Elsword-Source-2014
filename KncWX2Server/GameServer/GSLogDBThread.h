#pragma once

#include "SubThread.h"
#include "odbc/Odbc.h"
//{{ 2009. 8. 17  최육사	sp profiler
#include "odbc/DBUtil.h"
//}}
#include "KncSend.h"

#include "Event.h"
#include "CommonPacket.h"
#include "SystemPacket.h"
#include "ClientPacket.h"
#include "ServerPacket.h"

class KGSLogDBThread : public KSubThread
{
    DeclareDBThread( KGSLogDBThread );
	//{{ 2009. 8. 17  최육사	sp profiler
	DeclareSPProfiler;
	//}}
    DeclPfID;

public:
    KGSLogDBThread();
    virtual ~KGSLogDBThread(void);

protected:
    // derived from KSubThread
    virtual inline void ProcessEvent( const KEventPtr& spEvent );

protected:
    // packet send function
    template < class T > void SendToServer( unsigned short usEventID, const T& data );
    template < class T > void SendToUser( UidType nTo, unsigned short usEventID, const T& data );
    void SendToServer( unsigned short usEventID );
    void SendToUser( UidType nTo, unsigned short usEventID );

	//{{ 2007. 10. 16  최육사  유저 통계
	void UserStatisticsTableParsing( std::map< std::pair< int, int >, std::vector< int > >& mapStatistics, 
		int iTableID, int iSubTableID, int iMaxColumn, int* arrayData );	
	//}}

    void WriteServerInfoToDB( IN KDBE_UPDATE_SERVER_INFO_REQ& kPacket_, OUT KServerList& kPacket );

	// event handler
	_DECL_ON_FUNC( DBE_SERVER_ON_REQ, KNetAddress );
    DECL_ON_FUNC( DBE_UPDATE_SERVER_INFO_REQ );
	DECL_ON_FUNC_NOPARAM( DBE_ADMIN_SERVER_STATUS_REQ );
	DECL_ON_FUNC_NOPARAM( DBE_SERVER_OFF_NOT );	
	//{{ 2009. 2. 13  최육사	채널 리스트
	DECL_ON_FUNC( DBE_CHANNEL_LIST_REQ );
	//}}
	DECL_ON_FUNC( DBE_CHARACTER_LEVELUP_NOT );
	DECL_ON_FUNC( ELOG_STAT_PLAY_TIME );
   _DECL_ON_FUNC( ELOG_STAT_PVP_MAP, KStatisticsData );
   _DECL_ON_FUNC( ELOG_STAT_FPS, KStatisticsData );
   _DECL_ON_FUNC( ELOG_STAT_ED, KStatisticsData );
   _DECL_ON_FUNC( ELOG_STAT_QUEST, KStatisticsData );
   //{{ 2011. 02. 28	최육사	사내 통합 통계
#ifdef SERV_CHAR_CREATE_DEL_STAT
   _DECL_ON_FUNC( ELOG_STAT_CHARACTER, KStatisticsData );
#endif SERV_CHAR_CREATE_DEL_STAT
   //}}
	DECL_ON_FUNC( ELOG_USER_STATISTICS );
	DECL_ON_FUNC( ELOG_CHEAT_LOG_NOT );
   _DECL_ON_FUNC( ELOG_STAT_DISCONNECT_USERFSM, KStatisticsData );
   _DECL_ON_FUNC( ELOG_STAT_DISCONNECT_REASON, KStatisticsData );
   _DECL_ON_FUNC( DBE_DELETE_UNIT_STAT_NOT, KEGS_DELETE_UNIT_REQ );
    DECL_ON_FUNC( DBE_UPDATE_UNIT_CLASS_NOT );	
	DECL_ON_FUNC( ELOG_RESURRECTION_STONE_LOG_NOT );
	DECL_ON_FUNC( ELOG_RESOLVE_JACKPOT_LOG_NOT );
    DECL_ON_FUNC( ELOG_GET_PURCHASED_CASH_ITEM_NOT );
#ifdef SERV_ADD_EVENT_DB
#else //SERV_ADD_EVENT_DB
	DECL_ON_FUNC_NOPARAM( DBE_EVENT_UPDATE_REQ );
#endif //SERV_ADD_EVENT_DB

#ifdef SERV_REFRESH_EVENT_USING_RELEASE_TICK
#ifdef SERV_ADD_EVENT_DB
#else //SERV_ADD_EVENT_DB
	DECL_ON_FUNC_NOPARAM( DBE_CHECK_EVENT_UPDATE_REQ );
#endif //SERV_ADD_EVENT_DB
#endif SERV_REFRESH_EVENT_USING_RELEASE_TICK

	//{{ 2012. 02. 03	박세훈	이벤트 관련정보 처리방법 변경 ( Script -> DB )
#ifdef SERV_CHANGE_EVENT_INFO_SCRIPT_TO_DB
	DECL_ON_FUNC_NOPARAM( DBE_RELEASE_TICK_UPDATE_REQ );
	DECL_ON_FUNC_NOPARAM( DBE_EVENT_DATA_UPDATE_REQ );
	DECL_ON_FUNC_NOPARAM( DBE_EVENT_MONSTER_UPDATE_REQ );
	DECL_ON_FUNC_NOPARAM( DBE_EVENT_NOTIFY_MSG_SERVER_INFO_UPDATE_REQ );
	DECL_ON_FUNC_NOPARAM( DBE_EVENT_REWARD_DATA_UPDATE_REQ );
	//{{ 2011. 08. 29	최육사	캐릭터 레벨업 이벤트
#ifdef SERV_CHAR_LEVEL_UP_EVENT
	DECL_ON_FUNC_NOPARAM( DBE_EVENT_REWARD_LEVEL_UP_UPDATE_REQ );
#endif SERV_CHAR_LEVEL_UP_EVENT
	//}}
	//{{ 2011. 06. 22    김민성    이탈 방지 모델 - NEXON 세션 시스템 수정
#ifdef SERV_NEXON_SESSION_PROTOCOL
	DECL_ON_FUNC_NOPARAM( DBE_EVENT_REWARD_RETAIN_USER_ITEM_UPDATE_REQ );
#endif SERV_NEXON_SESSION_PROTOCOL
	//}}
#endif SERV_CHANGE_EVENT_INFO_SCRIPT_TO_DB
	//}}
	DECL_ON_FUNC( ELOG_ITEM_ABUSER_LOG_NOT );
	DECL_ON_FUNC( ELOG_ENCHANT_ABUSER_LOG_NOT );
	DECL_ON_FUNC( ELOG_ED_ABUSER_LOG_NOT );	
	DECL_ON_FUNC( ELOG_CASH_ITEM_RESOLVE_LOG_NOT );			// 캐쉬 분해 로그
	DECL_ON_FUNC( ELOG_ENCHANT_ITEM_BREAK_LOG_NOT );		// 강화 깨짐 로그
	DECL_ON_FUNC( DBE_ABUSER_LIST_REQ );					// 어뷰저 리스트
	DECL_ON_FUNC( DBE_REG_ABUSER_AUTOMATIC_NOT );	
	DECL_ON_FUNC( ELOG_ENCHANT_SUPPORT_MATERIAL_LOG_NOT );	// 보조제 로그
	DECL_ON_FUNC( ELOG_RESTORE_ITEM_LOG_NOT );				// 깨짐 복구 로그
	DECL_ON_FUNC( ELOG_ATTACH_ITEM_ENCHANT_LOG_NOT );		// 부여 로그
	DECL_ON_FUNC( ELOG_CHARM_ITEM_LOG_NOT );				// 매력아이템 로그
	//{{ 2009. 4. 14  최육사	닉네임 변경
	DECL_ON_FUNC( ELOG_DELETE_NICK_NAME_NOT );
	DECL_ON_FUNC( ELOG_CHANGE_NICK_NAME_NOT );
	//}}

	DECL_ON_FUNC( ELOG_INIT_SKILL_TREE_NOT );
	DECL_ON_FUNC( ELOG_INSERT_CASH_SKILL_POINT_NOT );
	
	//{{ 2009. 7. 22  최육사	메가폰로그
	DECL_ON_FUNC( ELOG_MEGAPHONE_LOG_NOT );
	//}}

	//{{ 2009. 9. 1  최육사		비정상종료사유
	DECL_ON_FUNC( ELOG_ABNORMAL_DISCONNECT );
	//}}
	//{{ 2009. 9. 9  최육사		밀봉
	DECL_ON_FUNC( ELOG_USE_SEAL_ITEM_NOT );
	//}}
	//{{ 2009. 10. 22  최육사	트래픽 유발 유저 해킹유저로 자동등록
	DECL_ON_FUNC( ELOG_TRAFFIC_ATTACKER_LOG_NOT );
	//}}
	//{{ 2010. 02. 16  최육사	해킹툴 리스트
#ifdef SERV_HACKING_TOOL_LIST
	DECL_ON_FUNC( DBE_CHECK_HACKING_TOOL_LIST_REQ );
#endif SERV_HACKING_TOOL_LIST
	//}}
	//{{ 2010. 06. 30  최육사	근성도 통계
#ifdef SERV_SPIRIT_STATISTICS
	DECL_ON_FUNC( DBE_SPIRIT_STATISTICS_NOT );
#endif SERV_SPIRIT_STATISTICS
	//}}

#ifdef SERV_KOG_STATISTICS
	DECL_ON_FUNC_NOPARAM(DBE_CCU_AGENT_REQ);
#endif SERV_KOG_STATISTICS

	//{{ 2010. 9. 8	최육사	네트워크 트래픽 유발 유저 모니터링
#ifdef SERV_TRAFFIC_USER_MONITORING
	DECL_ON_FUNC( ELOG_INSERT_TRAFFIC_ABUSER_LOG_NOT );
#endif SERV_TRAFFIC_USER_MONITORING
	//}}

	//{{ 2011. 01. 05	최육사	속성 부적
#ifdef SERV_ATTRIBUTE_CHARM
	DECL_ON_FUNC( ELOG_ATTRIB_ATTACH_ITEM_LOG_NOT );
#endif SERV_ATTRIBUTE_CHARM
	//}}
	//{{ 2011. 01. 17	최육사	캐릭터 카운트 정보
#ifdef SERV_CHAR_LOG
	DECL_ON_FUNC( ELOG_USER_CHARACTER_LOG_NOT );
#endif SERV_CHAR_LOG
	//}}
	//{{ 2011. 02. 09	최육사	캐쉬템 구매 로그
#ifdef SERV_BUY_CASH_ITEM_LOG
	DECL_ON_FUNC( ELOG_BUY_CASH_ITEM_LOG_NOT );
#endif SERV_BUY_CASH_ITEM_LOG
	//}}
	//{{ 2011. 02. 23	최육사	캐쉬 상품 리스트
#ifdef SERV_CASH_ITEM_LIST
	DECL_ON_FUNC( ELOG_CASH_PRODUCT_LIST_UPDATE_NOT );
#endif SERV_CASH_ITEM_LIST
	//}}
	//{{ 2011. 04. 05  김민성	우편 및 거래 감시
#ifdef SERV_MONITORING_LETTER_AND_TRADE
	DECL_ON_FUNC( DBE_WRITE_LETTER_AND_TRADE_MOINTORING_REQ );
#endif SERV_MONITORING_LETTER_AND_TRADE
	//}}
	//{{ 2011. 04. 13	최육사	아이템 통계 DB기록
#ifdef SERV_ITEM_STATISTICS_TO_DB
   _DECL_ON_FUNC( ELOG_STAT_ITEM_DB, KStatisticsData );
#endif SERV_ITEM_STATISTICS_TO_DB
	//}}

#ifdef SERV_ACTIVE_KOG_GAME_PERFORMANCE_CHECK
   _DECL_ON_FUNC( ELOG_STAT_SYSTEM_INFO, KEGS_SYSTEM_INFO );
   _DECL_ON_FUNC( ELOG_STAT_KOG_GAME_PERFORMANCE_VILLAGE, KEGS_KOG_GAME_PERFORMANCE_VILLAGE_LOG );
   _DECL_ON_FUNC( ELOG_STAT_KOG_GAME_PERFORMANCE_FIELD, KEGS_KOG_GAME_PERFORMANCE_FIELD_LOG );
   _DECL_ON_FUNC( ELOG_STAT_KOG_GAME_PERFORMANCE_DUNGEON, KEGS_KOG_GAME_PERFORMANCE_DUNGEON_LOG );
   _DECL_ON_FUNC( ELOG_STAT_KOG_GAME_PERFORMANCE_PVP, KEGS_KOG_GAME_PERFORMANCE_PVP_LOG );
#endif//SERV_ACTIVE_KOG_GAME_PERFORMANCE_CHECK

   //{{ 2011. 05. 02  김민성	2차 보안 시스템
#ifdef SERV_SECOND_SECURITY
   DECL_ON_FUNC( DBE_FIRST_WRITE_SECURITY_TYPE_NOT );
#endif SERV_SECOND_SECURITY
   //}}
#ifdef	SERV_SHARING_BANK_TEST
	_DECL_ON_FUNC( ELOG_UPDATE_SHARE_ITEM_NOT, std::vector< KTradeShareItemInfo > );
	DECL_ON_FUNC( ELOG_ITEM_TRADE_ERROR_NOT );
#endif	SERV_SHARING_BANK_TEST
#ifdef SERV_GOLD_TICKET
	DECL_ON_FUNC( ELOG_CHARGE_POINT_NOT );
#endif //SERV_GOLD_TICKET

   //{{ 2011. 05. 27    김민성    휴면 복귀 유저 보상
#ifdef SERV_COME_BACK_USER_REWARD
   DECL_ON_FUNC( DBE_FIRST_WRITE_COME_BACK_INFO_NOT );
#endif SERV_COME_BACK_USER_REWARD
   //}} 
   //{{ 2011. 06. 22    김민성    이탈 방지 모델 - NEXON 세션 시스템 수정
#ifdef SERV_NEXON_SESSION_PROTOCOL
	DECL_ON_FUNC( DBE_INSERT_LOG_RETAINING_USER_NOT );
#endif SERV_NEXON_SESSION_PROTOCOL
	//}}
	//{{  2011.11.08     김민성    강화 로그
#ifdef SERV_ENCHANT_ITEM_LOG
	DECL_ON_FUNC( ELOG_HIGH_ENCHANT_ITEM_LOG_NOT );
#endif SERV_ENCHANT_ITEM_LOG
	//}}
	//{{  2011.11.24     김민성    캐릭터 접속 로그
#ifdef SERV_CHAR_CONNECT_LOG
	DECL_ON_FUNC( DBE_UNIT_CONNECT_LOG_NOT );
#endif SERV_CHAR_CONNECT_LOG
	//}}
	//{{ 2011. 12. 02  김민성	AP 구매 로그 수치
#ifdef SERV_BUY_AP_ITEM_LOG
	DECL_ON_FUNC( DBE_BUY_AP_ITEM_LOG_NOT );
#endif SERV_BUY_AP_ITEM_LOG
	//}}
	//{{ 2011. 12. 14	최육사	패킷 처리 지연 시간 체크
#ifdef SERV_PACKET_PROCESSING_LATENCY_CHECK
	DECL_ON_FUNC( DBE_UPDATE_PAKCET_MORNITORING_LOG_NOT );
#endif SERV_PACKET_PROCESSING_LATENCY_CHECK
	//}}
	//{{ 2012. 01. 27  김민성	해킹 프로세스 검사 기능
#ifdef SERV_HACKING_DLL_CHECK
	DECL_ON_FUNC( DBE_CHECK_MODULE_INFO_LOG_NOT );
#endif SERV_HACKING_DLL_CHECK
	//}}
	//{{ 2012. 03. 29	김민성		x2.exe 모듈 유무 검사
#ifdef SERV_CHECK_X2_EXE_MODULE
	DECL_ON_FUNC( DBE_MODULE_EXIST_LOG_NOT );
#endif SERV_CHECK_X2_EXE_MODULE
	//}}
	//{{ 2012. 04. 24	최육사	UDP릴레이 퍼포먼스 체크
#ifdef SERV_UDP_RELAY_CHECKER
	DECL_ON_FUNC_NOPARAM( DBE_GET_CENTER_SERVER_LIST_REQ );
	DECL_ON_FUNC( DBE_UPDATE_UDP_RELAY_CHECK_STATISTICS_NOT );
#endif SERV_UDP_RELAY_CHECKER
	//}}
	//{{ 2012. 10. 16	최육사		ED&아이템 모니터링 시스템
#ifdef SERV_ED_AND_ITEM_MORNITORING_SYSTEM
	DECL_ON_FUNC_NOPARAM( DBE_GET_ED_AND_ITEM_MORNITOING_INFO_REQ );
#endif SERV_ED_AND_ITEM_MORNITORING_SYSTEM
	//}}
	//{{ 2013. 01. 09 던전 강퇴 시스템 - 김민성
#ifdef SERV_DUNGEON_FORCED_EXIT_SYSTEM
	_DECL_ON_FUNC( DBE_BAD_ATTITUDE_USER_LOG_NOT, KERM_BAD_ATTITUDE_USER_LOG_NOT );
#endif SERV_DUNGEON_FORCED_EXIT_SYSTEM
	//}
	//{{ 2013. 02. 13	최육사	Tick퍼포먼스 DB로그 기록
#ifdef SERV_SIMLAYER_TICK_PERFORMANCE_DB_LOG
	DECL_ON_FUNC( DBE_TICK_PERFORMANCE_LOG_NOT );
#endif SERV_SIMLAYER_TICK_PERFORMANCE_DB_LOG
	//}}

	//{{ 2013. 02. 19   교환 로그 추가 - 김민성
#ifdef SERV_EXCHANGE_LOG
	DECL_ON_FUNC( DBE_ITEM_EXCHANGE_LOG_NOT );
#endif SERV_EXCHANGE_LOG
	//}
	//{{ 허상형 : [2010/8/31/] //	부활석 통계 분리 작업	// 임규수 일본 추가
#ifdef SERV_SELECT_UNIT_NEW
	DECL_ON_FUNC( ELOG_UPDATE_STONE_NOT );
#endif	//	SERV_SELECT_UNIT_NEW
	//}} 허상형 : [2010/8/31/] //	부활석 통계 분리 작업
	//{{ 2011.05.04   임규수 아바타 합성 시스템
#ifdef SERV_SYNTHESIS_AVATAR
	DECL_ON_FUNC( DBE_SYNTHESIS_LOG_NOT );
#endif SERV_SYNTHESIS_AVATAR
	//}}
#ifdef SERV_CATCH_HACKUSER_INFO
	_DECL_ON_FUNC( DBE_CATCH_HACKUSER_INTO_NOT, KEGS_CATCH_HACKUSER_INFO_NOT );
#endif SERV_CATCH_HACKUSER_INFO

#ifdef SERV_SKILL_POINT_CORRECTION
	DECL_ON_FUNC( DBE_SKILL_POINT_CORRECTION_INFO_NOT );
#endif //SERV_SKILL_POINT_CORRECTION

#ifdef SERV_CLIENT_PORT_CHANGE_REQUEST_LOG
	DECL_ON_FUNC( DBE_CLIENT_POPRT_CHANGE_REQUEST_INFO_NOT );
#endif //SERV_CLIENT_PORT_CHANGE_REQUEST_LOG

	//{{ 2013. 02. 21	최육사	로그 시스템 개선
#ifdef SERV_LOG_SYSTEM_NEW
	DECL_ON_FUNC( DBE_LOG_STATISTICS_INFO_NOT );
#endif SERV_LOG_SYSTEM_NEW
	//}}	
	//{{ 2013. 04. 01	 인연 시스템 - 김민성
#ifdef SERV_RELATIONSHIP_SYSTEM
	DECL_ON_FUNC( DBE_WRITE_RELATIONSHIP_INFO_LOG_REQ );
#endif SERV_RELATIONSHIP_SYSTEM
	//}

#ifdef SERV_LOCAL_RANKING_SYSTEM_STATISTICS_LOG// 작업날짜: 2013-05-15	// 박세훈
	DECL_ON_FUNC( DBE_LOCAL_RANKING_SYSTEM_STATISTICS_LOG_NOT );
#endif // SERV_LOCAL_RANKING_SYSTEM_STATISTICS_LOG

#ifdef SERV_FIELD_WORKINGS_BLOCK_LOG// 작업날짜: 2013-05-15	// 박세훈
	DECL_ON_FUNC( DBE_FIELD_WORKINGS_BLOCK_LOG_NOT );
#endif // SERV_FIELD_WORKINGS_BLOCK_LOG

#ifdef SERV_ITEM_ACTION_BY_DBTIME_SETTING // 2012.12.11 lygan_조성욱 // 석근이 작업 리뉴얼 ( DB에서 실시간 값 반영, 교환, 제조 쪽도 적용 )
	DECL_ON_FUNC( DBE_GET_ITEM_ONOFF_NPCSHOP_REQ );
#endif //SERV_ITEM_ACTION_BY_DBTIME_SETTING

#ifdef SERV_CUBE_IN_ITEM_MAPPING_BY_DBTIME_SETTING
	DECL_ON_FUNC( DBE_GET_CUBE_IN_ITEM_MAPPING_ONOFF_REQ );
#endif SERV_CUBE_IN_ITEM_MAPPING_BY_DBTIME_SETTING

#ifdef SERV_KOM_FILE_CHECK_ADVANCED
	DECL_ON_FUNC( ELOG_KOM_FILE_CHECK_LOG_NOT );
#endif SERV_KOM_FILE_CHECK_ADVANCED

#ifdef SERV_GOOD_ELSWORD
    DECL_ON_FUNC( ELOG_EXPAND_BANK_INVENTORY_NOT );
#endif // SERV_GOOD_ELSWORD

#ifdef SERV_SKILL_PAGE_SYSTEM
	DECL_ON_FUNC( ELOG_EXPAND_SKILL_PAGE_NOT );
#endif // SERV_SKILL_PAGE_SYSTEM

#ifdef SERV_HALLOWEEN_PUMPKIN_FAIRY_PET
	DECL_ON_FUNC( DBE_CHANGE_PET_ID_LOG_NOT );
#endif //SERV_HALLOWEEN_PUMPKIN_FAIRY_PET

#ifdef SERV_PAYLETTER_BILLING_ERROR_PACKET_LOG
	_DECL_ON_FUNC( DBE_PAYLETTER_BILLING_ERROR_BUY_PACKET_NOT, KEBILL_BUY_PRODUCT_REQ );
	_DECL_ON_FUNC( DBE_PAYLETTER_BILLING_ERROR_GIFT_PACKET_NOT, KEBILL_GIFT_ITEM_REQ );
	_DECL_ON_FUNC( DBE_PAYLETTER_BILLING_ERROR_COUPON_PACKET_NOT, KEBILL_USE_COUPON_REQ );
#endif //SERV_PAYLETTER_BILLING_ERROR_PACKET_LOG

#ifdef SERV_UNLIMITED_SECOND_CHANGE_JOB
	DECL_ON_FUNC( DBE_UNLIMITED_SECOND_CHANGE_JOB_NOT );
#endif	//	SERV_UNLIMITED_SECOND_CHANGE_JOB

};

template < class T >
void KGSLogDBThread::SendToServer( unsigned short usEventID, const T& data )
{
    KncSend( GetPfID(), 0, PI_GS_SERVER, KBaseServer::GetKObj()->GetUID(), NULL, usEventID, data );
}

template < class T >
void KGSLogDBThread::SendToUser( UidType nTo, unsigned short usEventID, const T& data )
{
    KncSend( GetPfID(), 0, PI_GS_USER, nTo, NULL, usEventID, data );
}
