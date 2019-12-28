#pragma once

#include "common.h"

using OGImGuiFocusedFlags = ::ImGuiFocusedFlags;

namespace ImGuiCppCli
{
#define WRAPPED_ENUM ImGuiFocusedFlags
	[Flags]
	public enum class WRAPPED_ENUM
	{
		WRAP_ENUM(None),
		WRAP_ENUM(ChildWindows),
		WRAP_ENUM(RootWindow),
		WRAP_ENUM(AnyWindow),
		WRAP_ENUM(RootAndChildWindows)
	};
#undef WRAPPED_ENUM
}