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
	V.push_back("1. ���� ��������� � = {a, b, d, e, f}, B = {b, c, e, g}, C = {a, d, f}. �������� ������ ���������:\na) C = ����������� � � �\n�) � = � \\ �\n�) � = � U B\n�) � = B \\ A\n");
	V.push_back("2. ����� ���� ���������� ������������?\na) �������� ������� �����\n�) ����� �����\n�) ����� ����� �����������\n");
	V.push_back("3. ��������� ����� ������:\na) ��������\n�) ���������� ��� ����������\n�) ���������� ��� ����������\n");
	V.push_back("4. ����� �������� ��� ����������� ���������� ����������?\na) �����������\n�) �����������\n�) ����������\n");
}
void push_rus1(vector<string>& V) {
	V.push_back("������� �������� ������� �������� �����:\n�) ���������������\n�) �����������������\n�) ��������������\n�) ����������� - ����������� �������.");
	V.push_back("��� ��� ���������������� �������� ������������� �����?\n�) �.�.���������\n�) �.�.�������\n�) �.�.������\n�) �.�.��������");
	V.push_back("�� ������ ����� ��������� �������� ������� ����������� ���������?\n�) �����\n�) ��������\n�) ����\n�) ����");
	V.push_back("������ ��������� ���� � ������� �����?\n�) 10\n�) 14\n�) 19\n�) 21");
}
void push_fiz1(vector<string>& V) {
	V.push_back("�����, ����� � ����� ����, ��������� � ����� ������ ���� �������� 30 �/�. ��� ���������� � ������\n�) 2 �\n�) 5 �\n�) 3 �\n�) 4 �");
	V.push_back("�����������, ��� ����� ����� ����������� � 4 ����, � ������� ������� �������. � ���� ������ ����, ����������� �� ������� ����� �� ����, ������� ��������� �� �� �����������\n�) ���������� � 2 ����\n�) ���������� � 2 ����\n�) ���������� � 4 ����\n�) ���������� � 4 ����");
	V.push_back("������� ���� �������� ������������ ������ ��������\n�) �����, ��������� �� �������� � ����������\n�) ���������� �����, ������� ������������� �����\n�) �����, ��������� �� �������� � ���������\n�) �����, ��������� �� ���� ��������� ������������ ������");
	V.push_back("�������� ���������� �������������� �������� ��, ���\n�) ���� ����� �����\n�) ���� ��������\n�) ���� ����� ������������������ ����������� ������\n�) � ������ ��� ������ ���������� ���������� �������");
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
			std::cout << "����������� ������ �������!" << std::endl;
		}
	}
	void Login() {
		std::string  login, password;
		std::ifstream in("admin.txt", std::ios_base::in);
		if (!in.is_open()) {
			std::cout << "���� �� ������!" << std::endl;
		}
		else {
			getline(in, this->elogin);
			getline(in, this->epassword);
			in.close();
		}
		while (true) {
			std::cout << "������� �����: ";
			std::cin >> login;
			std::cout << "������� ������: ";
			std::cin >> password;
			if (Dlogin(this->elogin) != login || Dlogin(this->epassword) != password) {
				std::cout << "�� ������ ����� ��� ������!" << std::endl;
			}
			else {
				std::cout << "����� ����������!" << std::endl;
				break;
			}
		}
	}
	void ReLogin() {
		std::ofstream out("admin.txt", std::ios_base::out);
		if (!out.is_open()) {
			std::cout << "������, ���� �� ����� ���� ������ ��� ������!" << std::endl;
		}
		else {
			std::string login, password;
			std::cout << "������� ����� �����: ";
			std::cin >> login;
			std::cout << "������� ����� ������: ";
			std::cin >> password;
			this->elogin = ElogiN(login);
			this->epassword = ElogiN(password);
			out << this->elogin << "\n";
			out << this->epassword << "\n";
			out.close();
			std::cout << "������  ������� ��������." << std::endl;
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
		cout << "������� ���: ";
		cin.ignore();
		getline(cin, this->FullName);
		cout << "������� �������� �����: ";
		getline(cin, this->HomeAdress);
		cout << "������� ����� ��������: ";
		getline(cin, this->PhoneNumber);
		ofstream out(path, ios_base::out);
		if (!out.is_open()) {
			cout << "���� �� ����� ���� ������!" << endl;
		}
		else {
			out << this->elogin << '\n';
			out << this->epassword << '\n';
			out << "���: " << this->FullName << '\n';
			out << "�������� �����: " << this->HomeAdress << '\n';
			out << "�������: " << this->PhoneNumber << '\n';
			out.close();
			std::cout << "����������� ������ �������!" << std::endl;
		}
	}
	void Login(string path) {
		std::string login, password;
		std::ifstream in(path, std::ios_base::in);
		if (!in.is_open()) {
			std::cout << "���� �� ������!" << std::endl;
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
			std::cout << "������� �����: ";
			std::cin >> login;
			std::cout << "������� ������: ";
			std::cin >> password;
			if (Dlogin(this->elogin) != login || Dlogin(this->epassword) != password) {
				std::cout << "�� ������ ����� ��� ������!" << std::endl;
			}
			else {
				std::cout << "����� ����������!" << std::endl;
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
			cout << "|�����|" << endl;
			cout << "1 �> ���������� ����������;" << endl;
			cout << "2 -> ������� ���� (����� ����);" << endl;
			cout << "3 �> ��������;" << endl;
			cout << "0 -> ����� �� ���� ������." << endl;
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
						throw "���� �� ����� ���� �������!";
					}
					else {
						push_math1(math1);
						int score = 0, count_win = 0, procent_win = 0;
						char var;
						cout << "���������� ����������(1 ������ = 3 �����):" << endl;
						cout << math1[0] << endl;
						cin >> var;
						f << var << '\n';
						if (var == '�') {
							count_win++;
							score += 3;
						}
						system("cls");
						cout << math1[1] << endl;
						cin >> var;
						f << var << '\n';
						if (var == '�') {
							count_win++;
							score += 3;
						}
						system("cls");
						cout << math1[2] << endl;
						cin >> var;
						f << var << '\n';
						if (var == '�') {
							count_win++;
							score += 3;
						}
						system("cls");
						cout << math1[3] << endl;
						cin >> var;
						f << var << '\n';
						if (var == '�') {
							count_win++;
							score += 3;
						}
						system("cls");
						procent_win = (double)count_win / 4 * 100;
						cout << "��������� �����: " << endl;
						cout << "���������� ���������� �������: " << count_win << endl;
						f << count_win << '\n';
						cout << "������� ���������� �������: " << procent_win << '%' << endl;
						f << procent_win << '\n';
						cout << "������: " << score << " �����" << endl;
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
						throw "���� �� ����� ���� �������!";
					}
					else {
						push_rus1(rus1);
						int score = 0, count_win = 0, procent_win = 0;
						char var;
						cout << "������� ����(1 ������ = 3 �����):" << endl;
						cout << rus1[0] << endl;
						cin >> var;
						f << var << '\n';
						if (var == '�') {
							count_win++;
							score += 3;
						}
						system("cls");
						cout << rus1[1] << endl;
						cin >> var;
						f << var << '\n';
						if (var == '�') {
							count_win++;
							score += 3;
						}
						system("cls");
						cout << rus1[2] << endl;
						cin >> var;
						f << var << '\n';
						if (var == '�') {
							count_win++;
							score += 3;
						}
						system("cls");
						cout << rus1[3] << endl;
						cin >> var;
						f << var << '\n';
						if (var == '�') {
							count_win++;
							score += 3;
						}
						system("cls");
						procent_win = (double)count_win / 4 * 100;
						cout << "��������� �����: " << endl;
						cout << "���������� ���������� �������: " << count_win << endl;
						f << count_win << '\n';
						cout << "������� ���������� �������: " << procent_win << '%' << endl;
						f << procent_win << '\n';
						cout << "������: " << score << " �����" << endl;
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
						throw "���� �� ����� ���� �������!";
					}
					else {
						push_fiz1(fiz1);
						int score = 0, count_win = 0, procent_win = 0;
						char var;
						cout << "��������(1 ������ = 3 �����):" << endl;
						cout << fiz1[0] << endl;
						cin >> var;
						f << var << '\n';
						if (var == '�') {
							count_win++;
							score += 3;
						}
						system("cls");
						cout << fiz1[1] << endl;
						cin >> var;
						f << var << '\n';
						if (var == '�') {
							count_win++;
							score += 3;
						}
						system("cls");
						cout << fiz1[2] << endl;
						cin >> var;
						f << var << '\n';
						if (var == '�') {
							count_win++;
							score += 3;
						}
						system("cls");
						cout << fiz1[3] << endl;
						cin >> var;
						f << var << '\n';
						if (var == '�') {
							count_win++;
							score += 3;
						}
						system("cls");
						procent_win = (double)count_win / 4 * 100;
						cout << "��������� �����: " << endl;
						cout << "���������� ���������� �������: " << count_win << endl;
						f << count_win << '\n';
						cout << "������� ���������� �������: " << procent_win << '%' << endl;
						f << procent_win << '\n';
						cout << "������: " << score << " �����" << endl;
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
			default:cerr << "�������� ������������ ����!" << endl;
				break;
			}
		} while (test != 0);
	}
};

void MenuAdm(Admin A) {
	int menuAdm;
	do
	{
		std::cout << "����:\n1 --- ����� ������ ��� ������\n2 --- �������� �������������� ������ �� ��������������\n0 --- �����\n";
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
		default:std::cout << "�������� ���������� �������!" << std::endl;
			break;
		}
	} while (menuAdm != 0);
}
void MenuGue(Guest A, string index) {
	int menuGue;
	do
	{
		std::cout << "����:\n1 --- �������� ������ �� ������������\n2 --- �����\n0 --- �����\n";
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
		default:std::cout << "�������� ���������� �������!" << std::endl;
			break;
		}
	} while (menuGue != 0);
}
void Menu_main() {
	cout.width(10);
	cout.fill(' ');
	cout << "" << "�������� ������������:" << std::endl;
	cout << "  1 --- �������������       2 --- �����" << std::endl;
	cout.width(15);
	cout << "" << "0 --- �����" << std::endl;
	cout.width(18);
	cout << "-> ";
}
