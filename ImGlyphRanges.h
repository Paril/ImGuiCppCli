#pragma once

#include "common.h"

namespace ImGuiCppCli
{
	public value struct ImGlyphRanges
	{
	internal:
		const ImWchar* _ranges;
		int _numRanges;

		ImGlyphRanges(const ImWchar* ranges);

	public:
		property int Count { int get(); }

		ValueTuple<ImWchar, ImWchar> GetRange(int index);
	};
}