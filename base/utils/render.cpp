#include "render.h"
#include "../core/displacement.h"

void Render::BeginDraw( ) {
    // switch to 2D drawing
    glDisable( GL_DEPTH_TEST );

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity( );

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity( );
    glOrtho( 0, **reinterpret_cast<int**>( Displacement::VIRTW ), 1800, 0, -1, 1 ); //VIRTH: 1800.f, 
    glEnable( GL_BLEND );
}

void Render::EndDraw( ) {
    glLoadIdentity( );
    glOrtho( 0, **reinterpret_cast< int** >( Displacement::VIRTW ), 1800, 0, -1, 1 );

    glDisable( GL_BLEND );
    glDisable( GL_TEXTURE_2D );
    glEnable( GL_DEPTH_TEST );

    glMatrixMode( GL_MODELVIEW );
}

void Render::Rect( Vector2D pos, Vector2D size, Color col ) {
    glColor4ub( col.r, col.g, col.b, col.a );

    glBegin( GL_LINE_LOOP );

    glVertex2f( pos.x, pos.y );
    glVertex2f( pos.x + size.x, pos.y );
    glVertex2f( pos.x + size.x, pos.y + size.y );
    glVertex2f( pos.x, pos.y + size.y );

    glEnd( );
}

void Render::RectFilled( Vector2D pos, Vector2D size, Color col ) {
    glColor4ub( col.r, col.g, col.b, col.a );

    glBegin( GL_QUADS );

    glVertex2f( pos.x, pos.y );
    glVertex2f( pos.x + size.x, pos.y );
    glVertex2f( pos.x + size.x, pos.y + size.y );
    glVertex2f( pos.x, pos.y + size.y );

    glEnd( );
}