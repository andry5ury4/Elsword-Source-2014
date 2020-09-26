#include "stdafx.h"
#include "ServerList.h"
#include "X2ChinaLauncher.h"
#include "BtnST.h"
#include "BitmapScrollBarView.h"
#include "BitmapScrollBar.h"
#include "BitmapScrollElementView.h"
#include "BitmapScrollElement.h"


//VOID CALLBACK OnTimer(HWND hwnd, UINT msg, UINT_PTR id, DWORD dwTime);

CServerList::CServerList()
{
	iElementButton = 0;
	//m_pSlideBG = NULL;
	m_pSlideBarView = NULL;
	m_pSlideBarButton = NULL;

	m_pSlideView = NULL;
	m_uiScrollViewResourceID = 0;
}

CServerList::~CServerList()
{
	delete m_pSlideBarView;
	delete m_pSlideView;

	//delete m_pSlideBG;

	//for(int i=0; i<m_vecElement.size(); i++)
	//	delete m_vecElement[i];
}
#if 1
void CServerList::AddElement(CWnd* pParentWnd, const std::wstring& wstrName, const BOOL bHot, const BOOL bNew, const BOOL bOpen, const BOOL bEnable)
{
	if(!m_pSlideView)
	{
		m_pSlideView = new CBitmapScrollElementView;

		m_pSlideView->Create(m_ScrollElementViewPos.x, m_ScrollElementViewPos.y, pParentWnd, m_uiScrollElemViewID, m_uiScrollViewResourceID);
		m_pSlideView->SetManager(this);
	}
	
	CBitmapScrollElement* pElementButton = new CBitmapScrollElement;

	//pElementButton->Create(wstrName.c_str(), WS_CHILD | WS_VISIBLE, CRect(454, 526+iElementButton*30, 0, 0), pParentWnd, IDC_SERVERELEMENTBUTTON_BEGIN+iElementButton);
	pElementButton->SetOwnerBackground(m_pSlideView->GetDCBackground());
	pElementButton->Create(wstrName.c_str(), WS_CHILD | WS_VISIBLE, CRect(0, iElementButton*30, 0, 0), m_pSlideView, IDC_SERVERELEMENTBUTTON_BEGIN+iElementButton);
	//pElementButton->SetID(iElementButton);
	pElementButton->SetBitmaps(IDB_SERVERELEMENT_UP_BITMAP, RGB(255, 0, 255), IDB_SERVERELEMENT_UP_BITMAP, RGB(255, 0, 255), 0, RGB(255, 0, 255), IDB_SERVERELEMENT_SELECTED_BITMAP, RGB(255, 0, 255), IDB_SERVERELEMENT_DISABLE_BITMAP, RGB(255, 0, 255));
	pElementButton->SetAlign(CButtonST::ST_ALIGN_OVERLAP, FALSE);
	pElementButton->SetPressedStyle(CButtonST::BTNST_PRESSED_NONE, FALSE);
	pElementButton->SetFontType(13, GB2312_CHARSET, _T( "ARIALUNI" ));
	pElementButton->SizeToContent();
	pElementButton->DrawBorder(FALSE, FALSE);
	pElementButton->DrawTransparent(TRUE);

	pElementButton->PrepareServerFeel(bHot, CPoint(0, -5), CSize(30, 33), 
									bNew, CPoint(0, 5), CSize(35, 18),
									bOpen, CPoint(0, 0), CSize(52, 24) );

	//선택된 server element가 enable/disable 여부에 따라 start button이 enable/disable 되도록 설정
	if(bEnable)
		pElementButton->EnableWindow(TRUE);
	else
		pElementButton->EnableWindow(FALSE);

	//pElementButton->UpdateStatus();

	//m_vecElement.push_back(pElementButton);

	m_pSlideView->AddElement(pElementButton/*, CBitmapScrollElementView::eServer_Feel_Type_NEW*/);

	//
	/*if(m_vecElement.size()>1)
	{
		RECT sRect, eRect;
		m_vecElement[0]->GetWindowRect(&sRect);
		m_vecElement[0]->GetParent()->ScreenToClient(&sRect);
		m_vecElement[m_vecElement.size()-1]->GetWindowRect(&eRect);
		m_vecElement[m_vecElement.size()-1]->GetParent()->ScreenToClient(&eRect);

		m_CurElementRegion.left = sRect.left;
		m_CurElementRegion.top = sRect.top;
		m_CurElementRegion.right = eRect.right;
		m_CurElementRegion.bottom = eRect.bottom;
	}*/


	if(iElementButton>=0 && !m_pSlideBarView)
	{
#if 1
		m_pSlideBarView = new CBitmapScrollBarView;

		m_pSlideBarView->Create(m_ScrollBarViewPos.x, m_ScrollBarViewPos.y, pParentWnd, m_uiScrollBarViewID, IDB_SCROLLBARVIEW_BITMAP);
		m_pSlideBarView->SetManager(this);
#endif

		m_pSlideBarButton = new CBitmapScrollBar;
		
		//스크롤 바 버튼
		//m_pSlideBarButton->Create(NULL, WS_CHILD | WS_VISIBLE, CRect(426, 543+100, 0, 0), pParentWnd, IDC_SCROLLBAR_BUTTON);
		//m_pSlideBarButton->SetBgBitmap(IDB_SCROLLBARVIEW_BITMAP)
		//m_pSlideBarButton->Init(426, 543);
		//m_pSlideBarButton->Create(_T("oo"), WS_CHILD | WS_VISIBLE, CRect(426, 543, 0, 0), pParentWnd, IDC_SCROLLBAR_BUTTON);
		//m_pSlideBarButton->Init(0, 0);
		m_pSlideBarButton->SetOwnerBackground(m_pSlideBarView->GetDCBackground());
		m_pSlideBarButton->Create(NULL, WS_CHILD | WS_VISIBLE, CRect(0, 0, 0, 0), m_pSlideBarView, m_uiScrollBarID);
		m_pSlideBarButton->SetBitmaps(IDB_SCROLLBAR_BITMAP, RGB(255, 0, 255), IDB_SCROLLBAR_BITMAP, RGB(255, 0, 255), IDB_SCROLLBAR_BITMAP, RGB(255, 0, 255));
		//m_pSlideBarButton->SetPngs("res/ScrollBar.png.png", "res/ScrollBar.png.png", "res/ScrollBar.png.png");
		m_pSlideBarButton->SetAlign(CButtonST::ST_ALIGN_OVERLAP, FALSE);
		m_pSlideBarButton->SetPressedStyle(CButtonST::BTNST_PRESSED_NONE, FALSE);
		m_pSlideBarButton->SizeToContent();
		m_pSlideBarButton->DrawBorder(FALSE, FALSE);
		m_pSlideBarButton->DrawTransparent(TRUE);

		m_pSlideBarButton->SetManager(this);
		//m_pSlideBarButton->SetRegion(m_ScrollRegion);

		m_pSlideBarView->Attatch(m_pSlideBarButton);

	}

	iElementButton++;


	//CServerElementButton* pElementButton = new CServerElementButton;

	//pElementButton->Create(NULL, WS_CHILD | WS_VISIBLE | BS_OWNERDRAW, CRect(454, 526+iElementButton*30, 0, 0), pParentWnd, IDC_SERVERELEMENTBUTTON_BEGIN+iElementButton);
	//pElementButton->LoadBitmaps(IDB_SERVERELEMENT_BITMAP, IDB_SERVERELEMENT_BITMAP, IDB_SERVERELEMENT_BITMAP, IDB_SERVERELEMENT_BITMAP);
	//pElementButton->SizeToContent();
	//m_vecElement.push_back(pElementButton);

	//iElementButton++;
}
#else
void CServerList::AddElement(CWnd* pParentWnd, const std::wstring& wstrName, const BOOL bHot, const BOOL bNew, const BOOL bOpen, const BOOL bEnable)
{
	{
#if 0
		m_pSlideBG = new CBitmapButton;

		//스크롤 바 버튼
		m_pSlideBG->Create(NULL, WS_CHILD | WS_VISIBLE | BS_OWNERDRAW, CRect(322, 526, 0, 0), pParentWnd, IDC_SCROLLBAR_BG);
		m_pSlideBG->LoadBitmaps(IDB_SCROLLBARVIEW_BITMAP);
		m_pSlideBG->SizeToContent();
#endif
		m_pSlideBarButton = new CBitmapScrollBar;

		//스크롤 바 버튼
		//m_pSlideBarButton->Create(NULL, WS_CHILD | WS_VISIBLE, CRect(426, 543+100, 0, 0), pParentWnd, IDC_SCROLLBAR_BUTTON);
		//m_pSlideBarButton->SetBgBitmap(IDB_SCROLLBARVIEW_BITMAP)
		m_pSlideBarButton->Create(NULL, WS_CHILD | WS_VISIBLE, CRect(426, 543, 0, 0), pParentWnd, IDC_SCROLLBAR_BUTTON);
		//m_pSlideBarButton->Create(NULL, WS_CHILD | WS_VISIBLE, CRect(0, 0, 0, 0), m_pSlideBG, IDC_SCROLLBAR_BUTTON);
		m_pSlideBarButton->SetBitmaps(IDB_SCROLLBAR_BITMAP, RGB(255, 0, 255), IDB_SCROLLBAR_BITMAP, RGB(255, 0, 255), IDB_SCROLLBAR_BITMAP, RGB(255, 0, 255));
		m_pSlideBarButton->SetAlign(CButtonST::ST_ALIGN_OVERLAP, FALSE);
		m_pSlideBarButton->SetPressedStyle(CButtonST::BTNST_PRESSED_NONE, FALSE);
		m_pSlideBarButton->SizeToContent();
		m_pSlideBarButton->DrawBorder(FALSE, FALSE);
		m_pSlideBarButton->DrawTransparent(TRUE);

		m_pSlideBarButton->SetManager(this);
		m_pSlideBarButton->SetRegion(m_ScrollRegion);
		//스크롤이 생기면 버튼들에 대한 scroll를 위한 timer 동작
		//SetTimer(NULL, (UINT_PTR)this, 50, OnTimer);

	}
}
#endif

int CServerList::CalcElementButtonMove(int iSlideBarMoveY)
{
	CRect curElementRegion = m_pSlideView->GetAllElementRect();
	CRect curScrollRegion;
	CRect curScrollRegion2;
	CRect ScrollBarRegion;

	m_pSlideBarView->GetClientRect(&curScrollRegion);
	curScrollRegion2 = curScrollRegion;
	m_pSlideBarButton->GetClientRect(&ScrollBarRegion);
	curScrollRegion2.bottom -= ScrollBarRegion.Height();


	//int temp = (curElementRegion.bottom-curElementRegion.top-(curScrollRegion.bottom-curScrollRegion.top)) * iSlideBarMoveY/(curScrollRegion.bottom-curScrollRegion.top);
	int temp = ((curElementRegion.Height()-curScrollRegion.Height()) * iSlideBarMoveY)/curScrollRegion2.Height();
	return -temp;
}

BOOL CServerList::IsEnableScrollBar()
{
	CRect curScrollRegion;
	CRect curElementRegion = m_pSlideView->GetAllElementRect();

	m_pSlideBarView->GetClientRect(&curScrollRegion);
	
	//스크롤바는 element들이 충분히 있을때만 이동한다.
	if(curElementRegion.Height()<=curScrollRegion.Height())
	{
		return FALSE;
	}

	return TRUE;
}

void CServerList::NotifyElementSelected(const std::wstring& wstrCurElementName, const std::wstring& wstrPreElementName)
{
	if(m_pSlideView)
		m_pSlideView->NotifyElementSelected(wstrCurElementName, wstrPreElementName);
}
//
//VOID CALLBACK OnTimer(HWND hwnd, UINT msg, UINT_PTR id, DWORD dwTime)
//{
//	CServerList* temp = (CServerList*)id;
//
//	int y=temp->GetScrollbar()->GetBarMoveY();
//
//	//bar move offsetY로 부터 버튼들이 움직일 량을 계산
//	temp->CalcElementButtonMove(y);
//}
