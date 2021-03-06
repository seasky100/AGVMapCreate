// CSetChargerCtrlDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "MapCreater.h"
#include "CSetChargerCtrlDlg.h"
#include "afxdialogex.h"


// CSetChargerCtrlDlg 对话框

IMPLEMENT_DYNAMIC(CSetChargerCtrlDlg, CDialogEx)

CSetChargerCtrlDlg::CSetChargerCtrlDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SETCHARGERCTRL_DIALOG, pParent)
	, m_unNo(1)
	, m_dwIP(0)
	, m_unPort(0)
{
	m_cstrIp = _T("0.0.0.0");
	m_bEdit = false;
}

CSetChargerCtrlDlg::~CSetChargerCtrlDlg()
{
}

void CSetChargerCtrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NO, m_unNo);
	DDV_MinMaxUInt(pDX, m_unNo, 1, 65535);
	DDX_IPAddress(pDX, IDC_IPADDRESS_CHARGERCTRL, m_dwIP);
	DDX_Text(pDX, IDC_EDIT_PORT, m_unPort);
	DDV_MinMaxUInt(pDX, m_unPort, 0, 65535);
}


BEGIN_MESSAGE_MAP(CSetChargerCtrlDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT_NO, &CSetChargerCtrlDlg::OnEnChangeEditNo)
	ON_NOTIFY(IPN_FIELDCHANGED, IDC_IPADDRESS_CHARGERCTRL, &CSetChargerCtrlDlg::OnIpnFieldchangedIpaddressChargerctrl)
	ON_EN_CHANGE(IDC_EDIT_PORT, &CSetChargerCtrlDlg::OnEnChangeEditPort)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CSetChargerCtrlDlg 消息处理程序


void CSetChargerCtrlDlg::OnEnChangeEditNo()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
}


void CSetChargerCtrlDlg::OnIpnFieldchangedIpaddressChargerctrl(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMIPADDRESS pIPAddr = reinterpret_cast<LPNMIPADDRESS>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;

	UpdateData(true);

	m_cstrIp.Format(_T("%d.%d.%d.%d"),
		(m_dwIP >> 24) & 0xff,
		(m_dwIP >> 16) & 0xff,
		(m_dwIP >> 8) & 0xff,
		m_dwIP & 0xff);
}


void CSetChargerCtrlDlg::OnEnChangeEditPort()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
}

BOOL CSetChargerCtrlDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	if (m_bEdit)
	{
		m_dwIP = ntohl(inet_addr(CStringA(m_cstrIp).GetBuffer()));

		UpdateData(false);

		GetDlgItem(IDC_EDIT_NO)->EnableWindow(false);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CSetChargerCtrlDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
}