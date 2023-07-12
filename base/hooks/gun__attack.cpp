#include "../core/hooks.h"
#include "../core/displacement.h"
#include "../features/ragebot.h"

// angle = 'targ' in assaultcube
bool __fastcall Hooks::hkgun__attack( Gun_t* ecx, int edx, Vector* angle ) {
	const auto og{ gun__attack.Original<decltype( &hkgun__attack )>( ) };

	if ( !Configs::m_cConfig.m_bAimbotEnable
		|| !ecx->m_pOwner->m_bAttacking
		|| ecx->m_pOwner != *Displacement::LocalPlayer )
		return og( ecx, edx, angle );

	auto& local{ ( *Displacement::LocalPlayer ) };

	const auto backupOrigin{ local->m_vecOrigin };

	Features::Ragebot.Main( angle );

	auto ret{ og( ecx, edx, angle ) };

	( *Displacement::LocalPlayer )->m_vecOrigin = backupOrigin;

	return ret;
}