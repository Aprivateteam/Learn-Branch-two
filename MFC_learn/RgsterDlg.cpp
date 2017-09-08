// RgsterDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_learn.h"
#include "RgsterDlg.h"
#include "afxdialogex.h"


// CRgsterDlg 对话框

IMPLEMENT_DYNAMIC(CRgsterDlg, CDialogEx)

CRgsterDlg::CRgsterDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_REGSTER_DIALOG, pParent)
{

}

CRgsterDlg::~CRgsterDlg()
{
}

void CRgsterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CRgsterDlg, CDialogEx)
END_MESSAGE_MAP()


// CRgsterDlg 消息处理程序
