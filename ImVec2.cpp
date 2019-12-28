#include "ImVec2.h"

namespace ImGuiCppCli
{
	ImVec2::ImVec2(float x, float y) :
		x(x),
		y(y)
	{
	}

	ImVec2::ImVec2(const OGImVec2& v) :
		ImVec2(v.x, v.y)
	{
	}

	ImVec2::operator OGImVec2()
	{
		return OGImVec2(x, y);
	}

	/*static*/ ImVec2::operator ImVec2(OGImVec2 v)
	{
		return ImVec2(v);
	}
}