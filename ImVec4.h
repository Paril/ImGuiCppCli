#pragma once

#include "common.h"

using OGImVec4 = ImVec4;

namespace ImGuiCppCli
{
	[StructLayout(LayoutKind::Sequential)]
	public value struct ImVec4
	{
	public:
		float x, y, z, w;

		ImVec4(float x, float y, float z, float w);

	internal:
		ImVec4(const OGImVec4& v);

		operator OGImVec4();

		static operator ImVec4(OGImVec4 v);
	};
}