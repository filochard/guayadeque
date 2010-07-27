// -------------------------------------------------------------------------------- //
//	Copyright (C) 2008-2010 J.Rios
//	anonbeat@gmail.com
//
//    This Program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 2, or (at your option)
//    any later version.
//
//    This Program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program; see the file LICENSE.  If not, write to
//    the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
//    http://www.gnu.org/copyleft/gpl.html
//
// -------------------------------------------------------------------------------- //
#ifndef FILEBROWSER_H
#define FILEBROWSER_H

#include "DbLibrary.h"
#include "PlayerPanel.h"

#include <wx/colour.h>
#include <wx/dirctrl.h>
#include <wx/dynarray.h>
#include <wx/font.h>
#include <wx/gdicmn.h>
#include <wx/panel.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/string.h>
#include <wx/tglbtn.h>


#define     guPANEL_FILEBROWSER_DIRCTRL             ( 1 << 0 )
#define     guPANEL_FILEBROWSER_FILECTRL            ( 1 << 1 )
#define     guPANEL_FILEBROWSER_FILEDETAILS         ( 1 << 2 )

#define     guPANEL_FILEBROWSER_VISIBLE_DEFAULT     ( guPANEL_FILEBROWSER_DIRCTRL | guPANEL_FILEBROWSER_FILECTRL |\
                                                      guPANEL_FILEBROWSER_FILEDETAILS )
enum guFILEITEM_TYPE {
    guFILEITEM_TYPE_FOLDER = 0,
    guFILEITEM_TYPE_AUDIO,
    guFILEITEM_TYPE_IMAGE,
    guFILEITEM_TYPE_FILE
};

#define     guFILEBROWSER_SHOWPATH_SYSTEM           ( 1 << 0 )
#define     guFILEBROWSER_SHOWPATH_LIBRARY          ( 1 << 1 )
#define     guFILEBROWSER_SHOWPATH_RECORDS          ( 1 << 2 )
#define     guFILEBROWSER_SHOWPATH_PODCASTS         ( 1 << 3 )

#define guDIR_IMAGE_INDEX_FOLDER        0
#define guDIR_IMAGE_INDEX_OTHER         7
#define guDIR_IMAGE_INDEX_LIBRARY       9
#define guDIR_IMAGE_INDEX_PODCASTS      10
#define guDIR_IMAGE_INDEX_RECORDS       11
#define guDIR_IMAGE_INDEX_AUDIO         12
#define guDIR_IMAGE_INDEX_IMAGE         13


#define guFILEBROWSER_COLUMN_NAME       0
#define guFILEBROWSER_COLUMN_SIZE       1
#define guFILEBROWSER_COLUMN_TIME       2

// -------------------------------------------------------------------------------- //
class guFileItem
{
  public :
    int             m_Type;
    wxString        m_Name;
    wxFileOffset    m_Size;
    int             m_Time;
};
WX_DECLARE_OBJARRAY(guFileItem, guFileItemArray);

class guFileBrowserDirCtrl;

// -------------------------------------------------------------------------------- //
class guGenericDirCtrl : public wxGenericDirCtrl
{
  protected :
    guFileBrowserDirCtrl *  m_FileBrowserDirCtrl;
    wxString                m_RenameName;
    int                     m_ShowPaths;

    void            OnBeginRenameDir( wxTreeEvent &event );
    void            OnEndRenameDir( wxTreeEvent &event );

  public :
    guGenericDirCtrl() : wxGenericDirCtrl() { m_FileBrowserDirCtrl = NULL; };
    guGenericDirCtrl( wxWindow * parent, const int showpaths  );
    ~guGenericDirCtrl();

    void            OnConfigUpdated( wxCommandEvent &event );

    virtual void    SetupSections();

    void            FolderRename( void );

    void            SetShowLibPaths( int showlibpaths ) { m_ShowPaths = showlibpaths; }

    DECLARE_EVENT_TABLE()
};

// -------------------------------------------------------------------------------- //
class guFileBrowserDirCtrl : public wxPanel
{
  protected :
    guDbLibrary *       m_Db;
    guGenericDirCtrl *  m_DirCtrl;
    bool                m_AddingFolder;
    wxToggleBitmapButton *  m_ShowRecPathsBtn;
    wxToggleBitmapButton *  m_ShowPodPathsBtn;
    wxToggleBitmapButton *  m_ShowLibPathsBtn;

    void                OnShowLibPathsClick( wxCommandEvent& event );

    wxImageList *       GetImageList( void ) { return m_DirCtrl->GetTreeCtrl()->GetImageList(); }

    void                OnContextMenu( wxTreeEvent &event );

  public :
    guFileBrowserDirCtrl( wxWindow * parent, guDbLibrary * db, const wxString &dirpath );
    ~guFileBrowserDirCtrl();

    wxString            GetPath( void )
    {
        wxString DirPath = m_DirCtrl->GetPath();
        if( !DirPath.EndsWith( wxT( "/" ) ) )
            DirPath.Append( wxT( "/" ) );
        return DirPath;
    }

    void                SetPath( const wxString &path ) { m_DirCtrl->SetPath( path ); }

    void                RenamedDir( const wxString &oldname, const wxString &newname );
    void                FolderRename( void ) { m_DirCtrl->FolderRename(); };
    void                FolderNew( void );
    void                FolderDelete( void );
    bool                ExpandPath( const wxString &path ) { return m_DirCtrl->ExpandPath( path ); }
    bool                CollapsePath( const wxString &path ) { return m_DirCtrl->CollapsePath( path ); }

  friend class guFileBrowserFileCtrl;
  friend class guFileBrowser;
};

// -------------------------------------------------------------------------------- //
class guFilesListBox : public guListView
{
  protected :
    guDbLibrary *       m_Db;
    wxString            m_CurDir;
    guFileItemArray     m_Files;
    wxImageList *       m_TreeImageList;
    int                 m_Order;
    bool                m_OrderDesc;

    virtual void                CreateContextMenu( wxMenu * Menu ) const;
    virtual wxString            OnGetItemText( const int row, const int column ) const;
    virtual void                DrawItem( wxDC &dc, const wxRect &rect, const int row, const int col ) const;
    virtual void                GetItemsList( void );
    virtual int                 GetSelectedSongs( guTrackArray * tracks ) const;
    int                         GetAllSongs( guTrackArray * tracks ) const;
    int                         GetTracksFromFiles( const wxArrayString &files, guTrackArray * tracks ) const;

    virtual int                 GetDragFiles( wxFileDataObject * files );

    wxArrayString               GetColumnNames( void );

    int                         GetPathSordedItems( const wxString &path, guFileItemArray * items,
                                                    const int order, const bool orderdesc,
                                                    const bool recursive = false ) const;

  public :
    guFilesListBox( wxWindow * parent, guDbLibrary * db );
    ~guFilesListBox();

    virtual void                ReloadItems( bool reset = true );

    virtual wxString inline     GetItemName( const int item ) const;
    virtual int inline          GetItemId( const int item ) const;

    void                        SetOrder( int order );
    void                        SetPath( const wxString &path );
    wxString                    GetPath( const int item, const bool absolute = true ) const;
    int                         GetType( const int item ) const;
    void                        SetTreeImageList( wxImageList * imagelist ) { m_TreeImageList = imagelist; }

    bool                        GetCounters( wxLongLong * count, wxLongLong * len, wxLongLong * size );

    wxArrayString               GetSelectedFiles( const bool recursive = false ) const;
    wxArrayString               GetAllFiles( const bool recursive = false ) const;

  friend class guFileBrowserFileCtrl;
};

// -------------------------------------------------------------------------------- //
class guFileBrowserFileCtrl : public wxPanel
{
  protected :
    guDbLibrary *           m_Db;
    guFilesListBox *        m_FilesListBox;
    guFileBrowserDirCtrl *  m_DirCtrl;

  public :
    guFileBrowserFileCtrl( wxWindow * parent, guDbLibrary * db, guFileBrowserDirCtrl * dirctrl );
    ~guFileBrowserFileCtrl();

    void                    SetPath( const wxString &path ) { m_FilesListBox->SetPath( path ); }
    const wxString          GetPath( const int item, const bool absolute = true ) const { return m_FilesListBox->GetPath( item, absolute ); }
    int                     GetType( const int item ) const { return m_FilesListBox->GetType( item ); }
    wxArrayInt              GetSelectedItems( const bool convertall = true ) { return m_FilesListBox->GetSelectedItems( convertall ); }
    wxArrayString           GetSelectedFiles( const bool recursive = false ) { return m_FilesListBox->GetSelectedFiles( recursive ); }
    wxArrayString           GetAllFiles( const bool recursive = false ) { return m_FilesListBox->GetAllFiles( recursive ); }
    int                     GetSelectedSongs( guTrackArray * tracks ) { return m_FilesListBox->GetSelectedSongs( tracks ); }
    int                     GetAllSongs( guTrackArray * tracks ) { return m_FilesListBox->GetAllSongs( tracks ); }
    void                    SetOrder( const int order ) { m_FilesListBox->SetOrder( order ); }

    bool                    GetCounters( wxLongLong * count, wxLongLong * len, wxLongLong * size )
    {
        return m_FilesListBox->GetCounters( count, len, size );
    }

};

// -------------------------------------------------------------------------------- //
class guFileBrowser : public wxPanel
{
  protected :
    wxAuiManager            m_AuiManager;
    int                     m_VisiblePanels;
	guDbLibrary *           m_Db;
	guPlayerPanel *         m_PlayerPanel;

	guFileBrowserDirCtrl *  m_DirCtrl;
	guFileBrowserFileCtrl * m_FilesCtrl;

    void                    OnDirItemChanged( wxTreeEvent &event );
    void                    OnFileItemActivated( wxListEvent &Event );
    void                    OnFilesColClick( wxListEvent &event );
    void                    OnDirBeginDrag( wxTreeEvent &event );

    void                    OnFolderPlay( wxCommandEvent &event );
    void                    OnFolderEnqueue( wxCommandEvent &event );
    void                    OnFolderEnqueueAsNext( wxCommandEvent &event );
    void                    OnFolderNew( wxCommandEvent &event );
    void                    OnFolderRename( wxCommandEvent &event );
    void                    OnFolderDelete( wxCommandEvent &event );
    void                    OnFolderCopy( wxCommandEvent &event );
    void                    OnFolderPaste( wxCommandEvent &event );
    void                    OnFolderEditTracks( wxCommandEvent &event );
    void                    OnFolderSaveToPlayList( wxCommandEvent &event );
    void                    OnFolderCopyTo( wxCommandEvent &event );
    void                    OnFolderCommand( wxCommandEvent &event );

    void                    OnItemsPlay( wxCommandEvent &event );
    void                    OnItemsEnqueue( wxCommandEvent &event );
    void                    OnItemsEnqueueAsNext( wxCommandEvent &event );
    void                    OnItemsEditTracks( wxCommandEvent &event );
    void                    OnItemsSaveToPlayList( wxCommandEvent &event );
    void                    OnItemsCopyTo( wxCommandEvent &event );
    void                    OnItemsRename( wxCommandEvent &event );
    void                    OnItemsDelete( wxCommandEvent &event );
    void                    OnItemsCommand( wxCommandEvent &event );
    void                    OnItemsCopy( wxCommandEvent &event );
    void                    OnItemsPaste( wxCommandEvent &event );

    DECLARE_EVENT_TABLE()

  public :
    guFileBrowser( wxWindow * parent, guDbLibrary * db, guPlayerPanel * playerpanel );
    ~guFileBrowser();

    bool                    GetCounters( wxLongLong * count, wxLongLong * len, wxLongLong * size )
    {
        return m_FilesCtrl->GetCounters( count, len, size );
    }


};

#endif
// -------------------------------------------------------------------------------- //
