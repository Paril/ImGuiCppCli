#pragma once

#include "common.h"
#include "ImVec2.h"

using OGImDrawData = ::ImDrawData;

namespace ImGuiCppCli
{
	value struct ImDrawList;

	public value struct ImDrawData
	{
	internal:
		OGImDrawData* _handle;

		ImDrawData(OGImDrawData* handle);

	public:
		WRAPPED_PROP_AUTO_DECL(Valid);
		property IEnumerable<ImDrawList>^ CmdLists
		{
			IEnumerable<ImDrawList>^ get();
		}
		ImDrawList GetCmdList(int index);
		WRAPPED_PROP_AUTO_DECL(CmdListsCount);
		WRAPPED_PROP_AUTO_DECL(TotalIdxCount);
		WRAPPED_PROP_AUTO_DECL(TotalVtxCount);
		WRAPPED_PROP_UDT_DECL(ImVec2, DisplayPos);
		WRAPPED_PROP_UDT_DECL(ImVec2, DisplaySize);
		WRAPPED_PROP_UDT_DECL(ImVec2, FramebufferScale);

		void DeIndexAllBuffers();
		void ScaleClipRects(ImVec2 fb_scale);
	};
}