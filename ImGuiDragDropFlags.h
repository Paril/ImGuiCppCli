#pragma once

#include "common.h"

using OGImGuiDragDropFlags = ::ImGuiDragDropFlags;

namespace ImGuiCppCli
{
#define WRAPPED_ENUM ImGuiDragDropFlags
	[Flags]
	public enum class WRAPPED_ENUM
	{
		WRAP_ENUM(None),
		WRAP_ENUM(SourceNoPreviewTooltip),
		WRAP_ENUM(SourceNoDisableHover),
		WRAP_ENUM(SourceNoHoldToOpenOthers),
		WRAP_ENUM(SourceAllowNullID),
		WRAP_ENUM(SourceExtern),
		WRAP_ENUM(SourceAutoExpirePayload),
		WRAP_ENUM(AcceptBeforeDelivery),
		WRAP_ENUM(AcceptNoDrawDefaultRect),
		WRAP_ENUM(AcceptNoPreviewTooltip),
		WRAP_ENUM(AcceptPeekOnly)
	};
#undef WRAPPED_ENUM
}