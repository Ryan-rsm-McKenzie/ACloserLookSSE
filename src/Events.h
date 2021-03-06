#pragma once

namespace Events
{
	class InputEventHandler : public RE::BSTEventSink<RE::InputEvent*>
	{
	public:
		using EventResult = RE::BSEventNotifyControl;

		static InputEventHandler* GetSingleton();

		virtual EventResult ProcessEvent(RE::InputEvent* const* a_event, RE::BSTEventSource<RE::InputEvent*>* a_eventSource) override;

		bool Save(const SKSE::SerializationInterface* a_intfc, UInt32 a_typeCode, UInt32 a_version);
		bool Load(const SKSE::SerializationInterface* a_intfc);
		void Clear();
		UInt32 GetKey() const;
		void SetKey(UInt32 a_key);

	private:
		using Lock = std::recursive_mutex;
		using Locker = std::lock_guard<Lock>;

		enum : UInt32
		{
			kInvalid = static_cast<UInt32>(-1),
			kKeyboardOffset = 0,
			kMouseOffset = 256
		};

		InputEventHandler();
		InputEventHandler(const InputEventHandler&) = delete;
		InputEventHandler(InputEventHandler&&) = delete;
		virtual ~InputEventHandler() = default;

		InputEventHandler& operator=(const InputEventHandler&) = delete;
		InputEventHandler& operator=(InputEventHandler&&) = delete;

		mutable Lock _lock;
		UInt32 _key;
	};

	void SinkEventHandlers();
}
