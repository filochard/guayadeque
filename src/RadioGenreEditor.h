// -------------------------------------------------------------------------------- //
//	Copyright (C) 2008-2016 J.Rios anonbeat@gmail.com
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
//    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//    http://www.gnu.org/copyleft/gpl.html
//
// -------------------------------------------------------------------------------- //
#ifndef RADIOGENREEDITOR_H
#define RADIOGENREEDITOR_H

#include "DbRadios.h"

#include <wx/string.h>
#include <wx/checklst.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/button.h>
#include <wx/dialog.h>

namespace Guayadeque {

// -------------------------------------------------------------------------------- //
class guRadioGenreEditor : public wxDialog
{
  private:
    guDbRadios *            m_Db;
    guListItems             m_AddedGenres;
    wxArrayString           m_RadioGenres;

  protected:
    wxCheckListBox*         m_CheckListBox;
    wxStaticText*           m_InputStaticText;
    wxTextCtrl*             m_InputTextCtrl;

  public:
    guRadioGenreEditor( wxWindow* parent, guDbRadios * db ); //
    ~guRadioGenreEditor();
    void GetGenres( wxArrayString &addedgenres, wxArrayInt &deletedgenres );

};

}

#endif
// -------------------------------------------------------------------------------- //
