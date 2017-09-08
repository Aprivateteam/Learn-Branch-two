// ComboDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_learn.h"
#include "ComboDlg.h"
#include "afxdialogex.h"


// CComboDlg 对话框

IMPLEMENT_DYNAMIC(CComboDlg, CDialogEx)

CComboDlg::CComboDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_COMBO_DIALOG, pParent)
{

}

CComboDlg::~CComboDlg()
{
}

void CComboDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_WEB_COMBO, m_comboWeb);


}


BEGIN_MESSAGE_MAP(CComboDlg, CDialogEx)
	ON_CBN_SELCHANGE(IDC_WEB_COMBO, &CComboDlg::OnCbnSelchangeWebCombo)
END_MESSAGE_MAP()


// CComboDlg 消息处理程序


void CComboDlg::OnCbnSelchangeWebCombo()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strWeb;
	int nSel;

	nSel = m_comboWeb.GetCurSel();
	m_comboWeb.GetLBText(nSel, strWeb);
	SetDlgItemText(IDC_SEL_WEB_EDIT, strWeb);
}


BOOL CComboDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	m_comboWeb.AddString(_T("鸡啄米:http://www.jizhuomi.com/"));
	m_comboWeb.AddString(_T("百度:http://www.baidu.com/"));
	m_comboWeb.AddString(_T("新浪:http://www.sina.com.cn/"));
	m_comboWeb.InsertString(3, _T("猫扑:http://www.mop.com/"));

	m_comboWeb.SetCurSel(0);

	SetDlgItemText(IDC_SEL_WEB_EDIT, _T("鸡啄米:http://www.jizhuomi.com/"));

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
