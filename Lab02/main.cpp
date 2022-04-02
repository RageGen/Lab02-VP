#include "Func.hpp"
#include "Menu.hpp"
#include "Item.hpp"
using namespace std;
using namespace ZDA;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int StudentsAmount = 0;
	int TeachersAmount = 0;
	int CheckMenu = 0;
	const int ItemsNumber = 2;
	bool RunMenu = true;
	Item Items[ItemsNumber]{Item{"Ввод информации о студенте",InputStudentInfo},Item{"Вывод",StudentsTable}};
	Menu menu("ZDA menu", Items, ItemsNumber);
	while (menu.runCommand())
	{
	}
	return 0;
}
