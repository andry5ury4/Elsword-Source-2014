
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

EVENT_HANDLER_NOPARAM( EGS_SEND_STATISTICS_LOCLOG_REQ );
EVENT_HANDLER_NOPARAM( EGS_SEND_STATISTICS_DBLOG_REQ );

_EVENT_HANDLER( EGS_ADMIN_QUEST_COMPLETE_REQ, KEGS_QUEST_COMPLETE_REQ );

EVENT_HANDLER_NOPARAM( EGS_ADMIN_SERVER_STATUS_REQ );
_EVENT_HANDLER( DBE_ADMIN_SERVER_STATUS_ACK, KEGS_ADMIN_SERVER_STATUS_ACK );
EVENT_HANDLER( EGS_NOTIFY_MSG_REQ );

EVENT_HANDLER( EGS_ADMIN_MODIFY_UNIT_LEVEL_REQ );
_EVENT_HANDLER( DBE_ADMIN_MODIFY_UNIT_LEVEL_ACK, KEGS_ADMIN_MODIFY_UNIT_LEVEL_ACK );

EVENT_HANDLER( EGS_ADMIN_CHANGE_AUTH_LEVEL_REQ );
_EVENT_HANDLER( DBE_ADMIN_CHANGE_AUTH_LEVEL_ACK, KEGS_ADMIN_CHANGE_AUTH_LEVEL_ACK );
EVENT_HANDLER( EGS_ADMIN_GET_AUTH_LEVEL_LIST_REQ );
_EVENT_HANDLER( DBE_ADMIN_GET_AUTH_LEVEL_LIST_ACK, KEGS_ADMIN_GET_AUTH_LEVEL_LIST_ACK );

EVENT_HANDLER( EGS_ADMIN_CHANGE_ED_REQ );
_EVENT_HANDLER( DBE_ADMIN_CHANGE_ED_ACK, KEGS_ADMIN_CHANGE_ED_ACK );
EVENT_HANDLER( EGS_ADMIN_KICK_USER_REQ );
_EVENT_HANDLER( ELG_ADMIN_KICK_USER_ACK, KEGS_ADMIN_KICK_USER_ACK );

EVENT_HANDLER( EGS_ADMIN_CHANGE_SKILL_POINT_REQ );

#ifdef SERV_SKILL_PAGE_SYSTEM
EVENT_HANDLER( EGS_ADMIN_INIT_SKILL_TREE_REQ );
#else // SERV_SKILL_PAGE_SYSTEM
EVENT_HANDLER_NOPARAM( EGS_ADMIN_INIT_SKILL_TREE_REQ );
#endif // SERV_SKILL_PAGE_SYSTEM
_EVENT_HANDLER( DBE_ADMIN_INIT_SKILL_TREE_ACK, KEGS_ADMIN_INIT_SKILL_TREE_ACK );

//{{ 2009. 7. 26  최육사	party fever cheat
EVENT_HANDLER_NOPARAM( EGS_ADMIN_INCREASE_PARTY_FEVER_POINT_NOT );
//}}

EVENT_HANDLER( EGS_ADMIN_CHANGE_SPIRIT_REQ );
EVENT_HANDLER( EGS_ADMIN_SET_PC_BANG_REQ );
EVENT_HANDLER( EGS_ADMIN_CHANGE_VSPOINT_REQ );
EVENT_HANDLER( EGS_ADMIN_CHANGE_UNIT_CLASS_REQ );

//{{ 2008. 10. 24  최육사	타이틀 치트
EVENT_HANDLER( EGS_ADMIN_GET_TITLE_CHEAT_REQ );
//}}

//{{ 2009. 7. 29  최육사	item set cheat
EVENT_HANDLER_NOPARAM( EGS_ADMIN_GET_ITEM_SET_NOT );
//}}

//{{ 2009. 8. 5  최육사		체험ID치트
_EVENT_HANDLER( EGS_ADMIN_GUEST_USER_MODE_NOT, bool );
//}}

#ifdef GUILD_SKILL_TEST
EVENT_HANDLER( EGS_ADMIN_GET_GUILD_SKILL_POINT_REQ );
EVENT_HANDLER( ELG_ADMIN_GET_GUILD_SKILL_POINT_ACK );
#endif GUILD_SKILL_TEST

//{{ 2010. 7. 21  최육사	펫 시스템
#ifdef SERV_PET_SYSTEM
EVENT_HANDLER( EGS_ADMIN_CHANGE_PET_INFO_NOT );
#endif SERV_PET_SYSTEM
//}}

//{{ 2010. 9. 29	최육사	ED 모니터링 치트
#ifdef SERV_ADMIN_SHOW_ED
EVENT_HANDLER( EGS_ADMIN_SHOW_ED_CHEAT_REQ );
EVENT_HANDLER( ELG_ADMIN_SHOW_ED_CHEAT_REQ );
_EVENT_HANDLER( ELG_ADMIN_SHOW_ED_CHEAT_ACK, KEGS_ADMIN_SHOW_ED_CHEAT_ACK );
#endif SERV_ADMIN_SHOW_ED
//}}

//{{ 2011. 04. 16	최육사	대리 상인
#ifdef SERV_PSHOP_AGENCY
EVENT_HANDLER( EGS_ADMIN_PSHOP_AGENCY_CHEAT_REQ );
#endif SERV_PSHOP_AGENCY
//}}

//{{ 2011. 08. 11	최육사	투니 랜드 채널링 
#ifdef SERV_TOONILAND_CHANNELING // SERV_JAPAN_CHANNELING
EVENT_HANDLER( EGS_ADMIN_CHANNELING_CODE_CHEAT_NOT );
#endif SERV_TOONILAND_CHANNELING // SERV_JAPAN_CHANNELING
//}}

//{{ 2011. 08. 12   김민성      헤니르 개편 
#ifdef SERV_NEW_HENIR_TEST
EVENT_HANDLER( EGS_ADMIN_HENIR_REWARD_CHEAT_NOT );
#endif SERV_NEW_HENIR_TEST
//}}

//{{ 2011. 09. 20  김민성	게임내 ED 감시 모니터링
#ifdef SERV_ED_MONITORING_IN_GAME
EVENT_HANDLER( EGS_ADMIN_ED_MONITORING_CHEAT_NOT );
#endif SERV_ED_MONITORING_IN_GAME
//}}

#ifdef SERV_CREATE_ELITE_FOR_ADMIN
EVENT_HANDLER( EGS_ADMIN_NPC_UNIT_CREATE_REQ );
_EVENT_HANDLER( ERM_ADMIN_NPC_UNIT_CREATE_ACK, KPacketOK );
_EVENT_HANDLER( ERM_ADMIN_NPC_UNIT_CREATE_NOT, KEGS_ADMIN_NPC_UNIT_CREATE_NOT );
#endif SERV_CREATE_ELITE_FOR_ADMIN

//{{ 2012. 05. 30	최육사	그노시스 기간 치트
#ifdef SERV_CASH_SKILL_POINT_DATE_CHANGE
EVENT_HANDLER( EGS_ADMIN_CASH_SKILL_POINT_DATE_CHANGE_REQ );
_EVENT_HANDLER( DBE_ADMIN_CASH_SKILL_POINT_DATE_CHANGE_ACK, KEGS_ADMIN_CASH_SKILL_POINT_DATE_CHANGE_ACK );
#endif SERV_CASH_SKILL_POINT_DATE_CHANGE
//}}

//{{ 2012. 07. 24	박세훈	해당 캐릭터의 모든 스킬을 다 찍는 치트
#ifdef SERV_ADMIN_CHEAT_GET_ALL_SKILL

#ifdef SERV_SKILL_PAGE_SYSTEM
EVENT_HANDLER( EGS_ADMIN_CHEAT_GET_ALL_SKILL_REQ );
#else // SERV_SKILL_PAGE_SYSTEM
EVENT_HANDLER_NOPARAM( EGS_ADMIN_CHEAT_GET_ALL_SKILL_REQ );
#endif // SERV_SKILL_PAGE_SYSTEM

EVENT_HANDLER( DBE_ADMIN_CHEAT_GET_ALL_SKILL_ACK );
#endif SERV_ADMIN_CHEAT_GET_ALL_SKILL
//}}

//{{ 2012. 09. 02	박세훈	Merge ( 대전에서 클라이언트 조작등으로 UDP 패킷이 날아오지 않는 유저가 발견되면 서버에서 킥한다. // 2012.06.11 lygan_조성욱 )
#ifdef UDP_CAN_NOT_SEND_USER_KICK
EVENT_HANDLER( EGS_UDP_KICK_GAMEEDIT_NOT );
#endif UDP_CAN_NOT_SEND_USER_KICK
//}}

//{{ 배틀필드 위험도 확인 치트 - 김민성
#ifdef SERV_BATTLE_FIELD_DANGEROUS_CHEAT
EVENT_HANDLER_NOPARAM( EGS_BATTLE_FIELD_DANGEROUS_VALUE_NOT );
_EVENT_HANDLER( ERM_BATTLE_FIELD_DANGEROUS_VALUE_ACK, int )
#endif SERV_BATTLE_FIELD_DANGEROUS_CHEAT
//}}

//{{ 2012. 11. 20	박세훈	영웅 대전 참가자 관리용 리스트
#ifdef SERV_HERO_PVP_MANAGE_LIST
EVENT_HANDLER_NOPARAM( EGS_ADMIN_HERO_PVP_USER_LIST_REQ );
_EVENT_HANDLER( EGB_ADMIN_HERO_PVP_USER_LIST_ACK, KEGS_ADMIN_HERO_PVP_USER_LIST_ACK );

EVENT_HANDLER( EGS_ADMIN_HERO_PVP_USER_ADD_REQ );
_EVENT_HANDLER( EGB_ADMIN_HERO_PVP_USER_ADD_ACK, KEGS_ADMIN_HERO_PVP_USER_ADD_ACK );

EVENT_HANDLER( EGS_ADMIN_HERO_PVP_USER_REMOVE_REQ );
_EVENT_HANDLER( EGB_ADMIN_HERO_PVP_USER_REMOVE_ACK, KEGS_ADMIN_HERO_PVP_USER_REMOVE_ACK );

EVENT_HANDLER( EGS_ADMIN_NOTIFY_HERO_PVP_USER_REQ );
_EVENT_HANDLER( EGB_ADMIN_NOTIFY_HERO_PVP_USER_ACK, KPacketOK );
_EVENT_HANDLER( EGB_ADMIN_NOTIFY_HERO_PVP_USER_NOT, KEGS_ADMIN_NOTIFY_HERO_PVP_USER_REQ );

_EVENT_HANDLER( EGB_ADMIN_HERO_PVP_USER_CONNECTION_NOT, KEGS_ADMIN_HERO_PVP_USER_CONNECTION_NOT );
_EVENT_HANDLER( EGB_ADMIN_HERO_PVP_USER_TOURNAMENT_CONNECTION_CHECK_NOT, bool );
#endif SERV_HERO_PVP_MANAGE_LIST
//}}

//{{ 2012. 12. 5	최육사		옵저버 대전 난입 모드
#ifdef SERV_OBSERVER_PVP_INTRUDE_MODE
EVENT_HANDLER( EGS_ADMIN_OBSERVER_MODE_REQ );
#endif SERV_OBSERVER_PVP_INTRUDE_MODE
//}}

#ifdef SERV_DELETE_GUILD_ADD_CHEAT
EVENT_HANDLER( EGS_ADMIN_DELETE_GUILD_ADD_NOT );
#endif // SERV_DELETE_GUILD_ADD_CHEAT

//{{ 2011.03.04  임규수 헤니르 랭킹 삭제 치트 ( 운영자,개발자 계정 )
#ifdef SERV_DELETE_HENIR_RANKING
EVENT_HANDLER( EGS_ADMIN_DELETE_HENIR_RANKING_RANK_NOT );
EVENT_HANDLER( EGS_ADMIN_DELETE_HENIR_RANKING_NICKNAME_NOT );
EVENT_HANDLER( EGS_ADMIN_DELETE_HENIR_RANKING_UNITUID_NOT );
#endif SERV_DELETE_HENIR_RANKING
//}}

//{{ 2013. 02. 15   필드 중간 보스 - 김민성
#ifdef SERV_BATTLEFIELD_MIDDLE_BOSS
EVENT_HANDLER( EGS_ADMIN_BATTLE_FIELD_INCREASE_DANGER_REQ );
_EVENT_HANDLER( ERM_ADMIN_BATTLE_FIELD_INCREASE_DANGER_ACK, KEGS_ADMIN_BATTLE_FIELD_INCREASE_DANGER_ACK );
#endif SERV_BATTLEFIELD_MIDDLE_BOSS
//}

//{{ 2013. 04. 01	 인연 시스템 - 김민성
#ifdef SERV_RELATIONSHIP_SYSTEM
EVENT_HANDLER( EGS_ADMIN_CHANGE_COUPLE_DATE_REQ );
_EVENT_HANDLER( DBE_ADMIN_CHANGE_COUPLE_DATE_ACK, KEGS_ADMIN_CHANGE_COUPLE_DATE_ACK );
#endif SERV_RELATIONSHIP_SYSTEM
//}

#ifdef SERV_UPGRADE_SKILL_SYSTEM_2013 // 적용날짜: 2013-06-27
EVENT_HANDLER( DBE_ADMIN_CHANGE_UNIT_CLASS_ACK );

#ifdef SERV_SKILL_PAGE_SYSTEM
EVENT_HANDLER( EGS_ADMIN_AUTO_GET_ALL_SKILL_REQ );
#else // SERV_SKILL_PAGE_SYSTEM
EVENT_HANDLER_NOPARAM( EGS_ADMIN_AUTO_GET_ALL_SKILL_REQ );
#endif // SERV_SKILL_PAGE_SYSTEM

EVENT_HANDLER( DBE_ADMIN_AUTO_GET_ALL_SKILL_ACK);
EVENT_HANDLER( EGS_ADMIN_GET_SKILL_REQ );
EVENT_HANDLER( DBE_ADMIN_GET_SKILL_ACK );
#endif	// SERV_UPGRADE_SKILL_SYSTEM_2013

#ifdef SERV_EVENT_CHECK_POWER
EVENT_HANDLER( EGS_SET_MULTIPLYER );
#endif SERV_EVENT_CHECK_POWER

#ifdef SERV_BATTLE_FIELD_BOSS// 작업날짜: 2013-11-09	// 박세훈
EVENT_HANDLER( EGS_ADMIN_BOSS_FIELD_GATE_OPEN_REQ );
EVENT_HANDLER( EGB_ADMIN_BOSS_FIELD_GATE_OPEN_ACK );
EVENT_HANDLER_NOPARAM( EGS_ADMIN_BOSS_FIELD_GATE_CLOSE_NOT );
EVENT_HANDLER( EGS_ADMIN_GET_TOTAL_DANGEROUS_VALUE_REQ );
EVENT_HANDLER( EGB_ADMIN_GET_TOTAL_DANGEROUS_VALUE_ACK );
EVENT_HANDLER( EGS_ADMIN_SET_TOTAL_DANGEROUS_VALUE_REQ );
EVENT_HANDLER( EGB_ADMIN_SET_TOTAL_DANGEROUS_VALUE_ACK );
#endif // SERV_BATTLE_FIELD_BOSS
#ifdef SERV_EVENT_COBO_DUNGEON_AND_FIELD
EVENT_HANDLER( EGS_EVENT_COBO_ITEM_GIVE_CHEAT_NOT );
#endif SERV_EVENT_COBO_DUNGEON_AND_FIELD

#ifdef SERV_EVENT_VALENTINE_DUNGEON_GIVE_ITEM
EVENT_HANDLER( EGS_EVENT_VALENTINE_DUNGEON_GIVE_ITEM_CHEAT_NOT );
#endif SERV_EVENT_VALENTINE_DUNGEON_GIVE_ITEM