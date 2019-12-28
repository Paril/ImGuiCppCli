# ImGuiCppCli
A C++/CLI binding for [ImGui](https://github.com/ocornut/imgui)

# Why?
I'm not a huge fan of the existing C# binding, and I wanted to do a few projects to see how well C++/CLI is supported with the new VS 2019 preview and .NET Core 3.1.

# Notes

## Strings
Strings in ImGui are UTF8, but in .NET they're UTF16. This posed a slight problem, and required an interesting solution: the ImString and ImImmutableString classes. ImImmutableString is a soft, value type wrapper to read-only strings exposed by ImGui, such as the version or SaveIniSettingsToMemory. They cache the String representation when requested, so that it is only converted once.

ImString, however, is a bit more complex. It had to be made a byref type since the string is mutable and stores a pointer to the bytes of the string which must be disposed of. It is an IDisposable vector-like class that stores a cached copy of both the String and UTF8 byte representation of a string. It can be used to read/write either the bytes or the String. If the bytes are modified, String should be set to nullptr and vice versa. This indicates to the class that the other end is dirty and must be regenerated. If String is re-assigned, it will automatically set the proper dirtiness flag.

ImString will implicitly convert from String, so you *can* use it like you would in C++, **but I don't recommend it**. The reason for this is that the strings must be converted from UTF16 to UTF8 every time, and this may be bad for performance. The strings should be cached statically/made readonly and those variables should be used instead, so that the cached byte data can be re-used.

## Changes from base
*Scalar and *ScalarN functions are mostly the same as you'd expect, however the ScalarN versions take Spans, which will implicitly convert from arrays. Overloads are used instead of optional values as C++/CLI doesn't support optional parameters.

All of the varargs functions are gone, since C# does string formatting already.

Some functions (Color*3 and Color*4 mainly) take a Span but do not enforce length at runtime. Please be sure to only call these with the required amount of values.
