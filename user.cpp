#include "user.h"
std::vector <User> user;

void User::AddUser(User_Info new_user)
{
	all_user.push_back(new_user);
}

std::string User::GetName(int Id)
{
	for (auto i : all_user)
		if (i.Id_ == Id)
			return i.Name_;
	return "";
}