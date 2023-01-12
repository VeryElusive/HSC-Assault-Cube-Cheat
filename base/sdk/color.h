#pragma once
#include <stdint.h>


class Color {
public:
	Color( uint8_t red, uint8_t green, uint8_t blue ) : r( red ), g( green ), b( blue ) {};
	Color( uint8_t red, uint8_t green, uint8_t blue, float alpha ) : r( red ), g( green ), b( blue ), a( alpha ) {};
	Color( int hex ) {
		r = ( ( hex >> 16 ) & 0xFF ) / 255;
		g = ( ( hex >> 8 ) & 0xFF ) / 255;
		b = ( ( hex ) & 0xFF ) / 255;
	};

	int ToHex( ) {
		return ( ( r & 0xff ) << 16 ) + ( ( g & 0xff ) << 8 ) + ( b & 0xff );
	}

	uint8_t r{ }, g{ }, b{ }, a{ 255 };
};