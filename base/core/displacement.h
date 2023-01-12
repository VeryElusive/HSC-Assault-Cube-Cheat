#pragma once
#include "memory.h"

namespace Displacement {
	std::uintptr_t VIRTW{ Memory::FindPattern( "66 0F 6E 05 ? ? ? ? F3 0F E6 C0 F2 0F 11 44 24 ? F2 0F 11 0C 24 FF 15 ? ? ? ? 68 ? ? ? ? FF 15 ? ? ? ? 80" ) + 4 };
}