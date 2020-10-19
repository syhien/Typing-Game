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

int User::GetId(std::string name)
{
	for (auto i : all_user_)
		if (i.name_ == name)
			return i.id_;
	return -1;
}

bool User::CheckPassword(int id, std::string password)
{
	for (auto i : all_user_)
		if (i.id_ == id)
			if (i.password_ == password)
				return 1;
	return 0;
}