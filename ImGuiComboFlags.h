#pragma once

#include "common.h"

using OGImGuiComboFlags = ::ImGuiComboFlags;

namespace ImGuiCppCli
{
#define WRAPPED_ENUM ImGuiComboFlags
	[Flags]
	public enum class WRAPPED_ENUM
	{
		WRAP_ENUM(None),
		WRAP_ENUM(PopupAlignLeft),
		WRAP_ENUM(HeightSmall),
		WRAP_ENUM(HeightRegular),
		WRAP_ENUM(HeightLarge),
		WRAP_ENUM(HeightLargest),
		WRAP_ENUM(NoArrowButton),
		WRAP_ENUM(NoPreview)
	};
#undef WRAPPED_ENUM
}