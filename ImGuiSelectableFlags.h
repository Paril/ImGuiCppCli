#pragma once

#include "common.h"

using OGImGuiSelectableFlags = ::ImGuiSelectableFlags;

namespace ImGuiCppCli
{
#define WRAPPED_ENUM ImGuiSelectableFlags
	[Flags]
	public enum class WRAPPED_ENUM
	{
		WRAP_ENUM(None),
		WRAP_ENUM(DontClosePopups),
		WRAP_ENUM(SpanAllColumns),
		WRAP_ENUM(AllowDoubleClick),
		WRAP_ENUM(Disabled),
		WRAP_ENUM(AllowItemOverlap)
	};
#undef WRAPPED_ENUM
}