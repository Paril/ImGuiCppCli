#pragma once

using namespace System;

#include "ImVec2.h"

namespace ImGuiCppCli
{
    public value struct ImGuiSizeCallbackData
    {
    private:
        IntPtr UserData;
    public:
        ImVec2 Pos;
        ImVec2 CurrentSize;
        ImVec2 DesiredSize;
    };

    public delegate void ImGuiSizeDelegate(ImGuiSizeCallbackData% data);
}