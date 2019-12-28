#pragma once

#include "common.h"

using OGImGuiStyleVar = ::ImGuiStyleVar;

namespace ImGuiCppCli
{
#define WRAPPED_ENUM ImGuiStyleVar
	[Flags]
	public enum class WRAPPED_ENUM
	{
		WRAP_ENUM(Alpha),
		WRAP_ENUM(WindowPadding),
		WRAP_ENUM(WindowRounding),
		WRAP_ENUM(WindowBorderSize),
		WRAP_ENUM(WindowMinSize),
		WRAP_ENUM(WindowTitleAlign),
		WRAP_ENUM(ChildRounding),
		WRAP_ENUM(ChildBorderSize),
		WRAP_ENUM(PopupRounding),
		WRAP_ENUM(PopupBorderSize),
		WRAP_ENUM(FramePadding),
		WRAP_ENUM(FrameRounding),
		WRAP_ENUM(FrameBorderSize),
		WRAP_ENUM(ItemSpacing),
		WRAP_ENUM(ItemInnerSpacing),
		WRAP_ENUM(IndentSpacing),
		WRAP_ENUM(ScrollbarSize),
		WRAP_ENUM(ScrollbarRounding),
		WRAP_ENUM(GrabMinSize),
		WRAP_ENUM(GrabRounding),
		WRAP_ENUM(TabRounding),
		WRAP_ENUM(ButtonTextAlign),
		WRAP_ENUM(SelectableTextAlign),
		WRAP_ENUM(COUNT)
	};
#undef WRAPPED_ENUM
}