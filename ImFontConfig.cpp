#include "ImFontConfig.h"
#include "ImFont.h"
#include "ImGlyphRanges.h"
#include "ImFontGlyphRangesBuilder.h"

namespace ImGuiCppCli
{
	/*static*/ ImFontDataStorage^ ImFontDataStorage::Copy(const void* data, int size)
	{
		auto storage = New(size);
		memcpy(storage->_data, data, size);
		return storage;
	}

	/*static*/ ImFontDataStorage^ ImFontDataStorage::New(int size)
	{
		auto storage = gcnew ImFontDataStorage();
		storage->_data = new uint8_t[size];
		storage->_size = size;
		return storage;
	}

	/*static*/ ImFontDataStorage^ ImFontDataStorage::Create(ReadOnlySpan<uint8_t> data)
	{
		SPAN_GET_PTR(uint8_t, const uint8_t, data);
		return Copy(data_ptr, data.Length);
	}

	/*static*/ ImFontDataStorage^ ImFontDataStorage::Create(Span<uint8_t> data)
	{
		SPAN_GET_PTR(uint8_t, const uint8_t, data);
		return Copy(data_ptr, data.Length);
	}

	/*static*/ ImFontDataStorage^ ImFontDataStorage::Create(ReadOnlyMemory<uint8_t> data)
	{
		auto pin = data.Pin();
		return Copy(pin.Pointer, data.Length);
	}

	/*static*/ ImFontDataStorage^ ImFontDataStorage::Create(Memory<uint8_t> data)
	{
		auto pin = data.Pin();
		return Copy(pin.Pointer, data.Length);
	}

	/*static*/ ImFontDataStorage^ ImFontDataStorage::Create(array<uint8_t>^ data)
	{
		ARRAY_PIN_PTR(uint8_t, data);
		return Copy(data_ptr, data->Length);
	}

	/*static*/ ImFontDataStorage^ ImFontDataStorage::Create(Stream^ stream)
	{
		if (!stream->CanRead || stream->Length == 0)
			throw gcnew ArgumentException();

		auto storage = New((int)stream->Length);
		auto span = Span<uint8_t>(storage->_data, storage->_size);
		int total = 0;

		while (total != storage->_size)
		{
			int read = stream->Read(span);
			total += read;

			span = span.Slice(read);
		}

		return storage;
	}


	/*static*/ ImGlyphRangeStorage^ ImGlyphRangeStorage::Copy(const void* data, int size)
	{
		auto storage = New(size);
		memcpy(storage->_data, data, size);
		return storage;
	}

	/*static*/ ImGlyphRangeStorage^ ImGlyphRangeStorage::New(int size)
	{
		auto storage = gcnew ImGlyphRangeStorage();
		storage->_data = new uint8_t[size];
		storage->_size = size;
		return storage;
	}

	/*static*/ ImGlyphRangeStorage^ ImGlyphRangeStorage::Create(ImGlyphRanges ranges)
	{
		auto sizeInBytes = (ranges._numRanges + 1) * 2;
		return Copy(ranges._ranges, sizeInBytes);
	}

	/*static*/ ImGlyphRangeStorage^ ImGlyphRangeStorage::Create(ImFontGlyphRangesBuilder^ builder)
	{
		static ::ImVector<ImWchar> ranges;
		builder->BuildRanges(&ranges);

		auto sizeInBytes = (ranges.size() + 1) * 2;
		return Copy(ranges.Data, sizeInBytes);
	}


	ImFontConfig::ImFontConfig()
	{
		_handle = new OGImFontConfig();
		_handle->FontDataOwnedByAtlas = false;
	}

	ImFontConfig::ImFontConfig(const OGImFontConfig* handle)
	{
		_handle = (OGImFontConfig*) handle;
	}

	ImFontConfig::ImFontConfig(ImFontConfig^ copy) :
		ImFontConfig()
	{
		memcpy(_handle, copy->_handle, sizeof(*_handle));
		SetFont(copy);
		SetGlyphRanges(copy);
	}

	ImFontConfig::~ImFontConfig()
	{
		ClearFont();
		ClearRanges();
		delete _handle;
	}

	void ImFontConfig::ClearFont()
	{
		_handle->FontData = nullptr;
		_handle->FontDataSize = 0;
		_font_data = nullptr;
	}

	void ImFontConfig::ClearRanges()
	{
		_handle->GlyphRanges = nullptr;
		_glyph_data = nullptr;
	}

	void ImFontConfig::SetFont(ImFontConfig^ copy)
	{
		ClearFont();

		_handle->FontData = copy->_handle->FontData;
		_handle->FontDataSize = copy->_handle->FontDataSize;
		_font_data = copy->_font_data;
	}

	void ImFontConfig::SetFont(ImFontDataStorage^ storage)
	{
		ClearFont();

		_handle->FontData = storage->_data;
		_handle->FontDataSize = storage->_size;
		_font_data = storage;
	}

	void ImFontConfig::SetGlyphRanges(ImFontConfig^ copy)
	{
		ClearRanges();

		_handle->GlyphRanges = copy->_handle->GlyphRanges;
		_glyph_data = copy->_glyph_data;
	}

	void ImFontConfig::SetGlyphRanges(ImGlyphRangeStorage^ storage)
	{
		ClearFont();

		_handle->GlyphRanges = (ImWchar*) storage->_data;
		_glyph_data = storage;
	}


	WRAPPED_PROP_AUTO_IMPL(ImFontConfig, FontDataSize);
	WRAPPED_PROP_AUTO_IMPL(ImFontConfig, FontNo);
	WRAPPED_PROP_AUTO_IMPL(ImFontConfig, SizePixels);
	WRAPPED_PROP_AUTO_IMPL(ImFontConfig, OversampleH);
	WRAPPED_PROP_AUTO_IMPL(ImFontConfig, OversampleV);
	WRAPPED_PROP_AUTO_IMPL(ImFontConfig, PixelSnapH);
	WRAPPED_PROP_UDT_IMPL(ImFontConfig, ImVec2, GlyphExtraSpacing);
	WRAPPED_PROP_UDT_IMPL(ImFontConfig, ImVec2, GlyphOffset);
	ImGlyphRanges ImFontConfig::GlyphRanges::get()
	{
		return ImGlyphRanges(_handle->GlyphRanges);
	}
	WRAPPED_PROP_AUTO_IMPL(ImFontConfig, GlyphMinAdvanceX);
	WRAPPED_PROP_AUTO_IMPL(ImFontConfig, GlyphMaxAdvanceX);
	WRAPPED_PROP_AUTO_IMPL(ImFontConfig, MergeMode);
	WRAPPED_PROP_AUTO_IMPL(ImFontConfig, RasterizerFlags);
	WRAPPED_PROP_AUTO_IMPL(ImFontConfig, RasterizerMultiply);
	WRAPPED_PROP_AUTO_IMPL(ImFontConfig, EllipsisChar);

	ImString^ ImFontConfig::Name::get()
	{
		return gcnew ImString(_handle->Name);
	}

	void ImFontConfig::Name::set(ImString^ value)
	{
		IMSTR_DECODE_TEMP(value);
		auto nul_pos = Math::Min(value_bytes.Length, (int)sizeof(_handle->Name) - 1);
		auto str_len = Math::Min(value_bytes.Length, (int)sizeof(_handle->Name));
		memcpy(_handle->Name, value_cstr, str_len);
		_handle->Name[nul_pos] = 0;
	}

	WRAPPED_PROP_HANDLE_IMPL(ImFontConfig, ImFont, OGImFont, DstFont);
}