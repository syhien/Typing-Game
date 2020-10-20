#pragma once
#include <string>
#include <vector>
#include <iostream>

class Words
{
public:
	void SetId(int id);
	void SetLevel(int level);
	void AddWord(std::string word);
	void Print();
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
private:
	int id_;
	int level_;
	std::vector <std::string> sentences_;
};
