#include "ImGuiIO.h"
#include "ImFont.h"
#include "ImFontAtlas.h"

namespace ImGuiCppCli
{
	ImGuiIO::ImGuiIO(OGImGuiIO* handle) :
		_handle(handle)
	{
		WRAPPED_CSTR_INIT(IniFilename);
		WRAPPED_CSTR_INIT(LogFilename);
		WRAPPED_CSTR_INIT(BackendPlatformName);
		WRAPPED_CSTR_INIT(BackendRendererName);

		_self = GCHandle::Alloc(this, GCHandleType::Normal);
		_handle->ClipboardUserData = GCHandle::ToIntPtr(_self).ToPointer();
	}

	ImGuiIO::~ImGuiIO()
	{
		WRAPPED_CSTR_FREE(IniFilename);
		WRAPPED_CSTR_FREE(LogFilename);
		WRAPPED_CSTR_FREE(BackendPlatformName);
		WRAPPED_CSTR_FREE(BackendRendererName);

		if (_clipboard)
		{
			delete[] _clipboard;
			_clipboard = nullptr;
		}

		_self.Free();
	}

	WRAPPED_PROP_UDT_IMPL(ImGuiIO, ImGuiConfigFlags, ConfigFlags);
	WRAPPED_PROP_UDT_IMPL(ImGuiIO, ImGuiBackendFlags, BackendFlags);
	WRAPPED_PROP_UDT_IMPL(ImGuiIO, ImVec2, DisplaySize);
	WRAPPED_PROP_AUTO_IMPL(ImGuiIO, DeltaTime);
	WRAPPED_PROP_AUTO_IMPL(ImGuiIO, IniSavingRate);
	WRAPPED_PROP_STR_IMPL(ImGuiIO, IniFilename);
	WRAPPED_PROP_STR_IMPL(ImGuiIO, LogFilename);
	WRAPPED_PROP_AUTO_IMPL(ImGuiIO, MouseDoubleClickTime);
	WRAPPED_PROP_AUTO_IMPL(ImGuiIO, MouseDoubleClickMaxDist);
	WRAPPED_PROP_AUTO_IMPL(ImGuiIO, MouseDragThreshold);
	WRAPPED_PROP_INDEX_AUTO_IMPL(ImGuiIO, ImGuiKey, KeyMap);
	WRAPPED_PROP_AUTO_IMPL(ImGuiIO, KeyRepeatDelay);
	WRAPPED_PROP_AUTO_IMPL(ImGuiIO, KeyRepeatRate);

	WRAPPED_PROP_HANDLE_IMPL(ImGuiIO, ImFontAtlas, OGImFontAtlas, Fonts);
	WRAPPED_PROP_AUTO_IMPL(ImGuiIO, FontGlobalScale);
	WRAPPED_PROP_AUTO_IMPL(ImGuiIO, FontAllowUserScaling);
	WRAPPED_PROP_HANDLE_IMPL(ImGuiIO, ImFont, OGImFont, FontDefault);
	WRAPPED_PROP_UDT_IMPL(ImGuiIO, ImVec2, DisplayFramebufferScale);

	WRAPPED_PROP_AUTO_IMPL(ImGuiIO, MouseDrawCursor);
	WRAPPED_PROP_AUTO_IMPL(ImGuiIO, ConfigMacOSXBehaviors);
	WRAPPED_PROP_AUTO_IMPL(ImGuiIO, ConfigInputTextCursorBlink);
	WRAPPED_PROP_AUTO_IMPL(ImGuiIO, ConfigWindowsResizeFromEdges);
	WRAPPED_PROP_AUTO_IMPL(ImGuiIO, ConfigWindowsMoveFromTitleBarOnly);
	WRAPPED_PROP_AUTO_IMPL(ImGuiIO, ConfigWindowsMemoryCompactTimer);

	WRAPPED_PROP_STR_IMPL(ImGuiIO, BackendPlatformName);
	WRAPPED_PROP_STR_IMPL(ImGuiIO, BackendRendererName);

	static const char* GetClipboardTextFn_internal(void* user_data)
	{
		ImGuiIO^ io = (ImGuiIO^) GCHandle::FromIntPtr((IntPtr)user_data).Target;

		if (io->_clipboard)
			delete[] io->_clipboard;

		auto clipboard = io->_GetClipboardTextFn();
		IMSTR_DECODE_TEMP(clipboard);
		io->_clipboard = new char(clipboard_bytes.Length + 1);
		memcpy(io->_clipboard, clipboard_cstr, clipboard_bytes.Length);
		io->_clipboard[clipboard_bytes.Length] = 0;

		return io->_clipboard;
	}

	static void SetClipboardTextFn_internal(void* user_data, const char* string)
	{
		ImGuiIO^ io = (ImGuiIO^)GCHandle::FromIntPtr((IntPtr)user_data).Target;
		io->_SetClipboardTextFn(gcnew ImString(Encoding::UTF8, string));
	}

	GetClipboardTextDelegate^ ImGuiIO::GetClipboardTextFn::get()
	{
		return _GetClipboardTextFn;
	}
	void ImGuiIO::GetClipboardTextFn::set(GetClipboardTextDelegate^ value)
	{
		_GetClipboardTextFn = value;
		_handle->GetClipboardTextFn = value ? GetClipboardTextFn_internal : nullptr;
	}

	SetClipboardTextDelegate^ ImGuiIO::SetClipboardTextFn::get()
	{
		return _SetClipboardTextFn;
	}
	void ImGuiIO::SetClipboardTextFn::set(SetClipboardTextDelegate^ value)
	{
		_SetClipboardTextFn = value;
		_handle->SetClipboardTextFn = value ? SetClipboardTextFn_internal : nullptr;
	}

	ImeSetInputScreenPosDelegate^ ImGuiIO::ImeSetInputScreenPosFn::get()
	{
		return _ImeSetInputScreenPosFn;
	}
	void ImGuiIO::ImeSetInputScreenPosFn::set(ImeSetInputScreenPosDelegate^ value)
	{
		_ImeSetInputScreenPosFn = value;
		_handle->ImeSetInputScreenPosFn = value ? (decltype(_handle->ImeSetInputScreenPosFn))Marshal::GetFunctionPointerForDelegate(_ImeSetInputScreenPosFn).ToPointer() : nullptr;
	}

	//ImeSetInputScreenPosFn
	WRAPPED_PROP_CAST_IMPL(ImGuiIO, IntPtr, void*, ImeWindowHandle);

	WRAPPED_PROP_UDT_IMPL(ImGuiIO, ImVec2, MousePos);
	WRAPPED_PROP_INDEX_AUTO_IMPL(ImGuiIO, int, MouseDown);
	WRAPPED_PROP_AUTO_IMPL(ImGuiIO, MouseWheel);
	WRAPPED_PROP_AUTO_IMPL(ImGuiIO, MouseWheelH);
	WRAPPED_PROP_AUTO_IMPL(ImGuiIO, KeyCtrl);
	WRAPPED_PROP_AUTO_IMPL(ImGuiIO, KeyShift);
	WRAPPED_PROP_AUTO_IMPL(ImGuiIO, KeyAlt);
	WRAPPED_PROP_AUTO_IMPL(ImGuiIO, KeySuper);
	WRAPPED_PROP_INDEX_AUTO_IMPL(ImGuiIO, int, KeysDown);
	WRAPPED_PROP_INDEX_AUTO_IMPL(ImGuiIO, int, NavInputs);

	void ImGuiIO::AddInputCharacter(uint32_t c) { _handle->AddInputCharacter(c); }
	void ImGuiIO::AddInputCharactersUTF8(array<uint8_t>^ str)
	{
		ARRAY_PIN_TYPE_PTR(uint8_t, const char, str);
		_handle->AddInputCharactersUTF8(str_ptr);
	}
	void ImGuiIO::ClearInputCharacters() { _handle->ClearInputCharacters(); }

	WRAPPED_PROP_AUTO_IMPL(ImGuiIO, WantCaptureMouse);
	WRAPPED_PROP_AUTO_IMPL(ImGuiIO, WantCaptureKeyboard);
	WRAPPED_PROP_AUTO_IMPL(ImGuiIO, WantTextInput);
	WRAPPED_PROP_AUTO_IMPL(ImGuiIO, WantSetMousePos);
	WRAPPED_PROP_AUTO_IMPL(ImGuiIO, WantSaveIniSettings);
	WRAPPED_PROP_AUTO_IMPL(ImGuiIO, NavActive);
	WRAPPED_PROP_AUTO_IMPL(ImGuiIO, NavVisible);
	WRAPPED_PROP_AUTO_IMPL(ImGuiIO, Framerate);
	WRAPPED_PROP_AUTO_IMPL(ImGuiIO, MetricsRenderVertices);
	WRAPPED_PROP_AUTO_IMPL(ImGuiIO, MetricsRenderIndices);
	WRAPPED_PROP_AUTO_IMPL(ImGuiIO, MetricsRenderWindows);
	WRAPPED_PROP_AUTO_IMPL(ImGuiIO, MetricsActiveWindows);
	WRAPPED_PROP_AUTO_IMPL(ImGuiIO, MetricsActiveAllocations);
	WRAPPED_PROP_CAST_IMPL(ImGuiIO, ImVec2, OGImVec2, MouseDelta);
}