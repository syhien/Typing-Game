#include <iostream>
#include "admin.h"

void Admin::NewAdminSetPassword()
{
	std::cout << "�¹���Ա��������������룬�������벻Ҫ�����ո񣬿ո����ַ��ᱻ����\n";
	std::cin >> password_;
	std::cout << "����Ա���뽫��Ϊ��" << password_ << std::endl << "�����������";
	std::cin.get();
}

void Admin::AdminSetPassword(std::string password)
{
	password_ = password;
}

void Admin::AdminChangePassword()
{
	std::cout << "�������µĹ���Ա����:\n";
	std::cin >> password_;
}