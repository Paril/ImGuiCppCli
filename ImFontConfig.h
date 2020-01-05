#pragma once
#include <memory>

#include "common.h"
#include "ImVec2.h"

using namespace System::IO;
using namespace System::Buffers;

using OGImFontConfig = ::ImFontConfig;
using OGImFont = ::ImFont;

namespace ImGuiCppCli
{
	ref struct ImFont;
	ref class ImFontGlyphRangesBuilder;
	value struct ImGlyphRanges;

	public ref struct ImFontDataStorage
	{
	internal:
		void* _data;
		int _size;

		~ImFontDataStorage()
		{
			delete[] _data;
			_data = nullptr;
		}

		static ImFontDataStorage^ Copy(const void* data, int size);
		static ImFontDataStorage^ New(int size);

	public:
		static ImFontDataStorage^ Create(ReadOnlySpan<uint8_t> data);
		static ImFontDataStorage^ Create(Span<uint8_t> data);
		static ImFontDataStorage^ Create(ReadOnlyMemory<uint8_t> data);
		static ImFontDataStorage^ Create(Memory<uint8_t> data);
		static ImFontDataStorage^ Create(array<uint8_t>^ data);
		static ImFontDataStorage^ Create(Stream^ data);
	};

	public ref struct ImGlyphRangeStorage
	{
		void* _data;
		int _size;

		~ImGlyphRangeStorage()
		{
			delete[] _data;
			_data = nullptr;
		}

		static ImGlyphRangeStorage^ Copy(const void* data, int size);
		static ImGlyphRangeStorage^ New(int size);

	public:
		static ImGlyphRangeStorage^ Create(ImGlyphRanges ranges);
		static ImGlyphRangeStorage^ Create(ImFontGlyphRangesBuilder^ builder);
	};

	public ref struct ImFontConfig
	{
	internal:
		OGImFontConfig *_handle;
		ImFontDataStorage^ _font_data;
		ImGlyphRangeStorage^ _glyph_data;

		ImFontConfig(const OGImFontConfig* handle);

	public:
		ImFontConfig();

		ImFontConfig(ImFontConfig^ copy);

		~ImFontConfig();

		void ClearFont();

		void ClearRanges();

		void SetFont(ImFontConfig^ copy);

		void SetFont(ImFontDataStorage^ storage);

		void SetGlyphRanges(ImFontConfig^ copy);

		void SetGlyphRanges(ImGlyphRangeStorage^ builder);

		WRAPPED_PROP_AUTO_DECL(FontDataSize);
		WRAPPED_PROP_AUTO_DECL(FontNo);
		WRAPPED_PROP_AUTO_DECL(SizePixels);
		WRAPPED_PROP_AUTO_DECL(OversampleH);
		WRAPPED_PROP_AUTO_DECL(OversampleV);
		WRAPPED_PROP_AUTO_DECL(PixelSnapH);
		WRAPPED_PROP_UDT_DECL(ImVec2, GlyphExtraSpacing);
		WRAPPED_PROP_UDT_DECL(ImVec2, GlyphOffset);
		property ImGlyphRanges GlyphRanges
		{
			ImGlyphRanges get();
		}
		WRAPPED_PROP_AUTO_DECL(GlyphMinAdvanceX);
		WRAPPED_PROP_AUTO_DECL(GlyphMaxAdvanceX);
		WRAPPED_PROP_AUTO_DECL(MergeMode);
		WRAPPED_PROP_AUTO_DECL(RasterizerFlags);
		WRAPPED_PROP_AUTO_DECL(RasterizerMultiply);
		WRAPPED_PROP_AUTO_DECL(EllipsisChar);

		property ImString^ Name
		{
			ImString^ get();
			void set(ImString^ value);
		}

		WRAPPED_PROP_HANDLE_DECL(ImFont, OGImFont, DstFont);
	};
}