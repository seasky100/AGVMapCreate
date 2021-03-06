// CSetCallDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "MapCreater.h"
#include "CSetCallDlg.h"
#include "afxdialogex.h"


// CSetCallDlg 对话框

IMPLEMENT_DYNAMIC(CSetCallDlg, CDialogEx)

CSetCallDlg::CSetCallDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SETCALL_DIALOG, pParent)
	, m_unNo(1)
	, m_unStation(1)
	, m_unRestQueue(0)
	, m_cstrMsg(_T(""))
{
	m_bEdit = false;
	m_cstrAGV = _T("全部");
}

CSetCallDlg::~CSetCallDlg()
{
}

void CSetCallDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NO, m_unNo);
	DDV_MinMaxUInt(pDX, m_unNo, 1, 65535);
	DDX_Text(pDX, IDC_EDIT_STATION, m_unStation);
	DDV_MinMaxUInt(pDX, m_unStation, 1, 65535);
	DDX_Text(pDX, IDC_EDIT_RESTQUEUE, m_unRestQueue);
	DDV_MinMaxUInt(pDX, m_unRestQueue, 0, 65535);
	DDX_Control(pDX, IDC_COMBO_AGV, m_comboAGV);
	DDX_Text(pDX, IDC_EDIT_MSG, m_cstrMsg);
}


BEGIN_MESSAGE_MAP(CSetCallDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT_NO, &CSetCallDlg::OnEnChangeEditNo)
	ON_EN_CHANGE(IDC_EDIT_STATION, &CSetCallDlg::OnEnChangeEditStation)
	ON_EN_CHANGE(IDC_EDIT_RESTQUEUE, &CSetCallDlg::OnEnChangeEditRestqueue)
	ON_EN_CHANGE(IDC_EDIT_MSG, &CSetCallDlg::OnEnChangeEditMsg)
	ON_CBN_SELCHANGE(IDC_COMBO_AGV, &CSetCallDlg::OnCbnSelchangeComboAgv)
	ON_WM_CTLCOLOR()
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CSetCallDlg 消息处理程序


void CSetCallDlg::InitComboBox()
{
	m_comboAGV.InsertString(0, _T("全部"));
	m_comboAGV.InsertString(1, _T("牵引式"));
	m_comboAGV.InsertString(2, _T("潜入式"));
	m_comboAGV.InsertString(3, _T("移载式"));
	m_comboAGV.InsertString(4, _T("叉车式"));
	m_comboAGV.InsertString(5, _T("机械手式"));
	m_comboAGV.InsertString(6, _T("激光式"));

	m_comboAGV.SetCurSel(0);

	return;
}

void CSetCallDlg::OnEnChangeEditNo()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
}


void CSetCallDlg::OnEnChangeEditStation()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
}


void CSetCallDlg::OnEnChangeEditRestqueue()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
}


void CSetCallDlg::OnEnChangeEditMsg()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
}


void CSetCallDlg::OnCbnSelchangeComboAgv()
{
	// TODO: 在此添加控件通知处理程序代码
	m_comboAGV.GetLBText(m_comboAGV.GetCurSel(), m_cstrAGV);
}


BOOL CSetCallDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	InitComboBox();

	if (m_bEdit)
	{
		if (m_cstrAGV == _T("全部"))
		{
			m_comboAGV.SetCurSel(0);
		}
		else if (m_cstrAGV == _T("牵引式"))
		{
			m_comboAGV.SetCurSel(1);
		}
		else if (m_cstrAGV == _T("潜入式"))
		{
			m_comboAGV.SetCurSel(2);
		}
		else if (m_cstrAGV == _T("移载式"))
		{
			m_comboAGV.SetCurSel(3);
		}
		else if (m_cstrAGV == _T("叉车式"))
		{
			m_comboAGV.SetCurSel(4);
		}
		else if (m_cstrAGV == _T("机械手式"))
		{
			m_comboAGV.SetCurSel(5);
		}
		else if (m_cstrAGV == _T("激光式"))
		{
			m_comboAGV.SetCurSel(6);
		}

		UpdateData(false);

		GetDlgItem(IDC_EDIT_NO)->EnableWindow(false);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


HBRUSH CSetCallDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	if (IDC_STATIC_RESTQUEUEHELP == pWnd->GetDlgCtrlID()
		|| IDC_STATIC_AGVHELP == pWnd->GetDlgCtrlID())
	{
		// 红色
		pDC->SetTextColor(RGB(255, 0, 0));
	}

	return hbr;
}


void CSetCallDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
}
