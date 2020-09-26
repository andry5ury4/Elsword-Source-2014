/* soapAccessTokenSoapProxy.h
   Generated by gSOAP 2.8.15 from nx_soap.h

Copyright(C) 2000-2013, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under ONE of the following licenses:
GPL or Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#ifndef soapAccessTokenSoapProxy_H
#define soapAccessTokenSoapProxy_H
#include "soapH.h"

class SOAP_CMAC AccessTokenSoapProxy : public soap
{ public:
	/// Endpoint URL of service 'AccessTokenSoapProxy' (change as needed)
	const char *soap_endpoint;
	/// Constructor
	AccessTokenSoapProxy();
	/// Construct from another engine state
	AccessTokenSoapProxy(const struct soap&);
	/// Constructor with endpoint URL
	AccessTokenSoapProxy(const char *url);
	/// Constructor with engine input+output mode control
	AccessTokenSoapProxy(soap_mode iomode);
	/// Constructor with URL and input+output mode control
	AccessTokenSoapProxy(const char *url, soap_mode iomode);
	/// Constructor with engine input and output mode control
	AccessTokenSoapProxy(soap_mode imode, soap_mode omode);
	/// Destructor frees deserialized data
	virtual	~AccessTokenSoapProxy();
	/// Initializer used by constructors
	virtual	void AccessTokenSoapProxy_init(soap_mode imode, soap_mode omode);
	/// Delete all deserialized data (with soap_destroy and soap_end)
	virtual	void destroy();
	/// Delete all deserialized data and reset to default
	virtual	void reset();
	/// Disables and removes SOAP Header from message
	virtual	void soap_noheader();
	/// Get SOAP Header structure (NULL when absent)
	virtual	const SOAP_ENV__Header *soap_header();
	/// Get SOAP Fault structure (NULL when absent)
	virtual	const SOAP_ENV__Fault *soap_fault();
	/// Get SOAP Fault string (NULL when absent)
	virtual	const char *soap_fault_string();
	/// Get SOAP Fault detail as string (NULL when absent)
	virtual	const char *soap_fault_detail();
	/// Close connection (normally automatic, except for send_X ops)
	virtual	int soap_close_socket();
	/// Force close connection (can kill a thread blocked on IO)
	virtual	int soap_force_close_socket();
	/// Print fault
	virtual	void soap_print_fault(FILE*);
#ifndef WITH_LEAN
	/// Print fault to stream
#ifndef WITH_COMPAT
	virtual	void soap_stream_fault(std::ostream&);
#endif

	/// Put fault into buffer
	virtual	char *soap_sprint_fault(char *buf, size_t len);
#endif

	/// Web service operation 'GetGameAccessToken' (returns error code or SOAP_OK)
	virtual	int GetGameAccessToken(_ns2__GetGameAccessToken *ns2__GetGameAccessToken, _ns2__GetGameAccessTokenResponse *ns2__GetGameAccessTokenResponse) { return this->GetGameAccessToken(NULL, NULL, ns2__GetGameAccessToken, ns2__GetGameAccessTokenResponse); }
	virtual	int GetGameAccessToken(const char *endpoint, const char *soap_action, _ns2__GetGameAccessToken *ns2__GetGameAccessToken, _ns2__GetGameAccessTokenResponse *ns2__GetGameAccessTokenResponse);

	/// Web service operation 'GetGameAccessToken' (returns error code or SOAP_OK)
	virtual	int GetGameAccessToken_(_ns2__GetGameAccessToken *ns2__GetGameAccessToken, _ns2__GetGameAccessTokenResponse *ns2__GetGameAccessTokenResponse) { return this->GetGameAccessToken_(NULL, NULL, ns2__GetGameAccessToken, ns2__GetGameAccessTokenResponse); }
	virtual	int GetGameAccessToken_(const char *endpoint, const char *soap_action, _ns2__GetGameAccessToken *ns2__GetGameAccessToken, _ns2__GetGameAccessTokenResponse *ns2__GetGameAccessTokenResponse);
};
#endif
