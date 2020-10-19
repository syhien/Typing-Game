#include <iostream>
#include "admin.h"

void Admin::NewAdminSetPassword()
{
	std::cout << "新管理员，请输入你的密码，密码中请不要包含空格，空格后的字符会被丢弃\n";
	std::cin >> password_;
	std::cout << "管理员密码将设为：" << password_ << std::endl << "按任意键继续";
	_getch();
	system("cls");
}

void Admin::AdminSetPassword(std::string password)
{
	password_ = password;
}

void Admin::AdminChangePassword()
{
	std::cout << "请输入新的管理员密码:\n";
	std::cin >> password_;
}

bool Admin::CheckPassword(std::string password)
{
	return password == password_;
}