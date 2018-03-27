#ifndef HEADER_MATH_MATRIX
#define HEADER_MATH_MATRIX

#include <stdlib.h>

#ifndef uint
#define uint unsigned int
#endif // !uint

//Rows x Coloms
template<class Type, uint rows, uint coloms>
struct Matrix
{

private:
	
	Type m_data[rows * coloms];

public:

	static Matrix<Type, rows, coloms> Identity();

	Matrix();
	Matrix(float* data);

	//operator Type*(); { return m_data; }
	//operator const Type*() const { return m_data; }
	Type& operator()(uint row, uint colom); // { return m_data[coloms * row + colom]; }
	const Type& operator()(uint row, uint colom) const; // const { return m_data[coloms * row + colom]; }
};

template<class Type, uint leftRows, uint LeftColomsAndRightRows, uint rightColoms>
Matrix<Type, leftRows, rightColoms> operator * (
	const Matrix<Type, leftRows, LeftColomsAndRightRows>	&	left,
	const Matrix<Type, LeftColomsAndRightRows, rightColoms>&	right);

typedef Matrix<float, 4, 4> Matrix4x4f;
typedef Matrix<float, 3, 3> Matrix3x3f;


#ifdef MAIN_FILE
#include "_Matrix.h"
#endif // MAIN_FILE




#endif // !HEADER_MATH_MATRIX
