#pragma once

ComboElement_t comboElements[ ]{ "hello", "what's", "up", "guys" };

MultiElement_t multiComboElements[ 5 ]{
	{ &ctx.m_cConfig.m_bOptions[0], "option 1" },
	{ &ctx.m_cConfig.m_bOptions[1], "option 2" },
	{ &ctx.m_cConfig.m_bOptions[2], "option 3" },
	{ &ctx.m_cConfig.m_bOptions[3], "option 4" },
	{ &ctx.m_cConfig.m_bOptions[4], "option 5" },
};