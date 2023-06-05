#include "menu.h"
#include "../core/displacement.h"


void Menu::Render( float elapsed ) {
	if ( m_flMenuAlpha >= 0 && !m_bOpened )
		m_flMenuAlpha -= 5.f * elapsed;
	else if ( m_flMenuAlpha <= 1 && m_bOpened )
		m_flMenuAlpha += 5.f * elapsed;

	m_flMenuAlpha = std::max( std::min( m_flMenuAlpha, 1.f ), 0.f );

	if ( m_flMenuAlpha <= 0 )
		return;

	HandleControls( );

	Render::Rect( m_vecPos - Vector2D( 1, 1 ), m_vecSize + 2, DARKOUTLINECOL );
	Render::Rect( m_vecPos, m_vecSize, LIGHTOUTLINECOL );
	Render::Rect( m_vecPos + 1, m_vecSize - Vector2D( 2, 2 ), DARKOUTLINECOL );
	Render::RectFilled( m_vecPos + 2, m_vecSize - Vector2D( 4, 4 ), BACKGROUNDCOL );

	Render::Line( m_vecPos + Vector2D( 1, 51 ), m_vecPos + Vector2D( m_vecSize.x - 2, 51 ), DARKOUTLINECOL );
	Render::Line( m_vecPos + Vector2D( 0, 50 ), m_vecPos + Vector2D( m_vecSize.x, 50 ), LIGHTOUTLINECOL );
	Render::Line( m_vecPos + Vector2D( 1, 49 ), m_vecPos + Vector2D( m_vecSize.x - 2, 49 ), DARKOUTLINECOL );


	Fonts::Menu.Render( m_vecPos + Vector2D( m_vecSize.x / 2 - 5 * 5, 25 ), ACCENTCOL, "HAVOC" );
}

void Menu::HandleControls( ) {
	const bool topBarHovered{ Input::Hovered( m_vecPos, { m_vecSize.x, 50 } ) };

	if ( !m_bDraggingMenu && Input::Pressed( VK_LBUTTON ) && topBarHovered )
		m_bDraggingMenu = true;

	else if ( m_bDraggingMenu && Input::Down( VK_LBUTTON ) )
		m_vecPos -= Input::m_vecMouseDelta;
	else if ( m_bDraggingMenu && !Input::Down( VK_LBUTTON ) )
		m_bDraggingMenu = false;


	const bool BottomCornerHovered{ Input::Hovered( m_vecPos + m_vecSize - Vector2D( 20, 20 ), Vector2D( 20, 20 ) ) };

	if ( BottomCornerHovered || m_bDraggingSize ) {
		SetCursor( true );

		if ( Input::Down( VK_LBUTTON ) ) {
			m_bDraggingSize = true;
			m_vecSize += Vector2D( Input::m_vecMousePos - ( m_vecPos + m_vecSize ) );
		}
		else
			m_bDraggingSize = false;
		
	}
	else
		SetCursor( false );

	m_vecSize.x = std::clamp( static_cast< int >( m_vecSize.x ), 550, 1000 );
	m_vecSize.y = std::clamp( static_cast< int >( m_vecSize.y ), 420, 1000 );
}

void Menu::SetCursor( bool resize ) {
	if ( resize )
		SetCursor( CursorResize );
	else
		SetCursor( CursorArrow );
}