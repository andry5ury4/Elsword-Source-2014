#pragma once

#include "ByteStream.h"
#include "ToString.h"
#include "SADatabase.h"

NAMESPACE_BEGIN( KncSecurity )

class KSecurityAssociation;

class KSecureBuffer
{
    DeclToStringA;

public:
    KSecureBuffer( SpiType nSPI );                                  // for sender
    KSecureBuffer( const KSecureBuffer& buf );                      // for... for test -_-;
    KSecureBuffer( SpiType nSPI, const void* pRecvData, unsigned long nBytes );   // for receiver
    KSecureBuffer& operator=( const KSecureBuffer& );
    ~KSecureBuffer();

    bool Create( const KByteStream& );
    bool Create( const void*, unsigned long nBytes );
    //void Set( const KByteStream& );
    bool IsAuthentic() const;   // GePayload()에서 한번 호출됨. 외부에서 불릴 수 있음
    bool GetPayload( KByteStream& payload ) const;
    bool GetPayload( char*, int* );
    void SetAccepted();

	//////////////////////////////////////////////////////////////////////////
	//{{ 2009. 10. 15  최육사	Sequence Number ( not have replay window mask )
	bool Create_notRWM( const KByteStream& );
	bool IsAuthentic_notRWM( bool bCheckSequenceNum = true ); // GePayload()에서 한번 호출됨. 외부에서 불릴 수 있음
	bool GetPayload_notRWM( KByteStream& payload, bool bAuthentic = true, bool bCheckSequenceNum = true );
	//}}
	//////////////////////////////////////////////////////////////////////////
    const char* GetDataPtr() const;     // for SOCKET I/O function.
    unsigned long GetSize() const;

	//{{
	//////////////////////////////////////////////////////////////////////////
	// SADatabase 를 Session 객체의 맴버로 사용 하기 위하여 추가된 변수
	//////////////////////////////////////////////////////////////////////////
	bool Create_Local( const void* pData, unsigned long nBytes, KSADatabase* pSADatabase );
	bool Create_Local( const KByteStream& payload, KSADatabase* pSADatabase );
	bool GetPayload_Local( KByteStream& payload, KSADatabase* pSADatabase );
	bool GetPayload_Local( char* pPayload, int* pnBytes, KSADatabase* pSADatabase );
	void SetAccepted_Local( KSADatabase* pSADatabase );
	bool Create_notRWM_Local( const KByteStream& payload, KSADatabase* pSADatabase );
	bool IsAuthentic_notRWM_Local( bool bCheckSequenceNum /*= true*/, KSADatabase* pSADatabase );
	bool GetPayload_notRWM_Local( KByteStream& payload, bool bAuthentic /*= true*/, bool bCheckSequenceNum /*= true*/, KSADatabase* pSADatabase );
	void GenerateIV_Local( KByteStream& bsIV_, KSADatabase* pSADatabase ) const;
	KByteStream GenerateCrypt_Local( const KByteStream& payload, const KByteStream& iv, KSADatabase* pSADatabase ) const;
	KByteStream GeneratePadding_Local( const KByteStream& payload, KSADatabase* pSADatabase ) const;
	KByteStream GenerateICV_Local( const KByteStream& auth, KSADatabase* pSADatabase ) const;
	unsigned long GetMaxSecureSize_Local( const KByteStream& payload, KSADatabase* pSADatabase ) const;
	unsigned long GetMaxPadSize_Local( const KByteStream& payload, KSADatabase* pSADatabase ) const;
	inline bool IsValidSize_Local( KSADatabase* pSADatabase ) const;
	inline bool IsValidSPIndex_Local( SpiType& nSPIndex, KSADatabase* pSADatabase ) const;
	inline bool IsValidSequenceNum_Local( SeqType& nSequenceNum, KSADatabase* pSADatabase ) const;
	inline bool IsValidSequenceNum_notRWM_Local( SeqType& nSequenceNum, KSADatabase* pSADatabase );
	inline bool IsValidICV_Local( KSADatabase* pSADatabase ) const;
	bool IsAuthentic_Local( KSADatabase* pSADatabase );
	//////////////////////////////////////////////////////////////////////////
	// SADatabase 를 Session 객체의 맴버로 사용 하기 위하여 추가된 변수
	//////////////////////////////////////////////////////////////////////////
	//}}

private:
    KSecurityAssociation& GetSA();
    const KSecurityAssociation& GetSA() const;

    void GenerateIV( OUT KByteStream& bsIV ) const;
    KByteStream GenerateCrypt( const KByteStream& payload, const KByteStream& iv ) const;
    KByteStream GeneratePadding( const KByteStream& payload ) const;
    KByteStream GenerateICV( const KByteStream& auth ) const;

    unsigned long GetMaxSecureSize( const KByteStream& payload ) const;
    unsigned long GetMaxPadSize( const KByteStream& payload ) const;

	// 기본 SPIndex인지 검사
	inline bool IsDefaultSPIndex() const { return ( m_nSPIndex == 0 ); }
    // 데이터가 최소요구 사이즈 이상인지 확인한다.
    inline bool IsValidSize() const;
    // 데이터에서 SPI를 얻어오면서, 현재 SADB에 있는 SPI인지 확인한다.
    inline bool IsValidSPIndex( SpiType& nSPIndex ) const;
    // 데이터에서 SeqNumber를 얻어오면서, 값이 올바른지 확인한다.
    inline bool IsValidSequenceNum( SeqType& nSequenceNum ) const;
	//{{ 2009. 10. 15  최육사	LastSequenceNum검증
	inline bool IsValidSequenceNum_notRWM( SeqType& nSequenceNum );
	//}}
    // 데이터에서 얻은 ICV와 새로 계산한 ICV를 비교한다.
    inline bool IsValidICV() const;

    bool IsValidPadding( const KByteStream& payload, unsigned long& nPadBytes ) const;

private:
    KByteStream             m_bsBuf;
    mutable SpiType         m_nSPIndex;  // Security Parameters Index
};

DeclOstmOperatorA( KSecureBuffer );
DeclOstmOperatorW( KByteStream );

NAMESPACE_END
