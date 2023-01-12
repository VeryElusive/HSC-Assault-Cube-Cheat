#pragma once
#include <Windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "../sdk/color.h"
#include "../sdk/vector.h"

namespace Render {
	void BeginDraw( );
	void EndDraw( );

	void Rect( Vector2D pos, Vector2D size, Color col );
	void RectFilled( Vector2D pos, Vector2D size, Color col );
}