#include "Menu.hpp"
#include <iostream>
namespace ZDA
{
	Menu::Menu(std::string title, Item* items, size_t count)
	{
		m_count = count;
		m_menu_title = title;
		m_items = items;
	}
	int Menu::getSelect() const
	{
		return m_select;
	}
	bool Menu::isRun() const
	{
		return m_running;
	}
	size_t Menu::getCount() const
	{
		return m_count;
	}
		std::string Menu::getTitle() const
	{
		return m_menu_title;
	}
	Item* Menu::getItems()
	{
		return m_items;
	}
	void Menu::printMenu() const
	{
		std::cout << getTitle() << std::endl;
		for (int i = 0; i < m_count; i++)
		{
			std::cout << i + 1 << ". ";
			m_items[i].printItem();
			std::cout << std::endl;
		}
		std::cout << "0. Выход" << std::endl;
	}
	bool Menu::runCommand()
	{
		printMenu();
		std::cout << "\nВведите пункт меню\n>> ";
		std::cin >> m_select;
		if (m_select == 0)
			return false;
		return m_items[m_select - 1].run();
	}
}