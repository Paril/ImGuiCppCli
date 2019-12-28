#include "ImGuiStorage.h"

namespace ImGuiCppCli
{
	void ImGuiStorage::Clear()
	{
		_handle->Clear();
	}

	int ImGuiStorage::GetInt(ImGuiID key, int default_val)
	{
		return _handle->GetInt(key, default_val);
	}

	int ImGuiStorage::GetInt(ImGuiID key)
	{
		return _handle->GetInt(key);
	}

	void ImGuiStorage::SetInt(ImGuiID key, int val)
	{
		_handle->SetInt(key, val);
	}

	bool ImGuiStorage::GetBool(ImGuiID key, bool default_val)
	{
		return _handle->GetBool(key, default_val);
	}

	bool ImGuiStorage::GetBool(ImGuiID key)
	{
		return _handle->GetBool(key);
	}

	void ImGuiStorage::SetBool(ImGuiID key, bool val)
	{
		_handle->SetBool(key, val);
	}

	float ImGuiStorage::GetFloat(ImGuiID key, float default_val)
	{
		return _handle->GetFloat(key, default_val);
	}

	float ImGuiStorage::GetFloat(ImGuiID key)
	{
		return _handle->GetFloat(key);
	}

	void ImGuiStorage::SetFloat(ImGuiID key, float val)
	{
		_handle->SetFloat(key, val);
	}

	IntPtr ImGuiStorage::GetVoidPtr(ImGuiID key)
	{
		return (IntPtr)_handle->GetVoidPtr(key);
	}

	void ImGuiStorage::SetVoidPtr(ImGuiID key, IntPtr val)
	{
		_handle->SetVoidPtr(key, (void*)val);
	}

	void ImGuiStorage::SetAllInt(int val)
	{
		_handle->SetAllInt(val);
	}

	void ImGuiStorage::BuildSortByKey()
	{
		_handle->BuildSortByKey();
	}
}