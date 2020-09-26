#include "stdafx.h"
#include "X2ChinaLauncher.h"
#include "BitmapScrollElementView.h"
#include "ServerList.h"
#include "BitmapScrollElement.h"
//#include "PngWindow/PngWindow.h"

CBitmapScrollElementView::CBitmapScrollElementView()
{
	m_pManager = NULL;

	//m_ServerFeelDlg.Create(CServerFeelDlg::IDD);
}

CBitmapScrollElementView::~CBitmapScrollElementView()
{
	for(int i=0; i<m_vecElement.size(); i++)
		delete m_vecElement[i];

	m_dcBG.SelectObject(m_pbmpOldBG);
	m_bmpBG.DeleteObject();
	m_dcBG.DeleteDC();
}

void CBitmapScrollElementView::Create(int x, int y, CWnd* pParentWnd, UINT uiCtrlID, UINT uiResourceID)
{
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
}

//void CBitmapScrollElementView::PreSubclassWindow()
//{
//
//	CBitmapButton::PreSubclassWindow();
//}

void CBitmapScrollElementView::AddElement(CBitmapScrollElement* pElement/*, EServerFeelType eFeelType*/) 
{
	m_vecElement.push_back(pElement); 
	//m_vecServerFeelType.push_back(eFeelType);

	if(m_vecElement.size()>1)
	{
		RECT sRect, eRect;
		m_vecElement[0]->GetWindowRect(&sRect);
		m_vecElement[0]->GetParent()->ScreenToClient(&sRect);
		m_vecElement[m_vecElement.size()-1]->GetWindowRect(&eRect);
		m_vecElement[m_vecElement.size()-1]->GetParent()->ScreenToClient(&eRect);

		m_AllElementRect.left = sRect.left;
		m_AllElementRect.top = sRect.top;
		m_AllElementRect.right = eRect.right;
		m_AllElementRect.bottom = eRect.bottom;
	}
		
}

void CBitmapScrollElementView::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	//OutputDebugString(_T("CBitmapScrollElementView is DrawItem......................\n"));

	
#if 0
	//test
	CRect rc;
	GetWindowRect(&rc);

	CClientDC dcScreen(this);

	dcScreen.BitBlt(-400, 0, rc.Width(), rc.Height(), &m_dcBG, 0, 0, SRCCOPY);
#endif

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

BEGIN_MESSAGE_MAP(CBitmapScrollElementView, CBitmapButton)
	//{{AFX_MSG_MAP(CBitmapScrollElementView)
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP

END_MESSAGE_MAP()

BOOL CBitmapScrollElementView::OnEraseBkgnd(CDC* pDC)
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
	//return CButtonST::OnEraseBkgnd(pDC);
}

void CBitmapScrollElementView::NotifyScroll(int iOffsetY, BOOL bUp)
{
	//element button들 scroll 시키기
	if(bUp)//element들이 위로 이동할 경우에는 그리는 순서를 위->아래 방향으로 하도록 설정한다.
	{
		for(int i=0; i<m_vecElement.size(); i++)
		{
			//RECT rc;
			//m_vecElement[i]->GetWindowRect(&rc);
			//m_vecElement[i]->GetParent()->ScreenToClient(&rc);
			//rc.top -= iOffsetY;

			if(i==0)
				m_vecElement[i]->SetWindowPos(m_vecElement[i]->GetParent(), 0, iOffsetY+i*30, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
			else
				m_vecElement[i]->SetWindowPos(m_vecElement[i-1], 0, iOffsetY+i*30, 0, 0, SWP_NOSIZE);
			m_vecElement[i]->Invalidate();
		}

	}
	else//element들이 위로 이동할 경우에는 그리는 순서를 아래->위 방향으로 하도록 설정한다.
	{
		for(int i=m_vecElement.size()-1; i>=0; i--)
		{
			//RECT rc;
			//m_vecElement[i]->GetWindowRect(&rc);
			//m_vecElement[i]->GetParent()->ScreenToClient(&rc);
			//rc.top -= iOffsetY;

			if(i==m_vecElement.size()-1)
				m_vecElement[i]->SetWindowPos(m_vecElement[i]->GetParent(), 0, iOffsetY+i*30, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
			else
				m_vecElement[i]->SetWindowPos(m_vecElement[i+1], 0, iOffsetY+i*30, 0, 0, SWP_NOSIZE);
			m_vecElement[i]->Invalidate();
		}
	}
	
/*	//hot, new 표시
	for(int i=0; i<m_vecServerFeelType.size(); i++)
	{
		if(m_vecServerFeelType[i] == eServer_Feel_Type_HOT)
		{
			//UpdateFeelType();
		}
		else if(m_vecServerFeelType[i] == eServer_Feel_Type_NEW)
		{
			//m_vecElement[i]->UpdateFeelType();
		}
	}*/
}

void CBitmapScrollElementView::NotifyElementSelected(const std::wstring& wstrCurElementName, const std::wstring& wstrPreElementName)
{
	for(int i=0; i<m_vecElement.size(); i++)
	{
		CString sTitle;
		m_vecElement[i]->GetWindowText(sTitle);


		if(sTitle.GetBuffer() == wstrCurElementName)
		{
			m_vecElement[i]->SetSelected(TRUE);
		}
		else
		{
			m_vecElement[i]->SetSelected(FALSE);

			if(sTitle.GetBuffer() == wstrPreElementName)
			{
				m_vecElement[i]->Invalidate();
			}
		}

	}
}