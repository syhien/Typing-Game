#pragma once
#include <string>

class Admin
{
public:
	void AdminSetPassword();
	void AdminChangePassword();
private:
	std::string Password_;
};
