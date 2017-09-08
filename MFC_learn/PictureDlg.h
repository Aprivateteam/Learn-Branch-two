#pragma once


// CPictureDlg 对话框

class CPictureDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPictureDlg)

public:
	CPictureDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPictureDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PICTURE_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
