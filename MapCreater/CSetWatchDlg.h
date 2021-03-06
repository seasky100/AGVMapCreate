#pragma once


// CSetWatchDlg 对话框

class CSetWatchDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSetWatchDlg)

public:
	CSetWatchDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CSetWatchDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SETWATCH_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	unsigned int m_unNo;		/*!< 编号 */
	unsigned int m_unCA;		/*!< 主机号 */
	unsigned int m_unStation;	/*!< 工位号 */
	bool m_bEdit;				/*!< 编辑标识 */
public:
	afx_msg void OnEnChangeEditNo();
	afx_msg void OnEnChangeEditCa();
	afx_msg void OnEnChangeEditStation();
	virtual BOOL OnInitDialog();
};
