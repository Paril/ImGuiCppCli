#include "ImGuiContext.h"
#include "common.h"

//struct ImGuiContext { };

namespace ImGuiCppCli
{
	ImGuiContext::ImGuiContext(OGImGuiContext* handle) :
		_handle(handle)
	{
	}
}