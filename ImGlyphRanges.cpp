#include "ImGlyphRanges.h"

namespace ImGuiCppCli
{
	ImGlyphRanges::ImGlyphRanges(const ImWchar* ranges) :
		_numRanges(0),
		_ranges(ranges)
	{
		for (auto range = ranges; *range; range += 2)
			_numRanges++;
	}

	int ImGlyphRanges::Count::get() { return _numRanges; }

	ValueTuple<ImWchar, ImWchar> ImGlyphRanges::GetRange(int index)
	{
		auto start = index * 2;
		return ValueTuple::Create(_ranges[start], _ranges[start + 1]);
	}
}