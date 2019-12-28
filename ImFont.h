#pragma once

#include "common.h"
#include "ImFontGlyph.h"
#include "ImDrawList.h"
#include "ImVec2.h"

using OGImFont = ::ImFont;
using OGImFontAtlas = ::ImFontAtlas;
using OGImFontConfig = ::ImFontConfig;

namespace ImGuiCppCli
{
	ref struct ImFontAtlas;
	ref struct ImFontConfig;

	public ref struct ImFont
	{
	internal:
		OGImFont* _handle;

		ImFont(OGImFont* handle);

	public:
		WRAPPED_PROP_VECTOR_READONLY_DECL(float, IndexAdvanceX);
		WRAPPED_PROP_AUTO_DECL(FallbackAdvanceX);
		WRAPPED_PROP_AUTO_DECL(FontSize);

		WRAPPED_PROP_VECTOR_READONLY_DECL(ImWchar, IndexLookup);
		WRAPPED_PROP_VECTOR_READONLY_DECL(ImFontGlyph, Glyphs);
		property ImFontGlyph FallbackGlyph
		{
			ImFontGlyph get();
		}
		WRAPPED_PROP_UDT_DECL(ImVec2, DisplayOffset);

		WRAPPED_PROP_HANDLE_DECL(ImFontAtlas, OGImFontAtlas, ContainerAtlas);
		WRAPPED_PROP_HANDLE_DECL(ImFontConfig, OGImFontConfig, ConfigData);
		WRAPPED_PROP_AUTO_DECL(ConfigDataCount);
		WRAPPED_PROP_AUTO_DECL(FallbackChar);
		WRAPPED_PROP_AUTO_DECL(EllipsisChar);
		WRAPPED_PROP_AUTO_DECL(Scale);
		WRAPPED_PROP_AUTO_DECL(Ascent);
		WRAPPED_PROP_AUTO_DECL(Descent);
		WRAPPED_PROP_AUTO_DECL(MetricsTotalSurface);
		WRAPPED_PROP_AUTO_DECL(DirtyLookupTables);

		ImFontGlyph FindGlyph(ImWchar c);
		ImFontGlyph FindGlyphNoFallback(ImWchar c);
		float GetCharAdvance(ImWchar c);
		bool IsLoaded();
		ReadOnlySpan<const uint8_t> GetDebugName();

		ImVec2 CalcTextSizeA(float size, float max_width, float wrap_width, ReadOnlySpan<const uint8_t> text, [Out] int% remaining);
		ImVec2 CalcTextSizeA(float size, float max_width, float wrap_width, ReadOnlySpan<const uint8_t> text);
		int CalcWordWrapPositionA(float scale, ReadOnlySpan<const uint8_t> text, float wrap_width);
		void RenderChar(ImDrawList draw_list, float size, ImVec2 pos, ImU32 col, ImWchar c);
		void RenderText(ImDrawList draw_list, float size, ImVec2 pos, ImU32 col, ImVec4 clip_rect, ImString^ text, float wrap_width, bool cpu_fine_clip);
		void RenderText(ImDrawList draw_list, float size, ImVec2 pos, ImU32 col, ImVec4 clip_rect, ReadOnlySpan<const uint8_t> text, float wrap_width, bool cpu_fine_clip);
		void RenderText(ImDrawList draw_list, float size, ImVec2 pos, ImU32 col, ImVec4 clip_rect, ImString^ text, float wrap_width);
		void RenderText(ImDrawList draw_list, float size, ImVec2 pos, ImU32 col, ImVec4 clip_rect, ReadOnlySpan<const uint8_t> text, float wrap_width);
		void RenderText(ImDrawList draw_list, float size, ImVec2 pos, ImU32 col, ImVec4 clip_rect, ImString^ text);
		void RenderText(ImDrawList draw_list, float size, ImVec2 pos, ImU32 col, ImVec4 clip_rect, ReadOnlySpan<const uint8_t> text);
	};
}