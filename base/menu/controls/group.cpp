#include "group.h"
#include "../menu.h"

void CMenuGroup::Render( int groupNum, int maxGroups ) {
	// TODO: dynamic system for this
	if ( !( groupNum % maxGroups ) )
		Menu::m_vecDrawPos = { MARGIN, Menu::m_vecDrawPos.y + m_vecSize.y };

	Render::RectFilled( Menu::m_vecDrawPos, Menu::m_vecSize, GROUP );
	Render::RectFilled( Menu::m_vecDrawPos, Menu::m_vecSize + 2, Color( 0, 0, 0 ) );
	Render::RectFilled( Menu::m_vecDrawPos + 1, Menu::m_vecSize, OUTLINE_LIGHT );
}