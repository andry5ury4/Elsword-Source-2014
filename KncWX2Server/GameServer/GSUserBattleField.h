
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
// ���⼭ ���� �̺�Ʈ �ڵ鷯 ����!


EVENT_HANDLER( EGS_JOIN_BATTLE_FIELD_REQ );
EVENT_HANDLER( EPM_GET_PARTY_INFO_FOR_JOIN_BATTLE_FIELD_ACK );
_EVENT_HANDLER( ERM_LEAVE_ROOM_FOR_JOIN_BATTLE_FIELD_ACK, KEGS_LEAVE_ROOM_ACK );
_EVENT_HANDLER( ERM_LEAVE_BATTLE_FIELD_FOR_JOIN_BATTLE_FIELD_ACK, KEGS_LEAVE_ROOM_ACK );
EVENT_HANDLER( ERM_OPEN_BATTLE_FIELD_ACK );
#ifdef SERV_BATTLE_FIELD_BOSS// �۾���¥: 2013-11-08	// �ڼ���
EVENT_HANDLER( ERM_JOIN_BATTLE_FIELD_ACK );
#else // SERV_BATTLE_FIELD_BOSS
_EVENT_HANDLER( ERM_JOIN_BATTLE_FIELD_ACK, KEGS_JOIN_BATTLE_FIELD_ACK );
#endif // SERV_BATTLE_FIELD_BOSS
_EVENT_HANDLER( ERM_JOIN_BATTLE_FIELD_NOT, KEGS_JOIN_BATTLE_FIELD_NOT );

_EVENT_HANDLER( ERM_LEAVE_BATTLE_FIELD_NOT, KEGS_LEAVE_BATTLE_FIELD_NOT );

_EVENT_HANDLER( ERM_BATTLE_FIELD_GAME_LOADING_ACK, KPacketOK );
EVENT_HANDLER( EGS_BATTLE_FIELD_JOIN_USER_LOAD_COMPLETE_NOT );

_EVENT_HANDLER( ERM_BATTLE_FIELD_NPC_LOAD_NOT, KEGS_BATTLE_FIELD_NPC_LOAD_NOT );
EVENT_HANDLER_NOPARAM( EGS_BATTLE_FIELD_NPC_LOAD_COMPLETE_REQ );
_EVENT_HANDLER( ERM_BATTLE_FIELD_NPC_LOAD_COMPLETE_ACK, KEGS_BATTLE_FIELD_NPC_LOAD_COMPLETE_ACK );
_EVENT_HANDLER( ERM_BATTLE_FIELD_NPC_P2P_SYNC_NOT, KEGS_BATTLE_FIELD_NPC_P2P_SYNC_NOT );
//#ifndef SERV_OPTIMIZE_ROBUST_USER_NPC_PACKET_SEND
//EVENT_HANDLER_NOPARAM( EGS_BATTLE_FIELD_NPC_P2P_SYNC_COMPLETE_NOT );
//#endif  SERV_OPTIMIZE_ROBUST_USER_NPC_PACKET_SEND

_EVENT_HANDLER( ERM_BATTLE_FIELD_EVENT_MESSAGE_NOT, KEGS_BATTLE_FIELD_EVENT_MESSAGE_NOT );
EVENT_HANDLER( EGS_UPDATE_BATTLE_FIELD_USER_POS_NOT );

_EVENT_HANDLER( EPM_UPDATE_MOVE_TO_PARTY_MEMBER_INFO_NOT, KEGS_UPDATE_MOVE_TO_PARTY_MEMBER_INFO_NOT );

EVENT_HANDLER( ERM_BATTLE_FIELD_ZU_ECHO_REQ );

//{{ 2012. 09. 19   ��μ�   ĳ�ü� �湮 ����
#ifdef SERV_VISIT_CASH_SHOP
EVENT_HANDLER( ERM_UPDATE_VISIT_CASH_SHOP_NOT );
#endif SERV_VISIT_CASH_SHOP
//}}

//{{ ��Ʋ�ʵ� Ŀ�´�Ƽ ����Ʈ Ȯ�� - ��μ�
#ifdef SERV_COMMUNITY_IN_BATTLE_FIELD
_EVENT_HANDLER( ERM_COMMUNITY_IN_BATTLE_FIELD_ACK, KEGS_COMMUNITY_USER_LIST_ACK );
#endif SERV_COMMUNITY_IN_BATTLE_FIELD
//}}

//{{ 2013. 02. 15   �ʵ� �߰� ���� - ��μ�
#ifdef SERV_BATTLEFIELD_MIDDLE_BOSS
_EVENT_HANDLER( ERM_NPC_UNIT_CREATE_MIDDLE_BOSS_NOT, KEGS_NPC_UNIT_CREATE_MIDDLE_BOSS_NOT );
EVENT_HANDLER( EGS_SYNC_BATTLE_FIELD_DAMAGED_MAP_REQ );
_EVENT_HANDLER( ERM_BATTLE_FIELD_NPC_DAMAGED_MAP_ACK, KEGS_BATTLE_FIELD_NPC_DAMAGED_MAP_REQ );
EVENT_HANDLER( EGS_BATTLE_FIELD_NPC_DAMAGED_MAP_ACK );
_EVENT_HANDLER( ERM_SYNC_BATTLE_FIELD_DAMAGED_MAP_NOT, KEGS_SYNC_BATTLE_FIELD_DAMAGED_MAP_NOT );
#endif SERV_BATTLEFIELD_MIDDLE_BOSS
//}

#ifdef SERV_SYNC_PACKET_USING_RELAY_WORKINGS_CHECK// �۾���¥: 2013-05-09	// �ڼ���
_EVENT_HANDLER( ERM_LEAVE_ROOM_FOR_WORKINGS_BLOCK_ACK, KEGS_LEAVE_ROOM_ACK );
EVENT_HANDLER( DBE_BLOCK_COUNT_CHECK_INFO_READ_ACK );
#endif // SERV_SYNC_PACKET_USING_RELAY_WORKINGS_CHECK

#ifdef SERV_FIELD_WORKINGS_BLOCK_LOG// �۾���¥: 2013-05-15	// �ڼ���
EVENT_HANDLER( EGS_FIELD_WORKINGS_BLOCK_LOG_ACK );
#endif // SERV_FIELD_WORKINGS_BLOCK_LOG

#ifdef SERV_BATTLE_FIELD_BOSS// �۾���¥: 2013-11-07	// �ڼ���
EVENT_HANDLER_NOPARAM( EGS_BOSS_FIELD_INTRUDE_RESTRICTION_REQ );
EVENT_HANDLER( ERM_BOSS_FIELD_INTRUDE_RESTRICTION_ACK );
EVENT_HANDLER_NOPARAM( ERM_BOSS_FIELD_CLOSE_PROCESS_NOT );
EVENT_HANDLER_NOPARAM( ERM_BOSS_FIELD_RETURN_PROCESS_NOT );
EVENT_HANDLER( EGS_BOSS_FIELD_LOG_NOT );
#endif // SERV_BATTLE_FIELD_BOSS
