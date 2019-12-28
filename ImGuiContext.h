#pragma once

#include "common.h"

using OGImGuiContext = ::ImGuiContext;

namespace ImGuiCppCli
{
	public value struct ImGuiContext
	{
	internal:
		OGImGuiContext* _handle;

		ImGuiContext(OGImGuiContext* handle);
	};
}