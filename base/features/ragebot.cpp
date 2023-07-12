#include "ragebot.h"
#include "../utils/render.h"

void CRagebot::Main( Vector* angle ) {
	auto& local{ ( *Displacement::LocalPlayer ) };

	Player_t* bestPlayer{ };
	float bestOriginDiff{ FLT_MAX };

	for ( int i{ }; i < *Displacement::EntityListSize; ++i ) {
		const auto player{ ( *Displacement::EntityListBase )[ i ] };
		if ( !player )
			continue;

		if ( player->m_iTeam == local->m_iTeam )
			continue;

		const auto orDiff{ local->m_vecOrigin.DistTo( player->m_vecOrigin ) };
		if ( orDiff < bestOriginDiff ) {
			bestOriginDiff = orDiff;
			bestPlayer = player;
		}
	}

	if ( bestPlayer ) {
		if ( Configs::m_cConfig.m_bAimbotThroughWalls )
			local->m_vecOrigin = bestPlayer->m_vecOrigin;

		*angle = bestPlayer->m_vecOrigin;// getAngle( ( *Displacement::LocalPlayer )->m_vecOrigin, bestPlayer->m_vecOrigin );
	}
}