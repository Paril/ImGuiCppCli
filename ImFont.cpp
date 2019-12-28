#include "ImFont.h"
#include "ImFontAtlas.h"
#include "ImFontConfig.h"

namespace ImGuiCppCli
{
	ImFont::ImFont(OGImFont* handle) :
		_handle(handle)
	{
	}

	WRAPPED_PROP_VECTOR_READONLY_IMPL(ImFont, float, IndexAdvanceX);
	WRAPPED_PROP_AUTO_IMPL(ImFont, FallbackAdvanceX);
	WRAPPED_PROP_AUTO_IMPL(ImFont, FontSize);

	WRAPPED_PROP_VECTOR_READONLY_IMPL(ImFont, ImWchar, IndexLookup);
	WRAPPED_PROP_VECTOR_READONLY_IMPL(ImFont, ImFontGlyph, Glyphs);
	ImFontGlyph ImFont::FallbackGlyph::get() { return *(ImFontGlyph*)_handle->FallbackGlyph; }
	WRAPPED_PROP_UDT_IMPL(ImFont, ImVec2, DisplayOffset);

	WRAPPED_PROP_HANDLE_IMPL(ImFont, ImFontAtlas, OGImFontAtlas, ContainerAtlas);
	WRAPPED_PROP_HANDLE_IMPL(ImFont, ImFontConfig, OGImFontConfig, ConfigData);
	WRAPPED_PROP_AUTO_IMPL(ImFont, ConfigDataCount);
	WRAPPED_PROP_AUTO_IMPL(ImFont, FallbackChar);
	WRAPPED_PROP_AUTO_IMPL(ImFont, EllipsisChar);
	WRAPPED_PROP_AUTO_IMPL(ImFont, Scale);
	WRAPPED_PROP_AUTO_IMPL(ImFont, Ascent);
	WRAPPED_PROP_AUTO_IMPL(ImFont, Descent);
	WRAPPED_PROP_AUTO_IMPL(ImFont, MetricsTotalSurface);
	WRAPPED_PROP_AUTO_IMPL(ImFont, DirtyLookupTables);

	ImFontGlyph ImFont::FindGlyph(ImWchar c) { return *(ImFontGlyph*)_handle->FindGlyph(c); }
	ImFontGlyph ImFont::FindGlyphNoFallback(ImWchar c) { return *(ImFontGlyph*)_handle->FindGlyphNoFallback(c); }
	float ImFont::GetCharAdvance(ImWchar c) { return _handle->GetCharAdvance(c); }
	bool ImFont::IsLoaded() { return _handle->IsLoaded(); }
	ReadOnlySpan<const uint8_t> ImFont::GetDebugName()
	{
		return ReadOnlySpan<const uint8_t>((void*)_handle->GetDebugName(), (int)strlen(_handle->GetDebugName()));
	}

	ImVec2 ImFont::CalcTextSizeA(float size, float max_width, float wrap_width, ReadOnlySpan<const uint8_t> text, [Out] int% remaining)
	{
		SPAN_GET_PTR(const uint8_t, const char, text);
		const char* out_remaining;
		OGImVec2 ret = _handle->CalcTextSizeA(size, max_width, wrap_width, text_ptr, NULL, &out_remaining);
		remaining = (int)(out_remaining - text_ptr);
		return ret;
	}
	ImVec2 ImFont::CalcTextSizeA(float size, float max_width, float wrap_width, ReadOnlySpan<const uint8_t> text)
	{
		SPAN_GET_PTR(const uint8_t, const char, text);
		return _handle->CalcTextSizeA(size, max_width, wrap_width, text_ptr);
	}
	int ImFont::CalcWordWrapPositionA(float scale, ReadOnlySpan<const uint8_t> text, float wrap_width)
	{
		SPAN_GET_PTR(const uint8_t, const char, text);
		auto pos = _handle->CalcWordWrapPositionA(scale, text_ptr, text_ptr + text.Length, wrap_width);
		return (int)(pos - text_ptr);
	}
	void ImFont::RenderChar(ImDrawList draw_list, float size, ImVec2 pos, ImU32 col, ImWchar c)
	{
		_handle->RenderChar(draw_list._handle, size, pos, col, c);
	}
	void ImFont::RenderText(ImDrawList draw_list, float size, ImVec2 pos, ImU32 col, ImVec4 clip_rect, ImString^ text, float wrap_width, bool cpu_fine_clip)
	{
		IMSTR_DECODE_TEMP(text);
		_handle->RenderText(draw_list._handle, size, pos, col, clip_rect, text_cstr, text_cstr + text_bytes.Length, wrap_width, cpu_fine_clip);
	}
	void ImFont::RenderText(ImDrawList draw_list, float size, ImVec2 pos, ImU32 col, ImVec4 clip_rect, ReadOnlySpan<const uint8_t> text, float wrap_width, bool cpu_fine_clip)
	{
		SPAN_GET_PTR(const uint8_t, const char, text);
		_handle->RenderText(draw_list._handle, size, pos, col, clip_rect, text_ptr, text_ptr + text.Length, wrap_width, cpu_fine_clip);
	}
	void ImFont::RenderText(ImDrawList draw_list, float size, ImVec2 pos, ImU32 col, ImVec4 clip_rect, ImString^ text, float wrap_width)
	{
		IMSTR_DECODE_TEMP(text);
		_handle->RenderText(draw_list._handle, size, pos, col, clip_rect, text_cstr, text_cstr + text_bytes.Length, wrap_width);
	}
	void ImFont::RenderText(ImDrawList draw_list, float size, ImVec2 pos, ImU32 col, ImVec4 clip_rect, ReadOnlySpan<const uint8_t> text, float wrap_width)
	{
		SPAN_GET_PTR(const uint8_t, const char, text);
		_handle->RenderText(draw_list._handle, size, pos, col, clip_rect, text_ptr, text_ptr + text.Length, wrap_width);
	}
	void ImFont::RenderText(ImDrawList draw_list, float size, ImVec2 pos, ImU32 col, ImVec4 clip_rect, ImString^ text)
	{
		IMSTR_DECODE_TEMP(text);
		_handle->RenderText(draw_list._handle, size, pos, col, clip_rect, text_cstr, text_cstr + text_bytes.Length);
	}
	void ImFont::RenderText(ImDrawList draw_list, float size, ImVec2 pos, ImU32 col, ImVec4 clip_rect, ReadOnlySpan<const uint8_t> text)
	{
		SPAN_GET_PTR(const uint8_t, const char, text);
		_handle->RenderText(draw_list._handle, size, pos, col, clip_rect, text_ptr, text_ptr + text.Length);
	}
}