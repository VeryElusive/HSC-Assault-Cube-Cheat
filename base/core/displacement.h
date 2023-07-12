#pragma once
#include "memory.h"
#include "../sdk/player.h"

#define SIG_ADD_RECAST( name, addr, addOffset, type ) inline type* name{ *reinterpret_cast<type**>( Memory::FindPattern( addr ) + addOffset ) };
#define SIG_OFFSET( name, addr, addOffset ) inline std::uintptr_t name{ Memory::FindPattern( addr ) + addOffset };
#define FUNCTION( name, addr, addOffset, callType ) inline callType name{ reinterpret_cast<callType>( Memory::FindPattern( addr ) + addOffset ) };
#define ADDRESS( name, addr ) SIG_OFFSET( name, addr, 0 );

typedef void( __fastcall* inputgrab_t )( bool, uint8_t );
typedef void( __vectorcall* RayDamage_t )( Vector& from, Vector& to, Player_t* d );

namespace Displacement {
	SIG_ADD_RECAST( VIRTW, "66 0F 6E 05 ? ? ? ? F3 0F E6 C0 F2 0F 11 44 24 ? F2 0F 11 0C 24 FF 15 ? ? ? ? 68 ? ? ? ? FF 15 ? ? ? ? 80", 4, int );
	SIG_ADD_RECAST( byte_593F19, "6A 01 FF 15 ? ? ? ? 83 C4 04 80 3D ? ? ? ? ? 74 20", 13, bool );

	// IMPORTANT NOTE: LOCAL PLAYER DOES NOT APPEAR IN THE ENTITY LIST
	SIG_ADD_RECAST( EntityListSize, "3B 0D ? ? ? ? 7D 1B A1 ? ? ? ? 8B 34 88", 2, int );
	SIG_ADD_RECAST( EntityListBase, "A1 ? ? ? ? 8B 04 88 85 C0 74 38 C7 80", 1, Player_t** );
	// this was messing up and i cant be bothered finding out why so im hardcoding the offset here
	//inline uintptr_t* EntityListBase = *( uintptr_t** ) ( ( ( uintptr_t ) GetModuleHandleA( "ac_client.exe" ) ) + 0x18AC04 );
	SIG_ADD_RECAST( LocalPlayer, "3B 05 ? ? ? ? E9", 2, Player_t* );
	ADDRESS( draw_text, "83 EC 60 8A 44 24 68 88 44 24 30 8A 44" );
	ADDRESS( defformatstring, "8B 44 24 04 BA ? ? ? ? 56 8B 30 8D 44" );
	SIG_OFFSET( hits_SIZE, "C7 05 ? ? ? ? ? ? ? ? 8D 54 24 0C", 2 );
	//SIG_ADD_RECAST( totalmillis, "A1 ? ? ? ? 2B C1 3D ? ? ? ? 0F 8C ? ? ? ? 6A", 1, int );
	FUNCTION( inputgrab, "53 8A DA 84 C9 74 7B", 0, inputgrab_t );
	FUNCTION( RayDamage, "55 8B EC 83 E4 C0 81 EC ? ? ? ? 53 8B", 0, RayDamage_t );
}

#undef ADDRESS
#undef FUNCTION
#undef SIG_OFFSET
#undef SIG_ADD_RECAST