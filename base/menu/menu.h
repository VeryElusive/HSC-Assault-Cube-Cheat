#pragma once
#include "../utils/render.h"
#include "../core/input.h"
#include "controls/tabs.h"

// colors
#define ACCENT2 Color( 182, 139, 252 )
#define ACCENT Color( 115, 155, 255 )

#define BACKGROUND Color( 20, 20, 20 )
#define GROUP Color( 25, 25, 25 )

#define OUTLINE_LIGHT Color( 55, 55, 55 )
#define OUTLINE_DARK Color( 10, 10, 10 )

#define DIM_ELEMENT Color( 80, 80, 80 )
#define HOVERED_ELEMENT Color( 150, 150, 150 )
#define SELECTED_ELEMENT Color( 200, 200, 200 )

// other menu stuff
#define HEADER 50
#define MARGIN 20

inline HCURSOR CursorArrow;
inline HCURSOR CursorResize;

namespace Menu {
	void Render( float elapsed );
	void RenderElements( );
	void Register( );

	void HandleControls( );
	void SetCursor( bool resize );

	/* main */
	inline bool m_bOpened{ };
	inline bool m_bRendering{ };
	inline float m_flAlpha{ };

	inline Vector2D m_vecDrawPos{ };

	inline void* m_pPopup{ };
	inline uint8_t m_iSelectedTab{ };

	inline CMenuTab m_cTabs[ 4 ]{ };

	inline Vector2D m_vecSize{ 650, 650 };
	inline Vector2D m_vecPos{ 500, 200 };

	/* control stuff */
	inline bool m_bDraggingMenu{ };
	inline bool m_bDraggingSize{ };
}