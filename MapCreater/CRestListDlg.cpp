// CRestListDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "MapCreater.h"
#include "CRestListDlg.h"
#include "afxdialogex.h"
#include "CSetRestDlg.h"
#include "MainFrm.h"
#include "MapCreaterView.h"

// CRestListDlg 对话框

IMPLEMENT_DYNAMIC(CRestListDlg, CDialogEx)

CRestListDlg::CRestListDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_RESTLIST_DIALOG, pParent)
{

}

CRestListDlg::~CRestListDlg()
{
}

void CRestListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_REST, m_listRest);
}


BEGIN_MESSAGE_MAP(CRestListDlg, CDialogEx)
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_BUTTON_LOCATION, &CRestListDlg::OnBnClickedButtonLocation)
	ON_BN_CLICKED(IDC_BUTTON_EDIT, &CRestListDlg::OnBnClickedButtonEdit)
	ON_BN_CLICKED(IDC_BUTTON_DEL, &CRestListDlg::OnBnClickedButtonDel)
	ON_BN_CLICKED(IDC_BUTTON_DELALL, &CRestListDlg::OnBnClickedButtonDelall)
END_MESSAGE_MAP()


// CRestListDlg 消息处理程序
void CRestListDlg::SortList()
{
	int nRow = m_listRest.GetItemCount();
	int nCol = 3;

	if (nRow < 2)
	{
		return;
	}

	/*!
	 * 将列表成员放入数组集合
	 * 列表成员为字符串数组
	*/
	CString **ppCStrList = new CString*[nRow];

	for (int i = 0; i < nRow; i++)
	{
		ppCStrList[i] = new CString[nCol];
	}

	for (int i = 0; i < nRow; i++)
	{
		for (int l = 0; l < nCol; l++)
		{
			ppCStrList[i][l] = m_listRest.GetItemText(i, l);
		}
	}

	/*!
	 * 根据条件进行排序
	 * 待机位的排序条件为待机位号
	 * 冒泡排序
	*/
	for (int i = 1; i < nRow; i++)
	{
		for (int j = 0; j < nRow - i; j++)
		{
			if (_ttoi(ppCStrList[j][0]) > _ttoi(ppCStrList[j + 1][0]))
			{
				CString *pCStrItem = ppCStrList[j];
				ppCStrList[j] = ppCStrList[j + 1];
				ppCStrList[j + 1] = pCStrItem;
			}
		}
	}

	for (int i = 0; i < nRow; i++)
	{
		for (int j = 0; j < nCol; j++)
		{
			m_listRest.SetItemText(i, j, ppCStrList[i][j]);
		}
	}

	for (int i = 0; i < nRow; i++)
	{
		delete[] ppCStrList[i];
	}

	delete[] ppCStrList;

	return;
}

void CRestListDlg::Delete(unsigned int unRest)
{
	/*!
	 * 通知界面删除工位图形
	*/
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	CMapCreaterView* pView = (CMapCreaterView*)pMainFrame->GetActiveView();
	pView->DeleteRest(unRest);

	return;
}

void CRestListDlg::DeleteAll()
{
	/*!
	 * 通知界面删除所有工位图形
	*/
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	CMapCreaterView* pView = (CMapCreaterView*)pMainFrame->GetActiveView();
	pView->DeleteAllRest();

	return;
}

void CRestListDlg::Locate(unsigned int unRest)
{
	/*!
	 * 通知界面定位选中的工位
	*/
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	CMapCreaterView* pView = (CMapCreaterView*)pMainFrame->GetActiveView();
	pView->LocateRest(unRest);

	return;
}

void CRestListDlg::Update(unsigned int unRest, unsigned int unMark)
{
	/*!
	 * 通知界面更新工位属性
	*/
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	CMapCreaterView* pView = (CMapCreaterView*)pMainFrame->GetActiveView();
	pView->UpdateRest(unRest, unMark);

	return;
}

void CRestListDlg::Add(unsigned int unRest, CPoint ptCenter, unsigned int unMark)
{
	CString cstrNo = _T("");
	CString cstrPoint = _T("");
	CString cstrMark = _T("");
	cstrNo.Format(_T("%d"), unRest);
	cstrPoint.Format(_T("%d,%d"), ptCenter.x, ptCenter.y);
	cstrMark.Format(_T("%d"), unMark);

	int nRow = -1;

	for (int i = 0; i < m_listRest.GetItemCount(); i++)
	{
		if (unRest == _ttoi(m_listRest.GetItemText(i, 0)))
		{
			nRow = i;
			break;
		}
	}

	if (nRow == -1)
	{
		nRow = m_listRest.InsertItem(m_listRest.GetItemCount(), cstrNo);
		m_listRest.SetItemText(nRow, 1, cstrPoint);
		m_listRest.SetItemText(nRow, 2, cstrMark);

		SortList();
	}
	else
	{
		m_listRest.SetItemText(nRow, 1, cstrPoint);
		m_listRest.SetItemText(nRow, 2, cstrMark);
	}

	return;
}

void CRestListDlg::DeleteItem(unsigned int unRest)
{
	for (int i = 0; i < m_listRest.GetItemCount(); i++)
	{
		if (unRest == _ttoi(m_listRest.GetItemText(i, 0)))
		{
			m_listRest.DeleteItem(i);

			return;
		}
	}

	return;
}

void CRestListDlg::InitList()
{
	m_listRest.InsertColumn(0, _T(""), LVCFMT_CENTER);
	m_listRest.InsertColumn(1, _T("编号"), LVCFMT_CENTER);
	m_listRest.InsertColumn(2, _T("坐标"), LVCFMT_CENTER);
	m_listRest.InsertColumn(3, _T("地标卡"), LVCFMT_CENTER);
	m_listRest.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_DOUBLEBUFFER);
	m_listRest.DeleteColumn(0);

	return;
}

void CRestListDlg::ListSize()
{
	if (GetDlgItem(IDC_BUTTON_DEL)->GetSafeHwnd() == nullptr
		|| GetDlgItem(IDC_BUTTON_DELALL)->GetSafeHwnd() == nullptr
		|| GetDlgItem(IDC_BUTTON_LOCATION)->GetSafeHwnd() == nullptr
		|| GetDlgItem(IDC_BUTTON_EDIT)->GetSafeHwnd() == nullptr
		|| m_listRest.GetSafeHwnd() == nullptr)
	{
		return;
	}

	CRect rect;
	GetClientRect(&rect);

	/*!
	 * 调整对话框中的空间位置
	*/

	int nWidth = 100;	/*!< 宽 */
	int nHeight = 30;	/*!< 高 */

	rect.top += 5;
	int nDis = (rect.Width() - 4 * nWidth) / 5;

	GetDlgItem(IDC_BUTTON_LOCATION)->MoveWindow(CRect(rect.left + nDis, rect.top, rect.left + nDis + nWidth, rect.top + nHeight));
	GetDlgItem(IDC_BUTTON_EDIT)->MoveWindow(CRect(rect.left + nDis * 2 + nWidth, rect.top, rect.left + nDis * 2 + nWidth * 2, rect.top + nHeight));
	GetDlgItem(IDC_BUTTON_DEL)->MoveWindow(CRect(rect.left + nDis * 3 + nWidth * 2, rect.top, rect.left + nDis * 3 + nWidth * 3, rect.top + nHeight));
	GetDlgItem(IDC_BUTTON_DELALL)->MoveWindow(CRect(rect.left + nDis * 4 + nWidth * 3, rect.top, rect.left + nDis * 4 + nWidth * 4, rect.top + nHeight));

	rect.top += nHeight + 5;
	m_listRest.MoveWindow(rect);

	/*!
	 * 调整列表中列的宽度
	*/
	m_listRest.GetClientRect(&rect);

	m_listRest.SetColumnWidth(0, rect.Width() / 3);
	m_listRest.SetColumnWidth(1, rect.Width() / 3);
	m_listRest.SetColumnWidth(2, rect.Width() / 3);

	return;
}

BOOL CRestListDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	InitList();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CRestListDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
	ListSize();

	return;
}

BOOL CRestListDlg::PreTranslateMessage(MSG * pMsg)
{
	switch (pMsg->wParam)
	{
	case VK_ESCAPE:
		return TRUE;
	case VK_RETURN:
		return TRUE;
	}

	return CDialog::PreTranslateMessage(pMsg);
}


void CRestListDlg::OnBnClickedButtonLocation()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i = 0; i < m_listRest.GetItemCount(); i++)
	{
		if (m_listRest.GetItemState(i, LVNI_SELECTED) == LVNI_SELECTED)
		{
			Locate(_ttoi(m_listRest.GetItemText(i, 0)));

			return;
		}
	}

	return;
}


void CRestListDlg::OnBnClickedButtonEdit()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i = 0; i < m_listRest.GetItemCount(); i++)
	{
		if (m_listRest.GetItemState(i, LVNI_SELECTED) == LVNI_SELECTED)
		{
			CSetRestDlg setRestDlg;
			setRestDlg.m_unNo = _ttoi(m_listRest.GetItemText(i, 0));
			setRestDlg.m_unMark = _ttoi(m_listRest.GetItemText(i, 2));
			setRestDlg.m_bEdit = true;

			if (setRestDlg.DoModal() == IDOK)
			{
				CString cstrMark = _T("");
				cstrMark.Format(_T("%d"), setRestDlg.m_unMark);

				m_listRest.SetItemText(i, 2, cstrMark);

				Update(setRestDlg.m_unNo, setRestDlg.m_unMark);
			}

			return;
		}
	}

	return;
}


void CRestListDlg::OnBnClickedButtonDel()
{
	// TODO: 在此添加控件通知处理程序代码
	/*!
	 * 删除勾选的
	*/
	for (int i = 0; i < m_listRest.GetItemCount();)
	{
		if (m_listRest.GetItemState(i, LVNI_SELECTED) == LVNI_SELECTED)
		{
			Delete(_ttoi(m_listRest.GetItemText(i, 0)));
			m_listRest.DeleteItem(i);
		}
		else
		{
			i++;
		}
	}

	return;
}


void CRestListDlg::OnBnClickedButtonDelall()
{
	// TODO: 在此添加控件通知处理程序代码
	DeleteAll();
	m_listRest.DeleteAllItems();

	return;
}
