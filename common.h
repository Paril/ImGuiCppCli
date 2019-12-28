#pragma once

#include <cstddef>
#include <cinttypes>
#include <type_traits>

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace System::Runtime::InteropServices;

#pragma managed(push, off)
#include "imgui/imgui.h"
#pragma managed(pop)

#include "macros.h"

namespace ImGuiCppCli
{
	public interface class IEncodableString
	{
		property ::String^ String
		{
			::String^ get();
		}

		property Span<char> Bytes
		{
			Span<char> get();
		}

		property ::Encoding^ Encoding
		{
			::Encoding^ get();
		}
	};

	public value class ImImmutableString : IEncodableString
	{
		::Encoding^ _encoding;
		::String^ _string;
		const char* _ptr;
		int _len;

	internal:
		ImImmutableString(const char* ptr);
		ImImmutableString(::Encoding^ encoding, const char* ptr);
		ImImmutableString(::Encoding^ encoding, const char* ptr, int len);
		ImImmutableString(::Encoding^ encoding, ::String^ v, const char* ptr, int len);

	public:
		property ::String^ String
		{
			virtual ::String^ get() sealed;
		}

		property Span<char> Bytes
		{
			virtual Span<char> get() sealed;
		}

		property ::Encoding^ Encoding
		{
			virtual ::Encoding^ get() sealed;
		}
	};

	public ref class ImString : IEncodableString
	{
	internal:
		::Encoding^ _encoding;
		::String^ _string;
		::ImVector<char>* _bytes;
		bool _bytes_dirty;

		property ::ImVector<char>* Vector
		{
			::ImVector<char>* get() { return _bytes; }
		}

		ImString(const char* ptr, int len);
		ImString(::Encoding^ encoding, const char* ptr, int len);
		ImString(const char* ptr);
		ImString(::Encoding^ encoding, const char* ptr);
		template<int T>
		ImString(const char(&ptr)[T]);
		template<int T>
		ImString(::Encoding^ encoding, const char(&ptr)[T]);
		!ImString();
		~ImString() { this->!ImString(); }

	public:
		property ::String^ String
		{
			virtual ::String^ get() sealed;
			void set(::String^ value);
		}

		property Span<char> Bytes
		{
			virtual Span<char> get() sealed;
		}

		property Encoding^ Encoding
		{
			virtual ::Encoding^ get() sealed;
			void set(::Encoding^ value);
		}

		ImString();
		ImString(::Encoding^ encoding);
		ImString(::String^ string);
		ImString(::String^ string, ::Encoding^ encoding);
		ImString(array<unsigned char>^ bytes);
		ImString(array<unsigned char>^ bytes, ::Encoding^ encoding);

		void Resize(int capacity);

		static operator ::String^ (ImString^ str)
		{
			return str->String;
		}

		static operator ImString^ (::String^ str)
		{
			return gcnew ImString(str, ::Encoding::UTF8);
		}
	};

	using BaseEnumerable = System::Collections::IEnumerable;
	using BaseEnumerator = System::Collections::IEnumerator;
	using ImTextureID = System::IntPtr;
}

#include "ImVector.h"