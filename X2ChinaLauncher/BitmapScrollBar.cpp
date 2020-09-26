#include "stdafx.h"
#include "X2ChinaLauncher.h"
#include "BitmapScrollBar.h"
#include "ServerList.h"
#include "BitmapScrollElementView.h"
//#include "BitmapScrollBarView.h"

CBitmapScrollBar::CBitmapScrollBar()
{
	m_bIsBarMove = FALSE;
	m_iBarMoveY = 0;
	//bNeedUpdate = TRUE;
	m_iBarStartY = 0;

	//m_PreRect = CRect(-1, -1, -1, -1);

	m_pOwnerBackgroundDC = NULL;
	//m_ServerFeelDlg.Create(CServerFeelDlg::IDD);
	m_pManager = NULL;
}

CBitmapScrollBar::~CBitmapScrollBar()
{
}


void CBitmapScrollBar::PreSubclassWindow()
{
	CButtonST::PreSubclassWindow();
}

void CBitmapScrollBar::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	
	//if(bNeedUpdate)
	{
		//OutputDebugString(_T("CBitmapScrollBar is DrawItem......................\n"));

	//CClientDC clDC(GetParent());
	//CDC dcScreen;
	//CBitmap bmp;

	//dcScreen.CreateCompatibleDC(&clDC);
	//bmp.LoadBitmap(IDB_SCROLLBARVIEW_BITMAP);


	//CBitmap *pOldBitmap= dcScreen.SelectObject(&bmp);


	//// get the bitmap dimensions
	//BITMAP bmpInfo;
	//bmp.GetBitmap(&bmpInfo);

	////CDC*	pDC = CDC::FromHandle(lpDrawItemStruct->hDC);
	//clDC.BitBlt(426, 526, bmpInfo.bmWidth, bmpInfo.bmHeight, &dcScreen, 0, 0, SRCCOPY);

	//dcScreen.SelectObject(pOldBitmap);

		RECT rect;
		GetWindowRect(&rect);
		GetParent()->ScreenToClient(&rect);
		CRect curRect = CRect(rect);

		CClientDC clDC(GetParent());


		if(m_PreRect.top != curRect.top)
		{
			//복원
			RestoreBackground(&clDC);
		}

		m_PreRect = rect;

		//
		//현재 부모의 배경을 저장한다.
		//StoreBackground();




	CButtonST::DrawItem(lpDrawItemStruct);

/*
	GetWindowRect(&rect);
	//m_ServerFeelDlg.SetWindowPos(this, rect.left, rect.top, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
	m_ServerFeelDlg.SetWindowPos(this, rect.left-50, rect.top, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
	m_ServerFeelDlg.ShowWindow(SW_SHOW);
*/
	//bNeedUpdate = FALSE;
	}


	////RECT rc, rc2;
	////GetClientRect(&rc);
	////rc2.left = rc.left+point.x;
	////rc2.top = rc.top+point.y;
	////rc2.right = rc.right+point.x;
	////rc2.bottom = rc.bottom+point.y;
	////MoveWindow(&rc2);
	////InvalidateRect(&rc2);

	//if(m_bIsBarMove)
	//{
	//	RECT rc;
	//	GetWindowRect(&rc);
	//	GetParent()->ScreenToClient(&rc);
	//	SetWindowPos(GetParent(), rc.left, rc.top+m_fBarMoveY, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
	//	m_bIsBarMove = FALSE;
	//}
}

BEGIN_MESSAGE_MAP(CBitmapScrollBar, CButtonST)
	//{{AFX_MSG_MAP(CBitmapScrollBar)
	ON_WM_CREATE()
	//ON_WM_PAINT()
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_ERASEBKGND()
	//ON_WM_WINDOWPOSCHANGED()
	//}}AFX_MSG_MAP

	//ON_MESSAGE(WM_MOUSELEAVE, OnMouseLeave)

END_MESSAGE_MAP()

int CBitmapScrollBar::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	RECT rc;
	GetWindowRect(&rc);
	GetParent()->ScreenToClient(&rc);

	m_PreRect = rc;

	//현재 부모의 배경을 저장한다.
	//StoreBackground();

	return CWnd::OnCreate(lpCreateStruct);
}

void CBitmapScrollBar::OnTimer(UINT nIDEvent)
{
	if(nIDEvent == 1)
	{
		if(m_bIsBarMove && m_iBarMoveY != 0/* && abs(m_iBarMoveY)>0*//* && !bNeedUpdate*/)
		{
			CRect MyRect, ViewRect;
			GetWindowRect(&MyRect);
			GetParent()->ScreenToClient(&MyRect);
			GetParent()->GetClientRect(&ViewRect);

			MyRect.top += m_iBarMoveY;
			MyRect.bottom += m_iBarMoveY;

			if(MyRect.top < ViewRect.top)
				MyRect.top = ViewRect.top;

			if(MyRect.bottom > ViewRect.bottom)
				MyRect.top = ViewRect.bottom - MyRect.Height();

			SetWindowPos(GetParent(), MyRect.left, MyRect.top, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

			BOOL bUp;
			if(m_iBarMoveY>0)
				bUp = TRUE;
			else
				bUp = FALSE;

			//bar move offsetY로 부터 버튼들이 움직일 량을 계산
			int temp = m_pManager->CalcElementButtonMove(MyRect.top);
			m_pManager->GetScrollView()->NotifyScroll(temp, bUp);
			//OutputDebugString(_T("scroll bar is OnTimer......................\n"));
		}
	}

}

void CBitmapScrollBar::OnLButtonDown(UINT nFlags, CPoint point)
{
	OutputDebugString(_T("scroll bar is OnLButtonDown......................\n"));

	//if(nFlags & MK_LBUTTON)
	//	m_bIsPressed = TRUE;
	//else
	//	m_bIsPressed = FALSE;

	//if(m_bIsPressed)
	//{
	//	if(!m_bIsBarMove)
	//	{
	//		m_iBarStartY = point.y;
	//		m_bIsBarMove = TRUE;
	//	}

	//	RECT rc;
	//	GetClientRect(&rc);

	//	m_iBarMoveY = point.y - m_iBarStartY;

	//	WCHAR buf[200];
	//	wsprintf(buf, _T("bar move y = %d\n"), point.y);
	//	//OutputDebugString(_T("scroll bar is pressed......................\n"));
	//	//OutputDebugString(buf);
	//}
	//else
	//{
	//	m_iBarMoveY = 0;

	//	m_bIsBarMove = FALSE;


	//}

	CButton::OnLButtonDown(nFlags, point);

	//TRACKMOUSEEVENT		csTME;
	//csTME.cbSize = sizeof(csTME);
	//csTME.dwFlags = TME_LEAVE;
	//csTME.hwndTrack = m_hWnd;
	//::_TrackMouseEvent(&csTME);
}

void CBitmapScrollBar::OnLButtonUp(UINT nFlags, CPoint point)
{
	OutputDebugString(_T("scroll bar is OnLButtonUp......................\n"));

	KillTimer(1);

	m_iBarMoveY = 0;

	m_bIsBarMove = FALSE;


	CButton::OnLButtonDown(nFlags, point);
}

void CBitmapScrollBar::OnMouseMove(UINT nFlags, CPoint point)
{
	//OutputDebugString(_T("scroll bar is OnMouseMove......................\n"));

	if(nFlags & MK_LBUTTON)
		m_bIsPressed = TRUE;
	else
		m_bIsPressed = FALSE;

	if(m_bIsPressed && m_pManager->IsEnableScrollBar())
	{
		if(!m_bIsBarMove)
		{

			SetTimer(1, 0, 0);

			m_iBarStartY = point.y;
			m_bIsBarMove = TRUE;
		}
		
		RECT rc;
		GetClientRect(&rc);

		m_iBarMoveY = point.y - m_iBarStartY;

		WCHAR buf[200];
		wsprintf(buf, _T("bar move y = %d\n"), point.y);
		//OutputDebugString(_T("scroll bar is pressed......................\n"));
		//OutputDebugString(buf);

		//if(point.y)
		//{
		//	m_pManager->GetScrollView()->NotifyScroll(temp);
		//}
	}
	

	CButton::OnMouseMove(nFlags, point);

	//TRACKMOUSEEVENT		csTME;
	//csTME.cbSize = sizeof(csTME);
	//csTME.dwFlags = TME_LEAVE;
	//csTME.hwndTrack = m_hWnd;
	//::_TrackMouseEvent(&csTME);

} // End of OnMouseMove

BOOL CBitmapScrollBar::OnEraseBkgnd(CDC* pDC)
{
	//OutputDebugString(_T("scroll bar is OnEraseBkgnd......................\n"));

	return TRUE;
	//return CButtonST::OnEraseBkgnd(pDC);
}

//void CBitmapScrollBar::OnPaint()
//{
//	OutputDebugString(_T("CBitmapScrollBar::OnPaint()......................\n"));
//	CButtonST::OnPaint();
//	//CPaintDC dc(this); // device context for painting
//	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
//	// 그리기 메시지에 대해서는 CDialog::OnPaint()을(를) 호출하지 마십시오.
//
//
//	// 흰 색으로 칠해주마
//	//dc.FloodFill(0, 0, RGB(100, 0, 100));
//
//	//RECT rc;
//	//GetClientRect(&rc);
//	//dc.FillSolidRect(&rc, RGB(255, 255, 255));
//
//	//RECT rc = {0, 0, 100, 100};
//	//DrawText(m_StartButton.GetDC()->m_hDC, "hohohoho", -1, &rc, DT_CENTER);
//	////m_StartButton.TextOut()
//	////TextOut();
//
//	//SendMessage(WM_LOADSERVERLIST);
//}

//LRESULT CBitmapScrollBar::OnMouseLeave(WPARAM wParam, LPARAM lParam)
//{
//	m_bIsBarMove = FALSE;
//
//	return 0;
//}

//void CBitmapScrollBar::OnWindowPosChanged(WINDOWPOS* lpwndpos)
//{
//	OutputDebugString(_T("CBitmapScrollBar::OnWindowPosChanged()......................\n"));
//
//	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
//	//CPaintDC dc(this); // device context for painting
//}


void CBitmapScrollBar::RestoreBackground(CDC* pParentDC)
{
	pParentDC->BitBlt(m_PreRect.left, m_PreRect.top, m_PreRect.Width(), m_PreRect.Height(), m_pOwnerBackgroundDC, 0, 0, SRCCOPY);
}