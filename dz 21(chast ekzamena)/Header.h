#pragma once
#include<iostream>
#include<Windows.h>
#include<string>
#include<fstream>
#include<iomanip>
#include<vector>;

using namespace std;

vector<string> math1;
vector<string> rus1;
vector<string> fiz1;
std::string ElogiN(std::string login) {
	std::string elogin = login;
	for (size_t i = 0; i < login.size(); i++)
	{
		elogin[i] = login[i] + 3;
	}
	return elogin;
}
std::string Dlogin(std::string elogin) {
	std::string login = elogin;
	for (size_t i = 0; i < elogin.size(); i++)
	{
		login[i] = elogin[i] - 3;
	}
	return login;
}
bool ChecK(string path) {
	std::ifstream in(path, std::ios_base::in);
	if (!in.is_open()) {
		return false;
	}
	else {
		in.close();
		return true;
	}
}
void push_math1(vector<string>& V) {
	V.push_back("1. Даны моженства А = {a, b, d, e, f}, B = {b, c, e, g}, C = {a, d, f}. Отметьте верное равенство:\na) C = Пересечения А и В\nб) С = А \\ В\nв) С = А U B\nг) С = B \\ A\n");
	V.push_back("2. Какой граф называется мультиграфом?\na) содердит кратные ребра\nб) имеет петлю\nв) ребра имеют направление\n");
	V.push_back("3. Множество можна задать:\na) очередью\nб) процедурой что продолжает\nв) процедурой что роспознает\n");
	V.push_back("4. Какая операция над множествами называется однородной?\na) объединение\nб) пересечение\nв) дополнение\n");
}
void push_rus1(vector<string>& V) {
	V.push_back("Укажите основную функцию русского языка:\nа) Коммуникативная\nб) Мировоззренческая\nв) Познавательная\nг) Практически - действенная функция.");
	V.push_back("Кто был основоположником русского литературного языка?\nа) М.В.Ломоносов\nб) Л.Н.Толстой\nв) А.С.Пушкин\nг) Н.М.Карамзин");
	V.push_back("От какого слова произошло название раздела лингвистики «Фонетика»?\nа) Буква\nб) Ударение\nв) Слог\nг) Звук");
	V.push_back("колько согласных букв в русском языке?\nа) 10\nб) 14\nв) 19\nг) 21");
}
void push_fiz1(vector<string>& V) {
	V.push_back("Капля, падая с крыши дома, приобрела в конце своего пути скорость 30 м/с. Она находилась в полете\nа) 2 с\nб) 5 с\nв) 3 с\nг) 4 с");
	V.push_back("Предположим, что масса Земли увеличилась в 4 раза, а диаметр остался прежним. В этом случае сила, действующая со стороны Земли на тело, которое находится на ее поверхности\nа) уменьшится в 2 раза\nб) увеличится в 2 раза\nв) уменьшится в 4 раза\nг) увеличится в 4 раза");
	V.push_back("Атомное ядро согласно существующей модели является\nа) шаром, состоящим из протонов и электронов\nб) однородным шаром, имеющим положительный заряд\nв) шаром, состоящим из протонов и нейтронов\nг) шаром, состоящим из всех известных элементарных частиц");
	V.push_back("Причиной магнитного взаимодействия является то, что\nа) тела имеют массы\nб) тела движутся\nв) тела имеют некомпенсированные неподвижные заряды\nг) в состав тел входят движущиеся заряженные частицы");
}


class Admin {
	std::string elogin;
	std::string epassword;
public:
	Admin() = default;
	void Register(std::string login, std::string password) {
		this->elogin = ElogiN(login);
		this->epassword = ElogiN(password);
		FILE* f1;
		if (fopen_s(&f1, "admin.txt", "w") == NULL) {
			//std::cout << "FILE OPENED" << std::endl;
			fputs(this->elogin.c_str(), f1);
			fputs("\n", f1);
			fputs(this->epassword.c_str(), f1);
			fputs("\n", f1);
			fclose(f1);
			std::cout << "Регистрация прошла успешно!" << std::endl;
		}
	}
	void Login() {
		std::string  login, password;
		std::ifstream in("admin.txt", std::ios_base::in);
		if (!in.is_open()) {
			std::cout << "Файл не найден!" << std::endl;
		}
		else {
			getline(in, this->elogin);
			getline(in, this->epassword);
			in.close();
		}
		while (true) {
			std::cout << "Введите логин: ";
			std::cin >> login;
			std::cout << "Введите пароль: ";
			std::cin >> password;
			if (Dlogin(this->elogin) != login || Dlogin(this->epassword) != password) {
				std::cout << "Не верный логин или пароль!" << std::endl;
			}
			else {
				std::cout << "Добро пожаловать!" << std::endl;
				break;
			}
		}
	}
	void ReLogin() {
		std::ofstream out("admin.txt", std::ios_base::out);
		if (!out.is_open()) {
			std::cout << "Ошибка, файл не может быть открыт для записи!" << std::endl;
		}
		else {
			std::string login, password;
			std::cout << "Введите новый логин: ";
			std::cin >> login;
			std::cout << "Введите новый пароль: ";
			std::cin >> password;
			this->elogin = ElogiN(login);
			this->epassword = ElogiN(password);
			out << this->elogin << "\n";
			out << this->epassword << "\n";
			out.close();
			std::cout << "Данные  успешно изменены." << std::endl;
		}
	}
	void ShowData() {
		std::cout << "login: " << Dlogin(this->elogin) << std::endl;
		std::cout << "password: " << Dlogin(this->epassword) << std::endl;
	}
};

class Guest {
	std::string elogin;
	std::string epassword;
	std::string FullName;
	std::string HomeAdress;
	std::string PhoneNumber;
public:
	Guest() = default;
	void Register(string login, string password, string path) {
		this->elogin = ElogiN(login);
		this->epassword = ElogiN(password);
		cout << "Введите ФИО: ";
		cin.ignore();
		getline(cin, this->FullName);
		cout << "Введите домашний адрес: ";
		getline(cin, this->HomeAdress);
		cout << "Введите номер телефона: ";
		getline(cin, this->PhoneNumber);
		ofstream out(path, ios_base::out);
		if (!out.is_open()) {
			cout << "Файл не может быть открыт!" << endl;
		}
		else {
			out << this->elogin << '\n';
			out << this->epassword << '\n';
			out << "ФИО: " << this->FullName << '\n';
			out << "Домашний адрес: " << this->HomeAdress << '\n';
			out << "Телефон: " << this->PhoneNumber << '\n';
			out.close();
			std::cout << "Регистрация прошла успешно!" << std::endl;
		}
	}
	void Login(string path) {
		std::string login, password;
		std::ifstream in(path, std::ios_base::in);
		if (!in.is_open()) {
			std::cout << "Файл не найден!" << std::endl;
		}
		else {
			getline(in, this->elogin);
			getline(in, this->epassword);
			getline(in, this->FullName);
			getline(in, this->HomeAdress);
			getline(in, this->PhoneNumber);
			in.close();
		}
		while (true) {
			std::cout << "Введите логин: ";
			std::cin >> login;
			std::cout << "Введите пароль: ";
			std::cin >> password;
			if (Dlogin(this->elogin) != login || Dlogin(this->epassword) != password) {
				std::cout << "Не верный логин или пароль!" << std::endl;
			}
			else {
				std::cout << "Добро пожаловать!" << std::endl;
				break;
			}
		}
	}
	void ShowData() {
		std::cout << "login: " << Dlogin(this->elogin) << std::endl;
		std::cout << "password: " << Dlogin(this->epassword) << std::endl;
		std::cout << this->FullName << std::endl;
		std::cout << this->HomeAdress << std::endl;
		std::cout << this->PhoneNumber << std::endl;
	}
	void Test(string index) {
		int test;
		do
		{
			cout.width(15);
			cout << "|Тесты|" << endl;
			cout << "1 –> Дискретная математика;" << endl;
			cout << "2 -> Русский язык (общий тест);" << endl;
			cout << "3 –> Механика;" << endl;
			cout << "0 -> Выход из меню тестов." << endl;
			cout << "->";
			cin >> test;
			system("cls");
			switch (test)
			{
			case 1: {
				string path = "math" + index + ".txt";
				fstream f(path, ios::out);
				try
				{
					if (!f.is_open()) {
						throw "Тест не может быть записан!";
					}
					else {
						push_math1(math1);
						int score = 0, count_win = 0, procent_win = 0;
						char var;
						cout << "Дискретная математика(1 вопрос = 3 балла):" << endl;
						cout << math1[0] << endl;
						cin >> var;
						f << var << '\n';
						if (var == 'б') {
							count_win++;
							score += 3;
						}
						system("cls");
						cout << math1[1] << endl;
						cin >> var;
						f << var << '\n';
						if (var == 'а') {
							count_win++;
							score += 3;
						}
						system("cls");
						cout << math1[2] << endl;
						cin >> var;
						f << var << '\n';
						if (var == 'б') {
							count_win++;
							score += 3;
						}
						system("cls");
						cout << math1[3] << endl;
						cin >> var;
						f << var << '\n';
						if (var == 'в') {
							count_win++;
							score += 3;
						}
						system("cls");
						procent_win = (double)count_win / 4 * 100;
						cout << "Результат теста: " << endl;
						cout << "Количество правильных ответов: " << count_win << endl;
						f << count_win << '\n';
						cout << "Процент правильных ответов: " << procent_win << '%' << endl;
						f << procent_win << '\n';
						cout << "Оценка: " << score << " балов" << endl;
						f << score << '\n';
						f.close();
						system("pause");
						system("cls");

					}
				}
				catch (const char* str)
				{
					cerr << str << endl;
				}
			}
				  break;
			case 2: {
				string path = "rus" + index + ".txt";
				fstream f("rus1.txt", ios::out);
				try
				{
					if (!f.is_open()) {
						throw "Тест не может быть записан!";
					}
					else {
						push_rus1(rus1);
						int score = 0, count_win = 0, procent_win = 0;
						char var;
						cout << "Русский язык(1 вопрос = 3 балла):" << endl;
						cout << rus1[0] << endl;
						cin >> var;
						f << var << '\n';
						if (var == 'а') {
							count_win++;
							score += 3;
						}
						system("cls");
						cout << rus1[1] << endl;
						cin >> var;
						f << var << '\n';
						if (var == 'в') {
							count_win++;
							score += 3;
						}
						system("cls");
						cout << rus1[2] << endl;
						cin >> var;
						f << var << '\n';
						if (var == 'б') {
							count_win++;
							score += 3;
						}
						system("cls");
						cout << rus1[3] << endl;
						cin >> var;
						f << var << '\n';
						if (var == 'г') {
							count_win++;
							score += 3;
						}
						system("cls");
						procent_win = (double)count_win / 4 * 100;
						cout << "Результат теста: " << endl;
						cout << "Количество правильных ответов: " << count_win << endl;
						f << count_win << '\n';
						cout << "Процент правильных ответов: " << procent_win << '%' << endl;
						f << procent_win << '\n';
						cout << "Оценка: " << score << " балов" << endl;
						f << score << '\n';
						f.close();
						system("pause");
						system("cls");

					}
				}
				catch (const char* str)
				{
					cerr << str << endl;
				}
			}
				  break;
			case 3: {
				string path = "fiz" + index + ".txt";
				fstream f("fiz1.txt", ios::out);
				try
				{
					if (!f.is_open()) {
						throw "Тест не может быть записан!";
					}
					else {
						push_fiz1(fiz1);
						int score = 0, count_win = 0, procent_win = 0;
						char var;
						cout << "Механика(1 вопрос = 3 балла):" << endl;
						cout << fiz1[0] << endl;
						cin >> var;
						f << var << '\n';
						if (var == 'в') {
							count_win++;
							score += 3;
						}
						system("cls");
						cout << fiz1[1] << endl;
						cin >> var;
						f << var << '\n';
						if (var == 'г') {
							count_win++;
							score += 3;
						}
						system("cls");
						cout << fiz1[2] << endl;
						cin >> var;
						f << var << '\n';
						if (var == 'в') {
							count_win++;
							score += 3;
						}
						system("cls");
						cout << fiz1[3] << endl;
						cin >> var;
						f << var << '\n';
						if (var == 'г') {
							count_win++;
							score += 3;
						}
						system("cls");
						procent_win = (double)count_win / 4 * 100;
						cout << "Результат теста: " << endl;
						cout << "Количество правильных ответов: " << count_win << endl;
						f << count_win << '\n';
						cout << "Процент правильных ответов: " << procent_win << '%' << endl;
						f << procent_win << '\n';
						cout << "Оценка: " << score << " балов" << endl;
						f << score << '\n';
						f.close();
						system("pause");
						system("cls");
					}
				}
				catch (const char* str)
				{
					cerr << str << endl;
				}
			}
				  break;
			case 0: {}break;
			default:cerr << "Выберите существующий тест!" << endl;
				break;
			}
		} while (test != 0);
	}
};

void MenuAdm(Admin A) {
	int menuAdm;
	do
	{
		std::cout << "Меню:\n1 --- Смена логина или пароля\n2 --- Показать зашифромванные данные об администраторе\n0 --- Выход\n";
		std::cout.width(15);
		std::cout << "";
		std::cin >> menuAdm;
		switch (menuAdm)
		{
		case 1: {
			A.ReLogin();
			Sleep(2000);
			system("cls");
		}
			  break;
		case 2: {
			A.ShowData();
			system("pause");
			system("cls");
		}
			  break;
		case 0: {}break;
		default:std::cout << "Выберите корректный вариант!" << std::endl;
			break;
		}
	} while (menuAdm != 0);
}
void MenuGue(Guest A, string index) {
	int menuGue;
	do
	{
		std::cout << "Меню:\n1 --- Показать данные об пользователе\n2 --- Тесты\n0 --- Выход\n";
		std::cout.width(15);
		std::cout << "";
		std::cin >> menuGue;
		switch (menuGue)
		{
		case 1: {
			A.ShowData();
			system("pause");
			system("cls");
		}
			  break;
		case 2: {
			A.Test(index);
		}
			  break;
		case 0: {}break;
		default:std::cout << "Выберите корректный вариант!" << std::endl;
			break;
		}
	} while (menuGue != 0);
}
void Menu_main() {
	cout.width(10);
	cout.fill(' ');
	cout << "" << "Выберите пользователя:" << std::endl;
	cout << "  1 --- Администратор       2 --- Гость" << std::endl;
	cout.width(15);
	cout << "" << "0 --- Выход" << std::endl;
	cout.width(18);
	cout << "-> ";
}
