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

namespace Hooks {

	inline CHooked GlDrawHud{ };
	void __cdecl hkGlDrawHud( int w, int h, int curfps, int nquads, int curvert, bool underwater, int elapsed );

	void Init( );
}