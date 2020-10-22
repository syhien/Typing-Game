#include "game.h"

Record NewEasyGame(int user_id, class Words word)//�������
{
	system("cls");
	Record record;
	cout << "����Ϊ��˵����Ϸ����\n1.ֻ����ֵ��ʣ�����Ҫ�����Сд\n2.�����ÿ�����ʺ���Ҫ�س�\n3.�ڻس�֮ǰ���ֵĴ��󶼿����˸���������\n���ϣ����Ͱ�\n";
	cout << "�����������ʼ��Ϸ\n", _getch();
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
	cout << "������ʱ" << record.used_time << "��\n";
	cout << "�ʾ���ʱ" << (double)record.used_time / word.words_.size() << "��\n";
	cout << "������ȷ��Ϊ" << record.right_percent << "%\n";
	return record;
}

Record NewNormalGame(int user_id, class Words word)//���������
{
	system("cls");
	Record record;
	cout << "����Ϊ��˵����Ϸ����\n1.ֻ����ֵ��ʣ�����Ҫ�����Сд\n2.�����ÿ�����ʺ���Ҫ�س�\n3.������ĸ������������ж�����\n���ϣ����Ͱ�\n";
	cout << "�����������ʼ��Ϸ\n", _getch();
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
	cout << "������ʱ" << record.used_time << "��\n";
	cout << "�ʾ���ʱ" << (double)record.used_time / word.words_.size() << "��\n";
	cout << "������ȷ��Ϊ" << record.right_percent << "%\n";
	return record;
}

Record NewHardGame(int user_id, class Text text)//�������
{
	system("cls");
	Record record;
	cout << "����Ϊ��˵����Ϸ����\n1.ֻ����־��ӣ�����Ҫ�����Сд\n2.�����ÿ�����Ӻ���Ҫ�س�\n3.�ڻس�֮ǰ���ֵĴ��󶼿����˸���������\n4.����������Ϳո��Ƿ���ȷ���룬��ñ������뷨����Ӣ������״̬\n���ϣ����Ͱ�\n";
	cout << "�����������ʼ��Ϸ\n", _getch();
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
	cout << "������ʱ" << record.used_time << "��\n";
	cout << "�����ʱ" << (double)record.used_time / text.sentences_.size() << "��\n";
	cout << "������ȷ��Ϊ" << record.right_percent << "%\n";
	return record;
}

Record NewExpertGame(int user_id, class Text text)//���������
{
	system("cls");
	Record record;
	cout << "����Ϊ��˵����Ϸ����\n1.ֻ����־��ӣ�����Ҫ�����Сд\n2.�����ÿ�����Ӻ���Ҫ�س�\n3.������ĸ����㡢�ո񰴼���������ж�����\n4.�ո�ͱ��Ҳ�������Ҫ����\n5.��ʹ�����������ҲҪ���ֺý��࣬��֤������ַ�һһ��Ӧ\n���ϣ����Ͱ�\n";
	cout << "�����������ʼ��Ϸ\n", _getch();
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
	cout << "������ʱ" << record.used_time << "��\n";
	cout << "�����ʱ" << (double)record.used_time / text.sentences_.size() << "��\n";
	cout << "������ȷ��Ϊ" << record.right_percent << "%\n";
	return record;
}