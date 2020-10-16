#pragma once
#include <vector>
#include <string>
class User
{
public:
	std::string GetName(int Id);
private:
	int Id_;
	std::string Name_;
	std::string Password_;
};
