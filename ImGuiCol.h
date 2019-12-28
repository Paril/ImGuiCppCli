#pragma once
#include "common.h"

using OGImGuiCol = ::ImGuiCol;

namespace ImGuiCppCli
{
#define WRAPPED_ENUM ImGuiCol
	public enum class WRAPPED_ENUM
	{
		WRAP_ENUM(Text),
		WRAP_ENUM(TextDisabled),
		WRAP_ENUM(WindowBg),
		WRAP_ENUM(ChildBg),
		WRAP_ENUM(PopupBg),
		WRAP_ENUM(Border),
		WRAP_ENUM(BorderShadow),
		WRAP_ENUM(FrameBg),
		WRAP_ENUM(FrameBgHovered),
		WRAP_ENUM(FrameBgActive),
		WRAP_ENUM(TitleBg),
		WRAP_ENUM(TitleBgActive),
		WRAP_ENUM(TitleBgCollapsed),
		WRAP_ENUM(MenuBarBg),
		WRAP_ENUM(ScrollbarBg),
		WRAP_ENUM(ScrollbarGrab),
		WRAP_ENUM(ScrollbarGrabHovered),
		WRAP_ENUM(ScrollbarGrabActive),
		WRAP_ENUM(CheckMark),
		WRAP_ENUM(SliderGrab),
		WRAP_ENUM(SliderGrabActive),
		WRAP_ENUM(Button),
		WRAP_ENUM(ButtonHovered),
		WRAP_ENUM(ButtonActive),
		WRAP_ENUM(Header),
		WRAP_ENUM(HeaderHovered),
		WRAP_ENUM(HeaderActive),
		WRAP_ENUM(Separator),
		WRAP_ENUM(SeparatorHovered),
		WRAP_ENUM(SeparatorActive),
		WRAP_ENUM(ResizeGrip),
		WRAP_ENUM(ResizeGripHovered),
		WRAP_ENUM(ResizeGripActive),
		WRAP_ENUM(Tab),
		WRAP_ENUM(TabHovered),
		WRAP_ENUM(TabActive),
		WRAP_ENUM(TabUnfocused),
		WRAP_ENUM(TabUnfocusedActive),
		WRAP_ENUM(PlotLines),
		WRAP_ENUM(PlotLinesHovered),
		WRAP_ENUM(PlotHistogram),
		WRAP_ENUM(PlotHistogramHovered),
		WRAP_ENUM(TextSelectedBg),
		WRAP_ENUM(DragDropTarget),
		WRAP_ENUM(NavHighlight),
		WRAP_ENUM(NavWindowingHighlight),
		WRAP_ENUM(NavWindowingDimBg),
		WRAP_ENUM(ModalWindowDimBg),
		WRAP_ENUM(COUNT)
	};
#undef WRAPPED_ENUM
}