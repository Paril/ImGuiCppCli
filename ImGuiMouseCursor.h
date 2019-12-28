#pragma once

#include "common.h"

using OGImGuiMouseCursor = ::ImGuiMouseCursor;

namespace ImGuiCppCli
{
#define WRAPPED_ENUM ImGuiMouseCursor
    public enum class WRAPPED_ENUM
    {
        WRAP_ENUM(None),
        WRAP_ENUM(Arrow),
        WRAP_ENUM(TextInput),
        WRAP_ENUM(ResizeAll),
        WRAP_ENUM(ResizeNS),
        WRAP_ENUM(ResizeEW),
        WRAP_ENUM(ResizeNESW),
        WRAP_ENUM(ResizeNWSE),
        WRAP_ENUM(Hand),
        WRAP_ENUM(NotAllowed),
        WRAP_ENUM(COUNT)
    };
#undef WRAPPED_ENUM
}