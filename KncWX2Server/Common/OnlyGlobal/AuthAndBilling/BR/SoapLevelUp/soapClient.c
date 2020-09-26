/* soapClient.c
   Generated by gSOAP 2.8.0 from lv_soap.h
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

SOAP_SOURCE_STAMP("@(#) soapClient.c ver 2.8.0 2013-06-28 13:32:08 GMT")


SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__Authenticate(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct _ns1__Authenticate *ns1__Authenticate, struct _ns1__AuthenticateResponse *ns1__AuthenticateResponse)
{	struct __ns1__Authenticate soap_tmp___ns1__Authenticate;
	if (!soap_endpoint)
		soap_endpoint = "http://auth.elsword.levelup.com.br/AuthenticationService.svc/soap";
	if (!soap_action)
		soap_action = "http://tempuri.org/IAuthenticationService/Authenticate";
	soap->encodingStyle = NULL;
	soap_tmp___ns1__Authenticate.ns1__Authenticate = ns1__Authenticate;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns1__Authenticate(soap, &soap_tmp___ns1__Authenticate);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__Authenticate(soap, &soap_tmp___ns1__Authenticate, "-ns1:Authenticate", NULL)
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
	 || soap_put___ns1__Authenticate(soap, &soap_tmp___ns1__Authenticate, "-ns1:Authenticate", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns1__AuthenticateResponse)
		return soap_closesock(soap);
	soap_default__ns1__AuthenticateResponse(soap, ns1__AuthenticateResponse);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get__ns1__AuthenticateResponse(soap, ns1__AuthenticateResponse, "ns1:AuthenticateResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__Block(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct _ns1__Block *ns1__Block, struct _ns1__BlockResponse *ns1__BlockResponse)
{	struct __ns1__Block soap_tmp___ns1__Block;
	if (!soap_endpoint)
		soap_endpoint = "http://auth.elsword.levelup.com.br/AuthenticationService.svc/soap";
	if (!soap_action)
		soap_action = "http://tempuri.org/IAuthenticationService/Block";
	soap->encodingStyle = NULL;
	soap_tmp___ns1__Block.ns1__Block = ns1__Block;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns1__Block(soap, &soap_tmp___ns1__Block);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__Block(soap, &soap_tmp___ns1__Block, "-ns1:Block", NULL)
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
	 || soap_put___ns1__Block(soap, &soap_tmp___ns1__Block, "-ns1:Block", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns1__BlockResponse)
		return soap_closesock(soap);
	soap_default__ns1__BlockResponse(soap, ns1__BlockResponse);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get__ns1__BlockResponse(soap, ns1__BlockResponse, "ns1:BlockResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__BlockLockAccount(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct _ns1__BlockLockAccount *ns1__BlockLockAccount, struct _ns1__BlockLockAccountResponse *ns1__BlockLockAccountResponse)
{	struct __ns1__BlockLockAccount soap_tmp___ns1__BlockLockAccount;
	if (!soap_endpoint)
		soap_endpoint = "http://auth.elsword.levelup.com.br/AuthenticationService.svc/soap";
	if (!soap_action)
		soap_action = "http://tempuri.org/IAuthenticationService/BlockLockAccount";
	soap->encodingStyle = NULL;
	soap_tmp___ns1__BlockLockAccount.ns1__BlockLockAccount = ns1__BlockLockAccount;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns1__BlockLockAccount(soap, &soap_tmp___ns1__BlockLockAccount);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__BlockLockAccount(soap, &soap_tmp___ns1__BlockLockAccount, "-ns1:BlockLockAccount", NULL)
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
	 || soap_put___ns1__BlockLockAccount(soap, &soap_tmp___ns1__BlockLockAccount, "-ns1:BlockLockAccount", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns1__BlockLockAccountResponse)
		return soap_closesock(soap);
	soap_default__ns1__BlockLockAccountResponse(soap, ns1__BlockLockAccountResponse);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get__ns1__BlockLockAccountResponse(soap, ns1__BlockLockAccountResponse, "ns1:BlockLockAccountResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__BlockWithExpiration(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct _ns1__BlockWithExpiration *ns1__BlockWithExpiration, struct _ns1__BlockWithExpirationResponse *ns1__BlockWithExpirationResponse)
{	struct __ns1__BlockWithExpiration soap_tmp___ns1__BlockWithExpiration;
	if (!soap_endpoint)
		soap_endpoint = "http://auth.elsword.levelup.com.br/AuthenticationService.svc/soap";
	if (!soap_action)
		soap_action = "http://tempuri.org/IAuthenticationService/BlockWithExpiration";
	soap->encodingStyle = NULL;
	soap_tmp___ns1__BlockWithExpiration.ns1__BlockWithExpiration = ns1__BlockWithExpiration;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns1__BlockWithExpiration(soap, &soap_tmp___ns1__BlockWithExpiration);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__BlockWithExpiration(soap, &soap_tmp___ns1__BlockWithExpiration, "-ns1:BlockWithExpiration", NULL)
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
	 || soap_put___ns1__BlockWithExpiration(soap, &soap_tmp___ns1__BlockWithExpiration, "-ns1:BlockWithExpiration", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns1__BlockWithExpirationResponse)
		return soap_closesock(soap);
	soap_default__ns1__BlockWithExpirationResponse(soap, ns1__BlockWithExpirationResponse);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get__ns1__BlockWithExpirationResponse(soap, ns1__BlockWithExpirationResponse, "ns1:BlockWithExpirationResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__Unblock(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct _ns1__Unblock *ns1__Unblock, struct _ns1__UnblockResponse *ns1__UnblockResponse)
{	struct __ns1__Unblock soap_tmp___ns1__Unblock;
	if (!soap_endpoint)
		soap_endpoint = "http://auth.elsword.levelup.com.br/AuthenticationService.svc/soap";
	if (!soap_action)
		soap_action = "http://tempuri.org/IAuthenticationService/Unblock";
	soap->encodingStyle = NULL;
	soap_tmp___ns1__Unblock.ns1__Unblock = ns1__Unblock;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns1__Unblock(soap, &soap_tmp___ns1__Unblock);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__Unblock(soap, &soap_tmp___ns1__Unblock, "-ns1:Unblock", NULL)
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
	 || soap_put___ns1__Unblock(soap, &soap_tmp___ns1__Unblock, "-ns1:Unblock", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns1__UnblockResponse)
		return soap_closesock(soap);
	soap_default__ns1__UnblockResponse(soap, ns1__UnblockResponse);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get__ns1__UnblockResponse(soap, ns1__UnblockResponse, "ns1:UnblockResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__UnblockLockAccount(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct _ns1__UnblockLockAccount *ns1__UnblockLockAccount, struct _ns1__UnblockLockAccountResponse *ns1__UnblockLockAccountResponse)
{	struct __ns1__UnblockLockAccount soap_tmp___ns1__UnblockLockAccount;
	if (!soap_endpoint)
		soap_endpoint = "http://auth.elsword.levelup.com.br/AuthenticationService.svc/soap";
	if (!soap_action)
		soap_action = "http://tempuri.org/IAuthenticationService/UnblockLockAccount";
	soap->encodingStyle = NULL;
	soap_tmp___ns1__UnblockLockAccount.ns1__UnblockLockAccount = ns1__UnblockLockAccount;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns1__UnblockLockAccount(soap, &soap_tmp___ns1__UnblockLockAccount);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__UnblockLockAccount(soap, &soap_tmp___ns1__UnblockLockAccount, "-ns1:UnblockLockAccount", NULL)
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
	 || soap_put___ns1__UnblockLockAccount(soap, &soap_tmp___ns1__UnblockLockAccount, "-ns1:UnblockLockAccount", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns1__UnblockLockAccountResponse)
		return soap_closesock(soap);
	soap_default__ns1__UnblockLockAccountResponse(soap, ns1__UnblockLockAccountResponse);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get__ns1__UnblockLockAccountResponse(soap, ns1__UnblockLockAccountResponse, "ns1:UnblockLockAccountResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__GetSalt(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct _ns1__GetSalt *ns1__GetSalt, struct _ns1__GetSaltResponse *ns1__GetSaltResponse)
{	struct __ns1__GetSalt soap_tmp___ns1__GetSalt;
	if (!soap_endpoint)
		soap_endpoint = "http://auth.elsword.levelup.com.br/AuthenticationService.svc/soap";
	if (!soap_action)
		soap_action = "http://tempuri.org/IAuthenticationService/GetSalt";
	soap->encodingStyle = NULL;
	soap_tmp___ns1__GetSalt.ns1__GetSalt = ns1__GetSalt;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns1__GetSalt(soap, &soap_tmp___ns1__GetSalt);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__GetSalt(soap, &soap_tmp___ns1__GetSalt, "-ns1:GetSalt", NULL)
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
	 || soap_put___ns1__GetSalt(soap, &soap_tmp___ns1__GetSalt, "-ns1:GetSalt", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns1__GetSaltResponse)
		return soap_closesock(soap);
	soap_default__ns1__GetSaltResponse(soap, ns1__GetSaltResponse);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get__ns1__GetSaltResponse(soap, ns1__GetSaltResponse, "ns1:GetSaltResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__IsBlocked(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct _ns1__IsBlocked *ns1__IsBlocked, struct _ns1__IsBlockedResponse *ns1__IsBlockedResponse)
{	struct __ns1__IsBlocked soap_tmp___ns1__IsBlocked;
	if (!soap_endpoint)
		soap_endpoint = "http://auth.elsword.levelup.com.br/AuthenticationService.svc/soap";
	if (!soap_action)
		soap_action = "http://tempuri.org/IAuthenticationService/IsBlocked";
	soap->encodingStyle = NULL;
	soap_tmp___ns1__IsBlocked.ns1__IsBlocked = ns1__IsBlocked;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns1__IsBlocked(soap, &soap_tmp___ns1__IsBlocked);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__IsBlocked(soap, &soap_tmp___ns1__IsBlocked, "-ns1:IsBlocked", NULL)
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
	 || soap_put___ns1__IsBlocked(soap, &soap_tmp___ns1__IsBlocked, "-ns1:IsBlocked", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns1__IsBlockedResponse)
		return soap_closesock(soap);
	soap_default__ns1__IsBlockedResponse(soap, ns1__IsBlockedResponse);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get__ns1__IsBlockedResponse(soap, ns1__IsBlockedResponse, "ns1:IsBlockedResponse", "");
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
