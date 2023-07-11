#pragma once

struct Gun_t;



// struct name is assault cube is 'playerent'
struct Player_t {
	char pad[ 0x204 ]{ };// 0x0
	bool m_bAttacking{ };//0x204
	char pad2[ 0x15F ]{ };//0x205
	Gun_t* m_pWeapon{ };//0x364
};

// struct name in assault cube is 'gun'
struct Gun_t {
	char pad[ 0x8 ]{ };// 0x0
	Player_t* m_pOwner{ };//0x8
};