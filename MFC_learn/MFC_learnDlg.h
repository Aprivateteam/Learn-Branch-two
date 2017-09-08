
// MFC_learnDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "MyListDlg.h"
#include "ComboDlg.h"
#include "ScbarDlg.h"
#include "PictureDlg.h"
#include "ListCtrlDlg.h"
#include "TreeDlg.h"
#include "TabDlg.h"
#include "LoginDlg.h"


// CMFC_learnDlg 对话框
class CMFC_learnDlg : public CDialogEx
{
private:
	CMyListDlg *m_pListDlg;
	CComboDlg *m_pComboDlg;
	CScbarDlg *m_pScbarDlg;
	CPictureDlg *m_pPictureDlg;
	CListCtrlDlg *m_pListCtrlDlg;
	CTreeDlg *m_pTreeDlg;
	CTabDlg *m_pTabDlg;
	CString m_identity;
// 构造
public:
	CMFC_learnDlg(CString m_id =_T("主人"), CWnd* pParent = NULL);	// 标准构造函数
	~CMFC_learnDlg();

// 对话框数据
	enum { IDD = IDD_MFC_LEARN_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CEdit m_editMultiLine;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CButton m_check1;
	CButton m_check2;
	CButton m_check3;
	CButton m_check4;
	CButton m_check5;
	CButton m_check6;
	void initAllCheckBoxStatus();
	afx_msg void OnBnClickedPortalRadio();
	afx_msg void OnBnClickedForumRadio();
	afx_msg void OnBnClickedBlogRadio();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedListButton();
	afx_msg void OnBnClickedComboButton();
	afx_msg void OnBnClickedScbarButton();
	afx_msg void OnBnClickedPictureButton();
	afx_msg void OnBnClickedListctrlButton();
	afx_msg void OnBnClickedTreeButton();
	afx_msg void OnBnClickedButton1();
};
