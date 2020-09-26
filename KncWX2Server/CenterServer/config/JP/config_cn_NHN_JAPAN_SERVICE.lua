﻿-- lua header. UTF-8 인코딩 인식을 위해 이 줄은 지우지 마세요.

----------     Login Server 설정     ----------

-- 크래쉬 리포트 메일링 리스트 --
Server:SetMailingList( "kknd345@kog.co.kr, bowrain@kog.co.kr" )

-- 종료시 db 처리 대기시간 --
Server:SetShutDownWait( 60 * 1000 )  -- 종료시 db 처리 대기시간 : 1분.

-- 스크립트 파싱 실패 리포트
Server:SetScriptParsingErrReport( true )
Server:AddScriptParsingErrReportMail( 'kknd345@kog.co.kr' )	-- 조효진
Server:AddScriptParsingErrReportMail( 'bowrain@kog.co.kr' ) -- 임규수

-- Add moritoring server's IP for checking port of elsword's server ( SERV_PERMIT_PORT_CHECK )
--Server:AddPortCheckMoritoringServer( "79.110.90.240" )

----------     Center NetLayer 설정     ----------

NetLayer:SetCheckSequenceNum( false ) -- 내부통신은 SequenceNum 체크필요없음


----------     Center SimLayer 설정     ----------
SimLayer:SetUseKogOTP ( true )

-- PublisherBillingConnectType Flag --
--[[
		PBCT_NONE				= 0,	
		// kncSend 떄문에 DBLayer와 일반 Manager 는 구분되어야 함
		PBCT_NORMAL		= 1,	// 일반적인 Manager 통해 (보통은 TCP, SOAP 등)
		PBCT_DB					= 2,	// DB 통신 Manager를 통해
		PBCT_UNUSUAL		= 3,	// 섞어 쓰던가 특이 사항 있는 경우
--]]
SimLayer:SetPublisherBillingConnectType (PBCT_NORMAL)
SimLayer:SetCheckCouponByPublisher ( false )

-- Auth Flag --
--[[
AF_INTERNAL    : 사내 인증
AF_GLOBAL_SERVICE : 퍼블 인증
--]]
SimLayer:SetAuthFlag( AF_GLOBAL_SERVICE )


----------     DB Layer 설정     ----------

-- 접속 DB 목록 --
--[[
DC_ACCOUNT         : 계정
DC_GAME            : 게임
DC_LOG             : 통계
DC_NX_SHOP_GATEWAY : 넥슨 빌링 게이트웨이
--]]
-- AddDB( DB 종류, file dsn, thread 개수, DBConnectionString여부 )

--DBLayer:AddDB( DC_ACCOUNT,	'Account_NHN_JAPAN_INTERNAL.dsn',	3, false )
--DBLayer:AddDB( DC_LOG,		'Log_NHN_JAPAN_INTERNAL.dsn',		3, false )
DBLayer:AddDB( DC_ACCOUNT,		'DRIVER=SQL Server;Network=DBMSSOCN;DATABASE=Account;WSID=PBSWDDM1007;SERVER=10.32.25.5',		3, true )
DBLayer:AddDB( DC_GAME,			'DRIVER=SQL Server;Network=DBMSSOCN;DATABASE=Game01;WSID=PBSWDDM1008;SERVER=10.32.25.7',		3, true )
DBLayer:AddDB( DC_LOG,			'DRIVER=SQL Server;Network=DBMSSOCN;DATABASE=Statistics;WSID=PBSWDDM1006;SERVER=10.32.25.3',	3, true )
DBLayer:AddDB( DC_EVENT,		'DRIVER=SQL Server;Network=DBMSSOCN;DATABASE=GameEvent;WSID=PBSWDDM1007;SERVER=10.32.25.5',		3, true )

-- Script File Path --
SimLayer:AddPath( "D:\\Server\\bin\\ServerResource" ) -- server common
SimLayer:AddPath( "D:\\Server\\bin\\ClientScript" ) -- client script

----------     룸 설정     ----------

RoomManager:SetNumPvPRoom( 2000 )
RoomManager:SetNumDungeonRoom( 2000 )
-- DB에 설정되어 있는 광장 개수 이상이어야 한다.
RoomManager:SetNumSquare( 10 )
--RoomManager:SetNumParty( 1500 )
RoomManager:SetNumTrade( 300 )
RoomManager:SetNumTrainingCenterRoom( 2000 )
RoomManager:SetNumPersonalShop( 100 )
RoomManager:SetNumBattleField( 1500 )
RoomManager:SetNumWeddingHall( 100 )
--RoomManager:SetNumArcadeRoom( 100 )
-- 좀비유저 체크 시간 설정 --
RoomManager:SetZUTickTime( 300 )
RoomManager:SetBattleFieldZUTickTime( 100 )		-- 배틀필드 좀비유저 체크 시간 설정


----------     통계 설정     ----------

StatisticsManager:AddStatistics( SI_RES_STONE, 3600, true )
StatisticsManager:AddStatistics( SI_LOC_PVP, 3600, false )



----------     로그 레벨 설정     ----------

-- 로그 레벨 --
--[[
-1 : no logs
 0 : cerr, cout
 1 : cerr, cwarn, cout
 2 : cerr, cwarn, clog, cout
--]]
log( 0 )
