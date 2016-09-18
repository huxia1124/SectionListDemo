#pragma once

#include <atlwin.h>

#include "STXAnchor.h"
#include "STXSectionListNS.h"

class CMainWindow : public CWindowImpl<CMainWindow, CWindow, CFrameWinTraits>
{
public:
	CMainWindow();
	~CMainWindow();

protected:
	BEGIN_MSG_MAP(CMainWindow)
		MESSAGE_HANDLER(WM_CLOSE, OnClose)
		MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
		MESSAGE_HANDLER(WM_CREATE, OnCreate)
		MESSAGE_HANDLER(WM_TIMER, OnTimer)
	END_MSG_MAP()


protected:
	CSTXAnchor *_anchor;
	CString _currentMode;	//GDI+ or Direct2D
	CSTXSectionList _list;
	int _totalRandomItems;

private:
	void InitializeSectionList();

protected:
	LRESULT OnClose(UINT msg, WPARAM wParam, LPARAM lParam, BOOL &bHandled)
	{
		DestroyWindow();
		return 0;
	}
	LRESULT OnDestroy(UINT msg, WPARAM wParam, LPARAM lParam, BOOL &bHandled)
	{
		if (_anchor)
		{
			delete _anchor;
			_anchor = NULL;
		}

		PostQuitMessage(0);
		return 0;
	}
	LRESULT OnCreate(UINT msg, WPARAM wParam, LPARAM lParam, BOOL &bHandled);
	LRESULT OnTimer(UINT msg, WPARAM wParam, LPARAM lParam, BOOL &bHandled);

private:

public:


};

