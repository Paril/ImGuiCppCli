#pragma once

#include "common.h"

using OGImGuiInputTextFlags = ::ImGuiInputTextFlags;

namespace ImGuiCppCli
{
#define WRAPPED_ENUM ImGuiInputTextFlags
	[Flags]
	public enum class WRAPPED_ENUM
	{
		WRAP_ENUM(None),
		WRAP_ENUM(CharsDecimal),
		WRAP_ENUM(CharsHexadecimal),
		WRAP_ENUM(CharsUppercase),
		WRAP_ENUM(CharsNoBlank),
		WRAP_ENUM(AutoSelectAll),
		WRAP_ENUM(EnterReturnsTrue),
		WRAP_ENUM(CallbackCompletion),
		WRAP_ENUM(CallbackHistory),
		WRAP_ENUM(CallbackAlways),
		WRAP_ENUM(CallbackCharFilter),
		WRAP_ENUM(AllowTabInput),
		WRAP_ENUM(CtrlEnterForNewLine),
		WRAP_ENUM(NoHorizontalScroll),
		WRAP_ENUM(AlwaysInsertMode),
		WRAP_ENUM(ReadOnly),
		WRAP_ENUM(Password),
		WRAP_ENUM(NoUndoRedo),
		WRAP_ENUM(CharsScientific),
		WRAP_ENUM(CallbackResize)
	};
#undef WRAPPED_ENUM
}