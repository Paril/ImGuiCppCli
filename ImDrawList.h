#pragma once

#include "common.h"
#include "ImDrawCmd.h"
#include "ImDrawVert.h"
#include "ImDrawListFlags.h"

using OGImDrawList = ::ImDrawList;

namespace ImGuiCppCli
{
	public value struct ImDrawList
	{
	internal:
		OGImDrawList* _handle;

		ImDrawList(OGImDrawList* handle);

	public:
		WRAPPED_PROP_UDT_DECL(ImDrawListFlags, Flags);
		WRAPPED_PROP_VECTOR_READONLY_DECL(ImDrawCmd, CmdBuffer);
		WRAPPED_PROP_VECTOR_READONLY_DECL(ImDrawIdx, IdxBuffer);
		WRAPPED_PROP_VECTOR_READONLY_DECL(ImDrawVert, VtxBuffer);
	};
}