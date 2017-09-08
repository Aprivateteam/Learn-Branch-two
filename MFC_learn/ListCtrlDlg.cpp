// ListCtrlDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_learn.h"
#include "ListCtrlDlg.h"
#include "afxdialogex.h"


// CListCtrlDlg 对话框

IMPLEMENT_DYNAMIC(CListCtrlDlg, CDialogEx)

CListCtrlDlg::CListCtrlDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_LISTCTRL_DIALOG, pParent)
{

}

CListCtrlDlg::~CListCtrlDlg()
{
}

void CListCtrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRAM_LANG_LIST, m_programLangList);

}


BEGIN_MESSAGE_MAP(CListCtrlDlg, CDialogEx)
	ON_NOTIFY(NM_CLICK, IDC_PROGRAM_LANG_LIST, &CListCtrlDlg::OnNMClickProgramLangList)
END_MESSAGE_MAP()


// CListCtrlDlg 消息处理程序


void CListCtrlDlg::OnNMClickProgramLangList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;

	CString strLangName;
	NMLISTVIEW *pNMListView = (NMLISTVIEW*)pNMHDR;

	if (pNMListView->iItem != -1) { // 如果iItem不是-1，就说明有列表项被选择
		//获取被选择列表项的第一个子项的文本
		strLangName = m_programLangList.GetItemText(pNMListView->iItem, 0);
		//将选择的语言显示在编辑框中
		SetDlgItemText(IDC_LANG_SEL_EDIT, strLangName);
	}
}


BOOL CListCtrlDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	CRect rect;
	//获取列表视图控件的位置与大小
	m_programLangList.GetClientRect(&rect);

	// 为列表视图控件添加全行选中和栅格风格
	m_programLangList.SetExtendedStyle(m_programLangList.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	// 为列表视图控件添加三列
	m_programLangList.InsertColumn(0, _T("语言"), LVCFMT_CENTER, rect.Width() / 3, 0);
	m_programLangList.InsertColumn(1, _T("2012.02排名"), LVCFMT_CENTER, rect.Width() / 3, 1);
	m_programLangList.InsertColumn(2, _T("2011.02排名"), LVCFMT_CENTER, rect.Width() / 3, 2);

	// 在列表视图控件中插入列表项，并设置列表子项文本
	m_programLangList.InsertItem(0, _T("Java"));
	m_programLangList.SetItemText(0, 1, _T("1"));
	m_programLangList.SetItemText(0, 2, _T("1"));
	m_programLangList.InsertItem(1, _T("C"));
	m_programLangList.SetItemText(1, 1, _T("2"));
	m_programLangList.SetItemText(1, 2, _T("2"));
	m_programLangList.InsertItem(2, _T("C#"));
	m_programLangList.SetItemText(2, 1, _T("3"));
	m_programLangList.SetItemText(2, 2, _T("6"));
	m_programLangList.InsertItem(3, _T("C++"));
	m_programLangList.SetItemText(3, 1, _T("4"));
	m_programLangList.SetItemText(3, 2, _T("3"));

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
