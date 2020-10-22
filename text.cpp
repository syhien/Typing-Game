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
	std::cout << "~~END~~\n";
}

int Words::GetId()
{
	return id_;
}

bool Words::Edit(std::string file_address)
{
	ofstream fout(file_address);
	for (auto i : words_)
		fout << i << " ";
	fout.close();
	cout << "原文本已输出到同目录的" << file_address << "中，请自行打开该文件修改，修改完成后按任意键继续\n";
	_getch();
	ifstream fin(file_address);
	vector <string> old_words_ = words_;
	words_.clear();
	string new_word;
	while (fin >> new_word)
		words_.push_back(new_word);
	fin.close();
	cout << "请检查修改后的文本，无误按y确认，按其他按键取消更改\n";
	Print();
	if (_getch() == 'y')
		return 1;
	else
		words_ = old_words_;
	return 0;
}

int Text::GetId()
{
	return id_;
}

int Text::GetLevel()
{
	return level_;
}

bool Text::Edit(string file_address)
{
	ofstream fout(file_address);
	for (auto i : sentences_)
		fout << i << endl;
	fout.close();
	cout << "原文本已输出到同目录的" << file_address << "中，请自行打开该文件修改，修改完成后按任意键继续\n";
	_getch();
	ifstream fin(file_address);
	vector <string> old_sentences = sentences_;
	sentences_.clear();
	string new_sentence;
	while (getline(fin, new_sentence))
		sentences_.push_back(new_sentence);
	fin.close();
	cout << "请检查修改后的文本，无误按y确认，按其他按键取消更改\n";
	Print();
	if (_getch() == 'y')
		return 1;
	else
		sentences_ = old_sentences;
	return 0;
}

int Words::GetLevel()
{
	return level_;
}