// PatchReadyDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "X2ChinaLauncher.h"
#include "PatchReadyDlg.h"
#include ".\patchreadydlg.h"
#include "ServerManager.h"

// CPatchReadyDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CPatchReadyDlg, CDialog)
CPatchReadyDlg::CPatchReadyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPatchReadyDlg::IDD, pParent)
{
}

CPatchReadyDlg::~CPatchReadyDlg()
{
}

BOOL CPatchReadyDlg::OnInitDialog()
{
	GetParent()->EnableWindow(FALSE);

	return TRUE;
}
BOOL CPatchReadyDlg::PreTranslateMessage(MSG* pMsg)
{
	switch(pMsg->message)
	{
		// 키가 눌렸을때
	case WM_KEYDOWN:
		switch(pMsg->wParam)
		{
			// 리턴키\tab 
		case VK_RETURN:
			return TRUE;

			// ESC키
		case VK_ESCAPE:
			return TRUE;
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}

void CPatchReadyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPatchReadyDlg, CDialog)
	ON_WM_DESTROY()
	ON_MESSAGE(WM_CLOSE_EVENT, &CPatchReadyDlg::OnCloseEvent)
END_MESSAGE_MAP()


// CPatchReadyDlg 메시지 처리기입니다.

void CPatchReadyDlg::OnDestroy()
{
	CDialog::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	GetParent()->EnableWindow(TRUE);
}

LRESULT CPatchReadyDlg::OnCloseEvent(WPARAM wParam, LPARAM lParam)
{
	CServerManager::GetInstance()->HidePatchReadyDlg();

	return 0;
}