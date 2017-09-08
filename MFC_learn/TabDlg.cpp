// TabDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_learn.h"
#include "TabDlg.h"
#include "afxdialogex.h"


// CTabDlg 对话框

IMPLEMENT_DYNAMIC(CTabDlg, CDialogEx)

CTabDlg::CTabDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TAB_DIALOG, pParent)
{

}

CTabDlg::~CTabDlg()
{
}

void CTabDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TABCTRL, m_tab);
}


BEGIN_MESSAGE_MAP(CTabDlg, CDialogEx)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TABCTRL, &CTabDlg::OnTcnSelchangeTabctrl)
END_MESSAGE_MAP()


// CTabDlg 消息处理程序


BOOL CTabDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CRect tabRect; // 标签控件客户区的位置大小
	m_tab.InsertItem(0, _T("滚动块"));
	m_tab.InsertItem(1, _T("组合框"));
	m_scbarDlg.Create(IDD_SCBAR_DIALOG1, &m_tab);
	m_comboDlg.Create(IDD_COMBO_DIALOG, &m_tab);

	m_tab.GetClientRect(&tabRect); // 获取把标签控件客户区Rect
	// 调整tabRect,使其覆盖范围适合放置标签页
	tabRect.left += 1;
	tabRect.right -= 1;
	tabRect.top += 25;
	tabRect.bottom -= 1;
	// 根据调整好的tabRect放置m_scbarDlg子对话框,设置为显示
	m_scbarDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_SHOWWINDOW);
	m_comboDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CTabDlg::OnTcnSelchangeTabctrl(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	CRect tabRect; // 标签控件客户区的位置大小

	m_tab.GetClientRect(&tabRect);
	
	tabRect.left += 1;
	tabRect.right -= 1;
	tabRect.top += 25;
	tabRect.bottom -= 1;
	
	switch (m_tab.GetCurSel())
	{
	case 0:
		m_scbarDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_SHOWWINDOW);
		m_comboDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);
		break;
	case 1:
		m_scbarDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);
		m_comboDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_SHOWWINDOW);
		break;
	default:
		break;
	}
}
