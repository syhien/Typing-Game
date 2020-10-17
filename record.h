#pragma once
#include <string>
#include <vector>
#include <time.h>

struct Record
{
	tm time;
	int used_time;
	int text_id;
	int user_id;
};
