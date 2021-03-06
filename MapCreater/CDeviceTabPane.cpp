// CDeviceTabPane.cpp: 实现文件
//

#include "stdafx.h"
#include "MapCreater.h"
#include "CDeviceTabPane.h"


// CDeviceTabPane

IMPLEMENT_DYNAMIC(CDeviceTabPane, CDockablePane)

CDeviceTabPane::CDeviceTabPane()
{

}

CDeviceTabPane::~CDeviceTabPane()
{
}


BEGIN_MESSAGE_MAP(CDeviceTabPane, CDockablePane)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_DESTROY()
	ON_WM_CONTEXTMENU()
END_MESSAGE_MAP()



// CDeviceTabPane 消息处理程序
int CDeviceTabPane::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	if (!m_dlgDeviceTab.Create(IDD_DEVICETAB_DIALOG, this))
	{
		TRACE0("未能创建输出选项卡窗口/n");
		return -1;      // 未能创建
	}
	m_dlgDeviceTab.ShowWindow(SW_SHOW);
	return 0;
}


void CDeviceTabPane::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);

	// TODO:  在此处添加消息处理程序代码
	if (m_dlgDeviceTab.GetSafeHwnd())
	{
		CRect rect;
		GetClientRect(rect);

		m_dlgDeviceTab.MoveWindow(rect);
	}
}


void CDeviceTabPane::OnDestroy()
{
	CDockablePane::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
	m_dlgDeviceTab.DestroyWindow();
}


void CDeviceTabPane::OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/)
{
	// TODO: 在此处添加消息处理程序代码
}

