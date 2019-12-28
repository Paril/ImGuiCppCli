#pragma once

#include "common.h"

using OGImGuiColorEditFlags = ::ImGuiColorEditFlags;

namespace ImGuiCppCli
{
#define WRAPPED_ENUM ImGuiColorEditFlags
	[Flags]
	public enum class WRAPPED_ENUM
	{
		WRAP_ENUM(None),
		WRAP_ENUM(NoAlpha),
		WRAP_ENUM(NoPicker),
		WRAP_ENUM(NoOptions),
		WRAP_ENUM(NoSmallPreview),
		WRAP_ENUM(NoInputs),
		WRAP_ENUM(NoTooltip),
		WRAP_ENUM(NoLabel),
		WRAP_ENUM(NoSidePreview),
		WRAP_ENUM(NoDragDrop),

		WRAP_ENUM(AlphaBar),
		WRAP_ENUM(AlphaPreview),
		WRAP_ENUM(AlphaPreviewHalf),
		WRAP_ENUM(HDR),
		WRAP_ENUM(DisplayRGB),
		WRAP_ENUM(DisplayHSV),
		WRAP_ENUM(DisplayHex),
		WRAP_ENUM(Uint8),
		WRAP_ENUM(Float),
		WRAP_ENUM(PickerHueBar),
		WRAP_ENUM(PickerHueWheel),
		WRAP_ENUM(InputRGB),
		WRAP_ENUM(InputHSV)
	};
#undef WRAPPED_ENUM
}
