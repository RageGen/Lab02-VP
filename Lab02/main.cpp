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
	const int ItemsNumber = 3;
	bool RunMenu = true;
	LocalInformation();
	Item Items[ItemsNumber]{ Item{"���� ���������� � �����",InputAllInfo},Item{"����� ����������",AllInfoTable},Item{"�������� �������� ���� ����������",CheckAge}};
	Menu menu("������� ����", Items, ItemsNumber);
	while (menu.runCommand())
	{
		system("cls");
	}
	return 0;
}
