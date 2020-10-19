#pragma once
#include <vector>
#include <string>
struct User_Info
{
	int id_;
	std::string name_;
	std::string password_;
};
class User
{
public:
	std::string GetName(int id);
	int GetId(std::string name);//ʧ�ܷ���-1
	void AddUser(User_Info new_user);
	bool CheckPassword(int id, std::string password);
private:
	std::vector <User_Info> all_user_;
};
