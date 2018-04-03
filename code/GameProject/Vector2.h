#ifndef HEADER_VECTOR2
#define HEADER_VECTOR2

#define Sgn(x) (x < 0 ? -1 : (x > 0 ? 1 : 0))

#include <math.h>
#include <SFML\System\Vector2.hpp>
#include <iostream>

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

		//static Vector2<T> FromPolar(float aAngle, float aRadius = 1) const { return Vector2<T>(cos(aAngle) * aRadius, sin(aAngle) * aRadius); }

		static Vector2<T> ZERO;
		static Vector2<T> UNITX;
		static Vector2<T> UNITY;
		static Vector2<T> ONE;

		~Vector2() {};

		void Print() const { std::cout << "V = [ " << myX << ", " << myY << " ]" << std::endl; }

		Vector2<T> Set(T xValue, T yValue) { x = xValue; y = yValue; return *this; }

		inline Vector2<T> operator-() const { return Vector2<T>(-x, -y); }

		inline Vector2<T> operator+(const Vector2<T> & rhs) const { return Vector2<T>(x + rhs.x, y + rhs.y); }
		inline Vector2<T> operator-(const Vector2<T> & rhs) const { return Vector2<T>(x - rhs.x, y - rhs.y); }
		inline Vector2<T> operator*(const Vector2<T> & rhs) const { return Vector2<T>(x * rhs.x, y * rhs.y); }
		inline Vector2<T> operator/(const Vector2<T> & rhs) const { return Vector2<T>(x / rhs.x, y / rhs.y); }

		inline Vector2<T> operator+(const T rhs) const { return Vector2<T>(x + rhs, y + rhs); }
		inline Vector2<T> operator-(const T rhs) const { return Vector2<T>(x - rhs, y - rhs); }
		inline Vector2<T> operator*(const T rhs) const { return Vector2<T>(x * rhs, y * rhs); }
		inline Vector2<T> operator/(const T rhs) const { return Vector2<T>(x / rhs, y / rhs); }

		inline Vector2<T>& operator +=(const Vector2<T> & rhs) { x += rhs.x; y += rhs.y; return *this; }
		inline Vector2<T>& operator -=(const Vector2<T> & rhs) { x -= rhs.x; y -= rhs.y; return *this; }
		inline Vector2<T>& operator *=(const Vector2<T> & rhs) { x *= rhs.x; y *= rhs.y; return *this; }
		inline Vector2<T>& operator /=(const Vector2<T> & rhs) { x /= rhs.x; y /= rhs.y; return *this; }

		inline Vector2<T>& operator +=(const T rhs) { x += rhs; y += rhs; return *this; }
		inline Vector2<T>& operator -=(const T rhs) { x -= rhs; y -= rhs; return *this; }
		inline Vector2<T>& operator *=(const T rhs) { x *= rhs; y *= rhs; return *this; }
		inline Vector2<T>& operator /=(const T rhs) { x /= rhs; y /= rhs; return *this; }

		inline T Length() const { return sqrtf(x * x + y * y); }
		inline T LengthSquared() const { return (x * x + y * y); }

		inline T DistanceTo(const Vector2<T>& other) const { return (*this - other).Length(); }

		inline Vector2<T> Normalize() 
		{
			float inverse = 1.0f / Length(); 
			x *= inverse; y *= inverse; 
			return *this; 
		}

		inline Vector2<T> Normalized() const { float inverse = 1.0f / Length(); return Vector2<T>(x * inverse, y * inverse); }

		inline Vector2<T> LeftNormal() const { float inverse = 1.0f / Length(); return Vector2<T>(y * inverse, -x * inverse); }
		inline Vector2<T> RightNormal() const { float inverse = 1.0f / Length(); return Vector2<T>(-y * inverse, x * inverse); }

		inline T Dot(const Vector2<T> & other) const { return x * other.x + y * other.y; }
		inline T Cross(const Vector2<T> & other) const { return x * other.y - y * other.x; }

		inline T Angle() const { return atan2(y, x); }
		inline T AngleTo(const Vector2<T> other) const { return (other - *this).Angle(); }

		inline void Rotate(float aAngle)
		{
			float c = cosf(aAngle);
			float s = sinf(aAngle);
			T xTemp = x;
			x = x * c - y * s;
			y = y * c + xTemp * s;
		}

		inline void RotateAround(float aAngle, const Vector2<T> &aAnchor)
		{
			x -= aAnchor.x;
			y -= aAnchor.y;
			Rotate(aAngle);
			x += aAnchor.x;
			y += aAnchor.y;
		}

		inline Vector2<T> Sign() { x = Sgn(x); y = Sgn(y); return *this; }
		inline Vector2<T> GetSign() const { return Vector2<T>(Sgn(x), Sgn(y)); }

	};

	template<typename T>
	Vector2<T> Vector2<T>::ZERO = { 0, 0 };
	
	template<typename T>
	Vector2<T> Vector2<T>::UNITX = { static_cast<T>(1), 0 };
	
	template<typename T>
	Vector2<T> Vector2<T>::UNITY = { 0, static_cast<T>(1) };
	
	template<typename T>
	Vector2<T> Vector2<T>::ONE = { static_cast<T>(1) };

	typedef Vector2<float> Vector2F;
	typedef Vector2<int> Vector2I;
}

#endif // !HEADER_VECTOR2
