#pragma once


// CRgsterDlg 对话框

class CRgsterDlg : public CDialogEx
{

	DECLARE_DYNAMIC(CRgsterDlg)

public:
	CRgsterDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRgsterDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_REGSTER_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
