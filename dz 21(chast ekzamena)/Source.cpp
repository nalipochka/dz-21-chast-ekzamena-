#include"Header.h"

int main() {
	setlocale(LC_ALL, "RU");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	int menu, count_in = 1;
	Menu_main();
	cin >> menu;
	system("cls");
	switch (menu)
	{
	case 1: {
		if (!ChecK("admin.txt")) {
			Admin A;
			std::string login, password;
			std::cout << "---�����������---" << std::endl;
			std::cout << "������� �����: ";
			std::cin >> login;
			std::cout << "������� ������: ";
			std::cin >> password;
			A.Register(login, password);
			Sleep(2000);
			system("cls");
			MenuAdm(A);

		}
		else {
			Admin A;
			std::cout << "---�����������---" << std::endl;
			A.Login();
			Sleep(2000);
			system("cls");
			MenuAdm(A);
		}
	}
		  break;
	case 2: {
		string path, index;
		cout << "������� ��� ������ � ������: ";
		cin >> index;
		path = "guest" + index + ".txt";
		if (!ChecK(path)) {
			Guest G;
			string login, password;
			cout << "---�����������---" << std::endl;
			cout << "������� �����: ";
			cin >> login;
			cout << "������� ������: ";
			cin >> password;
			G.Register(login, password, path);
			count_in++;
			Sleep(2000);
			system("cls");
			MenuGue(G, index);
		}
		else {
			Guest G;
			std::cout << "---�����������---" << std::endl;
			G.Login(path);
			Sleep(2000);
			system("cls");
			MenuGue(G, index);
		}
	}
	case 0: {}break;
	default:std::cout << "������ ������!" << std::endl;
		break;
	}
}