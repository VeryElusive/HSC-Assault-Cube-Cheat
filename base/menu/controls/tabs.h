#pragma once
#include "group.h"

class CMenuSubtab {
private:
	const char* m_szName{ };
	std::vector < CMenuGroup > m_vecGroups{ };
};

class CMenuTab {
public:
	const char* m_szName{ };
	std::vector< CMenuSubtab > m_vecSubtabs{ };

	uint8_t m_iSelectedSubtab{ };
};