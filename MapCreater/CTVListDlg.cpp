// CTVListDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "MapCreater.h"
#include "CTVListDlg.h"
#include "afxdialogex.h"
#include "Xml.h"
#include "CSetTVDlg.h"


// CTVListDlg 对话框

IMPLEMENT_DYNAMIC(CTVListDlg, CDialogEx)

CTVListDlg::CTVListDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TVLIST_DIALOG, pParent)
{

}

CTVListDlg::~CTVListDlg()
{
}

void CTVListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listTV);
}


BEGIN_MESSAGE_MAP(CTVListDlg, CDialogEx)
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CTVListDlg::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_EDIT, &CTVListDlg::OnBnClickedButtonEdit)
	ON_BN_CLICKED(IDC_BUTTON_DEL, &CTVListDlg::OnBnClickedButtonDel)
	ON_BN_CLICKED(IDC_BUTTON_DELALL, &CTVListDlg::OnBnClickedButtonDelall)
END_MESSAGE_MAP()


// CTVListDlg 消息处理程序

void CTVListDlg::SortList()
{
	int nRow = m_listTV.GetItemCount();
	int nCol = 5;

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
			ppCStrList[i][l] = m_listTV.GetItemText(i, l);
		}
	}

	/*!
	 * 根据条件进行排序
	 * TV的排序条件为TV编号
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
			m_listTV.SetItemText(i, j, ppCStrList[i][j]);
		}
	}

	for (int i = 0; i < nRow; i++)
	{
		delete[] ppCStrList[i];
	}

	delete[] ppCStrList;

	return;
}

bool CTVListDlg::Output(CString cstrFilePath)
{
	TRACE(_T("开始导出显示器信息.\r\n"));

	TiXmlDocument xmlDoc; /*!< XML文档 */
	if (xmlDoc.LoadFile(CStringA(cstrFilePath).GetBuffer()) == false)
	{
		TRACE(_T("显示器信息导出失败.\r\n"));
		return false;
	}

	TiXmlElement *pXmlRoot = xmlDoc.FirstChildElement(); /*!< 根节点 */
	if (pXmlRoot == NULL)
	{
		TRACE(_T("显示器信息导出失败.\r\n"));
		return false;
	}

	/*!
	 * 写入TV信息
	*/
	for (int i = 0; i < m_listTV.GetItemCount(); i++)
	{
		TiXmlElement element("TV");	/*!< 子节点 */
		element.SetAttribute("No", CStringA(m_listTV.GetItemText(i, TVLIST_NO)));
		element.SetAttribute("Width", CStringA(m_listTV.GetItemText(i, TVLIST_WIDTH)));
		element.SetAttribute("Height", CStringA(m_listTV.GetItemText(i, TVLIST_HEIGHT)));
		element.SetAttribute("IP", CStringA(m_listTV.GetItemText(i, TVLIST_IP)));
		element.SetAttribute("Port", CStringA(m_listTV.GetItemText(i, TVLIST_PORT)));

		pXmlRoot->InsertEndChild(element);

	}

	TRACE(_T("显示器信息导出完成.\r\n"));

	return xmlDoc.SaveFile(CStringA(cstrFilePath));
}

bool CTVListDlg::Input(CString cstrFilePath)
{
	TRACE(_T("开始导入显示器信息.\r\n"));

	m_listTV.DeleteAllItems();

	TiXmlDocument xmlDoc; /*!< XML文档 */
	if (xmlDoc.LoadFile(CStringA(cstrFilePath).GetBuffer()) == false)
	{
		TRACE(_T("显示器信息导入失败.\r\n"));
		return false;
	}

	TiXmlElement *pXmlRoot = xmlDoc.FirstChildElement(); /*!< 根节点 */
	if (pXmlRoot == NULL || pXmlRoot->NoChildren())
	{
		TRACE(_T("显示器信息导入失败.\r\n"));
		return false;
	}

	TiXmlElement *pXmlElemt = pXmlRoot->FirstChildElement(); /*!< 子节点*/

	while (pXmlElemt)
	{
		CString cstrElemtName(pXmlElemt->Value()); /*!< 子节点名称 */

		/*!
		 * 读取TV信息
		*/
		if (cstrElemtName == _T("TV"))
		{
			TiXmlAttribute *pAttr = pXmlElemt->FirstAttribute(); /*!< 子节点属性 */

			CString cstrNo = _T("0");		/*!< 编号 */
			CString cstrWidth = _T("");		/*!< 宽 */
			CString cstrHeight = _T("");	/*!< 高 */
			CString cstrIp = _T("0.0.0.0");	/*!< IP地址 */
			CString cstrPort = _T("0");		/*!< 端口 */

			while (pAttr)
			{
				CString cstrAttrName(pAttr->Name());	/*!< 属性名称*/
				CString cstrAttrValue(pAttr->Value()); /*!< 属性值 */

				pAttr = pAttr->Next();

				if (cstrAttrName == _T("No"))
				{
					cstrNo = cstrAttrValue;
				}
				else if (cstrAttrName == _T("Width"))
				{
					cstrWidth = cstrAttrValue;
				}
				else if (cstrAttrName == _T("Height"))
				{
					cstrHeight = cstrAttrValue;
				}
				else if (cstrAttrName == _T("IP"))
				{
					cstrIp = cstrAttrValue;
				}
				else if (cstrAttrName == _T("Port"))
				{
					cstrPort = cstrAttrValue;
				}
			}

			int nRow = m_listTV.InsertItem(m_listTV.GetItemCount(), cstrNo);
			m_listTV.SetItemText(nRow, TVLIST_WIDTH, cstrWidth);
			m_listTV.SetItemText(nRow, TVLIST_HEIGHT, cstrHeight);
			m_listTV.SetItemText(nRow, TVLIST_IP, cstrIp);
			m_listTV.SetItemText(nRow, TVLIST_PORT, cstrPort);
		}

		pXmlElemt = pXmlElemt->NextSiblingElement();
	}

	SortList();

	TRACE(_T("显示器信息导入完成.\r\n"));

	return true;
}

void CTVListDlg::InitList()
{
	m_listTV.InsertColumn(0, _T(""), LVCFMT_CENTER);
	m_listTV.InsertColumn(TVLIST_NO + 1, _T("编号"), LVCFMT_CENTER);
	m_listTV.InsertColumn(TVLIST_WIDTH + 1, _T("宽"), LVCFMT_CENTER);
	m_listTV.InsertColumn(TVLIST_HEIGHT + 1, _T("高"), LVCFMT_CENTER);
	m_listTV.InsertColumn(4 + 1, _T("IP地址"), LVCFMT_CENTER);
	m_listTV.InsertColumn(5 + 1, _T("端口"), LVCFMT_CENTER);
	m_listTV.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_DOUBLEBUFFER);
	m_listTV.DeleteColumn(0);

	return;
}

void CTVListDlg::ListSize()
{
	if (GetDlgItem(IDC_BUTTON_DEL)->GetSafeHwnd() == nullptr
		|| GetDlgItem(IDC_BUTTON_DELALL)->GetSafeHwnd() == nullptr
		|| GetDlgItem(IDC_BUTTON_EDIT)->GetSafeHwnd() == nullptr
		|| GetDlgItem(IDC_BUTTON_ADD)->GetSafeHwnd() == nullptr
		|| m_listTV.GetSafeHwnd() == nullptr)
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

	GetDlgItem(IDC_BUTTON_ADD)->MoveWindow(CRect(rect.left + nDis, rect.top, rect.left + nDis + nWidth, rect.top + nHeight));
	GetDlgItem(IDC_BUTTON_EDIT)->MoveWindow(CRect(rect.left + nDis * 2 + nWidth, rect.top, rect.left + nDis * 2 + nWidth * 2, rect.top + nHeight));
	GetDlgItem(IDC_BUTTON_DEL)->MoveWindow(CRect(rect.left + nDis * 3 + nWidth * 2, rect.top, rect.left + nDis * 3 + nWidth * 3, rect.top + nHeight));
	GetDlgItem(IDC_BUTTON_DELALL)->MoveWindow(CRect(rect.left + nDis * 4 + nWidth * 3, rect.top, rect.left + nDis * 4 + nWidth * 4, rect.top + nHeight));

	rect.top += nHeight + 5;
	m_listTV.MoveWindow(rect);

	/*!
	 * 调整列表中列的宽度
	*/
	m_listTV.GetClientRect(&rect);

	m_listTV.SetColumnWidth(TVLIST_NO, rect.Width() / 6);
	m_listTV.SetColumnWidth(TVLIST_WIDTH, rect.Width() / 6);
	m_listTV.SetColumnWidth(TVLIST_HEIGHT, rect.Width() / 6);
	m_listTV.SetColumnWidth(TVLIST_IP, rect.Width() * 2 / 6);
	m_listTV.SetColumnWidth(TVLIST_PORT, rect.Width() / 6);

	return;
}


BOOL CTVListDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	InitList();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CTVListDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
	ListSize();
}

BOOL CTVListDlg::PreTranslateMessage(MSG * pMsg)
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

void CTVListDlg::OnBnClickedButtonAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	CSetTVDlg setTVDlg;
	if (setTVDlg.DoModal() == IDOK)
	{
		for (int i = 0; i < m_listTV.GetItemCount(); i++)
		{
			if (setTVDlg.m_unNo == _ttoi(m_listTV.GetItemText(i, TVLIST_NO)))
			{
				MessageBox(_T("已存在相同编号的显示器设备!"), _T("添加失败"), MB_ICONERROR);
				return;
			}
		}

		CString cstrText = _T("");
		cstrText.Format(_T("%d"), setTVDlg.m_unNo);

		int nRow = m_listTV.InsertItem(m_listTV.GetItemCount(), cstrText);

		cstrText.Format(_T("%d"), setTVDlg.m_unWidth);
		m_listTV.SetItemText(nRow, TVLIST_WIDTH, cstrText);

		cstrText.Format(_T("%d"), setTVDlg.m_unHeight);
		m_listTV.SetItemText(nRow, TVLIST_HEIGHT, cstrText);

		m_listTV.SetItemText(nRow, TVLIST_IP, setTVDlg.m_cstrIp);


		cstrText.Format(_T("%d"), setTVDlg.m_unPort);
		m_listTV.SetItemText(nRow, TVLIST_PORT, cstrText);

		SortList();
	}

	return;
}


void CTVListDlg::OnBnClickedButtonEdit()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i = 0; i < m_listTV.GetItemCount(); i++)
	{
		if (m_listTV.GetItemState(i, LVNI_SELECTED) == LVNI_SELECTED)
		{
			CSetTVDlg setTVDlg;
			setTVDlg.m_unNo = _ttoi(m_listTV.GetItemText(i, TVLIST_NO));
			setTVDlg.m_unWidth = _ttoi(m_listTV.GetItemText(i, TVLIST_WIDTH));
			setTVDlg.m_unHeight = _ttoi(m_listTV.GetItemText(i, TVLIST_HEIGHT));
			setTVDlg.m_cstrIp = m_listTV.GetItemText(i, TVLIST_IP);
			setTVDlg.m_unPort = _ttoi(m_listTV.GetItemText(i, TVLIST_PORT));
			setTVDlg.m_bEdit = true;

			if (setTVDlg.DoModal() == IDOK)
			{
				CString cstrText = _T("");
				cstrText.Format(_T("%d"), setTVDlg.m_unWidth);
				m_listTV.SetItemText(i, TVLIST_WIDTH, cstrText);

				cstrText.Format(_T("%d"), setTVDlg.m_unHeight);
				m_listTV.SetItemText(i, TVLIST_HEIGHT, cstrText);

				m_listTV.SetItemText(i, TVLIST_IP, setTVDlg.m_cstrIp);


				cstrText.Format(_T("%d"), setTVDlg.m_unPort);
				m_listTV.SetItemText(i, TVLIST_PORT, cstrText);
				
			}

			return;
		}
	}

	return;
}


void CTVListDlg::OnBnClickedButtonDel()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i = 0; i < m_listTV.GetItemCount();)
	{
		if (m_listTV.GetItemState(i, LVNI_SELECTED) == LVNI_SELECTED)
		{
			m_listTV.DeleteItem(i);
		}
		else
		{
			i++;
		}
	}

	return;
}


void CTVListDlg::OnBnClickedButtonDelall()
{
	// TODO: 在此添加控件通知处理程序代码
	m_listTV.DeleteAllItems();
	return;
}