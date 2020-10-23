#pragma once
#include <vector>
#include <string>
struct User_Info
{
	int id_;
	std::string name_;
	std::string password_;
	bool privacy_;
};
class User
{
public:
	std::string GetName(int id);
	int GetId(std::string name);//Ê§°Ü·µ»Ø-1
	void AddUser(User_Info new_user);
	bool CheckPassword(int id, std::string password);
	void PrintAllUser();//¿ØÖÆÌ¨print
	User_Info PopUser(int id);
	friend int main();
	void PrintUser(int id);
	bool GetPrivacy(int id);
	void ChangePrivacySetting(int id);
private:
	std::vector <User_Info> all_user_;
};
