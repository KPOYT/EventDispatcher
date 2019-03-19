////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Event Dispatcher
// (C)2019 Stanislav Kazachok
// v1.0 (20.03.2019)

// Making subscribers on events
// Dispatching events for notify subscribers

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <string>
#include <vector>

struct Event {
	std::string type;
	void (*callback)();
};

class EventDispatcher {
	public:
	static EventDispatcher* Instance();
	void addEventListener(std::string type, void (*callback)());
	void removeEventListener(std::string type, void (*callback)());
	void dispatchEvent(std::string type);

	private:
	EventDispatcher() {};
	EventDispatcher(EventDispatcher const&) {};
	EventDispatcher& operator=(EventDispatcher const&) {};
	bool findEvent(std::string type, void(*callback)());

	static EventDispatcher* m_pInstance;
	std::vector<Event> events;
};
