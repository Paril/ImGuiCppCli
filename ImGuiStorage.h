#pragma once

#include "common.h"
#include "ImGuiConfigFlags.h"
#include "ImGuiBackendFlags.h"
#include "ImVec2.h"

using OGImGuiStorage = ::ImGuiStorage;

namespace ImGuiCppCli
{
	public value struct ImGuiStorage
	{
	internal:
		OGImGuiStorage* _handle;

		ImGuiStorage(OGImGuiStorage* handle) :
			_handle(handle)
		{
		}

	public:
		void Clear();

		int GetInt(ImGuiID key, int default_val);
		int GetInt(ImGuiID key);
		void SetInt(ImGuiID key, int val);
		bool GetBool(ImGuiID key, bool default_val);
		bool GetBool(ImGuiID key);
		void SetBool(ImGuiID key, bool val);
		float GetFloat(ImGuiID key, float default_val);
		float GetFloat(ImGuiID key);
		void SetFloat(ImGuiID key, float val);
		IntPtr GetVoidPtr(ImGuiID key);
		void SetVoidPtr(ImGuiID key, IntPtr val);

		void SetAllInt(int val);
		void BuildSortByKey();
	};
}