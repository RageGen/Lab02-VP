#pragma once
#include <string>
namespace ZDA
{
	class Item
	{
	public:
		typedef bool (*Func)();
		Item(std::string, Func);
		std::string getItemTitle() const;
		void printItem() const;
		bool run();
	private:
		Func m_func{};
		std::string m_item_title;
	};
}