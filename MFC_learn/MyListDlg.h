#pragma once
#include "afxwin.h"


// CMyListDlg 对话框

class CMyListDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMyListDlg)

public:
	CMyListDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMyListDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LIST_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_listBox;
	afx_msg void OnLbnSelchangeList1();
	virtual BOOL OnInitDialog();
};
