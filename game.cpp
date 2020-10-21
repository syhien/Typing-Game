#include "game.h"

Record NewEasyGame(int user_id, class Words word)//�������
{
	system("cls");
	Record record;
	cout << "����Ϊ��˵����Ϸ����\n1.ֻ����ֵ���\n2.�����ÿ�����ʺ���Ҫ�س�\n3.�ڻس�֮ǰ���ֵĴ��󶼿����˸���������\n���ϣ����Ͱ�\n";
	cout << "�����������ʼ��Ϸ\n", _getch();
	string input_word;
	int right_input = 0;
	time_t game_begin = time(0);
	for (auto i : word.words_)
	{
		cout << i << endl;
		cin >> input_word;
		if (input_word == i)
			right_input++;
	}
	time_t game_end = time(0);
	tm* tm_game_end = gmtime(&game_end);
	record.time = *tm_game_end;
	record.used_time = game_end - game_begin;
	record.text_id = word.GetId();
	record.user_id = user_id;
	record.right_percent = (int)((double)right_input / word.words_.size() * 100);
	cout << "������ʱ" << record.used_time << "��\n";
	cout << "������ȷ��Ϊ" << record.right_percent << "%\n";
	return record;
}
/*
Record NewNormalGame(int user_id, class Words)//���������
{
}

Record NewHardGame(int user_id, class Text)//�������
{
}

Record NewExpertGame(int user_id, class Text)//���������
{
}*/