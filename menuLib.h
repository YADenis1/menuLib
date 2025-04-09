#pragma once
#include "string"
#include "map"


class Menu {
public:
	void addMenuItem(std::string text, void(*fun)());
	void mainLoop();
	std::string name = "Menu";
	void setName(std::string _name);
	void removeItem(size_t idx);
	std::map<size_t, std::string> getItems();
private:
	void printMenu();
	std::map<size_t, std::string> color;
	std::map<size_t, void(*)()> funMap;
	std::map<size_t, std::string> textMap;
	size_t numOfFuns = 0;
	size_t inputItem();
};