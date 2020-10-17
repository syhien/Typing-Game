#pragma once
#include <string>

class Admin
{
public:
	void NewAdminSetPassword();
	void AdminSetPassword(std::string password);
	void AdminChangePassword();
private:
	std::string password_;
};
