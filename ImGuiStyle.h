#pragma once

#include "common.h"
#include "ImVec2.h"
#include "ImVec4.h"
#include "ImGuiDir.h"

using OGImGuiStyle = ::ImGuiStyle;

namespace ImGuiCppCli
{
	public ref struct ImGuiStyle
	{
	internal:
		native_struct<OGImGuiStyle> _handle;

		ImGuiStyle(OGImGuiStyle* ptr);

	public:
		ImGuiStyle();
		ImGuiStyle(ImGuiStyle^ style);

		WRAPPED_PROP_AUTO_DECL(Alpha);
		WRAPPED_PROP_UDT_DECL(ImVec2, WindowPadding);
		WRAPPED_PROP_AUTO_DECL(WindowRounding);
		WRAPPED_PROP_AUTO_DECL(WindowBorderSize);
		WRAPPED_PROP_UDT_DECL(ImVec2, WindowMinSize);
		WRAPPED_PROP_UDT_DECL(ImVec2, WindowTitleAlign);
		WRAPPED_PROP_UDT_DECL(ImGuiDir, WindowMenuButtonPosition);
		WRAPPED_PROP_AUTO_DECL(ChildRounding);
		WRAPPED_PROP_AUTO_DECL(ChildBorderSize);
		WRAPPED_PROP_AUTO_DECL(PopupRounding);
		WRAPPED_PROP_AUTO_DECL(PopupBorderSize);
		WRAPPED_PROP_UDT_DECL(ImVec2, FramePadding);
		WRAPPED_PROP_AUTO_DECL(FrameRounding);
		WRAPPED_PROP_AUTO_DECL(FrameBorderSize);
		WRAPPED_PROP_UDT_DECL(ImVec2, ItemSpacing);
		WRAPPED_PROP_UDT_DECL(ImVec2, ItemInnerSpacing);
		WRAPPED_PROP_UDT_DECL(ImVec2, TouchExtraPadding);
		WRAPPED_PROP_AUTO_DECL(IndentSpacing);
		WRAPPED_PROP_AUTO_DECL(ColumnsMinSpacing);
		WRAPPED_PROP_AUTO_DECL(ScrollbarSize);
		WRAPPED_PROP_AUTO_DECL(ScrollbarRounding);
		WRAPPED_PROP_AUTO_DECL(GrabMinSize);
		WRAPPED_PROP_AUTO_DECL(GrabRounding);
		WRAPPED_PROP_AUTO_DECL(TabRounding);
		WRAPPED_PROP_AUTO_DECL(TabBorderSize);
		WRAPPED_PROP_UDT_DECL(ImGuiDir, ColorButtonPosition);
		WRAPPED_PROP_UDT_DECL(ImVec2, ButtonTextAlign);
		WRAPPED_PROP_UDT_DECL(ImVec2, SelectableTextAlign);
		WRAPPED_PROP_UDT_DECL(ImVec2, DisplayWindowPadding);
		WRAPPED_PROP_UDT_DECL(ImVec2, DisplaySafeAreaPadding);
		WRAPPED_PROP_AUTO_DECL(MouseCursorScale);
		WRAPPED_PROP_AUTO_DECL(AntiAliasedLines);
		WRAPPED_PROP_AUTO_DECL(AntiAliasedFill);
		WRAPPED_PROP_AUTO_DECL(CurveTessellationTol);
		WRAPPED_PROP_INDEX_DECL(ImVec4, int, Colors);

		void ScaleAllSizes(float scale_factor);
	};
}