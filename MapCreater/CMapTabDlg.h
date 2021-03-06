#pragma once
#include "CMarkListDlg.h"
#include "CStationListDlg.h"
#include "CRestListDlg.h"
#include "CChargerListDlg.h"

// CMapTabDlg 对话框

class CMapTabDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMapTabDlg)

public:
	CMapTabDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CMapTabDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MAPTAB_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
protected:
	enum TABDLG
	{
		TABDLG_MARK,	/*!< 地标卡列表框 */
		TABDLG_STATION,	/*!< 工位列表框 */
		TABDLG_REST,	/*!< 待机位列表框 */
		TABDLG_CHARGER,	/*!< 充电器列表框 */
	};
public:
	CTabCtrl m_tabMap;
	CMarkListDlg m_dlgMarkList;
	CStationListDlg m_dlgStationList;
	CRestListDlg m_dlgRestList;
	CChargerListDlg m_dlgChargerList;

protected:
	/*!
	 * @brief 初始化Tab
	*/
	void InitTab();

public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnTcnSelchangeTabMap(NMHDR *pNMHDR, LRESULT *pResult);
};
