#include "ImVec4.h"

namespace ImGuiCppCli
{
	ImVec4::ImVec4(float x, float y, float z, float w) :
		x(x),
		y(y),
		z(z),
		w(w)
	{
	}

	ImVec4::ImVec4(const OGImVec4& v) :
		ImVec4(v.x, v.y, v.z, v.w)
	{
	}

	ImVec4::operator OGImVec4()
	{
		return OGImVec4(x, y, z, w);
	}

	/*static*/ ImVec4::operator ImGuiCppCli::ImVec4(OGImVec4 v)
	{
		return ImGuiCppCli::ImVec4(v);
	}
}