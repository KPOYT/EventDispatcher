////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Event Dispatcher
// (C)2019 Stanislav Kazachok
// v1.0 (20.03.2019)

// Making subscribers on events
// Dispatching events for notify subscribers

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "EventDispatcher.h"

EventDispatcher* EventDispatcher::m_pInstance = NULL;

EventDispatcher* EventDispatcher::Instance() {
	if (!m_pInstance) {
		m_pInstance = new EventDispatcher();
	}

	return m_pInstance;
}


void EventDispatcher::addEventListener(std::string type, void (*callback)()) {
	if (findEvent(type, callback)) return;

	Event event;
	event.type = type;
	event.callback = callback;

	events.push_back(event);
}

void EventDispatcher::removeEventListener(std::string type, void (*callback)()) {
	for (int i = events.size() - 1; i >= 0; i--) {
		if (events[i].type == type && events[i].callback == callback) {
			events.erase(events.begin() + i);
		}
	}
}

void EventDispatcher::dispatchEvent(std::string type) {
	for (int i = 0; i < events.size(); i++) {
		if (events[i].type == type) {
			(events[i].callback)();
		}
	}
}


bool EventDispatcher::findEvent(std::string type, void(*callback)()) {
	for (int i = events.size() - 1; i >= 0; i--) {
		if (events[i].type == type && events[i].callback == callback) {
			return true;
		}
	}

	return false;
}
