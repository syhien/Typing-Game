#include <iostream>
#include "admin.h"

Admin admin;

void Admin::AdminSetPassword()
{
	std::cin >> Password_;
}

void Admin::AdminChangePassword()
{
	std::cout << "�������µĹ���Ա����:\n";
	std::cin >> Password_;
}