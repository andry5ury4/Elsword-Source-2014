#pragma once

#include "SubThread.h"
#include "odbc/Odbc.h"
//{{ 2009. 8. 17  ������	sp profiler
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
	//{{ 2009. 8. 17  ������	sp profiler
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

	//{{ 2007. 10. 16  ������  ���� ���
	void UserStatisticsTableParsing( std::map< std::pair< int, int >, std::vector< int > >& mapStatistics, 
		int iTableID, int iSubTableID, int iMaxColumn, int* arrayData );	
	//}}

    void WriteServerInfoToDB( IN KDBE_UPDATE_SERVER_INFO_REQ& kPacket_, OUT KServerList& kPacket );

	// event handler
	_DECL_ON_FUNC( DBE_SERVER_ON_REQ, KNetAddress );
    DECL_ON_FUNC( DBE_UPDATE_SERVER_INFO_REQ );
	DECL_ON_FUNC_NOPARAM( DBE_ADMIN_SERVER_STATUS_REQ );
	DECL_ON_FUNC_NOPARAM( DBE_SERVER_OFF_NOT );	
	//{{ 2009. 2. 13  ������	ä�� ����Ʈ
	DECL_ON_FUNC( DBE_CHANNEL_LIST_REQ );
	//}}
	DECL_ON_FUNC( DBE_CHARACTER_LEVELUP_NOT );
	DECL_ON_FUNC( ELOG_STAT_PLAY_TIME );
   _DECL_ON_FUNC( ELOG_STAT_PVP_MAP, KStatisticsData );
   _DECL_ON_FUNC( ELOG_STAT_FPS, KStatisticsData );
   _DECL_ON_FUNC( ELOG_STAT_ED, KStatisticsData );
   _DECL_ON_FUNC( ELOG_STAT_QUEST, KStatisticsData );
   //{{ 2011. 02. 28	������	�系 ���� ���
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

	//{{ 2012. 02. 03	�ڼ���	�̺�Ʈ �������� ó����� ���� ( Script -> DB )
#ifdef SERV_CHANGE_EVENT_INFO_SCRIPT_TO_DB
	DECL_ON_FUNC_NOPARAM( DBE_RELEASE_TICK_UPDATE_REQ );
	DECL_ON_FUNC_NOPARAM( DBE_EVENT_DATA_UPDATE_REQ );
	DECL_ON_FUNC_NOPARAM( DBE_EVENT_MONSTER_UPDATE_REQ );
	DECL_ON_FUNC_NOPARAM( DBE_EVENT_NOTIFY_MSG_SERVER_INFO_UPDATE_REQ );
	DECL_ON_FUNC_NOPARAM( DBE_EVENT_REWARD_DATA_UPDATE_REQ );
	//{{ 2011. 08. 29	������	ĳ���� ������ �̺�Ʈ
#ifdef SERV_CHAR_LEVEL_UP_EVENT
	DECL_ON_FUNC_NOPARAM( DBE_EVENT_REWARD_LEVEL_UP_UPDATE_REQ );
#endif SERV_CHAR_LEVEL_UP_EVENT
	//}}
	//{{ 2011. 06. 22    ��μ�    ��Ż ���� �� - NEXON ���� �ý��� ����
#ifdef SERV_NEXON_SESSION_PROTOCOL
	DECL_ON_FUNC_NOPARAM( DBE_EVENT_REWARD_RETAIN_USER_ITEM_UPDATE_REQ );
#endif SERV_NEXON_SESSION_PROTOCOL
	//}}
#endif SERV_CHANGE_EVENT_INFO_SCRIPT_TO_DB
	//}}
	DECL_ON_FUNC( ELOG_ITEM_ABUSER_LOG_NOT );
	DECL_ON_FUNC( ELOG_ENCHANT_ABUSER_LOG_NOT );
	DECL_ON_FUNC( ELOG_ED_ABUSER_LOG_NOT );	
	DECL_ON_FUNC( ELOG_CASH_ITEM_RESOLVE_LOG_NOT );			// ĳ�� ���� �α�
	DECL_ON_FUNC( ELOG_ENCHANT_ITEM_BREAK_LOG_NOT );		// ��ȭ ���� �α�
	DECL_ON_FUNC( DBE_ABUSER_LIST_REQ );					// ����� ����Ʈ
	DECL_ON_FUNC( DBE_REG_ABUSER_AUTOMATIC_NOT );	
	DECL_ON_FUNC( ELOG_ENCHANT_SUPPORT_MATERIAL_LOG_NOT );	// ������ �α�
	DECL_ON_FUNC( ELOG_RESTORE_ITEM_LOG_NOT );				// ���� ���� �α�
	DECL_ON_FUNC( ELOG_ATTACH_ITEM_ENCHANT_LOG_NOT );		// �ο� �α�
	DECL_ON_FUNC( ELOG_CHARM_ITEM_LOG_NOT );				// �ŷ¾����� �α�
	//{{ 2009. 4. 14  ������	�г��� ����
	DECL_ON_FUNC( ELOG_DELETE_NICK_NAME_NOT );
	DECL_ON_FUNC( ELOG_CHANGE_NICK_NAME_NOT );
	//}}

	DECL_ON_FUNC( ELOG_INIT_SKILL_TREE_NOT );
	DECL_ON_FUNC( ELOG_INSERT_CASH_SKILL_POINT_NOT );
	
	//{{ 2009. 7. 22  ������	�ް����α�
	DECL_ON_FUNC( ELOG_MEGAPHONE_LOG_NOT );
	//}}

	//{{ 2009. 9. 1  ������		�������������
	DECL_ON_FUNC( ELOG_ABNORMAL_DISCONNECT );
	//}}
	//{{ 2009. 9. 9  ������		�к�
	DECL_ON_FUNC( ELOG_USE_SEAL_ITEM_NOT );
	//}}
	//{{ 2009. 10. 22  ������	Ʈ���� ���� ���� ��ŷ������ �ڵ����
	DECL_ON_FUNC( ELOG_TRAFFIC_ATTACKER_LOG_NOT );
	//}}
	//{{ 2010. 02. 16  ������	��ŷ�� ����Ʈ
#ifdef SERV_HACKING_TOOL_LIST
	DECL_ON_FUNC( DBE_CHECK_HACKING_TOOL_LIST_REQ );
#endif SERV_HACKING_TOOL_LIST
	//}}
	//{{ 2010. 06. 30  ������	�ټ��� ���
#ifdef SERV_SPIRIT_STATISTICS
	DECL_ON_FUNC( DBE_SPIRIT_STATISTICS_NOT );
#endif SERV_SPIRIT_STATISTICS
	//}}

#ifdef SERV_KOG_STATISTICS
	DECL_ON_FUNC_NOPARAM(DBE_CCU_AGENT_REQ);
#endif SERV_KOG_STATISTICS

	//{{ 2010. 9. 8	������	��Ʈ��ũ Ʈ���� ���� ���� ����͸�
#ifdef SERV_TRAFFIC_USER_MONITORING
	DECL_ON_FUNC( ELOG_INSERT_TRAFFIC_ABUSER_LOG_NOT );
#endif SERV_TRAFFIC_USER_MONITORING
	//}}

	//{{ 2011. 01. 05	������	�Ӽ� ����
#ifdef SERV_ATTRIBUTE_CHARM
	DECL_ON_FUNC( ELOG_ATTRIB_ATTACH_ITEM_LOG_NOT );
#endif SERV_ATTRIBUTE_CHARM
	//}}
	//{{ 2011. 01. 17	������	ĳ���� ī��Ʈ ����
#ifdef SERV_CHAR_LOG
	DECL_ON_FUNC( ELOG_USER_CHARACTER_LOG_NOT );
#endif SERV_CHAR_LOG
	//}}
	//{{ 2011. 02. 09	������	ĳ���� ���� �α�
#ifdef SERV_BUY_CASH_ITEM_LOG
	DECL_ON_FUNC( ELOG_BUY_CASH_ITEM_LOG_NOT );
#endif SERV_BUY_CASH_ITEM_LOG
	//}}
	//{{ 2011. 02. 23	������	ĳ�� ��ǰ ����Ʈ
#ifdef SERV_CASH_ITEM_LIST
	DECL_ON_FUNC( ELOG_CASH_PRODUCT_LIST_UPDATE_NOT );
#endif SERV_CASH_ITEM_LIST
	//}}
	//{{ 2011. 04. 05  ��μ�	���� �� �ŷ� ����
#ifdef SERV_MONITORING_LETTER_AND_TRADE
	DECL_ON_FUNC( DBE_WRITE_LETTER_AND_TRADE_MOINTORING_REQ );
#endif SERV_MONITORING_LETTER_AND_TRADE
	//}}
	//{{ 2011. 04. 13	������	������ ��� DB���
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

   //{{ 2011. 05. 02  ��μ�	2�� ���� �ý���
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

   //{{ 2011. 05. 27    ��μ�    �޸� ���� ���� ����
#ifdef SERV_COME_BACK_USER_REWARD
   DECL_ON_FUNC( DBE_FIRST_WRITE_COME_BACK_INFO_NOT );
#endif SERV_COME_BACK_USER_REWARD
   //}} 
   //{{ 2011. 06. 22    ��μ�    ��Ż ���� �� - NEXON ���� �ý��� ����
#ifdef SERV_NEXON_SESSION_PROTOCOL
	DECL_ON_FUNC( DBE_INSERT_LOG_RETAINING_USER_NOT );
#endif SERV_NEXON_SESSION_PROTOCOL
	//}}
	//{{  2011.11.08     ��μ�    ��ȭ �α�
#ifdef SERV_ENCHANT_ITEM_LOG
	DECL_ON_FUNC( ELOG_HIGH_ENCHANT_ITEM_LOG_NOT );
#endif SERV_ENCHANT_ITEM_LOG
	//}}
	//{{  2011.11.24     ��μ�    ĳ���� ���� �α�
#ifdef SERV_CHAR_CONNECT_LOG
	DECL_ON_FUNC( DBE_UNIT_CONNECT_LOG_NOT );
#endif SERV_CHAR_CONNECT_LOG
	//}}
	//{{ 2011. 12. 02  ��μ�	AP ���� �α� ��ġ
#ifdef SERV_BUY_AP_ITEM_LOG
	DECL_ON_FUNC( DBE_BUY_AP_ITEM_LOG_NOT );
#endif SERV_BUY_AP_ITEM_LOG
	//}}
	//{{ 2011. 12. 14	������	��Ŷ ó�� ���� �ð� üũ
#ifdef SERV_PACKET_PROCESSING_LATENCY_CHECK
	DECL_ON_FUNC( DBE_UPDATE_PAKCET_MORNITORING_LOG_NOT );
#endif SERV_PACKET_PROCESSING_LATENCY_CHECK
	//}}
	//{{ 2012. 01. 27  ��μ�	��ŷ ���μ��� �˻� ���
#ifdef SERV_HACKING_DLL_CHECK
	DECL_ON_FUNC( DBE_CHECK_MODULE_INFO_LOG_NOT );
#endif SERV_HACKING_DLL_CHECK
	//}}
	//{{ 2012. 03. 29	��μ�		x2.exe ��� ���� �˻�
#ifdef SERV_CHECK_X2_EXE_MODULE
	DECL_ON_FUNC( DBE_MODULE_EXIST_LOG_NOT );
#endif SERV_CHECK_X2_EXE_MODULE
	//}}
	//{{ 2012. 04. 24	������	UDP������ �����ս� üũ
#ifdef SERV_UDP_RELAY_CHECKER
	DECL_ON_FUNC_NOPARAM( DBE_GET_CENTER_SERVER_LIST_REQ );
	DECL_ON_FUNC( DBE_UPDATE_UDP_RELAY_CHECK_STATISTICS_NOT );
#endif SERV_UDP_RELAY_CHECKER
	//}}
	//{{ 2012. 10. 16	������		ED&������ ����͸� �ý���
#ifdef SERV_ED_AND_ITEM_MORNITORING_SYSTEM
	DECL_ON_FUNC_NOPARAM( DBE_GET_ED_AND_ITEM_MORNITOING_INFO_REQ );
#endif SERV_ED_AND_ITEM_MORNITORING_SYSTEM
	//}}
	//{{ 2013. 01. 09 ���� ���� �ý��� - ��μ�
#ifdef SERV_DUNGEON_FORCED_EXIT_SYSTEM
	_DECL_ON_FUNC( DBE_BAD_ATTITUDE_USER_LOG_NOT, KERM_BAD_ATTITUDE_USER_LOG_NOT );
#endif SERV_DUNGEON_FORCED_EXIT_SYSTEM
	//}
	//{{ 2013. 02. 13	������	Tick�����ս� DB�α� ���
#ifdef SERV_SIMLAYER_TICK_PERFORMANCE_DB_LOG
	DECL_ON_FUNC( DBE_TICK_PERFORMANCE_LOG_NOT );
#endif SERV_SIMLAYER_TICK_PERFORMANCE_DB_LOG
	//}}

	//{{ 2013. 02. 19   ��ȯ �α� �߰� - ��μ�
#ifdef SERV_EXCHANGE_LOG
	DECL_ON_FUNC( DBE_ITEM_EXCHANGE_LOG_NOT );
#endif SERV_EXCHANGE_LOG
	//}
	//{{ ����� : [2010/8/31/] //	��Ȱ�� ��� �и� �۾�	// �ӱԼ� �Ϻ� �߰�
#ifdef SERV_SELECT_UNIT_NEW
	DECL_ON_FUNC( ELOG_UPDATE_STONE_NOT );
#endif	//	SERV_SELECT_UNIT_NEW
	//}} ����� : [2010/8/31/] //	��Ȱ�� ��� �и� �۾�
	//{{ 2011.05.04   �ӱԼ� �ƹ�Ÿ �ռ� �ý���
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

	//{{ 2013. 02. 21	������	�α� �ý��� ����
#ifdef SERV_LOG_SYSTEM_NEW
	DECL_ON_FUNC( DBE_LOG_STATISTICS_INFO_NOT );
#endif SERV_LOG_SYSTEM_NEW
	//}}	
	//{{ 2013. 04. 01	 �ο� �ý��� - ��μ�
#ifdef SERV_RELATIONSHIP_SYSTEM
	DECL_ON_FUNC( DBE_WRITE_RELATIONSHIP_INFO_LOG_REQ );
#endif SERV_RELATIONSHIP_SYSTEM
	//}

#ifdef SERV_LOCAL_RANKING_SYSTEM_STATISTICS_LOG// �۾���¥: 2013-05-15	// �ڼ���
	DECL_ON_FUNC( DBE_LOCAL_RANKING_SYSTEM_STATISTICS_LOG_NOT );
#endif // SERV_LOCAL_RANKING_SYSTEM_STATISTICS_LOG

#ifdef SERV_FIELD_WORKINGS_BLOCK_LOG// �۾���¥: 2013-05-15	// �ڼ���
	DECL_ON_FUNC( DBE_FIELD_WORKINGS_BLOCK_LOG_NOT );
#endif // SERV_FIELD_WORKINGS_BLOCK_LOG

#ifdef SERV_ITEM_ACTION_BY_DBTIME_SETTING // 2012.12.11 lygan_������ // ������ �۾� ������ ( DB���� �ǽð� �� �ݿ�, ��ȯ, ���� �ʵ� ���� )
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