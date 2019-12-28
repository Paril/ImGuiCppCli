#include "ImFontGlyphRangesBuilder.h"
#include "ImGlyphRanges.h"

namespace ImGuiCppCli
{
	ImFontGlyphRangesBuilder::ImFontGlyphRangesBuilder()
	{
		_handle = new OGImFontGlyphRangesBuilder();
	}

	ImFontGlyphRangesBuilder::~ImFontGlyphRangesBuilder()
	{
		delete _handle;
	}

	void ImFontGlyphRangesBuilder::Clear()
	{
		_handle->Clear();
	}

	bool ImFontGlyphRangesBuilder::default::get(int index)
	{
		return _handle->GetBit(index);
	}

	void ImFontGlyphRangesBuilder::default::set(int index, bool value)
	{
		if (!value)
			throw gcnew InvalidOperationException();

		_handle->SetBit(index);
	}

	void ImFontGlyphRangesBuilder::Add(ImWchar c)
	{
		_handle->AddChar(c);
	}

	void ImFontGlyphRangesBuilder::Add(Char c)
	{
		_handle->AddChar(c);
	}

	void ImFontGlyphRangesBuilder::Add(ImString^ text)
	{
		IMSTR_DECODE_TEMP(text);
		_handle->AddText(text_cstr);
	}

	void ImFontGlyphRangesBuilder::Add(ValueTuple<ImWchar, ImWchar> range)
	{
		const ImWchar ranges[] = { range.Item1, range.Item2, 0 };
		_handle->AddRanges(ranges);
	}

	void ImFontGlyphRangesBuilder::Add(IEnumerable<ValueTuple<ImWchar, ImWchar>>^ ranges)
	{
		for each (auto x in ranges)
			Add(x);
	}

	void ImFontGlyphRangesBuilder::Add(ImGlyphRanges ranges)
	{
		_handle->AddRanges(ranges._ranges);
	}

	void ImFontGlyphRangesBuilder::BuildRanges(::ImVector<ImWchar>* vector)
	{
		_handle->BuildRanges(vector);
	}

	array<ValueTuple<ImWchar, ImWchar>>^ ImFontGlyphRangesBuilder::Ranges::get()
	{
		static ::ImVector<ImWchar> out_ranges;
		_handle->BuildRanges(&out_ranges);

		auto out_array = gcnew array<ValueTuple<ImWchar, ImWchar>>((out_ranges.Size - 1) / 2);

		for (int i = 0, r = 0; r < out_ranges.Size - 1; i++, r += 2)
			out_array[i] = ValueTuple::Create(out_ranges[r], out_ranges[r + 1]);

		return out_array;
	}
}