#include <iostream>
#include "admin.h"

Admin admin;

void Admin::AdminSetPassword()
{
	std::cin >> Password_;
}

void Admin::AdminChangePassword()
{
	std::cout << "请输入新的管理员密码:\n";
	std::cin >> Password_;
}