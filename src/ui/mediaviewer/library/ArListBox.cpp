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
#include "ArListBox.h"

#include "Accelerators.h"
#include "EventCommandIds.h"
#include "Config.h"
#include "Images.h"
#include "LibPanel.h"
#include "MainApp.h"
#include "MainFrame.h"
#include "MediaViewer.h"
#include "OnlineLinks.h"
#include "Settings.h"
#include "Utils.h"

namespace Guayadeque {

// -------------------------------------------------------------------------------- //
guArListBox::guArListBox( wxWindow * parent, guLibPanel * libpanel, guDbLibrary * db, const wxString &label ) :
             guAccelListBox( parent, db, label )
{
    m_LibPanel = libpanel;

    Bind( wxEVT_MENU, &guArListBox::OnSearchLinkClicked, this, ID_LINKS_BASE, ID_LINKS_BASE + guLINKS_MAXCOUNT );
    Bind( wxEVT_MENU, &guArListBox::OnCommandClicked, this, ID_COMMANDS_BASE, ID_COMMANDS_BASE + guCOMMANDS_MAXCOUNT );

    CreateAcceleratorTable();

    ReloadItems();
};

// -------------------------------------------------------------------------------- //
guArListBox::~guArListBox()
{
    Unbind( wxEVT_MENU, &guArListBox::OnSearchLinkClicked, this, ID_LINKS_BASE, ID_LINKS_BASE + guLINKS_MAXCOUNT );
    Unbind( wxEVT_MENU, &guArListBox::OnCommandClicked, this, ID_COMMANDS_BASE, ID_COMMANDS_BASE + guCOMMANDS_MAXCOUNT );
}

// -------------------------------------------------------------------------------- //
void guArListBox::CreateAcceleratorTable( void )
{
    wxAcceleratorTable AccelTable;
    wxArrayInt AliasAccelCmds;
    wxArrayInt RealAccelCmds;

    AliasAccelCmds.Add( ID_PLAYER_PLAYLIST_SAVE );
    AliasAccelCmds.Add( ID_PLAYER_PLAYLIST_EDITLABELS );
    AliasAccelCmds.Add( ID_PLAYER_PLAYLIST_EDITTRACKS );
    AliasAccelCmds.Add( ID_TRACKS_PLAY );
    AliasAccelCmds.Add( ID_TRACKS_ENQUEUE_AFTER_ALL );
    AliasAccelCmds.Add( ID_TRACKS_ENQUEUE_AFTER_TRACK );
    AliasAccelCmds.Add( ID_TRACKS_ENQUEUE_AFTER_ALBUM );
    AliasAccelCmds.Add( ID_TRACKS_ENQUEUE_AFTER_ARTIST );
    AliasAccelCmds.Add( ID_PLAYER_PLAYLIST_SEARCH );

    RealAccelCmds.Add( ID_ARTIST_SAVETOPLAYLIST );
    RealAccelCmds.Add( ID_ARTIST_EDITLABELS );
    RealAccelCmds.Add( ID_ARTIST_EDITTRACKS );
    RealAccelCmds.Add( ID_ARTIST_PLAY );
    RealAccelCmds.Add( ID_ARTIST_ENQUEUE_AFTER_ALL );
    RealAccelCmds.Add( ID_ARTIST_ENQUEUE_AFTER_TRACK );
    RealAccelCmds.Add( ID_ARTIST_ENQUEUE_AFTER_ALBUM );
    RealAccelCmds.Add( ID_ARTIST_ENQUEUE_AFTER_ARTIST );
    RealAccelCmds.Add( ID_LIBRARY_SEARCH );

    if( guAccelDoAcceleratorTable( AliasAccelCmds, RealAccelCmds, AccelTable ) )
    {
        SetAcceleratorTable( AccelTable );
    }
}

// -------------------------------------------------------------------------------- //
void guArListBox::GetItemsList( void )
{
    m_Db->GetArtists( m_Items );
}

// -------------------------------------------------------------------------------- //
int guArListBox::GetSelectedSongs( guTrackArray * songs, const bool isdrag ) const
{
    int Count = m_Db->GetArtistsSongs( GetSelectedItems(), songs );
    m_LibPanel->NormalizeTracks( songs, isdrag );
    return Count;
}

// -------------------------------------------------------------------------------- //
void AddArtistCommands( wxMenu * Menu, int SelCount )
{
    wxMenu * SubMenu;
    wxMenuItem * MenuItem;
    if( Menu )
    {
        SubMenu = new wxMenu();

        guConfig * Config = (guConfig *) guConfig::Get();

        wxString current_desktop = Config->ReadStr(CONFIG_KEY_GENERAL_DESKTOP, wxEmptyString, CONFIG_PATH_GENERAL);
        wxString category_execs = wxString::Format(CONFIG_PATH_COMMANDS_DESKTOP_EXECS, current_desktop);
        wxArrayString Commands = Config->ReadAStr(CONFIG_KEY_COMMANDS_EXEC, wxEmptyString, category_execs);
        wxString category_names = wxString::Format(CONFIG_PATH_COMMANDS_DESKTOP_NAMES, current_desktop);
        wxArrayString Names = Config->ReadAStr(CONFIG_KEY_COMMANDS_NAME, wxEmptyString, category_names);
        int count = Commands.Count();
        if( count )
        {
            for( int index = 0; index < count; index++ )
            {
                if( ( Commands[ index ].Find( guCOMMAND_COVERPATH ) == wxNOT_FOUND ) || ( SelCount == 1 ) )
                {
                    MenuItem = new wxMenuItem( Menu, ID_COMMANDS_BASE + index, _( Names[ index ] ), _( Commands[ index ] ) );
                    SubMenu->Append( MenuItem );
                }
            }

            SubMenu->AppendSeparator();
        }
        else
        {
            MenuItem = new wxMenuItem( Menu, ID_MENU_PREFERENCES_COMMANDS, _( "Preferences" ), _( "Add commands in preferences" ) );
            SubMenu->Append( MenuItem );
        }
        Menu->AppendSubMenu( SubMenu, _( "Commands" ) );
    }
}

// -------------------------------------------------------------------------------- //
void guArListBox::CreateContextMenu( wxMenu * Menu ) const
{
    wxMenuItem * MenuItem;

    int SelCount = GetSelectedCount();
    int ContextMenuFlags = m_LibPanel->GetContextMenuFlags();

    MenuItem = new wxMenuItem( Menu, ID_ARTIST_PLAY,
                            wxString( _( "Play" ) ) + guAccelGetCommandKeyCodeString( ID_TRACKS_PLAY ),
                            _( "Play current selected artists" ) );
    MenuItem->SetBitmap( guImage( guIMAGE_INDEX_player_tiny_light_play ) );
    Menu->Append( MenuItem );
    MenuItem->Enable( SelCount );

    MenuItem = new wxMenuItem( Menu, ID_ARTIST_ENQUEUE_AFTER_ALL,
                            wxString( _( "Enqueue" ) ) + guAccelGetCommandKeyCodeString( ID_TRACKS_ENQUEUE_AFTER_ALL ),
                            _( "Add current selected artists to playlist" ) );
    MenuItem->SetBitmap( guImage( guIMAGE_INDEX_tiny_add ) );
    Menu->Append( MenuItem );
    MenuItem->Enable( SelCount );

    wxMenu * EnqueueMenu = new wxMenu();

    MenuItem = new wxMenuItem( EnqueueMenu, ID_ARTIST_ENQUEUE_AFTER_TRACK,
                            wxString( _( "Current Track" ) ) +  guAccelGetCommandKeyCodeString( ID_TRACKS_ENQUEUE_AFTER_TRACK ),
                            _( "Add current selected tracks to playlist after the current track" ) );
    MenuItem->SetBitmap( guImage( guIMAGE_INDEX_tiny_add ) );
    EnqueueMenu->Append( MenuItem );
    MenuItem->Enable( SelCount );

    MenuItem = new wxMenuItem( EnqueueMenu, ID_ARTIST_ENQUEUE_AFTER_ALBUM,
                            wxString( _( "Current Album" ) ) +  guAccelGetCommandKeyCodeString( ID_TRACKS_ENQUEUE_AFTER_ALBUM ),
                            _( "Add current selected tracks to playlist after the current album" ) );
    MenuItem->SetBitmap( guImage( guIMAGE_INDEX_tiny_add ) );
    EnqueueMenu->Append( MenuItem );
    MenuItem->Enable( SelCount );

    MenuItem = new wxMenuItem( EnqueueMenu, ID_ARTIST_ENQUEUE_AFTER_ARTIST,
                            wxString( _( "Current Artist" ) ) +  guAccelGetCommandKeyCodeString( ID_TRACKS_ENQUEUE_AFTER_TRACK ),
                            _( "Add current selected tracks to playlist after the current artist" ) );
    MenuItem->SetBitmap( guImage( guIMAGE_INDEX_tiny_add ) );
    EnqueueMenu->Append( MenuItem );
    MenuItem->Enable( SelCount );

    Menu->Append( wxID_ANY, _( "Enqueue After" ), EnqueueMenu );

    if( SelCount )
    {
        Menu->AppendSeparator();

        MenuItem = new wxMenuItem( Menu, ID_ARTIST_EDITLABELS,
                            wxString( _( "Edit Labels" ) ) + guAccelGetCommandKeyCodeString( ID_PLAYER_PLAYLIST_EDITLABELS ),
                            _( "Edit the labels assigned to the selected artists" ) );
        MenuItem->SetBitmap( guImage( guIMAGE_INDEX_tags ) );
        Menu->Append( MenuItem );

        if( ContextMenuFlags & guCONTEXTMENU_EDIT_TRACKS )
        {
            MenuItem = new wxMenuItem( Menu, ID_ARTIST_EDITTRACKS,
                            wxString( _( "Edit Songs" ) ) + guAccelGetCommandKeyCodeString( ID_PLAYER_PLAYLIST_EDITTRACKS ),
                            _( "Edit the songs from the selected artists" ) );
            MenuItem->SetBitmap( guImage( guIMAGE_INDEX_tiny_edit ) );
            Menu->Append( MenuItem );
        }

        Menu->AppendSeparator();

        MenuItem = new wxMenuItem( Menu, ID_ARTIST_SAVETOPLAYLIST,
                            wxString( _( "Save to Playlist" ) ) + guAccelGetCommandKeyCodeString( ID_PLAYER_PLAYLIST_SAVE ),
                            _( "Save the selected tracks to playlist" ) );
        MenuItem->SetBitmap( guImage( guIMAGE_INDEX_tiny_doc_save ) );
        Menu->Append( MenuItem );

        MenuItem = new wxMenuItem( Menu, ID_ARTIST_CREATE_BESTOF_PLAYLIST,
                            wxString( _( "Create Best of Playlist" ) ),
                            _( "Create a playlist with the best of this artist" ) );
        Menu->Append( MenuItem );

        if( ( ContextMenuFlags & guCONTEXTMENU_COPY_TO ) ||
            ( ContextMenuFlags & guCONTEXTMENU_LINKS ) ||
            ( ContextMenuFlags & guCONTEXTMENU_COMMANDS ) )
        {
            Menu->AppendSeparator();

            if( ContextMenuFlags & guCONTEXTMENU_COPY_TO )
            {
                m_LibPanel->CreateCopyToMenu( Menu );
            }

            if( SelCount == 1 && ( ContextMenuFlags & guCONTEXTMENU_LINKS ) )
            {
                AddOnlineLinksMenu( Menu );
            }

            if( ContextMenuFlags & guCONTEXTMENU_COMMANDS )
                AddArtistCommands( Menu, SelCount );
        }
    }

    m_LibPanel->CreateContextMenu( Menu );
}

// -------------------------------------------------------------------------------- //
void guArListBox::OnSearchLinkClicked( wxCommandEvent &event )
{
    unsigned long cookie;
    int Item = GetFirstSelected( cookie );
    if( Item != wxNOT_FOUND )
    {
        ExecuteOnlineLink( event.GetId(), GetSearchText( Item ) );
    }
}

// -------------------------------------------------------------------------------- //
void guArListBox::OnCommandClicked( wxCommandEvent &event )
{
    wxArrayInt Selection = GetSelectedItems();
    if( Selection.Count() )
    {
        guConfig * Config = ( guConfig * ) guConfig::Get();
        if( Config )
        {
            wxString current_desktop = Config->ReadStr(CONFIG_KEY_GENERAL_DESKTOP, wxEmptyString, CONFIG_PATH_GENERAL);
            wxString category_execs = wxString::Format(CONFIG_PATH_COMMANDS_DESKTOP_EXECS, current_desktop);
            wxArrayString Commands = Config->ReadAStr(CONFIG_KEY_COMMANDS_EXEC, wxEmptyString, category_execs);

            //guLogMessage( wxT( "CommandId: %u" ), index );
            int CommandIndex = event.GetId() - ID_COMMANDS_BASE;
            wxString CurCmd = Commands[ CommandIndex ];

            if( CurCmd.Find( guCOMMAND_ALBUMPATH ) != wxNOT_FOUND )
            {
                wxArrayInt AlbumList;
                m_Db->GetArtistsAlbums( Selection, &AlbumList );
                wxArrayString AlbumPaths = m_Db->GetAlbumsPaths( AlbumList );
                wxString Paths = wxEmptyString;
                int count = AlbumPaths.Count();
                for( int index = 0; index < count; index++ )
                {
                    AlbumPaths[ index ].Replace( wxT( " " ), wxT( "\\ " ) );
                    Paths += wxT( " " ) + AlbumPaths[ index ];
                }
                CurCmd.Replace( guCOMMAND_ALBUMPATH, Paths.Trim( false ) );
            }

            if( CurCmd.Find( guCOMMAND_COVERPATH ) != wxNOT_FOUND )
            {
                wxArrayInt AlbumList;
                m_Db->GetArtistsAlbums( Selection, &AlbumList );
                int CoverId = m_Db->GetAlbumCoverId( AlbumList[ 0 ] );
                wxString CoverPath = wxEmptyString;
                if( CoverId > 0 )
                {
                    CoverPath = wxT( "\"" ) + m_Db->GetCoverPath( CoverId ) + wxT( "\"" );
                }
                CurCmd.Replace( guCOMMAND_COVERPATH, CoverPath );
            }

            if( CurCmd.Find( guCOMMAND_TRACKPATH ) != wxNOT_FOUND )
            {
                guTrackArray Songs;
                wxString SongList = wxEmptyString;
                if( m_Db->GetArtistsSongs( Selection, &Songs ) )
                {
                    int count = Songs.Count();
                    for( int index = 0; index < count; index++ )
                    {
                        SongList += wxT( " \"" ) + Songs[ index ].m_FileName + wxT( "\"" );
                    }
                    CurCmd.Replace( guCOMMAND_TRACKPATH, SongList.Trim( false ) );
                }
            }

            //guLogMessage( wxT( "Execute Command '%s'" ), CurCmd.c_str() );
            guExecute( CurCmd );
        }
    }
}

// -------------------------------------------------------------------------------- //
wxString guArListBox::GetSearchText( int item ) const
{
    return GetItemName( item );
}

// -------------------------------------------------------------------------------- //
bool guArListBox::SelectArtistName( const wxString &ArtistName )
{
    int item = FindItem( 0, ArtistName, false );
    if( item != wxNOT_FOUND )
    {
        wxArrayInt * Artists = new wxArrayInt();
        Artists->Add( ( * m_Items )[ item ].m_Id );

        wxCommandEvent event( wxEVT_MENU, ID_ARTIST_SETSELECTION );
        event.SetClientData( ( void * ) Artists );
        wxPostEvent( guMainFrame::GetMainFrame(), event );

        return true;
    }
    return false;
}

// -------------------------------------------------------------------------------- //
int guArListBox::FindArtist( const int artistid )
{
    int Count = m_Items->Count();
    for( int Index = 0; Index < Count; Index++ )
    {
        if( m_Items->Item( Index ).m_Id == artistid )
        {
            return Index;
        }
    }
    return wxNOT_FOUND;
}

}

// -------------------------------------------------------------------------------- //
