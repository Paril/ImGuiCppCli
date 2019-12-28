#include "ImDrawData.h"
#include "ImDrawList.h"

namespace ImGuiCppCli
{
	private ref struct ImDrawDataEnumerable : public IEnumerable<ImDrawList>
	{
		OGImDrawData* _handle;

	public:
		ImDrawDataEnumerable(OGImDrawData* handle) :
			_handle(handle)
		{
		}

		virtual IEnumerator<ImDrawList>^ GetEnumerator() sealed = IEnumerable<ImDrawList>::GetEnumerator
		{
			return gcnew Enumerator(_handle);
		}

		virtual BaseEnumerator^ GetEnumeratorBase() sealed = BaseEnumerable::GetEnumerator
		{
			return GetEnumerator();
		}

	private:
		ref struct Enumerator : public IEnumerator<ImDrawList>
		{
			int _index = -1;
			OGImDrawData* _handle;

		public:
			Enumerator(OGImDrawData* handle) :
				_handle(handle)
			{
			}

			property ImDrawList Current
			{
				virtual ImDrawList get()
				{
					return ImDrawList(_handle->CmdLists[_index]);
				}
			};

			property Object^ CurrentBase
			{
				virtual Object^ get() sealed = BaseEnumerator::Current::get
				{
					return Current;
				}
			};

			virtual bool MoveNext()
			{
				return (++_index) != _handle->CmdListsCount;
			}

			virtual void Reset()
			{
				_index = -1;
			}

			virtual ~Enumerator()
			{
			}
		};
	};

	ImDrawData::ImDrawData(OGImDrawData* handle) :
		_handle(handle)
	{
	}

	WRAPPED_PROP_AUTO_IMPL(ImDrawData, Valid);
	IEnumerable<ImDrawList>^ ImDrawData::CmdLists::get() { return gcnew ImDrawDataEnumerable(_handle); }
	ImDrawList ImDrawData::GetCmdList(int index) { return ImDrawList(_handle->CmdLists[index]); }
	WRAPPED_PROP_AUTO_IMPL(ImDrawData, CmdListsCount);
	WRAPPED_PROP_AUTO_IMPL(ImDrawData, TotalIdxCount);
	WRAPPED_PROP_AUTO_IMPL(ImDrawData, TotalVtxCount);
	WRAPPED_PROP_UDT_IMPL(ImDrawData, ImVec2, DisplayPos);
	WRAPPED_PROP_UDT_IMPL(ImDrawData, ImVec2, DisplaySize);
	WRAPPED_PROP_UDT_IMPL(ImDrawData, ImVec2, FramebufferScale);

	void ImDrawData::DeIndexAllBuffers() { _handle->DeIndexAllBuffers(); }
	void ImDrawData::ScaleClipRects(ImVec2 fb_scale) { _handle->ScaleClipRects(fb_scale); }
}