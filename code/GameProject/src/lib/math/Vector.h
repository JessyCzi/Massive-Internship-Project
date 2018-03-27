#ifndef HEADER_VECTOR_TWO_TREE_FOUR
#define HEADER_VECTOR_TWO_TREE_FOUR

#define _COMPILE_VECTOR_BEGIN

#define _COMPILE_VECTOR_TWO
#include "_VectorSrc.h"
#undef _COMPILE_VECTOR_TWO

#define _COMPILE_VECTOR_THREE
#include "_VectorSrc.h"
#undef _COMPILE_VECTOR_THREE

#define _COMPILE_VECTOR_FOUR
#include "_VectorSrc.h"
#undef _COMPILE_VECTOR_FOUR

#define _COMPILE_VECTOR_DONE

#undef _COMPILE_VECTOR_TWO
#undef _COMPILE_VECTOR_THREE
#undef _COMPILE_VECTOR_FOUR
#undef _COMPILE_VECTOR_NAME
#undef _INCLUDE_IN_VECTOR_COMPILATION_Z
#undef _INCLUDE_IN_VECTOR_COMPILATION_W

typedef Vector2<float> Vector2f;
typedef Vector2<double> Vector2d;
typedef Vector2<int> Vector2i;

typedef Vector3<float> Vector3f;
typedef Vector3<double> Vector3d;
typedef Vector3<int> Vector3i;

typedef Vector4<float> Vector4f;
typedef Vector4<double> Vector4d;
typedef Vector4<int> Vector4i;

#endif // !HEADER_VECTOR_TWO_TREE_FOUR