// ScbarDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_learn.h"
#include "ScbarDlg.h"
#include "afxdialogex.h"


// CScbarDlg 对话框

IMPLEMENT_DYNAMIC(CScbarDlg, CDialogEx)

CScbarDlg::CScbarDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SCBAR_DIALOG1, pParent)
{

}

CScbarDlg::~CScbarDlg()
{
}

void CScbarDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SCROLLBAR2, m_horiScrollbar);

}


BEGIN_MESSAGE_MAP(CScbarDlg, CDialogEx)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// CScbarDlg 消息处理程序


void CScbarDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int pos = m_horiScrollbar.GetScrollPos(); // 获取水平滚动条当前位置

	switch(nSBCode)
	{
	// 向左滚动 pos -= 1
	case SB_LINELEFT:
		pos -= 1;
		break;

	//向右滚动 pos += 1
	case SB_LINERIGHT:
		pos += 1;
		break;

	//向左滚动一页 pos -= 10
	case SB_PAGELEFT:
		pos -= 10;
		break;
	// 如果向右滚动一页，pos +=10
	case SB_PAGERIGHT:
		pos += 10;
		break;
	// 如果滚动到最左端，则pos为1
	case SB_LEFT:
		pos = 1;
		break;
	//如果滚动到最右端，则pos为100
	case SB_RIGHT:
		pos = 100;
		break;
	// 如果拖动滚动块滚动到指定位置，则pos赋值为nPos的值
	case SB_THUMBPOSITION:
		pos = nPos;
		break;

	// 下面的m_horiScrollbar.SetScrollPos(pos);
	// 执行时会第二次进入此函数，最终确定滚动块位置，并且会直接到default分支，所以在此处设置编辑框中显示数值  
	default:
		SetDlgItemInt(IDC_HSCROLL_EDIT, pos);
		return;
	}
	// 设置滚动块位置
	m_horiScrollbar.SetScrollPos(pos);
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


BOOL CScbarDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_horiScrollbar.SetScrollRange(1, 100);
	m_horiScrollbar.SetScrollPos(20);
	SetDlgItemInt(IDC_HSCROLL_EDIT, 20);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
