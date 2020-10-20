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

const string ask_for_check = "����yȷ�ϣ�����������ȡ����\n";
const string kick_to_continue = "�����ⰴ������\n";

Admin admin;
User user;
vector <Text> text;
vector <Words> word;
vector <Record> record;

void AdminControl()
{
	bool admin_logout = 0;
	while (!admin_logout)
	{
		system("cls");
		cout << "����Ա����:\n1.�鿴�����û�\n2.�����û�\n3.�޸��û���Ϣ\n4.ɾ���û�\n5.�޸Ĺ���Ա����\n6.�鿴�����ı�\n7.�޸��ı�\n8.�����ı�\n9.ɾ���ı�\n10.�鿴�Ѷȿ������\n11.�޸��Ѷȿ������\n0.�˳�\n";
		int ch;
		cin >> ch;
		User_Info new_user;
		int edit_user_id;
		User_Info edit_user;
		int edit_text_id;
		bool edit_text = 0;
		Words new_word;
		int new_text_level;
		Text new_text;
		ifstream fin;
		ofstream fout;
		string new_text_input;
		int delete_text_id;
		bool delete_text = 0;
		switch (ch)
		{
		case 1:
			user.PrintAllUser();
			cout << kick_to_continue;
			_getch();
			break;
		case 2:
			cout << "�������û��ǳƣ������ո񣩺����루�����ո񣩣��ÿո���зָ�:\n";
			new_user.id_ = rand() % 100000;
			cin >> new_user.name_ >> new_user.password_;
			user.AddUser(new_user);
			cout << "������\n" << kick_to_continue;
			_getch();
			break;
		case 3:
			cout << "������༭�µ��û���id\n";
			cin >> edit_user_id;
			edit_user = user.PopUser(edit_user_id);
			if (edit_user.id_ == -1)
			{
				cout << "ָ��id�û�������\n" << kick_to_continue;
				_getch();
				break;
			}
			cout << "�Ƿ��޸��ǳƣ����û�ԭ�ǳ�Ϊ:" << edit_user.name_ << endl << ask_for_check;
			if (_getch() == 'y')
			{
				cout << "���������ǳ�:\n";
				cin >> edit_user.name_;
			}
			cout << "�Ƿ��޸����룿���û�ԭ����Ϊ:" << edit_user.password_ << endl << ask_for_check;
			if (_getch() == 'y')
			{
				cout << "������������:\n";
				cin >> edit_user.password_;
			}
			user.AddUser(edit_user);
			cout << "�޸����\n" << kick_to_continue;
			_getch();
			break;
		case 4:
			cout << "�����ɾ���û�id\n";
			cin >> edit_user_id;
			edit_user = user.PopUser(edit_user_id);
			if (edit_user.id_ == -1)
			{
				cout << "�û������ڣ�ɾ��ʧ��\n" << kick_to_continue;
				_getch();
			}
			else
			{
				cout << "ɾ���ɹ�\n" << kick_to_continue;
				_getch();
			}
			break;
		case 5:
			admin.AdminChangePassword();
			cout << kick_to_continue;
			_getch();
			break;
		case 6:
			cout << "��������ı���������ı��ԡ�~~����β\n";
			for (auto i : word)
				i.Print();
			for (auto i : text)
				i.Print();
			cout << kick_to_continue;
			_getch();
			break;
		case 7:
			cout << "������޸��ı���id\n";
			cin >> edit_text_id;
			if (edit_text_id % 2)//�����
			{
				for (auto& i : text)
					if (i.GetId() == edit_text_id)
						edit_text = i.Edit();
				if (!edit_text)
				{
					cout << "�޸�ʧ��\n" << kick_to_continue, _getch();
					break;
				}
				cout << "�޸����\n" << kick_to_continue, _getch();
			}
			else//�����
			{
				for (auto &i : word)
					if (i.GetId() == edit_text_id)
						edit_text = i.Edit();
				if (!edit_text)
				{
					cout << "�޸�ʧ��\n" << kick_to_continue, _getch();
					break;
				}
				cout << "�޸����\n" << kick_to_continue, _getch();
			}
			break;
		case 8:
			cout << "Ĭ������������ı�����w�����൥���ı�����������������������ı�\n";
			if (_getch() == 'w')//����
			{
				new_word.SetId(rand() % 100000);
				while (new_word.GetId() % 2)
					new_word.SetId(rand() % 100000);
				cout << "�������ı����Ѷ�(һ����λ����������ʮλ����1��2��3��4����������Ѷȣ�easy,normal,hard,expert)����λ����������Ѷ���ϸ�ֵ��Ѷ�\n";
				cin >> new_text_level;
				new_word.SetLevel(new_text_level);
				fout.open("new_text.txt");
				fout.close();
				cout << "����ͬĿ¼��new_text.txt�������ı����ո�ָ�ʣ��������" << kick_to_continue, _getch();
				fin.open("new_text.txt");
				while (fin >> new_text_input)
					new_word.AddWord(new_text_input);
				fin.close();
				new_word.Print();
				word.push_back(new_word);
				cout << "�����ı����\n";
			}
			else//����
			{
				new_text.SetId(rand() % 100000);
				while (new_text.GetId() % 2 == 0)
					new_text.SetId(rand() % 100000);
				cout << "�������ı����Ѷ�(һ����λ����������ʮλ����1��2��3��4����������Ѷȣ�easy,normal,hard,expert)����λ����������Ѷ���ϸ�ֵ��Ѷ�\n";
				cin >> new_text_level;
				new_text.SetLevel(new_text_level);
				fout.open("new_text.txt");
				fout.close();
				cout << "����ͬĿ¼��new_text.txt�������ı������зָ���ӣ��������" << kick_to_continue, _getch();
				fin.open("new_text.txt");
				while (getline(fin, new_text_input))
					new_text.AddSentence(new_text_input);
				fin.close();
				new_text.Print();
				text.push_back(new_text);
				cout << "�����ı����\n";
			}
			cout << kick_to_continue, _getch();
			break;
		case 9:
			cout << "����Ҫɾ�����ı���id:\n";
			cin >> delete_text_id;
			if (delete_text_id % 2)
			{
				for (auto i = text.begin(); i != text.end() and !delete_text; i++)
					if (i->GetId() == delete_text_id)
					{
						text.erase(i);
						cout << "ɾ���ɹ�\n" << kick_to_continue, _getch();
						delete_text = 1;
						break;
					}
			}
			else
			{
				for(auto i=word.begin();i!=word.end() and !delete_text;i++)
					if (i->GetId() == delete_text_id)
					{
						word.erase(i);
						cout << "ɾ���ɹ�\n" << kick_to_continue, _getch();
						delete_text = 1;
						break;
					}
			}
			if(!delete_text)
				cout << "ɾ��ʧ��\n" << kick_to_continue, _getch();
			break;
		case 0:
			admin_logout = 1;
			break;
		default:
			break;
		}
	}
}

int main()
{
	system("cls");
	srand(time(0));
	ifstream fin("game.data");
	if (!fin)
		fin.open("game_template.data");
	if (!fin)//����������Ĭ�����ã��³�ʼ����Ϸ
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
	fin.close();

	cout << "������ϷTyping Game��ʼ�����\n\n";

	int login_user_id;
	bool already_login = 0;
	while (!already_login)
	{
		cout << "������Ӧ����ִ�в���:\n1.�û���¼\n2.�û�ע��\nESC.�˳�����\n";
		bool game_exit = 0;
		if (_kbhit)
		{
			char ch = _getch();
			User_Info new_user;//���ע��Ļ�
			string login_user_name;
			string login_user_password;
			string admin_password;
			switch (ch)
			{
			case '1'://log in
				cout << "����������ǳƣ�\n";
				cin >> login_user_name;
				if (login_user_name == "admin" or login_user_name == "Admin")
				{
					cout << "�������Ա��������֤���:\n";
					cin >> admin_password;
					if (admin.CheckPassword(admin_password))
					{
						AdminControl();
						cout << "\n�˳�����Ա���\n" << kick_to_continue;
						_getch();
						break;
					}
					else
					{
						cout << "����Ա�������\n" << kick_to_continue;
						_getch();
						break;
					}
				}
				login_user_id = user.GetId(login_user_name);
				if (login_user_id == -1)//������
				{
					cout << "������ϵͳ���������ǳ�Ϊ" << login_user_name << "���û�\n��Ҫע��һ���ǳ�Ϊ" << login_user_name << "���û���\n" << ask_for_check;
					if (_getch() == 'y')
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
				cout << "ע��ɹ��������µ�¼\n" << kick_to_continue;
				_getch();
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

	cout << "\n��DEBUG���Լ�СС����\n";

	return 0;
}