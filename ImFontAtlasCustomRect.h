#pragma once

#include "common.h"
#include "ImVec2.h"
#include "ImFont.h"

namespace ImGuiCppCli
{
	[StructLayout(LayoutKind::Sequential)]
	public value struct ImFontAtlasCustomRect
	{
		static const ImFontAtlasCustomRect Default = ImFontAtlasCustomRect(true);

		uint32_t ID;
		uint16_t Width, Height;
		uint16_t X, Y;
		float GlyphAdvanceX;
		ImVec2 GlyphOffset;

	private:
		::ImFont* Font_;

		ImFontAtlasCustomRect(bool dumb);

	public:
		property ImFont^ Font
		{
			ImFont^ get();
			void set(ImFont^ v);
		}
		bool IsPacked();
	};
}