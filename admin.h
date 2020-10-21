#pragma once
#include <string>
#include <conio.h>

class Admin
{
public:
	void NewAdminSetPassword();
	void AdminSetPassword(std::string password);
	void AdminChangePassword();
	bool CheckPassword(std::string password);
	friend int main();
private:
	std::string password_;
};