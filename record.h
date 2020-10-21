#pragma once
#include <string>
#include <vector>
#include <time.h>

struct Record
{
	tm time;
	long long used_time;
	int text_id;
	int user_id;
	int right_percent;
};
