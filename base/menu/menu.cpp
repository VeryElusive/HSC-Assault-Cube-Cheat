#include "menu.h"
#include "../core/displacement.h"

void Menu::Render( float elapsed ) {
	if ( m_flAlpha >= 0 && !m_bOpened )
		m_flAlpha -= 5.f * elapsed;
	else if ( m_flAlpha <= 1 && m_bOpened )
		m_flAlpha += 5.f * elapsed;

	m_flAlpha = std::clamp( m_flAlpha, 0.f, 1.f );

	if ( m_flAlpha <= 0 )
		return;

	HandleControls( );

	m_bRendering = true;

	Render::Rect( m_vecPos - Vector2D( 1, 1 ), m_vecSize + 2, OUTLINE_DARK );
	Render::Rect( m_vecPos, m_vecSize, OUTLINE_LIGHT );
	Render::Rect( m_vecPos + 1, m_vecSize - Vector2D( 2, 2 ), OUTLINE_DARK );
	Render::RectFilled( m_vecPos + 2, m_vecSize - Vector2D( 4, 4 ), BACKGROUND );

	Render::Line( m_vecPos + Vector2D( 1, HEADER + 1 ), m_vecPos + Vector2D( m_vecSize.x - 2, HEADER + 1 ), OUTLINE_DARK );
	Render::Line( m_vecPos + Vector2D( 0, HEADER ), m_vecPos + Vector2D( m_vecSize.x, HEADER ), OUTLINE_LIGHT );
	Render::Line( m_vecPos + Vector2D( 1, HEADER - 1 ), m_vecPos + Vector2D( m_vecSize.x - 2, HEADER - 1 ), OUTLINE_DARK );

	Fonts::Menu.Render( m_vecPos + Vector2D( m_vecSize.x / 2 - 5 * 5, 25 ), ACCENT, "HAVOC" );

	RenderElements( );

	m_bRendering = false;
}

void Menu::HandleControls( ) {
	const auto topBarHovered{ Input::Hovered( m_vecPos, { m_vecSize.x, 50 } ) };

	if ( !m_bDraggingMenu && Input::Pressed( VK_LBUTTON ) && topBarHovered )
		m_bDraggingMenu = true;

	else if ( m_bDraggingMenu && Input::Down( VK_LBUTTON ) )
		m_vecPos -= Input::m_vecMouseDelta;
	else if ( m_bDraggingMenu && !Input::Down( VK_LBUTTON ) )
		m_bDraggingMenu = false;


	const auto bottomCornerHovered{ Input::Hovered( m_vecPos + m_vecSize - Vector2D( 20, 20 ), Vector2D( 20, 20 ) ) };

	if ( bottomCornerHovered || m_bDraggingSize ) {
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