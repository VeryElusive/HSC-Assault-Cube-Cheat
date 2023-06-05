#pragma once
//Thank you c5 for your help!
#include <windows.h>
#include <stdio.h>
#include <gl\GL.h>
#include "../sdk/vector.h"
#include "../sdk/color.h"

class CFont {
public:
	HDC hdc{ };

	bool m_bBuilt{ };
	unsigned int m_iBase{ };

	void Setup( const char* fontName, int height, int weight, int quality );
	void Render( Vector2D pos, Color col, const char* text, bool centered = false );
};