//
//Copyright(c) 2016. Huan Xia
//
//Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated 
//documentation files(the "Software"), to deal in the Software without restriction, including without limitation
//the rights to use, copy, modify, merge, publish, distribute, sublicense, and / or sell copies of the Software,
//and to permit persons to whom the Software is furnished to do so, subject to the following conditions :
//
//The above copyright notice and this permission notice shall be included in all copies or substantial portions
//of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
//TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL
//THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
//CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
//DEALINGS IN THE SOFTWARE.

#pragma once

#include "STXAnimationControl.h"

//////////////////////////////////////////////////////////////////////////

class CSTXSectionListTitleNode : public CSTXAnimationControlChildNode
{
public:
	std::wstring _caption;

public:
	static CSTXGraphicsBrush* _sbkBrush[1];

protected:
	virtual void DrawNode(CSTXGraphics *pGraphics);
	int GetTotalHeight();
	virtual BOOL IsDelayRemove();
};

class CSTXSectionListContentNode : public CSTXAnimationControlChildNode
{
public:
	CSTXSectionListContentNode();
	virtual ~CSTXSectionListContentNode();

public:
	std::wstring _caption;
	int _type;

protected:
	CSTXGraphicsBrush* _bkBrush;


protected:
	virtual void DrawNode(CSTXGraphics *pGraphics);
	virtual BOOL IsDelayRemove();

protected:
	virtual void OnLButtonDown(int x, int y, UINT nFlags, BOOL bForRButton = FALSE);
	virtual void OnLButtonUp(int x, int y, UINT nFlags, BOOL bForRButton = FALSE);
	virtual void OnMouseMove(int x, int y, UINT nFlags);
	virtual void OnMouseLeave();
	virtual void OnLButtonClick();
	virtual void OnRButtonClick();
	virtual void OnLButtonDblClk(int x, int y, UINT nFlags);
	virtual void OnMouseEnter();
	virtual void OnQueryToolTipsText(LPTSTR pszBuffer, int cchBufferSize, POINT ptLocation, LPCTSTR *ppszToolTips);
	virtual void OnBeginMouseDragging(POINT ptGlobal);
	virtual void OnEndMouseDragging(POINT ptGlobal, POINT ptOffset);

};

class CSTXSectionListTipNode : public CSTXAnimationControlChildNode
{
public:
	std::wstring _caption;
	int _location;	//0 to 3

protected:
	virtual void DrawNode(CSTXGraphics *pGraphics);
	virtual void OnQueryToolTipsText(LPTSTR pszBuffer, int cchBufferSize, POINT ptLocation, LPCTSTR *ppszToolTips);
};


//////////////////////////////////////////////////////////////////////////

class CSTXSectionList :	public CSTXAnimationControl
{
public:
	CSTXSectionList();
	virtual ~CSTXSectionList();

protected:
	void CalculateItemsPerLine();
	POINT CalculateItemLocation(int nSectionIndex, int nItemIndex);
	void ResetItemLocationsInSectionFromIndex(int nSectionIndex, int nItemIndexStart);
	int CalculateLineCount(int nSectionItemCount);
	int CalculateLineCount(int nSectionItemCount, int nItemsPerLine);
protected:
	int _itemsPerLine;

protected:
	virtual int OnQueryNodeFinalHeight();
	virtual LPCTSTR GetControlClassName();

protected:
	virtual void OnSize(UINT nType, int cx, int cy);
	virtual void OnMouseWheel(UINT nFlags, short zDelta, int x, int y);


public:
	int GetTotalHeightBefore(int nSectionIndex);
	int AddSection(LPCTSTR lpszTitle);
	void RemoveSection(int nSectionIndex);
	int AddItemToSection(int nSectionIndex, LPCTSTR lpszItemText);
	void AdjustSectionLocationsFromIndex(int nSectionIndex, int nOffsetChanged);
	void SetItemTipCount(int nSectionIndex, int nItemIndex, int nCount);
	void SetItemTipLeftBottom(int nSectionIndex, int nItemIndex, LPCTSTR lpszTipText);
	void SetItemTipLeftTop(int nSectionIndex, int nItemIndex, LPCTSTR lpszTipText);
	void RemoveItemFromSection(int nSectionIndex, int nItemIndex);
	int GetSectionCount();
};

