#include <iostream>
#include "admin.h"

void Admin::NewAdminSetPassword()
{
	std::cout << "�¹���Ա��������������룬�������벻Ҫ�����ո񣬿ո����ַ��ᱻ����\n";
	std::cin >> Password_;
	std::cin.get();
	std::cout << "����Ա���뽫��Ϊ��" << Password_ << std::endl << "�����������";
	std::cin.get();
}

void Admin::AdminSetPassword(std::string password)
{
	Password_ = password;
}

void Admin::AdminChangePassword()
{
	std::cout << "�������µĹ���Ա����:\n";
	std::cin >> Password_;
}