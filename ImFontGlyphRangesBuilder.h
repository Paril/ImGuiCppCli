#pragma once

#include "common.h"

using OGImFontGlyphRangesBuilder = ::ImFontGlyphRangesBuilder;

namespace ImGuiCppCli
{
	value struct ImGlyphRanges;

	public ref class ImFontGlyphRangesBuilder
	{
	private:
		OGImFontGlyphRangesBuilder* _handle;

	internal:
		void BuildRanges(::ImVector<ImWchar>* vector);

	public:
		ImFontGlyphRangesBuilder();

		~ImFontGlyphRangesBuilder();

		void Clear();

		property bool default[int]
		{
			bool get(int index);
			void set(int index, bool value);
		}

		void Add(ImWchar c);

		void Add(Char c);

		void Add(ImString^ text);

		void Add(ValueTuple<ImWchar, ImWchar> range);

		void Add(IEnumerable<ValueTuple<ImWchar, ImWchar>>^ ranges);

		void Add(ImGlyphRanges ranges);

		property array<ValueTuple<ImWchar, ImWchar>>^ Ranges
		{
			array<ValueTuple<ImWchar, ImWchar>>^ get();
		}
	};
}