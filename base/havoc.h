#pragma once
#include <cstdint>
#include <vector>
#include <optional>
#include <string_view>
#include <Windows.h>
#include <algorithm>

#include "core/config.h"
#include "core/memory.h"

#include "sdk/vector.h"

struct Context_t {
	HWND hwnd;
	Config_t m_cConfigs{ };
	float m_flElapsed{ };
};

inline Context_t ctx;