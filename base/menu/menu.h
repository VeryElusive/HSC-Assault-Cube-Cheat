#pragma once
#include "../utils/render.h"
#include "../core/input.h"

#define OUTLINECOL Color( 55, 55, 55 )
#define BACKGROUNDCOL Color( 20, 20, 20 )
#define GROUPCOL Color( 25, 25, 25 )
#define ACCENTCOL2 Color( 182, 139, 252 )
#define ACCENTCOL Color( 115, 155, 255 )

namespace Menu {
	void Render( );
	void HandleControls( );

	/* main */
	inline bool m_bOpened{ };

	inline Vector2D m_vecSize{ 650, 700 };
	inline Vector2D m_vecPos{ };

	/* control stuff */
	inline bool m_bDraggingMouse{ };
}