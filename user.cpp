#include "user.h"
std::vector <User> user;

std::string User::GetName(int Id)
{
	for (auto i : user)
		if (i.Id_ == Id)
			return i.Name_;
	return "";
}