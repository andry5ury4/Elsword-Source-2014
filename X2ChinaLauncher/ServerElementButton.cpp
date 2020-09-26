#include "stdafx.h"
#include "ServerElementButton.h"
#include "PngWindow/PngWindow.h"
IMPLEMENT_DYNAMIC(CServerElementButton, CBitmapButton)

CServerElementButton::CServerElementButton()
{
	int i=0;
}

void CServerElementButton::DoDataExchange(CDataExchange* pDX)
{
	CBitmapButton::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CServerElementButton, CBitmapButton)
	ON_WM_PAINT()
END_MESSAGE_MAP()

BOOL CServerElementButton::OnInitDialog()
{
	return TRUE;
}

void CServerElementButton::OnPaint()
{
	CBitmapButton::OnPaint();

	//WindowAlphaBlendFromPNG(_T("res\\ServerElement.png"), m_hWnd);



	CPaintDC dc(this); // device context for painting
	CDC *pDC = GetDC();		

	CFont font;                
	font.CreateFont( 20, 0,0,0,FW_NORMAL,0,0,0,GB2312_CHARSET,0,0,0,0, _T( "ARIALUNI" ) );/*MS Snas Serif*/
	CFont* pOldFont = pDC->SelectObject( &font );            
	int mode = pDC->SetBkMode( TRANSPARENT );

	BOOL test = pDC->TextOut(0, 0, _T("时空争雄"));  

	/*RECT rc = {0,0 , 50, 30};
	BOOL test = pDC->ExtTextOut(0, 0, ETO_OPAQUE, &rc, _T("珂왕轢衿"), 0);  */

	//dc->SelectStockObject( DEFAULT_GUI_FONT );
	pDC->SelectObject(pOldFont);
	pDC->SetBkMode( mode );   
}