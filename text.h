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
	bool Edit(string file_address = "edit_text.txt");
	friend int main();
private:
	int id_;
	int level_;
	std::vector <std::string> sentences_;
};
