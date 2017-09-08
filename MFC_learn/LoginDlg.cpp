// LoginDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_learn.h"
#include "LoginDlg.h"
#include "afxdialogex.h"
#include "RgsterDlg.h"

using namespace std;


// CLoginDlg 对话框

IMPLEMENT_DYNAMIC(CLoginDlg, CDialogEx)

CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_LOGIN_DIALOG, pParent)
	, m_name(_T(""))
	, m_password(_T(""))
{
	m_pRgsterDlg = NULL;
}

CLoginDlg::~CLoginDlg()
{
	if (m_pRgsterDlg != NULL) {
		delete m_pRgsterDlg;
	}
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NAME_EDIT, m_name);
	DDX_Text(pDX, IDC_PW_EDIT, m_password);
	DDX_Control(pDX, IDC_COMBO1, m_idbox);
}

BOOL CLoginDlg::Login_Check() {
	CString pszFileName = _T("Secret.m"), m_str, m_name_file=_T(""), m_pw_file = _T("");
	CStdioFile file_one,file_two;
	CFileException fileException;
	if (file_one.Open(pszFileName, CFile::typeBinary|CFile::modeRead)) {
		while (file_one.ReadString(m_str)) {
			bool n_swch = false;
			bool p_swch = false;
			m_name_file = _T("");
			m_pw_file = _T("");
			for (int i = 0;i < m_str.GetLength();i++) {
				if (m_str[i] == '*') {
					n_swch = !n_swch;
				}
				else if (n_swch) {
					m_name_file += m_str[i];
				}

				if (m_str[i] == '+') {
					p_swch = !p_swch;
				}
				else if (p_swch) {
					m_pw_file += m_str[i];
				}
			}
			if (m_name_file == m_name) {
				if (m_pw_file == m_password) {
					if (m_idbox.GetCurSel() == CB_ERR) {
						MessageBox(_T("请选择用户类型！"), _T("登录失败"), MB_OK | MB_ICONWARNING);
						return FALSE;
					}
					else {
						return TRUE;
					}
				}
			}
		}
		file_one.Close();
	}
	else {
		TRACE("Can't open file %s,error=%u\n", pszFileName, fileException.m_cause);
	}
	
	MessageBox(_T("请输入正确的用户名及密码！"), _T("登录失败"), MB_OK | MB_ICONWARNING);
	return FALSE;
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialogEx)
	ON_BN_CLICKED(IDC_LOGIN_BUTTON, &CLoginDlg::OnBnClickedLoginButton)
	ON_BN_CLICKED(IDC_REGSTER_BUTTON, &CLoginDlg::OnBnClickedRegsterButton)
	ON_CBN_SELCHANGE(IDC_ID_COMBO, &CLoginDlg::OnCbnSelchangeIdCombo)
END_MESSAGE_MAP()


// CLoginDlg 消息处理程序


void CLoginDlg::OnBnClickedLoginButton()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (CLoginDlg::Login_Check()) {
		CDialogEx::OnOK();
	}
}


void CLoginDlg::OnBnClickedRegsterButton()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_pRgsterDlg == NULL) {
		m_pRgsterDlg = new CRgsterDlg();
		m_pRgsterDlg->Create(IDD_REGSTER_DIALOG);
	}
	m_pRgsterDlg->ShowWindow(SW_SHOW);
}


BOOL CLoginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	SetDlgItemText(IDC_ID_COMBO, _T("请选择用户类型"));
	m_idbox.AddString(_T("家庭用户"));
	m_idbox.AddString(_T("企业用户"));
	m_idbox.AddString(_T("管理用户"));

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CLoginDlg::OnCbnSelchangeIdCombo()
{
	// TODO: 在此添加控件通知处理程序代码
	int nSel = m_idbox.GetCurSel();
	CString idstr;
	m_idbox.GetLBText(nSel, idstr);
	m_identity = idstr;
}
