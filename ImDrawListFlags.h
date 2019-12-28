#pragma once

#include "common.h"

using OGImDrawListFlags = ::ImDrawListFlags;

namespace ImGuiCppCli
{
#define WRAPPED_ENUM ImDrawListFlags
	[Flags]
	public enum class WRAPPED_ENUM
	{
		WRAP_ENUM(None),
		WRAP_ENUM(AntiAliasedLines),
		WRAP_ENUM(AntiAliasedFill),
		WRAP_ENUM(AllowVtxOffset)
	};
#undef WRAPPED_ENUM
}