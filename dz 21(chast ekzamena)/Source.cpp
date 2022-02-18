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
			std::cout << "---–≈√»—“–ј÷»я---" << std::endl;
			std::cout << "¬ведите логин: ";
			std::cin >> login;
			std::cout << "¬ведите пароль: ";
			std::cin >> password;
			A.Register(login, password);
			Sleep(2000);
			system("cls");
			MenuAdm(A);

		}
		else {
			Admin A;
			std::cout << "---јвторизаци€---" << std::endl;
			A.Login();
			Sleep(2000);
			system("cls");
			MenuAdm(A);
		}
	}
		  break;
	case 2: {
		string path, index;
		cout << "¬ведите ваш индекс в списке: ";
		cin >> index;
		path = "guest" + index + ".txt";
		if (!ChecK(path)) {
			Guest G;
			string login, password;
			cout << "---–≈√»—“–ј÷»я---" << std::endl;
			cout << "¬ведите логин: ";
			cin >> login;
			cout << "¬ведите пароль: ";
			cin >> password;
			G.Register(login, password, path);
			count_in++;
			Sleep(2000);
			system("cls");
			MenuGue(G, index);
		}
		else {
			Guest G;
			std::cout << "---јвторизаци€---" << std::endl;
			G.Login(path);
			Sleep(2000);
			system("cls");
			MenuGue(G, index);
		}
	}
	case 0: {}break;
	default:std::cout << "ќшибка выбора!" << std::endl;
		break;
	}
}