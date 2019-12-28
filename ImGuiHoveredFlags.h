#pragma once

#include "common.h"

using OGImGuiHoveredFlags = ::ImGuiHoveredFlags;

namespace ImGuiCppCli
{
#define WRAPPED_ENUM ImGuiHoveredFlags
    [Flags]
    public enum class WRAPPED_ENUM
    {
        WRAP_ENUM(None),
        WRAP_ENUM(ChildWindows),
        WRAP_ENUM(RootWindow),
        WRAP_ENUM(AnyWindow),
        WRAP_ENUM(AllowWhenBlockedByPopup),
        //WRAP_ENUM(AllowWhenBlockedByModal),
        WRAP_ENUM(AllowWhenBlockedByActiveItem),
        WRAP_ENUM(AllowWhenOverlapped),
        WRAP_ENUM(AllowWhenDisabled),
        WRAP_ENUM(RectOnly),
        WRAP_ENUM(RootAndChildWindows)
    };
#undef WRAPPED_ENUM
}