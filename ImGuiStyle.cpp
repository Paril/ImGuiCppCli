#include "ImGuiStyle.h"

namespace ImGuiCppCli
{
	ImGuiStyle::ImGuiStyle()
	{
	}

	ImGuiStyle::ImGuiStyle(OGImGuiStyle* ptr) :
		_handle(ptr)
	{
	}

	ImGuiStyle::ImGuiStyle(ImGuiStyle^ style)
	{
		memcpy(&_handle, &style->_handle, sizeof(OGImGuiStyle));
	}

	WRAPPED_PROP_AUTO_IMPL(ImGuiStyle, Alpha);
	WRAPPED_PROP_UDT_IMPL(ImGuiStyle, ImVec2, WindowPadding);
	WRAPPED_PROP_AUTO_IMPL(ImGuiStyle, WindowRounding);
	WRAPPED_PROP_AUTO_IMPL(ImGuiStyle, WindowBorderSize);
	WRAPPED_PROP_UDT_IMPL(ImGuiStyle, ImVec2, WindowMinSize);
	WRAPPED_PROP_UDT_IMPL(ImGuiStyle, ImVec2, WindowTitleAlign);
	WRAPPED_PROP_UDT_IMPL(ImGuiStyle, ImGuiDir, WindowMenuButtonPosition);
	WRAPPED_PROP_AUTO_IMPL(ImGuiStyle, ChildRounding);
	WRAPPED_PROP_AUTO_IMPL(ImGuiStyle, ChildBorderSize);
	WRAPPED_PROP_AUTO_IMPL(ImGuiStyle, PopupRounding);
	WRAPPED_PROP_AUTO_IMPL(ImGuiStyle, PopupBorderSize);
	WRAPPED_PROP_UDT_IMPL(ImGuiStyle, ImVec2, FramePadding);
	WRAPPED_PROP_AUTO_IMPL(ImGuiStyle, FrameRounding);
	WRAPPED_PROP_AUTO_IMPL(ImGuiStyle, FrameBorderSize);
	WRAPPED_PROP_UDT_IMPL(ImGuiStyle, ImVec2, ItemSpacing);
	WRAPPED_PROP_UDT_IMPL(ImGuiStyle, ImVec2, ItemInnerSpacing);
	WRAPPED_PROP_UDT_IMPL(ImGuiStyle, ImVec2, TouchExtraPadding);
	WRAPPED_PROP_AUTO_IMPL(ImGuiStyle, IndentSpacing);
	WRAPPED_PROP_AUTO_IMPL(ImGuiStyle, ColumnsMinSpacing);
	WRAPPED_PROP_AUTO_IMPL(ImGuiStyle, ScrollbarSize);
	WRAPPED_PROP_AUTO_IMPL(ImGuiStyle, ScrollbarRounding);
	WRAPPED_PROP_AUTO_IMPL(ImGuiStyle, GrabMinSize);
	WRAPPED_PROP_AUTO_IMPL(ImGuiStyle, GrabRounding);
	WRAPPED_PROP_AUTO_IMPL(ImGuiStyle, TabRounding);
	WRAPPED_PROP_AUTO_IMPL(ImGuiStyle, TabBorderSize);
	WRAPPED_PROP_UDT_IMPL(ImGuiStyle, ImGuiDir, ColorButtonPosition);
	WRAPPED_PROP_UDT_IMPL(ImGuiStyle, ImVec2, ButtonTextAlign);
	WRAPPED_PROP_UDT_IMPL(ImGuiStyle, ImVec2, SelectableTextAlign);
	WRAPPED_PROP_UDT_IMPL(ImGuiStyle, ImVec2, DisplayWindowPadding);
	WRAPPED_PROP_UDT_IMPL(ImGuiStyle, ImVec2, DisplaySafeAreaPadding);
	WRAPPED_PROP_AUTO_IMPL(ImGuiStyle, MouseCursorScale);
	WRAPPED_PROP_AUTO_IMPL(ImGuiStyle, AntiAliasedLines);
	WRAPPED_PROP_AUTO_IMPL(ImGuiStyle, AntiAliasedFill);
	WRAPPED_PROP_AUTO_IMPL(ImGuiStyle, CurveTessellationTol);
	WRAPPED_PROP_INDEX_IMPL(ImGuiStyle, ImVec4, int, Colors);

	void ImGuiStyle::ScaleAllSizes(float scale_factor)
	{
		_handle->ScaleAllSizes(scale_factor);
	}
}