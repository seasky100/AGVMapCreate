#pragma once


// CSetAGVDlg 对话框

class CSetAGVDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSetAGVDlg)

public:
	CSetAGVDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CSetAGVDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SETAGV_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

public:
	unsigned int m_unNo;	/*!< 编号*/
	unsigned int m_unPort;	/*!< 端口 */
	CString m_cstrIp;		/*!< IP地址 */
	CString m_cstrType;		/*!< 类型 */
	CString m_cstrMove;		/*!< 可运动方向 */
	bool m_bEdit;			/*!< 编辑标识 */

protected:
	CComboBox m_comboType;	/*!< 类型下拉列表 */
	DWORD m_dwIP;			/*!< IP地址 */
	int m_nMove;			/*!< 可运动方向 */

protected:
	/*!
	 * @brief 初始化下拉列表
	*/
	void InitComboBox();

public:
	afx_msg void OnEnChangeEditNo();
	afx_msg void OnCbnSelchangeComboType();
	afx_msg void OnBnClickedRadioSingle();
	afx_msg void OnBnClickedRadioDouble();
	afx_msg void OnBnClickedRadioFull();
	afx_msg void OnIpnFieldchangedIpaddressAgv(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEditPort();
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnBnClickedOk();
};
