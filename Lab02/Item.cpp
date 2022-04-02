#include "Item.hpp"
#include <iostream>
namespace ZDA
{
	Item::Item(std::string item_title, Item::Func func)
	{
		m_item_title = item_title;
		m_func = func;
	}
	std::string Item::getItemTitle() const
	{
		return m_item_title;
	}
	void Item::printItem() const
	{
		std::cout << m_item_title;
	}
	bool Item::run()
	{
		return m_func();
	}
}
