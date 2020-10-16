#pragma once
#include <string>
#include <vector>

struct Text_Info
{
	int Id;
	int level;
	std::string LongText;
};

class Text
{
public:
	void AddText(Text_Info new_text);
private:
	std::vector <Text_Info> all_text;
};
