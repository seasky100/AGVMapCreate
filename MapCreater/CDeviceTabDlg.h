#pragma once
#include "CAGVListDlg.h"
#include "CTVListDlg.h"
#include "CChargerCtrlListDlg.h"
#include "CCAListDlg.h"
#include "CCallListDlg.h"
#include "CWatchListDlg.h"

// CDeviceTabDlg 对话框

class CDeviceTabDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CDeviceTabDlg)

public:
	CDeviceTabDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDeviceTabDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DEVICETAB_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
protected:
	enum TABDLG
	{
		TABDLG_AGV,		/*!< AGV设备列表框 */
		TABDLG_TV,		/*!< 显示器列表框 */
		TABDLG_CHARGER,	/*!< 充电控制器列表框 */
		TABDLG_CA,		/*!< 无线主机列表框 */
		TABDLG_CALL,	/*!< 无线呼叫器列表框 */
		TABDLG_WATCH,	/*!< 无线手表列表框 */
	};

public:
	CTabCtrl m_tabDevice;
	CAGVListDlg m_dlgAGVList;
	CTVListDlg m_dlgTVList;
	CChargerCtrlListDlg m_dlgChargerCtrlList;
	CCAListDlg m_dlgCAList;
	CCallListDlg m_dlgCallList;
	CWatchListDlg m_dlgWatchList;

protected:
	/*!
	 * @brief 初始化Tab
	*/
	void InitTab();

public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnTcnSelchangeTabDevice(NMHDR *pNMHDR, LRESULT *pResult);
};
