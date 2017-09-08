// TreeDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_learn.h"
#include "TreeDlg.h"
#include "afxdialogex.h"


// CTreeDlg 对话框

IMPLEMENT_DYNAMIC(CTreeDlg, CDialogEx)

CTreeDlg::CTreeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TREE_DIALOG, pParent)
{

}

CTreeDlg::~CTreeDlg()
{
}

void CTreeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_WEB_TREE, m_webTree);
}


BEGIN_MESSAGE_MAP(CTreeDlg, CDialogEx)
	ON_NOTIFY(TVN_SELCHANGED, IDC_WEB_TREE, &CTreeDlg::OnTvnSelchangedWebTree)
	ON_NOTIFY(TVN_GETINFOTIP, IDC_WEB_TREE, &CTreeDlg::OnTvnGetInfoTipWebTree)
END_MESSAGE_MAP()


// CTreeDlg 消息处理程序


BOOL CTreeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	HICON hIcon[3];
	HTREEITEM hRoot;		// 树的根节点的句柄
	HTREEITEM hCataItem;	// 可表示任一分类节点的句柄
	HTREEITEM hArtItem;		// 可表示任一文章节点的句柄

	// 加载图标
	hIcon[0] = theApp.LoadIcon(IDI_HOUSE_ICON);
	hIcon[1] = theApp.LoadIcon(IDI_BLUE_ICON);
	hIcon[2] = theApp.LoadIcon(IDI_RED_ICON);

	m_imageList.Create(32, 32, ILC_COLOR32, 3, 3);
	
	for (int i = 0;i < 3;i++) {
		m_imageList.Add(hIcon[i]);
	}
	
	//m_imageList.Add(hIcon[0]);

	// 为树形控件设置图像序列
	m_webTree.SetImageList(&m_imageList, TVSIL_NORMAL);

	// 插入根节点
	hRoot = m_webTree.InsertItem(_T("分布式电源"));
	hCataItem = m_webTree.InsertItem(_T("实时监控数据"), 1, 1, hRoot, TVI_LAST);
	m_webTree.SetItemData(hCataItem, 1);
	hArtItem = m_webTree.InsertItem(_T("电压"), 2, 2, hCataItem, TVI_LAST);
	m_webTree.SetItemData(hArtItem, 2);
	hArtItem = m_webTree.InsertItem(_T("电流"), 2, 2, hCataItem, TVI_LAST);
	m_webTree.SetItemData(hArtItem, 3);
	hCataItem = m_webTree.InsertItem(_T("实时报警系统"), 1, 1, hRoot, TVI_LAST);
	m_webTree.SetItemData(hCataItem, 4);
	hArtItem = m_webTree.InsertItem(_T("本地报警系统"), 2, 2, hCataItem, TVI_LAST);
	m_webTree.SetItemData(hArtItem, 5);
	hArtItem = m_webTree.InsertItem(_T("电网报警系统"), 2, 2, hCataItem, TVI_LAST);
	m_webTree.SetItemData(hArtItem, 6);
	hCataItem = m_webTree.InsertItem(_T("统计数据"), 1, 1, hRoot, TVI_LAST);
	m_webTree.SetItemData(hCataItem, 7);
	hArtItem = m_webTree.InsertItem(_T("当日电量"), 2, 2, hCataItem, TVI_LAST);
	m_webTree.SetItemData(hArtItem, 8);
	hArtItem = m_webTree.InsertItem(_T("历史电量"), 2, 2, hCataItem, TVI_LAST);
	m_webTree.SetItemData(hArtItem, 9);
	hArtItem = m_webTree.InsertItem(_T("相关历史记录"), 2, 2, hCataItem, TVI_LAST);
	m_webTree.SetItemData(hArtItem, 10);
	hCataItem = m_webTree.InsertItem(_T("相关API"), 1, 1, hRoot, TVI_LAST);
	m_webTree.SetItemData(hCataItem, 11);
	hArtItem = m_webTree.InsertItem(_T("电能转换计算"), 2, 2, hCataItem, TVI_LAST);
	m_webTree.SetItemData(hArtItem, 12);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CTreeDlg::OnTvnSelchangedWebTree(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;

	CString strText; // 树节点的标签文本字符串

	// 获取当前选中节点的句柄
	HTREEITEM hItem = m_webTree.GetSelectedItem();

	// 获取选中节点的标签文本字符串
	strText = m_webTree.GetItemText(hItem);
	// 将字符串显示到编辑框中
	SetDlgItemText(IDC_ITEM_SEL_EDIT, strText);
}


void CTreeDlg::OnTvnGetInfoTipWebTree(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTVGETINFOTIP pGetInfoTip = reinterpret_cast<LPNMTVGETINFOTIP>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	NMTVGETINFOTIP* pTVTipInfo = (NMTVGETINFOTIP*)pNMHDR;
	HTREEITEM hRoot = m_webTree.GetRootItem();
	CString strText;

	if (pTVTipInfo->hItem == hRoot) {
		strText = _T("");
	}
	else {
		strText.Format(_T("%d"), pTVTipInfo->lParam);
	}

	wcscpy(pTVTipInfo->pszText, strText);
}
