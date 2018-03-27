#ifndef HEADER_BUFFER_INTERFACE
#define HEADER_BUFFER_INTERFACE

template<typename T, typename I = unsigned int>
class IStorage
{
	virtual I GetLength() = 0;
	virtual T* GetData() = 0;
};

#endif // !HEADER_BUFFER_INTERFACE
