#include "common.h"

namespace ImGuiCppCli
{
	ImImmutableString::ImImmutableString(const char* ptr) :
		ImImmutableString(::Encoding::UTF8, ptr)
	{
	}

	ImImmutableString::ImImmutableString(::Encoding^ encoding, const char* ptr) :
		_encoding(encoding),
		_ptr(ptr),
		_len(ptr ? (int)strlen(ptr) : 0)
	{
	}

	ImImmutableString::ImImmutableString(::Encoding^ encoding, const char* ptr, int len) :
		_encoding(encoding),
		_ptr(ptr),
		_len(len)
	{
	}

	ImImmutableString::ImImmutableString(::Encoding^ encoding, ::String^ v, const char* ptr, int len) :
		_encoding(encoding),
		_string(v),
		_ptr(ptr),
		_len(len)
	{
	}

	String^ ImImmutableString::String::get()
	{
		if (!_string && !_ptr)
			return nullptr;

		if (!_string)
			_string = _encoding->GetString((unsigned char*)_ptr, _len);

		return _string;
	}

	Span<char> ImImmutableString::Bytes::get()
	{
		if (!_ptr)
			return Span<char>::Empty;

		return Span<char>((void*)_ptr, _len);
	}

	::Encoding^ ImImmutableString::Encoding::get()
	{
		return _encoding;
	}

	::String^ ImString::String::get()
	{
		if (!_string && !_bytes->Capacity)
			return ::String::Empty;

		if (!_string)
			_string = _encoding->GetString(MemoryMarshal::Cast<char, unsigned char>(Bytes));

		return _string;
	}

	void ImString::String::set(::String^ value)
	{
		_string = value;
		_bytes_dirty = true;
	}

	Span<char> ImString::Bytes::get()
	{
		if (!_bytes->Capacity)
			return Span<char>::Empty;

		if (_bytes_dirty)
		{
			_bytes->reserve(_encoding->GetMaxByteCount(_string->Length) + 1);
			_encoding->GetBytes(_string, Span<unsigned char>(_bytes->Data, _bytes->capacity()));
			_bytes->Data[_bytes->Size] = 0;
			_bytes_dirty = false;
		}

		return Span<char>(_bytes->Data, _bytes->capacity());
	}

	::Encoding^ ImString::Encoding::get()
	{
		return _encoding;
	}

	void ImString::Encoding::set(::Encoding^ value)
	{
		_encoding = value;
		_bytes_dirty = true;
	}

	ImString::ImString(const char* ptr, int len) :
		ImString(::Encoding::ASCII, ptr, len)
	{
	}

	ImString::ImString(::Encoding^ encoding, const char* ptr, int len) :
		_encoding(encoding),
		_string(encoding->GetString((unsigned char*)ptr, len))
	{
		_bytes = new ::ImVector<char>();
		_bytes->resize(len + 1);
		memcpy(_bytes->Data, ptr, len);
		_bytes->Data[len] = 0;
	}

	ImString::ImString(const char* ptr) :
		ImString(::Encoding::UTF8, ptr)
	{
	}

	ImString::ImString(::Encoding^ encoding, const char* ptr) :
		ImString(encoding, ptr, ptr ? (int)strlen(ptr) : 0)
	{
	}

	template<int T>
	ImString::ImString(const char(&ptr)[T]) :
		ImString(::Encoding::UTF8, ptr, T)
	{
	}

	template<int T>
	ImString::ImString(::Encoding^ encoding, const char(&ptr)[T]) :
		ImString(encoding, ptr, T)
	{
	}

	ImString::!ImString()
	{
		if (_bytes)
		{
			delete _bytes;
			_bytes = nullptr;
		}
	}

	ImString::ImString() :
		ImString(::Encoding::UTF8)
	{
	}

	ImString::ImString(::Encoding^ encoding) :
		_encoding(encoding)
	{
		_bytes = new ::ImVector<char>();
		_bytes->reserve(4);
		_bytes->Data[0] = 0;
	}

	ImString::ImString(::String^ string) :
		ImString(string, ::Encoding::UTF8)
	{
	}

	ImString::ImString(::String^ string, ::Encoding^ encoding) :
		_encoding(encoding),
		_string(string)
	{
		_bytes = new ::ImVector<char>();
		_bytes->reserve(_encoding->GetMaxByteCount(_string->Length));
		_bytes->Data[0] = 0;
	}

	ImString::ImString(array<unsigned char>^ bytes) :
		ImString(bytes, ::Encoding::UTF8)
	{
	}

	ImString::ImString(array<unsigned char>^ bytes, ::Encoding^ encoding) :
		_encoding(encoding)
	{
		_bytes = new ::ImVector<char>();
		_bytes->resize(bytes->Length);
		Marshal::Copy(bytes, 0, IntPtr(_bytes->Data), bytes->Length);
	}

	void ImString::Resize(int capacity)
	{
		_bytes->resize(capacity);
	}
}