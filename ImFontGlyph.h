#pragma once

#include "common.h"

namespace ImGuiCppCli
{
	[StructLayout(LayoutKind::Sequential)]
	public value struct ImFontGlyph
	{
		ImWchar         Codepoint;
		float           AdvanceX;
		float           X0, Y0, X1, Y1;
		float           U0, V0, U1, V1;
	};
}