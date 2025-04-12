#pragma once
#include "string"
#include "map"
#include "functional"

class Menu {
public:
	template <typename C>
	void addMenuItem(const std::string& text, C* obj, void (C::* method)()) {
		numOfFuns++;
		funMap[numOfFuns] = [obj, method]() { (obj->*method)(); };
		textMap[numOfFuns] = text;
	}
	void addMenuItem(std::string text, void(*fun)());
	void mainLoop();
	std::string name = "Menu";
	void setName(std::string _name);
	void removeItem(size_t idx);
	std::map<size_t, std::string> getItems();
private:
	void printMenu();
	std::map<size_t, std::string> color;
	std::map<size_t, std::function<void()>> funMap;
	std::map<size_t, std::string> textMap;
	size_t numOfFuns = 0;
	size_t inputItem();
};