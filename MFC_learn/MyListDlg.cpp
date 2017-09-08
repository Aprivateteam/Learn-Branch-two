// MyListDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_learn.h"
#include "MyListDlg.h"
#include "afxdialogex.h"


// CMyListDlg 对话框

IMPLEMENT_DYNAMIC(CMyListDlg, CDialogEx)

CMyListDlg::CMyListDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_LIST_DIALOG, pParent)
{
}

CMyListDlg::~CMyListDlg()
{
}

void CMyListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listBox);
	
}


BEGIN_MESSAGE_MAP(CMyListDlg, CDialogEx)
	ON_LBN_SELCHANGE(IDC_LIST1, &CMyListDlg::OnLbnSelchangeList1)
END_MESSAGE_MAP()


// CMyListDlg 消息处理程序


void CMyListDlg::OnLbnSelchangeList1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strText;
	int nCurSel;

	nCurSel = m_listBox.GetCurSel();
	m_listBox.GetText(nCurSel, strText);
	SetDlgItemText(IDC_SEL_WEB_EDIT, strText);
}


BOOL CMyListDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_listBox.AddString(_T("新浪:http://www.sina.com.cn/"));
	m_listBox.AddString(_T("鸡啄米:http://www.jizhuomi.com/"));
	m_listBox.AddString(_T("猫扑:http://www.mop.com/"));
	m_listBox.InsertString(2, _T("百度:http://www.baidu.com/"));
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
