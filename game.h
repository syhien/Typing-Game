#pragma once
#include "record.h"
#include "text.h"
#include <time.h>
#include <conio.h>
#include <math.h>

Record NewEasyGame(int user_id, class Words);
Record NewNormalGame(int user_id, class Words);
Record NewHardGame(int user_id, class Text);
Record NewExpertGame(int user_id, class Text);
