#include "../utils/render.h"
#include "../core/hooks.h"
#include "../menu/menu.h"

void __cdecl Hooks::hkGlDrawHud( int w, int h, int curfps, int nquads, int curvert, bool underwater, int elapsed ) {
	const auto og{ GlDrawHud.Original<decltype( &hkGlDrawHud )>( ) };

	og( w, h, curfps, nquads, curvert, underwater, elapsed );

	Input::Update( );

	Render::BeginDraw( );
	{
		Menu::Render( );
	}
	Render::EndDraw( );
}