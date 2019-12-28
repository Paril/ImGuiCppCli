#pragma once

#include "common.h"

using OGImGuiBackendFlags = ::ImGuiBackendFlags;

namespace ImGuiCppCli
{
#define WRAPPED_ENUM ImGuiBackendFlags
	[Flags]
	public enum class WRAPPED_ENUM
	{
		WRAP_ENUM(None),
		WRAP_ENUM(HasGamepad),
		WRAP_ENUM(HasMouseCursors),
		WRAP_ENUM(HasSetMousePos),
		WRAP_ENUM(RendererHasVtxOffset)
	};
#undef WRAPPED_ENUM
}