#pragma once
#include "afxwin.h"


// CScbarDlg 对话框

class CScbarDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CScbarDlg)

public:
	CScbarDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CScbarDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SCBAR_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CScrollBar m_horiScrollbar;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	virtual BOOL OnInitDialog();
};
