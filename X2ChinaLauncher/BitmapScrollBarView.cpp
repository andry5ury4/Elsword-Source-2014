#include "stdafx.h"
#include "X2ChinaLauncher.h"
#include "BitmapScrollBarView.h"
#include "ServerList.h"
#include "BitmapScrollBar.h"

CBitmapScrollBarView::CBitmapScrollBarView()
{
	m_pManager = NULL;
}

CBitmapScrollBarView::~CBitmapScrollBarView()
{
	delete m_pScrollbar;

	m_dcBG.SelectObject(m_pbmpOldBG);
	m_bmpBG.DeleteObject();
	m_dcBG.DeleteDC();
}

void CBitmapScrollBarView::Create(int x, int y, CWnd* pParentWnd, UINT uiCtrlID, UINT uiResourceID)
{
#if 1
	CBitmapButton::Create(NULL, WS_CHILD | WS_VISIBLE | BS_OWNERDRAW, CRect(x, y, 0, 0), pParentWnd, uiCtrlID);
	LoadBitmaps(uiResourceID);
	//LoadBitmaps(0);
	SizeToContent();

	CRect rect;
	GetWindowRect(rect);

	m_dcBG.CreateCompatibleDC(GetDC());
	m_bmpBG.LoadBitmap(uiResourceID);
	//m_bmpBG.CreateCompatibleBitmap(&dc, rect.Width(), rect.Height());
	m_pbmpOldBG = m_dcBG.SelectObject(&m_bmpBG);

	m_dcBG.BitBlt(0, 0, rect.Width(), rect.Height(), GetDC(), 0, 0, SRCCOPY);
#else
	CBitmapButton::Create(NULL, WS_CHILD | WS_VISIBLE | BS_OWNERDRAW, CRect(x, y, x+50, y+200), pParentWnd, uiCtrlID);

	CRect rect;
	GetWindowRect(&rect);

	m_dcBG.CreateCompatibleDC(AfxGetMainWnd()->GetDC());
	m_bmpBG.CreateCompatibleBitmap(&m_dcBG, rect.Width(), rect.Height());
	//m_bmpBG.CreateCompatibleBitmap(&dc, rect.Width(), rect.Height());
	m_pbmpOldBG = m_dcBG.SelectObject(&m_bmpBG);

	m_dcBG.BitBlt(0, 0, rect.Width(), rect.Height(), AfxGetMainWnd()->GetDC(), rect.left, rect.top, SRCCOPY);

	

#endif
}

//void CBitmapScrollBarView::PreSubclassWindow()
//{
//
//	CBitmapButton::PreSubclassWindow();
//}

void CBitmapScrollBarView::Attatch(CBitmapScrollBar* pElement)
{
	m_pScrollbar = pElement;
}

void CBitmapScrollBarView::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	//OutputDebugString(_T("CBitmapScrollBarView is DrawItem......................\n"));


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
	//clDC.BitBlt(451, 530, bmpInfo.bmWidth, bmpInfo.bmHeight, &dcScreen, 0, 0, SRCCOPY);

	//dcScreen.SelectObject(pOldBitmap);

	//CBitmapButton::DrawItem(lpDrawItemStruct);

	//for(int i=0; i<m_vecElement.size(); i++)
	//	m_vecElement[i]->Invalidate();
		//m_vecElement[i]->DrawItem(lpDrawItemStruct);
}

BEGIN_MESSAGE_MAP(CBitmapScrollBarView, CBitmapButton)
	//{{AFX_MSG_MAP(CBitmapScrollBarView)
	//ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP

END_MESSAGE_MAP()

//void CBitmapScrollBarView::OnPaint()
//{
//	CBitmapButton::OnPaint();
//}

BOOL CBitmapScrollBarView::OnEraseBkgnd(CDC* pDC)
{

	//CClientDC clDC(this);
	//CDC dcScreen;
	//CBitmap bmp;

	//dcScreen.CreateCompatibleDC(&clDC);
	//bmp.LoadBitmap(IDB_SCROLLELEMENTVIEW_BITMAP);


	//CBitmap *pOldBitmap= dcScreen.SelectObject(&bmp);


	//// get the bitmap dimensions
	//BITMAP bmpInfo;
	//bmp.GetBitmap(&bmpInfo);

	////CDC*	pDC = CDC::FromHandle(lpDrawItemStruct->hDC);
	//clDC.BitBlt(0, 0, bmpInfo.bmWidth, bmpInfo.bmHeight, &dcScreen, 0, 0, SRCCOPY);

	//dcScreen.SelectObject(pOldBitmap);


	return TRUE;
	//return CBitmapButton::OnEraseBkgnd(pDC);
}

