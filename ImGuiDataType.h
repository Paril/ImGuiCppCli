#pragma once

#include "common.h"

using OGImGuiDataType = ::ImGuiDataType;

namespace ImGuiCppCli
{
#define WRAPPED_ENUM ImGuiDataType
	public enum class WRAPPED_ENUM
	{
        WRAP_ENUM(S8),
        WRAP_ENUM(U8),
        WRAP_ENUM(S16),
        WRAP_ENUM(U16),
        WRAP_ENUM(S32),
        WRAP_ENUM(U32),
        WRAP_ENUM(S64),
        WRAP_ENUM(U64),
        WRAP_ENUM(Float),
        WRAP_ENUM(Double),
        WRAP_ENUM(COUNT)
	};
#undef WRAPPED_ENUM
}