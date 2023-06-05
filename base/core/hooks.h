#pragma once
#include "../dependencies/minhook/minhook.h"
#include "../havoc.h"

// just using minhook temporarily, will replace it later with manual VMT hooking
// minhook library is extremely useful (and commonly used) in real-world software that hook functions.
class CHooked {
public:
	bool Hook( void* ptrTo, void* newPTR ) {
		auto status{ MH_CreateHook( ptrTo, newPTR, &m_pOriginal ) };

		// log unsuccessful hooking attemps mb?
		if ( status != MH_OK )
			return false;

		status = MH_EnableHook( ptrTo );

		return status == MH_OK;
	}

	template <typename Fn>
	Fn Original( ) {
		return static_cast< Fn >( m_pOriginal );
	}

	void* m_pOriginal{ };
};

#define NEW_HOOK(name, returnVal, callingConvention) inline CHooked name{ }; returnVal callingConvention hk##name(

namespace Hooks {

	NEW_HOOK( GlDrawHud, void, __cdecl ) int w, int h, int curfps, int nquads, int curvert, bool underwater, int elapsed );
	NEW_HOOK( GlSwapBuffers, bool, __stdcall ) HDC hDc );

	inline WNDPROC OldWndProc{ };
	LRESULT __stdcall	hkWndProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam );

	void Init( );
}