// menuLib.cpp : Определяет функции для статической библиотеки.
//

#include "pch.h"
#include "framework.h"
#include "string"
#include "map"
#include "iostream"
#include "menuLib.h"
#include <functional>
#include <unordered_map>

void Menu::printMenu() {
	std::cout << "                                                 " << name << std::endl;
	for (size_t i = 1; i <= numOfFuns; i++) {
		std::cout << i << ": " << textMap[i] << std::endl;
	}
	std::cout << std::endl << "0: Exit" << std::endl;
	std::cout << std::endl << "Select Menu Item >> ";
}
size_t Menu::inputItem() {
	size_t menuNum, countWrong = 0;
	while (!(std::cin >> menuNum)) {
		system("CLS");
		countWrong++;
		printMenu();
		std::cout << "\n";
		//Возврат на предыдущую строку и её отчистка
		std::cout << "\033[A" << "\033[K";
		std::cout << "Wrong input, try again >> ";
		if (countWrong > 2) {
			std::cout << "\n" << "\033[K" << "Count of wrong inputs >> " << countWrong << "\033[A";
		}
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	std::cout << "\n";
	return menuNum;
}
void Menu::removeItem(size_t idx) {
	textMap.erase(idx);
	funMap.erase(idx);
	for (size_t i = idx; i < numOfFuns; i++) {
		textMap[i] = textMap[i + 1];
		funMap[i] = funMap[i + 1];
	}
	numOfFuns--;
}
std::map<size_t, std::string> Menu::getItems() {
	return textMap;
}
void Menu::addMenuItem(std::string text, void(*fun)()) {
	numOfFuns++;
	funMap[numOfFuns] = fun;
	textMap[numOfFuns] = text;
}

void Menu::setName(std::string _name){
	name = _name;
}
void Menu::mainLoop() {
	system("CLS");
	std::size_t menuNum = 1;
	while (true) {
		printMenu();
		menuNum = inputItem();
		if (menuNum == 0) {
			break;
		}
		if (funMap.find(menuNum) != funMap.end()) {
			funMap[menuNum]();
		}
		system("pause");
		system("CLS");
	}

}