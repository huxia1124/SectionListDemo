#include "stdafx.h"
#include "MainWindow.h"
#include "STXGraphics.h"

CMainWindow::CMainWindow()
{
	_anchor = NULL;
}

CMainWindow::~CMainWindow()
{
}

void CMainWindow::InitializeSectionList()
{
	int a0 = 0;
	int a1 = 0;
	int a2 = 0;
	int a3 = 0;

	LANGID lang = GetUserDefaultUILanguage();
	if (lang != 0x804)		//not Chinese
	{
		a0 = _list.AddSection(_T("2014-1-25   Today          Click items to remove"));
		_list.AddItemToSection(a0, _T("Apple"));
		_list.AddItemToSection(a0, _T("Banana"));
		_list.AddItemToSection(a0, _T("Bolwarra"));
		a1 = _list.AddSection(_T("2014-1-26   Tomorrow"));
		_list.AddItemToSection(a1, _T("Mangos"));
		_list.AddItemToSection(a1, _T("Salak"));
		_list.AddItemToSection(a1, _T("Genip"));
		_list.AddItemToSection(a1, _T("Papayas"));
		_list.AddItemToSection(a1, _T("Lapsi"));
		_list.AddItemToSection(a1, _T("Lemon"));
		_list.AddItemToSection(a1, _T("Lime"));
		_list.AddItemToSection(a1, _T("Yellow Mombin"));
		_list.AddItemToSection(a1, _T("[Sample]"));
		_list.AddItemToSection(a1, _T("[Sample]"));
		_list.AddItemToSection(a1, _T("[Sample]"));
		_list.AddItemToSection(a1, _T("[Sample]"));
		_list.AddItemToSection(a1, _T("[Sample]"));
		_list.AddItemToSection(a1, _T("[Sample]"));
		a2 = _list.AddSection(_T("2014-1-27"));
		_list.AddItemToSection(a2, _T("Youngberry"));
		a3 = _list.AddSection(_T("2014-1-28"));
		_list.AddItemToSection(a3, _T("Watermelon"));

		_list.SetItemTipLeftTop(a1, 8, _T("S"));
		_list.SetItemTipLeftTop(a1, 9, _T("S"));
		_list.SetItemTipLeftTop(a1, 10, _T("S"));
		_list.SetItemTipLeftTop(a1, 11, _T("S"));
		_list.SetItemTipLeftTop(a1, 12, _T("S"));
		_list.SetItemTipLeftTop(a1, 13, _T("S"));
	}
	else
	{
		a0 = _list.AddSection(_T("2014年1月25日   今天    点击以下各项可删除"));
		_list.AddItemToSection(a0, _T("Apple"));
		_list.AddItemToSection(a0, _T("芭蕉"));
		_list.AddItemToSection(a0, _T("菠萝蜜"));

		a1 = _list.AddSection(_T("2014年1月26日   明天"));
		_list.AddItemToSection(a1, _T("芒果"));
		_list.AddItemToSection(a1, _T("山竹"));
		_list.AddItemToSection(a1, _T("柑桔"));
		_list.AddItemToSection(a1, _T("葡萄"));
		_list.AddItemToSection(a1, _T("莲雾"));
		_list.AddItemToSection(a1, _T("荔枝"));
		_list.AddItemToSection(a1, _T("榴莲"));
		_list.AddItemToSection(a1, _T("椰子"));
		_list.AddItemToSection(a1, _T("梨"));
		_list.AddItemToSection(a1, _T("火龙果"));
		_list.AddItemToSection(a1, _T("樱桃"));
		_list.AddItemToSection(a1, _T("草莓"));
		_list.AddItemToSection(a1, _T("石榴"));
		_list.AddItemToSection(a1, _T("奇异果"));

		a2 = _list.AddSection(_T("2014年1月27日"));
		_list.AddItemToSection(a2, _T("杨桃"));
		a3 = _list.AddSection(_T("2014年1月28日"));
		_list.AddItemToSection(a3, _T("Watermelon"));


		_list.SetItemTipLeftTop(a1, 8, _T("L"));
		_list.SetItemTipLeftTop(a1, 9, _T("H"));
		_list.SetItemTipLeftTop(a1, 10, _T("Y"));
		_list.SetItemTipLeftTop(a1, 11, _T("C"));
		_list.SetItemTipLeftTop(a1, 12, _T("S"));
		_list.SetItemTipLeftTop(a1, 13, _T("Q"));
	}

	_list.SetItemTipCount(a0, 0, 6);
	_list.SetItemTipCount(a0, 1, 12);
	_list.SetItemTipCount(a0, 2, 0);
	_list.SetItemTipCount(a1, 0, 3);
	_list.SetItemTipCount(a1, 1, 2);
	_list.SetItemTipCount(a1, 2, 0);
	_list.SetItemTipCount(a1, 3, 20);
	_list.SetItemTipCount(a1, 4, 0);
	_list.SetItemTipCount(a1, 5, 5);
	_list.SetItemTipCount(a1, 6, 16);
	_list.SetItemTipCount(a1, 7, 32);
	_list.SetItemTipCount(a2, 0, 9);
	_list.SetItemTipCount(a3, 0, 0);

	_list.SetItemTipLeftBottom(a0, 0, _T("$5.00"));
	_list.SetItemTipLeftBottom(a0, 1, _T("$70.00"));
	_list.SetItemTipLeftBottom(a0, 2, _T("$32.00"));
	_list.SetItemTipLeftBottom(a1, 0, _T("$7.09"));
	_list.SetItemTipLeftBottom(a1, 1, _T("$66.00"));
	_list.SetItemTipLeftBottom(a1, 7, _T("$1999.00"));
	_list.SetItemTipLeftBottom(a2, 0, _T("Free"));

	_list.SetItemTipLeftTop(a0, 0, _T("A"));
	_list.SetItemTipLeftTop(a0, 1, _T("B"));
	_list.SetItemTipLeftTop(a0, 2, _T("B"));
	_list.SetItemTipLeftTop(a1, 0, _T("M"));
	_list.SetItemTipLeftTop(a1, 1, _T("S"));
	_list.SetItemTipLeftTop(a1, 2, _T("G"));
	_list.SetItemTipLeftTop(a1, 3, _T("P"));
	_list.SetItemTipLeftTop(a1, 4, _T("L"));
	_list.SetItemTipLeftTop(a1, 5, _T("L"));
	_list.SetItemTipLeftTop(a1, 6, _T("L"));
	_list.SetItemTipLeftTop(a1, 7, _T("Y"));

	_list.SetItemTipLeftTop(a2, 0, _T("Y"));
	_list.SetItemTipLeftTop(a3, 0, _T("W"));
}

LRESULT CMainWindow::OnCreate(UINT msg, WPARAM wParam, LPARAM lParam, BOOL &bHandled)
{
	ModifyStyle(0, WS_CLIPCHILDREN);
	RECT rcWnd;
	GetClientRect(&rcWnd);

	_anchor = new CSTXAnchor(m_hWnd);

	_list.Create(_T("SectionList"), WS_CHILD|WS_VISIBLE, 0, 0, rcWnd.right - rcWnd.left, rcWnd.bottom - rcWnd.top, m_hWnd, 1001);

	_anchor->AddItem(1001, STXANCHOR_ALL);

	InitializeSectionList();

	_totalRandomItems = 0;
	SetTimer(1, 1000, NULL);
	return 0;
}

LRESULT CMainWindow::OnTimer(UINT msg, WPARAM wParam, LPARAM lParam, BOOL &bHandled)
{
	if (_totalRandomItems > 20) {
		KillTimer(1);
		_totalRandomItems = 0;
	}
	int nSection = rand() % _list.GetSectionCount();
	int nItem = _list.AddItemToSection(nSection, _T("New Item"));

	_list.SetItemTipCount(nSection, nItem, rand() % 2);
	_list.SetItemTipLeftBottom(nSection, nItem, _T("$9.99"));

	_list.SetItemTipLeftTop(nSection, nItem, _T("N"));
	_totalRandomItems++;
	return 0;
}

