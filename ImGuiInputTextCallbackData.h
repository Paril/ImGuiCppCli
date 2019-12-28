#pragma once
#include "common.h"
#include "ImGuiInputTextFlags.h"
#include "ImGuiKey.h"

namespace ImGuiCppCli
{
	public value struct ImGuiInputTextCallbackData
	{
	internal:
		::ImGuiInputTextCallbackData* _handle;

		ImGuiInputTextCallbackData(::ImGuiInputTextCallbackData* handle) :
			_handle(handle)
		{
		}

	public:
		property ImGuiInputTextFlags EventFlag
		{
			ImGuiInputTextFlags get() { return (ImGuiInputTextFlags)_handle->EventFlag; }
		}

		property ImGuiInputTextFlags Flags
		{
			ImGuiInputTextFlags get() { return (ImGuiInputTextFlags)_handle->Flags; }
		}

		WRAPPED_PROP_AUTO_DECL(EventChar);

		property ImGuiKey EventKey
		{
			ImGuiKey get() { return (ImGuiKey)_handle->EventKey; }
		}

		property Span<char> Buf
		{
			Span<char> get() { return Span<char>(_handle->Buf, _handle->BufSize); }
		}

		WRAPPED_PROP_AUTO_DECL(BufTextLen);
		WRAPPED_PROP_AUTO_DECL(BufDirty);
		WRAPPED_PROP_AUTO_DECL(CursorPos);
		WRAPPED_PROP_AUTO_DECL(SelectionStart);
		WRAPPED_PROP_AUTO_DECL(SelectionEnd);

		void DeleteChars(int pos, int bytes_count);
		void InsertChars(int pos, ImString^ text);
		bool HasSelection();
	};
}