#include "ImGui.h"
#include "ImGuiContext.h"
#include "ImFontAtlas.h"
#include "ImFont.h"
#include "ImGuiIO.h"
#include "ImDrawData.h"
#include "ImGuiStorage.h"
#include "ImGuiStyle.h"
#include "ImGuiPayload.h"

struct ImGuiContext { };

namespace ImGuiCppCli
{
	/*static*/ ImGuiContext ImGui::CreateContext(ImFontAtlas^ shared_font_atlas)
	{
		return ImGuiContext(::ImGui::CreateContext(shared_font_atlas ? shared_font_atlas->_handle : nullptr));
	}

	/*static*/ ImGuiContext ImGui::CreateContext()
	{
		return CreateContext(nullptr);
	}

	/*static*/ void ImGui::DestroyContext(ImGuiContext% ctx)
	{
		::ImGui::DestroyContext(ctx._handle);
	}

	/*static*/ void ImGui::DestroyContext()
	{
		::ImGui::DestroyContext();
	}

	/*static*/ void ImGui::SetCurrentContext(ImGuiContext% ctx)
	{
		::ImGui::SetCurrentContext(ctx._handle);
	}

	/*static*/ ImGuiIO^ ImGui::GetIO()
	{
		return gcnew ImGuiIO(&::ImGui::GetIO());
	}

	/*static*/ ImGuiStyle^ ImGui::GetStyle()
	{
		return gcnew ImGuiStyle(&::ImGui::GetStyle());
	}

	/*static*/ void ImGui::GetStyle(ImGuiStyle^ style)
	{
		auto ptr = &::ImGui::GetStyle();
		memcpy(&style->_handle, ptr, sizeof(*ptr));
	}

	/*static*/ void ImGui::NewFrame()
	{
		::ImGui::NewFrame();
	}

	/*static*/ void ImGui::EndFrame()
	{
		::ImGui::EndFrame();
	}

	/*static*/ void ImGui::Render()
	{
		::ImGui::Render();
	}

	/*static*/ ImDrawData ImGui::GetDrawData()
	{
		return ImDrawData(::ImGui::GetDrawData());
	}

	/*static*/ void ImGui::ShowDemoWindow(bool% open)
	{
		REF_VAL_INIT(open);
		::ImGui::ShowDemoWindow(&out_open);
		REF_VAL_COPY(open);
	}

	/*static*/ void ImGui::ShowAboutWindow(bool% open)
	{
		REF_VAL_INIT(open);
		::ImGui::ShowAboutWindow(&out_open);
		REF_VAL_COPY(open);
	}

	/*static*/ void ImGui::ShowMetricsWindow(bool% open)
	{
		REF_VAL_INIT(open);
		::ImGui::ShowMetricsWindow(&out_open);
		REF_VAL_COPY(open);
	}

	/*static*/ void ImGui::ShowStyleEditor(ImGuiStyle^ ref)
	{
		::ImGui::ShowStyleEditor(&ref->_handle);
	}

	/*static*/ void ImGui::ShowStyleEditor()
	{
		::ImGui::ShowStyleEditor();
	}

	/*static*/ bool ImGui::ShowStyleSelector(ImString^ label)
	{
		IMSTR_DECODE_TEMP(label);
		return ::ImGui::ShowStyleSelector(label_cstr);
	}

	/*static*/ void ImGui::ShowFontSelector(ImString^ label)
	{
		IMSTR_DECODE_TEMP(label);
		::ImGui::ShowStyleSelector(label_cstr);
	}

	/*static*/ void ImGui::ShowUserGuide() { ::ImGui::ShowUserGuide(); }

	/*static*/ ImString^ ImGui::GetVersion()
	{
		return gcnew ImString(::ImGui::GetVersion());
	}

	/*static*/ void ImGui::StyleColorsDark(ImGuiStyle^ style)
	{
		::ImGui::StyleColorsDark(&style->_handle);
	}

	/*static*/ void ImGui::StyleColorsDark()
	{
		::ImGui::StyleColorsDark();
	}

	/*static*/ void ImGui::StyleColorsClassic(ImGuiStyle^ style)
	{
		::ImGui::StyleColorsClassic(&style->_handle);
	}

	/*static*/ void ImGui::StyleColorsClassic()
	{
		::ImGui::StyleColorsClassic();
	}

	/*static*/ void ImGui::StyleColorsLight(ImGuiStyle^ style)
	{
		::ImGui::StyleColorsLight(&style->_handle);
	}

	/*static*/ void ImGui::StyleColorsLight()
	{
		::ImGui::StyleColorsLight();
	}

	/*static*/ bool ImGui::Begin(ImString^ name, bool% open, ImGuiWindowFlags flags)
	{
		IMSTR_DECODE_TEMP(name);
		REF_VAL_INIT(open);
		auto result = ::ImGui::Begin(name_cstr, &out_open, (OGImGuiWindowFlags)flags);
		REF_VAL_COPY(open);
		return result;
	}

	/*static*/ bool ImGui::Begin(ImString^ name, bool% open)
	{
		IMSTR_DECODE_TEMP(name);
		REF_VAL_INIT(open);
		auto result = ::ImGui::Begin(name_cstr, &out_open);
		REF_VAL_COPY(open);
		return result;
	}

	/*static*/ bool ImGui::Begin(ImString^ name)
	{
		IMSTR_DECODE_TEMP(name);
		auto result = ::ImGui::Begin(name_cstr);
		return result;
	}

	/*static*/ void ImGui::End()
	{
		::ImGui::End();
	}

	/*static*/ bool ImGui::BeginChild(ImString^ id, ImVec2 size, bool border, ImGuiWindowFlags flags)
	{
		IMSTR_DECODE_TEMP(id);
		return ::ImGui::BeginChild(id_cstr, size, border, (OGImGuiWindowFlags)flags);
	}

	/*static*/ bool ImGui::BeginChild(ImString^ id, ImVec2 size, bool border)
	{
		IMSTR_DECODE_TEMP(id);
		return ::ImGui::BeginChild(id_cstr, size, border);
	}

	/*static*/ bool ImGui::BeginChild(ImString^ id, ImVec2 size)
	{
		IMSTR_DECODE_TEMP(id);
		return ::ImGui::BeginChild(id_cstr, (::ImVec2)size);
	}

	/*static*/ bool ImGui::BeginChild(ImString^ id)
	{
		IMSTR_DECODE_TEMP(id);
		return ::ImGui::BeginChild(id_cstr);
	}

	/*static*/ bool ImGui::BeginChild(ImGuiID id, ImVec2 size, bool border, ImGuiWindowFlags flags)
	{
		return ::ImGui::BeginChild(id, size, border, (OGImGuiWindowFlags)flags);
	}

	/*static*/ bool ImGui::BeginChild(ImGuiID id, ImVec2 size, bool border)
	{
		return ::ImGui::BeginChild(id, size, border);
	}

	/*static*/ bool ImGui::BeginChild(ImGuiID id, ImVec2 size)
	{
		return ::ImGui::BeginChild(id, size);
	}

	/*static*/ bool ImGui::BeginChild(ImGuiID id)
	{
		return ::ImGui::BeginChild(id);
	}

	/*static*/ void ImGui::EndChild()
	{
		::ImGui::EndChild();
	}

	/*static*/ bool ImGui::IsWindowAppearing()
	{
		return ::ImGui::IsWindowAppearing();
	}

	/*static*/ bool ImGui::IsWindowCollapsed()
	{
		return ::ImGui::IsWindowCollapsed();
	}

	/*static*/ bool ImGui::IsWindowFocused(ImGuiFocusedFlags flags)
	{
		return ::ImGui::IsWindowFocused((OGImGuiFocusedFlags)flags);
	}

	/*static*/ bool ImGui::IsWindowFocused()
	{
		return ::ImGui::IsWindowFocused();
	}

	/*static*/ bool ImGui::IsWindowHovered(ImGuiFocusedFlags flags)
	{
		return ::ImGui::IsWindowHovered((OGImGuiFocusedFlags)flags);
	}

	/*static*/ bool ImGui::IsWindowHovered()
	{
		return ::ImGui::IsWindowHovered();
	}

	/*static*/ ImDrawList ImGui::GetWindowDrawList()
	{
		return ImDrawList(::ImGui::GetWindowDrawList());
	}

	/*static*/ ImVec2 ImGui::GetWindowPos()
	{
		return (ImVec2)::ImGui::GetWindowPos();
	}

	/*static*/ ImVec2 ImGui::GetWindowSize()
	{
		return (ImVec2)::ImGui::GetWindowSize();
	}

	/*static*/ float ImGui::GetWindowWidth()
	{
		return ::ImGui::GetWindowWidth();
	}

	/*static*/ float ImGui::GetWindowHeight()
	{
		return ::ImGui::GetWindowHeight();
	}

	/*static*/ void ImGui::SetNextWindowPos(ImVec2 pos, ImGuiCond cond, ImVec2 pivot)
	{
		::ImGui::SetNextWindowPos(pos, (OGImGuiCond)cond, pivot);
	}

	/*static*/ void ImGui::SetNextWindowPos(ImVec2 pos, ImGuiCond cond)
	{
		::ImGui::SetNextWindowPos(pos, (OGImGuiCond)cond);
	}

	/*static*/ void ImGui::SetNextWindowPos(ImVec2 pos)
	{
		::ImGui::SetNextWindowPos(pos);
	}

	/*static*/ void ImGui::SetNextWindowSize(ImVec2 size, ImGuiCond cond)
	{
		::ImGui::SetNextWindowSize(size, (OGImGuiCond)cond);
	}

	/*static*/ void ImGui::SetNextWindowSize(ImVec2 size)
	{
		::ImGui::SetNextWindowSize(size);
	}

	/*static*/ void ImGui::SetNextWindowSizeConstraints(ImVec2 min, ImVec2 max, ImGuiSizeDelegate^ callback)
	{
		::ImGui::SetNextWindowSizeConstraints(min, max, (ImGuiSizeCallback)Marshal::GetFunctionPointerForDelegate(callback).ToPointer());
	}

	/*static*/ void ImGui::SetNextWindowSizeConstraints(ImVec2 min, ImVec2 max)
	{
		::ImGui::SetNextWindowSizeConstraints(min, max);
	}

	/*static*/ void ImGui::SetNextWindowContentSize(ImVec2 size)
	{
		::ImGui::SetNextWindowContentSize(size);
	}

	/*static*/ void ImGui::SetNextWindowCollapsed(bool collapsed, ImGuiCond cond)
	{
		::ImGui::SetNextWindowCollapsed(collapsed, (OGImGuiCond)cond);
	}

	/*static*/ void ImGui::SetNextWindowCollapsed(bool collapsed)
	{
		::ImGui::SetNextWindowCollapsed(collapsed);
	}

	/*static*/ void ImGui::SetNextWindowFocus()
	{
		::ImGui::SetNextWindowFocus();
	}

	/*static*/ void ImGui::SetNextWindowBgAlpha(float alpha)
	{
		::ImGui::SetNextWindowBgAlpha(alpha);
	}

	/*static*/ void ImGui::SetWindowPos(ImVec2 pos, ImGuiCond cond)
	{
		::ImGui::SetWindowPos(pos, (OGImGuiCond)cond);
	}

	/*static*/ void ImGui::SetWindowPos(ImVec2 pos)
	{
		::ImGui::SetWindowPos(pos);
	}

	/*static*/ void ImGui::SetWindowSize(ImVec2 size, ImGuiCond cond)
	{
		::ImGui::SetWindowSize(size, (OGImGuiCond)cond);
	}

	/*static*/ void ImGui::SetWindowSize(ImVec2 size)
	{
		::ImGui::SetWindowSize(size);
	}

	/*static*/ void ImGui::SetWindowCollapsed(bool collapsed, ImGuiCond cond)
	{
		::ImGui::SetWindowCollapsed(collapsed, (OGImGuiCond)cond);
	}

	/*static*/ void ImGui::SetWindowCollapsed(bool collapsed)
	{
		::ImGui::SetWindowCollapsed(collapsed);
	}

	/*static*/ void ImGui::SetWindowFocus()
	{
		::ImGui::SetWindowFocus();
	}

	/*static*/ void ImGui::SetWindowFontScale(float scale)
	{
		::ImGui::SetWindowFontScale(scale);
	}

	/*static*/ void ImGui::SetWindowPos(ImString^ name, ImVec2 pos, ImGuiCond cond)
	{
		IMSTR_DECODE_TEMP(name);
		::ImGui::SetWindowPos(name_cstr, pos, (OGImGuiCond)cond);
	}

	/*static*/ void ImGui::SetWindowPos(ImString^ name, ImVec2 pos)
	{
		IMSTR_DECODE_TEMP(name);
		::ImGui::SetWindowPos(name_cstr, pos);
	}

	/*static*/ void ImGui::SetWindowSize(ImString^ name, ImVec2 size, ImGuiCond cond)
	{
		IMSTR_DECODE_TEMP(name);
		::ImGui::SetWindowSize(name_cstr, size, (OGImGuiCond)cond);
	}

	/*static*/ void ImGui::SetWindowSize(ImString^ name, ImVec2 size)
	{
		IMSTR_DECODE_TEMP(name);
		::ImGui::SetWindowSize(name_cstr, size);
	}

	/*static*/ void ImGui::SetWindowCollapsed(ImString^ name, bool collapsed, ImGuiCond cond)
	{
		IMSTR_DECODE_TEMP(name);
		::ImGui::SetWindowCollapsed(name_cstr, collapsed, (OGImGuiCond)cond);
	}

	/*static*/ void ImGui::SetWindowCollapsed(ImString^ name, bool collapsed)
	{
		IMSTR_DECODE_TEMP(name);
		::ImGui::SetWindowCollapsed(name_cstr, collapsed);
	}

	/*static*/ void ImGui::SetWindowFocus(ImString^ name)
	{
		IMSTR_DECODE_TEMP(name);
		::ImGui::SetWindowFocus(name_cstr);
	}

	/*static*/ ImVec2 ImGui::GetContentRegionMax()
	{
		return ::ImGui::GetContentRegionMax();
	}

	/*static*/ ImVec2 ImGui::GetContentRegionAvail()
	{
		return ::ImGui::GetContentRegionAvail();
	}

	/*static*/ ImVec2 ImGui::GetWindowContentRegionMin()
	{
		return ::ImGui::GetWindowContentRegionMin();
	}

	/*static*/ ImVec2 ImGui::GetWindowContentRegionMax()
	{
		return ::ImGui::GetWindowContentRegionMax();
	}

	/*static*/ float ImGui::GetWindowContentRegionWidth()
	{
		return ::ImGui::GetWindowContentRegionWidth();
	}

	/*static*/ float ImGui::GetScrollX()
	{
		return ::ImGui::GetScrollX();
	}

	/*static*/ float ImGui::GetScrollY()
	{
		return ::ImGui::GetScrollY();
	}

	/*static*/ float ImGui::GetScrollMaxX()
	{
		return ::ImGui::GetScrollMaxX();
	}

	/*static*/ float ImGui::GetScrollMaxY()
	{
		return ::ImGui::GetScrollMaxY();
	}

	/*static*/ void ImGui::SetScrollX(float scroll_x)
	{
		::ImGui::SetScrollX(scroll_x);
	}

	/*static*/ void ImGui::SetScrollY(float scroll_y)
	{
		::ImGui::SetScrollY(scroll_y);
	}

	/*static*/ void ImGui::SetScrollHereX(float center_x_ratio)
	{
		::ImGui::SetScrollHereX(center_x_ratio);
	}

	/*static*/ void ImGui::SetScrollHereX()
	{
		::ImGui::SetScrollHereX();
	}

	/*static*/ void ImGui::SetScrollHereY(float center_y_ratio)
	{
		::ImGui::SetScrollHereY(center_y_ratio);
	}

	/*static*/ void ImGui::SetScrollHereY()
	{
		::ImGui::SetScrollHereY();
	}

	/*static*/ void ImGui::SetScrollFromPosX(float local_x, float center_x_ratio)
	{
		::ImGui::SetScrollFromPosX(local_x, center_x_ratio);
	}

	/*static*/ void ImGui::SetScrollFromPosX(float local_x)
	{
		::ImGui::SetScrollFromPosX(local_x);
	}

	/*static*/ void ImGui::SetScrollFromPosY(float local_y, float center_y_ratio)
	{
		::ImGui::SetScrollFromPosY(local_y, center_y_ratio);
	}

	/*static*/ void ImGui::SetScrollFromPosY(float local_y)
	{
		::ImGui::SetScrollFromPosY(local_y);
	}

	/*static*/ void ImGui::PushFont(ImFont^ font)
	{
		::ImGui::PushFont(font->_handle);
	}

	/*static*/ void ImGui::PopFont()
	{
		::ImGui::PopFont();
	}

	/*static*/ void ImGui::PushStyleColor(ImGuiCol idx, ImU32 col)
	{
		::ImGui::PushStyleColor((OGImGuiCol)idx, col);
	}

	/*static*/ void ImGui::PushStyleColor(ImGuiCol idx, ImVec4 col)
	{
		::ImGui::PushStyleColor((OGImGuiCol)idx, col);
	}

	/*static*/ void ImGui::PopStyleColor(int count)
	{
		::ImGui::PopStyleColor(count);
	}

	/*static*/ void ImGui::PopStyleColor()
	{
		::ImGui::PopStyleColor();
	}

	/*static*/ void ImGui::PushStyleVar(ImGuiStyleVar idx, float val)
	{
		::ImGui::PushStyleVar((OGImGuiStyleVar)idx, val);
	}

	/*static*/ void ImGui::PushStyleVar(ImGuiStyleVar idx, ImVec2 val)
	{
		::ImGui::PushStyleVar((OGImGuiStyleVar)idx, val);
	}

	/*static*/ void ImGui::PopStyleVar(int count)
	{
		::ImGui::PopStyleVar(count);
	}

	/*static*/ void ImGui::PopStyleVar()
	{
		::ImGui::PopStyleVar();
	}

	/*static*/ ImVec4 ImGui::GetStyleColorVec4(ImGuiCol idx)
	{
		return ::ImGui::GetStyleColorVec4((OGImGuiCol)idx);
	}

	/*static*/ ImFont^ ImGui::GetFont()
	{
		return gcnew ImFont(::ImGui::GetFont());
	}

	/*static*/ float ImGui::GetFontSize()
	{
		return ::ImGui::GetFontSize();
	}

	/*static*/ ImVec2 ImGui::GetFontTexUvWhitePixel()
	{
		return ::ImGui::GetFontTexUvWhitePixel();
	}

	/*static*/ ImU32 ImGui::GetColorU32(ImGuiCol idx, float alpha_mul)
	{
		return ::ImGui::GetColorU32((OGImGuiCol)idx, alpha_mul);
	}

	/*static*/ ImU32 ImGui::GetColorU32(ImGuiCol idx)
	{
		return ::ImGui::GetColorU32((OGImGuiCol)idx);
	}

	/*static*/ ImU32 ImGui::GetColorU32(ImVec4 col)
	{
		return ::ImGui::GetColorU32(col);
	}

	/*static*/ ImU32 ImGui::GetColorU32(ImU32 col)
	{
		return ::ImGui::GetColorU32(col);
	}

	/*static*/ void ImGui::PushItemWidth(float item_width)
	{
		::ImGui::PushItemWidth(item_width);
	}

	/*static*/ void ImGui::PopItemWidth()
	{
		::ImGui::PopItemWidth();
	}

	/*static*/ void ImGui::SetNextItemWidth(float item_width)
	{
		::ImGui::SetNextItemWidth(item_width);
	}

	/*static*/ float ImGui::CalcItemWidth()
	{
		return ::ImGui::CalcItemWidth();
	}

	/*static*/ void ImGui::PushTextWrapPos(float wrap_local_pos_x)
	{
		::ImGui::PushTextWrapPos(wrap_local_pos_x);
	}

	/*static*/ void ImGui::PushTextWrapPos()
	{
		::ImGui::PushTextWrapPos();
	}

	/*static*/ void ImGui::PopTextWrapPos()
	{
		::ImGui::PopTextWrapPos();
	}

	/*static*/ void ImGui::PushAllowKeyboardFocus(bool allow_keyboard_focus)
	{
		::ImGui::PushAllowKeyboardFocus(allow_keyboard_focus);
	}

	/*static*/ void ImGui::PopAllowKeyboardFocus()
	{
		::ImGui::PopAllowKeyboardFocus();
	}

	/*static*/ void ImGui::PushButtonRepeat(bool repeat)
	{
		::ImGui::PushButtonRepeat(repeat);
	}

	/*static*/ void ImGui::PopButtonRepeat()
	{
		::ImGui::PopButtonRepeat();
	}

	/*static*/ void ImGui::Separator()
	{
		::ImGui::Separator();
	}

	/*static*/ void ImGui::SameLine(float offset_from_start_x, float spacing)
	{
		::ImGui::SameLine(offset_from_start_x, spacing);
	}

	/*static*/ void ImGui::SameLine(float offset_from_start_x)
	{
		::ImGui::SameLine(offset_from_start_x);
	}

	/*static*/ void ImGui::SameLine()
	{
		::ImGui::SameLine();
	}

	/*static*/ void ImGui::NewLine()
	{
		::ImGui::NewLine();
	}

	/*static*/ void ImGui::Spacing()
	{
		::ImGui::Spacing();
	}

	/*static*/ void ImGui::Dummy(ImVec2 size)
	{
		::ImGui::Dummy(size);
	}

	/*static*/ void ImGui::Indent(float indent_w)
	{
		::ImGui::Indent(indent_w);
	}

	/*static*/ void ImGui::Indent()
	{
		::ImGui::Indent();
	}

	/*static*/ void ImGui::Unindent(float indent_w)
	{
		::ImGui::Unindent(indent_w);
	}

	/*static*/ void ImGui::Unindent()
	{
		::ImGui::Unindent();
	}

	/*static*/ void ImGui::BeginGroup()
	{
		::ImGui::BeginGroup();
	}

	/*static*/ void ImGui::EndGroup()
	{
		::ImGui::EndGroup();
	}

	/*static*/ ImVec2 ImGui::GetCursorPos()
	{
		return ::ImGui::GetCursorPos();
	}

	/*static*/ float ImGui::GetCursorPosX()
	{
		return ::ImGui::GetCursorPosX();
	}

	/*static*/ float ImGui::GetCursorPosY()
	{
		return ::ImGui::GetCursorPosY();
	}

	/*static*/ void ImGui::SetCursorPos(ImVec2 local_pos)
	{
		::ImGui::SetCursorPos(local_pos);
	}

	/*static*/ void ImGui::SetCursorPosX(float local_x)
	{
		::ImGui::SetCursorPosX(local_x);
	}

	/*static*/ void ImGui::SetCursorPosY(float local_y)
	{
		::ImGui::SetCursorPosY(local_y);
	}

	/*static*/ ImVec2 ImGui::GetCursorStartPos()
	{
		return ::ImGui::GetCursorStartPos();
	}

	/*static*/ ImVec2 ImGui::GetCursorScreenPos()
	{
		return ::ImGui::GetCursorScreenPos();
	}

	/*static*/ void ImGui::SetCursorScreenPos(ImVec2 pos)
	{
		::ImGui::SetCursorScreenPos(pos);
	}

	/*static*/ void ImGui::AlignTextToFramePadding()
	{
		::ImGui::AlignTextToFramePadding();
	}

	/*static*/ float ImGui::GetTextLineHeight()
	{
		return ::ImGui::GetTextLineHeight();
	}

	/*static*/ float ImGui::GetTextLineHeightWithSpacing()
	{
		return ::ImGui::GetTextLineHeightWithSpacing();
	}

	/*static*/ float ImGui::GetFrameHeight()
	{
		return ::ImGui::GetFrameHeight();
	}

	/*static*/ float ImGui::GetFrameHeightWithSpacing()
	{
		return ::ImGui::GetFrameHeightWithSpacing();
	}

	/*static*/ void ImGui::PushID(ImString^ str_id)
	{
		IMSTR_DECODE_TEMP(str_id);
		::ImGui::PushID(str_id_cstr);
	}

	///*static*/ void PushID(const char* str_id_begin, const char* str_id_end);  

	///*static*/ void PushID(const void* ptr_id);                                

	/*static*/ void ImGui::PushID(int int_id)
	{
		::ImGui::PushID(int_id);
	}

	/*static*/ void ImGui::PopID()
	{
		::ImGui::PopID();
	}

	/*static*/ ImGuiID ImGui::GetID(ImString^ str_id)
	{
		IMSTR_DECODE_TEMP(str_id);
		return ::ImGui::GetID(str_id_cstr);
	}

	///*static*/ ImGuiID GetID(const char* str_id_begin, const char* str_id_end);

	///*static*/ ImGuiID GetID(const void* ptr_id);

	/*static*/ void ImGui::Text(ImString^ text)
	{
		IMSTR_DECODE_TEMP(text);
		::ImGui::TextUnformatted(text_cstr);
	}

	/*static*/ void ImGui::TextColored(ImVec4 col, ImString^ text)
	{
		IMSTR_DECODE_TEMP(text);
		::ImGui::TextColored(col, "%s", text_cstr);
	}

	/*static*/ void ImGui::TextDisabled(ImString^ text)
	{
		IMSTR_DECODE_TEMP(text);
		::ImGui::TextDisabled("%s", text_cstr);
	}

	/*static*/ void ImGui::TextWrapped(ImString^ text)
	{
		IMSTR_DECODE_TEMP(text);
		::ImGui::TextWrapped("%s", text_cstr);
	}

	/*static*/ void ImGui::LabelText(ImString^ label, ImString^ text)
	{
		IMSTR_DECODE_TEMP(label);
		IMSTR_DECODE_TEMP(text);
		::ImGui::LabelText(label_cstr, "%s", text_cstr);
	}

	/*static*/ void ImGui::BulletText(ImString^ text)
	{
		IMSTR_DECODE_TEMP(text);
		::ImGui::BulletText("%s", text_cstr);
	}

	/*static*/ bool ImGui::Button(ImString^ label, ImVec2 size)
	{
		IMSTR_DECODE_TEMP(label);
		return ::ImGui::Button(label_cstr, size);
	}

	/*static*/ bool ImGui::Button(ImString^ label)
	{
		IMSTR_DECODE_TEMP(label);
		return ::ImGui::Button(label_cstr);
	}

	/*static*/ bool ImGui::SmallButton(ImString^ label)
	{
		IMSTR_DECODE_TEMP(label);
		return ::ImGui::SmallButton(label_cstr);
	}

	/*static*/ bool ImGui::InvisibleButton(ImString^ str_id, ImVec2 size)
	{
		IMSTR_DECODE_TEMP(str_id);
		return ::ImGui::InvisibleButton(str_id_cstr, size);
	}

	/*static*/ bool ImGui::ArrowButton(ImString^ str_id, ImGuiDir dir)
	{
		IMSTR_DECODE_TEMP(str_id);
		return ::ImGui::ArrowButton(str_id_cstr, (OGImGuiDir)dir);
	}

	/*static*/ void ImGui::Image(ImTextureID user_texture_id, ImVec2 size, ImVec2 uv0, ImVec2 uv1, ImVec4 tint_col, ImVec4 border_col)
	{
		::ImGui::Image(user_texture_id.ToPointer(), size, uv0, uv1, tint_col, border_col);
	}

	/*static*/ void ImGui::Image(ImTextureID user_texture_id, ImVec2 size, ImVec2 uv0, ImVec2 uv1, ImVec4 tint_col)
	{
		::ImGui::Image(user_texture_id.ToPointer(), size, uv0, uv1, tint_col);
	}

	/*static*/ void ImGui::Image(ImTextureID user_texture_id, ImVec2 size, ImVec2 uv0, ImVec2 uv1)
	{
		::ImGui::Image(user_texture_id.ToPointer(), size, uv0, uv1);
	}

	/*static*/ void ImGui::Image(ImTextureID user_texture_id, ImVec2 size, ImVec2 uv0)
	{
		::ImGui::Image(user_texture_id.ToPointer(), size, uv0);
	}

	/*static*/ void ImGui::Image(ImTextureID user_texture_id, ImVec2 size)
	{
		::ImGui::Image(user_texture_id.ToPointer(), size);
	}

	/*static*/ bool ImGui::ImageButton(ImTextureID user_texture_id, ImVec2 size, ImVec2 uv0, ImVec2 uv1, int frame_padding, ImVec4 bg_col, ImVec4 tint_col)
	{
		return ::ImGui::ImageButton(user_texture_id.ToPointer(), size, uv0, uv1, frame_padding, bg_col, tint_col);
	}

	/*static*/ bool ImGui::ImageButton(ImTextureID user_texture_id, ImVec2 size, ImVec2 uv0, ImVec2 uv1, int frame_padding, ImVec4 bg_col)
	{
		return ::ImGui::ImageButton(user_texture_id.ToPointer(), size, uv0, uv1, frame_padding, bg_col);
	}

	/*static*/ bool ImGui::ImageButton(ImTextureID user_texture_id, ImVec2 size, ImVec2 uv0, ImVec2 uv1, int frame_padding)
	{
		return ::ImGui::ImageButton(user_texture_id.ToPointer(), size, uv0, uv1, frame_padding);
	}

	/*static*/ bool ImGui::ImageButton(ImTextureID user_texture_id, ImVec2 size, ImVec2 uv0, ImVec2 uv1)
	{
		return ::ImGui::ImageButton(user_texture_id.ToPointer(), size, uv0, uv1);
	}

	/*static*/ bool ImGui::ImageButton(ImTextureID user_texture_id, ImVec2 size, ImVec2 uv0)
	{
		return ::ImGui::ImageButton(user_texture_id.ToPointer(), size, uv0);
	}

	/*static*/ bool ImGui::ImageButton(ImTextureID user_texture_id, ImVec2 size)
	{
		return ::ImGui::ImageButton(user_texture_id.ToPointer(), size);
	}

	/*static*/ bool ImGui::Checkbox(ImString^ label, bool% v)
	{
		IMSTR_DECODE_TEMP(label);
		REF_VAL_INIT(v);
		auto ret = ::ImGui::Checkbox(label_cstr, &out_v);
		REF_VAL_COPY(v);
		return ret;
	}

	/*static*/ bool ImGui::CheckboxFlags(ImString^ label, unsigned int% flags, unsigned int flags_value)
	{
		IMSTR_DECODE_TEMP(label);
		REF_VAL_INIT(flags);
		auto ret = ::ImGui::CheckboxFlags(label_cstr, &out_flags, flags_value);
		REF_VAL_COPY(flags);
		return ret;
	}

	/*static*/ bool ImGui::RadioButton(ImString^ label, bool active)
	{
		IMSTR_DECODE_TEMP(label);
		return ::ImGui::RadioButton(label_cstr, active);
	}

	/*static*/ bool ImGui::RadioButton(ImString^ label, int% v, int v_button)
	{
		IMSTR_DECODE_TEMP(label);
		REF_VAL_INIT(v);
		auto ret = ::ImGui::RadioButton(label_cstr, &out_v, v_button);
		REF_VAL_COPY(v);
		return ret;
	}

	/*static*/ void ImGui::ProgressBar(float fraction, ImVec2 size_arg, ImString^ overlay)
	{
		IMSTR_DECODE_TEMP(overlay);
		::ImGui::ProgressBar(fraction, size_arg, overlay_cstr);
	}

	/*static*/ void ImGui::ProgressBar(float fraction, ImVec2 size_arg)
	{
		::ImGui::ProgressBar(fraction, size_arg);
	}

	/*static*/ void ImGui::ProgressBar(float fraction)
	{
		::ImGui::ProgressBar(fraction);
	}

	/*static*/ void ImGui::Bullet()
	{
		::ImGui::Bullet();
	}

	static char* _list_box_buffer;
	static int _list_box_buffer_len = 0;

	static bool ListBoxGetterWrap(void* func, int idx, const char** out_text)
	{
		ImString^ str;
		auto dg = Marshal::GetDelegateForFunctionPointer<ListBoxGetter^>((IntPtr)func);
		auto ret = dg(idx, str);
		IMSTR_DECODE_TEMP(str);

		if (str_bytes.Length >= _list_box_buffer_len)
		{
			_list_box_buffer_len = str_bytes.Length;

			if (_list_box_buffer)
				delete[] _list_box_buffer;

			_list_box_buffer = new char[str_bytes.Length + 1];
		}

		memcpy(_list_box_buffer, str_cstr, str_bytes.Length);
		_list_box_buffer[str_bytes.Length] = 0;

		*out_text = _list_box_buffer;
		return ret;
	}

	/*static*/ bool ImGui::Combo(ImString^ label, int% current_item, ListBoxGetter^ items_getter, int items_count, int popup_max_height_in_items)
	{
		IMSTR_DECODE_TEMP(label);
		REF_VAL_INIT(current_item);
		GET_CB_FUNC_PTR(items_getter);
		auto ret = ::ImGui::Combo(label_cstr, &out_current_item, ListBoxGetterWrap, items_getter_ptr, items_count, popup_max_height_in_items);
		REF_VAL_COPY(current_item);
		return ret;
	}

	/*static*/ bool ImGui::Combo(ImString^ label, int% current_item, ListBoxGetter^ items_getter, int items_count)
	{
		IMSTR_DECODE_TEMP(label);
		REF_VAL_INIT(current_item);
		GET_CB_FUNC_PTR(items_getter);
		auto ret = ::ImGui::Combo(label_cstr, &out_current_item, ListBoxGetterWrap, items_getter_ptr, items_count);
		REF_VAL_COPY(current_item);
		return ret;
	}

	/*static*/ bool ImGui::BeginCombo(ImString^ label, ImString^ preview_value, ImGuiComboFlags flags)
	{
		IMSTR_DECODE_TEMP(label);
		IMSTR_DECODE_TEMP(preview_value);
		return ::ImGui::BeginCombo(label_cstr, preview_value_cstr, (OGImGuiComboFlags)flags);
	}

	/*static*/ bool ImGui::BeginCombo(ImString^ label, ImString^ preview_value)
	{
		IMSTR_DECODE_TEMP(label);
		IMSTR_DECODE_TEMP(preview_value);
		return ::ImGui::BeginCombo(label_cstr, preview_value_cstr);
	}

	/*static*/ void ImGui::EndCombo()
	{
		::ImGui::EndCombo();
	}

	/*static*/ bool ImGui::DragFloatRange2(ImString^ label, float% v_current_min, float% v_current_max, float v_speed, float v_min, float v_max, ImString^ format, ImString^ format_max, float power)
	{
		IMSTR_DECODE_TEMP(label);
		IMSTR_DECODE_TEMP(format);
		IMSTR_DECODE_TEMP(format_max);
		float out_v_current_min = v_current_min, out_v_current_max = v_current_max;
		auto ret = ::ImGui::DragFloatRange2(label_cstr, &out_v_current_min, &out_v_current_max, v_speed, v_min, v_max, format_cstr, format_max_cstr, power);
		v_current_min = out_v_current_min;
		v_current_max = out_v_current_max;
		return ret;
	}

	/*static*/ bool ImGui::DragFloatRange2(ImString^ label, float% v_current_min, float% v_current_max, float v_speed, float v_min, float v_max, ImString^ format, ImString^ format_max)
	{
		IMSTR_DECODE_TEMP(label);
		IMSTR_DECODE_TEMP(format);
		IMSTR_DECODE_TEMP(format_max);
		float out_v_current_min = v_current_min, out_v_current_max = v_current_max;
		auto ret = ::ImGui::DragFloatRange2(label_cstr, &out_v_current_min, &out_v_current_max, v_speed, v_min, v_max, format_cstr, format_max_cstr);
		v_current_min = out_v_current_min;
		v_current_max = out_v_current_max;
		return ret;
	}

	/*static*/ bool ImGui::DragFloatRange2(ImString^ label, float% v_current_min, float% v_current_max, float v_speed, float v_min, float v_max, ImString^ format)
	{
		IMSTR_DECODE_TEMP(label);
		IMSTR_DECODE_TEMP(format);
		float out_v_current_min = v_current_min, out_v_current_max = v_current_max;
		auto ret = ::ImGui::DragFloatRange2(label_cstr, &out_v_current_min, &out_v_current_max, v_speed, v_min, v_max, format_cstr);
		v_current_min = out_v_current_min;
		v_current_max = out_v_current_max;
		return ret;
	}

	/*static*/ bool ImGui::DragFloatRange2(ImString^ label, float% v_current_min, float% v_current_max, float v_speed, float v_min, float v_max)
	{
		IMSTR_DECODE_TEMP(label);
		float out_v_current_min = v_current_min, out_v_current_max = v_current_max;
		auto ret = ::ImGui::DragFloatRange2(label_cstr, &out_v_current_min, &out_v_current_max, v_speed, v_min, v_max);
		v_current_min = out_v_current_min;
		v_current_max = out_v_current_max;
		return ret;
	}

	/*static*/ bool ImGui::DragFloatRange2(ImString^ label, float% v_current_min, float% v_current_max, float v_speed, float v_min)
	{
		IMSTR_DECODE_TEMP(label);
		float out_v_current_min = v_current_min, out_v_current_max = v_current_max;
		auto ret = ::ImGui::DragFloatRange2(label_cstr, &out_v_current_min, &out_v_current_max, v_speed, v_min);
		v_current_min = out_v_current_min;
		v_current_max = out_v_current_max;
		return ret;
	}

	/*static*/ bool ImGui::DragFloatRange2(ImString^ label, float% v_current_min, float% v_current_max, float v_speed)
	{
		IMSTR_DECODE_TEMP(label);
		float out_v_current_min = v_current_min, out_v_current_max = v_current_max;
		auto ret = ::ImGui::DragFloatRange2(label_cstr, &out_v_current_min, &out_v_current_max, v_speed);
		v_current_min = out_v_current_min;
		v_current_max = out_v_current_max;
		return ret;
	}

	/*static*/ bool ImGui::DragFloatRange2(ImString^ label, float% v_current_min, float% v_current_max)
	{
		IMSTR_DECODE_TEMP(label);
		float out_v_current_min = v_current_min, out_v_current_max = v_current_max;
		auto ret = ::ImGui::DragFloatRange2(label_cstr, &out_v_current_min, &out_v_current_max);
		v_current_min = out_v_current_min;
		v_current_max = out_v_current_max;
		return ret;
	}

	/*static*/ bool ImGui::DragIntRange2(ImString^ label, int% v_current_min, int% v_current_max, float v_speed, int v_min, int v_max, ImString^ format, ImString^ format_max)
	{
		IMSTR_DECODE_TEMP(label);
		IMSTR_DECODE_TEMP(format);
		IMSTR_DECODE_TEMP(format_max);
		int out_v_current_min = v_current_min, out_v_current_max = v_current_max;
		auto ret = ::ImGui::DragIntRange2(label_cstr, &out_v_current_min, &out_v_current_max, v_speed, v_min, v_max, format_cstr, format_max_cstr);
		v_current_min = out_v_current_min;
		v_current_max = out_v_current_max;
		return ret;
	}

	/*static*/ bool ImGui::DragIntRange2(ImString^ label, int% v_current_min, int% v_current_max, float v_speed, int v_min, int v_max, ImString^ format)
	{
		IMSTR_DECODE_TEMP(label);
		IMSTR_DECODE_TEMP(format);
		int out_v_current_min = v_current_min, out_v_current_max = v_current_max;
		auto ret = ::ImGui::DragIntRange2(label_cstr, &out_v_current_min, &out_v_current_max, v_speed, v_min, v_max, format_cstr);
		v_current_min = out_v_current_min;
		v_current_max = out_v_current_max;
		return ret;
	}

	/*static*/ bool ImGui::DragIntRange2(ImString^ label, int% v_current_min, int% v_current_max, float v_speed, int v_min, int v_max)
	{
		IMSTR_DECODE_TEMP(label);
		int out_v_current_min = v_current_min, out_v_current_max = v_current_max;
		auto ret = ::ImGui::DragIntRange2(label_cstr, &out_v_current_min, &out_v_current_max, v_speed, v_min, v_max);
		v_current_min = out_v_current_min;
		v_current_max = out_v_current_max;
		return ret;
	}

	/*static*/ bool ImGui::DragIntRange2(ImString^ label, int% v_current_min, int% v_current_max, float v_speed, int v_min)
	{
		IMSTR_DECODE_TEMP(label);
		int out_v_current_min = v_current_min, out_v_current_max = v_current_max;
		auto ret = ::ImGui::DragIntRange2(label_cstr, &out_v_current_min, &out_v_current_max, v_speed, v_min);
		v_current_min = out_v_current_min;
		v_current_max = out_v_current_max;
		return ret;
	}

	/*static*/ bool ImGui::DragIntRange2(ImString^ label, int% v_current_min, int% v_current_max, float v_speed)
	{
		IMSTR_DECODE_TEMP(label);
		int out_v_current_min = v_current_min, out_v_current_max = v_current_max;
		auto ret = ::ImGui::DragIntRange2(label_cstr, &out_v_current_min, &out_v_current_max, v_speed);
		v_current_min = out_v_current_min;
		v_current_max = out_v_current_max;
		return ret;
	}

	/*static*/ bool ImGui::DragIntRange2(ImString^ label, int% v_current_min, int% v_current_max)
	{
		IMSTR_DECODE_TEMP(label);
		int out_v_current_min = v_current_min, out_v_current_max = v_current_max;
		auto ret = ::ImGui::DragIntRange2(label_cstr, &out_v_current_min, &out_v_current_max);
		v_current_min = out_v_current_min;
		v_current_max = out_v_current_max;
		return ret;
	}

	generic<typename T>
	/*static*/ bool ImGui::DragScalar(ImString^ label, ImGuiDataType data_type, T% p_data, float v_speed, T p_min, T p_max, ImString^ format, float power)
	{
		IMSTR_DECODE_TEMP(label);
		IMSTR_DECODE_TEMP(format);
		REF_PIN(T, T, p_data);
		REF_PIN(T, const T, p_min);
		REF_PIN(T, const T, p_max);
		return ::ImGui::DragScalar(label_cstr, (OGImGuiDataType)data_type, p_data_ptr, v_speed, p_min_ptr, p_max_ptr, format_cstr, power);
	}
	
	generic<typename T>
	/*static*/ bool ImGui::DragScalar(ImString^ label, ImGuiDataType data_type, T% p_data, float v_speed, T p_min, T p_max, ImString^ format)
	{
		IMSTR_DECODE_TEMP(label);
		IMSTR_DECODE_TEMP(format);
		REF_PIN(T, T, p_data);
		REF_PIN(T, const T, p_min);
		REF_PIN(T, const T, p_max);
		return ::ImGui::DragScalar(label_cstr, (OGImGuiDataType)data_type, p_data_ptr, v_speed, p_min_ptr, p_max_ptr, format_cstr);
	}
		
	generic<typename T>
	/*static*/ bool ImGui::DragScalar(ImString^ label, ImGuiDataType data_type, T% p_data, float v_speed, T p_min, T p_max)
	{
		IMSTR_DECODE_TEMP(label);
		REF_PIN(T, T, p_data);
		REF_PIN(T, const T, p_min);
		REF_PIN(T, const T, p_max);
		return ::ImGui::DragScalar(label_cstr, (OGImGuiDataType)data_type, p_data_ptr, v_speed, p_min_ptr, p_max_ptr);
	}
		
	generic<typename T>
	/*static*/ bool ImGui::DragScalar(ImString^ label, ImGuiDataType data_type, T% p_data, float v_speed, T p_min)
	{
		IMSTR_DECODE_TEMP(label);
		REF_PIN(T, T, p_data);
		REF_PIN(T, const T, p_min);
		return ::ImGui::DragScalar(label_cstr, (OGImGuiDataType)data_type, p_data_ptr, v_speed, p_min_ptr);
	}
			
	generic<typename T>
	/*static*/ bool ImGui::DragScalar(ImString^ label, ImGuiDataType data_type, T% p_data, float v_speed)
	{
		IMSTR_DECODE_TEMP(label);
		REF_PIN(T, T, p_data);
		return ::ImGui::DragScalar(label_cstr, (OGImGuiDataType)data_type, p_data_ptr, v_speed);
	}

	generic<typename T>
	/*static*/ bool ImGui::DragScalarN(ImString^ label, ImGuiDataType data_type, Span<T> p_data, float v_speed, T p_min, T p_max, ImString^ format, float power)
	{
		IMSTR_DECODE_TEMP(label);
		IMSTR_DECODE_TEMP(format);
		SPAN_GET_PTR(T, void, p_data);
		REF_PIN(T, const T, p_min);
		REF_PIN(T, const T, p_max);
		return ::ImGui::DragScalarN(label_cstr, (OGImGuiDataType)data_type, p_data_ptr, p_data.Length, v_speed, p_min_ptr, p_max_ptr, format_cstr, power);
	}

	generic<typename T>
	/*static*/ bool ImGui::DragScalarN(ImString^ label, ImGuiDataType data_type, Span<T> p_data, float v_speed, T p_min, T p_max, ImString^ format)
	{
		IMSTR_DECODE_TEMP(label);
		IMSTR_DECODE_TEMP(format);
		SPAN_GET_PTR(T, void, p_data);
		REF_PIN(T, const T, p_min);
		REF_PIN(T, const T, p_max);
		return ::ImGui::DragScalarN(label_cstr, (OGImGuiDataType)data_type, p_data_ptr, p_data.Length, v_speed, p_min_ptr, p_max_ptr, format_cstr);
	}

	generic<typename T>
	/*static*/ bool ImGui::DragScalarN(ImString^ label, ImGuiDataType data_type, Span<T> p_data, float v_speed, T p_min, T p_max)
	{
		IMSTR_DECODE_TEMP(label);
		SPAN_GET_PTR(T, void, p_data);
		REF_PIN(T, const T, p_min);
		REF_PIN(T, const T, p_max);
		return ::ImGui::DragScalarN(label_cstr, (OGImGuiDataType)data_type, p_data_ptr, p_data.Length, v_speed, p_min_ptr, p_max_ptr);
	}
	
	generic<typename T>
	/*static*/ bool ImGui::DragScalarN(ImString^ label, ImGuiDataType data_type, Span<T> p_data, float v_speed, T p_min)
	{
		IMSTR_DECODE_TEMP(label);
		SPAN_GET_PTR(T, void, p_data);
		REF_PIN(T, const T, p_min);
		return ::ImGui::DragScalarN(label_cstr, (OGImGuiDataType)data_type, p_data_ptr, p_data.Length, v_speed, p_min_ptr);
	}
	
	generic<typename T>
	/*static*/ bool ImGui::DragScalarN(ImString^ label, ImGuiDataType data_type, Span<T> p_data, float v_speed)
	{
		IMSTR_DECODE_TEMP(label);
		SPAN_GET_PTR(T, void, p_data);
		return ::ImGui::DragScalarN(label_cstr, (OGImGuiDataType)data_type, p_data_ptr, p_data.Length, v_speed);
	}

	static int InputTextCallback(::ImGuiInputTextCallbackData* data)
	{
		if (data->UserData)
			return Marshal::GetDelegateForFunctionPointer<InputTextDelegate^>((IntPtr)data->UserData)(ImGuiInputTextCallbackData(data));

		return 0;
	}

	/*static*/ bool ImGui::InputText(ImString^ label, Span<unsigned char> buf, ImGuiInputTextFlags flags, InputTextDelegate^ callback)
	{
		CSTR_DECODE_TEMP(label);
		SPAN_GET_PTR(unsigned char, char, buf);

		return ::ImGui::InputText(label_cstr, buf_ptr, buf.Length, (OGImGuiInputTextFlags)flags, InputTextCallback, callback ? Marshal::GetFunctionPointerForDelegate(callback).ToPointer() : nullptr);
	}

	/*static*/ bool ImGui::InputText(ImString^ label, Span<unsigned char> buf, ImGuiInputTextFlags flags)
	{
		CSTR_DECODE_TEMP(label);
		SPAN_GET_PTR(unsigned char, char, buf);

		return ::ImGui::InputText(label_cstr, buf_ptr, buf.Length, (OGImGuiInputTextFlags)flags);
	}

	/*static*/ bool ImGui::InputText(ImString^ label, Span<unsigned char> buf)
	{
		CSTR_DECODE_TEMP(label);
		SPAN_GET_PTR(unsigned char, char, buf);

		return ::ImGui::InputText(label_cstr, buf_ptr, buf.Length);
	}

	struct InputTextTemporary
	{
		::ImVector<char>* buf;
		IntPtr callback;
	};

	static InputTextTemporary temp;

	static int InputTextResizeCallback(::ImGuiInputTextCallbackData* data)
	{
		if (data->EventFlag == ImGuiInputTextFlags_CallbackResize)
		{
			temp.buf->resize(data->BufTextLen);
			data->Buf = temp.buf->Data;
		}
		else if (temp.callback.ToPointer())
			return Marshal::GetDelegateForFunctionPointer<InputTextDelegate^>(temp.callback)(ImGuiInputTextCallbackData(data));

		return 0;
	}

	/*static*/ bool ImGui::InputText(ImString^ label, ImString^ buf, ImGuiInputTextFlags flags, InputTextDelegate^ callback)
	{
		temp.buf = buf->Vector;
		temp.callback = callback ? Marshal::GetFunctionPointerForDelegate(callback) : IntPtr::Zero;

		CSTR_DECODE_TEMP(label);

		auto ret = ::ImGui::InputText(label_cstr, buf->Vector->Data, buf->Vector->capacity(), (OGImGuiInputTextFlags)flags, InputTextCallback);

		if (ret)
			buf->String = nullptr;

		return ret;
	}

	/*static*/ bool ImGui::InputText(ImString^ label, ImString^ buf, ImGuiInputTextFlags flags)
	{
		temp.buf = buf->Vector;
		temp.callback = IntPtr::Zero;

		CSTR_DECODE_TEMP(label);

		auto ret = ::ImGui::InputText(label_cstr, buf->Vector->Data, buf->Vector->capacity(), (OGImGuiInputTextFlags)flags, InputTextCallback);

		if (ret)
			buf->String = nullptr;

		return ret;
	}

	/*static*/ bool ImGui::InputText(ImString^ label, ImString^ buf)
	{
		temp.buf = buf->Vector;
		temp.callback = IntPtr::Zero;

		CSTR_DECODE_TEMP(label);

		auto ret = ::ImGui::InputText(label_cstr, buf->Vector->Data, buf->Vector->capacity());

		if (ret)
			buf->String = nullptr;

		return ret;
	}

	/*static*/ bool ImGui::InputTextMultiline(ImString^ label, Span<unsigned char> buf, ImVec2 size, ImGuiInputTextFlags flags, InputTextDelegate^ callback)
	{
		CSTR_DECODE_TEMP(label);
		SPAN_GET_PTR(unsigned char, char, buf);

		return ::ImGui::InputTextMultiline(label_cstr, buf_ptr, buf.Length, size, (OGImGuiInputTextFlags)flags, InputTextCallback, callback ? Marshal::GetFunctionPointerForDelegate(callback).ToPointer() : nullptr);
	}

	/*static*/ bool ImGui::InputTextMultiline(ImString^ label, Span<unsigned char> buf, ImVec2 size, ImGuiInputTextFlags flags)
	{
		CSTR_DECODE_TEMP(label);
		SPAN_GET_PTR(unsigned char, char, buf);

		return ::ImGui::InputTextMultiline(label_cstr, buf_ptr, buf.Length, size, (OGImGuiInputTextFlags)flags);
	}

	/*static*/ bool ImGui::InputTextMultiline(ImString^ label, Span<unsigned char> buf, ImVec2 size)
	{
		CSTR_DECODE_TEMP(label);
		SPAN_GET_PTR(unsigned char, char, buf);

		return ::ImGui::InputTextMultiline(label_cstr, buf_ptr, buf.Length, size);
	}

	/*static*/ bool ImGui::InputTextMultiline(ImString^ label, Span<unsigned char> buf)
	{
		CSTR_DECODE_TEMP(label);
		SPAN_GET_PTR(unsigned char, char, buf);

		return ::ImGui::InputTextMultiline(label_cstr, buf_ptr, buf.Length);
	}

	/*static*/ bool ImGui::InputTextMultiline(ImString^ label, ImString^ buf, ImVec2 size, ImGuiInputTextFlags flags, InputTextDelegate^ callback)
	{
		temp.buf = buf->Vector;
		temp.callback = callback ? Marshal::GetFunctionPointerForDelegate(callback) : IntPtr::Zero;

		CSTR_DECODE_TEMP(label);

		auto ret = ::ImGui::InputTextMultiline(label_cstr, buf->Vector->Data, buf->Vector->capacity(), size, (OGImGuiInputTextFlags)flags, InputTextCallback);

		if (ret)
			buf->String = nullptr;

		return ret;
	}

	/*static*/ bool ImGui::InputTextMultiline(ImString^ label, ImString^ buf, ImVec2 size, ImGuiInputTextFlags flags)
	{
		temp.buf = buf->Vector;
		temp.callback = IntPtr::Zero;

		CSTR_DECODE_TEMP(label);

		auto ret = ::ImGui::InputTextMultiline(label_cstr, buf->Vector->Data, buf->Vector->capacity(), size, (OGImGuiInputTextFlags)flags, InputTextCallback);

		if (ret)
			buf->String = nullptr;

		return ret;
	}

	/*static*/ bool ImGui::InputTextMultiline(ImString^ label, ImString^ buf, ImVec2 size)
	{
		temp.buf = buf->Vector;
		temp.callback = IntPtr::Zero;

		CSTR_DECODE_TEMP(label);

		auto ret = ::ImGui::InputTextMultiline(label_cstr, buf->Vector->Data, buf->Vector->capacity(), size);

		if (ret)
			buf->String = nullptr;

		return ret;
	}

	/*static*/ bool ImGui::InputTextMultiline(ImString^ label, ImString^ buf)
	{
		temp.buf = buf->Vector;
		temp.callback = IntPtr::Zero;

		CSTR_DECODE_TEMP(label);

		auto ret = ::ImGui::InputTextMultiline(label_cstr, buf->Vector->Data, buf->Vector->capacity());

		if (ret)
			buf->String = nullptr;

		return ret;
	}

	/*static*/ bool ImGui::InputTextWithHint(ImString^ label, ImString^ hint, Span<unsigned char> buf, ImGuiInputTextFlags flags, InputTextDelegate^ callback)
	{
		CSTR_DECODE_TEMP(label);
		CSTR_DECODE_TEMP(hint);
		SPAN_GET_PTR(unsigned char, char, buf);

		return ::ImGui::InputTextWithHint(label_cstr, hint_cstr, buf_ptr, buf.Length, (OGImGuiInputTextFlags)flags, InputTextCallback, callback ? Marshal::GetFunctionPointerForDelegate(callback).ToPointer() : nullptr);
	}

	/*static*/ bool ImGui::InputTextWithHint(ImString^ label, ImString^ hint, Span<unsigned char> buf, ImGuiInputTextFlags flags)
	{
		CSTR_DECODE_TEMP(label);
		CSTR_DECODE_TEMP(hint);
		SPAN_GET_PTR(unsigned char, char, buf);

		return ::ImGui::InputTextWithHint(label_cstr, hint_cstr, buf_ptr, buf.Length, (OGImGuiInputTextFlags)flags);
	}

	/*static*/ bool ImGui::InputTextWithHint(ImString^ label, ImString^ hint, Span<unsigned char> buf)
	{
		CSTR_DECODE_TEMP(label);
		CSTR_DECODE_TEMP(hint);
		SPAN_GET_PTR(unsigned char, char, buf);

		return ::ImGui::InputTextWithHint(label_cstr, hint_cstr, buf_ptr, buf.Length);
	}

	/*static*/ bool ImGui::InputTextWithHint(ImString^ label, ImString^ hint, ImString^ buf, ImGuiInputTextFlags flags, InputTextDelegate^ callback)
	{
		temp.buf = buf->Vector;
		temp.callback = callback ? Marshal::GetFunctionPointerForDelegate(callback) : IntPtr::Zero;

		CSTR_DECODE_TEMP(label);
		CSTR_DECODE_TEMP(hint);

		auto ret = ::ImGui::InputTextWithHint(label_cstr, hint_cstr, buf->Vector->Data, buf->Vector->capacity(), (OGImGuiInputTextFlags)flags, InputTextCallback);

		if (ret)
			buf->String = nullptr;

		return ret;
	}

	/*static*/ bool ImGui::InputTextWithHint(ImString^ label, ImString^ hint, ImString^ buf, ImGuiInputTextFlags flags)
	{
		temp.buf = buf->Vector;
		temp.callback = IntPtr::Zero;

		CSTR_DECODE_TEMP(label);
		CSTR_DECODE_TEMP(hint);

		auto ret = ::ImGui::InputTextWithHint(label_cstr, hint_cstr, buf->Vector->Data, buf->Vector->capacity(), (OGImGuiInputTextFlags)flags, InputTextCallback);

		if (ret)
			buf->String = nullptr;

		return ret;
	}

	/*static*/ bool ImGui::InputTextWithHint(ImString^ label, ImString^ hint, ImString^ buf)
	{
		temp.buf = buf->Vector;
		temp.callback = IntPtr::Zero;

		CSTR_DECODE_TEMP(label);
		CSTR_DECODE_TEMP(hint);

		auto ret = ::ImGui::InputTextWithHint(label_cstr, hint_cstr, buf->Vector->Data, buf->Vector->capacity());

		if (ret)
			buf->String = nullptr;

		return ret;
	}

	generic<typename T> /*static*/ bool ImGui::InputScalar(ImString^ label, ImGuiDataType data_type, T% p_data, T p_step, T p_step_fast, ImString^ format, ImGuiInputTextFlags flags)
	{
		CSTR_DECODE_TEMP(label);
		CSTR_DECODE_TEMP(format);
		REF_PIN(T, T, p_data);
		REF_PIN(T, const T, p_step);
		REF_PIN(T, const T, p_step_fast);

		return ::ImGui::InputScalar(label_cstr, (OGImGuiDataType)data_type, p_data_ptr, p_step_ptr, p_step_fast_ptr, format_cstr, (OGImGuiInputTextFlags)flags);
	}

	generic<typename T> /*static*/ bool ImGui::InputScalar(ImString^ label, ImGuiDataType data_type, T% p_data, T p_step, T p_step_fast, ImString^ format)
	{
		CSTR_DECODE_TEMP(label);
		CSTR_DECODE_TEMP(format);
		REF_PIN(T, T, p_data);
		REF_PIN(T, const T, p_step);
		REF_PIN(T, const T, p_step_fast);

		return ::ImGui::InputScalar(label_cstr, (OGImGuiDataType)data_type, p_data_ptr, p_step_ptr, p_step_fast_ptr, format_cstr);
	}

	generic<typename T> /*static*/ bool ImGui::InputScalar(ImString^ label, ImGuiDataType data_type, T% p_data, T p_step, T p_step_fast)
	{
		CSTR_DECODE_TEMP(label);
		REF_PIN(T, T, p_data);
		REF_PIN(T, const T, p_step);
		REF_PIN(T, const T, p_step_fast);

		return ::ImGui::InputScalar(label_cstr, (OGImGuiDataType)data_type, p_data_ptr, p_step_ptr, p_step_fast_ptr);
	}

	generic<typename T> /*static*/ bool ImGui::InputScalar(ImString^ label, ImGuiDataType data_type, T% p_data, T p_step)
	{
		CSTR_DECODE_TEMP(label);
		REF_PIN(T, T, p_data);
		REF_PIN(T, const T, p_step);

		return ::ImGui::InputScalar(label_cstr, (OGImGuiDataType)data_type, p_data_ptr, p_step_ptr);
	}

	generic<typename T> /*static*/ bool ImGui::InputScalar(ImString^ label, ImGuiDataType data_type, T% p_data)
	{
		CSTR_DECODE_TEMP(label);
		REF_PIN(T, T, p_data);

		return ::ImGui::InputScalar(label_cstr, (OGImGuiDataType)data_type, p_data_ptr);
	}

	generic<typename T> /*static*/ bool ImGui::InputScalarN(ImString^ label, ImGuiDataType data_type, Span<T> p_data, T p_step, T p_step_fast, ImString^ format, ImGuiInputTextFlags flags)
	{
		CSTR_DECODE_TEMP(label);
		CSTR_DECODE_TEMP(format);
		SPAN_GET_PTR(T, void, p_data);
		REF_PIN(T, const T, p_step);
		REF_PIN(T, const T, p_step_fast);
		return ::ImGui::InputScalarN(label_cstr, (OGImGuiDataType)data_type, p_data_ptr, p_data.Length, p_step_ptr, p_step_fast_ptr, format_cstr, (OGImGuiInputTextFlags)flags);
	}

	generic<typename T> /*static*/ bool ImGui::InputScalarN(ImString^ label, ImGuiDataType data_type, Span<T> p_data, T p_step, T p_step_fast, ImString^ format)
	{
		CSTR_DECODE_TEMP(label);
		CSTR_DECODE_TEMP(format);
		SPAN_GET_PTR(T, void, p_data);
		REF_PIN(T, const T, p_step);
		REF_PIN(T, const T, p_step_fast);
		return ::ImGui::InputScalarN(label_cstr, (OGImGuiDataType)data_type, p_data_ptr, p_data.Length, p_step_ptr, p_step_fast_ptr, format_cstr);
	}

	generic<typename T> /*static*/ bool ImGui::InputScalarN(ImString^ label, ImGuiDataType data_type, Span<T> p_data, T p_step, T p_step_fast)
	{
		CSTR_DECODE_TEMP(label);
		SPAN_GET_PTR(T, void, p_data);
		REF_PIN(T, const T, p_step);
		REF_PIN(T, const T, p_step_fast);
		return ::ImGui::InputScalarN(label_cstr, (OGImGuiDataType)data_type, p_data_ptr, p_data.Length, p_step_ptr, p_step_fast_ptr);
	}

	generic<typename T> /*static*/ bool ImGui::InputScalarN(ImString^ label, ImGuiDataType data_type, Span<T> p_data, T p_step)
	{
		CSTR_DECODE_TEMP(label);
		SPAN_GET_PTR(T, void, p_data);
		REF_PIN(T, const T, p_step);
		return ::ImGui::InputScalarN(label_cstr, (OGImGuiDataType)data_type, p_data_ptr, p_data.Length, p_step_ptr);
	}

	generic<typename T> /*static*/ bool ImGui::InputScalarN(ImString^ label, ImGuiDataType data_type, Span<T> p_data)
	{
		CSTR_DECODE_TEMP(label);
		SPAN_GET_PTR(T, void, p_data);
		return ::ImGui::InputScalarN(label_cstr, (OGImGuiDataType)data_type, p_data_ptr, p_data.Length);
	}

	/*static*/ bool ImGui::SliderAngle(ImString^ label, float% v_rad, float v_degrees_min, float v_degrees_max, ImString^ format)
	{
		CSTR_DECODE_TEMP(label);
		REF_PIN(float, float, v_rad);
		CSTR_DECODE_TEMP(format);
		return ::ImGui::SliderAngle(label_cstr, v_rad_ptr, v_degrees_min, v_degrees_max, format_cstr);
	}
	/*static*/ bool ImGui::SliderAngle(ImString^ label, float% v_rad, float v_degrees_min, float v_degrees_max)
	{
		CSTR_DECODE_TEMP(label);
		REF_PIN(float, float, v_rad);
		return ::ImGui::SliderAngle(label_cstr, v_rad_ptr, v_degrees_min, v_degrees_max);
	}
	/*static*/ bool ImGui::SliderAngle(ImString^ label, float% v_rad, float v_degrees_min)
	{
		CSTR_DECODE_TEMP(label);
		REF_PIN(float, float, v_rad);
		return ::ImGui::SliderAngle(label_cstr, v_rad_ptr, v_degrees_min);
	}
	/*static*/ bool ImGui::SliderAngle(ImString^ label, float% v_rad)
	{
		CSTR_DECODE_TEMP(label);
		REF_PIN(float, float, v_rad);
		return ::ImGui::SliderAngle(label_cstr, v_rad_ptr);
	}

	generic<typename T> /*static*/ bool ImGui::SliderScalar(ImString^ label, ImGuiDataType data_type, T% p_data, T p_min, T p_max, ImString^ format, float power)
	{
		CSTR_DECODE_TEMP(label);
		REF_PIN(T, T, p_data);
		REF_PIN(T, const T, p_min);
		REF_PIN(T, const T, p_max);
		CSTR_DECODE_TEMP(format);
		return ::ImGui::SliderScalar(label_cstr, (OGImGuiDataType)data_type, p_data_ptr, p_min_ptr, p_max_ptr, format_cstr, power);
	}

	generic<typename T> /*static*/ bool ImGui::SliderScalar(ImString^ label, ImGuiDataType data_type, T% p_data, T p_min, T p_max, ImString^ format)
	{
		CSTR_DECODE_TEMP(label);
		REF_PIN(T, T, p_data);
		REF_PIN(T, const T, p_min);
		REF_PIN(T, const T, p_max);
		CSTR_DECODE_TEMP(format);
		return ::ImGui::SliderScalar(label_cstr, (OGImGuiDataType)data_type, p_data_ptr, p_min_ptr, p_max_ptr, format_cstr);
	}

	generic<typename T> /*static*/ bool ImGui::SliderScalar(ImString^ label, ImGuiDataType data_type, T% p_data, T p_min, T p_max)
	{
		CSTR_DECODE_TEMP(label);
		REF_PIN(T, T, p_data);
		REF_PIN(T, const T, p_min);
		REF_PIN(T, const T, p_max);
		return ::ImGui::SliderScalar(label_cstr, (OGImGuiDataType)data_type, p_data_ptr, p_min_ptr, p_max_ptr);
	}

	generic<typename T> /*static*/ bool ImGui::SliderScalarN(ImString^ label, ImGuiDataType data_type, Span<T> p_data, T p_min, T p_max, ImString^ format, float power)
	{
		CSTR_DECODE_TEMP(label);
		SPAN_GET_PTR(T, void, p_data);
		REF_PIN(T, const T, p_min);
		REF_PIN(T, const T, p_max);
		CSTR_DECODE_TEMP(format);
		return ::ImGui::SliderScalarN(label_cstr, (OGImGuiDataType)data_type, p_data_ptr, p_data.Length, p_min_ptr, p_max_ptr, format_cstr, power);
	}

	generic<typename T> /*static*/ bool ImGui::SliderScalarN(ImString^ label, ImGuiDataType data_type, Span<T> p_data, T p_min, T p_max, ImString^ format)
	{
		CSTR_DECODE_TEMP(label);
		SPAN_GET_PTR(T, void, p_data);
		REF_PIN(T, const T, p_min);
		REF_PIN(T, const T, p_max);
		CSTR_DECODE_TEMP(format);
		return ::ImGui::SliderScalarN(label_cstr, (OGImGuiDataType)data_type, p_data_ptr, p_data.Length, p_min_ptr, p_max_ptr, format_cstr);
	}

	generic<typename T> /*static*/ bool ImGui::SliderScalarN(ImString^ label, ImGuiDataType data_type, Span<T> p_data, T p_min, T p_max)
	{
		CSTR_DECODE_TEMP(label);
		SPAN_GET_PTR(T, void, p_data);
		REF_PIN(T, const T, p_min);
		REF_PIN(T, const T, p_max);
		return ::ImGui::SliderScalarN(label_cstr, (OGImGuiDataType)data_type, p_data_ptr, p_data.Length, p_min_ptr, p_max_ptr);
	}

	generic<typename T> /*static*/ bool ImGui::VSliderScalar(ImString^ label, ImVec2 size, ImGuiDataType data_type, T% p_data, T p_min, T p_max, ImString^ format, float power)
	{
		CSTR_DECODE_TEMP(label);
		REF_PIN(T, T, p_data);
		REF_PIN(T, const T, p_min);
		REF_PIN(T, const T, p_max);
		CSTR_DECODE_TEMP(format);
		return ::ImGui::VSliderScalar(label_cstr, size, (OGImGuiDataType)data_type, p_data_ptr, p_min_ptr, p_max_ptr, format_cstr, power);
	}

	generic<typename T> /*static*/ bool ImGui::VSliderScalar(ImString^ label, ImVec2 size, ImGuiDataType data_type, T% p_data, T p_min, T p_max, ImString^ format)
	{
		CSTR_DECODE_TEMP(label);
		REF_PIN(T, T, p_data);
		REF_PIN(T, const T, p_min);
		REF_PIN(T, const T, p_max);
		CSTR_DECODE_TEMP(format);
		return ::ImGui::VSliderScalar(label_cstr, size, (OGImGuiDataType)data_type, p_data_ptr, p_min_ptr, p_max_ptr, format_cstr);
	}

	generic<typename T> /*static*/ bool ImGui::VSliderScalar(ImString^ label, ImVec2 size, ImGuiDataType data_type, T% p_data, T p_min, T p_max)
	{
		CSTR_DECODE_TEMP(label);
		REF_PIN(T, T, p_data);
		REF_PIN(T, const T, p_min);
		REF_PIN(T, const T, p_max);
		return ::ImGui::VSliderScalar(label_cstr, size, (OGImGuiDataType)data_type, p_data_ptr, p_min_ptr, p_max_ptr);
	}


	/*static*/ bool ImGui::ColorEdit3(ImString^ label, Span<float> col, ImGuiColorEditFlags flags)
	{
		IMSTR_DECODE_TEMP(label);
		SPAN_GET_PTR(float, float, col);
		return ::ImGui::ColorEdit3(label_cstr, col_ptr, (OGImGuiColorEditFlags)flags);
	}

	/*static*/ bool ImGui::ColorEdit3(ImString^ label, Span<float> col)
	{
		IMSTR_DECODE_TEMP(label);
		SPAN_GET_PTR(float, float, col);
		return ::ImGui::ColorEdit3(label_cstr, col_ptr);
	}

	/*static*/ bool ImGui::ColorEdit4(ImString^ label, Span<float> col, ImGuiColorEditFlags flags)
	{
		IMSTR_DECODE_TEMP(label);
		SPAN_GET_PTR(float, float, col);
		return ::ImGui::ColorEdit4(label_cstr, col_ptr, (OGImGuiColorEditFlags)flags);
	}

	/*static*/ bool ImGui::ColorEdit4(ImString^ label, Span<float> col)
	{
		IMSTR_DECODE_TEMP(label);
		SPAN_GET_PTR(float, float, col);
		return ::ImGui::ColorEdit4(label_cstr, col_ptr);
	}

	/*static*/ bool ImGui::ColorPicker3(ImString^ label, Span<float> col, ImGuiColorEditFlags flags)
	{
		IMSTR_DECODE_TEMP(label);
		SPAN_GET_PTR(float, float, col);
		return ::ImGui::ColorPicker3(label_cstr, col_ptr, (OGImGuiColorEditFlags)flags);
	}

	/*static*/ bool ImGui::ColorPicker3(ImString^ label, Span<float> col)
	{
		IMSTR_DECODE_TEMP(label);
		SPAN_GET_PTR(float, float, col);
		return ::ImGui::ColorPicker3(label_cstr, col_ptr);
	}

	/*static*/ bool ImGui::ColorPicker4(ImString^ label, Span<float> col, ImGuiColorEditFlags flags, ReadOnlySpan<float> ref_col)
	{
		IMSTR_DECODE_TEMP(label);
		SPAN_GET_PTR(float, float, col);
		SPAN_GET_PTR(float, float, ref_col);
		return ::ImGui::ColorPicker4(label_cstr, col_ptr, (OGImGuiColorEditFlags)flags, ref_col_ptr);
	}

	/*static*/ bool ImGui::ColorPicker4(ImString^ label, Span<float> col, ImGuiColorEditFlags flags)
	{
		IMSTR_DECODE_TEMP(label);
		SPAN_GET_PTR(float, float, col);
		return ::ImGui::ColorPicker4(label_cstr, col_ptr, (OGImGuiColorEditFlags)flags);
	}

	/*static*/ bool ImGui::ColorPicker4(ImString^ label, Span<float> col)
	{
		IMSTR_DECODE_TEMP(label);
		SPAN_GET_PTR(float, float, col);
		return ::ImGui::ColorPicker4(label_cstr, col_ptr);
	}

	/*static*/ bool ImGui::ColorButton(ImString^ desc_id, ImVec4 col, ImGuiColorEditFlags flags, ImVec2 size)
	{
		IMSTR_DECODE_TEMP(desc_id);
		return ::ImGui::ColorButton(desc_id_cstr, col, (OGImGuiColorEditFlags)flags, size);
	}

	/*static*/ bool ImGui::ColorButton(ImString^ desc_id, ImVec4 col, ImGuiColorEditFlags flags)
	{
		IMSTR_DECODE_TEMP(desc_id);
		return ::ImGui::ColorButton(desc_id_cstr, col, (OGImGuiColorEditFlags)flags);
	}

	/*static*/ bool ImGui::ColorButton(ImString^ desc_id, ImVec4 col)
	{
		IMSTR_DECODE_TEMP(desc_id);
		return ::ImGui::ColorButton(desc_id_cstr, col);
	}

	/*static*/ void ImGui::SetColorEditOptions(ImGuiColorEditFlags flags)
	{
		::ImGui::SetColorEditOptions((OGImGuiColorEditFlags)flags);
	}

	/*static*/ bool ImGui::TreeNode(ImString^ label)
	{
		IMSTR_DECODE_TEMP(label);
		return ::ImGui::TreeNode(label_cstr);
	}

	/*static*/ bool ImGui::TreeNodeEx(ImString^ label, ImGuiTreeNodeFlags flags)
	{
		IMSTR_DECODE_TEMP(label);
		return ::ImGui::TreeNodeEx(label_cstr, (OGImGuiTreeNodeFlags)flags);
	}

	/*static*/ bool ImGui::TreeNodeEx(ImString^ label)
	{
		IMSTR_DECODE_TEMP(label);
		return ::ImGui::TreeNodeEx(label_cstr);
	}

	/*static*/ void ImGui::TreePush(ImString^ str_id)
	{
		IMSTR_DECODE_TEMP(str_id);
		::ImGui::TreePush(str_id_cstr);
	}

	/*static*/ void ImGui::TreePush()
	{
		::ImGui::TreePush();
	}

	/*static*/ void ImGui::TreePop()
	{
		::ImGui::TreePop();
	}

	/*static*/ float ImGui::GetTreeNodeToLabelSpacing()
	{
		return ::ImGui::GetTreeNodeToLabelSpacing();
	}

	/*static*/ bool ImGui::CollapsingHeader(ImString^ label, ImGuiTreeNodeFlags flags)
	{
		IMSTR_DECODE_TEMP(label);
		return ::ImGui::CollapsingHeader(label_cstr, (OGImGuiTreeNodeFlags)flags);
	}

	/*static*/ bool ImGui::CollapsingHeader(ImString^ label)
	{
		IMSTR_DECODE_TEMP(label);
		return ::ImGui::CollapsingHeader(label_cstr);
	}

	/*static*/ bool ImGui::CollapsingHeader(ImString^ label, bool% p_open, ImGuiTreeNodeFlags flags)
	{
		IMSTR_DECODE_TEMP(label);
		REF_VAL_INIT(p_open);
		auto ret = ::ImGui::CollapsingHeader(label_cstr, &out_p_open, (OGImGuiTreeNodeFlags)flags);
		REF_VAL_COPY(p_open);
		return ret;
	}

	/*static*/ bool ImGui::CollapsingHeader(ImString^ label, bool% p_open)
	{
		IMSTR_DECODE_TEMP(label);
		REF_VAL_INIT(p_open);
		auto ret = ::ImGui::CollapsingHeader(label_cstr, &out_p_open);
		REF_VAL_COPY(p_open);
		return ret;
	}

	/*static*/ void ImGui::SetNextItemOpen(bool is_open, ImGuiCond cond)
	{
		::ImGui::SetNextItemOpen(is_open, (OGImGuiCond)cond);
	}

	/*static*/ void ImGui::SetNextItemOpen(bool is_open)
	{
		::ImGui::SetNextItemOpen(is_open);
	}

	/*static*/ bool ImGui::Selectable(ImString^ label, bool selected, ImGuiSelectableFlags flags, ImVec2 size)
	{
		IMSTR_DECODE_TEMP(label);
		return ::ImGui::Selectable(label_cstr, selected, (OGImGuiSelectableFlags)flags, size);
	}

	/*static*/ bool ImGui::Selectable(ImString^ label, bool selected, ImGuiSelectableFlags flags)
	{
		IMSTR_DECODE_TEMP(label);
		return ::ImGui::Selectable(label_cstr, selected, (OGImGuiSelectableFlags)flags);
	}

	/*static*/ bool ImGui::Selectable(ImString^ label, bool selected)
	{
		IMSTR_DECODE_TEMP(label);
		return ::ImGui::Selectable(label_cstr, selected);
	}

	/*static*/ bool ImGui::Selectable(ImString^ label)
	{
		IMSTR_DECODE_TEMP(label);
		return ::ImGui::Selectable(label_cstr);
	}

	/*static*/ bool ImGui::Selectable(ImString^ label, bool% p_selected, ImGuiSelectableFlags flags, ImVec2 size)
	{
		IMSTR_DECODE_TEMP(label);
		REF_VAL_INIT(p_selected);
		auto ret = ::ImGui::Selectable(label_cstr, &out_p_selected, (OGImGuiSelectableFlags)flags, size);
		REF_VAL_COPY(p_selected);
		return ret;
	}

	/*static*/ bool ImGui::Selectable(ImString^ label, bool% p_selected, ImGuiSelectableFlags flags)
	{
		IMSTR_DECODE_TEMP(label);
		REF_VAL_INIT(p_selected);
		auto ret = ::ImGui::Selectable(label_cstr, &out_p_selected, (OGImGuiSelectableFlags)flags);
		REF_VAL_COPY(p_selected);
		return ret;
	}

	/*static*/ bool ImGui::Selectable(ImString^ label, bool% p_selected)
	{
		IMSTR_DECODE_TEMP(label);
		REF_VAL_INIT(p_selected);
		auto ret = ::ImGui::Selectable(label_cstr, &out_p_selected);
		REF_VAL_COPY(p_selected);
		return ret;
	}

	/*static*/ bool ImGui::ListBox(ImString^ label, int% current_item, ListBoxGetter^ items_getter, int items_count, int height_in_items)
	{
		IMSTR_DECODE_TEMP(label);
		REF_VAL_INIT(current_item);
		GET_CB_FUNC_PTR(items_getter);
		auto ret = ::ImGui::ListBox(label_cstr, &out_current_item, ListBoxGetterWrap, items_getter_ptr, items_count, height_in_items);
		REF_VAL_COPY(current_item);
		return ret;
	}
	/*static*/ bool ImGui::ListBox(ImString^ label, int% current_item, ListBoxGetter^ items_getter, int items_count)
	{
		IMSTR_DECODE_TEMP(label);
		REF_VAL_INIT(current_item);
		GET_CB_FUNC_PTR(items_getter);
		auto ret = ::ImGui::ListBox(label_cstr, &out_current_item, ListBoxGetterWrap, items_getter_ptr, items_count);
		REF_VAL_COPY(current_item);
		return ret;
	}
	/*static*/ bool ImGui::ListBoxHeader(ImString^ label, ImVec2 size)
	{
		IMSTR_DECODE_TEMP(label);
		return ::ImGui::ListBoxHeader(label_cstr, size);
	}
	/*static*/ bool ImGui::ListBoxHeader(ImString^ label)
	{
		IMSTR_DECODE_TEMP(label);
		return ::ImGui::ListBoxHeader(label_cstr);
	}
	/*static*/ bool ImGui::ListBoxHeader(ImString^ label, int items_count, int height_in_items)
	{
		IMSTR_DECODE_TEMP(label);
		return ::ImGui::ListBoxHeader(label_cstr, items_count, height_in_items);
	}
	/*static*/ bool ImGui::ListBoxHeader(ImString^ label, int items_count)
	{
		IMSTR_DECODE_TEMP(label);
		return ::ImGui::ListBoxHeader(label_cstr, items_count);
	}
	/*static*/ void ImGui::ListBoxFooter()
	{
		::ImGui::ListBoxFooter();
	}

	static float PlotGetterWrap(void* func, int idx)
	{
		return Marshal::GetDelegateForFunctionPointer<PlotGetter^>((IntPtr)func)(idx);
	}

	/*static*/ void ImGui::PlotLines(ImString^ label, PlotGetter^ values_getter, int values_count, int values_offset, ImString^ overlay_text, float scale_min, float scale_max, ImVec2 graph_size)
	{
		IMSTR_DECODE_TEMP(label);
		IMSTR_DECODE_TEMP(overlay_text);
		GET_CB_FUNC_PTR(values_getter);
		::ImGui::PlotLines(label_cstr, PlotGetterWrap, values_getter_ptr, values_count, values_offset, overlay_text_cstr, scale_min, scale_max, graph_size);
	}

	/*static*/ void ImGui::PlotLines(ImString^ label, PlotGetter^ values_getter, int values_count, int values_offset, ImString^ overlay_text, float scale_min, float scale_max)
	{
		IMSTR_DECODE_TEMP(label);
		IMSTR_DECODE_TEMP(overlay_text);
		GET_CB_FUNC_PTR(values_getter);
		::ImGui::PlotLines(label_cstr, PlotGetterWrap, values_getter_ptr, values_count, values_offset, overlay_text_cstr, scale_min, scale_max);
	}

	/*static*/ void ImGui::PlotLines(ImString^ label, PlotGetter^ values_getter, int values_count, int values_offset, ImString^ overlay_text, float scale_min)
	{
		IMSTR_DECODE_TEMP(label);
		IMSTR_DECODE_TEMP(overlay_text);
		GET_CB_FUNC_PTR(values_getter);
		::ImGui::PlotLines(label_cstr, PlotGetterWrap, values_getter_ptr, values_count, values_offset, overlay_text_cstr, scale_min);
	}

	/*static*/ void ImGui::PlotLines(ImString^ label, PlotGetter^ values_getter, int values_count, int values_offset, ImString^ overlay_text)
	{
		IMSTR_DECODE_TEMP(label);
		IMSTR_DECODE_TEMP(overlay_text);
		GET_CB_FUNC_PTR(values_getter);
		::ImGui::PlotLines(label_cstr, PlotGetterWrap, values_getter_ptr, values_count, values_offset, overlay_text_cstr);
	}

	/*static*/ void ImGui::PlotLines(ImString^ label, PlotGetter^ values_getter, int values_count, int values_offset)
	{
		IMSTR_DECODE_TEMP(label);
		GET_CB_FUNC_PTR(values_getter);
		::ImGui::PlotLines(label_cstr, PlotGetterWrap, values_getter_ptr, values_count, values_offset);
	}

	/*static*/ void ImGui::PlotLines(ImString^ label, PlotGetter^ values_getter, int values_count)
	{
		IMSTR_DECODE_TEMP(label);
		GET_CB_FUNC_PTR(values_getter);
		::ImGui::PlotLines(label_cstr, PlotGetterWrap, values_getter_ptr, values_count);
	}

	/*static*/ void ImGui::PlotHistogram(ImString^ label, PlotGetter^ values_getter, int values_count, int values_offset, ImString^ overlay_text, float scale_min, float scale_max, ImVec2 graph_size)
	{
		IMSTR_DECODE_TEMP(label);
		IMSTR_DECODE_TEMP(overlay_text);
		GET_CB_FUNC_PTR(values_getter);
		::ImGui::PlotHistogram(label_cstr, PlotGetterWrap, values_getter_ptr, values_count, values_offset, overlay_text_cstr, scale_min, scale_max, graph_size);
	}

	/*static*/ void ImGui::PlotHistogram(ImString^ label, PlotGetter^ values_getter, int values_count, int values_offset, ImString^ overlay_text, float scale_min, float scale_max)
	{
		IMSTR_DECODE_TEMP(label);
		IMSTR_DECODE_TEMP(overlay_text);
		GET_CB_FUNC_PTR(values_getter);
		::ImGui::PlotHistogram(label_cstr, PlotGetterWrap, values_getter_ptr, values_count, values_offset, overlay_text_cstr, scale_min, scale_max);
	}

	/*static*/ void ImGui::PlotHistogram(ImString^ label, PlotGetter^ values_getter, int values_count, int values_offset, ImString^ overlay_text, float scale_min)
	{
		IMSTR_DECODE_TEMP(label);
		IMSTR_DECODE_TEMP(overlay_text);
		GET_CB_FUNC_PTR(values_getter);
		::ImGui::PlotHistogram(label_cstr, PlotGetterWrap, values_getter_ptr, values_count, values_offset, overlay_text_cstr, scale_min);
	}

	/*static*/ void ImGui::PlotHistogram(ImString^ label, PlotGetter^ values_getter, int values_count, int values_offset, ImString^ overlay_text)
	{
		IMSTR_DECODE_TEMP(label);
		IMSTR_DECODE_TEMP(overlay_text);
		GET_CB_FUNC_PTR(values_getter);
		::ImGui::PlotHistogram(label_cstr, PlotGetterWrap, values_getter_ptr, values_count, values_offset, overlay_text_cstr);
	}

	/*static*/ void ImGui::PlotHistogram(ImString^ label, PlotGetter^ values_getter, int values_count, int values_offset)
	{
		IMSTR_DECODE_TEMP(label);
		GET_CB_FUNC_PTR(values_getter);
		::ImGui::PlotHistogram(label_cstr, PlotGetterWrap, values_getter_ptr, values_count, values_offset);
	}

	/*static*/ void ImGui::PlotHistogram(ImString^ label, PlotGetter^ values_getter, int values_count)
	{
		IMSTR_DECODE_TEMP(label);
		GET_CB_FUNC_PTR(values_getter);
		::ImGui::PlotHistogram(label_cstr, PlotGetterWrap, values_getter_ptr, values_count);
	}

	/*static*/ void ImGui::Value(ImString^ prefix, bool b)
	{
		IMSTR_DECODE_TEMP(prefix);
		::ImGui::Value(prefix_cstr, b);
	}

	/*static*/ void ImGui::Value(ImString^ prefix, int v)
	{
		IMSTR_DECODE_TEMP(prefix);
		::ImGui::Value(prefix_cstr, v);
	}

	/*static*/ void ImGui::Value(ImString^ prefix, unsigned int v)
	{
		IMSTR_DECODE_TEMP(prefix);
		::ImGui::Value(prefix_cstr, v);
	}

	/*static*/ void ImGui::Value(ImString^ prefix, float v, ImString^ float_format)
	{
		IMSTR_DECODE_TEMP(prefix);
		IMSTR_DECODE_TEMP(float_format);
		::ImGui::Value(prefix_cstr, v, float_format_cstr);
	}

	/*static*/ void ImGui::Value(ImString^ prefix, float v)
	{
		IMSTR_DECODE_TEMP(prefix);
		::ImGui::Value(prefix_cstr, v);
	}

	/*static*/ bool ImGui::BeginMenuBar()
	{
		return ::ImGui::BeginMenuBar();
	}

	/*static*/ void ImGui::EndMenuBar()
	{
		::ImGui::EndMenuBar();
	}

	/*static*/ bool ImGui::BeginMainMenuBar()
	{
		return ::ImGui::BeginMainMenuBar();
	}

	/*static*/ void ImGui::EndMainMenuBar()
	{
		::ImGui::EndMainMenuBar();
	}

	/*static*/ bool ImGui::BeginMenu(ImString^ label, bool enabled)
	{
		IMSTR_DECODE_TEMP(label);
		return ::ImGui::BeginMenu(label_cstr, enabled);
	}

	/*static*/ bool ImGui::BeginMenu(ImString^ label)
	{
		IMSTR_DECODE_TEMP(label);
		return ::ImGui::BeginMenu(label_cstr);
	}

	/*static*/ void ImGui::EndMenu()
	{
		::ImGui::EndMenu();
	}

	/*static*/ bool ImGui::MenuItem(ImString^ label, ImString^ shortcut, bool selected, bool enabled)
	{
		IMSTR_DECODE_TEMP(label);
		IMSTR_DECODE_TEMP(shortcut);
		return ::ImGui::MenuItem(label_cstr, shortcut_cstr, selected, enabled);
	}

	/*static*/ bool ImGui::MenuItem(ImString^ label, ImString^ shortcut, bool selected)
	{
		IMSTR_DECODE_TEMP(label);
		IMSTR_DECODE_TEMP(shortcut);
		return ::ImGui::MenuItem(label_cstr, shortcut_cstr, selected);
	}

	/*static*/ bool ImGui::MenuItem(ImString^ label, ImString^ shortcut)
	{
		IMSTR_DECODE_TEMP(label);
		IMSTR_DECODE_TEMP(shortcut);
		return ::ImGui::MenuItem(label_cstr, shortcut_cstr);
	}

	/*static*/ bool ImGui::MenuItem(ImString^ label)
	{
		IMSTR_DECODE_TEMP(label);
		return ::ImGui::MenuItem(label_cstr);
	}

	/*static*/ bool ImGui::MenuItem(ImString^ label, ImString^ shortcut, bool% p_selected, bool enabled)
	{
		IMSTR_DECODE_TEMP(label);
		IMSTR_DECODE_TEMP(shortcut);
		REF_VAL_INIT(p_selected);
		auto ret = ::ImGui::MenuItem(label_cstr, shortcut_cstr, out_p_selected, enabled);
		REF_VAL_COPY(p_selected);
		return ret;
	}

	/*static*/ bool ImGui::MenuItem(ImString^ label, ImString^ shortcut, bool% p_selected)
	{
		IMSTR_DECODE_TEMP(label);
		IMSTR_DECODE_TEMP(shortcut);
		REF_VAL_INIT(p_selected);
		auto ret = ::ImGui::MenuItem(label_cstr, shortcut_cstr, out_p_selected);
		REF_VAL_COPY(p_selected);
		return ret;
	}

	/*static*/ void ImGui::BeginTooltip()
	{
		::ImGui::EndTooltip();
	}
	/*static*/ void ImGui::EndTooltip()
	{
		::ImGui::EndTooltip();
	}
	/*static*/ void ImGui::SetTooltip(ImString^ text)
	{
		IMSTR_DECODE_TEMP(text);
		::ImGui::SetTooltip("%s", text_cstr);
	}

	/*static*/ void ImGui::OpenPopup(ImString^ str_id)
	{
		IMSTR_DECODE_TEMP(str_id);
		::ImGui::OpenPopup(str_id_cstr);
	}
	/*static*/ bool ImGui::BeginPopup(ImString^ str_id, ImGuiWindowFlags flags)
	{
		IMSTR_DECODE_TEMP(str_id);
		return ::ImGui::BeginPopup(str_id_cstr, (OGImGuiWindowFlags)flags);
	}
	/*static*/ bool ImGui::BeginPopup(ImString^ str_id)
	{
		IMSTR_DECODE_TEMP(str_id);
		return ::ImGui::BeginPopup(str_id_cstr);
	}
	/*static*/ bool ImGui::BeginPopupContextItem(ImString^ str_id, ImGuiMouseButton mouse_button)
	{
		IMSTR_DECODE_TEMP(str_id);
		return ::ImGui::BeginPopupContextItem(str_id_cstr, (OGImGuiMouseButton)mouse_button);
	}
	/*static*/ bool ImGui::BeginPopupContextItem(ImString^ str_id)
	{
		IMSTR_DECODE_TEMP(str_id);
		return ::ImGui::BeginPopupContextItem(str_id_cstr);
	}
	/*static*/ bool ImGui::BeginPopupContextItem()
	{
		return ::ImGui::BeginPopupContextItem();
	}
	/*static*/ bool ImGui::BeginPopupContextWindow(ImString^ str_id, ImGuiMouseButton mouse_button, bool also_over_items)
	{
		IMSTR_DECODE_TEMP(str_id);
		return ::ImGui::BeginPopupContextWindow(str_id_cstr, (OGImGuiMouseButton)mouse_button, also_over_items);
	}
	/*static*/ bool ImGui::BeginPopupContextWindow(ImString^ str_id, ImGuiMouseButton mouse_button)
	{
		IMSTR_DECODE_TEMP(str_id);
		return ::ImGui::BeginPopupContextWindow(str_id_cstr, (OGImGuiMouseButton)mouse_button);
	}
	/*static*/ bool ImGui::BeginPopupContextWindow(ImString^ str_id)
	{
		IMSTR_DECODE_TEMP(str_id);
		return ::ImGui::BeginPopupContextWindow(str_id_cstr);
	}
	/*static*/ bool ImGui::BeginPopupContextWindow()
	{
		return ::ImGui::BeginPopupContextWindow();
	}
	/*static*/ bool ImGui::BeginPopupContextVoid(ImString^ str_id, ImGuiMouseButton mouse_button)
	{
		IMSTR_DECODE_TEMP(str_id);
		return ::ImGui::BeginPopupContextVoid(str_id_cstr, (OGImGuiMouseButton)mouse_button);
	}
	/*static*/ bool ImGui::BeginPopupContextVoid(ImString^ str_id)
	{
		IMSTR_DECODE_TEMP(str_id);
		return ::ImGui::BeginPopupContextVoid(str_id_cstr);
	}
	/*static*/ bool ImGui::BeginPopupContextVoid()
	{
		return ::ImGui::BeginPopupContextVoid();
	}
	/*static*/ bool ImGui::BeginPopupModal(ImString^ name, bool% p_open, ImGuiWindowFlags flags)
	{
		IMSTR_DECODE_TEMP(name);
		REF_VAL_INIT(p_open);
		auto ret = ::ImGui::BeginPopupModal(name_cstr, &out_p_open, (OGImGuiWindowFlags)flags);
		REF_VAL_COPY(p_open);
		return ret;
	}
	/*static*/ bool ImGui::BeginPopupModal(ImString^ name, bool% p_open)
	{
		IMSTR_DECODE_TEMP(name);
		REF_VAL_INIT(p_open);
		auto ret = ::ImGui::BeginPopupModal(name_cstr, &out_p_open);
		REF_VAL_COPY(p_open);
		return ret;
	}
	/*static*/ bool ImGui::BeginPopupModal(ImString^ name)
	{
		IMSTR_DECODE_TEMP(name);
		return ::ImGui::BeginPopupModal(name_cstr);
	}
	/*static*/ void ImGui::EndPopup()
	{
		::ImGui::EndPopup();
	}
	/*static*/ bool ImGui::OpenPopupOnItemClick(ImString^ str_id, ImGuiMouseButton mouse_button)
	{
		IMSTR_DECODE_TEMP(str_id);
		return ::ImGui::OpenPopupOnItemClick(str_id_cstr, (OGImGuiMouseButton)mouse_button);
	}
	/*static*/ bool ImGui::OpenPopupOnItemClick(ImString^ str_id)
	{
		IMSTR_DECODE_TEMP(str_id);
		return ::ImGui::OpenPopupOnItemClick(str_id_cstr);
	}
	/*static*/ bool ImGui::OpenPopupOnItemClick()
	{
		return ::ImGui::OpenPopupOnItemClick();
	}
	/*static*/ bool ImGui::IsPopupOpen(ImString^ str_id)
	{
		IMSTR_DECODE_TEMP(str_id);
		return ::ImGui::IsPopupOpen(str_id_cstr);
	}
	/*static*/ void ImGui::CloseCurrentPopup()
	{
		::ImGui::CloseCurrentPopup();
	}

	/*static*/ void ImGui::Columns(int count, ImString^ id, bool border)
	{
		IMSTR_DECODE_TEMP(id);
		::ImGui::Columns(count, id_cstr, border);
	}

	/*static*/ void ImGui::Columns(int count, ImString^ id)
	{
		IMSTR_DECODE_TEMP(id);
		::ImGui::Columns(count, id_cstr);
	}

	/*static*/ void ImGui::Columns(int count)
	{
		::ImGui::Columns(count);
	}

	/*static*/ void ImGui::Columns()
	{
		::ImGui::Columns();
	}

	/*static*/ void ImGui::NextColumn()
	{
		::ImGui::NextColumn();
	}

	/*static*/ int ImGui::GetColumnIndex()
	{
		return ::ImGui::GetColumnIndex();
	}

	/*static*/ float ImGui::GetColumnWidth(int column_index)
	{
		return ::ImGui::GetColumnWidth(column_index);
	}

	/*static*/ float ImGui::GetColumnWidth()
	{
		return ::ImGui::GetColumnWidth();
	}

	/*static*/ void ImGui::SetColumnWidth(int column_index, float width)
	{
		::ImGui::SetColumnWidth(column_index, width);
	}

	/*static*/ float ImGui::GetColumnOffset(int column_index)
	{
		return ::ImGui::GetColumnOffset(column_index);
	}

	/*static*/ float ImGui::GetColumnOffset()
	{
		return ::ImGui::GetColumnOffset();
	}

	/*static*/ void ImGui::SetColumnOffset(int column_index, float offset_x)
	{
		::ImGui::SetColumnOffset(column_index, offset_x);
	}

	/*static*/ int ImGui::GetColumnsCount()
	{
		return ::ImGui::GetColumnsCount();
	}

	/*static*/ bool ImGui::BeginTabBar(ImString^ str_id, ImGuiTabBarFlags flags)
	{
		IMSTR_DECODE_TEMP(str_id);
		return ::ImGui::BeginTabBar(str_id_cstr, (OGImGuiTabBarFlags)flags);
	}

	/*static*/ bool ImGui::BeginTabBar(ImString^ str_id)
	{
		IMSTR_DECODE_TEMP(str_id);
		return ::ImGui::BeginTabBar(str_id_cstr);
	}

	/*static*/ void ImGui::EndTabBar()
	{
		::ImGui::EndTabBar();
	}

	/*static*/ bool ImGui::BeginTabItem(ImString^ label, bool% p_open, ImGuiTabItemFlags flags)
	{
		IMSTR_DECODE_TEMP(label);
		REF_VAL_INIT(p_open);
		auto ret = ::ImGui::BeginTabItem(label_cstr, &out_p_open, (OGImGuiTabItemFlags)flags);
		REF_VAL_COPY(p_open);
		return ret;
	}

	/*static*/ bool ImGui::BeginTabItem(ImString^ label, bool% p_open)
	{
		IMSTR_DECODE_TEMP(label);
		REF_VAL_INIT(p_open);
		auto ret = ::ImGui::BeginTabItem(label_cstr, &out_p_open);
		REF_VAL_COPY(p_open);
		return ret;
	}

	/*static*/ bool ImGui::BeginTabItem(ImString^ label)
	{
		IMSTR_DECODE_TEMP(label);
		return ::ImGui::BeginTabItem(label_cstr);
	}

	/*static*/ void ImGui::EndTabItem()
	{
		::ImGui::EndTabItem();
	}

	/*static*/ void ImGui::SetTabItemClosed(ImString^ tab_or_docked_window_label)
	{
		IMSTR_DECODE_TEMP(tab_or_docked_window_label);
		::ImGui::SetTabItemClosed(tab_or_docked_window_label_cstr);
	}

	/*static*/ void ImGui::LogToTTY(int auto_open_depth)
	{
		::ImGui::LogToTTY(auto_open_depth);
	}

	/*static*/ void ImGui::LogToTTY()
	{
		::ImGui::LogToTTY();
	}

	/*static*/ void ImGui::LogToFile(int auto_open_depth, ImString^ filename)
	{
		IMSTR_DECODE_TEMP(filename);
		::ImGui::LogToFile(auto_open_depth, filename_cstr);
	}

	/*static*/ void ImGui::LogToFile(int auto_open_depth)
	{
		::ImGui::LogToFile(auto_open_depth);
	}

	/*static*/ void ImGui::LogToFile()
	{
		::ImGui::LogToFile();
	}

	/*static*/ void ImGui::LogToClipboard(int auto_open_depth)
	{
		::ImGui::LogToClipboard(auto_open_depth);
	}

	/*static*/ void ImGui::LogToClipboard()
	{
		::ImGui::LogToClipboard();
	}

	/*static*/ void ImGui::LogFinish()
	{
		::ImGui::LogFinish();
	}

	/*static*/ void ImGui::LogButtons()
	{
		::ImGui::LogButtons();
	}

	/*static*/ void ImGui::LogText(ImString^ text)
	{
		IMSTR_DECODE_TEMP(text);
		::ImGui::LogText("%s", text_cstr);
	}

	/*static*/ bool ImGui::BeginDragDropSource(ImGuiDragDropFlags flags)
	{
		return ::ImGui::BeginDragDropSource((OGImGuiDragDropFlags)flags);
	}

	/*static*/ bool ImGui::BeginDragDropSource()
	{
		return ::ImGui::BeginDragDropSource();
	}

	/*static*/ bool ImGui::SetDragDropPayload(ImString^ type, IntPtr data, size_t sz, ImGuiCond cond)
	{
		IMSTR_DECODE_TEMP(type);
		return ::ImGui::SetDragDropPayload(type_cstr, data.ToPointer(), sz, (OGImGuiCond)cond);
	}

	/*static*/ bool ImGui::SetDragDropPayload(ImString^ type, IntPtr data, size_t sz)
	{
		IMSTR_DECODE_TEMP(type);
		return ::ImGui::SetDragDropPayload(type_cstr, data.ToPointer(), sz);
	}

	/*static*/ void ImGui::EndDragDropSource()
	{
		::ImGui::EndDragDropSource();
	}

	/*static*/ bool ImGui::BeginDragDropTarget()
	{
		return ::ImGui::BeginDragDropTarget();
	}

	/*static*/ ImGuiPayload ImGui::AcceptDragDropPayload(ImString^ type, ImGuiDragDropFlags flags)
	{
		IMSTR_DECODE_TEMP(type);
		return ImGuiPayload(::ImGui::AcceptDragDropPayload(type_cstr, (OGImGuiDragDropFlags)flags));
	}

	/*static*/ ImGuiPayload ImGui::AcceptDragDropPayload(ImString^ type)
	{
		IMSTR_DECODE_TEMP(type);
		return ImGuiPayload(::ImGui::AcceptDragDropPayload(type_cstr));
	}

	/*static*/ void ImGui::EndDragDropTarget()
	{
		::ImGui::EndDragDropTarget();
	}

	/*static*/ ImGuiPayload ImGui::GetDragDropPayload()
	{
		return ImGuiPayload(::ImGui::GetDragDropPayload());
	}

	/*static*/ void ImGui::PushClipRect(ImVec2 clip_rect_min, ImVec2 clip_rect_max, bool intersect_with_current_clip_rect)
	{
		::ImGui::PushClipRect(clip_rect_min, clip_rect_max, intersect_with_current_clip_rect);
	}

	/*static*/ void ImGui::PopClipRect()
	{
		::ImGui::PopClipRect();
	}

	/*static*/ void ImGui::SetItemDefaultFocus()
	{
		::ImGui::SetItemDefaultFocus();
	}

	/*static*/ void ImGui::SetKeyboardFocusHere(int offset)
	{
		::ImGui::SetKeyboardFocusHere(offset);
	}

	/*static*/ void ImGui::SetKeyboardFocusHere()
	{
		::ImGui::SetKeyboardFocusHere();
	}

	/*static*/ bool ImGui::IsItemHovered(ImGuiHoveredFlags flags)
	{
		return ::ImGui::IsItemHovered((OGImGuiHoveredFlags)flags);
	}

	/*static*/ bool ImGui::IsItemHovered()
	{
		return ::ImGui::IsItemHovered();
	}

	/*static*/ bool ImGui::IsItemActive()
	{
		return ::ImGui::IsItemActive();
	}

	/*static*/ bool ImGui::IsItemFocused()
	{
		return ::ImGui::IsItemFocused();
	}

	/*static*/ bool ImGui::IsItemClicked(ImGuiMouseButton mouse_button)
	{
		return ::ImGui::IsItemClicked((OGImGuiMouseButton)mouse_button);
	}

	/*static*/ bool ImGui::IsItemClicked()
	{
		return ::ImGui::IsItemClicked();
	}

	/*static*/ bool ImGui::IsItemVisible()
	{
		return ::ImGui::IsItemVisible();
	}

	/*static*/ bool ImGui::IsItemEdited()
	{
		return ::ImGui::IsItemEdited();
	}

	/*static*/ bool ImGui::IsItemActivated()
	{
		return ::ImGui::IsItemActivated();
	}

	/*static*/ bool ImGui::IsItemDeactivated()
	{
		return ::ImGui::IsItemDeactivated();
	}

	/*static*/ bool ImGui::IsItemDeactivatedAfterEdit()
	{
		return ::ImGui::IsItemDeactivatedAfterEdit();
	}

	/*static*/ bool ImGui::IsItemToggledOpen()
	{
		return ::ImGui::IsItemToggledOpen();
	}

	/*static*/ bool ImGui::IsAnyItemHovered()
	{
		return ::ImGui::IsAnyItemHovered();
	}

	/*static*/ bool ImGui::IsAnyItemActive()
	{
		return ::ImGui::IsAnyItemActive();
	}

	/*static*/ bool ImGui::IsAnyItemFocused()
	{
		return ::ImGui::IsAnyItemFocused();
	}

	/*static*/ ImVec2 ImGui::GetItemRectMin()
	{
		return ::ImGui::GetItemRectMin();
	}

	/*static*/ ImVec2 ImGui::GetItemRectMax()
	{
		return ::ImGui::GetItemRectMax();
	}

	/*static*/ ImVec2 ImGui::GetItemRectSize()
	{
		return ::ImGui::GetItemRectSize();
	}

	/*static*/ void ImGui::SetItemAllowOverlap()
	{
		::ImGui::SetItemAllowOverlap();
	}

	/*static*/ bool ImGui::IsRectVisible(ImVec2 size)
	{
		return ::ImGui::IsRectVisible(size);
	}

	/*static*/ bool ImGui::IsRectVisible(ImVec2 rect_min, ImVec2 rect_max)
	{
		return ::ImGui::IsRectVisible(rect_min, rect_max);
	}

	/*static*/ double ImGui::GetTime()
	{
		return ::ImGui::GetTime();
	}

	/*static*/ int ImGui::GetFrameCount()
	{
		return ::ImGui::GetFrameCount();
	}

	/*static*/ ImDrawList ImGui::GetBackgroundDrawList()
	{
		return ImDrawList(::ImGui::GetBackgroundDrawList());
	}

	/*static*/ ImDrawList ImGui::GetForegroundDrawList()
	{
		return ImDrawList(::ImGui::GetForegroundDrawList());
	}

	/*static*/ ImImmutableString ImGui::GetStyleColorName(ImGuiCol idx)
	{
		return ImImmutableString(::ImGui::GetStyleColorName((OGImGuiCol)idx));
	}
	
	///*static*/ void SetStateStorage(ImGuiStorage storage);                        
	
	/*static*/ ImGuiStorage ImGui::GetStateStorage()
	{
		return ImGuiStorage(::ImGui::GetStateStorage());
	}
	
	/*static*/ ImVec2 ImGui::CalcTextSize(ImString^ text, bool hide_text_after_double_hash, float wrap_width)
	{
		IMSTR_DECODE_TEMP(text);
		return ::ImGui::CalcTextSize(text_cstr, NULL, hide_text_after_double_hash, wrap_width);
	}
	
	/*static*/ ImVec2 ImGui::CalcTextSize(ImString^ text, bool hide_text_after_double_hash)
	{
		IMSTR_DECODE_TEMP(text);
		return ::ImGui::CalcTextSize(text_cstr, NULL, hide_text_after_double_hash);
	}
	
	/*static*/ ImVec2 ImGui::CalcTextSize(ImString^ text)
	{
		IMSTR_DECODE_TEMP(text);
		return ::ImGui::CalcTextSize(text_cstr);
	}
	
	/*static*/ void ImGui::CalcListClipping(int items_count, float items_height, [Out] int% out_items_display_start, [Out] int% out_items_display_end)
	{
		int out_out_items_display_start, out_out_items_display_end;
		::ImGui::CalcListClipping(items_count, items_height, &out_out_items_display_start, &out_out_items_display_end);
		out_items_display_start = out_out_items_display_start;
		out_items_display_end = out_out_items_display_end;
	}
	
	/*static*/ bool ImGui::BeginChildFrame(ImGuiID id, ImVec2 size, ImGuiWindowFlags flags)
	{
		return ::ImGui::BeginChildFrame(id, size, (OGImGuiWindowFlags)flags);
	}
	
	/*static*/ bool ImGui::BeginChildFrame(ImGuiID id, ImVec2 size)
	{
		return ::ImGui::BeginChildFrame(id, size);
	}
	
	/*static*/ void ImGui::EndChildFrame()
	{
		::ImGui::EndChildFrame();
	}

	/*static*/ ImVec4 ImGui::ColorConvertU32ToFloat4(ImU32 in)
	{
		return ::ImGui::ColorConvertU32ToFloat4(in);
	}

	/*static*/ ImU32 ImGui::ColorConvertFloat4ToU32(ImVec4 in)
	{
		return ::ImGui::ColorConvertFloat4ToU32(in);
	}

	/*static*/ void ImGui::ColorConvertRGBtoHSV(float r, float g, float b, [Out] float% out_h, [Out] float% out_s, [Out] float% out_v)
	{
		float out_out_h, out_out_s, out_out_v;
		::ImGui::ColorConvertRGBtoHSV(r, g, b, out_out_h, out_out_s, out_out_v);
		out_h = out_out_h;
		out_s = out_out_s;
		out_v = out_out_v;
	}

	/*static*/ void ImGui::ColorConvertHSVtoRGB(float h, float s, float v, [Out] float% out_r, [Out] float% out_g, [Out] float% out_b)
	{
		float out_out_r, out_out_g, out_out_b;
		::ImGui::ColorConvertRGBtoHSV(h, s, v, out_out_r, out_out_g, out_out_b);
		out_r = out_out_r;
		out_g = out_out_g;
		out_b = out_out_b;
	}

	/*static*/ int ImGui::GetKeyIndex(ImGuiKey imgui_key)
	{
		return ::ImGui::GetKeyIndex((OGImGuiKey)imgui_key);
	}

	/*static*/ bool ImGui::IsKeyDown(int user_key_index)
	{
		return ::ImGui::IsKeyDown(user_key_index);
	}

	/*static*/ bool ImGui::IsKeyPressed(int user_key_index, bool repeat)
	{
		return ::ImGui::IsKeyPressed(user_key_index, repeat);
	}

	/*static*/ bool ImGui::IsKeyPressed(int user_key_index)
	{
		return ::ImGui::IsKeyPressed(user_key_index);
	}

	/*static*/ bool ImGui::IsKeyReleased(int user_key_index)
	{
		return ::ImGui::IsKeyReleased(user_key_index);
	}

	/*static*/ int ImGui::GetKeyPressedAmount(int key_index, float repeat_delay, float rate)
	{
		return ::ImGui::GetKeyPressedAmount(key_index, repeat_delay, rate);
	}

	/*static*/ void ImGui::CaptureKeyboardFromApp(bool want_capture_keyboard_value)
	{
		::ImGui::CaptureKeyboardFromApp(want_capture_keyboard_value);
	}

	/*static*/ void ImGui::CaptureKeyboardFromApp()
	{
		::ImGui::CaptureKeyboardFromApp();
	}

	/*static*/ bool ImGui::IsMouseDown(ImGuiMouseButton button)
	{
		return ::ImGui::IsMouseDown((OGImGuiMouseButton)button);
	}

	/*static*/ bool ImGui::IsMouseClicked(ImGuiMouseButton button, bool repeat)
	{
		return ::ImGui::IsMouseClicked((OGImGuiMouseButton)button, repeat);
	}

	/*static*/ bool ImGui::IsMouseClicked(ImGuiMouseButton button)
	{
		return ::ImGui::IsMouseClicked((OGImGuiMouseButton)button);
	}

	/*static*/ bool ImGui::IsMouseReleased(ImGuiMouseButton button)
	{
		return ::ImGui::IsMouseReleased((OGImGuiMouseButton)button);
	}

	/*static*/ bool ImGui::IsMouseDoubleClicked(ImGuiMouseButton button)
	{
		return ::ImGui::IsMouseDoubleClicked((OGImGuiMouseButton)button);
	}

	/*static*/ bool ImGui::IsMouseHoveringRect(ImVec2 r_min, ImVec2 r_max, bool clip)
	{
		return ::ImGui::IsMouseHoveringRect(r_min, r_max, clip);
	}

	/*static*/ bool ImGui::IsMouseHoveringRect(ImVec2 r_min, ImVec2 r_max)
	{
		return ::ImGui::IsMouseHoveringRect(r_min, r_max);
	}

	/*static*/ bool ImGui::IsMousePosValid(ImVec2 mouse_pos)
	{
		return ::ImGui::IsMousePosValid((OGImVec2*)&mouse_pos);
	}

	/*static*/ bool ImGui::IsMousePosValid()
	{
		return ::ImGui::IsMousePosValid();
	}

	/*static*/ bool ImGui::IsAnyMouseDown()
	{
		return ::ImGui::IsAnyMouseDown();
	}

	/*static*/ ImVec2 ImGui::GetMousePos()
	{
		return ::ImGui::GetMousePos();
	}

	/*static*/ ImVec2 ImGui::GetMousePosOnOpeningCurrentPopup()
	{
		return ::ImGui::GetMousePosOnOpeningCurrentPopup();
	}

	/*static*/ bool ImGui::IsMouseDragging(ImGuiMouseButton button, float lock_threshold)
	{
		return ::ImGui::IsMouseDragging((OGImGuiMouseButton)button, lock_threshold);
	}

	/*static*/ bool ImGui::IsMouseDragging(ImGuiMouseButton button)
	{
		return ::ImGui::IsMouseDragging((OGImGuiMouseButton)button);
	}

	/*static*/ ImVec2 ImGui::GetMouseDragDelta(ImGuiMouseButton button, float lock_threshold)
	{
		return ::ImGui::GetMouseDragDelta((OGImGuiMouseButton)button, lock_threshold);
	}

	/*static*/ ImVec2 ImGui::GetMouseDragDelta(ImGuiMouseButton button)
	{
		return ::ImGui::GetMouseDragDelta((OGImGuiMouseButton)button);
	}

	/*static*/ ImVec2 ImGui::GetMouseDragDelta()
	{
		return ::ImGui::GetMouseDragDelta();
	}

	/*static*/ void ImGui::ResetMouseDragDelta(ImGuiMouseButton button)
	{
		return ::ImGui::ResetMouseDragDelta((OGImGuiMouseButton)button);
	}

	/*static*/ void ImGui::ResetMouseDragDelta()
	{
		return ::ImGui::ResetMouseDragDelta();
	}

	/*static*/ ImGuiMouseCursor ImGui::GetMouseCursor()
	{
		return (ImGuiMouseCursor)::ImGui::GetMouseCursor();
	}

	/*static*/ void ImGui::SetMouseCursor(ImGuiMouseCursor cursor_type)
	{
		::ImGui::SetMouseCursor((OGImGuiMouseCursor)cursor_type);
	}

	/*static*/ void ImGui::CaptureMouseFromApp(bool want_capture_mouse_value)
	{
		::ImGui::SetMouseCursor(want_capture_mouse_value);
	}

	/*static*/ void ImGui::CaptureMouseFromApp()
	{
		::ImGui::CaptureMouseFromApp();
	}

	/*static*/ ImImmutableString ImGui::GetClipboardText()
	{
		return ImImmutableString(::ImGui::GetClipboardText());
	}

	/*static*/ void ImGui::SetClipboardText(ImString^ text)
	{
		IMSTR_DECODE_TEMP(text);
		::ImGui::SetClipboardText(text_cstr);
	}

	/*static*/ void ImGui::LoadIniSettingsFromDisk(ImString^ ini_filename)
	{
		IMSTR_DECODE_TEMP(ini_filename);
		::ImGui::LoadIniSettingsFromDisk(ini_filename_cstr);
	}

	/*static*/ void ImGui::LoadIniSettingsFromMemory(ImString^ ini_data)
	{
		IMSTR_DECODE_TEMP(ini_data);
		::ImGui::LoadIniSettingsFromMemory(ini_data_cstr);
	}

	/*static*/ void ImGui::SaveIniSettingsToDisk(ImString^ ini_filename)
	{
		IMSTR_DECODE_TEMP(ini_filename);
		::ImGui::SaveIniSettingsToDisk(ini_filename_cstr);
	}

	/*static*/ ImImmutableString ImGui::SaveIniSettingsToMemory()
	{
		return ImImmutableString(::ImGui::SaveIniSettingsToMemory());
	}
}