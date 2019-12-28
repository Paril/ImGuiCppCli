#pragma once

#include "common.h"

using OGImGuiWindowFlags = ::ImGuiWindowFlags;

namespace ImGuiCppCli
{
#define WRAPPED_ENUM ImGuiWindowFlags
	[Flags]
	public enum class WRAPPED_ENUM
	{
		WRAP_ENUM(None),
		WRAP_ENUM(NoTitleBar),
		WRAP_ENUM(NoResize),
		WRAP_ENUM(NoMove),
		WRAP_ENUM(NoScrollbar),
		WRAP_ENUM(NoScrollWithMouse),
		WRAP_ENUM(NoCollapse),
		WRAP_ENUM(AlwaysAutoResize),
		WRAP_ENUM(NoBackground),
		WRAP_ENUM(NoSavedSettings),
		WRAP_ENUM(NoMouseInputs),
		WRAP_ENUM(MenuBar),
		WRAP_ENUM(HorizontalScrollbar),
		WRAP_ENUM(NoFocusOnAppearing),
		WRAP_ENUM(NoBringToFrontOnFocus),
		WRAP_ENUM(AlwaysVerticalScrollbar),
		WRAP_ENUM(AlwaysHorizontalScrollbar),
		WRAP_ENUM(AlwaysUseWindowPadding),
		WRAP_ENUM(NoNavInputs),
		WRAP_ENUM(NoNavFocus),
		WRAP_ENUM(UnsavedDocument),
		WRAP_ENUM(NoNav),
		WRAP_ENUM(NoDecoration),
		WRAP_ENUM(NoInputs)
	};
#undef WRAPPED_ENUM
}