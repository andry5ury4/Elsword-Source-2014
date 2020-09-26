#include "MatchUserFSM.h"
#include "FSM/FSMstate.h"

#undef _ENUM
#define _ENUM( id ) L"KMatchUserFSM::" L ## #id,
const wchar_t*  KMatchUserFSM::ms_szState[] = { 
#   include "MatchUserFSMState_def.h" 
};

const wchar_t*  KMatchUserFSM::ms_szInput[] = { 
#   include "MatchUserFSMInput_def.h" 
};

KMatchUserFSM::KMatchUserFSM() : FSMclass( KMatchUserFSM::S_INIT )
{
    // S_INIT
    FSMstate* pState = new FSMstate( S_INIT, 1 );
	pState->AddTransition( I_TO_ACCEPTED,		S_ACCEPTED );	
    AddState( pState );

    // S_ACCEPTED
    pState = new FSMstate( S_ACCEPTED, 2 );
    pState->AddTransition( I_TO_INIT,           S_INIT );
    pState->AddTransition( I_TO_UPDATED_INFO,	S_UPDATED_INFO );
    AddState( pState );

    // S_UPDATED_INFO
    pState = new FSMstate( S_UPDATED_INFO, 2 );
	pState->AddTransition( I_TO_INIT,			S_INIT );
    pState->AddTransition( I_TO_PLAY,			S_PLAY );
    AddState( pState );

	// S_PLAY
	pState = new FSMstate( S_PLAY, 1 );
	pState->AddTransition( I_TO_INIT,			S_INIT );
	AddState( pState );
}

KMatchUserFSM::~KMatchUserFSM()
{
}

const wchar_t* KMatchUserFSM::GetStateIDString(int iStateID_) const
{
    return ms_szState[iStateID_];
}

const wchar_t* KMatchUserFSM::GetInputIDString(int iInputID_) const
{
    return ms_szInput[iInputID_];
}