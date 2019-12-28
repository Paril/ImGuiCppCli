#pragma once
#include "common.h"

using OGImGuiKey = ::ImGuiKey;

namespace ImGuiCppCli
{
#define WRAPPED_ENUM ImGuiKey
    public enum class WRAPPED_ENUM
    {
        WRAP_ENUM(Tab),
        WRAP_ENUM(LeftArrow),
        WRAP_ENUM(RightArrow),
        WRAP_ENUM(UpArrow),
        WRAP_ENUM(DownArrow),
        WRAP_ENUM(PageUp),
        WRAP_ENUM(PageDown),
        WRAP_ENUM(Home),
        WRAP_ENUM(End),
        WRAP_ENUM(Insert),
        WRAP_ENUM(Delete),
        WRAP_ENUM(Backspace),
        WRAP_ENUM(Space),
        WRAP_ENUM(Enter),
        WRAP_ENUM(Escape),
        WRAP_ENUM(KeyPadEnter),
        WRAP_ENUM(A),          
        WRAP_ENUM(C),          
        WRAP_ENUM(V),          
        WRAP_ENUM(X),          
        WRAP_ENUM(Y),          
        WRAP_ENUM(Z),          
        WRAP_ENUM(COUNT)
    };
#undef WRAPPED_ENUM
}