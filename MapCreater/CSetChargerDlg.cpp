// CSetChargerDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "MapCreater.h"
#include "CSetChargerDlg.h"
#include "afxdialogex.h"


// CSetChargerDlg 对话框

IMPLEMENT_DYNAMIC(CSetChargerDlg, CDialogEx)

CSetChargerDlg::CSetChargerDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SETCHARGER_DIALOG, pParent)
	, m_unNo(1)
	, m_unMark(1)
	, m_unCtrl(0)
{
	m_bEdit = false;
}

CSetChargerDlg::~CSetChargerDlg()
{
}

void CSetChargerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NO, m_unNo);
	DDV_MinMaxUInt(pDX, m_unNo, 1, 65535);
	DDX_Text(pDX, IDC_EDIT_MARK, m_unMark);
	DDV_MinMaxUInt(pDX, m_unMark, 1, 65535);
	DDX_Text(pDX, IDC_EDIT_CTRL, m_unCtrl);
	DDV_MinMaxUInt(pDX, m_unCtrl, 0, 65535);
}


BEGIN_MESSAGE_MAP(CSetChargerDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT_NO, &CSetChargerDlg::OnEnChangeEditNo)
	ON_EN_CHANGE(IDC_EDIT_MARK, &CSetChargerDlg::OnEnChangeEditMark)
	ON_EN_CHANGE(IDC_EDIT_CTRL, &CSetChargerDlg::OnEnChangeEditCtrl)
END_MESSAGE_MAP()


// CSetChargerDlg 消息处理程序


void CSetChargerDlg::OnEnChangeEditNo()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
}


void CSetChargerDlg::OnEnChangeEditMark()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
}


void CSetChargerDlg::OnEnChangeEditCtrl()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
}


BOOL CSetChargerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	if (m_bEdit)
	{
		UpdateData(false);
		GetDlgItem(IDC_EDIT_NO)->EnableWindow(false);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
