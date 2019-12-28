#pragma once

#include "common.h"
#include "ImGlyphRanges.h"
#include "ImVec2.h"
#include "ImFontAtlasFlags.h"

using OGImFontAtlas = ::ImFontAtlas;

namespace ImGuiCppCli
{
	ref struct ImFont;
	ref struct ImFontConfig;

	public ref struct ImFontAtlas
	{
	internal:
		OGImFontAtlas* _handle;

		ImFontAtlas(OGImFontAtlas* handle);

	public:
		ImFont^ AddFont(ImFontConfig^ config);
		ImFont^ AddFontDefault(ImFontConfig^ config);
		ImFont^ AddFontDefault();
		void ClearInputData();
		void ClearTexData();
		void ClearFonts();
		void Clear();
		bool Build();
		void GetTexDataAsAlpha8([Out] array<uint8_t>^% value, [Out] int% width, [Out] int% height, [Out] int% out_bytes_per_pixel);
		void GetTexDataAsAlpha8([Out] array<uint8_t>^% value, [Out] int% width, [Out] int% height);
		void GetTexDataAsRGBA32([Out] array<uint8_t>^% value, [Out] int% width, [Out] int% height, [Out] int% out_bytes_per_pixel);
		void GetTexDataAsRGBA32([Out] array<uint8_t>^% value, [Out] int% width, [Out] int% height);
		bool IsBuilt();
		void SetTexID(ImTextureID id);

		ImGlyphRanges GetGlyphRangesDefault();
		ImGlyphRanges GetGlyphRangesKorean();
		ImGlyphRanges GetGlyphRangesJapanese();
		ImGlyphRanges GetGlyphRangesChineseFull();
		ImGlyphRanges GetGlyphRangesChineseSimplifiedCommon();
		ImGlyphRanges GetGlyphRangesCyrillic();
		ImGlyphRanges GetGlyphRangesThai();
		ImGlyphRanges GetGlyphRangesVietnamese();

		int AddCustomRectRegular(uint32_t id, int width, int height);
		int AddCustomRectFontGlyph(ImFont^ font, ImWchar id, int width, int height, float advance_x, ImVec2 offset);
		int AddCustomRectFontGlyph(ImFont^ font, ImWchar id, int width, int height, float advance_x);

		ImFontAtlasCustomRect GetCustomRectByIndex(int index);

		WRAPPED_PROP_AUTO_DECL(Locked);
		WRAPPED_PROP_UDT_DECL(ImFontAtlasFlags, Flags);
		WRAPPED_PROP_CAST_DECL(IntPtr, void*, TexID);
		WRAPPED_PROP_AUTO_DECL(TexDesiredWidth);
		WRAPPED_PROP_AUTO_DECL(TexGlyphPadding);
	};
}