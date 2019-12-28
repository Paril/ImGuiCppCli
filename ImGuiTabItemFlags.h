#pragma once

#include "common.h"

using OGImGuiTabItemFlags = ::ImGuiTabItemFlags;

namespace ImGuiCppCli
{
#define WRAPPED_ENUM ImGuiTabItemFlags
	[Flags]
	public enum class WRAPPED_ENUM
	{
		WRAP_ENUM(None),
		WRAP_ENUM(UnsavedDocument),
		WRAP_ENUM(SetSelected),
		WRAP_ENUM(NoCloseWithMiddleMouseButton),
		WRAP_ENUM(NoPushId)
	};
#undef WRAPPED_ENUM
}