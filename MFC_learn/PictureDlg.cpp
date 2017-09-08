// PictureDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_learn.h"
#include "PictureDlg.h"
#include "afxdialogex.h"


// CPictureDlg 对话框

IMPLEMENT_DYNAMIC(CPictureDlg, CDialogEx)

CPictureDlg::CPictureDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PICTURE_DIALOG, pParent)
{

}

CPictureDlg::~CPictureDlg()
{
}

void CPictureDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPictureDlg, CDialogEx)
END_MESSAGE_MAP()


// CPictureDlg 消息处理程序
