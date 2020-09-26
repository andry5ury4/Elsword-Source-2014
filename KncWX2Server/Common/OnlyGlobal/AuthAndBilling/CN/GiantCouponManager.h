#pragma once

#include "GiantBaseManager.h"
#include "GiantBillingPacket.h"

#ifdef SERV_COUNTRY_CN

class KGiantCouponManager : public KGiantBaseManager
{
	DeclDump;
	DeclToStringW;
	DeclPfID;
	DeclareSingleton( KGiantCouponManager );

protected:
	KGiantCouponManager();

public:
	
	virtual ~KGiantCouponManager();

	virtual void RegToLua();

	// derived from KThreadManager
	virtual KThread* CreateThread();
	
	template < class T > void SendToGSUser( UidType nGS, UidType nTo, unsigned short usEventID, const T& data );

protected:

	virtual void MakeEventFromReceivedPacket();


	virtual void Handle_OnCommonPacket(KGiantCommonPacket& kReceivedPacket);
	void Handle_OnLoginPacket(KGiantBillingPacket& kReceivedPacket);
	void Handle_OnBillingPacket(KGiantBillingPacket& kReceivedPacket);

protected:


};

DefSingletonInline( KGiantCouponManager );

#endif // SERV_COUNTRY_CN