#pragma once
#include <vector>
#include "../../sdk/vector.h"
#include "../../sdk/color.h"

enum EItemType {
	CHECKBOX
};

class CMenuItem {
public:
	CMenuItem( void* value, EItemType type ) 
		: m_pValue( value ), m_eItemType( type ) { };

	void* m_pValue{ };
	EItemType m_eItemType{ };

	short m_flAnimation{ };
};

class CMenuGroup {
public:
	CMenuGroup( const char* name, Vector2D size )
		: m_vecSize( size ), m_szName( name ) {};

	void RegisterCheckbox( void* value, EItemType type ) { 
		m_vecItems.emplace_back( value, type ); 
	};

	void Render( int groupNum, int maxGroups );

	/*bool NewLine( ) {
		return Menu::m_vecDrawPos.x - Menu::m_vecPos.x + MARGIN * 2 + m_vecSize.x > Menu::m_vecSize.x;
	}*/

private:
	std::vector< CMenuItem > m_vecItems{ };
	Vector2D m_vecSize{ };
	const char* m_szName{ };
};

