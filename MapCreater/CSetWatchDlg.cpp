// CSetWatchDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "MapCreater.h"
#include "CSetWatchDlg.h"
#include "afxdialogex.h"


// CSetWatchDlg 对话框

IMPLEMENT_DYNAMIC(CSetWatchDlg, CDialogEx)

CSetWatchDlg::CSetWatchDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SETWATCH_DIALOG, pParent)
	, m_unNo(1)
	, m_unCA(1)
	, m_unStation(1)
{
	m_bEdit = false;
}

CSetWatchDlg::~CSetWatchDlg()
{
}

void CSetWatchDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NO, m_unNo);
	DDV_MinMaxUInt(pDX, m_unNo, 1, 65535);
	DDX_Text(pDX, IDC_EDIT_CA, m_unCA);
	DDV_MinMaxUInt(pDX, m_unCA, 1, 65535);
	DDX_Text(pDX, IDC_EDIT_STATION, m_unStation);
	DDV_MinMaxUInt(pDX, m_unStation, 1, 65535);
}


BEGIN_MESSAGE_MAP(CSetWatchDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT_NO, &CSetWatchDlg::OnEnChangeEditNo)
	ON_EN_CHANGE(IDC_EDIT_CA, &CSetWatchDlg::OnEnChangeEditCa)
	ON_EN_CHANGE(IDC_EDIT_STATION, &CSetWatchDlg::OnEnChangeEditStation)
END_MESSAGE_MAP()


// CSetWatchDlg 消息处理程序


void CSetWatchDlg::OnEnChangeEditNo()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
}


void CSetWatchDlg::OnEnChangeEditCa()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
}


void CSetWatchDlg::OnEnChangeEditStation()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
}


BOOL CSetWatchDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	if (m_bEdit)
	{
		GetDlgItem(IDC_EDIT_NO)->EnableWindow(false);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
