#pragma once

#include "common.h"

using OGImFontAtlasFlags = ::ImFontAtlasFlags;

namespace ImGuiCppCli
{
#define WRAPPED_ENUM ImFontAtlasFlags
	[Flags]
	public enum class WRAPPED_ENUM
	{
		WRAP_ENUM(None),
		WRAP_ENUM(NoPowerOfTwoHeight),
		WRAP_ENUM(NoMouseCursors)
	};
#undef WRAPPED_ENUM
}