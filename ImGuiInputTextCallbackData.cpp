#include "ImGuiInputTextCallbackData.h"

namespace ImGuiCppCli
{
	WRAPPED_PROP_AUTO_IMPL(ImGuiInputTextCallbackData, EventChar);
	WRAPPED_PROP_AUTO_IMPL(ImGuiInputTextCallbackData, BufTextLen);
	WRAPPED_PROP_AUTO_IMPL(ImGuiInputTextCallbackData, BufDirty);
	WRAPPED_PROP_AUTO_IMPL(ImGuiInputTextCallbackData, CursorPos);
	WRAPPED_PROP_AUTO_IMPL(ImGuiInputTextCallbackData, SelectionStart);
	WRAPPED_PROP_AUTO_IMPL(ImGuiInputTextCallbackData, SelectionEnd);

	void ImGuiInputTextCallbackData::DeleteChars(int pos, int bytes_count)
	{
		_handle->DeleteChars(pos, bytes_count);
	}

	void ImGuiInputTextCallbackData::InsertChars(int pos, ImString^ text)
	{
		CSTR_DECODE_TEMP(text);
		_handle->InsertChars(pos, text_cstr);
	}

	bool ImGuiInputTextCallbackData::HasSelection()
	{
		return _handle->HasSelection();
	}
}