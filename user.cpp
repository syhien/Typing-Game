#include "user.h"
std::vector <User> user;

void User::AddUser(User_Info new_user)
{
	all_user_.push_back(new_user);
}

std::string User::GetName(int id)
{
	for (auto i : all_user_)
		if (i.id_ == id)
			return i.name_;
	return "";
}