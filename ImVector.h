#pragma once

#include "common.h"

using OGImVector = ::ImVector<uint8_t>;

namespace ImGuiCppCli
{
	generic<typename T> public value struct ImVectorRef sealed
	{
	private:
		const OGImVector* _vector;
		int _elementSize;

	internal:
		ImVectorRef(const OGImVector* vector);

	public:
		property Span<T> Memory
		{
			Span<T> get();
		}

		property int Count
		{
			int get();
		}

		property T% default[int]
		{
			T% get(int index);
		}

		Span<T> Slice(int start);
		Span<T> Slice(int start, int length);

	public:
		Span<T>::Enumerator GetEnumerator();
	};
}