#include "game.h"

Record NewEasyGame(int user_id, class Words word)//允许纠错
{
	system("cls");
	Record record;
	cout << "下面为你说明游戏规则\n1.只会出现单词\n2.输入的每个单词后都需要回车\n3.在回车之前发现的错误都可以退格重新输入\n以上，加油吧\n";
	cout << "按下任意键开始游戏\n", _getch();
	string input_word;
	int right_input = 0;
	time_t game_begin = time(0);
	for (auto i : word.words_)
	{
		cout << i << endl;
		cin >> input_word;
		if (input_word.length() != i.length())
			continue;
		bool str_cmp = 1;
		for (int j = 0; j < i.length() and str_cmp; j++)
			if (abs(i[j] - input_word[j]) != abs('A' - 'a') and i[j] != input_word[j])
				str_cmp = 0;
		if (str_cmp)
			right_input++;
	}
	time_t game_end = time(0);
	tm* tm_game_end = gmtime(&game_end);
	record.time = *tm_game_end;
	record.used_time = game_end - game_begin;
	record.text_id = word.GetId();
	record.user_id = user_id;
	record.right_percent = (int)((double)right_input / word.words_.size() * 100);
	cout << "本次用时" << record.used_time << "秒\n";
	cout << "词均用时" << (double)record.used_time / word.words_.size() << "秒\n";
	cout << "本次正确率为" << record.right_percent << "%\n";
	return record;
}
/*
Record NewNormalGame(int user_id, class Words)//不允许纠错
{
}

Record NewHardGame(int user_id, class Text)//允许纠错
{
}

Record NewExpertGame(int user_id, class Text)//不允许纠错
{
}*/