#include "Item.hpp"
namespace ZDA
{
	class Menu
	{
	public:
		Menu(std::string, Item*, size_t);
		int getSelect() const;
		bool isRun() const;
		std::string getTitle() const;
		size_t getCount() const;
		Item* getItems();
		void printMenu() const;
		bool runCommand();
	private:
		int m_select{ -1 };
		size_t m_count{};
		std::string m_menu_title;
		bool m_running{};
		Item* m_items{};
	};
}