#pragma once
#include <string>
#include <vector>

struct GameRecord
{
	int GameNo;
	std::string Time;
	int UsedTime;
};

struct GameRecordWithUser
{
	GameRecord x;
	int UserId;
};

class User
{
public:
	std::string GetName(int Id);
	friend void GameSafe();
private:
	int Id_;
	std::string Name_;
	std::string Password_;
	std::vector <GameRecord> Record_;
};

class Admin
{
public:
	void AdminSetPassword();
	void AdminChangePassword();
	friend void GameSafe();
private:
	std::string Password_;
};

struct Text
{
	int Id;
	std::string LongText;
};

Admin admin;
std::vector <User> user;
std::vector <Text> text;