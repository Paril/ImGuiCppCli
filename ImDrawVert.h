#pragma once

#include "common.h"
#include "ImVec2.h"

namespace ImGuiCppCli
{
	[StructLayout(LayoutKind::Explicit)]
	public value struct ImDrawVert
	{
		[FieldOffset(0)]
		ImVec2  pos;
		[FieldOffset(8)]
		ImVec2  uv;
		[FieldOffset(16)]
		ImU32   col;
		[FieldOffset(16)]
		uint8_t R;
		[FieldOffset(17)]
		uint8_t G;
		[FieldOffset(18)]
		uint8_t B;
		[FieldOffset(19)]
		uint8_t A;
	};
}