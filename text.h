#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <conio.h>
#include "record.h"
#include "game.h"
using namespace std;

class Words
{
public:
	void SetId(int id);
	void SetLevel(int level);
	void AddWord(std::string word);
	void Print();
	bool Edit(std::string file_address = "edit_text.txt");
	int GetId();
	int GetLevel();
	friend int main();
	friend Record NewEasyGame(int, Words);
	friend Record NewNormalGame(int, Words);
private:
	int id_;
	int level_;
	std::vector <std::string> words_;
};

class Text
{
public:
	void SetId(int id);
	void SetLevel(int level);
	void AddSentence(std::string sentence);
	void Print();
	int GetId();
	int GetLevel();
	bool Edit(string file_address = "edit_text.txt");
	friend int main();
	friend Record NewHardGame(int user_id, class Text text);
	friend Record NewExpertGame(int user_id, class Text text);
private:
	int id_;
	int level_;
	std::vector <std::string> sentences_;
};
