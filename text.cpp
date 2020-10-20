#include "text.h"

void Words::SetId(int id)
{
	id_ = id;
}
void Words::SetLevel(int level)
{
	level_ = level;
}
void Words::AddWord(std::string word)
{
	words_.push_back(word);
}

void Text::SetId(int id)
{
	id_ = id;
}
void Text::SetLevel(int level)
{
	level_ = level;
}
void Text::AddSentence(std::string sentence)
{
	sentences_.push_back(sentence);
}

void Words::Print()
{
	std::cout << "id:" << id_ << " " << "level:" << level_ << std::endl;
	for (auto i : words_)
		std::cout << i << " ";
	std::cout << std::endl;
}

void Text::Print()
{
	std::cout << "id:" << id_ << " " << "level:" << level_ << std::endl;
	for (auto i : sentences_)
		std::cout << i << std::endl;
	std::cout << "~~\n";
}