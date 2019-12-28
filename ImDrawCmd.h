#pragma once

#include "common.h"
#include "ImVec4.h"

namespace ImGuiCppCli
{
	value struct ImDrawList;
	value struct ImDrawCmd;

	public delegate void ImDrawCallback(ImDrawList% parent_list, ImDrawCmd% cmd);

	[StructLayout(LayoutKind::Sequential)]
	public value struct ImDrawCmd
	{
		uint32_t	ElemCount;
		ImVec4		ClipRect;
		ImTextureID	TextureId;
		uint32_t	VtxOffset;
		uint32_t	IdxOffset;

	private:
		IntPtr		UserCallback_;

	public:
		IntPtr		UserCallbackData;

		property ImDrawCallback^ UserCallback
		{
			ImDrawCallback^ get();
		}
	};
}