#pragma once

#include "common.h"

using OGImGuiConfigFlags = ::ImGuiConfigFlags;

namespace ImGuiCppCli
{
#define WRAPPED_ENUM ImGuiConfigFlags
	[Flags]
	public enum class WRAPPED_ENUM
	{
		WRAP_ENUM(None),
		WRAP_ENUM(NavEnableKeyboard),
		WRAP_ENUM(NavEnableGamepad),
		WRAP_ENUM(NavEnableSetMousePos),
		WRAP_ENUM(NavNoCaptureKeyboard),
		WRAP_ENUM(NoMouse),
		WRAP_ENUM(NoMouseCursorChange),
		WRAP_ENUM(IsSRGB),
		WRAP_ENUM(IsTouchScreen)
	};
#undef WRAPPED_ENUM
}