#pragma once


// CBannerDlg 대화 상자입니다.

class CBannerDlg : public CDialog
{
	DECLARE_DYNAMIC(CBannerDlg)

public:
	CBannerDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CBannerDlg();

	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

// 대화 상자 데이터입니다.
	enum { IDD = IDD_BANNER_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};
