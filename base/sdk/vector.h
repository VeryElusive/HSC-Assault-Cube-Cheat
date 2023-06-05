#pragma once

struct Vector {
	int x{ }, y{ }, z{ };

	Vector( ) {};

	Vector( int x, int y, int z ) : x( x ), y( y ), z( z ) {};
};

struct Vector2D {
	int x{ }, y{ };

	constexpr bool operator > ( const Vector2D& rhs ) const {
		return ( this->x > rhs.x && this->y > rhs.y );
	}

	constexpr bool operator < ( const Vector2D& rhs ) const {
		return ( this->x < rhs.x&& this->y < rhs.y );
	}

	__forceinline Vector2D operator+( Vector2D v ) const {
		return Vector2D( x + v.x, y + v.y );
	}

	__forceinline Vector2D operator-( Vector2D v ) const {
		return Vector2D( x - v.x, y - v.y );
	}

	__forceinline Vector2D operator+( int v ) const {
		return Vector2D( x + v, y + v );
	}

	__forceinline Vector2D operator-( int v ) const {
		return Vector2D( x - v, y - v );
	}

	__forceinline Vector2D operator*( float v ) const {
		return Vector2D( x * v, y * v );
	}

	__forceinline void operator-=( Vector2D v ) {
		this->x -= v.x;
		this->y -= v.y;
	}

	__forceinline void operator-=( int v ) {
		this->x -= v;
		this->y -= v;
	}

	__forceinline void operator+=( Vector2D v ) {
		this->x += v.x;
		this->y += v.y;
	}

	__forceinline void operator*=( float v ) {
		this->x *= v;
		this->y *= v;
	}

	Vector2D( ) {};

	Vector2D( int x, int y ) : x( x ), y( y ) {};
};