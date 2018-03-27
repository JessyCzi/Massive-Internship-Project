#ifndef _COMPILE_VECTOR_DONE
#ifdef _COMPILE_VECTOR_BEGIN

#include <cmath>
#include <stdlib.h>

#ifdef _COMPILE_VECTOR_TWO
#define _COMPILE_VECTOR_NAME Vector2
#endif

#ifdef _COMPILE_VECTOR_THREE
#define _COMPILE_VECTOR_NAME Vector3
#define _INCLUDE_IN_VECTOR_COMPILATION_Z
#endif

#ifdef _COMPILE_VECTOR_FOUR
#define _COMPILE_VECTOR_NAME Vector4
#define _INCLUDE_IN_VECTOR_COMPILATION_Z
#define _INCLUDE_IN_VECTOR_COMPILATION_W
#endif

#ifdef _COMPILE_VECTOR_NAME



template<typename ValueType>
struct _COMPILE_VECTOR_NAME
{
	ValueType x;
	ValueType y;

#ifdef _INCLUDE_IN_VECTOR_COMPILATION_Z
	ValueType z;
#endif

#ifdef _INCLUDE_IN_VECTOR_COMPILATION_W
	ValueType w;
#endif 

	_COMPILE_VECTOR_NAME();
	explicit _COMPILE_VECTOR_NAME(ValueType value);
	explicit _COMPILE_VECTOR_NAME(const _COMPILE_VECTOR_NAME<ValueType> & value);
	
	_COMPILE_VECTOR_NAME(
		ValueType xValue,
		ValueType yValue
#ifdef _INCLUDE_IN_VECTOR_COMPILATION_Z
		,
		ValueType zValue
#endif
#ifdef _INCLUDE_IN_VECTOR_COMPILATION_W
		,
		ValueType wValue
#endif
	);

	_COMPILE_VECTOR_NAME(const ValueType* values) {
		memcpy(this, values,
#ifdef _COMPILE_VECTOR_TWO
			2
#endif
#ifdef _COMPLIE_VECTOR_THREE
			3
#endif
#ifdef _COMPILE_VECTOR_FOUR
			4
#endif
			* sizeof(ValueType)
			);	
	}


	inline ValueType Length();

	inline ValueType Dot(const _COMPILE_VECTOR_NAME<ValueType> & v);


#ifdef _COMPILE_VECTOR_THREE
	inline ValueType Cross(const _COMPILE_VECTOR_NAME<ValueType> & v);
#endif

#ifdef _COMPILE_VECTOR_TWO
	inline _COMPILE_VECTOR_NAME<ValueType> & Rotate(const float angle );
	inline _COMPILE_VECTOR_NAME<ValueType> Rotated(const float angle);
	inline _COMPILE_VECTOR_NAME<ValueType> & Rotate(const _COMPILE_VECTOR_NAME<ValueType> & origin, const float angle);
	inline _COMPILE_VECTOR_NAME<ValueType> Rotated(const _COMPILE_VECTOR_NAME<ValueType> & origin, const float angle);
#endif // !_COMPILE_VECTOR_TWO

	inline _COMPILE_VECTOR_NAME<ValueType> & Normalize() { return *this /= Length(); }
	inline _COMPILE_VECTOR_NAME<ValueType> Normalized() { return *this / Length(); }


	inline _COMPILE_VECTOR_NAME<ValueType> operator+(const _COMPILE_VECTOR_NAME<ValueType> & rhs) const;
	inline _COMPILE_VECTOR_NAME<ValueType> operator-(const _COMPILE_VECTOR_NAME<ValueType> & rhs) const;
	inline _COMPILE_VECTOR_NAME<ValueType> operator*(const _COMPILE_VECTOR_NAME<ValueType> & rhs) const;
	inline _COMPILE_VECTOR_NAME<ValueType> operator/(const _COMPILE_VECTOR_NAME<ValueType> & rhs) const;

	inline _COMPILE_VECTOR_NAME<ValueType> operator+(const ValueType & rhs) const;
	inline _COMPILE_VECTOR_NAME<ValueType> operator-(const ValueType & rhs) const;
	inline _COMPILE_VECTOR_NAME<ValueType> operator*(const ValueType & rhs) const;
	inline _COMPILE_VECTOR_NAME<ValueType> operator/(const ValueType & rhs) const;

	inline _COMPILE_VECTOR_NAME<ValueType> & operator +=(const _COMPILE_VECTOR_NAME<ValueType> & rhs);
	inline _COMPILE_VECTOR_NAME<ValueType> & operator -=(const _COMPILE_VECTOR_NAME<ValueType> & rhs);
	inline _COMPILE_VECTOR_NAME<ValueType> & operator *=(const _COMPILE_VECTOR_NAME<ValueType> & rhs);
	inline _COMPILE_VECTOR_NAME<ValueType> & operator /=(const _COMPILE_VECTOR_NAME<ValueType> & rhs);

	inline _COMPILE_VECTOR_NAME<ValueType> & operator +=(const ValueType & rhs);
	inline _COMPILE_VECTOR_NAME<ValueType> & operator -=(const ValueType & rhs);
	inline _COMPILE_VECTOR_NAME<ValueType> & operator *=(const ValueType & rhs);
	inline _COMPILE_VECTOR_NAME<ValueType> & operator /=(const ValueType & rhs);


	operator ValueType*() { return (ValueType*)this; }
	operator const ValueType*() const { return (ValueType*)this; }

};

template<typename ValueType>
inline _COMPILE_VECTOR_NAME<ValueType> operator+ (ValueType left, _COMPILE_VECTOR_NAME<ValueType> right) { right + left}

template<typename ValueType>
inline _COMPILE_VECTOR_NAME<ValueType> operator- (ValueType left, _COMPILE_VECTOR_NAME<ValueType> right) { right - left }

template<typename ValueType>
inline _COMPILE_VECTOR_NAME<ValueType> operator* (ValueType left, _COMPILE_VECTOR_NAME<ValueType> right) { right * left }

template<typename ValueType>
inline _COMPILE_VECTOR_NAME<ValueType> operator/ (ValueType left, _COMPILE_VECTOR_NAME<ValueType> right) { right / left }

template<typename ValueType>
inline _COMPILE_VECTOR_NAME<ValueType>::_COMPILE_VECTOR_NAME()
	: x(0)
	, y(0)

#ifdef _INCLUDE_IN_VECTOR_COMPILATION_Z
	, z(0)
#endif

#ifdef _INCLUDE_IN_VECTOR_COMPILATION_W
	, w(0)
#endif

{}

template<typename ValueType>
inline _COMPILE_VECTOR_NAME<ValueType>::_COMPILE_VECTOR_NAME(ValueType value)
	: x(value)
	, y(value)
#ifdef _INCLUDE_IN_VECTOR_COMPILATION_Z
	, z(value)
#endif

#ifdef _INCLUDE_IN_VECTOR_COMPILATION_W
	, w(value)
#endif

{}

template<typename ValueType>
inline _COMPILE_VECTOR_NAME<ValueType>::_COMPILE_VECTOR_NAME(
#pragma region Prameters
	ValueType xValue,	ValueType yValue
#ifdef _INCLUDE_IN_VECTOR_COMPILATION_Z
	, ValueType zValue
#endif
#ifdef _INCLUDE_IN_VECTOR_COMPILATION_W
	, ValueType wValue
#endif
#pragma endregion
)
	: x(xValue)
	, y(yValue)
#ifdef _INCLUDE_IN_VECTOR_COMPILATION_Z
	, z(zValue)
#endif

#ifdef _INCLUDE_IN_VECTOR_COMPILATION_W
	, w(wValue)
#endif

{}


template<typename ValueType>
inline ValueType _COMPILE_VECTOR_NAME<ValueType>::Length()
{
	return sqrt(
		x * x + y * y
#ifdef _INCLUDE_IN_VECTOR_COMPILATION_Z
		+ z * z 
#endif
#ifdef _INCLUDE_IN_VECTOR_COMPILATION_W
		+ w * w
#endif
	);
}

template<typename ValueType>
inline ValueType _COMPILE_VECTOR_NAME<ValueType>::Dot(const _COMPILE_VECTOR_NAME<ValueType>& v)
{
	return x * v.x + y * v.y
#ifdef _INCLUDE_IN_VECTOR_COMPILATION_Z
		+ z * v.z
#endif
#ifdef _INCLUDE_IN_VECTOR_COMPILATION_W
		+ w * v.w
#endif
		;
}

#ifdef _COMPILE_VECTOR_TWO

template<typename ValueType>
inline _COMPILE_VECTOR_NAME<ValueType> & _COMPILE_VECTOR_NAME<ValueType>::Rotate(const float angle)
{
	ValueType prevX = x;
	ValueType prevY = y;

	float cos = cos(angle);
	float sin = sin(angle);

	x = prevX * cos - prevY * sin;
	y = prevY * cos + prevX * sin;

	return *this;
}

template<typename ValueType>
inline _COMPILE_VECTOR_NAME<ValueType> _COMPILE_VECTOR_NAME<ValueType>::Rotated(const float angle)
{

	float cos = cos(angle);
	float sin = sin(angle);
	return _COMPILE_VECTOR_NAME<ValueType>(
		x * cos - y * sin,
		y * cos + x * sin);
}

template<typename ValueType>
inline _COMPILE_VECTOR_NAME<ValueType>& _COMPILE_VECTOR_NAME<ValueType>::Rotate(const _COMPILE_VECTOR_NAME<ValueType>& origin, const float angle)
{

	float cos = cos(angle);
	float sin = sin(angle);

	x -= origin.x;
	y -= origin.y;
	
	float newX = x * cos - y * sin + origin.x;
	y = y * cos + x * sin + origin.y;
	x = newX;

	return *this;
}

template<typename ValueType>
inline _COMPILE_VECTOR_NAME<ValueType> _COMPILE_VECTOR_NAME<ValueType>::Rotated(const _COMPILE_VECTOR_NAME<ValueType>& origon, const float angle)
{
	float cos = cos(angle);
	float sin = sin(angle);


	_COMPILE_VECTOR_NAME<ValueType> temp = *this - origin;

	return  _COMPILE_VECTOR_NAME<ValueType>(
		temp.x * cos - temp.y * sin + origin.x,
		temp.y * cos + temp.x * sin + origin.y);
}

#endif // _COMPILE_VECTOR_TWO

#ifdef _COMPILE_VECTOR_THREE
template<typename ValueType>
inline ValueType _COMPILE_VECTOR_NAME<ValueType>::Cross(const _COMPILE_VECTOR_NAME<ValueType>& v)
{
	return _COMPILE_VECTOR_NAME<ValueType>(
		y * v.z - z * v.y,
		z * v.x - x * v.z,
		x * v.y - y * v.x
	);
}
#endif // !_COMPLIE_VECTOR_THREE


template<typename ValueType>
inline _COMPILE_VECTOR_NAME<ValueType>::_COMPILE_VECTOR_NAME(const _COMPILE_VECTOR_NAME<ValueType>& value)
	: x(value.x)
	, y(value.y)
#ifdef _INCLUDE_IN_VECTOR_COMPILATION_Z
	, z(value.z)
#endif

#ifdef _INCLUDE_IN_VECTOR_COMPILATION_W
	, w(value.w)
#endif

{}

template<typename ValueType>
inline _COMPILE_VECTOR_NAME<ValueType> _COMPILE_VECTOR_NAME<ValueType>::operator+(const _COMPILE_VECTOR_NAME<ValueType>& rhs) const
{
	return _COMPILE_VECTOR_NAME<ValueType>(
		x + rhs.x,
		y + rhs.y
#ifdef _INCLUDE_IN_VECTOR_COMPILATION_Z
		,
		z + rhs.z
#endif // _INCLUDE_IN_VECTOR_COMPILATION_Z
#ifdef _INCLUDE_IN_VECTOR_COMPILATION_W
		,
		w + rhs.w
#endif // _INCLUDE_IN_VECTOR_COMPILATION_W
		);
}

template<typename ValueType>
inline _COMPILE_VECTOR_NAME<ValueType> _COMPILE_VECTOR_NAME<ValueType>::operator-(const _COMPILE_VECTOR_NAME<ValueType>& rhs) const
{
	return _COMPILE_VECTOR_NAME<ValueType>(
		x - rhs.x,
		y - rhs.y
#ifdef _INCLUDE_IN_VECTOR_COMPILATION_Z
		,
		z - rhs.z
#endif // _INCLUDE_IN_VECTOR_COMPILATION_Z
#ifdef _INCLUDE_IN_VECTOR_COMPILATION_W
		,
		w - rhs.w
#endif // _INCLUDE_IN_VECTOR_COMPILATION_W
		);
}

template<typename ValueType>
inline _COMPILE_VECTOR_NAME<ValueType> _COMPILE_VECTOR_NAME<ValueType>::operator*(const _COMPILE_VECTOR_NAME<ValueType>& rhs) const
{
	return _COMPILE_VECTOR_NAME<ValueType>(
		x * rhs.x,
		y * rhs.y
#ifdef _INCLUDE_IN_VECTOR_COMPILATION_Z
		,
		z * rhs.z
#endif // _INCLUDE_IN_VECTOR_COMPILATION_Z
#ifdef _INCLUDE_IN_VECTOR_COMPILATION_W
		,
		w * rhs.w
#endif // _INCLUDE_IN_VECTOR_COMPILATION_W
		);
}

template<typename ValueType>
inline _COMPILE_VECTOR_NAME<ValueType> _COMPILE_VECTOR_NAME<ValueType>::operator/(const _COMPILE_VECTOR_NAME<ValueType>& rhs) const
{
	return _COMPILE_VECTOR_NAME<ValueType>(
		x / rhs.x,
		y / rhs.y
#ifdef _INCLUDE_IN_VECTOR_COMPILATION_Z
		,
		z / rhs.z
#endif // _INCLUDE_IN_VECTOR_COMPILATION_Z
#ifdef _INCLUDE_IN_VECTOR_COMPILATION_W
		,
		w / rhs.w
#endif // _INCLUDE_IN_VECTOR_COMPILATION_W
		);
}


template<typename ValueType>
inline _COMPILE_VECTOR_NAME<ValueType> _COMPILE_VECTOR_NAME<ValueType>::operator+(const ValueType & rhs) const
{
	return _COMPILE_VECTOR_NAME<ValueType>(
		x + rhs,
		y + rhs
#ifdef _INCLUDE_IN_VECTOR_COMPILATION_Z
		,
		z + rhs
#endif // _INCLUDE_IN_VECTOR_COMPILATION_Z
#ifdef _INCLUDE_IN_VECTOR_COMPILATION_W
		,
		w + rhs
#endif // _INCLUDE_IN_VECTOR_COMPILATION_W
		);
}

template<typename ValueType>
inline _COMPILE_VECTOR_NAME<ValueType> _COMPILE_VECTOR_NAME<ValueType>::operator-(const ValueType & rhs) const
{
	return _COMPILE_VECTOR_NAME<ValueType>(
		x - rhs,
		y - rhs
#ifdef _INCLUDE_IN_VECTOR_COMPILATION_Z
		,
		z - rhs
#endif // _INCLUDE_IN_VECTOR_COMPILATION_Z
#ifdef _INCLUDE_IN_VECTOR_COMPILATION_W
		,
		w - rhs
#endif // _INCLUDE_IN_VECTOR_COMPILATION_W
		);
}

template<typename ValueType>
inline _COMPILE_VECTOR_NAME<ValueType> _COMPILE_VECTOR_NAME<ValueType>::operator*(const ValueType & rhs) const
{
	return _COMPILE_VECTOR_NAME<ValueType>(
		x * rhs,
		y * rhs
#ifdef _INCLUDE_IN_VECTOR_COMPILATION_Z
		,
		z * rhs
#endif // _INCLUDE_IN_VECTOR_COMPILATION_Z
#ifdef _INCLUDE_IN_VECTOR_COMPILATION_W
		,
		w * rhs
#endif // _INCLUDE_IN_VECTOR_COMPILATION_W
		);
}

template<typename ValueType>
inline _COMPILE_VECTOR_NAME<ValueType> _COMPILE_VECTOR_NAME<ValueType>::operator/(const ValueType & rhs) const
{
	return _COMPILE_VECTOR_NAME<ValueType>(
		x / rhs,
		y / rhs
#ifdef _INCLUDE_IN_VECTOR_COMPILATION_Z
		,
		z / rhs
#endif // _INCLUDE_IN_VECTOR_COMPILATION_Z
#ifdef _INCLUDE_IN_VECTOR_COMPILATION_W
		,
		w / rhs
#endif // _INCLUDE_IN_VECTOR_COMPILATION_W
		);
}


template<typename ValueType>
inline _COMPILE_VECTOR_NAME<ValueType> & _COMPILE_VECTOR_NAME<ValueType>::operator+=(const _COMPILE_VECTOR_NAME<ValueType>& rhs)
{
	x += rhs.x;
	y += rhs.y;
#ifdef _INCLUDE_IN_VECTOR_COMPILATION_Z
	z += rhs.z;
#endif // _INCLUDE_IN_VECTOR_COMPILATION_Z
#ifdef _INCLUDE_IN_VECTOR_COMPILATION_W
	w += rhs.w;
#endif // _INCLUDE_IN_VECTOR_COMPILATION_W

	return *this;
}

template<typename ValueType>
inline _COMPILE_VECTOR_NAME<ValueType> & _COMPILE_VECTOR_NAME<ValueType>::operator-=(const _COMPILE_VECTOR_NAME<ValueType>& rhs)
{
	x -= rhs.x;
	y -= rhs.y;
#ifdef _INCLUDE_IN_VECTOR_COMPILATION_Z
	z -= rhs.z;
#endif // _INCLUDE_IN_VECTOR_COMPILATION_Z
#ifdef _INCLUDE_IN_VECTOR_COMPILATION_W
	w -= rhs.w;
#endif // _INCLUDE_IN_VECTOR_COMPILATION_W

	return *this;
}

template<typename ValueType>
inline _COMPILE_VECTOR_NAME<ValueType> & _COMPILE_VECTOR_NAME<ValueType>::operator*=(const _COMPILE_VECTOR_NAME<ValueType>& rhs)
{
	x *= rhs.x;
	y *= rhs.y;
#ifdef _INCLUDE_IN_VECTOR_COMPILATION_Z
	z *= rhs.z;
#endif // _INCLUDE_IN_VECTOR_COMPILATION_Z
#ifdef _INCLUDE_IN_VECTOR_COMPILATION_W
	w *= rhs.w;
#endif // _INCLUDE_IN_VECTOR_COMPILATION_W

	return *this;
}

template<typename ValueType>
inline _COMPILE_VECTOR_NAME<ValueType> & _COMPILE_VECTOR_NAME<ValueType>::operator/=(const _COMPILE_VECTOR_NAME<ValueType>& rhs)
{
	x /= rhs.x;
	y /= rhs.y;
#ifdef _INCLUDE_IN_VECTOR_COMPILATION_Z
	z /= rhs.z;
#endif // _INCLUDE_IN_VECTOR_COMPILATION_Z
#ifdef _INCLUDE_IN_VECTOR_COMPILATION_W
	w /= rhs.w;
#endif // _INCLUDE_IN_VECTOR_COMPILATION_W

	return *this;
}


template<typename ValueType>
inline _COMPILE_VECTOR_NAME<ValueType> & _COMPILE_VECTOR_NAME<ValueType>::operator+=(const ValueType & rhs)
{
	x += rhs;
	y += rhs;
#ifdef _INCLUDE_IN_VECTOR_COMPILATION_Z
	z += rhs;
#endif // _INCLUDE_IN_VECTOR_COMPILATION_Z
#ifdef _INCLUDE_IN_VECTOR_COMPILATION_W
	w += rhs;
#endif // _INCLUDE_IN_VECTOR_COMPILATION_W

	return *this;
}

template<typename ValueType>
inline _COMPILE_VECTOR_NAME<ValueType> & _COMPILE_VECTOR_NAME<ValueType>::operator-=(const ValueType & rhs)
{
	x -= rhs;
	y -= rhs;
#ifdef _INCLUDE_IN_VECTOR_COMPILATION_Z
	z -= rhs;
#endif // _INCLUDE_IN_VECTOR_COMPILATION_Z
#ifdef _INCLUDE_IN_VECTOR_COMPILATION_W
	w -= rhs;
#endif // _INCLUDE_IN_VECTOR_COMPILATION_W

	return *this;
}

template<typename ValueType>
inline _COMPILE_VECTOR_NAME<ValueType> & _COMPILE_VECTOR_NAME<ValueType>::operator*=(const ValueType & rhs)
{
	x *= rhs;
	y *= rhs;
#ifdef _INCLUDE_IN_VECTOR_COMPILATION_Z
	z *= rhs;
#endif // _INCLUDE_IN_VECTOR_COMPILATION_Z
#ifdef _INCLUDE_IN_VECTOR_COMPILATION_W
	w *= rhs;
#endif // _INCLUDE_IN_VECTOR_COMPILATION_W

	return *this;
}

template<typename ValueType>
inline _COMPILE_VECTOR_NAME<ValueType> & _COMPILE_VECTOR_NAME<ValueType>::operator/=(const ValueType & rhs)
{
	x /= rhs;
	y /= rhs;
#ifdef _INCLUDE_IN_VECTOR_COMPILATION_Z
	z /= rhs;
#endif // _INCLUDE_IN_VECTOR_COMPILATION_Z
#ifdef _INCLUDE_IN_VECTOR_COMPILATION_W
	w /= rhs;
#endif // _INCLUDE_IN_VECTOR_COMPILATION_W

	return *this;
}


#ifdef _INCLUDE_IN_VECTOR_COMPILATION_Z
#undef _INCLUDE_IN_VECTOR_COMPILATION_Z
#endif // _INCLUDE_IN_VECTOR_COMPILATION_Z

#ifdef _INCLUDE_IN_VECTOR_COMPILATION_W
#undef _INCLUDE_IN_VECTOR_COMPILATION_W
#endif // _INCLUDE_IN_VECTOR_COMPILATION_W

#undef _COMPILE_VECTOR_NAME
#endif // _COMPILE_VECTOR_NAME

#endif // !_COMPILE_VECTOR_BEGIN
#endif // !_COMPILE_VECTOR_DONE
