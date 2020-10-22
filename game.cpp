#include "game.h"

Record NewEasyGame(int user_id, class Words word)//允许纠错
{
	system("cls");
	Record record;
	cout << "下面为你说明游戏规则\n1.只会出现单词，不需要在意大小写\n2.输入的每个单词后都需要回车\n3.在回车之前发现的错误都可以退格重新输入\n以上，加油吧\n";
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

Record NewNormalGame(int user_id, class Words word)//不允许纠错
{
	system("cls");
	Record record;
	cout << "下面为你说明游戏规则\n1.只会出现单词，不需要在意大小写\n2.输入的每个单词后不需要回车\n3.按下字母按键后会立即判断正误\n以上，加油吧\n";
	cout << "按下任意键开始游戏\n", _getch();
	int right_input = 0;
	char input_char = ' ';
	time_t game_begin = time(0);
	for (auto i : word.words_)
	{
		cout << i << endl;
		bool char_cmp = 1;
		fflush(stdin);
		for (int j = 0; j < i.length(); j++)
		{
			input_char = _getch();
			cout << input_char;
			if (abs(input_char - i[j]) != abs('A' - 'a') and input_char != i[j])
				char_cmp = 0;
		}
		cout << endl;
		if (char_cmp)
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

Record NewHardGame(int user_id, class Text text)//允许纠错
{
	system("cls");
	Record record;
	cout << "下面为你说明游戏规则\n1.只会出现句子，不需要在意大小写\n2.输入的每个句子后都需要回车\n3.在回车之前发现的错误都可以退格重新输入\n4.还请留意标点和空格是否正确输入，最好保存输入法处于英文输入状态\n以上，加油吧\n";
	cout << "按下任意键开始游戏\n", _getch();
	string input_text;
	cin.get();
	int right_input = 0;
	fflush(stdin);
	time_t game_begin = time(0);
	for (auto i : text.sentences_)
	{
		cout << i << endl;
		getline(cin, input_text);
		bool str_cmp = 1;
		for (int j = 0; j < i.length() and str_cmp; j++)
			if (abs(i[j] - input_text[j]) != abs('A' - 'a') and i[j] != input_text[j])
				str_cmp = 0;
		if (str_cmp)
			right_input++;
	}
	time_t game_end = time(0);
	tm* tm_game_end = gmtime(&game_end);
	record.time = *tm_game_end;
	record.used_time = game_end - game_begin;
	record.text_id = text.GetId();
	record.user_id = user_id;
	record.right_percent = (int)((double)right_input / text.sentences_.size() * 100);
	cout << "本次用时" << record.used_time << "秒\n";
	cout << "句均用时" << (double)record.used_time / text.sentences_.size() << "秒\n";
	cout << "本次正确率为" << record.right_percent << "%\n";
	return record;
}

Record NewExpertGame(int user_id, class Text text)//不允许纠错
{
	system("cls");
	Record record;
	cout << "下面为你说明游戏规则\n1.只会出现句子，不需要在意大小写\n2.输入的每个句子后不需要回车\n3.按下字母、标点、空格按键后会立即判断正误\n4.空格和标点也在输入的要求内\n5.即使发现输入错误，也要保持好节奏，保证后面的字符一一对应\n以上，加油吧\n";
	cout << "按下任意键开始游戏\n", _getch();
	int right_input = 0;
	char input_char = ' ';
	time_t game_begin = time(0);
	for (auto i : text.sentences_)
	{
		cout << i << endl;
		bool char_cmp = 1;
		fflush(stdin);
		for (int j = 0; j < i.length(); j++)
		{
			input_char = _getch();
			cout << input_char;
			if (abs(input_char - i[j]) != abs('A' - 'a') and input_char != i[j])
				char_cmp = 0;
		}
		cout << endl;
		if (char_cmp)
			right_input++;
	}
	time_t game_end = time(0);
	tm* tm_game_end = gmtime(&game_end);
	record.time = *tm_game_end;
	record.used_time = game_end - game_begin;
	record.text_id = text.GetId();
	record.user_id = user_id;
	record.right_percent = (int)((double)right_input / text.sentences_.size() * 100);
	cout << "本次用时" << record.used_time << "秒\n";
	cout << "句均用时" << (double)record.used_time / text.sentences_.size() << "秒\n";
	cout << "本次正确率为" << record.right_percent << "%\n";
	return record;
}