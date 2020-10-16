#pragma once
#include <vector>
#include <string>
struct User_Info
{
	int Id_;
	std::string Name_;
	std::string Password_;
};
class User
{
public:
	std::string GetName(int Id);
	void AddUser(User_Info new_user);
private:
	std::vector <User_Info> all_user;
};
