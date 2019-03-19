#include <iostream>
#include "EventDispatcher.h"

void Run() {
	std::cout << "Run!" << std::endl;
}

int main() {
	EventDispatcher* eventDispatcher = EventDispatcher::Instance();

	eventDispatcher->addEventListener("Move", []() {
		std::cout << "Move!" << std::endl;
	});
	eventDispatcher->addEventListener("Run", Run);

	eventDispatcher->dispatchEvent("Move");
	eventDispatcher->dispatchEvent("Run");

	return 0;
}
