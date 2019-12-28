#pragma once
#include "common.h"

using OGImGuiDir = ::ImGuiDir;

namespace ImGuiCppCli
{
#define WRAPPED_ENUM ImGuiDir
	public enum class WRAPPED_ENUM
	{
		WRAP_ENUM(None),
		WRAP_ENUM(Left),
		WRAP_ENUM(Right),
		WRAP_ENUM(Up),
		WRAP_ENUM(Down),
		WRAP_ENUM(COUNT)
	};
#undef WRAPPED_ENUM
}