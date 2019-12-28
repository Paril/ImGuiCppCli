#include "ImFontAtlas.h"
#include "ImFont.h"
#include "ImFontConfig.h"

namespace ImGuiCppCli
{
	ImFontAtlas::ImFontAtlas(OGImFontAtlas* handle) :
		_handle(handle)
	{
	}

	ImFont^ ImFontAtlas::AddFont(ImFontConfig^ config) { return gcnew ImFont(_handle->AddFont(config->_handle)); }
	ImFont^ ImFontAtlas::AddFontDefault(ImFontConfig^ config) { return gcnew ImFont(_handle->AddFontDefault(config->_handle)); }
	ImFont^ ImFontAtlas::AddFontDefault() { return gcnew ImFont(_handle->AddFontDefault()); }
	void ImFontAtlas::ClearInputData() { _handle->ClearInputData(); }
	void ImFontAtlas::ClearTexData() { _handle->ClearTexData(); }
	void ImFontAtlas::ClearFonts() { _handle->ClearFonts(); }
	void ImFontAtlas::Clear() { _handle->Clear(); }
	bool ImFontAtlas::Build() { return _handle->Build(); }
	void ImFontAtlas::GetTexDataAsAlpha8([Out] array<uint8_t>^% value, [Out] int% out_width, [Out] int% out_height, [Out] int% out_bytes_per_pixel)
	{
		uint8_t* out_pixels;
		OUT_VAL_INIT(out_width);
		OUT_VAL_INIT(out_height);
		OUT_VAL_INIT(out_bytes_per_pixel);
		_handle->GetTexDataAsAlpha8(&out_pixels, &out_out_width, &out_out_height, &out_out_bytes_per_pixel);
		OUT_VAL_COPY(out_width);
		OUT_VAL_COPY(out_height);
		OUT_VAL_COPY(out_bytes_per_pixel);

		value = gcnew array<uint8_t>(out_width * out_height * 4);
		Marshal::Copy((IntPtr)out_pixels, value, 0, value->Length);
	}
	void ImFontAtlas::GetTexDataAsAlpha8([Out] array<uint8_t>^% value, [Out] int% out_width, [Out] int% out_height)
	{
		uint8_t* out_pixels;
		OUT_VAL_INIT(out_width);
		OUT_VAL_INIT(out_height);
		_handle->GetTexDataAsAlpha8(&out_pixels, &out_out_width, &out_out_height);
		OUT_VAL_COPY(out_width);
		OUT_VAL_COPY(out_height);

		value = gcnew array<uint8_t>(out_width * out_height * 4);
		Marshal::Copy((IntPtr)out_pixels, value, 0, value->Length);
	}
	void ImFontAtlas::GetTexDataAsRGBA32([Out] array<uint8_t>^% value, [Out] int% out_width, [Out] int% out_height, [Out] int% out_bytes_per_pixel)
	{
		uint8_t* out_pixels;
		OUT_VAL_INIT(out_width);
		OUT_VAL_INIT(out_height);
		OUT_VAL_INIT(out_bytes_per_pixel);
		_handle->GetTexDataAsRGBA32(&out_pixels, &out_out_width, &out_out_height, &out_out_bytes_per_pixel);
		OUT_VAL_COPY(out_width);
		OUT_VAL_COPY(out_height);
		OUT_VAL_COPY(out_bytes_per_pixel);

		value = gcnew array<uint8_t>(out_width * out_height * 4);
		Marshal::Copy((IntPtr)out_pixels, value, 0, value->Length);
	}
	void ImFontAtlas::GetTexDataAsRGBA32([Out] array<uint8_t>^% value, [Out] int% out_width, [Out] int% out_height)
	{
		uint8_t* out_pixels;
		OUT_VAL_INIT(out_width);
		OUT_VAL_INIT(out_height);
		_handle->GetTexDataAsRGBA32(&out_pixels, &out_out_width, &out_out_height);
		OUT_VAL_COPY(out_width);
		OUT_VAL_COPY(out_height);

		value = gcnew array<uint8_t>(out_width * out_height * 4);
		Marshal::Copy((IntPtr)out_pixels, value, 0, value->Length);
	}
	bool ImFontAtlas::IsBuilt() { return _handle->IsBuilt(); }
	void ImFontAtlas::SetTexID(ImTextureID id) { _handle->SetTexID((void*)id); }

	ImGlyphRanges ImFontAtlas::GetGlyphRangesDefault() { return ImGlyphRanges(_handle->GetGlyphRangesDefault()); }
	ImGlyphRanges ImFontAtlas::GetGlyphRangesKorean() { return ImGlyphRanges(_handle->GetGlyphRangesKorean()); }
	ImGlyphRanges ImFontAtlas::GetGlyphRangesJapanese() { return ImGlyphRanges(_handle->GetGlyphRangesJapanese()); }
	ImGlyphRanges ImFontAtlas::GetGlyphRangesChineseFull() { return ImGlyphRanges(_handle->GetGlyphRangesChineseFull()); }
	ImGlyphRanges ImFontAtlas::GetGlyphRangesChineseSimplifiedCommon() { return ImGlyphRanges(_handle->GetGlyphRangesChineseSimplifiedCommon()); }
	ImGlyphRanges ImFontAtlas::GetGlyphRangesCyrillic() { return ImGlyphRanges(_handle->GetGlyphRangesCyrillic()); }
	ImGlyphRanges ImFontAtlas::GetGlyphRangesThai() { return ImGlyphRanges(_handle->GetGlyphRangesThai()); }
	ImGlyphRanges ImFontAtlas::GetGlyphRangesVietnamese() { return ImGlyphRanges(_handle->GetGlyphRangesVietnamese()); }

	int ImFontAtlas::AddCustomRectRegular(uint32_t id, int width, int height) { return _handle->AddCustomRectRegular(id, width, height); }
	int ImFontAtlas::AddCustomRectFontGlyph(ImFont^ font, ImWchar id, int width, int height, float advance_x, ImVec2 offset) { return _handle->AddCustomRectFontGlyph(font->_handle, id, width, height, advance_x, offset); }
	int ImFontAtlas::AddCustomRectFontGlyph(ImFont^ font, ImWchar id, int width, int height, float advance_x) { return _handle->AddCustomRectFontGlyph(font->_handle, id, width, height, advance_x); }

	ImFontAtlasCustomRect ImFontAtlas::GetCustomRectByIndex(int index) { return *_handle->GetCustomRectByIndex(index); }

	WRAPPED_PROP_AUTO_IMPL(ImFontAtlas, Locked);
	WRAPPED_PROP_UDT_IMPL(ImFontAtlas, ImFontAtlasFlags, Flags);
	WRAPPED_PROP_CAST_IMPL(ImFontAtlas, IntPtr, void*, TexID);
	WRAPPED_PROP_AUTO_IMPL(ImFontAtlas, TexDesiredWidth);
	WRAPPED_PROP_AUTO_IMPL(ImFontAtlas, TexGlyphPadding);
}