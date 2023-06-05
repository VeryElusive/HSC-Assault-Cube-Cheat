#pragma once
#include "../utils/render.h"
#include "../core/input.h"

#define LIGHTOUTLINECOL Color( 55, 55, 55, m_flMenuAlpha * 255)
#define DARKOUTLINECOL Color( 10, 10, 10, m_flMenuAlpha * 255)
#define BACKGROUNDCOL Color( 20, 20, 20, m_flMenuAlpha * 255 )
#define GROUPCOL Color( 25, 25, 25, m_flMenuAlpha * 255 )
#define ACCENTCOL2 Color( 182, 139, 252, m_flMenuAlpha * 255 )
#define ACCENTCOL Color( 115, 155, 255, m_flMenuAlpha * 255 )

inline HCURSOR CursorArrow;
inline HCURSOR CursorResize;

namespace Menu {
	void Render( float elapsed );
	void HandleControls( );
	void SetCursor( bool resize );

	/* main */
	inline bool m_bOpened{ };
	inline float m_flMenuAlpha{ };

	inline Vector2D m_vecSize{ 650, 650 };
	inline Vector2D m_vecPos{ };

	/* control stuff */
	inline bool m_bDraggingMenu{ };
	inline bool m_bDraggingSize{ };
}