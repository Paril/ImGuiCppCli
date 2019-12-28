#pragma once

#include "common.h"

using OGImGuiMouseButton = ::ImGuiMouseButton;

namespace ImGuiCppCli
{
#define WRAPPED_ENUM ImGuiMouseButton
	public enum class WRAPPED_ENUM
	{
		WRAP_ENUM(Left),
		WRAP_ENUM(Right),
		WRAP_ENUM(Middle),
		WRAP_ENUM(COUNT)
	};
#undef WRAPPED_ENUM
}