#pragma once
#include "afxcmn.h"
#include "ScbarDlg.h"
#include "ComboDlg.h"


// CTabDlg 对话框

class CTabDlg : public CDialogEx
{
	CScbarDlg m_scbarDlg;
	CComboDlg m_comboDlg;
	DECLARE_DYNAMIC(CTabDlg)

public:
	CTabDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTabDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tab;
	virtual BOOL OnInitDialog();
	afx_msg void OnTcnSelchangeTabctrl(NMHDR *pNMHDR, LRESULT *pResult);
};
