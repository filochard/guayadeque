/*
   Copyright (C) 2008-2023 J.Rios <anonbeat@gmail.com>
   Copyright (C) 2024-2025 Tiago T Barrionuevo <thothix@protonmail.com>

   This file is part of Guayadeque Music Player.

   Guayadeque is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   Guayadeque is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with Guayadeque. If not, see <https://www.gnu.org/licenses/>.
*/
#ifndef __PLAYLIST_H__
#define __PLAYLIST_H__

#include "AuiManagedPanel.h"
#include "DbLibrary.h"
#include "ListView.h"

#include <wx/wx.h>
#include <wx/vlbox.h>
#include <wx/dnd.h>
#include <wx/dir.h>
#include <wx/arrimpl.cpp>
#include <wx/thread.h>
#include <wx/timer.h>
#include <wx/string.h>

namespace Guayadeque {

class guPlayerPanel;
class guPlayList;
class guMainFrame;
class guPlayerPlayList;

// -------------------------------------------------------------------------------- //
class guPlayList : public guListView
{
  private :
    guDbLibrary *           m_Db;
    guMainFrame *           m_MainFrame;
    guPlayerPanel *         m_PlayerPanel;
    guPlayerPlayList *      m_PlayerPlayList;
    guTrackArray            m_Items;
    wxMutex                 m_ItemsMutex;
    bool                    m_StartPlaying;
    long                    m_CurItem;
    unsigned int            m_TotalLen;
    long                    m_MaxPlayedTracks;
    int                     m_MinPlayListTracks;
    bool                    m_DelTracksPLayed;
    int                     m_ItemHeight;
    wxString                m_LastSearch;

    wxBitmap *              m_PlayBitmap;
    wxBitmap *              m_StopBitmap;
    wxBitmap *              m_NormalStar;
    wxBitmap *              m_SelectStar;
    wxCoord                 m_SecondLineOffset;

    wxTimer *               m_SavePlaylistTimer;

    wxArrayString           m_PendingLoadIds;

    int                     m_SysFontPointSize;

    virtual wxCoord             OnMeasureItem( size_t row ) const;

    virtual int                 GetSelectedSongs( guTrackArray * Songs, const bool isdrag = false ) const;
    virtual void                OnDropFile( const wxString &filename );
    virtual void                OnDropTracks( const guTrackArray * tracks );
    virtual void                OnDropBegin( void );
    virtual void                OnDropEnd( void );

    virtual wxString            GetItemSearchText( const int row );

    void                        RemoveSelected();
    virtual void                MoveSelection( void );
    virtual void                MoveSelection(guLISTVIEW_NAVIGATION target);

    void                        OnClearClicked( wxCommandEvent &event );
    void                        OnRemoveClicked( wxCommandEvent &event );
    void                        OnSaveClicked( wxCommandEvent &event );
    void                        OnCreateBestOfClicked( wxCommandEvent &event );
    void                        OnCopyToClicked( wxCommandEvent &event );
    void                        OnEditLabelsClicked( wxCommandEvent &event );
    void                        OnEditTracksClicked( wxCommandEvent &event );
    void                        OnSearchClicked( wxCommandEvent &event );
    void                        OnStopAtEnd( wxCommandEvent &event ) { StopAtEnd(); }

    void                        SetTopPlayTracks( wxCommandEvent &event );
    void                        SetTopTracks( wxCommandEvent &event );
    void                        SetPrevTracks( wxCommandEvent &event );
    void                        SetNextTracks( wxCommandEvent &event );
    void                        SetBottomTracks( wxCommandEvent &event );

    void                        OnSearchLinkClicked( wxCommandEvent &event );
    void                        OnCommandClicked( wxCommandEvent &event );
    wxString                    GetSearchText( int item ) const;

    void                        OnSelectTrack( wxCommandEvent &event );
    void                        OnSelectArtist( wxCommandEvent &event );
    void                        OnSelectAlbum( wxCommandEvent &event );
    void                        OnSelectAlbumArtist( wxCommandEvent &event );
    void                        OnSelectComposer( wxCommandEvent &event );
    void                        OnSelectYear( wxCommandEvent &event );
    void                        OnSelectGenre( wxCommandEvent &event );

    void                        CreateAcceleratorTable( void );

    void                        SavePlaylistTracks( void );
    void                        LoadPlaylistTracks( void );

  protected:
    virtual void                OnKeyDown( wxKeyEvent &event );
    virtual void                DrawItem( wxDC &dc, const wxRect &rect, const int row, const int col ) const;
    virtual void                DrawBackground( wxDC &dc, const wxRect &rect, const int row, const int col ) const;
    virtual void                CreateContextMenu( wxMenu * Menu ) const;
    virtual wxString            OnGetItemText( const int row, const int column ) const;
    virtual void                GetItemsList( void );
    virtual void                OnMouse( wxMouseEvent &event );

    void                        OnColumnSelected( wxCommandEvent &event );
    void                        OnConfigUpdated( wxCommandEvent &event );

    void                        OnDeleteFromLibrary( wxCommandEvent &event );
    void                        OnDeleteFromDrive( wxCommandEvent &event );

    void                        OnSetRating( wxCommandEvent &event );

    void                        SetTrackRating( const guTrack &track, const int rating );
    void                        SetTracksRating( const guTrackArray &tracks, const int rating );

    void                        CheckPendingLoadItems( const wxString &uniqueid, guMediaViewer * mediaviewer );

    void                        OnCreateSmartPlaylist( wxCommandEvent &event );

    void                        StartSavePlaylistTimer( wxCommandEvent &event );
    void                        OnSavePlaylistTimer( wxTimerEvent & );

  public :
    guPlayList( wxWindow * parent, guDbLibrary * db, guPlayerPanel * playerpanel = nullptr, guMainFrame * mainframe = nullptr );
    ~guPlayList();

    void                        SetPlayerPanel( guPlayerPanel * playerpanel ) { m_PlayerPanel = playerpanel; }
    void                        SetPlayerPlayList( guPlayerPlayList * playerplaylist ) { m_PlayerPlayList = playerplaylist; }

    void                        AddItem( const guTrack &NewItem, const int pos = wxNOT_FOUND );
    //void                        AddItem( const guTrack * NewItem );
    void                        AddPlayListItem( const wxString &FileName, const int aftercurrent, const int pos );

    virtual void                ReloadItems( bool reset = true );

    virtual wxString            GetItemName( const int row ) const { return m_Items[ row ].m_SongName; }
    virtual int                 GetItemId( const int row ) const { return row; }

    guTrack *                   GetItem( size_t item );
    long                        GetCount() { return m_Items.GetCount(); }
    guTrack *                   GetCurrent();
    int                         GetCurItem();
    void                        SetCurrent( int curitem, bool delold = false );
    guTrack *                   GetNext( const int playloop, const bool forceskip = false );
    guTrack *                   GetPrev( const int playloop, const bool forceskip = false );
    guTrack *                   GetNextAlbum( const int playloop, const bool forceskip = false );
    guTrack *                   GetPrevAlbum( const int playloop, const bool forceskip = false );
    void                        ClearItems();
    long                        GetLength( void ) const;
    wxString                    GetLengthStr( void ) const;
    void                        AddToPlayList( const guTrackArray &newitems, const bool deleteold = false, const int aftercurrent = 0 ); //guINSERT_AFTER_CURRENT_NONE
    void                        SetPlayList( const guTrackArray &NewItems );
    wxString                    FindCoverFile( const wxString &DirName );
    void                        Randomize( const bool isplaying );
    int                         GetCaps();
    void                        RemoveItem( int itemnum, bool lock = true );

    void                        UpdatedTracks( const guTrackArray * tracks );
    void                        UpdatedTrack( const guTrack * track );

    bool                        StartPlaying( void ) { return m_StartPlaying; }

    void                        StopAtEnd( void );
    void                        ClearStopAtEnd( void );

    void                        MediaViewerCreated( const wxString &uniqueid, guMediaViewer * mediaviewer );
    void                        MediaViewerClosed( guMediaViewer * mediaviewer );

    void                        UpdatePlaylistToolbar( void );

  friend class guAddDropFilesThread;
  friend class guPlayListDropTarget;
  friend class guPlayerPlayList;

};

// -------------------------------------------------------------------------------- //
class guPlayerPlayList : public guAuiManagedPanel
{
  protected :
    guPlayList * m_PlayListCtrl;

    wxBoxSizer *MainSizer;
    wxBoxSizer *BigSizer;

    wxBitmapButton *m_TopPlayButton;
    wxBitmapButton *m_TopButton;
    wxBitmapButton *m_PrevButton;
    wxBitmapButton *m_NextButton;
    wxBitmapButton *m_BottomButton;
    wxBitmapButton *m_ShuffleButton;
    wxBitmapButton *m_RemoveButton;
    wxBitmapButton *m_ClearPlaylistButton;

    void OnTopPlayBtnClick(wxCommandEvent &event);
    void OnTopBtnClick(wxCommandEvent &event);
    void OnPrevBtnClick(wxCommandEvent &event);
    void OnNextBtnClick(wxCommandEvent &event);
    void OnBottomBtnClick(wxCommandEvent &event);
    void OnShuffleBtnClick(wxCommandEvent &event);
    void OnRemoveBtnClick(wxCommandEvent &event);
    void OnClearPlaylistBtnClick(wxCommandEvent &event);

public :
    guPlayerPlayList( wxWindow * parent, guDbLibrary * db, wxAuiManager * manager );
    ~guPlayerPlayList();

    guPlayList *    GetPlayListCtrl( void ) { return m_PlayListCtrl; }
    void            SetPlayerPanel( guPlayerPanel * player );

    void inline     UpdatedTracks( const guTrackArray * tracks ) { m_PlayListCtrl->UpdatedTracks( tracks ); }
    void inline     UpdatedTrack( const guTrack * track ) { m_PlayListCtrl->UpdatedTrack( track ); }

    void inline     MediaViewerCreated( const wxString &uniqueid, guMediaViewer * mediaviewer ) { m_PlayListCtrl->MediaViewerCreated( uniqueid, mediaviewer ); }
    void inline     MediaViewerClosed( guMediaViewer * mediaviewer ) { m_PlayListCtrl->MediaViewerClosed( mediaviewer ); }

    void            LoadPlaylistTracks( void ) { m_PlayListCtrl->LoadPlaylistTracks(); }

    void            UpdatePlayListToolbarState(int item, int curItem, int lastItem);
};

}
#endif
// -------------------------------------------------------------------------------- //
