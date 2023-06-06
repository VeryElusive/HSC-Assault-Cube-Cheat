#include "menu.h"

void Menu::Register( ) {
	m_cTabs[ 0 ].m_szName = "A";
	m_cTabs[ 1 ].m_szName = "C";
	m_cTabs[ 2 ].m_szName = "D";
	m_cTabs[ 3 ].m_szName = "E";


}

void Menu::RenderElements( ) {
	// tabs
	for ( int i{ }; i < 4; ++i ) {
		// TODO: text width maaaaan

		const Vector2D pos{ Menu::m_vecPos + Vector2D( ( m_vecSize.x / 5 ) * ( i + 1 ), 45 ) };

		const auto hovered{ Input::Hovered( pos + Vector2D( 0, -15 ), { 30, 30 } ) };
		if ( hovered && Input::Pressed( VK_LBUTTON ) )
			m_iSelectedTab = i;

		Fonts::Tabs.Render( pos, m_iSelectedTab == i ? SELECTED_ELEMENT : hovered ? HOVERED_ELEMENT : DIM_ELEMENT, m_cTabs[ i ].m_szName, true );
	}

	m_vecDrawPos = m_vecPos + Vector2D( MARGIN, HEADER + MARGIN );
}