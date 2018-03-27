#ifndef HEADER_MATH_SRC_MATRIX
#define HEADER_MATH_SRC_MATRIX
#include "Matrix.h"

template<class Type, uint leftRows, uint LeftColomsAndRightRows, uint rightColoms>
Matrix<Type, leftRows, rightColoms> operator * (
	const Matrix<Type, leftRows, LeftColomsAndRightRows>	&	left,
	const Matrix<Type, LeftColomsAndRightRows, rightColoms>&	right)
{

	Matrix<Type, leftRows, rightColoms> resault = Matrix<Type, leftRows, rightColoms>();
	//memset(&resault, 0, sizeof(Type) * leftRows * rightColoms); // zero out the memory // DONT KNOW IF NEEDED

	for (int row = 0; row < leftRows; row++)
	{
		for (int colom = 0; colom < rightColoms; colom++)
		{
			for (int count = 0; count < LeftColomsAndRightRows; count++)
			{
				resault(row, colom) += left(row, count) * right(count, colom);
			}
		}
	}
	return resault;
}



template<class Type, uint rows, uint coloms>
inline Matrix<Type, rows, coloms> Matrix<Type, rows, coloms>::Identity()
{
	Matrix<Type, rows, coloms> base;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < coloms; j++)
		{
			if (i == j)
			{
				base(i, j) = 1.0f;
			}
		}
	}

	return base;
}

template<class Type, uint rows, uint coloms>
inline Matrix<Type, rows, coloms>::Matrix()
{
	memset(m_data, 0, rows * coloms * sizeof(Type));
}

template<class Type, uint rows, uint coloms>
inline Matrix<Type, rows, coloms>::Matrix(float * data)
{
	memcpy(m_data, data, rows * coloms * sizeof(Type));
}

template<class Type, uint rows, uint coloms>
inline const Type & Matrix<Type, rows, coloms>::operator()(uint row, uint colom) const
{
	return m_data[coloms * row + colom];
}

template<class Type, uint rows, uint coloms>
inline Type & Matrix<Type, rows, coloms>::operator()(uint row, uint colom)
{
	return m_data[coloms * row + colom];
}




#endif // !HEADER_MATH_SRC_MATRIX