#pragma once

#pragma NOTE( "인도네시아 서버 디파인 적용 됩니다." )


//--------------------------------------------------------------------------------------------------------------//
//-------------------------------------- 언데프 목록 -----------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------------//
#undef SERV_EVENT_VALENTINE_DUNGEON
//--------------------------------------------------------------------------------------------------------------//
//-------------------------------------- 언데프 목록 -----------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------------//

//////////////////////////////////////////////////////////////////////////
// 이름: 조성욱
// 아이디: darkstarbt
// 작업시작날짜: 2013-06-26
// 패치날짜: 2013-07-03
// 작업내용: 인도네시아 넷마블 PC 방 인증 및 혜택 적용 작업
#define SERV_ID_NETMARBLE_PCBANG //패치를 위해 일단 주석
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// 이름: 임홍락
// 아이디: honnak
// 작업시작날짜: 2013-05-13
// 패치날짜: 2013-05-15
// 작업내용: 필드 쿠키 조각 작업
#define SERV_BATTLEFIELD_COOKIE_PIECE
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// 이름: 조성욱
// 아이디: darkstarbt
// 작업시작날짜: 2013-05-09
// 패치날짜: 2013-05-15
// 작업내용: 클라이언트에서 지정한 UDP 포트가 막혀있을 경우 오픈되어있는 UDP 포트 정보를 DB 에 기록하기 위한 용도
#define SERV_CLIENT_PORT_CHANGE_REQUEST_LOG // 2013.06.05 lyga_조성욱 // 머지
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// 이름: 조성욱
// 아이디: darkstarbt
// 작업시작날짜: 2013-05-14
// 패치날짜: 2013-xx-xx ( 미정 )
// 작업내용: 개발자용 가열기 가짜로 오픈해서 확률 정보 알아보는 작업 ( 사내 전용 )
#define SERV_DEVELOPER_RANDOM_OPEN_ITEM_LOG
//////////////////////////////////////////////////////////////////////////


// 2차 전직 이벤트용 망각의 알약 by 박진웅
#define SERV_2ND_CLASS_SKILL_RESET // 2013.05.27 lygan_조성욱 // 머지

// 퀘스트용 망각의 알약 by 박진웅
#define SERV_QUEST_SKILL_RESET // 2013.05.27 lygan_조성욱 // 머지

//////////////////////////////////////////////////////////////////////////
// 이름: 조성욱
// 아이디: darkstarbt
// 작업시작날짜: 2013-04-23
// 패치날짜: 2013-04-30
// 작업내용: 1/3 확률 가열기 추가 
#define SERV_ONE_THIRD_MINI_ATTRACTION_ITEM //  2013. 05.23 lygan_조성욱 머지
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// 이름: 조성욱
// 아이디: darkstarbt
// 작업시작날짜: 2013-05-23
// 패치날짜: 2013-06-04
// 작업내용: 클라이언트에서 PC방 정보를 알아내서 서버로 알려주는 구조용 작업
#define SERV_CLIENT_DIRECT_CONNECT_AUTH_PCBANG
//////////////////////////////////////////////////////////////////////////


//------------------------------------------------------------------------
// 보상 이슈가 발생할때 DB에서 우편으로 바로 지급하는 전용 타입 추가. // 2013.02.05 lygan_조성욱
//------------------------------------------------------------------------
#define SERV_INDEMNIFICATION_POST_DB_ONLY // 2013.05.22 lygan_조성욱 // 머지


// 박진웅 2차보안패드 진입점만 제거
#define SERV_DISABLE_SECOND_SECURITY

//------------------------------------------------------------------------
// NProtect 서버 인증
//------------------------------------------------------------------------
#define SERV_NPROTECT_CS_AUTH_30


// 박진웅 : [2012/10/30]  대전에 레벨 제한 제거
//#define SERV_FREE_PVP

//------------------------------------------------------------------------
// 캐릭터 삭제 프로세스 변경 (삭제 대기 기간 도입)
//------------------------------------------------------------------------
//#define SERV_UNIT_WAIT_DELETE // 2012. 04. 28	박교현	머지 완료


//------------------------------------------------------------------------
// 인증 시 패스워드 인증 관련 Token 값 사용
//------------------------------------------------------------------------
#define SERV_USE_PASSWORD_TOKEN

//////////////////////////////////////////////////////////////////////////
// 이름: 박진웅
// 아이디: orange82
// 작업시작날짜: 2013-06-18
// 패치날짜: 2013-06-19
// 작업내용: 이벤트용 그노시스
#define SERV_CN_GNOSIS
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// 이름: 임홍락
// 아이디: honnak
// 작업시작날짜: 2013-08-17
// 패치날짜: 2013-08-29
// 작업내용: 아이템 개편 이벤트(아이템 교환시 및 아이템 감정시 우편 지급)
//#define SERV_NEW_ITEM_SYSTEM_2013_05_EVENT
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// 이름 : 김석근
// 아이디 : 86red
// 작업시작날짜 : 2013-06-28
// 패치날짜 : 2013-07-04(TW)
// 작업내용 : 신규 캐릭터, 기존 캐릭터 구분 짓는 접속이벤트
// 사용 전 확인 필수, 머지후 빠졌을 지도!! ( 13.08.24 아이템 개편머지후)
#define SERV_TIME_EVENT_ONLY_CURRENT_USER_CHAR
//#define SERV_TIME_EVENT_ONLY_CURRENT_USER
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// 이름 : 김석근
// 아이디 : 86red
// 작업시작날짜 : 2013-10-14
// 패치날짜 : 2013-10-16
// 작업내용 : 전직, 만렙시 망각의 드링크 지급 해외팀 RewardID 변경
#define SERV_PRESENT_SKILL_INIT_ITEM_INT
#ifdef SERV_PRESENT_SKILL_INIT_ITEM_INT
namespace _CONST_PRESENT_SKILL_INIT_ITEM_INT_
{
	const int iReachLimitLevel	= 698; // 만렙 달성 시 망각의 드링크 (3일권) 제공
	const int iChangeFirstJob	= 699; // 1차 캐시 전직권 구매 시 망각의 드링크 (3일권) 및 1차 프로모션 아이템 제공
	const int iChangeSecondJob	= 700; // 2차 캐시 전직권 구매 시 망각의 드링크 (3일권) 및 2차 프로모션 아이템 제공
}
#endif SERV_PRESENT_SKILL_INIT_ITEM_INT

//////////////////////////////////////////////////////////////////////////
// 이름 : 임홍락
// 아이디 : honnak
// 작업시작날짜 : 2013-10-15
// 패치날짜 : 2013-10-17
// 작업내용 : 스킬 트리 개편 이벤트 그노시스의 축복 130 SP (1일권)
#define SERV_EVENT_SKILL_POINT_1DAY_USE_INVEN
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// 이름 : 임홍락
// 아이디 : honnak
// 작업시작날짜 : 2013-10-08
// 패치날짜 : 2013-10-17
// 작업내용 : 스킬 트리 개편 이벤트 그노시스의 축복 130 SP (1일권)
#define SERV_EVENT_SKILL_POINT_130_1DAY_USE_INVEN
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// 이름 : 임홍락
// 아이디 : honnak
// 작업시작날짜 : 2013-10-11
// 패치날짜 : 2013-10-17
// 작업내용 : 대만 홍콩 캐시 그노시스 축복 7일권
#define SERV_CASH_SKILL_POINT_TW
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// 이름: 임홍락
// 아이디: honnak
// 작업시작날짜: 2013-10-10
// 패치날짜: 2013-10-17
// 작업내용: 루리엘의 선택 스킬 초기화 메달, 루리엘의 스킬 초기화 메달
#define SERV_EVENT_RURIEL_RESET_SKILL_ITEM
//////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////
// 이름: 김준환
// 아이디: honnak
// 작업시작날짜: 2013-10-10
// 패치날짜: 2013-10-17
// 작업내용: 이벤트로 사용하는 그노시스 주석 처리된 것 윗 부분에 수정 작업
#define SERV_EVENT_GNOSYS_ITEM
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// 이름: 임규수
// 아이디: bowrain
// 작업시작날짜: 2013-07-31
// 패치날짜: 2013-08-07
// 작업내용: 레압 무제한 봉인 가능하도록 ( 봉인 횟수 감소 제거 )
// 레압 외에도 있을 수 있음. 기획툴에서 MaxSealCount 값이 255이면 모두 적용
#define SERV_REMOVE_SEAL_COUNT_DECREASE
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// 이름: 김준환
// 아이디: jhkim86
// 작업시작날짜: 2013-11-12
// 패치날짜: 2013-11-20
// 작업내용: 접속 이벤트 경험치 보너스 레벨 구간 적용되게하기.
//#define SERV_BUFF_BONUSRATE_HAMEL_EVENT
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// 이름: 최민철	
// 아이디: hohocmc
// 작업시작날짜: 2013-10-29
// 패치날짜: 2013-10-30
// 작업내용: 사내에서만 파싱에러 메일 날아오게 하는 기능 수정
#ifndef _SERVICE_
#define SERV_FIX_SCRIPT_PARSING_ERR_REPORT_ONLY_INTERNAL
#endif //!_SERVICE_
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// 이름: 김준환
// 아이디: jhkim86
// 작업시작날짜: 2013-11-14
// 패치날짜: 2013-11-21
// 작업내용: 전직 변경권, 전직 아이템 구매시 이벤트 아이템 지급
#define SERV_EVENT_CHANGE_CLASS
#ifdef SERV_EVENT_CHANGE_CLASS
namespace _CONST_EVENT_CHANGE_CLASS_ITEM_INT_
{
	const int iTransFormItem	= 1000307; // 뉴트랜스폼 큐브(해당이벤트 전직 캐릭터) 우편 지급
	//CXSLUnit::UNIT_CLASS iChangeClass	= CXSLUnit::UC_ARME_BATTLE_MAGICIAN; // 전직 클래스 //해당 소스에 직접 적용
}
#endif //SERV_EVENT_CHANGE_CLASS
//////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////
// 이름: 김준환
// 아이디: jhkim86
// 작업시작날짜: 2013-11-14
// 패치날짜: 2013-11-21
// 작업내용: 코보사 모험가 집중 훈련 프로그램
//#define SERV_EVENT_COBO_DUNGEON_AND_FIELD
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// 이름: 김준환
// 아이디: jhkim86
// 작업시작날짜: 2013-07-31
// 패치날짜: 2013-08-08
// 작업내용: 헤니르에서 이벤트 아이템 안떨어지게 하기 
//#define SERV_HENIR_EVENT_ITEM_NO_DROP
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// 이름: 이지헌
// 아이디: ninil
// 작업시작날짜: 2013-10-24
// 패치날짜: 2013-11-06
// 작업내용: 서버 config 파일위치 Config\ 폴더로 변경
#define SERV_CHANGE_SERVER_CONFIG_FORDER
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// 이름: 임규수
// 아이디: bowrain
// 작업시작날짜: 2013-10-28
// 패치날짜: 2013-10-28
// 작업내용: 넷에러 분리
#define SERV_SEPARATE_NET_ERROR
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// 이름: 이지헌
// 아이디: ninil
// 작업시작날짜: 2013-03-28
// 패치날짜: 미정
// 작업내용: 큐브 100개 까기 공지 OnOff 기능 추가
#define SERV_CUBE_AUTO_OPEN_NOTIFY_OFF
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// 이름: 김준환(머지)
// 아이디: jhkim86
// 작업시작날짜: 2013-05-21\
// 패치날짜: 미정
// 작업내용: DB Time 설정으로 아이템 관련 동작 수행 (상점, 교환, 제조)
//#define SERV_ITEM_ACTION_BY_DBTIME_SETTING
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// 이름: 박진웅
// 아이디: orange82
// 작업시작날짜: 2013-11-20
// 패치날짜: 2013-12-??
// 작업내용: 특정 아이템을 갖고 있을 때 그것을 소모하면서 클리어 보상 받음
#define SERV_PAYMENT_ITEM_WITH_CONSUMING_OTHER_ITEM
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// 이름: 박진웅
// 아이디: orange82
// 작업시작날짜: 2013-11-21
// 패치날짜: 2013-12-??
// 작업내용: 특정 NPC가 동료여야만 클리어 보상 받음
#define SERV_PAYMENT_ITEM_WITH_ALLY_NPC
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// 이름: 박진웅
// 아이디: orange82
// 작업시작날짜: 2013-11-21
// 패치날짜: 2013-12-??
// 작업내용: 2013 연말, 2014 새해 이벤트
#define SERV_NEW_YEAR_EVENT_2014
#ifdef SERV_NEW_YEAR_EVENT_2014
namespace _CONST_SERV_NEW_YEAR_EVENT_2014_
{
	const int iMaxLevelSpecialMissionItemID = 153000100; // 만렙 인증서
	const int iMaxLevelCertificationSubQuestID = 140221;
}
#endif SERV_NEW_YEAR_EVENT_2014
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// 이름: 박진웅
// 아이디: orange82
// 작업시작날짜: 2013-12-06
// 패치날짜: 2013-12-??
// 작업내용: 아직 진행중인 퀘스트만 보상을 주는 기능.
//			 SERV_DUNGEON_CLEAR_PAYMENT_ITEM_FIX 가 필요합니다.
#define SERV_PAYMENT_ITEM_ON_GOING_QUEST
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// 이름: 박진웅
// 아이디: orange82
// 작업시작날짜: 2013-12-10
// 패치날짜: 2013-12-??
// 작업내용: 아이템을 펫 인벤이나 은행으로 못 옮기게 함
#define SERV_RESTRICTED_TO_MOVE_TO_BANK
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// 이름: 김준환
// 아이디: jhkim86
// 작업시작날짜: 2013-05-21\
// 패치날짜: 미정
// 작업내용: 일본것 그노시스 축복 사용
#define SERV_GNOSIS_JP
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// 이름: 김준환
// 아이디: jhkim86
// 작업시작날짜: 2013-05-21\
// 패치날짜: 미정
// 작업내용: 그노시스 축복 나이트와쳐 이벤트 
#define SERV_EVENT_GNOSIS_ID_TH
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// 이름: 최민철
// 아이디: hohocmc
// 작업시작날짜: 2013-12-30
// 패치날짜: 2013-01-15
// 작업내용: 엘드라실 묘목 이벤트 몬스터 필드에서 퀘스트 보유시 적정레벨시 아이템 랜덤 획득
//#define SERV_RNW_ELDRASIL_EVENT
#ifdef SERV_RNW_ELDRASIL_EVENT
namespace _CONST_SERV_RNW_ELDRASIL_EVENT
{
	const int iMaxLevelCertificationSubQuestID = 121690;
}
#endif SERV_RNW_ELDRASIL_EVENT
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// 이름: 김준환
// 아이디: jhkim86
// 작업시작날짜: 2013-05-21\
// 패치날짜: 미정
// 작업내용: 큐브아이템 6강화 해서 주기 
#define SERV_EVENT_ENCHANT_LEVEL
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// 이름: 임규수
// 아이디: bowrain
// 작업시작날짜: 2013-07-22
// 패치날짜: 2013-07-24
// 작업내용: 아리엘 축복받은 무기 , 방어구 강화석
#define SERV_BLESSED_ARIEL_ENCHANT_STONE_EVENT
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// 이름: 김준환
// 아이디: jhkim86
// 작업시작날짜: 2013-05-21\
// 패치날짜: 미정
// 작업내용: 그노시스 춘절 이벤트용 
#define SERV_EVENT_GNOSIS_HAPP_NEW_YEAR
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// 이름: 최민철
// 아이디: hohocmc
// 작업시작날짜: 2014-01	-03
// 패치날짜: 2014-01-15
// 작업내용: 필드 이벤트 보스 시스템
#define SERV_BATTLEFIELD_EVENT_BOSS_INT
//////////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------------
// 2011.7.19 지헌 : 인벤확장 이벤트 아이템 추가.
//------------------------------------------------------------------------
#define SERV_EXPAND_INVENTORY_BY_EVENT_ITEM

//////////////////////////////////////////////////////////////////////////
// 이름: 김준환
// 아이디: jhkim86
// 작업시작날짜: 2013-05-21\
// 패치날짜: 미정
// 작업내용: 아담스의 상점 해킹 예외 처리 
//#define SERV_EVENT_ADAMS_UI_SHOP
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// 이름: 김석근
// 아이디: hohocmc
// 작업시작날짜: 2012-08-32
// 패치날짜: 2014-02-12
// 작업내용: 이벤트 재화(엘의 여인의 눈물) 
// 수정 : 최민철
//#define SERV_EVENT_TEAR_OF_ELWOMAN
//////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////
// 이름: 김준환
// 아이디: jhkim86
// 작업시작날짜: 2013-05-21\
// 패치날짜: 미정
// 작업내용: 발렌타인 던전 기술의 반지 소켓 옵션 발렌타인 던전에서만 적용 가능하게 하기 
//#define SERV_EVENT_VALENTINE_RING_IS_DUNGEON
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// 이름: 김준환
// 아이디: jhkim86
// 작업시작날짜: 2013-05-21\
// 패치날짜: 미정
// 작업내용: 헨렌의 발렌타인 던전 보상 지급 
//#define SERV_EVENT_VALENTINE_DUNGEON_GIVE_ITEM
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// 이름: 임홍락
// 아이디: honnak
// 작업시작날짜: 2014-01-17
// 패치날짜: 2014-02-05
// 작업내용: 2014 발렌타인 이벤트 던전
//#define SERV_EVENT_VALENTINE_DUNGEON_INT
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// 이름: 이지헌
// 아이디: ninil
// 작업시작날짜: 2014-01-09
// 패치날짜: 2014-01-09
// 작업내용: Sub Title Mission 파싱 오류나면 크래시 날 수 있는 부분 수정
#define SERV_SUB_TITLE_MISSION_BUG_FIX
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// 이름: 임규수
// 아이디: bowrain
// 작업시작날짜: 2013-09-25
// 패치날짜: 2013-09-25
// 작업내용: 한벌 아바타 슬롯 추가
#define SERV_NEW_ONE_PIECE_AVATAR_SLOT // 2013.11.20 darkstarbt_조성욱 // 필리핀에 머지
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// 이름: 김석근
// 아이디: 86red
// 작업시작날짜: 2013-11-04
// 패치날짜: 2013-11-06
// 작업내용: 루리엘 축복받은 무기 , 방어구 강화석
#define SERV_BLESSED_RURIEL_ENCHANT_STONE_EVENT
#ifdef SERV_BLESSED_RURIEL_ENCHANT_STONE_EVENT
namespace _CONST_BLESSED_RURIEL_ENCHANT_STONE_EVENT
{
	// ItemID
	const int	iRuriel_Enchant_Stone_Weapon_Item	= 152000121; // 루리엘의 축복받은 무기강화석
	const int	iRuriel_Enchant_Stone_Defence_Item	= 152000122; // 루리엘의 축복받은 방어구강화석
}
#endif //SERV_BLESSED_RURIEL_ENCHANT_STONE_EVENT
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// 이름 : 김석근
// 아이디 : 86red
// 작업시작날짜 : 2013-09-09
// 패치날짜 : 2013-09-11
// 작업내용 : 해외팀 이벤트 관련 UI 표시 // 임시로 어문만 대충작업. 추후 수정예정
#define SERV_INT_UI_SHOW_EVENT_UI
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// 이름 : 김석근
// 아이디 : 86red
// 작업시작날짜 : 2013-09-04
// 패치날짜 : 2013-09-11
// 작업내용 : 어둠의 문 시즌3 월드 디버프 해외팀 사용 안함!
#define SERV_NEW_DEFENCE_DUNGEON_NO_USE_DEFENSE_BUFF_AND_DEBUFF
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// 이름 : 김석근
// 아이디 : 86red
// 작업시작날짜 : 2013-09-04
// 패치날짜 : 2013-09-11
// 작업내용 : 어둠의 문 시즌3 확률 100% 이벤트
//#define SERV_NEW_DEFENCE_DUNGEON_ENTER_100_PERCENT_EVENT
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// 이름 : 임홍락
// 아이디 : honnak
// 작업시작날짜 : 2013-09-04
// 패치날짜 : 2013-09-12
// 작업내용 : 어둠의 문 개편 이벤트
//#define SERV_GATE_OF_DARKNESS_SUPPORT_EVENT
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// 김석근[12.12.18] 2인이상 파티플레이(77000, 77020)
// 박진웅[13.02.16] 3인이상 파티플레이(84430)
// 박진웅[13.02.16] 아래 상수 참조하도록 코드 수정
//////////////////////////////////////////////////////////////////////////
//#define SERV_PARTYPLAY_WITH_DUNGEON_CLEAR_COUNT // 2012. 12.19 lygan_조성욱 머지
#ifdef SERV_PARTYPLAY_WITH_DUNGEON_CLEAR_COUNT
namespace _CONST_PARTYPLAY_WITH_DUNGEON_CLEAR_COUNT_
{
	const int aSubQuestID[] = { 74560 };
	const int iSubQuestMaxNum = 1;
	const char cUnitType = 0;
	const char cUnitClass = 0;
	const char cRequiredMembers = 4;
}
#endif SERV_PARTYPLAY_WITH_DUNGEON_CLEAR_COUNT
/////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// 이름 : 이지헌
// 아이디 : ninil
// 작업시작날짜 : 2014-02-12
// 패치날짜 : 2014-02-12
// 작업내용 : 엘리시스 디파인 켠 상태에서 영향 주는 부분들 수정한 디파인. 엘리시스 들어가면 제거하면 됩니다.
// 1. 교환 최대 슬롯 7로 변경
#define SERV_NEW_CHARACTER_EL_DISABLE // 2014.02.12 lygan_조성욱 // 브라질에 머지
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// 이름: 조성욱
// 아이디: darkstarbt
// 작업시작날짜: 2014-02-17
// 패치날짜: 2014-02-26
// 작업내용: 기간제 제조의 경우 제조 리스트에 기간 표시가 없는 버그 수정
#define SERV_MANUFACTURE_PERIOD_FIX
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// 이름: 임규수
// 아이디: bowrain
// 작업시작날짜: 2013-04-22
// 패치날짜: 미정
// 작업내용: 샌더 마을 제거 ( 거의 스크립트 , 코보 익스프레스 관련 소스도 있음 ) ( 검색 위해서 넣음 )
#define NO_SANDER_VILLIAGE
//////////////////////////////////////////////////////////////////////////