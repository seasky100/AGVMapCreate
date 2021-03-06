#pragma once


// CStationListDlg 对话框

class CStationListDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CStationListDlg)

public:
	CStationListDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CStationListDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STATIONLIST_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_listStation;

protected:
	/*!
	 * @brief 为列表成员排序
	*/
	void SortList();

	/*!
	 * @brief 删除列表成员
	 *
	 * 通知界面删除工位图形
	 * @param unStation 工位编号
	*/
	void Delete(unsigned int unStation);

	/*!
	 * @brief 删除全部成员
	 *
	 * 通知界面删除所有工位图形
	*/
	void DeleteAll();

	/*!
	 * @brief 定位
	 *
	 * 通知界面定位工位图形
	 * @param unStation 工位编号
	*/
	void Locate(unsigned int unStation);

	/*!
	 * @brief 更新列表成员
	 *
	 * 通知界面更新工位图形
	 * @param unStation 工位编号
	 * @param cstrName 工位名称
	 * @param unMark 工位所在地标卡编号
	*/
	void Update(unsigned int unStation, CString cstrName, unsigned int unMark);

public:
	/*!
	 * @brief 添加列表成员
	 * @param unStation 工位编号
	 * @param ptCenter 工位中心坐标
	 * @param cstrName 工位名称
	 * @param unMark 工位所在地标卡编号
	*/
	void Add(unsigned int unStation, CPoint ptCenter,CString cstrName,unsigned int unMark);

	/*!
	 * @brief 删除列表成员
	 * @param unStation 工位编号
	*/
	void DeleteItem(unsigned int unStation);

protected:
	/*!
	 * @brief 初始化列表
	*/
	void InitList();

	/*!
	 * @brief 列表尺寸变更
	*/
	void ListSize();

public:
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedButtonLocation();
	afx_msg void OnBnClickedButtonEdit();
	afx_msg void OnBnClickedButtonDel();
	afx_msg void OnBnClickedButtonDelall();
};
