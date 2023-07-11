#include "../core/hooks.h"
#include "../core/displacement.h"

bool __fastcall Hooks::hkgun__attack( Gun_t* ecx, int edx, vec* position ) {
	const auto og{ gun__attack.Original<decltype( &hkgun__attack )>( ) };

	if ( !ecx->m_pOwner->m_bAttacking )
		return og( ecx, edx, position );

	for ( int i{ }; i < *Displacement::EntityListSize; ++i )
	{
		if ( reinterpret_cast< Player_t* >( Displacement::EntityListBase[ i ] ) == nullptr )
			continue;

		auto player = reinterpret_cast< Player_t* >( Displacement::EntityListBase[ i ] );

		if ( player == ecx->m_pOwner )
			ecx->m_pOwner->m_bAttacking = false;
	}

	//ecx->m_pOwner->m_bAttacking = false;

	return og( ecx, edx, position );
}