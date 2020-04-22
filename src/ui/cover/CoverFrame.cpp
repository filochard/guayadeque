// -------------------------------------------------------------------------------- //
//    Copyright (C) 2008-2020 J.Rios anonbeat@gmail.com
//
//    This Program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 3, or (at your option)
//    any later version.
//
//    This Program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program; see the file LICENSE.  If not, write to
//    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
//    Boston, MA 02110-1301 USA.
//
//    http://www.gnu.org/copyleft/gpl.html
//
// -------------------------------------------------------------------------------- //
#include "CoverFrame.h"

#include "Images.h"
#include "TagInfo.h"
#include "Utils.h"
#include "Config.h"

namespace Guayadeque {

// -------------------------------------------------------------------------------- //
guCoverFrame::guCoverFrame( wxWindow * parent, wxWindowID id, const wxString & title, const wxPoint & pos, const wxSize & size, long style ) :
     wxFrame( parent, id, title, pos, size, style | wxNO_BORDER | wxFRAME_NO_TASKBAR )
{
    m_CapturedMouse = false;
    m_AutoCloseTimer = new wxTimer( this );

	SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer * CoverSizer;
	CoverSizer = new wxBoxSizer( wxVERTICAL );

	m_CoverBitmap = new wxStaticBitmap( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	CoverSizer->Add( m_CoverBitmap, 1, wxALL|wxEXPAND, 0 );

	SetSizer( CoverSizer );
	Layout();

    m_AutoCloseTimer->Start( 1000, wxTIMER_ONE_SHOT );

    Bind( wxEVT_ACTIVATE, &guCoverFrame::CoverFrameActivate, this );
    Bind( wxEVT_LEFT_DOWN, &guCoverFrame::OnClick, this );
    Bind( wxEVT_RIGHT_DOWN, &guCoverFrame::OnClick, this );
    Bind( wxEVT_MOUSEWHEEL, &guCoverFrame::OnClick, this );

    m_CoverBitmap->Bind( wxEVT_MOTION, &guCoverFrame::OnMouse, this );
    Bind( wxEVT_MOTION, &guCoverFrame::OnMouse, this );
    Bind( wxEVT_MOUSE_CAPTURE_LOST, &guCoverFrame::OnCaptureLost, this );

    Bind( wxEVT_TIMER, &guCoverFrame::OnTimer, this );
}

// -------------------------------------------------------------------------------- //
guCoverFrame::~guCoverFrame()
{
    if( m_CapturedMouse )
        ReleaseMouse();

    if( m_AutoCloseTimer )
        delete m_AutoCloseTimer;

    Unbind( wxEVT_ACTIVATE, &guCoverFrame::CoverFrameActivate, this );
    Unbind( wxEVT_LEFT_DOWN, &guCoverFrame::OnClick, this );
    Unbind( wxEVT_RIGHT_DOWN, &guCoverFrame::OnClick, this );
    Unbind( wxEVT_MOUSEWHEEL, &guCoverFrame::OnClick, this );

    m_CoverBitmap->Unbind( wxEVT_MOTION, &guCoverFrame::OnMouse, this );
    Unbind( wxEVT_MOTION, &guCoverFrame::OnMouse, this );
    Unbind( wxEVT_MOUSE_CAPTURE_LOST, &guCoverFrame::OnCaptureLost, this );

    Unbind( wxEVT_TIMER, &guCoverFrame::OnTimer, this );
}

// -------------------------------------------------------------------------------- //
void guCoverFrame::OnTimer( wxTimerEvent &event )
{
    int MouseX, MouseY;
    wxGetMousePosition( &MouseX, &MouseY );

    wxRect WinRect = m_CoverBitmap->GetScreenRect();
    if( !WinRect.Contains( MouseX, MouseY ) )
    {
        Close();
    }
}

// -------------------------------------------------------------------------------- //
void guCoverFrame::OnClick( wxMouseEvent &event )
{
    Close();
}

// -------------------------------------------------------------------------------- //
void guCoverFrame::SetBitmap( const guSongCoverType CoverType, const wxString &CoverPath )
{
    wxImage CoverImage;
    if( CoverType == GU_SONGCOVER_ID3TAG )
    {
        wxImage * id3cover = guTagGetPicture( CoverPath );
        if( id3cover )
        {
            CoverImage = * id3cover;
            delete id3cover;
        }
        else
            guLogError( wxT( "Could not retrieve the image from '%s'" ), CoverPath.c_str() );
    }
    else if( CoverType == GU_SONGCOVER_FILE )
    {
        CoverImage.LoadFile( CoverPath );
    }
    else if( CoverType == GU_SONGCOVER_NONE )
    {
        CoverImage = guImage( guIMAGE_INDEX_no_cover );
    }
    else if( CoverType == GU_SONGCOVER_RADIO )
    {
        CoverImage = guImage( guIMAGE_INDEX_net_radio );
    }
    else if( CoverType == GU_SONGCOVER_PODCAST )
    {
        CoverImage = guImage( guIMAGE_INDEX_podcast );
    }
    //
    if( CoverImage.IsOk() )
    {
        guConfig * Config = ( guConfig * ) guConfig::Get();
        int CoverFrame = Config->ReadNum( CONFIG_KEY_GENERAL_COVER_FRAME, guCOVERFRAME_DEFAULT, CONFIG_PATH_GENERAL );
        if( CoverFrame == guCOVERFRAME_DEFAULT )
        {
            wxBitmap * BlankCD = new wxBitmap( guImage( guIMAGE_INDEX_blank_cd_cover ) );
            if( BlankCD )
            {
                if( BlankCD->IsOk() )
                {
                    // 38,6
                    wxMemoryDC MemDC;
                    MemDC.SelectObject( * BlankCD );
                    CoverImage.Rescale( 250, 250, wxIMAGE_QUALITY_HIGH );
                    MemDC.DrawBitmap( wxBitmap( CoverImage ), 34, 4, false );
                    m_CoverBitmap->SetBitmap( * BlankCD );
                    //m_CoverBitmap->SetBitmap( wxBitmap( CoverImage ) );
                    m_CoverBitmap->Refresh();
                }
                SetSize( BlankCD->GetWidth(), BlankCD->GetHeight() );

                delete BlankCD;
            }
        }
        else //if( CoverFrame == guCOVERFRAME_NONE )
        {
            CoverImage.Rescale( 300, 300, wxIMAGE_QUALITY_HIGH );
            m_CoverBitmap->SetBitmap( CoverImage );
            m_CoverBitmap->Refresh();
            SetSize( 300, 300 );
        }
//        else    // guCOVERFRAME_CUSTOM
//        {
//        }
        Layout();
    }
}

// -------------------------------------------------------------------------------- //
void guCoverFrame::CoverFrameActivate( wxActivateEvent &event )
{
    if( !event.GetActive() )
      Close();
}

// -------------------------------------------------------------------------------- //
void guCoverFrame::OnCaptureLost( wxMouseCaptureLostEvent &event )
{
    m_CapturedMouse = false;
    Close();
}

// -------------------------------------------------------------------------------- //
void guCoverFrame::OnMouse( wxMouseEvent &event )
{
    int MouseX, MouseY;
    wxGetMousePosition( &MouseX, &MouseY );

    wxRect WinRect = m_CoverBitmap->GetScreenRect();
    if( !WinRect.Contains( MouseX, MouseY ) )
    {
        Close();
    }
    else
    {
        if( !m_CapturedMouse )
        {
            m_CapturedMouse = true;
            CaptureMouse();
        }
    }

    if( m_AutoCloseTimer )
        m_AutoCloseTimer->Stop();

    event.Skip();
}

}

// -------------------------------------------------------------------------------- //
