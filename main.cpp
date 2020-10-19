//main.cpp实现对游戏全局的控制

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

const string ask_for_check = "（按Y确认，按N或其他按键取消）\n";
const string kick_to_continue = "按任意按键继续\n";

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
	if (!fin)//无配置，新初始化游戏
	{
		admin.NewAdminSetPassword();
	}
	else//有配置，从配置初始化游戏
	{
		//读管理员
		string admin_password;
		fin >> admin_password;
		admin.AdminSetPassword(admin_password);
		//读用户
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
		//读文本
		int num_of_text;
		fin >> num_of_text;
		for (int i = 0; i < num_of_text; i++)
		{
			int text_id;
			int text_level;
			fin >> text_id;
			if (text_id % 2)//读文章
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
			else//读单词
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
		//读记录
		int num_of_records;
		fin >> num_of_records;
		for (int i = 0; i < num_of_records; i++)
		{
			Record new_record;
			fin >> new_record.time.tm_sec >> new_record.time.tm_min >> new_record.time.tm_hour >> new_record.time.tm_mday >> new_record.time.tm_mon >> new_record.time.tm_year >> new_record.time.tm_wday >> new_record.time.tm_yday >> new_record.time.tm_isdst >> new_record.used_time >> new_record.text_id >> new_record.user_id;
			record.push_back(new_record);
		}
	}

	cout << "打字游戏Typing Game初始化完成\n\n";

	int login_user_id;
	bool already_login = 0;
	while (1 and !already_login)
	{
		cout << "按下相应按键执行操作:\n1.用户登录\n2.用户注册\nESC.退出程序\n";
		bool game_exit = 0;
		if (_kbhit)
		{
			char ch = _getch();
			User_Info new_user;//如果注册的话
			string login_user_name;
			string login_user_password;
			switch (ch)
			{
			case '1'://log in
				cout << "请输入你的昵称：\n";
				cin >> login_user_name;
				fflush(stdin);
				login_user_id = user.GetId(login_user_name);
				if (login_user_id == -1)//不存在
				{
					cout << "看起来系统并不存在昵称为" << login_user_name << "的用户\n需要注册一个昵称为" << login_user_name << "的用户吗？\n" << ask_for_check;
					if (_getch() == 89)
					{
						new_user.id_ = rand() % 100000;
						new_user.name_ = login_user_name;
						cout << "输入你的用户密码，请不要使用空格:\n";
						cin >> new_user.password_;
						user.AddUser(new_user);
						cout << "注册成功，请重新登录\n" << kick_to_continue;
						_getch();
					}
				}//存在
				else {
					cout << "请输入密码:\n";
					cin >> login_user_password;
					if (user.CheckPassword(login_user_id, login_user_password))
					{
						cout << "登录成功\n" << kick_to_continue;
						already_login = 1;
						_getch();
					}
					else
					{
						login_user_id = -1;
						cout << "登录失败\n" << kick_to_continue;
						_getch();
					}
				}
				break;
			case '2'://sign in
				cout << "请输入你的昵称：\n";
				cin >> login_user_name;
				new_user.id_ = rand() % 100000;
				new_user.name_ = login_user_name;
				cout << "输入你的用户密码，请不要使用空格:\n";
				cin >> new_user.password_;
				user.AddUser(new_user);
				cout << "注册成功，请重新登录\n";
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