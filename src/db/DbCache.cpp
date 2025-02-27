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
#include "DbCache.h"

#include "Utils.h"

#include <wx/mstream.h>

namespace Guayadeque {

guDbCache * guDbCache::m_DbCache = NULL;

// -------------------------------------------------------------------------------- //
guDbCache::guDbCache( const wxString &dbname ) : guDb( dbname )
{
  wxArrayString query;

  query.Add( wxT( "CREATE TABLE IF NOT EXISTS cache( cache_id INTEGER PRIMARY KEY AUTOINCREMENT, " \
                  "cache_key varchar, cache_data BLOB, cache_time INTEGER, " \
                  "cache_type INTEGER, cache_size INTEGER  );" ) );

  query.Add( wxT( "CREATE UNIQUE INDEX IF NOT EXISTS 'cache_id' on cache( cache_id ASC );" ) );
  query.Add( wxT( "CREATE INDEX IF NOT EXISTS 'cache_key' on cache( cache_key ASC );" ) );
  query.Add( wxT( "CREATE INDEX IF NOT EXISTS 'cache_time' on cache( cache_time ASC );" ) );

  int Count = query.Count();
  for( int Index = 0; Index < Count; Index++ )
  {
      //guLogMessage( query[ Index ] );
    ExecuteUpdate( query[ Index ] );
  }

}

// -------------------------------------------------------------------------------- //
guDbCache::~guDbCache()
{
}

// -------------------------------------------------------------------------------- //
wxImage * guDbCache::GetImage( const wxString &url, wxBitmapType &imgtype, const int imgsize )
{
  wxImage *             Img = NULL;
  wxString              query;
  wxSQLite3ResultSet    dbRes;
  const unsigned char * Data;
  int                   DataLen = 0;

  query = wxString::Format( wxT( "SELECT cache_data, cache_type FROM cache WHERE cache_key = '%s' " \
                                 "AND cache_size = %u LIMIT 1;" ),
      escape_query_str( url ).c_str(), imgsize );

  dbRes = ExecuteQuery( query );

  if( dbRes.NextRow() )
  {
    Data = dbRes.GetBlob( 0, DataLen );
    imgtype = wxBitmapType( dbRes.GetInt( 1 ) );

    if( DataLen )
    {
      wxMemoryInputStream Ins( Data, DataLen );
      Img = new wxImage( Ins, imgtype );
      if( Img )
      {
        if( !Img->IsOk() )
        {
            guLogMessage( wxT( "Image is not OK" ) );
            delete Img;
            Img = NULL;
        }
      }
//      else
//      {
//        guLogMessage( wxT( "Could not create the image" ) );
//      }
    }
  }
//  else
//  {
//      guLogMessage( wxT( "DbCache failed '%s'" ), url.c_str() );
//  }

  dbRes.Finalize();

  return Img;
}

// -------------------------------------------------------------------------------- //
bool guDbCache::DoSetImage( const wxString &url, wxImage * img, const wxBitmapType imgtype, const int imagesize )
{
  wxMemoryOutputStream Outs;
  if( img->SaveFile( Outs, imgtype ) )
  {
      wxSQLite3Statement stmt = m_Db->PrepareStatement( wxString::Format(
          wxT( "INSERT INTO cache( cache_id, cache_key, cache_data, cache_type, cache_time, cache_size ) " \
               "VALUES( NULL, '%s', ?, %u, %lu, %u );" ),
               escape_query_str( url ).c_str(), ( int ) imgtype, wxDateTime::Now().GetTicks(), imagesize ) );
      try {
        stmt.Bind( 1, ( const unsigned char * ) Outs.GetOutputStreamBuffer()->GetBufferStart(), Outs.GetSize() );
        //guLogMessage( wxT( "%s" ), stmt.GetSQL().c_str() );
        stmt.ExecuteQuery();
        return true;
      }
      catch( wxSQLite3Exception &e )
      {
        guLogError( wxT( "%u: %s" ),  e.GetErrorCode(), e.GetMessage().c_str() );
      }
      catch(...)
      {
        guLogError( wxT( "Other exception found while updating the image in cache" ) );
      }
  }
  return false;
}

// -------------------------------------------------------------------------------- //
bool guDbCache::SetImage( const wxString &url, wxImage * img, const wxBitmapType imgtype )
{
  wxImage TmpImg( * img );
//  int Width = 150;
//  int Height = 150;
//  int ImageSize = guDBCACHE_TYPE_IMAGE_SIZE_BIG;
//  TmpImg.Rescale( Width, Height, wxIMAGE_QUALITY_HIGH );
  guImageResize( &TmpImg, 150 );
  if( !DoSetImage( url, &TmpImg, imgtype, guDBCACHE_TYPE_IMAGE_SIZE_BIG ) )
    return false;


  TmpImg = * img;
//  Width = 100;
//  Height = 100;
//  ImageSize = guDBCACHE_TYPE_IMAGE_SIZE_MID;
//  TmpImg.Rescale( Width, Height, wxIMAGE_QUALITY_HIGH );
  guImageResize( &TmpImg, 100 );
  if( !DoSetImage( url, &TmpImg, imgtype, guDBCACHE_TYPE_IMAGE_SIZE_MID ) )
    return false;

  TmpImg = * img;
//  Width = 50;
//  Height = 50;
//  ImageSize = guDBCACHE_TYPE_IMAGE_SIZE_TINY;
//  TmpImg.Rescale( Width, Height, wxIMAGE_QUALITY_HIGH );
  guImageResize( &TmpImg, 50 );
  if( !DoSetImage( url, &TmpImg, imgtype, guDBCACHE_TYPE_IMAGE_SIZE_TINY ) )
    return false;

  // delete the expired entries but call it only 5% of the times
  if( guRandom( 1000 ) < 20 )
    ClearExpired();

  return true;
}

// -------------------------------------------------------------------------------- //
wxString guDbCache::GetContent( const wxString &url )
{
  wxString              RetVal = wxEmptyString;
  wxString              query;
  wxSQLite3ResultSet    dbRes;

  query = wxString::Format( wxT( "SELECT cache_data FROM cache WHERE cache_key = '%s' LIMIT 1;" ),
             escape_query_str( url ).c_str() );

  dbRes = ExecuteQuery( query );

  if( dbRes.NextRow() )
  {
      RetVal = dbRes.GetString( 0 );
  }
  dbRes.Finalize();

  return RetVal;
}

// -------------------------------------------------------------------------------- //
bool guDbCache::SetContent( const wxString &url, const char * str, const int len )
{
  try {
    wxSQLite3Statement stmt = m_Db->PrepareStatement( wxString::Format(
      wxT( "INSERT INTO cache( cache_id, cache_key, cache_data, cache_type, cache_time, cache_size ) " \
           "VALUES( NULL, '%s', ?, %u, %lu, %u );" ),
           escape_query_str( url ).c_str(), guDBCACHE_TYPE_TEXT, wxDateTime::Now().GetTicks(), 0 ) );

    stmt.Bind( 1, ( const unsigned char * ) str, len );
    //guLogMessage( wxT( "%s" ), stmt.GetSQL().c_str() );
    stmt.ExecuteQuery();
    return true;
  }
  catch( wxSQLite3Exception &e )
  {
    guLogError( wxT( "%u: %s" ),  e.GetErrorCode(), e.GetMessage().c_str() );
  }
  return false;
}

// -------------------------------------------------------------------------------- //
bool guDbCache::SetContent( const wxString &url, const wxString &content, const int type )
{
  wxString query = wxString::Format( wxT( "INSERT INTO cache( cache_id, cache_key, cache_data, " \
                "cache_type, cache_time, cache_size ) VALUES( NULL, '%s', '%s', %u, %lu, %u );" ),
          escape_query_str( url ).c_str(),
          escape_query_str( content ).c_str(),
          type,
          wxDateTime::Now().GetTicks(),
          0 );

  ExecuteUpdate( query );

  // delete the expired entries but call it only 2% of the times
  if( guRandom( 1000 ) < 7 )
    ClearExpired();

  return true;
}

#define guDAY_SECONDS   (60 * 60 * 24)

// -------------------------------------------------------------------------------- //
void guDbCache::ClearExpired( void )
{
    // TODO : Clear different types with different periods

    // last.fm queries are kept only 7 days
    wxString query = wxString::Format( wxT( "DELETE FROM cache WHERE cache_time < %lu AND cache_type = %u" ),
        wxDateTime::Now().GetTicks() - ( guDAY_SECONDS * 7 ), guDBCACHE_TYPE_TEXT );
    ExecuteUpdate( query );

    // Images are kept 30 days
//    query = wxString::Format( wxT( "DELETE FROM cache WHERE cache_time < %lu" ), wxDateTime::Now().GetTicks() - ( guDAY_SECONDS * 30 ) );
//    ExecuteUpdate( query );

    query = wxString::Format( wxT( "DELETE FROM cache WHERE cache_time < %lu AND cache_type = %u" ),
        wxDateTime::Now().GetTicks() - ( guDAY_SECONDS * 30 ), guDBCACHE_TYPE_LASTFM );
    ExecuteUpdate( query );

    query = wxString::Format( wxT( "DELETE FROM cache WHERE cache_time < %lu AND cache_type = %u" ),
        wxDateTime::Now().GetTicks() - ( guDAY_SECONDS * 3 ), guDBCACHE_TYPE_TUNEIN );
    ExecuteUpdate( query );

    guLogMessage( wxT( "Delete expired Cache elements done" ) );
}

}

// -------------------------------------------------------------------------------- //
