#include "stdafx.h"
#include "X2ChinaLauncher.h"
#include "BitmapScrollElement.h"
#include "ServerManager.h"
#include "PngWindow/PngWindow.h"
//#include <atlimage.h>
#include "BitmapScrollElementView.h"

CBitmapScrollElement::CBitmapScrollElement()
{
	//m_uiID = 0;

	m_bHotBmp = FALSE;
	m_bNewBmp = FALSE;
	m_bOpenBmp = FALSE;


	m_pOwnerBackgroundDC = NULL;
	//m_ServerFeelDlg.Create(CServerFeelDlg::IDD);
	m_PreOffsetY = 0;
}

CBitmapScrollElement::~CBitmapScrollElement()
{
}

//BOOL CBitmapScrollElement::Create(LPCTSTR lpszCaption, DWORD dwStyle, 	const RECT& rect, CWnd* pParentWnd, UINT nID)
//{
//	//m_PreOffsetY = rect.top;
//
//	return CButtonST::Create(lpszCaption, dwStyle, rect, pParentWnd, nID);
//}

void CBitmapScrollElement::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	//OutputDebugString(_T("CBitmapScrollElement is DrawItem......................\n"));

	if(lpDrawItemStruct->itemState & ODS_SELECTED)
	{
		CString sTitle;
		GetWindowText(sTitle);

		CServerManager::GetInstance()->SetSelectedServer(sTitle.GetBuffer());
	}

	
	//if(m_uiID == 0)
	//{
		//CClientDC clDC(GetParent());
		//CDC dcScreen;
		//CBitmap bmp;

		//dcScreen.CreateCompatibleDC(&clDC);
		//bmp.LoadBitmap(IDB_SCROLLELEMENTVIEW_BITMAP);


		//CBitmap *pOldBitmap= dcScreen.SelectObject(&bmp);


		//// get the bitmap dimensions
		//BITMAP bmpInfo;
		//bmp.GetBitmap(&bmpInfo);

		////CDC*	pDC = CDC::FromHandle(lpDrawItemStruct->hDC);
		////clDC.BitBlt(451, 530, bmpInfo.bmWidth, bmpInfo.bmHeight, &dcScreen, 0, 0, SRCCOPY);
		//clDC.BitBlt(0, 0, bmpInfo.bmWidth, bmpInfo.bmHeight, &dcScreen, 0, 0, SRCCOPY);

		//dcScreen.SelectObject(pOldBitmap);
	//}
	//
	//lpDrawItemStruct->hDC = clDC.m_hDC;

	RECT rect;
	GetWindowRect(&rect);
	GetParent()->ScreenToClient(&rect);
	CRect curRect = CRect(rect);

	CClientDC clDC(GetParent());

	//if(m_PreRect.top == curRect.top)
	//{
	//	CButtonST::DrawItem(lpDrawItemStruct);
	//	return;
	//}


	if(m_PreOffsetY != curRect.top)
	{
		//복원
		RestoreBackground(&clDC);
	}

	m_PreOffsetY = curRect.top;

	CButtonST::DrawItem(lpDrawItemStruct);

	//hot, new 표시
	BITMAP bmpInfo;

	if(m_bHotBmp)
	{
		m_bmpHot.GetBitmap(&bmpInfo);
		::TransparentBlt(GetDC()->m_hDC, m_ptHotbmpPos.x, m_ptHotbmpPos.y, m_szHotBmpSize.cx, m_szHotBmpSize.cy, m_dcHot.m_hDC, 0, 0, bmpInfo.bmWidth, bmpInfo.bmHeight, RGB(255, 0, 255));
	}
	else if(m_bNewBmp)
	{
		m_bmpNew.GetBitmap(&bmpInfo);
		::TransparentBlt(GetDC()->m_hDC, m_ptNewbmpPos.x, m_ptNewbmpPos.y, m_szNewBmpSize.cx, m_szNewBmpSize.cy, m_dcNew.m_hDC, 0, 0, bmpInfo.bmWidth, bmpInfo.bmHeight, RGB(255, 0, 255));
	}
	else if(m_bOpenBmp)
	{
		m_bmpOpen.GetBitmap(&bmpInfo);
		::TransparentBlt(GetDC()->m_hDC, m_ptOpenbmpPos.x, m_ptOpenbmpPos.y, m_szOpenBmpSize.cx, m_szOpenBmpSize.cy, m_dcOpen.m_hDC, 0, 0, bmpInfo.bmWidth, bmpInfo.bmHeight, RGB(255, 0, 255));
	}
}

BEGIN_MESSAGE_MAP(CBitmapScrollElement, CButtonST)
	//{{AFX_MSG_MAP(CBitmapScrollElement)
	//ON_MESSAGE(WM_LBUTTONDBLCLK, OnLButtonDblClk)
	ON_WM_CREATE()
	ON_WM_ERASEBKGND()
	//ON_WM_LBUTTONDOWN()
	//ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
	
END_MESSAGE_MAP()

int CBitmapScrollElement::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	RECT rc;
	GetWindowRect(&rc);
	GetParent()->ScreenToClient(&rc);

	m_PreOffsetY = rc.top;

	//현재 부모의 배경을 저장한다.
	//StoreBackground();

	return CWnd::OnCreate(lpCreateStruct);
}

BOOL CBitmapScrollElement::OnEraseBkgnd(CDC* pDC)
{
	return TRUE;
}


void CBitmapScrollElement::RestoreBackground(CDC* pParentDC)
{
	RECT rect;
	GetWindowRect(&rect);
	GetParent()->ScreenToClient(&rect);
	CRect curRect = CRect(rect);

	//버튼 이미지를 보고 아래 상수들 설정해야 최적화가 된다.
	pParentDC->BitBlt(curRect.left, curRect.top+1, 10, 25, m_pOwnerBackgroundDC, curRect.left, curRect.top+1, SRCCOPY);
	pParentDC->BitBlt(curRect.left+129, curRect.top+1, 10, 25, m_pOwnerBackgroundDC, curRect.left+129, curRect.top+1, SRCCOPY);
	pParentDC->BitBlt(curRect.left, curRect.top-4, curRect.Width(), 5, m_pOwnerBackgroundDC, curRect.left, curRect.top-4, SRCCOPY);
	pParentDC->BitBlt(curRect.left, curRect.top+26, curRect.Width(), 5, m_pOwnerBackgroundDC, curRect.left, curRect.top+26, SRCCOPY);

#if 0
	//test
	{
		CClientDC dcScreen(GetParent());

		CString sTitle;
		GetWindowText(sTitle);

		if(sTitle == _T("时空争雄"))
		{
			int i=0;
			dcScreen.BitBlt(m_PreRect.left-400, m_PreRect.top, m_PreRect.Width(), m_PreRect.Height(), &m_dcRestore, 0, 0, SRCCOPY);
		}
	}
	
#endif

}

/*void CBitmapScrollElement::OnLButtonDown(UINT nFlags, CPoint point)
{
	CButton::OnLButtonDown(nFlags, point);
	RedrawWindow();
}

void CBitmapScrollElement::OnMouseMove(UINT nFlags, CPoint point)
{
	CButton::OnMouseMove(nFlags, point);
}*/

void CBitmapScrollElement::PrepareServerFeel(const BOOL bHot, const CPoint& ptHotOffset, const CSize& ptHotSize, 
																const BOOL bNew, const CPoint& ptNewOffset, const CSize& ptNewSize,
																const BOOL bOpen, const CPoint& ptOpenOffset, const CSize& ptOpenSize )
{
	if(bHot)
	{
		m_dcHot.CreateCompatibleDC(GetDC());
		m_bmpHot.LoadBitmap(IDB_HOT_BITMAP);
		m_dcHot.SelectObject(&m_bmpHot);

		m_ptHotbmpPos = ptHotOffset;
		m_szHotBmpSize = ptHotSize;
	}
	else if(bNew)
	{
		m_dcNew.CreateCompatibleDC(GetDC());
		m_bmpNew.LoadBitmap(IDB_NEW_BITMAP);
		m_dcNew.SelectObject(&m_bmpNew);

		m_ptNewbmpPos = ptNewOffset;
		m_szNewBmpSize = ptNewSize;
	}
	else if(bOpen)
	{

		m_dcOpen.CreateCompatibleDC(GetDC());
		m_bmpOpen.LoadBitmap(IDB_OPEN_BITMAP);
		m_dcOpen.SelectObject(&m_bmpOpen);

		m_ptOpenbmpPos = ptOpenOffset;
		m_szOpenBmpSize = ptOpenSize;
	}

	m_bHotBmp = bHot;
	m_bNewBmp = bNew;
	m_bOpenBmp = bOpen;

	//::TransparentBlt(GetDC()->m_hDC, 0, -5, 30, 33, m_dcHot.m_hDC, 0, 0, bmpInfo.bmWidth, bmpInfo.bmHeight, RGB(255, 0, 255));



	//m_ServerFeel.Create(NULL, WS_CHILD | WS_VISIBLE, CRect(0, 0, 0, 0), this, IDC_SCROLLBAR_BUTTON);
	//m_ServerFeel.SetBitmaps(IDB_HOT_BITMAP, RGB(255, 0, 255), IDB_HOT_BITMAP, RGB(255, 0, 255), IDB_HOT_BITMAP, RGB(255, 0, 255));
	//m_ServerFeel.SetAlign(CButtonST::ST_ALIGN_OVERLAP, FALSE);
	//m_ServerFeel.SetPressedStyle(CButtonST::BTNST_PRESSED_NONE, FALSE);
	//m_ServerFeel.SizeToContent();
	//m_ServerFeel.DrawBorder(FALSE, FALSE);
	//m_ServerFeel.DrawTransparent(TRUE);
	
}

//void CBitmapScrollElement::UpdateStatus()
//{
//	//선택된 server element가 enable/disable 여부에 따라 start button이 enable/disable 되도록 설정
//	CString sTitle;
//	GetWindowText(sTitle);
//
//	if(CServerManager::GetInstance()->IsEnableServer(sTitle.GetBuffer()))
//		EnableWindow(TRUE);
//	else
//		EnableWindow(FALSE);
//}

/*void CBitmapScrollElement::UpdateFeelType()
{
	CClientDC clDC(GetParent());
	CImage image;
	RECT rect;
	GetWindowRect(&rect);
	GetParent()->ScreenToClient(&rect);
	CRect curRect = CRect(rect);

	HRESULT ret = image.Load(_T("res/Hot.bmp"));
	//BOOL flag = image.AlphaBlend(GetParent()->GetDC()->m_hDC, 0, curRect.top);
	//BOOL flag = image.AlphaBlend(lpDrawItemStruct->hDC, 0, curRect.top);
	BOOL flag = image.TransparentBlt(clDC.m_hDC, 0, curRect.top, 45, 50, RGB(255, 0, 255));
	//BOOL flag = image.TransparentBlt(GetDC()->m_hDC, 0, 0, 45, 50, RGB(255, 0, 255));
	//image.Draw(lpDrawItemStruct->hDC, -100, 0, image.GetWidth(),image.GetHeight());
	//image.ReleaseDC();
}*/