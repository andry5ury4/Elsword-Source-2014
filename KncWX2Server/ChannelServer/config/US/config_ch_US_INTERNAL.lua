﻿----------     Channel Server 설정     ----------

-- 크래쉬 리포트 메일링 리스트 --
Server:SetMailingList( "ninil@kog.co.kr, bowrain@kog.co.kr" )

-- 종료시 db 처리 대기시간 --
Server:SetShutDownWait( 60 * 1000 )

-- 스크립트 파싱 실패 리포트
Server:SetScriptParsingErrReport( true )
Server:AddScriptParsingErrReportMail( 'ninil@kog.co.kr' )	-- 조효진
Server:AddScriptParsingErrReportMail( 'bowrain@kog.co.kr' ) -- 임규수

-- Add moritoring server's IP for checking port of elsword's server ( SERV_PERMIT_PORT_CHECK )
--Server:AddPortCheckMoritoringServer( "79.110.90.240" )

----------     Channel NetLayer 설정     ----------

NetLayer:SetCheckSequenceNum( false )
NetLayer:SetPacketAuthFailLimit( 100 ) -- 유저가 100개이상 비정상 패킷을 보내면 해당 유저 접속해제


----------     Channel SimLayer 설정     ----------
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
AF_NEXON_KOREA : 넥슨 국내 인증
AF_K3RCOMBO_US : 미국
--]]
SimLayer:SetAuthFlag( AF_INTERNAL )

-- IP Check --
SimLayer:SetCheckIPMode( CIM_SERVICE_MODE )		-- 서비스 모드
--SimLayer:SetCheckIPMode( CIM_CHECK_MODE )		-- 점검모드

-- 점검 모드 IP 체크
SimLayer:AddCheckModeIP( "192.168.66" )
SimLayer:SetCheckModeCheckIPType( CIT_CHECK_IP_BLOCK )

-- 서비스 모드 IP 체크
SimLayer:AddIP( "192.168.66" )
SimLayer:SetCheckIPType( CIT_ALL_IP_ALLOW )

-- Script File Path --
SimLayer:AddPath( "D:\\ProjectX2_SVN\\source\\JP_TW_EU_CN_US\\Trunk\\KncWX2Server\\ServerResource\\US" ) -- server common
SimLayer:AddPath( "D:\\ProjectX2_SVN\\resource\\US\\Trunk\\dat\\Script" ) -- client script


----------     DB Layer 설정     ----------

-- 접속 DB 목록 --
--[[
DC_ACCOUNT         : 계정
DC_GAME            : 게임
DC_LOG             : 통계
DC_NX_SHOP_GATEWAY : 넥슨 빌링 게이트웨이
--]]
-- AddDB( DB 종류, file dsn, thread 개수, DBConnectionString여부 )

DBLayer:AddDB( DC_ACCOUNT,	'Config\\US\\Account_US_INTERNAL.dsn',	3, false )

if Server:GetServerGroupID() == 0 then
	DBLayer:AddDB( DC_LOG, 'Config\\US\\log_US_INTERNAL.dsn', 3, false )
elseif Server:GetServerGroupID() == 1 then
	DBLayer:AddDB( DC_LOG, 'Config\\US\\log_US_INTERNAL.dsn', 3, false )
else
	DBLayer:AddDB( DC_LOG, 'Config\\US\\log_US_INTERNAL.dsn', 3, false )
end

----------     인증 설정     ----------
-- 테스트 중
-- add 함수들은 인자를 다 임시로.. 어차피 안쓰고 있음
K3RComboAuthManager:AddWebServiceAddress( 'http://gamewcf.kill3rcombo.com:83/GameSecurityService.svc' )
K3RComboAuthManager:AddWebMethod( K3R_AUTH, 'http://Kill3rComboService/2010/IGameSecurityContract/Login' )
--K3RComboAuthManager:AddWebMethod( K3R_AUTH, 'http://tempuri.org/IGameSecurityContract/Login' )
K3RComboAuthManager:Init( 1 )


----------     로그 레벨 설정     ----------

-- 로그 레벨 --
--[[
-1 : no logs
 0 : cerr, cout
 1 : cerr, cwarn, cout
 2 : cerr, cwarn, clog, cout
--]]
log( 0 )