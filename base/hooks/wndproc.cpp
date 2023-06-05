#include "../utils/render.h"
#include "../core/hooks.h"
#include "../menu/menu.h"
#include "../core/displacement.h"

void EnableCursor( bool disable = false ) {
	const auto backup{ *Displacement::byte_593F19 };
	*Displacement::byte_593F19 = !disable;

	Displacement::inputgrab( disable, disable );

	*Displacement::byte_593F19 = backup;
}

LRESULT __stdcall Hooks::hkWndProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam ) {
	if ( GetForegroundWindow( ) != ctx.hwnd )
		return CallWindowProc( OldWndProc, hWnd, uMsg, wParam, lParam );

	if ( uMsg == WM_KEYDOWN && wParam == VK_INSERT ) {
		Menu::m_bOpened = !Menu::m_bOpened;
		EnableCursor( !Menu::m_bOpened );
	}

	if ( Menu::m_bOpened )
		return 0;

	return CallWindowProc( OldWndProc, hWnd, uMsg, wParam, lParam );
}