// CSetTVDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "MapCreater.h"
#include "CSetTVDlg.h"
#include "afxdialogex.h"


// CSetTVDlg 对话框

IMPLEMENT_DYNAMIC(CSetTVDlg, CDialogEx)

CSetTVDlg::CSetTVDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SETTV_DIALOG, pParent)
	, m_unNo(1)
	, m_unWidth(1)
	, m_unHeight(1)
	, m_dwIP(0)
	, m_unPort(0)
{
	m_cstrIp = _T("0.0.0.0");
	m_bEdit = false;
}

CSetTVDlg::~CSetTVDlg()
{
}

void CSetTVDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NO, m_unNo);
	DDV_MinMaxUInt(pDX, m_unNo, 1, 65535);
	DDX_Text(pDX, IDC_EDIT_WIDTH, m_unWidth);
	DDV_MinMaxUInt(pDX, m_unWidth, 1, 65535);
	DDX_Text(pDX, IDC_EDIT_HEIGHT, m_unHeight);
	DDV_MinMaxUInt(pDX, m_unHeight, 1, 65535);
	DDX_IPAddress(pDX, IDC_IPADDRESS_TV, m_dwIP);
	DDX_Text(pDX, IDC_EDIT_PORT, m_unPort);
	DDV_MinMaxUInt(pDX, m_unPort, 0, 65535);
}


BEGIN_MESSAGE_MAP(CSetTVDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT_NO, &CSetTVDlg::OnEnChangeEditNo)
	ON_EN_CHANGE(IDC_EDIT_WIDTH, &CSetTVDlg::OnEnChangeEditWidth)
	ON_EN_CHANGE(IDC_EDIT_HEIGHT, &CSetTVDlg::OnEnChangeEditHeight)
	ON_NOTIFY(IPN_FIELDCHANGED, IDC_IPADDRESS_TV, &CSetTVDlg::OnIpnFieldchangedIpaddressTv)
	ON_EN_CHANGE(IDC_EDIT_PORT, &CSetTVDlg::OnEnChangeEditPort)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CSetTVDlg 消息处理程序


void CSetTVDlg::OnEnChangeEditNo()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
}


void CSetTVDlg::OnEnChangeEditWidth()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
}


void CSetTVDlg::OnEnChangeEditHeight()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
}


void CSetTVDlg::OnIpnFieldchangedIpaddressTv(NMHDR *pNMHDR, LRESULT *pResult)
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


void CSetTVDlg::OnEnChangeEditPort()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
}


BOOL CSetTVDlg::OnInitDialog()
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


void CSetTVDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
}
