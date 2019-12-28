#include "ImGuiPayload.h"

namespace ImGuiCppCli
{
	ImGuiPayload::ImGuiPayload(const OGImGuiPayload* handle) :
		_handle(handle)
	{
	}

	IntPtr ImGuiPayload::Data::get()
	{
		return (IntPtr)_handle->Data;
	}

	int ImGuiPayload::DataSize::get()
	{
		return _handle->DataSize;
	}

	bool ImGuiPayload::IsDataType(ImString^ type)
	{
		IMSTR_DECODE_TEMP(type);
		return _handle->IsDataType(type_cstr);
	}
	
	bool ImGuiPayload::IsPreview()
	{
		return _handle->IsPreview();
	}

	bool ImGuiPayload::IsDelivery()
	{
		return _handle->IsDelivery();
	}
}