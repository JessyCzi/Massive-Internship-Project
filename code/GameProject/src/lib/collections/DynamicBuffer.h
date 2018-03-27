#ifndef HEADER_DYNAMIC_BUFFER
#define HEADER_DYNAMIC_BUFFER

#include "IStorage.h"

template<typename T, typename I = unsigned int>
class DynamicBuffer : public IStorage<T,I>
{
	I m_length;
	I m_count;
	T* m_storage;
public:
	DynamicBuffer(I length);

	I GetLength() override;
	T* GetData() override;

	void Put(T& value);
	void Put(T* values, I length);

	void Clear();
};


template<typename T, typename I>
inline DynamicBuffer<T, I>::DynamicBuffer(I length)
{
	m_storage = (T*)malloc(length * sizeof(T));
}

template<typename T, typename I>
inline I DynamicBuffer<T, I>::GetLength()
{
	return m_length();
}

template<typename T, typename I>
inline T * DynamicBuffer<T, I>::GetData()
{
	return m_storage;
}

template<typename T, typename I>
inline void DynamicBuffer<T, I>::Put(T & value)
{
	if (m_count > m_length)
		m_storage = (T*)realloc(m_length *= 2);
	
	m_storage[m_count] = value;
	m_count++;
}

template<typename T, typename I>
inline void DynamicBuffer<T, I>::Put(T * values, I length)
{
	while (m_count + length > m_length)
		m_storage = (T*)realloc(m_length *= 2);

	memmove(m_storage + m_count, values, length * sizeof(T));
	m_count++;
}

template<typename T, typename I>
inline void DynamicBuffer<T, I>::Clear()
{
	m_count = 0;
}

#endif // !HEADER_DYNAMIC_BUFFER
