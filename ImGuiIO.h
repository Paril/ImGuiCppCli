#pragma once

#include "common.h"
#include "ImGuiConfigFlags.h"
#include "ImGuiBackendFlags.h"
#include "ImVec2.h"
#include "ImGuiKey.h"

using OGImGuiIO = ::ImGuiIO;

namespace ImGuiCppCli
{
	ref struct ImFontAtlas;
	ref struct ImFont;

	public delegate ImString^ GetClipboardTextDelegate();
	public delegate void SetClipboardTextDelegate(ImString^ text);
	public delegate void ImeSetInputScreenPosDelegate(int x, int y);

	public ref class ImGuiIO
	{
	internal:
		OGImGuiIO* _handle;
		char* _clipboard;
		GCHandle _self;

		ImGuiIO(OGImGuiIO* handle);

		~ImGuiIO();

	public:
		WRAPPED_PROP_UDT_DECL(ImGuiConfigFlags, ConfigFlags);
		WRAPPED_PROP_UDT_DECL(ImGuiBackendFlags, BackendFlags);
		WRAPPED_PROP_UDT_DECL(ImVec2, DisplaySize);
		WRAPPED_PROP_AUTO_DECL(DeltaTime);
		WRAPPED_PROP_AUTO_DECL(IniSavingRate);
		WRAPPED_PROP_STR_DECL(IniFilename);
		WRAPPED_PROP_STR_DECL(LogFilename);
		WRAPPED_PROP_AUTO_DECL(MouseDoubleClickTime);
		WRAPPED_PROP_AUTO_DECL(MouseDoubleClickMaxDist);
		WRAPPED_PROP_AUTO_DECL(MouseDragThreshold);
		WRAPPED_PROP_INDEX_AUTO_DECL(ImGuiKey, KeyMap);
		WRAPPED_PROP_AUTO_DECL(KeyRepeatDelay);
		WRAPPED_PROP_AUTO_DECL(KeyRepeatRate);

		WRAPPED_PROP_HANDLE_DECL(ImFontAtlas, OGImFontAtlas, Fonts);
		WRAPPED_PROP_AUTO_DECL(FontGlobalScale);
		WRAPPED_PROP_AUTO_DECL(FontAllowUserScaling);
		WRAPPED_PROP_HANDLE_DECL(ImFont, OGImFont, FontDefault);
		WRAPPED_PROP_UDT_DECL(ImVec2, DisplayFramebufferScale);

		WRAPPED_PROP_AUTO_DECL(MouseDrawCursor);
		WRAPPED_PROP_AUTO_DECL(ConfigMacOSXBehaviors);
		WRAPPED_PROP_AUTO_DECL(ConfigInputTextCursorBlink);
		WRAPPED_PROP_AUTO_DECL(ConfigWindowsResizeFromEdges);
		WRAPPED_PROP_AUTO_DECL(ConfigWindowsMoveFromTitleBarOnly);
		WRAPPED_PROP_AUTO_DECL(ConfigWindowsMemoryCompactTimer);

		WRAPPED_PROP_STR_DECL(BackendPlatformName);
		WRAPPED_PROP_STR_DECL(BackendRendererName);

	internal:
		GetClipboardTextDelegate^ _GetClipboardTextFn;
	public:

		property GetClipboardTextDelegate^ GetClipboardTextFn
		{
			GetClipboardTextDelegate^ get();
			void set(GetClipboardTextDelegate^ value);
		}

	internal:
		SetClipboardTextDelegate^ _SetClipboardTextFn;
	public:
		property SetClipboardTextDelegate^ SetClipboardTextFn
		{
			SetClipboardTextDelegate^ get();
			void set(SetClipboardTextDelegate^ value);
		}

	internal:
		ImeSetInputScreenPosDelegate^ _ImeSetInputScreenPosFn;
	public:
		property ImeSetInputScreenPosDelegate^ ImeSetInputScreenPosFn
		{
			ImeSetInputScreenPosDelegate^ get();
			void set(ImeSetInputScreenPosDelegate^ value);
		}
		WRAPPED_PROP_CAST_DECL(IntPtr, void*, ImeWindowHandle);

		WRAPPED_PROP_UDT_DECL(ImVec2, MousePos);
		WRAPPED_PROP_INDEX_AUTO_DECL(int, MouseDown);
		WRAPPED_PROP_AUTO_DECL(MouseWheel);
		WRAPPED_PROP_AUTO_DECL(MouseWheelH);
		WRAPPED_PROP_AUTO_DECL(KeyCtrl);
		WRAPPED_PROP_AUTO_DECL(KeyShift);
		WRAPPED_PROP_AUTO_DECL(KeyAlt);
		WRAPPED_PROP_AUTO_DECL(KeySuper);
		WRAPPED_PROP_INDEX_AUTO_DECL(int, KeysDown);
		WRAPPED_PROP_INDEX_AUTO_DECL(int, NavInputs);

		void AddInputCharacter(uint32_t c);
		void AddInputCharactersUTF8(array<uint8_t>^ str);
		void ClearInputCharacters();

		WRAPPED_PROP_AUTO_DECL(WantCaptureMouse);
		WRAPPED_PROP_AUTO_DECL(WantCaptureKeyboard);
		WRAPPED_PROP_AUTO_DECL(WantTextInput);
		WRAPPED_PROP_AUTO_DECL(WantSetMousePos);
		WRAPPED_PROP_AUTO_DECL(WantSaveIniSettings);
		WRAPPED_PROP_AUTO_DECL(NavActive);
		WRAPPED_PROP_AUTO_DECL(NavVisible);
		WRAPPED_PROP_AUTO_DECL(Framerate);
		WRAPPED_PROP_AUTO_DECL(MetricsRenderVertices);
		WRAPPED_PROP_AUTO_DECL(MetricsRenderIndices);
		WRAPPED_PROP_AUTO_DECL(MetricsRenderWindows);
		WRAPPED_PROP_AUTO_DECL(MetricsActiveWindows);
		WRAPPED_PROP_AUTO_DECL(MetricsActiveAllocations);
		WRAPPED_PROP_CAST_DECL(ImVec2, OGImVec2, MouseDelta);
	};
}