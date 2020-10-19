//main.cppʵ�ֶ���Ϸȫ�ֵĿ���

#include "game.h"
#include "admin.h"
#include "user.h"
#include "text.h"
#include "record.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;

const string ask_for_check = "����Yȷ�ϣ���N����������ȡ����\n";
const string kick_to_continue = "�����ⰴ������\n";

int main()
{
	system("cls");
	srand(time(0));
	Admin admin;
	User user;
	vector <Text> text;
	vector <Words> word;
	vector <Record> record;
	ifstream fin("game.data");
	if (!fin)//�����ã��³�ʼ����Ϸ
	{
		admin.NewAdminSetPassword();
	}
	else//�����ã������ó�ʼ����Ϸ
	{
		//������Ա
		string admin_password;
		fin >> admin_password;
		admin.AdminSetPassword(admin_password);
		//���û�
		int num_of_user;
		fin >> num_of_user;
		for (int i = 0; i < num_of_user; i++)
		{
			int user_id;
			string user_name;
			string user_password;
			fin >> user_id >> user_name >> user_password;
			user.AddUser({ user_id,user_name,user_password });
		}
		//���ı�
		int num_of_text;
		fin >> num_of_text;
		for (int i = 0; i < num_of_text; i++)
		{
			int text_id;
			int text_level;
			fin >> text_id;
			if (text_id % 2)//������
			{
				int num_of_sentences;
				Text new_text;
				fin >> num_of_sentences;
				fin >> text_level;
				fin.get();
				new_text.SetId(text_id);
				new_text.SetLevel(text_level);
				for (int j = 0; j < num_of_sentences; j++)
				{
					string sentence;
					getline(fin, sentence);
					new_text.AddSentence(sentence);
				}
				text.push_back(new_text);
			}
			else//������
			{
				int num_of_words;
				fin >> num_of_words >> text_level;
				Words new_word;
				new_word.SetId(text_id);
				new_word.SetLevel(text_level);
				for (int j = 0; j < num_of_words; j++)
				{
					string tmp_word;
					fin >> tmp_word;
					new_word.AddWord(tmp_word);
				}
				word.push_back(new_word);
			}
		}
		//����¼
		int num_of_records;
		fin >> num_of_records;
		for (int i = 0; i < num_of_records; i++)
		{
			Record new_record;
			fin >> new_record.time.tm_sec >> new_record.time.tm_min >> new_record.time.tm_hour >> new_record.time.tm_mday >> new_record.time.tm_mon >> new_record.time.tm_year >> new_record.time.tm_wday >> new_record.time.tm_yday >> new_record.time.tm_isdst >> new_record.used_time >> new_record.text_id >> new_record.user_id;
			record.push_back(new_record);
		}
	}

	cout << "������ϷTyping Game��ʼ�����\n\n";

	int login_user_id;
	bool already_login = 0;
	while (1 and !already_login)
	{
		cout << "������Ӧ����ִ�в���:\n1.�û���¼\n2.�û�ע��\nESC.�˳�����\n";
		bool game_exit = 0;
		if (_kbhit)
		{
			char ch = _getch();
			User_Info new_user;//���ע��Ļ�
			string login_user_name;
			string login_user_password;
			switch (ch)
			{
			case '1'://log in
				cout << "����������ǳƣ�\n";
				cin >> login_user_name;
				fflush(stdin);
				login_user_id = user.GetId(login_user_name);
				if (login_user_id == -1)//������
				{
					cout << "������ϵͳ���������ǳ�Ϊ" << login_user_name << "���û�\n��Ҫע��һ���ǳ�Ϊ" << login_user_name << "���û���\n" << ask_for_check;
					if (_getch() == 89)
					{
						new_user.id_ = rand() % 100000;
						new_user.name_ = login_user_name;
						cout << "��������û����룬�벻Ҫʹ�ÿո�:\n";
						cin >> new_user.password_;
						user.AddUser(new_user);
						cout << "ע��ɹ��������µ�¼\n" << kick_to_continue;
						_getch();
					}
				}//����
				else {
					cout << "����������:\n";
					cin >> login_user_password;
					if (user.CheckPassword(login_user_id, login_user_password))
					{
						cout << "��¼�ɹ�\n" << kick_to_continue;
						already_login = 1;
						_getch();
					}
					else
					{
						login_user_id = -1;
						cout << "��¼ʧ��\n" << kick_to_continue;
						_getch();
					}
				}
				break;
			case '2'://sign in
				cout << "����������ǳƣ�\n";
				cin >> login_user_name;
				new_user.id_ = rand() % 100000;
				new_user.name_ = login_user_name;
				cout << "��������û����룬�벻Ҫʹ�ÿո�:\n";
				cin >> new_user.password_;
				user.AddUser(new_user);
				cout << "ע��ɹ��������µ�¼\n";
				break;
			case 27://ESC
				game_exit = 1;
				break;
			default:
				break;
			}
		}
		if (game_exit)
			break;
		system("cls");
	}

	cout << "OKzi";

	return 0;
}