#pragma once

#include "common.h"

using OGImVec2 = ImVec2;

namespace ImGuiCppCli
{
	[StructLayout(LayoutKind::Sequential)]
	public value struct ImVec2
	{
	public:
		float x, y;

		ImVec2(float x, float y);

	internal:
		ImVec2(const OGImVec2& v);

		operator OGImVec2();

		static operator ImVec2(OGImVec2 v);
	};
}