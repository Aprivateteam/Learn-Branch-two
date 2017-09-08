#pragma once
#include "afxwin.h"


// CComboDlg 对话框

class CComboDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CComboDlg)

public:
	CComboDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CComboDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_COMBO_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_comboWeb;
	afx_msg void OnCbnSelchangeWebCombo();
	virtual BOOL OnInitDialog();
};
