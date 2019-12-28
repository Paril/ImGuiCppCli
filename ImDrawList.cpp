#include "ImDrawList.h"

namespace ImGuiCppCli
{
	ImDrawList::ImDrawList(OGImDrawList* handle) :
		_handle(handle)
	{
	}

	WRAPPED_PROP_UDT_IMPL(ImDrawList, ImDrawListFlags, Flags);
	WRAPPED_PROP_VECTOR_READONLY_IMPL(ImDrawList, ImDrawCmd, CmdBuffer);
	WRAPPED_PROP_VECTOR_READONLY_IMPL(ImDrawList, ImDrawIdx, IdxBuffer);
	WRAPPED_PROP_VECTOR_READONLY_IMPL(ImDrawList, ImDrawVert, VtxBuffer);
}