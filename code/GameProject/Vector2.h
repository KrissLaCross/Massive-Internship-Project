#ifndef HEADER_VECTOR2
#define HEADER_VECTOR2

#define Sgn(x) (x < 0 ? -1 : (x > 0 ? 1 : 0))

#include <math.h>
#include <SFML\System\Vector2.hpp>

namespace stoffe
{
	template<typename T> struct Vector2
	{
		union
		{
			T x;
			T myX;
		};

		union
		{
			T y;
			T myY;
		};

		Vector2() : x(0), y(0) {};
		Vector2(T aValue) : x(aValue), y(aValue) {};
		Vector2(T xValue, T yValue) : x(xValue), y(yValue) {};
		Vector2(const Vector2<T> & other) : x(other.x), y(other.y) {};
		Vector2(const Vector2<T> * other) : x(other->x), y(other->y) {};

		Vector2(const sf::Vector2<T>& other) : x(other.x), y(other.y) {};
		operator sf::Vector2<T>() { return sf::Vector2<T>(x, y); }
		
		template <typename U>
		inline Vector2(const sf::Vector2<U>& vector) :
			x(static_cast<T>(vector.x)),
			y(static_cast<T>(vector.y))
		{
		}

		static Vector2<T> FromPolar(float aAngle, float aRadius = 1) { return Vector2<T>(cos(aAngle) * aRadius, sin(aAngle) * aRadius); }

		~Vector2() {};

		Vector2<T> Set(T xValue, T yValue) { x = xValue; y = yValue; return *this; }

		inline Vector2<T> operator-() { return Vector2<T>(-x, -y); }

		inline Vector2<T> operator+(const Vector2<T> & rhs) { return Vector2<T>(x + rhs.x, y + rhs.y); }
		inline Vector2<T> operator-(const Vector2<T> & rhs) { return Vector2<T>(x - rhs.x, y - rhs.y); }
		inline Vector2<T> operator*(const Vector2<T> & rhs) { return Vector2<T>(x * rhs.x, y * rhs.y); }
		inline Vector2<T> operator/(const Vector2<T> & rhs) { return Vector2<T>(x / rhs.x, y / rhs.y); }

		inline Vector2<T> operator+(const T rhs) { return Vector2<T>(x + rhs, y + rhs); }
		inline Vector2<T> operator-(const T rhs) { return Vector2<T>(x - rhs, y - rhs); }
		inline Vector2<T> operator*(const T rhs) { return Vector2<T>(x * rhs, y * rhs); }
		inline Vector2<T> operator/(const T rhs) { return Vector2<T>(x / rhs, y / rhs); }

		inline Vector2<T>& operator +=(const Vector2<T> & rhs) { x += rhs.x; y += rhs.y; return *this; }
		inline Vector2<T>& operator -=(const Vector2<T> & rhs) { x -= rhs.x; y -= rhs.y; return *this; }
		inline Vector2<T>& operator *=(const Vector2<T> & rhs) { x *= rhs.x; y *= rhs.y; return *this; }
		inline Vector2<T>& operator /=(const Vector2<T> & rhs) { x /= rhs.x; y /= rhs.y; return *this; }

		inline Vector2<T>& operator +=(const T rhs) { x += rhs; y += rhs; return *this; }
		inline Vector2<T>& operator -=(const T rhs) { x -= rhs; y -= rhs; return *this; }
		inline Vector2<T>& operator *=(const T rhs) { x *= rhs; y *= rhs; return *this; }
		inline Vector2<T>& operator /=(const T rhs) { x /= rhs; y /= rhs; return *this; }

		inline T Length() { return sqrtf(x * x + y * y); }
		inline T LengthSquared() { return (x * x + y * y); }

		inline T DistanceTo(const Vector2<T>& other) { return (*this - other).Length(); }

		inline Vector2<T> Normalize() { float inverse = 1.0f / Length(); x *= inverse; y *= inverse; return *this; }
		inline Vector2<T> Normalized() { float inverse = 1.0f / Length(); return Vector2<T>(x * inverse, y * inverse); }

		inline Vector2<T> LeftNormal() { float inverse = 1.0f / Length(); return Vector2<T>(y * inverse, -x * inverse); }
		inline Vector2<T> RightNormal() { float inverse = 1.0f / Length(); return Vector2<T>(-y * inverse, x * inverse); }

		inline T Dot(const Vector2<T> & other) { return x * other.x + y * other.y; }
		inline T Cross(const Vector2<T> & other) { return x * other.y - y * other.x; }

		inline T Angle() { return atan2(y, x); }
		inline T AngleTo(const Vector2<T> other) { return (other - *this).Angle(); }

		inline Vector2<T> Sign() { x = Sgn(x); y = Sgn(y); return *this; }
		inline Vector2<T> GetSign() { return Vector2<T>(Sgn(x), Sgn(y)); }

	};

	typedef Vector2<float> Vector2F;
	typedef Vector2<int> Vector2I;
}

#endif // !HEADER_VECTOR2
