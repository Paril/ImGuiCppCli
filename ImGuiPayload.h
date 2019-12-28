#pragma once

#include "common.h"

using OGImGuiPayload = ImGuiPayload;

namespace ImGuiCppCli
{
	public value struct ImGuiPayload
	{
	internal:
		const OGImGuiPayload* _handle;

		ImGuiPayload(const OGImGuiPayload* handle);

	public:
		property IntPtr Data
		{
			IntPtr get();
		}

		property int DataSize
		{
			int get();
		}

		bool IsDataType(ImString^ type);
		bool IsPreview();
		bool IsDelivery();
	};
}