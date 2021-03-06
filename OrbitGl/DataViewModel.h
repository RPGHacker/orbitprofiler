//-----------------------------------
// Copyright Pierric Gimmig 2013-2017
//-----------------------------------
#pragma once

#include <string>
#include <vector>
#include "DataViewTypes.h"

//-----------------------------------------------------------------------------
class DataViewModel
{
public:
    DataViewModel() : m_LastSortedColumn(-1)
                    , m_UpdatePeriodMs(-1)
                    , m_SelectedIndex(-1)
                    , m_Type( INVALID )
    {}

    ~DataViewModel();

    static DataViewModel* Create( DataViewType a_Type );

    virtual void SetAsMainInstance(){}
    virtual const std::vector<std::wstring>& GetColumnHeaders();
    virtual const std::vector<float>& GetColumnHeadersRatios();
    virtual const std::vector<std::wstring>& GetContextMenu(int a_Index);
    virtual int  GetNumElements() { return (int)m_Indices.size(); }
    virtual std::wstring GetValue(int /*a_Row*/, int /*a_Column*/) { return L""; }
    virtual std::wstring GetToolTip(int /*a_Row*/, int /*a_Column*/) { return L""; }
    virtual void SetFilter( const std::wstring & a_Filter ) { m_Filter = a_Filter; OnFilter( a_Filter ); }
    virtual void OnFilter( const std::wstring & /*a_Filter*/ ) {}
    virtual void OnSort( int /*a_Column*/, bool /*a_Toggle*/ = true ) {}
    virtual void OnContextMenu( int /*a_MenuIndex*/, std::vector<int> & /*a_ItemIndices*/ ) {}
    virtual void OnItemActivated() {}
    virtual void OnSelect(int /*a_Index*/) {}
    virtual int GetSelectedIndex(){ return m_SelectedIndex; }
    virtual void OnDataChanged() {}
    virtual void OnTimer() {}
    virtual bool WantsDisplayColor() { return false; }
    virtual bool GetDisplayColor(int /*a_Row*/, int /*a_Column*/, unsigned char& /*r*/, unsigned char& /*g*/, unsigned char& /*b*/){ return false; }
    virtual const std::wstring & GetName() { static std::wstring s(L"noname"); return s; }
    virtual std::wstring GetLabel(){ return L""; }
    virtual void SetGlPanel( class GlPanel* /*a_GlPanel*/ ){}
    virtual void LinkModel( DataViewModel* /*a_DataView*/ ){}
    virtual bool ScrollToBottom(){ return false; }
    virtual bool SkipTimer(){ return false; }
    
    int GetUpdatePeriodMs() const { return m_UpdatePeriodMs; }
    DataViewType GetType() const { return m_Type; }
    

protected:
    std::vector<int>  m_Indices;
    std::vector<bool> m_SortingToggles;
    int               m_LastSortedColumn;
    std::wstring      m_Filter;
    int               m_UpdatePeriodMs;
    int               m_SelectedIndex;
    DataViewType      m_Type;
};

