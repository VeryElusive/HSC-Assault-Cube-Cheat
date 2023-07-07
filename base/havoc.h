#pragma once
#include <cstdint>
#include <vector>
#include <optional>
#include <string_view>
#include <Windows.h>
#include <algorithm>

#include "core/memory.h"

#include "sdk/vector.h"

struct Context_t {
	HWND hwnd;

	float m_flElapsed{ };
};

inline Context_t ctx;