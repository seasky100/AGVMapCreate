// CSetStationDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "MapCreater.h"
#include "CSetStationDlg.h"
#include "afxdialogex.h"


// CSetStationDlg 对话框

IMPLEMENT_DYNAMIC(CSetStationDlg, CDialogEx)

CSetStationDlg::CSetStationDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SETSTATION_DIALOG, pParent)
	, m_unNo(1)
	, m_cstrName(_T(""))
	, m_unMark(1)
	, m_bEdit(false)
{

}

CSetStationDlg::~CSetStationDlg()
{
}

void CSetStationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NO, m_unNo);
	DDV_MinMaxUInt(pDX, m_unNo, 1, 65535);
	DDX_Text(pDX, IDC_EDIT_NAME, m_cstrName);
	DDX_Text(pDX, IDC_EDIT_MARK, m_unMark);
	DDV_MinMaxUInt(pDX, m_unMark, 1, 65535);
}


BEGIN_MESSAGE_MAP(CSetStationDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT_NO, &CSetStationDlg::OnEnChangeEditNo)
	ON_EN_CHANGE(IDC_EDIT_NAME, &CSetStationDlg::OnEnChangeEditName)
	ON_EN_CHANGE(IDC_EDIT_MARK, &CSetStationDlg::OnEnChangeEditMark)
END_MESSAGE_MAP()


// CSetStationDlg 消息处理程序


void CSetStationDlg::OnEnChangeEditNo()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
}


void CSetStationDlg::OnEnChangeEditName()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
}


void CSetStationDlg::OnEnChangeEditMark()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
}


BOOL CSetStationDlg::OnInitDialog()
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
