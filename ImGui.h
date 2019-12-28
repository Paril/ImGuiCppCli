#pragma once

#include "common.h"
#include "ImGuiWindowFlags.h"
#include "ImGuiFocusedFlags.h"
#include "ImGuiCond.h"
#include "ImGuiCol.h"
#include "ImGuiStyleVar.h"
#include "ImVec2.h"
#include "ImVec4.h"
#include "ImGuiHoveredFlags.h"
#include "ImGuiMouseButton.h"
#include "ImGuiMouseCursor.h"
#include "ImGuiKey.h"
#include "ImGuiDir.h"
#include "ImGuiSizeCallbackData.h"
#include "ImGuiComboFlags.h"
#include "ImGuiDataType.h"
#include "ImGuiDragDropFlags.h"
#include "ImGuiTabBarFlags.h"
#include "ImGuiTabItemFlags.h"
#include "ImGuiSelectableFlags.h"
#include "ImGuiTreeNodeFlags.h"
#include "ImGuiColorEditFlags.h"
#include "ImGuiInputTextFlags.h"
#include "ImGuiInputTextCallbackData.h"

using namespace System;

namespace ImGuiCppCli
{
	value struct ImGuiContext;
	ref struct ImFontAtlas;
	ref class ImGuiIO;
	value struct ImDrawData;
	ref struct ImFont;
	ref struct ImGuiStyle;
	value struct ImDrawList;
	value struct ImGuiStorage;
	value struct ImGuiPayload;

	public delegate float PlotGetter(int index);
	public delegate bool ListBoxGetter(int index, [Out] ImString^% out_text);
	public delegate int InputTextDelegate(ImGuiInputTextCallbackData data);

	public ref class ImGui abstract sealed
	{
	public:
		static ImGuiContext CreateContext(ImFontAtlas^ shared_font_atlas);
		static ImGuiContext CreateContext();
		static void DestroyContext(ImGuiContext% ctx);
		static void DestroyContext();
		static void SetCurrentContext(ImGuiContext% ctx);

		static ImGuiIO^ GetIO();
		static ImGuiStyle^ GetStyle();
		static void GetStyle(ImGuiStyle^ style);
		static void NewFrame();
		static void EndFrame();
		static void Render();
		static ImDrawData GetDrawData();

		static void ShowDemoWindow(bool% open);
		static void ShowAboutWindow(bool% open);
		static void ShowMetricsWindow(bool% open);
		static void ShowStyleEditor(ImGuiStyle^ ref);
		static void ShowStyleEditor();
		static bool ShowStyleSelector(ImString^ label);
		static void ShowFontSelector(ImString^ label);
		static void ShowUserGuide();
		static ImString^ GetVersion();

		static void StyleColorsDark(ImGuiStyle^ style);
		static void StyleColorsDark();
		static void StyleColorsClassic(ImGuiStyle^ style);
		static void StyleColorsClassic();
		static void StyleColorsLight(ImGuiStyle^ style);
		static void StyleColorsLight();

		static bool Begin(ImString^ name, bool% open, ImGuiWindowFlags flags);
		static bool Begin(ImString^ name, bool% open);
		static bool Begin(ImString^ name);
		static void End();

		static bool BeginChild(ImString^ id, ImVec2 size, bool border, ImGuiWindowFlags flags);
		static bool BeginChild(ImString^ id, ImVec2 size, bool border);
		static bool BeginChild(ImString^ id, ImVec2 size);
		static bool BeginChild(ImString^ id);
		static bool BeginChild(ImGuiID id, ImVec2 size, bool border, ImGuiWindowFlags flags);
		static bool BeginChild(ImGuiID id, ImVec2 size, bool border);
		static bool BeginChild(ImGuiID id, ImVec2 size);
		static bool BeginChild(ImGuiID id);
		static void EndChild();

		static bool IsWindowAppearing();
		static bool IsWindowCollapsed();
		static bool IsWindowFocused(ImGuiFocusedFlags flags);
		static bool IsWindowFocused();
		static bool IsWindowHovered(ImGuiFocusedFlags flags);
		static bool IsWindowHovered();
		static ImDrawList GetWindowDrawList();
		static ImVec2 GetWindowPos();
		static ImVec2 GetWindowSize();
		static float GetWindowWidth();
		static float GetWindowHeight();

		static void SetNextWindowPos(ImVec2 pos, ImGuiCond cond, ImVec2 pivot);
		static void SetNextWindowPos(ImVec2 pos, ImGuiCond cond);
		static void SetNextWindowPos(ImVec2 pos);
		static void SetNextWindowSize(ImVec2 size, ImGuiCond cond);
		static void SetNextWindowSize(ImVec2 size);
		static void SetNextWindowSizeConstraints(ImVec2 min, ImVec2 max, ImGuiSizeDelegate^ callback);
		static void SetNextWindowSizeConstraints(ImVec2 min, ImVec2 max);
		static void SetNextWindowContentSize(ImVec2 size);
		static void SetNextWindowCollapsed(bool collapsed, ImGuiCond cond);
		static void SetNextWindowCollapsed(bool collapsed);
		static void SetNextWindowFocus();
		static void SetNextWindowBgAlpha(float alpha);
		static void SetWindowPos(ImVec2 pos, ImGuiCond cond);
		static void SetWindowPos(ImVec2 pos);
		static void SetWindowSize(ImVec2 size, ImGuiCond cond);
		static void SetWindowSize(ImVec2 size);
		static void SetWindowCollapsed(bool collapsed, ImGuiCond cond);
		static void SetWindowCollapsed(bool collapsed);
		static void SetWindowFocus();
		static void SetWindowFontScale(float scale);
		static void SetWindowPos(ImString^ name, ImVec2 pos, ImGuiCond cond);
		static void SetWindowPos(ImString^ name, ImVec2 pos);
		static void SetWindowSize(ImString^ name, ImVec2 size, ImGuiCond cond);
		static void SetWindowSize(ImString^ name, ImVec2 size);
		static void SetWindowCollapsed(ImString^ name, bool collapsed, ImGuiCond cond);
		static void SetWindowCollapsed(ImString^ name, bool collapsed);
		static void SetWindowFocus(ImString^ name);

		static ImVec2 GetContentRegionMax();
		static ImVec2 GetContentRegionAvail();
		static ImVec2 GetWindowContentRegionMin();
		static ImVec2 GetWindowContentRegionMax();
		static float GetWindowContentRegionWidth();

		static float GetScrollX();
		static float GetScrollY();
		static float GetScrollMaxX();
		static float GetScrollMaxY();
		static void SetScrollX(float scroll_x);
		static void SetScrollY(float scroll_y);
		static void SetScrollHereX(float center_x_ratio);
		static void SetScrollHereX();
		static void SetScrollHereY(float center_y_ratio);
		static void SetScrollHereY();
		static void SetScrollFromPosX(float local_x, float center_x_ratio);
		static void SetScrollFromPosX(float local_x);
		static void SetScrollFromPosY(float local_y, float center_y_ratio);
		static void SetScrollFromPosY(float local_y);

		static void PushFont(ImFont^ font);
		static void PopFont();
		static void PushStyleColor(ImGuiCol idx, ImU32 col);
		static void PushStyleColor(ImGuiCol idx, ImVec4 col);
		static void PopStyleColor(int count);
		static void PopStyleColor();
		static void PushStyleVar(ImGuiStyleVar idx, float val);
		static void PushStyleVar(ImGuiStyleVar idx, ImVec2 val);
		static void PopStyleVar(int count);
		static void PopStyleVar();
		static ImVec4 GetStyleColorVec4(ImGuiCol idx);
		static ImFont^ GetFont();
		static float GetFontSize();
		static ImVec2 GetFontTexUvWhitePixel();
		static ImU32 GetColorU32(ImGuiCol idx, float alpha_mul);
		static ImU32 GetColorU32(ImGuiCol idx);
		static ImU32 GetColorU32(ImVec4 col);
		static ImU32 GetColorU32(ImU32 col);

		static void PushItemWidth(float item_width);
		static void PopItemWidth();
		static void SetNextItemWidth(float item_width);
		static float CalcItemWidth();
		static void PushTextWrapPos(float wrap_local_pos_x);
		static void PushTextWrapPos();
		static void PopTextWrapPos();
		static void PushAllowKeyboardFocus(bool allow_keyboard_focus);
		static void PopAllowKeyboardFocus();
		static void PushButtonRepeat(bool repeat);
		static void PopButtonRepeat();

		static void Separator();
		static void SameLine(float offset_from_start_x, float spacing);
		static void SameLine(float offset_from_start_x);
		static void SameLine();
		static void NewLine();
		static void Spacing();
		static void Dummy(ImVec2 size);
		static void Indent(float indent_w);
		static void Indent();
		static void Unindent(float indent_w);
		static void Unindent();
		static void BeginGroup();
		static void EndGroup();
		static ImVec2 GetCursorPos();
		static float GetCursorPosX();
		static float GetCursorPosY();
		static void SetCursorPos(ImVec2 local_pos);
		static void SetCursorPosX(float local_x);
		static void SetCursorPosY(float local_y);
		static ImVec2 GetCursorStartPos();
		static ImVec2 GetCursorScreenPos();
		static void SetCursorScreenPos(ImVec2 pos);
		static void AlignTextToFramePadding();
		static float GetTextLineHeight();
		static float GetTextLineHeightWithSpacing();
		static float GetFrameHeight();
		static float GetFrameHeightWithSpacing();

		static void PushID(ImString^ str_id);
		static void PushID(int int_id);
		static void PopID();
		static ImGuiID GetID(ImString^ str_id);

		static void Text(ImString^ text);
		static void TextColored(ImVec4 col, ImString^ text);
		static void TextDisabled(ImString^ text);
		static void TextWrapped(ImString^ text);
		static void LabelText(ImString^ label, ImString^ text);
		static void BulletText(ImString^ text);

		static bool Button(ImString^ label, ImVec2 size);
		static bool Button(ImString^ label);
		static bool SmallButton(ImString^ label);
		static bool InvisibleButton(ImString^ str_id, ImVec2 size);
		static bool ArrowButton(ImString^ str_id, ImGuiDir dir);
		static void Image(ImTextureID user_texture_id, ImVec2 size, ImVec2 uv0, ImVec2 uv1, ImVec4 tint_col, ImVec4 border_col);
		static void Image(ImTextureID user_texture_id, ImVec2 size, ImVec2 uv0, ImVec2 uv1, ImVec4 tint_col);
		static void Image(ImTextureID user_texture_id, ImVec2 size, ImVec2 uv0, ImVec2 uv1);
		static void Image(ImTextureID user_texture_id, ImVec2 size, ImVec2 uv0);
		static void Image(ImTextureID user_texture_id, ImVec2 size);
		static bool ImageButton(ImTextureID user_texture_id, ImVec2 size, ImVec2 uv0, ImVec2 uv1, int frame_padding, ImVec4 bg_col, ImVec4 tint_col);
		static bool ImageButton(ImTextureID user_texture_id, ImVec2 size, ImVec2 uv0, ImVec2 uv1, int frame_padding, ImVec4 bg_col);
		static bool ImageButton(ImTextureID user_texture_id, ImVec2 size, ImVec2 uv0, ImVec2 uv1, int frame_padding);
		static bool ImageButton(ImTextureID user_texture_id, ImVec2 size, ImVec2 uv0, ImVec2 uv1);
		static bool ImageButton(ImTextureID user_texture_id, ImVec2 size, ImVec2 uv0);
		static bool ImageButton(ImTextureID user_texture_id, ImVec2 size);
		static bool Checkbox(ImString^ label, bool% v);
		static bool CheckboxFlags(ImString^ label, unsigned int% flags, unsigned int flags_value);
		static bool RadioButton(ImString^ label, bool active);
		static bool RadioButton(ImString^ label, int% v, int v_button);
		static void ProgressBar(float fraction, ImVec2 size_arg, ImString^ overlay);
		static void ProgressBar(float fraction, ImVec2 size_arg);
		static void ProgressBar(float fraction);
		static void Bullet();

		static bool Combo(ImString^ label, int% current_item, ListBoxGetter^ items_getter, int items_count, int popup_max_height_in_items);
		static bool Combo(ImString^ label, int% current_item, ListBoxGetter^ items_getter, int items_count);
		static bool BeginCombo(ImString^ label, ImString^ preview_value, ImGuiComboFlags flags);
		static bool BeginCombo(ImString^ label, ImString^ preview_value);
		static void EndCombo();

		static bool DragFloatRange2(ImString^ label, float% v_current_min, float% v_current_max, float v_speed, float v_min, float v_max, ImString^ format, ImString^ format_max, float power);
		static bool DragFloatRange2(ImString^ label, float% v_current_min, float% v_current_max, float v_speed, float v_min, float v_max, ImString^ format, ImString^ format_max);
		static bool DragFloatRange2(ImString^ label, float% v_current_min, float% v_current_max, float v_speed, float v_min, float v_max, ImString^ format);
		static bool DragFloatRange2(ImString^ label, float% v_current_min, float% v_current_max, float v_speed, float v_min, float v_max);
		static bool DragFloatRange2(ImString^ label, float% v_current_min, float% v_current_max, float v_speed, float v_min);
		static bool DragFloatRange2(ImString^ label, float% v_current_min, float% v_current_max, float v_speed);
		static bool DragFloatRange2(ImString^ label, float% v_current_min, float% v_current_max);
		static bool DragIntRange2(ImString^ label, int% v_current_min, int% v_current_max, float v_speed, int v_min, int v_max, ImString^ format, ImString^ format_max);
		static bool DragIntRange2(ImString^ label, int% v_current_min, int% v_current_max, float v_speed, int v_min, int v_max, ImString^ format);
		static bool DragIntRange2(ImString^ label, int% v_current_min, int% v_current_max, float v_speed, int v_min, int v_max);
		static bool DragIntRange2(ImString^ label, int% v_current_min, int% v_current_max, float v_speed, int v_min);
		static bool DragIntRange2(ImString^ label, int% v_current_min, int% v_current_max, float v_speed);
		static bool DragIntRange2(ImString^ label, int% v_current_min, int% v_current_max);
		generic<typename T> static bool DragScalar(ImString^ label, ImGuiDataType data_type, T% p_data, float v_speed, T p_min, T p_max, ImString^ format, float power);
		generic<typename T> static bool DragScalar(ImString^ label, ImGuiDataType data_type, T% p_data, float v_speed, T p_min, T p_max, ImString^ format);
		generic<typename T> static bool DragScalar(ImString^ label, ImGuiDataType data_type, T% p_data, float v_speed, T p_min, T p_max);
		generic<typename T> static bool DragScalar(ImString^ label, ImGuiDataType data_type, T% p_data, float v_speed, T p_min);
		generic<typename T> static bool DragScalar(ImString^ label, ImGuiDataType data_type, T% p_data, float v_speed);
		generic<typename T> static bool DragScalarN(ImString^ label, ImGuiDataType data_type, Span<T> p_data, float v_speed, T p_min, T p_max, ImString^ format, float power);
		generic<typename T> static bool DragScalarN(ImString^ label, ImGuiDataType data_type, Span<T> p_data, float v_speed, T p_min, T p_max, ImString^ format);
		generic<typename T> static bool DragScalarN(ImString^ label, ImGuiDataType data_type, Span<T> p_data, float v_speed, T p_min, T p_max);
		generic<typename T> static bool DragScalarN(ImString^ label, ImGuiDataType data_type, Span<T> p_data, float v_speed, T p_min);
		generic<typename T> static bool DragScalarN(ImString^ label, ImGuiDataType data_type, Span<T> p_data, float v_speed);
		static bool DragFloat(ImString^ label, float% p_data, float v_speed, float p_min, float p_max, ImString^ format, float power) { return DragScalar(label, ImGuiDataType::Float, p_data, v_speed, p_min, p_max, format, power); }
		static bool DragFloat(ImString^ label, float% p_data, float v_speed, float p_min, float p_max, ImString^ format) { return DragScalar(label, ImGuiDataType::Float, p_data, v_speed, p_min, p_max, format); }
		static bool DragFloat(ImString^ label, float% p_data, float v_speed, float p_min, float p_max) { return DragScalar(label, ImGuiDataType::Float, p_data, v_speed, p_min, p_max); }
		static bool DragFloat(ImString^ label, float% p_data, float v_speed, float p_min) { return DragScalar(label, ImGuiDataType::Float, p_data, v_speed, p_min); }
		static bool DragFloat(ImString^ label, float% p_data, float v_speed) { return DragScalar(label, ImGuiDataType::Float, p_data, v_speed); }
		static bool DragFloat(ImString^ label, float% p_data) { return DragScalar(label, ImGuiDataType::Float, p_data, 1.0f); }
		static bool DragInt(ImString^ label, int% p_data, float v_speed, int p_min, int p_max, ImString^ format, float power) { return DragScalar(label, ImGuiDataType::S32, p_data, v_speed, p_min, p_max, format, power); }
		static bool DragInt(ImString^ label, int% p_data, float v_speed, int p_min, int p_max, ImString^ format) { return DragScalar(label, ImGuiDataType::S32, p_data, v_speed, p_min, p_max, format); }
		static bool DragInt(ImString^ label, int% p_data, float v_speed, int p_min, int p_max) { return DragScalar(label, ImGuiDataType::S32, p_data, v_speed, p_min, p_max); }
		static bool DragInt(ImString^ label, int% p_data, float v_speed, int p_min) { return DragScalar(label, ImGuiDataType::S32, p_data, v_speed, p_min); }
		static bool DragInt(ImString^ label, int% p_data, float v_speed) { return DragScalar(label, ImGuiDataType::S32, p_data, v_speed); }
		static bool DragInt(ImString^ label, int% p_data) { return DragScalar(label, ImGuiDataType::S32, p_data, 1.0f); }
		static bool DragFloatN(ImString^ label, Span<float> p_data, float v_speed, float p_min, float p_max, ImString^ format, float power) { return DragScalarN(label, ImGuiDataType::Float, p_data, v_speed, p_min, p_max, format, power); }
		static bool DragFloatN(ImString^ label, Span<float> p_data, float v_speed, float p_min, float p_max, ImString^ format) { return DragScalarN(label, ImGuiDataType::Float, p_data, v_speed, p_min, p_max, format); }
		static bool DragFloatN(ImString^ label, Span<float> p_data, float v_speed, float p_min, float p_max) { return DragScalarN(label, ImGuiDataType::Float, p_data, v_speed, p_min, p_max); }
		static bool DragFloatN(ImString^ label, Span<float> p_data, float v_speed, float p_min) { return DragScalarN(label, ImGuiDataType::Float, p_data, v_speed, p_min); }
		static bool DragFloatN(ImString^ label, Span<float> p_data, float v_speed) { return DragScalarN(label, ImGuiDataType::Float, p_data, v_speed); }
		static bool DragFloatN(ImString^ label, Span<float> p_data) { return DragScalarN(label, ImGuiDataType::Float, p_data, 1.0f); }
		static bool DragIntN(ImString^ label, Span<int> p_data, float v_speed, int p_min, int p_max, ImString^ format, float power) { return DragScalarN(label, ImGuiDataType::S32, p_data, v_speed, p_min, p_max, format, power); }
		static bool DragIntN(ImString^ label, Span<int> p_data, float v_speed, int p_min, int p_max, ImString^ format) { return DragScalarN(label, ImGuiDataType::S32, p_data, v_speed, p_min, p_max, format); }
		static bool DragIntN(ImString^ label, Span<int> p_data, float v_speed, int p_min, int p_max) { return DragScalarN(label, ImGuiDataType::S32, p_data, v_speed, p_min, p_max); }
		static bool DragIntN(ImString^ label, Span<int> p_data, float v_speed, int p_min) { return DragScalarN(label, ImGuiDataType::S32, p_data, v_speed, p_min); }
		static bool DragIntN(ImString^ label, Span<int> p_data, float v_speed) { return DragScalarN(label, ImGuiDataType::S32, p_data, v_speed); }
		static bool DragIntN(ImString^ label, Span<int> p_data) { return DragScalarN(label, ImGuiDataType::S32, p_data, 1.0f); }

		static bool SliderFloat(ImString^ label, float% p_data, float p_min, float p_max, ImString^ format, float power) { return SliderScalar<float>(label, ImGuiDataType::Float, p_data, p_min, p_max, format, power); }
		static bool SliderFloat(ImString^ label, float% p_data, float p_min, float p_max, ImString^ format) { return SliderScalar<float>(label, ImGuiDataType::Float, p_data, p_min, p_max, format); }
		static bool SliderFloat(ImString^ label, float% p_data, float p_min, float p_max) { return SliderScalar<float>(label, ImGuiDataType::Float, p_data, p_min, p_max); }
		static bool SliderFloatN(ImString^ label, Span<float> p_data, float p_min, float p_max, ImString^ format, float power) { return SliderScalarN<float>(label, ImGuiDataType::Float, p_data, p_min, p_max, format, power); }
		static bool SliderFloatN(ImString^ label, Span<float> p_data, float p_min, float p_max, ImString^ format) { return SliderScalarN<float>(label, ImGuiDataType::Float, p_data, p_min, p_max, format); }
		static bool SliderFloatN(ImString^ label, Span<float> p_data, float p_min, float p_max) { return SliderScalarN<float>(label, ImGuiDataType::Float, p_data, p_min, p_max); }
		static bool SliderAngle(ImString^ label, float% v_rad, float v_degrees_min, float v_degrees_max, ImString^ format);
		static bool SliderAngle(ImString^ label, float% v_rad, float v_degrees_min, float v_degrees_max);
		static bool SliderAngle(ImString^ label, float% v_rad, float v_degrees_min);
		static bool SliderAngle(ImString^ label, float% v_rad);
		static bool SliderInt(ImString^ label, int% p_data, int p_min, int p_max, ImString^ format) { return SliderScalar<int>(label, ImGuiDataType::S32, p_data, p_min, p_max, format); }
		static bool SliderInt(ImString^ label, int% p_data, int p_min, int p_max) { return  SliderScalar<int>(label, ImGuiDataType::S32, p_data, p_min, p_max); }
		static bool SliderIntN(ImString^ label, Span<int> p_data, int p_min, int p_max, ImString^ format) { return SliderScalarN<int>(label, ImGuiDataType::S32, p_data, p_min, p_max, format); }
		static bool SliderIntN(ImString^ label, Span<int> p_data, int p_min, int p_max) { return SliderScalarN<int>(label, ImGuiDataType::S32, p_data, p_min, p_max); }
		generic<typename T> static bool SliderScalar(ImString^ label, ImGuiDataType data_type, T% p_data, T p_min, T p_max, ImString^ format, float power);
		generic<typename T> static bool SliderScalar(ImString^ label, ImGuiDataType data_type, T% p_data, T p_min, T p_max, ImString^ format);
		generic<typename T> static bool SliderScalar(ImString^ label, ImGuiDataType data_type, T% p_data, T p_min, T p_max);
		generic<typename T> static bool SliderScalarN(ImString^ label, ImGuiDataType data_type, Span<T> p_data, T p_min, T p_max, ImString^ format, float power);
		generic<typename T> static bool SliderScalarN(ImString^ label, ImGuiDataType data_type, Span<T> p_data, T p_min, T p_max, ImString^ format);
		generic<typename T> static bool SliderScalarN(ImString^ label, ImGuiDataType data_type, Span<T> p_data, T p_min, T p_max);
		static bool VSliderFloat(ImString^ label, ImVec2 size, float% p_data, float p_min, float p_max, ImString^ format, float power) { return VSliderScalar<float>(label, size, ImGuiDataType::Float, p_data, p_min, p_max, format, power); }
		static bool VSliderFloat(ImString^ label, ImVec2 size, float% p_data, float p_min, float p_max, ImString^ format) { return VSliderScalar<float>(label, size, ImGuiDataType::Float, p_data, p_min, p_max, format); }
		static bool VSliderFloat(ImString^ label, ImVec2 size, float% p_data, float p_min, float p_max) { return VSliderScalar<float>(label, size, ImGuiDataType::Float, p_data, p_min, p_max); }
		static bool VSliderInt(ImString^ label, ImVec2 size, int% p_data, int p_min, int p_max, ImString^ format) { return VSliderScalar<int>(label, size, ImGuiDataType::S32, p_data, p_min, p_max, format); }
		static bool VSliderInt(ImString^ label, ImVec2 size, int% p_data, int p_min, int p_max) { return VSliderScalar<int>(label, size, ImGuiDataType::S32, p_data, p_min, p_max); }
		generic<typename T> static bool VSliderScalar(ImString^ label, ImVec2 size, ImGuiDataType data_type, T% p_data, T p_min, T p_max, ImString^ format, float power);
		generic<typename T> static bool VSliderScalar(ImString^ label, ImVec2 size, ImGuiDataType data_type, T% p_data, T p_min, T p_max, ImString^ format);
		generic<typename T> static bool VSliderScalar(ImString^ label, ImVec2 size, ImGuiDataType data_type, T% p_data, T p_min, T p_max);

		static bool InputText(ImString^ label, Span<unsigned char> buf, ImGuiInputTextFlags flags, InputTextDelegate^ callback);
		static bool InputText(ImString^ label, Span<unsigned char> buf, ImGuiInputTextFlags flags);
		static bool InputText(ImString^ label, Span<unsigned char> buf);
		static bool InputText(ImString^ label, ImString^ buf, ImGuiInputTextFlags flags, InputTextDelegate^ callback);
		static bool InputText(ImString^ label, ImString^ buf, ImGuiInputTextFlags flags);
		static bool InputText(ImString^ label, ImString^ buf);
		static bool InputTextMultiline(ImString^ label, Span<unsigned char> buf, ImVec2 size, ImGuiInputTextFlags flags, InputTextDelegate^ callback);
		static bool InputTextMultiline(ImString^ label, Span<unsigned char> buf, ImVec2 size, ImGuiInputTextFlags flags);
		static bool InputTextMultiline(ImString^ label, Span<unsigned char> buf, ImVec2 size);
		static bool InputTextMultiline(ImString^ label, Span<unsigned char> buf);
		static bool InputTextMultiline(ImString^ label, ImString^ buf, ImVec2 size, ImGuiInputTextFlags flags, InputTextDelegate^ callback);
		static bool InputTextMultiline(ImString^ label, ImString^ buf, ImVec2 size, ImGuiInputTextFlags flags);
		static bool InputTextMultiline(ImString^ label, ImString^ buf, ImVec2 size);
		static bool InputTextMultiline(ImString^ label, ImString^ buf);
		static bool InputTextWithHint(ImString^ label, ImString^ hint, Span<unsigned char> buf, ImGuiInputTextFlags flags, InputTextDelegate^ callback);
		static bool InputTextWithHint(ImString^ label, ImString^ hint, Span<unsigned char> buf, ImGuiInputTextFlags flags);
		static bool InputTextWithHint(ImString^ label, ImString^ hint, Span<unsigned char> buf);
		static bool InputTextWithHint(ImString^ label, ImString^ hint, ImString^ buf, ImGuiInputTextFlags flags, InputTextDelegate^ callback);
		static bool InputTextWithHint(ImString^ label, ImString^ hint, ImString^ buf, ImGuiInputTextFlags flags);
		static bool InputTextWithHint(ImString^ label, ImString^ hint, ImString^ buf);
		generic<typename T> static bool InputScalar(ImString^ label, ImGuiDataType data_type, T% p_data, T p_step, T p_step_fast, ImString^ format, ImGuiInputTextFlags flags);
		generic<typename T> static bool InputScalar(ImString^ label, ImGuiDataType data_type, T% p_data, T p_step, T p_step_fast, ImString^ format);
		generic<typename T> static bool InputScalar(ImString^ label, ImGuiDataType data_type, T% p_data, T p_step, T p_step_fast);
		generic<typename T> static bool InputScalar(ImString^ label, ImGuiDataType data_type, T% p_data, T p_step);
		generic<typename T> static bool InputScalar(ImString^ label, ImGuiDataType data_type, T% p_data);
		generic<typename T> static bool InputScalarN(ImString^ label, ImGuiDataType data_type, Span<T> p_data, T p_step, T p_step_fast, ImString^ format, ImGuiInputTextFlags flags);
		generic<typename T> static bool InputScalarN(ImString^ label, ImGuiDataType data_type, Span<T> p_data, T p_step, T p_step_fast, ImString^ format);
		generic<typename T> static bool InputScalarN(ImString^ label, ImGuiDataType data_type, Span<T> p_data, T p_step, T p_step_fast);
		generic<typename T> static bool InputScalarN(ImString^ label, ImGuiDataType data_type, Span<T> p_data, T p_step);
		generic<typename T> static bool InputScalarN(ImString^ label, ImGuiDataType data_type, Span<T> p_data);
		static bool InputFloat(ImString^ label, float% v, float step, float step_fast, ImString^ format, ImGuiInputTextFlags flags) { return InputScalar(label, ImGuiDataType::Float, v, step, step_fast, format, flags); }
		static bool InputFloat(ImString^ label, float% v, float step, float step_fast, ImString^ format) { return InputScalar(label, ImGuiDataType::Float, v, step, step_fast, format); }
		static bool InputFloat(ImString^ label, float% v, float step, float step_fast) { return InputScalar(label, ImGuiDataType::Float, v, step, step_fast); }
		static bool InputFloat(ImString^ label, float% v, float step) { return InputScalar(label, ImGuiDataType::Float, v, step); }
		static bool InputFloat(ImString^ label, float% v) { return InputScalar(label, ImGuiDataType::Float, v); }
		static bool InputFloatN(ImString^ label, Span<float> v, float step, float step_fast, ImString^ format, ImGuiInputTextFlags flags) { return InputScalarN(label, ImGuiDataType::Float, v, step, step_fast, format, flags); }
		static bool InputFloatN(ImString^ label, Span<float>% v, float step, float step_fast, ImString^ format) { return InputScalarN(label, ImGuiDataType::Float, v, step, step_fast, format); }
		static bool InputFloatN(ImString^ label, Span<float> v, float step, float step_fast) { return InputScalarN(label, ImGuiDataType::Float, v, step, step_fast); }
		static bool InputFloatN(ImString^ label, Span<float> v, float step) { return InputScalarN(label, ImGuiDataType::Float, v, step); }
		static bool InputFloatN(ImString^ label, Span<float> v) { return InputScalarN(label, ImGuiDataType::Float, v); }
		static bool InputInt(ImString^ label, int% v, int step, int step_fast, ImString^ format, ImGuiInputTextFlags flags) { return InputScalar(label, ImGuiDataType::S32, v, step, step_fast, format, flags); }
		static bool InputInt(ImString^ label, int% v, int step, int step_fast, ImString^ format) { return InputScalar(label, ImGuiDataType::S32, v, step, step_fast, format); }
		static bool InputInt(ImString^ label, int% v, int step, int step_fast) { return InputScalar(label, ImGuiDataType::S32, v, step, step_fast); }
		static bool InputInt(ImString^ label, int% v, int step) { return InputScalar(label, ImGuiDataType::S32, v, step); }
		static bool InputInt(ImString^ label, int% v) { return InputScalar(label, ImGuiDataType::S32, v); }
		static bool InputIntN(ImString^ label, Span<int> v, int step, int step_fast, ImString^ format, ImGuiInputTextFlags flags) { return InputScalarN(label, ImGuiDataType::S32, v, step, step_fast, format, flags); }
		static bool InputIntN(ImString^ label, Span<int>% v, int step, int step_fast, ImString^ format) { return InputScalarN(label, ImGuiDataType::S32, v, step, step_fast, format); }
		static bool InputIntN(ImString^ label, Span<int> v, int step, int step_fast) { return InputScalarN(label, ImGuiDataType::S32, v, step, step_fast); }
		static bool InputIntN(ImString^ label, Span<int> v, int step) { return InputScalarN(label, ImGuiDataType::S32, v, step); }
		static bool InputIntN(ImString^ label, Span<int> v) { return InputScalarN(label, ImGuiDataType::S32, v); }
		static bool InputDouble(ImString^ label, double% v, double step, double step_fast, ImString^ format, ImGuiInputTextFlags flags) { return InputScalar(label, ImGuiDataType::Double, v, step, step_fast, format, flags); }
		static bool InputDouble(ImString^ label, double% v, double step, double step_fast, ImString^ format) { return InputScalar(label, ImGuiDataType::Double, v, step, step_fast, format); }
		static bool InputDouble(ImString^ label, double% v, double step, double step_fast) { return InputScalar(label, ImGuiDataType::Double, v, step, step_fast); }
		static bool InputDouble(ImString^ label, double% v, double step) { return InputScalar(label, ImGuiDataType::Double, v, step); }
		static bool InputDouble(ImString^ label, double% v) { return InputScalar(label, ImGuiDataType::Double, v); }

		static bool ColorEdit3(ImString^ label, Span<float> col, ImGuiColorEditFlags flags);
		static bool ColorEdit3(ImString^ label, Span<float> col);
		static bool ColorEdit4(ImString^ label, Span<float> col, ImGuiColorEditFlags flags);
		static bool ColorEdit4(ImString^ label, Span<float> col);
		static bool ColorPicker3(ImString^ label, Span<float> col, ImGuiColorEditFlags flags);
		static bool ColorPicker3(ImString^ label, Span<float> col);
		static bool ColorPicker4(ImString^ label, Span<float> col, ImGuiColorEditFlags flags, ReadOnlySpan<float> ref_col);
		static bool ColorPicker4(ImString^ label, Span<float> col, ImGuiColorEditFlags flags);
		static bool ColorPicker4(ImString^ label, Span<float> col);
		static bool ColorButton(ImString^ desc_id, ImVec4 col, ImGuiColorEditFlags flags, ImVec2 size);
		static bool ColorButton(ImString^ desc_id, ImVec4 col, ImGuiColorEditFlags flags);
		static bool ColorButton(ImString^ desc_id, ImVec4 col);
		static void SetColorEditOptions(ImGuiColorEditFlags flags);

		static bool TreeNode(ImString^ label);
		static bool TreeNodeEx(ImString^ label, ImGuiTreeNodeFlags flags);
		static bool TreeNodeEx(ImString^ label);
		static void TreePush(ImString^ str_id);
		static void TreePush();
		static void TreePop();
		static float GetTreeNodeToLabelSpacing();
		static bool CollapsingHeader(ImString^ label, ImGuiTreeNodeFlags flags);
		static bool CollapsingHeader(ImString^ label);
		static bool CollapsingHeader(ImString^ label, bool% p_open, ImGuiTreeNodeFlags flags);
		static bool CollapsingHeader(ImString^ label, bool% p_open);
		static void SetNextItemOpen(bool is_open, ImGuiCond cond);
		static void SetNextItemOpen(bool is_open);

		static bool Selectable(ImString^ label, bool selected, ImGuiSelectableFlags flags, ImVec2 size);
		static bool Selectable(ImString^ label, bool selected, ImGuiSelectableFlags flags);
		static bool Selectable(ImString^ label, bool selected);
		static bool Selectable(ImString^ label);
		static bool Selectable(ImString^ label, bool% p_selected, ImGuiSelectableFlags flags, ImVec2 size);
		static bool Selectable(ImString^ label, bool% p_selected, ImGuiSelectableFlags flags);
		static bool Selectable(ImString^ label, bool% p_selected);

		static bool ListBox(ImString^ label, int% current_item, ListBoxGetter^ items_getter, int items_count, int height_in_items);
		static bool ListBox(ImString^ label, int% current_item, ListBoxGetter^ items_getter, int items_count);
		static bool ListBoxHeader(ImString^ label, ImVec2 size);
		static bool ListBoxHeader(ImString^ label);
		static bool ListBoxHeader(ImString^ label, int items_count, int height_in_items);
		static bool ListBoxHeader(ImString^ label, int items_count);
		static void ListBoxFooter();

		static void PlotLines(ImString^ label, PlotGetter^ values_getter, int values_count, int values_offset, ImString^ overlay_text, float scale_min, float scale_max, ImVec2 graph_size);
		static void PlotLines(ImString^ label, PlotGetter^ values_getter, int values_count, int values_offset, ImString^ overlay_text, float scale_min, float scale_max);
		static void PlotLines(ImString^ label, PlotGetter^ values_getter, int values_count, int values_offset, ImString^ overlay_text, float scale_min);
		static void PlotLines(ImString^ label, PlotGetter^ values_getter, int values_count, int values_offset, ImString^ overlay_text);
		static void PlotLines(ImString^ label, PlotGetter^ values_getter, int values_count, int values_offset);
		static void PlotLines(ImString^ label, PlotGetter^ values_getter, int values_count);
		static void PlotHistogram(ImString^ label, PlotGetter^ values_getter, int values_count, int values_offset, ImString^ overlay_text, float scale_min, float scale_max, ImVec2 graph_size);
		static void PlotHistogram(ImString^ label, PlotGetter^ values_getter, int values_count, int values_offset, ImString^ overlay_text, float scale_min, float scale_max);
		static void PlotHistogram(ImString^ label, PlotGetter^ values_getter, int values_count, int values_offset, ImString^ overlay_text, float scale_min);
		static void PlotHistogram(ImString^ label, PlotGetter^ values_getter, int values_count, int values_offset, ImString^ overlay_text);
		static void PlotHistogram(ImString^ label, PlotGetter^ values_getter, int values_count, int values_offset);
		static void PlotHistogram(ImString^ label, PlotGetter^ values_getter, int values_count);

		static void Value(ImString^ prefix, bool b);
		static void Value(ImString^ prefix, int v);
		static void Value(ImString^ prefix, unsigned int v);
		static void Value(ImString^ prefix, float v, ImString^ float_format);
		static void Value(ImString^ prefix, float v);

		static bool BeginMenuBar();
		static void EndMenuBar();
		static bool BeginMainMenuBar();
		static void EndMainMenuBar();
		static bool BeginMenu(ImString^ label, bool enabled);
		static bool BeginMenu(ImString^ label);
		static void EndMenu();
		static bool MenuItem(ImString^ label, ImString^ shortcut, bool selected, bool enabled);
		static bool MenuItem(ImString^ label, ImString^ shortcut, bool selected);
		static bool MenuItem(ImString^ label, ImString^ shortcut);
		static bool MenuItem(ImString^ label);
		static bool MenuItem(ImString^ label, ImString^ shortcut, bool% p_selected, bool enabled);
		static bool MenuItem(ImString^ label, ImString^ shortcut, bool% p_selected);

		static void BeginTooltip();
		static void EndTooltip();
		static void SetTooltip(ImString^ text);

		static void OpenPopup(ImString^ str_id);
		static bool BeginPopup(ImString^ str_id, ImGuiWindowFlags flags);
		static bool BeginPopup(ImString^ str_id);
		static bool BeginPopupContextItem(ImString^ str_id, ImGuiMouseButton mouse_button);
		static bool BeginPopupContextItem(ImString^ str_id);
		static bool BeginPopupContextItem();
		static bool BeginPopupContextWindow(ImString^ str_id, ImGuiMouseButton mouse_button, bool also_over_items);
		static bool BeginPopupContextWindow(ImString^ str_id, ImGuiMouseButton mouse_button);
		static bool BeginPopupContextWindow(ImString^ str_id);
		static bool BeginPopupContextWindow();
		static bool BeginPopupContextVoid(ImString^ str_id, ImGuiMouseButton mouse_button);
		static bool BeginPopupContextVoid(ImString^ str_id);
		static bool BeginPopupContextVoid();
		static bool BeginPopupModal(ImString^ name, bool% p_open, ImGuiWindowFlags flags);
		static bool BeginPopupModal(ImString^ name, bool% p_open);
		static bool BeginPopupModal(ImString^ name);
		static void EndPopup();
		static bool OpenPopupOnItemClick(ImString^ str_id, ImGuiMouseButton mouse_button);
		static bool OpenPopupOnItemClick(ImString^ str_id);
		static bool OpenPopupOnItemClick();
		static bool IsPopupOpen(ImString^ str_id);
		static void CloseCurrentPopup();

		static void Columns(int count, ImString^ id, bool border);
		static void Columns(int count, ImString^ id);
		static void Columns(int count);
		static void Columns();
		static void NextColumn();
		static int GetColumnIndex();
		static float GetColumnWidth(int column_index);
		static float GetColumnWidth();
		static void SetColumnWidth(int column_index, float width);
		static float GetColumnOffset(int column_index);
		static float GetColumnOffset();
		static void SetColumnOffset(int column_index, float offset_x);
		static int GetColumnsCount();

		static bool BeginTabBar(ImString^ str_id, ImGuiTabBarFlags flags);
		static bool BeginTabBar(ImString^ str_id);
		static void EndTabBar();                                                        
		static bool BeginTabItem(ImString^ label, bool% p_open, ImGuiTabItemFlags flags);
		static bool BeginTabItem(ImString^ label, bool% p_open);
		static bool BeginTabItem(ImString^ label);
		static void EndTabItem();
		static void SetTabItemClosed(ImString^ tab_or_docked_window_label); 

		static void LogToTTY(int auto_open_depth);
		static void LogToTTY();
		static void LogToFile(int auto_open_depth, ImString^ filename);
		static void LogToFile(int auto_open_depth);
		static void LogToFile();
		static void LogToClipboard(int auto_open_depth);
		static void LogToClipboard();
		static void LogFinish();                                                     
		static void LogButtons();         
		static void LogText(ImString^ text);

		static bool BeginDragDropSource(ImGuiDragDropFlags flags);
		static bool BeginDragDropSource();
		static bool SetDragDropPayload(ImString^ type, IntPtr data, size_t sz, ImGuiCond cond);
		static bool SetDragDropPayload(ImString^ type, IntPtr data, size_t sz);
		static void EndDragDropSource();
		static bool BeginDragDropTarget();
		static ImGuiPayload AcceptDragDropPayload(ImString^ type, ImGuiDragDropFlags flags);
		static ImGuiPayload AcceptDragDropPayload(ImString^ type);
		static void EndDragDropTarget();                                                          
		static ImGuiPayload GetDragDropPayload();                                                           

		static void PushClipRect(ImVec2 clip_rect_min, ImVec2 clip_rect_max, bool intersect_with_current_clip_rect);
		static void PopClipRect();

		static void SetItemDefaultFocus();
		static void SetKeyboardFocusHere(int offset);
		static void SetKeyboardFocusHere();

		static bool IsItemHovered(ImGuiHoveredFlags flags);
		static bool IsItemHovered();
		static bool IsItemActive();
		static bool IsItemFocused();
		static bool IsItemClicked(ImGuiMouseButton mouse_button);
		static bool IsItemClicked();
		static bool IsItemVisible();
		static bool IsItemEdited();
		static bool IsItemActivated();
		static bool IsItemDeactivated();
		static bool IsItemDeactivatedAfterEdit();
		static bool IsItemToggledOpen();
		static bool IsAnyItemHovered();
		static bool IsAnyItemActive();
		static bool IsAnyItemFocused();
		static ImVec2 GetItemRectMin();
		static ImVec2 GetItemRectMax();
		static ImVec2 GetItemRectSize();
		static void SetItemAllowOverlap();

		static bool IsRectVisible(ImVec2 size);
		static bool IsRectVisible(ImVec2 rect_min, ImVec2 rect_max);
		static double GetTime();
		static int GetFrameCount();
		static ImDrawList GetBackgroundDrawList();
		static ImDrawList GetForegroundDrawList();                   
		static ImImmutableString GetStyleColorName(ImGuiCol idx);
		//static void SetStateStorage(ImGuiStorage* storage);                        
		static ImGuiStorage GetStateStorage();
		static ImVec2 CalcTextSize(ImString^ text, bool hide_text_after_double_hash, float wrap_width);
		static ImVec2 CalcTextSize(ImString^ text, bool hide_text_after_double_hash);
		static ImVec2 CalcTextSize(ImString^ text);
		static void CalcListClipping(int items_count, float items_height, [Out] int% out_items_display_start, [Out] int% out_items_display_end);
		static bool BeginChildFrame(ImGuiID id, ImVec2 size, ImGuiWindowFlags flags);
		static bool BeginChildFrame(ImGuiID id, ImVec2 size);
		static void EndChildFrame();

		static ImVec4 ColorConvertU32ToFloat4(ImU32 in);
		static ImU32 ColorConvertFloat4ToU32(ImVec4 in);
		static void ColorConvertRGBtoHSV(float r, float g, float b, [Out] float% out_h, [Out] float% out_s, [Out] float% out_v);
		static void ColorConvertHSVtoRGB(float h, float s, float v, [Out] float% out_r, [Out] float% out_g, [Out] float% out_b);
		
		static int GetKeyIndex(ImGuiKey imgui_key);  
		static bool IsKeyDown(int user_key_index);
		static bool IsKeyPressed(int user_key_index, bool repeat);
		static bool IsKeyPressed(int user_key_index);
		static bool IsKeyReleased(int user_key_index);                                
		static int GetKeyPressedAmount(int key_index, float repeat_delay, float rate);
		static void CaptureKeyboardFromApp(bool want_capture_keyboard_value);
		static void CaptureKeyboardFromApp();

		static bool IsMouseDown(ImGuiMouseButton button);
		static bool IsMouseClicked(ImGuiMouseButton button, bool repeat);
		static bool IsMouseClicked(ImGuiMouseButton button);
		static bool IsMouseReleased(ImGuiMouseButton button);
		static bool IsMouseDoubleClicked(ImGuiMouseButton button);
		static bool IsMouseHoveringRect(ImVec2 r_min, ImVec2 r_max, bool clip);
		static bool IsMouseHoveringRect(ImVec2 r_min, ImVec2 r_max);
		static bool IsMousePosValid(ImVec2 mouse_pos);
		static bool IsMousePosValid();
		static bool IsAnyMouseDown();
		static ImVec2 GetMousePos();
		static ImVec2 GetMousePosOnOpeningCurrentPopup();
		static bool IsMouseDragging(ImGuiMouseButton button, float lock_threshold);
		static bool IsMouseDragging(ImGuiMouseButton button);
		static ImVec2 GetMouseDragDelta(ImGuiMouseButton button, float lock_threshold);
		static ImVec2 GetMouseDragDelta(ImGuiMouseButton button);
		static ImVec2 GetMouseDragDelta();
		static void ResetMouseDragDelta(ImGuiMouseButton button);
		static void ResetMouseDragDelta();
		static ImGuiMouseCursor GetMouseCursor();
		static void SetMouseCursor(ImGuiMouseCursor cursor_type);
		static void CaptureMouseFromApp(bool want_capture_mouse_value);
		static void CaptureMouseFromApp();

		static ImImmutableString GetClipboardText();
		static void SetClipboardText(ImString^ text);

		static void LoadIniSettingsFromDisk(ImString^ ini_filename);
		static void LoadIniSettingsFromMemory(ImString^ ini_data);
		static void SaveIniSettingsToDisk(ImString^ ini_filename);
		static ImImmutableString SaveIniSettingsToMemory();
	};
}
