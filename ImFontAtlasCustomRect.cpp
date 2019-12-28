#include "ImFontAtlasCustomRect.h"

namespace ImGuiCppCli
{
	ImFontAtlasCustomRect::ImFontAtlasCustomRect(bool dumb) :
		ID(0xFFFFFFFF),
		X(0xFFFF),
		Y(0xFFFF)
	{
	}

	ImFont^ ImFontAtlasCustomRect::Font::get() { return gcnew ImFont(Font_); }
	void ImFontAtlasCustomRect::Font::set(ImFont^ v) { Font_ = v->_handle; }

	bool ImFontAtlasCustomRect::IsPacked()
	{
		return X != 0xFFFF;
	}
}