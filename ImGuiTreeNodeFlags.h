#pragma once

#include "common.h"

using OGImGuiTreeNodeFlags = ::ImGuiTreeNodeFlags;

namespace ImGuiCppCli
{
#define WRAPPED_ENUM ImGuiTreeNodeFlags
	[Flags]
	public enum class WRAPPED_ENUM
	{
		WRAP_ENUM(None),
		WRAP_ENUM(Selected),
		WRAP_ENUM(Framed),
		WRAP_ENUM(AllowItemOverlap),
		WRAP_ENUM(NoTreePushOnOpen),
		WRAP_ENUM(NoAutoOpenOnLog),
		WRAP_ENUM(DefaultOpen),
		WRAP_ENUM(OpenOnDoubleClick),
		WRAP_ENUM(OpenOnArrow),
		WRAP_ENUM(Leaf),
		WRAP_ENUM(Bullet),
		WRAP_ENUM(FramePadding),
		WRAP_ENUM(SpanAvailWidth),
		WRAP_ENUM(SpanFullWidth),
		WRAP_ENUM(NavLeftJumpsBackHere),
		WRAP_ENUM(CollapsingHeader)
	};
#undef WRAPPED_ENUM
}