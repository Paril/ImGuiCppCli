#pragma once

#include "common.h"

using OGImGuiCond = ::ImGuiCond;

namespace ImGuiCppCli
{
#define WRAPPED_ENUM ImGuiCond
    [Flags]
    public enum class WRAPPED_ENUM
    {
       WRAP_ENUM(Always),
       WRAP_ENUM(Once),
       WRAP_ENUM(FirstUseEver),
       WRAP_ENUM(Appearing)
    };
#undef WRAPPED_ENUM
}