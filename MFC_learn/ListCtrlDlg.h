#pragma once
#include "afxcmn.h"


// CListCtrlDlg 对话框

class CListCtrlDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CListCtrlDlg)

public:
	CListCtrlDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CListCtrlDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LISTCTRL_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_programLangList;
	afx_msg void OnNMClickProgramLangList(NMHDR *pNMHDR, LRESULT *pResult);
	virtual BOOL OnInitDialog();
};
