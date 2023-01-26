#include "menu.h"
#include "../core/input.h"

void Menu::Render( ) {
	HandleControls( );

	Render::RectFilled( m_vecPos, m_vecSize, BACKGROUNDCOL );


}


void Menu::HandleControls( ) {
	const bool topBarHovered{ Input::Hovered( m_vecPos, { m_vecSize.x, 50 } ) };

	if ( !m_bDraggingMouse && Input::Pressed( VK_LBUTTON ) && topBarHovered )
		m_bDraggingMouse = true;

	else if ( m_bDraggingMouse && Input::Down( VK_LBUTTON ) )
		m_vecPos -= Input::m_vecMouseDelta;
	else if ( m_bDraggingMouse && !Input::Down( VK_LBUTTON ) )
		m_bDraggingMouse = false;
}