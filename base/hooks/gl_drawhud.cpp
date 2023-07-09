#include "../utils/render.h"
#include "../core/hooks.h"
#include "../menu/menu.h"

bool __stdcall Hooks::hkGlSwapBuffers( HDC hDc ) {
	const auto og{ GlSwapBuffers.Original<decltype( &hkGlSwapBuffers )>( ) };
	/*Input::Update( );

	Render::BeginDraw( );
	{
		// elapsed is in milliseconds, i want it in seconds
		Menu::Render( static_cast< float >( 1 ) / 1000.f );
	}
	Render::EndDraw( ); */

	return og( hDc );
}

void __cdecl Hooks::hkGlDrawHud( int w, int h, int curfps, int nquads, int curvert, bool underwater, int elapsed ) {
	const auto og{ GlDrawHud.Original<decltype( &hkGlDrawHud )>( ) };

	og( w, h, curfps, nquads, curvert, underwater, elapsed );

	ctx.m_flElapsed = static_cast< float >( elapsed ) / 1000.f;
	ctx.m_flTime += ctx.m_flElapsed;

	Input::Update( );
	Render::InitFonts( );

	Render::BeginDraw( );
	{
		// elapsed is in milliseconds, i want it in seconds
		Menu::Render( );

		Input::m_flScroll = 0;
	}
	Render::EndDraw( );
}