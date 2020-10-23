#include "user.h"
#include <iostream>
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

void User::PrintAllUser()
{
	for (auto i : all_user_)
		std::cout << "id:" << i.id_ << ", name:" << i.name_ << ", password:" << i.password_ << ", privacy:" << (i.privacy_ ? "Ë½ÃÜ" : "Éç½»") << std::endl;
}

User_Info User::PopUser(int id)
{
	for(auto i=all_user_.begin();i!=all_user_.end();i++)
		if (i->id_ == id)
		{
			User_Info user_found;
			user_found.id_ = id;
			user_found.name_ = i->name_;
			user_found.password_ = i->password_;
			user_found.privacy_ = i->privacy_;
			all_user_.erase(i);
			return user_found;
		}
	return { -1,"","",1 };
}

void User::PrintUser(int id)
{
	for (auto i : all_user_)
		if (i.id_ == id)
		{
			std::cout << "user id:" << i.id_ << "	user name:" << i.name_ << std::endl;
			return;
		}
}

bool User::GetPrivacy(int id)
{
	for (auto i : all_user_)
		if (i.id_ == id)
			return i.privacy_;
	return 1;
}

void User::ChangePrivacySetting(int id)
{
	for (auto &i : all_user_)
		if (i.id_ == id)
			i.privacy_ = !i.privacy_;
}

void User::AddFollow(int user_follow, int user_followed)
{
	follow_list_.push_back(std::make_pair(user_follow, user_followed));
}