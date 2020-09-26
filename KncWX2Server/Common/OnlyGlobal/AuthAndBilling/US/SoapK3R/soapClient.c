/* soapClient.c
   Generated by gSOAP 2.8.0 from k3r_soap.h
   Copyright(C) 2000-2010, Robert van Engelen, Genivia Inc. All Rights Reserved.
   The generated code is released under one of the following licenses:
   GPL, the gSOAP public license, or Genivia's license for commercial use.
*/

#if defined(__BORLANDC__)
#pragma option push -w-8060
#pragma option push -w-8004
#endif
#include "soapH.h"
#ifdef __cplusplus
extern "C" {
#endif

SOAP_SOURCE_STAMP("@(#) soapClient.c ver 2.8.0 2012-04-30 02:07:43 GMT")


SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__Login(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct _ns3__Login *ns3__Login, struct _ns3__LoginResponse *ns3__LoginResponse)
{	struct __ns1__Login soap_tmp___ns1__Login;
	if (!soap_endpoint)
		soap_endpoint = "http://222.127.25.30:83/GameSecurityService.svc";
	if (!soap_action)
		soap_action = "http://Kill3rComboService/2010/IGameSecurityContract/Login";
	soap->encodingStyle = NULL;
	soap_tmp___ns1__Login.ns3__Login = ns3__Login;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns1__Login(soap, &soap_tmp___ns1__Login);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__Login(soap, &soap_tmp___ns1__Login, "-ns1:Login", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__Login(soap, &soap_tmp___ns1__Login, "-ns1:Login", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns3__LoginResponse)
		return soap_closesock(soap);
	soap_default__ns3__LoginResponse(soap, ns3__LoginResponse);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get__ns3__LoginResponse(soap, ns3__LoginResponse, "ns3:LoginResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__Logout(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct _ns3__Logout *ns3__Logout, struct _ns3__LogoutResponse *ns3__LogoutResponse)
{	struct __ns1__Logout soap_tmp___ns1__Logout;
	if (!soap_endpoint)
		soap_endpoint = "http://222.127.25.30:83/GameSecurityService.svc";
	if (!soap_action)
		soap_action = "http://Kill3rComboService/2010/IGameSecurityContract/Logout";
	soap->encodingStyle = NULL;
	soap_tmp___ns1__Logout.ns3__Logout = ns3__Logout;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns1__Logout(soap, &soap_tmp___ns1__Logout);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__Logout(soap, &soap_tmp___ns1__Logout, "-ns1:Logout", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__Logout(soap, &soap_tmp___ns1__Logout, "-ns1:Logout", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns3__LogoutResponse)
		return soap_closesock(soap);
	soap_default__ns3__LogoutResponse(soap, ns3__LogoutResponse);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get__ns3__LogoutResponse(soap, ns3__LogoutResponse, "ns3:LogoutResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__InsertBannedFromGame(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct _ns3__InsertBannedFromGame *ns3__InsertBannedFromGame, struct _ns3__InsertBannedFromGameResponse *ns3__InsertBannedFromGameResponse)
{	struct __ns1__InsertBannedFromGame soap_tmp___ns1__InsertBannedFromGame;
	if (!soap_endpoint)
		soap_endpoint = "http://222.127.25.30:83/GameSecurityService.svc";
	if (!soap_action)
		soap_action = "http://Kill3rComboService/2010/IGameSecurityContract/InsertBannedFromGame";
	soap->encodingStyle = NULL;
	soap_tmp___ns1__InsertBannedFromGame.ns3__InsertBannedFromGame = ns3__InsertBannedFromGame;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns1__InsertBannedFromGame(soap, &soap_tmp___ns1__InsertBannedFromGame);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__InsertBannedFromGame(soap, &soap_tmp___ns1__InsertBannedFromGame, "-ns1:InsertBannedFromGame", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__InsertBannedFromGame(soap, &soap_tmp___ns1__InsertBannedFromGame, "-ns1:InsertBannedFromGame", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns3__InsertBannedFromGameResponse)
		return soap_closesock(soap);
	soap_default__ns3__InsertBannedFromGameResponse(soap, ns3__InsertBannedFromGameResponse);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get__ns3__InsertBannedFromGameResponse(soap, ns3__InsertBannedFromGameResponse, "ns3:InsertBannedFromGameResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__GetSecurityQuestionsStatus(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct _ns3__GetSecurityQuestionsStatus *ns3__GetSecurityQuestionsStatus, struct _ns3__GetSecurityQuestionsStatusResponse *ns3__GetSecurityQuestionsStatusResponse)
{	struct __ns1__GetSecurityQuestionsStatus soap_tmp___ns1__GetSecurityQuestionsStatus;
	if (!soap_endpoint)
		soap_endpoint = "http://222.127.25.30:83/GameSecurityService.svc";
	if (!soap_action)
		soap_action = "http://Kill3rComboService/2010/IGameSecurityContract/GetSecurityQuestionsStatus";
	soap->encodingStyle = NULL;
	soap_tmp___ns1__GetSecurityQuestionsStatus.ns3__GetSecurityQuestionsStatus = ns3__GetSecurityQuestionsStatus;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns1__GetSecurityQuestionsStatus(soap, &soap_tmp___ns1__GetSecurityQuestionsStatus);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__GetSecurityQuestionsStatus(soap, &soap_tmp___ns1__GetSecurityQuestionsStatus, "-ns1:GetSecurityQuestionsStatus", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__GetSecurityQuestionsStatus(soap, &soap_tmp___ns1__GetSecurityQuestionsStatus, "-ns1:GetSecurityQuestionsStatus", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns3__GetSecurityQuestionsStatusResponse)
		return soap_closesock(soap);
	soap_default__ns3__GetSecurityQuestionsStatusResponse(soap, ns3__GetSecurityQuestionsStatusResponse);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get__ns3__GetSecurityQuestionsStatusResponse(soap, ns3__GetSecurityQuestionsStatusResponse, "ns3:GetSecurityQuestionsStatusResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__setGamePinQuestions(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct _ns3__setGamePinQuestions *ns3__setGamePinQuestions, struct _ns3__setGamePinQuestionsResponse *ns3__setGamePinQuestionsResponse)
{	struct __ns1__setGamePinQuestions soap_tmp___ns1__setGamePinQuestions;
	if (!soap_endpoint)
		soap_endpoint = "http://222.127.25.30:83/GameSecurityService.svc";
	if (!soap_action)
		soap_action = "http://Kill3rComboService/2010/IGameSecurityContract/setGamePinQuestions";
	soap->encodingStyle = NULL;
	soap_tmp___ns1__setGamePinQuestions.ns3__setGamePinQuestions = ns3__setGamePinQuestions;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns1__setGamePinQuestions(soap, &soap_tmp___ns1__setGamePinQuestions);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__setGamePinQuestions(soap, &soap_tmp___ns1__setGamePinQuestions, "-ns1:setGamePinQuestions", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__setGamePinQuestions(soap, &soap_tmp___ns1__setGamePinQuestions, "-ns1:setGamePinQuestions", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns3__setGamePinQuestionsResponse)
		return soap_closesock(soap);
	soap_default__ns3__setGamePinQuestionsResponse(soap, ns3__setGamePinQuestionsResponse);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get__ns3__setGamePinQuestionsResponse(soap, ns3__setGamePinQuestionsResponse, "ns3:setGamePinQuestionsResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__getGamePinQuestions(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct _ns3__getGamePinQuestions *ns3__getGamePinQuestions, struct _ns3__getGamePinQuestionsResponse *ns3__getGamePinQuestionsResponse)
{	struct __ns1__getGamePinQuestions soap_tmp___ns1__getGamePinQuestions;
	if (!soap_endpoint)
		soap_endpoint = "http://222.127.25.30:83/GameSecurityService.svc";
	if (!soap_action)
		soap_action = "http://Kill3rComboService/2010/IGameSecurityContract/getGamePinQuestions";
	soap->encodingStyle = NULL;
	soap_tmp___ns1__getGamePinQuestions.ns3__getGamePinQuestions = ns3__getGamePinQuestions;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns1__getGamePinQuestions(soap, &soap_tmp___ns1__getGamePinQuestions);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__getGamePinQuestions(soap, &soap_tmp___ns1__getGamePinQuestions, "-ns1:getGamePinQuestions", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__getGamePinQuestions(soap, &soap_tmp___ns1__getGamePinQuestions, "-ns1:getGamePinQuestions", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns3__getGamePinQuestionsResponse)
		return soap_closesock(soap);
	soap_default__ns3__getGamePinQuestionsResponse(soap, ns3__getGamePinQuestionsResponse);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get__ns3__getGamePinQuestionsResponse(soap, ns3__getGamePinQuestionsResponse, "ns3:getGamePinQuestionsResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__testerMethod(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct _ns3__testerMethod *ns3__testerMethod, struct _ns3__testerMethodResponse *ns3__testerMethodResponse)
{	struct __ns1__testerMethod soap_tmp___ns1__testerMethod;
	if (!soap_endpoint)
		soap_endpoint = "http://222.127.25.30:83/GameSecurityService.svc";
	if (!soap_action)
		soap_action = "http://Kill3rComboService/2010/IGameSecurityContract/testerMethod";
	soap->encodingStyle = NULL;
	soap_tmp___ns1__testerMethod.ns3__testerMethod = ns3__testerMethod;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns1__testerMethod(soap, &soap_tmp___ns1__testerMethod);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__testerMethod(soap, &soap_tmp___ns1__testerMethod, "-ns1:testerMethod", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__testerMethod(soap, &soap_tmp___ns1__testerMethod, "-ns1:testerMethod", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns3__testerMethodResponse)
		return soap_closesock(soap);
	soap_default__ns3__testerMethodResponse(soap, ns3__testerMethodResponse);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get__ns3__testerMethodResponse(soap, ns3__testerMethodResponse, "ns3:testerMethodResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__ValidateGamePinSession(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct _ns3__ValidateGamePinSession *ns3__ValidateGamePinSession, struct _ns3__ValidateGamePinSessionResponse *ns3__ValidateGamePinSessionResponse)
{	struct __ns1__ValidateGamePinSession soap_tmp___ns1__ValidateGamePinSession;
	if (!soap_endpoint)
		soap_endpoint = "http://222.127.25.30:83/GameSecurityService.svc";
	if (!soap_action)
		soap_action = "http://Kill3rComboService/2010/IGameSecurityContract/ValidateGamePinSession";
	soap->encodingStyle = NULL;
	soap_tmp___ns1__ValidateGamePinSession.ns3__ValidateGamePinSession = ns3__ValidateGamePinSession;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns1__ValidateGamePinSession(soap, &soap_tmp___ns1__ValidateGamePinSession);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__ValidateGamePinSession(soap, &soap_tmp___ns1__ValidateGamePinSession, "-ns1:ValidateGamePinSession", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__ValidateGamePinSession(soap, &soap_tmp___ns1__ValidateGamePinSession, "-ns1:ValidateGamePinSession", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns3__ValidateGamePinSessionResponse)
		return soap_closesock(soap);
	soap_default__ns3__ValidateGamePinSessionResponse(soap, ns3__ValidateGamePinSessionResponse);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get__ns3__ValidateGamePinSessionResponse(soap, ns3__ValidateGamePinSessionResponse, "ns3:ValidateGamePinSessionResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__RevokeGamePinSession(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct _ns3__RevokeGamePinSession *ns3__RevokeGamePinSession, struct _ns3__RevokeGamePinSessionResponse *ns3__RevokeGamePinSessionResponse)
{	struct __ns1__RevokeGamePinSession soap_tmp___ns1__RevokeGamePinSession;
	if (!soap_endpoint)
		soap_endpoint = "http://222.127.25.30:83/GameSecurityService.svc";
	if (!soap_action)
		soap_action = "http://Kill3rComboService/2010/IGameSecurityContract/RevokeGamePinSession";
	soap->encodingStyle = NULL;
	soap_tmp___ns1__RevokeGamePinSession.ns3__RevokeGamePinSession = ns3__RevokeGamePinSession;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns1__RevokeGamePinSession(soap, &soap_tmp___ns1__RevokeGamePinSession);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__RevokeGamePinSession(soap, &soap_tmp___ns1__RevokeGamePinSession, "-ns1:RevokeGamePinSession", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__RevokeGamePinSession(soap, &soap_tmp___ns1__RevokeGamePinSession, "-ns1:RevokeGamePinSession", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns3__RevokeGamePinSessionResponse)
		return soap_closesock(soap);
	soap_default__ns3__RevokeGamePinSessionResponse(soap, ns3__RevokeGamePinSessionResponse);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get__ns3__RevokeGamePinSessionResponse(soap, ns3__RevokeGamePinSessionResponse, "ns3:RevokeGamePinSessionResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__AnswerGamePinQuestionsSuccess(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct _ns3__AnswerGamePinQuestionsSuccess *ns3__AnswerGamePinQuestionsSuccess, struct _ns3__AnswerGamePinQuestionsSuccessResponse *ns3__AnswerGamePinQuestionsSuccessResponse)
{	struct __ns1__AnswerGamePinQuestionsSuccess soap_tmp___ns1__AnswerGamePinQuestionsSuccess;
	if (!soap_endpoint)
		soap_endpoint = "http://222.127.25.30:83/GameSecurityService.svc";
	if (!soap_action)
		soap_action = "http://Kill3rComboService/2010/IGameSecurityContract/AnswerGamePinQuestionsSuccess";
	soap->encodingStyle = NULL;
	soap_tmp___ns1__AnswerGamePinQuestionsSuccess.ns3__AnswerGamePinQuestionsSuccess = ns3__AnswerGamePinQuestionsSuccess;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns1__AnswerGamePinQuestionsSuccess(soap, &soap_tmp___ns1__AnswerGamePinQuestionsSuccess);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__AnswerGamePinQuestionsSuccess(soap, &soap_tmp___ns1__AnswerGamePinQuestionsSuccess, "-ns1:AnswerGamePinQuestionsSuccess", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__AnswerGamePinQuestionsSuccess(soap, &soap_tmp___ns1__AnswerGamePinQuestionsSuccess, "-ns1:AnswerGamePinQuestionsSuccess", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns3__AnswerGamePinQuestionsSuccessResponse)
		return soap_closesock(soap);
	soap_default__ns3__AnswerGamePinQuestionsSuccessResponse(soap, ns3__AnswerGamePinQuestionsSuccessResponse);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get__ns3__AnswerGamePinQuestionsSuccessResponse(soap, ns3__AnswerGamePinQuestionsSuccessResponse, "ns3:AnswerGamePinQuestionsSuccessResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

#ifdef __cplusplus
}
#endif

#if defined(__BORLANDC__)
#pragma option pop
#pragma option pop
#endif

/* End of soapClient.c */
