#include "typing_game.h"
#include <iostream>

void Admin::AdminSetPassword()
{
	std::cin >> Password_;
}

void Admin::AdminChangePassword()
{
	std::cout << "�������µĹ���Ա����:\n";
	std::cin >> Password_;
}