#include "ImDrawCmd.h"

namespace ImGuiCppCli
{
	ImDrawCallback^ ImDrawCmd::UserCallback::get()
	{
		return UserCallback_ != UserCallback_.Zero ? Marshal::GetDelegateForFunctionPointer<ImDrawCallback^>(UserCallback_) : nullptr;
	}
}