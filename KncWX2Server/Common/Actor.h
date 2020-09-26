#pragma once

#include "Socket/Session.h"
#include "FSM/support_FSM.h"

SmartPointer(KActor);

class KActor : public KSession
{
    NiDeclareRTTI;
    DeclToStringW;
    DeclareFSM_MT;

public:
    KActor();
    virtual ~KActor();

protected:
};
