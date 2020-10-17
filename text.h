#pragma once
#include <string>
#include <vector>

class Words
{
public:
	void SetId(int id);
	void SetLevel(int level);
	void AddWord(std::string word);
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
private:
	int id_;
	int level_;
	std::vector <std::string> sentences_;
};
