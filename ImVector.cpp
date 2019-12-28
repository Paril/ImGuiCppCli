#include "ImVector.h"
#include "ImVec2.h"

namespace ImGuiCppCli
{
	generic<typename T>
	ImVectorRef<T>::ImVectorRef(const OGImVector* vector) :
		_vector(vector),
		_elementSize(sizeof(T))
	{
	}

	generic<typename T>
	Span<T> ImVectorRef<T>::Memory::get() { return Span<T>(_vector->Data, _vector->Size); }

	generic<typename T>
	int ImVectorRef<T>::Count::get() { return _vector->Size; }

	generic<typename T>
	T% ImVectorRef<T>::default::get(int index)
	{
		return Span<T>(_vector->Data + (_elementSize * index), 1)[0];
	}

	generic<typename T>
	Span<T> ImVectorRef<T>::Slice(int start)
	{
		return Memory.Slice(start);
	}

	generic<typename T>
	Span<T> ImVectorRef<T>::Slice(int start, int length)
	{
		return Memory.Slice(start, length);
	}

	generic<typename T>
	Span<T>::Enumerator ImVectorRef<T>::GetEnumerator()
	{
		return Memory.GetEnumerator();
	}
}