#pragma once

// HELPER MACROS
#undef WRAPPED_ENUM
#define WRAP_STR(x) x
#define WRAP_ENUM(name) \
	name = WRAP_STR(WRAPPED_ENUM) ## _ ## name

#define WRAP_HANDLE_OPERATOR	->

#define WRAPPED_PROP_DECL(type, prop) \
	property type prop \
	{ \
		type get(); \
		void set(type v); \
	}

#define WRAPPED_PROP_IMPL(class, type, prop) \
	type class::prop::get() { return _handle WRAP_HANDLE_OPERATOR prop; } \
	void class::prop::set(type v) { _handle WRAP_HANDLE_OPERATOR prop = v; }

#define WRAPPED_PROP_AUTO_DECL(prop) WRAPPED_PROP_DECL(decltype(_handle WRAP_HANDLE_OPERATOR prop), prop)

#define WRAPPED_PROP_AUTO_IMPL(class, prop) WRAPPED_PROP_IMPL(class, decltype(class::_handle WRAP_HANDLE_OPERATOR prop), prop)

#define WRAPPED_PROP_CAST_DECL(type, original_type, prop) \
	property type prop \
	{ \
		type get(); \
		void set(type v); \
	}

#define WRAPPED_PROP_CAST_IMPL(class, type, original_type, prop) \
	type class::prop::get() { return (type)_handle WRAP_HANDLE_OPERATOR prop; } \
	void class::prop::set(type v) { _handle WRAP_HANDLE_OPERATOR prop = (original_type)v; }

#define WRAPPED_PROP_UDT_DECL(type, prop) WRAPPED_PROP_CAST_DECL(type, OG ## type, prop)

#define WRAPPED_PROP_UDT_IMPL(class, type, prop) WRAPPED_PROP_CAST_IMPL(class, type, OG ## type, prop)

#define WRAPPED_PROP_HANDLE_DECL(type, original_type, prop) \
	property type^ prop \
	{ \
		type^ get(); \
		void set(type^ v); \
	}

#define WRAPPED_PROP_HANDLE_IMPL(class, type, original_type, prop) \
	type^ class::prop::get() { return gcnew type(_handle WRAP_HANDLE_OPERATOR prop); } \
	void class::prop::set(type^ v) { _handle WRAP_HANDLE_OPERATOR prop = v->_handle; }

#define WRAPPED_PROP_INDEX_DECL(type, key_type, prop) \
	type Get ## prop(key_type index); \
	void Set ## prop(key_type index, type value);

#define WRAPPED_PROP_INDEX_IMPL(class, type, key_type, prop) \
	type class::Get ## prop(key_type index) { return _handle WRAP_HANDLE_OPERATOR prop[(int)index]; } \
	void class::Set ## prop(key_type index, type value) { _handle WRAP_HANDLE_OPERATOR prop[(int)index] = value; }

#define WRAPPED_PROP_INDEX_AUTO_DECL(key_type, prop) \
	using prop ## _type = std::remove_reference<decltype(*_handle WRAP_HANDLE_OPERATOR prop)>::type; \
	WRAPPED_PROP_INDEX_DECL(prop ## _type, key_type, prop)

#define WRAPPED_PROP_INDEX_AUTO_IMPL(class, key_type, prop) \
	WRAPPED_PROP_INDEX_IMPL(class, class::prop ## _type, key_type, prop)

#define IMSTR_DECODE_TEMP(name) \
	auto name ## _bytes = name->Bytes; \
	pin_ptr<char> name ## _pinned; \
	if (name ## _bytes.Length) \
		name ## _pinned = &name ## _bytes[0]; \
	auto name ## _cstr = name ## _pinned ? (const char*)(&name ## _pinned[0]) : nullptr;

#define CSTR_DECODE_TEMP(name) \
	auto name ## _bytes = Encoding::UTF8->GetBytes(name); \
	pin_ptr<unsigned char> name ## _pinned; \
	if (name ## _bytes->Length) \
		name ## _pinned = &name ## _bytes[0]; \
	auto name ## _cstr = name ## _pinned ? (const char*)(&name ## _pinned[0]) : nullptr;

#define WRAPPED_CSTR_INIT(prop) \
	prop ## _default = _handle WRAP_HANDLE_OPERATOR prop; \
	prop ## _str = ImImmutableString(Encoding::UTF8, _handle WRAP_HANDLE_OPERATOR prop);

#define WRAPPED_CSTR_FREE(prop) \
	if (_handle WRAP_HANDLE_OPERATOR prop && _handle WRAP_HANDLE_OPERATOR prop != prop ## _default) \
	{ \
		delete[] _handle WRAP_HANDLE_OPERATOR prop; \
		_handle WRAP_HANDLE_OPERATOR prop = prop ## _default; \
		WRAPPED_CSTR_INIT(prop); \
	}

#define WRAPPED_PROP_CSTR_DECL(prop) \
	private: ImImmutableString prop ## _str; const char *prop ## _default; public: \
	property String^ prop \
	{ \
		String^ get(); \
		void set(String ^v); \
	}

#define WRAPPED_PROP_CSTR_IMPL(class, prop) \
	String^ class::prop::get() { return (prop ## _str).String; } \
	void class::prop::set(String ^v) \
	{ \
		WRAPPED_CSTR_FREE(prop); \
		if (v == nullptr) \
		{ \
			_handle WRAP_HANDLE_OPERATOR prop = nullptr; \
			return; \
		} \
		CSTR_DECODE_TEMP(v); \
		auto str = new char[v_bytes->Length + 1]; \
		memcpy(str, v_cstr, v_bytes->Length); \
		str[v_bytes->Length] = 0; \
		_handle WRAP_HANDLE_OPERATOR prop = str; \
		prop ## _str = ImImmutableString(Encoding::UTF8, v, str, v_bytes->Length); \
	}

#define WRAPPED_PROP_STR_DECL(prop) WRAPPED_PROP_CSTR_DECL(prop)

#define WRAPPED_PROP_STR_IMPL(class, prop) WRAPPED_PROP_CSTR_IMPL(class, prop)

// Thank you! https://blogs.msdn.microsoft.com/branbray/2005/07/20/some-notes-about-mixed-types/
using namespace System::Runtime::CompilerServices;
using namespace System::Runtime::InteropServices;
template<typename T, int size>
[UnsafeValueType]
[StructLayout(LayoutKind::Explicit, Size = (sizeof(T) * size))]
public value struct inline_array
{
private:
	[FieldOffset(0)]
	T dummy_item;

public:
	T% operator[](int index)
	{
		return *((&dummy_item) + index);
	}

	static operator interior_ptr<T>(inline_array<T, size>% ia)
	{
		return &ia.dummy_item;
	}
};

template<typename T>
ref class native_struct
{
	T* t;
	bool owned;

	void destroy()
	{
		if (!owned || t == nullptr)
			return;

		delete t;
		t = nullptr;
	}

	!native_struct()
	{
		destroy();
	}

	~native_struct()
	{
		destroy();
	}

public:
	native_struct() :
		t(new T),
		owned(true)
	{
	}

	native_struct(T* p) :
		t(p),
		owned(false)
	{
	}

	static T* operator&(native_struct% e) { return e.t; }
	T* operator->() { return t; }
};

#define SPAN_GET_PTR(type, ptr_type, name) \
	pin_ptr<type> name ## _pin = &MemoryMarshal::GetReference(name); \
	ptr_type* name ## _ptr = (ptr_type*)name ## _pin;

#define REF_PIN(type, ptr_type, name) \
	pin_ptr<type> name ## _pin = &name; \
	auto name ## _ptr = name ## _pin;

template <class _Ty>
struct remove_tracking
{
	using type = _Ty;
};

template <class _Ty>
struct remove_tracking<_Ty%>
{
	using type = _Ty;
};

#define REF_VAL_INIT(name) \
	remove_tracking<decltype(name)>::type out_ ## name = name;

#define REF_VAL_COPY(name) \
	name = out_ ## name;

#define OUT_VAL_INIT(name) \
	remove_tracking<decltype(name)>::type out_ ## name;

#define OUT_VAL_COPY(name) \
	REF_VAL_COPY(name)

#define ARRAY_PIN_TYPE_PTR(type, ptr_type, name) \
	pin_ptr<type> name ## _pin = &name[0]; \
	ptr_type* name ## _ptr = (ptr_type*)name ## _pin;

#define ARRAY_PIN_PTR(type, name) \
	pin_ptr<type> name ## _pin = &name[0]; \
	type* name ## _ptr = name ## _pin;

#define GET_CB_FUNC_PTR(name) \
	auto name ## _ptr = Marshal::GetFunctionPointerForDelegate(name).ToPointer();


// ImGui Specific
#define WRAPPED_PROP_VECTOR_READONLY_DECL(type, prop) \
	property ImVectorRef<type> prop \
	{ \
		ImVectorRef<type> get(); \
	}

#define WRAPPED_PROP_VECTOR_READONLY_IMPL(class, type, prop) \
	ImVectorRef<type> class::prop::get() \
	{ \
		return ImVectorRef<type>(reinterpret_cast<const OGImVector*>(&_handle WRAP_HANDLE_OPERATOR prop)); \
	}