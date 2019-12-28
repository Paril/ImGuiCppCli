#pragma once

#include "common.h"

using OGImGuiTabBarFlags = ::ImGuiTabBarFlags;

namespace ImGuiCppCli
{
#define WRAPPED_ENUM ImGuiTabBarFlags
	[Flags]
	public enum class WRAPPED_ENUM
	{
		WRAP_ENUM(None),
		WRAP_ENUM(Reorderable),
		WRAP_ENUM(AutoSelectNewTabs),
		WRAP_ENUM(TabListPopupButton),
		WRAP_ENUM(NoCloseWithMiddleMouseButton),
		WRAP_ENUM(NoTabListScrollingButtons),
		WRAP_ENUM(NoTooltip),
		WRAP_ENUM(FittingPolicyResizeDown),
		WRAP_ENUM(FittingPolicyScroll)
	};
#undef WRAPPED_ENUM
}