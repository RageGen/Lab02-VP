#pragma once
#include <string>
namespace ZDA
{
	class Item
	{
	public:
		Item(std::string, bool);
		std::string getItemTitle() const;
		void printItem() const;
		bool run();
	private:
		bool m_func{};
		std::string m_item_title;
	};
}