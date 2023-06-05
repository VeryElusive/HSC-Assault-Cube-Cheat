#pragma once
#include "gl_text.h"

void CFont::Setup( const char* fontName, int height, int weight, int quality ) {
	hdc = wglGetCurrentDC( );
	m_iBase = glGenLists( 96 );
	HFONT hFont = CreateFontA( -( height ), 0, 0, 0, weight, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, quality, FF_DONTCARE | DEFAULT_PITCH, fontName );
	HFONT hOldFont = ( HFONT ) SelectObject( hdc, hFont );
	wglUseFontBitmaps( hdc, 32, 96, m_iBase );
	SelectObject( hdc, hOldFont );
	DeleteObject( hFont );

	m_bBuilt = true;
}

void CFont::Render( Vector2D pos, Color col, const char* text, bool centered ) {
	glColor4ub( col.r, col.g, col.b, col.a );
	glRasterPos2f( pos.x, pos.y );

	// TODO:
	if ( centered ) {
		//pos.x -= 
	}

	glPushAttrib( GL_LIST_BIT );
	glListBase( m_iBase - 32 );
	glCallLists( strlen( text ), GL_UNSIGNED_BYTE, text );
	glPopAttrib( );
}