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

const string ask_for_check = "（按y确认，按其他按键取消）\n";
const string kick_to_continue = "按任意按键继续\n";

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
		cout << "管理员操作:\n1.查看所有用户\n2.新增用户\n3.修改用户信息\n4.删除用户\n5.修改管理员密码\n6.查看所有文本\n7.修改文本\n8.新增文本\n9.删除文本\n10.查看难度开放情况\n11.修改难度开放情况\n0.退出\n";
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
			cout << "输入新用户昵称（不含空格）和密码（不含空格），用空格或换行分割:\n";
			new_user.id_ = rand() % 100000;
			cin >> new_user.name_ >> new_user.password_;
			user.AddUser(new_user);
			cout << "添加完成\n" << kick_to_continue;
			_getch();
			break;
		case 3:
			cout << "输入待编辑新的用户的id\n";
			cin >> edit_user_id;
			edit_user = user.PopUser(edit_user_id);
			if (edit_user.id_ == -1)
			{
				cout << "指定id用户不存在\n" << kick_to_continue;
				_getch();
				break;
			}
			cout << "是否修改昵称？该用户原昵称为:" << edit_user.name_ << endl << ask_for_check;
			if (_getch() == 'y')
			{
				cout << "输入其新昵称:\n";
				cin >> edit_user.name_;
			}
			cout << "是否修改密码？该用户原密码为:" << edit_user.password_ << endl << ask_for_check;
			if (_getch() == 'y')
			{
				cout << "输入其新密码:\n";
				cin >> edit_user.password_;
			}
			user.AddUser(edit_user);
			cout << "修改完成\n" << kick_to_continue;
			_getch();
			break;
		case 4:
			cout << "输入待删除用户id\n";
			cin >> edit_user_id;
			edit_user = user.PopUser(edit_user_id);
			if (edit_user.id_ == -1)
			{
				cout << "用户不存在，删除失败\n" << kick_to_continue;
				_getch();
			}
			else
			{
				cout << "删除成功\n" << kick_to_continue;
				_getch();
			}
			break;
		case 5:
			admin.AdminChangePassword();
			cout << kick_to_continue;
			_getch();
			break;
		case 6:
			cout << "输出所有文本，多句子文本以“~~”结尾\n";
			for (auto i : word)
				i.Print();
			for (auto i : text)
				i.Print();
			cout << kick_to_continue;
			_getch();
			break;
		case 7:
			cout << "输入待修改文本的id\n";
			cin >> edit_text_id;
			if (edit_text_id % 2)//多句子
			{
				for (auto& i : text)
					if (i.GetId() == edit_text_id)
						edit_text = i.Edit();
				if (!edit_text)
				{
					cout << "修改失败\n" << kick_to_continue, _getch();
					break;
				}
				cout << "修改完成\n" << kick_to_continue, _getch();
			}
			else//多词组
			{
				for (auto &i : word)
					if (i.GetId() == edit_text_id)
						edit_text = i.Edit();
				if (!edit_text)
				{
					cout << "修改失败\n" << kick_to_continue, _getch();
					break;
				}
				cout << "修改完成\n" << kick_to_continue, _getch();
			}
			break;
		case 8:
			cout << "默认新增多句子文本。按w新增多单词文本，按其他按键新增多句子文本\n";
			if (_getch() == 'w')//单词
			{
				new_word.SetId(rand() % 100000);
				while (new_word.GetId() % 2)
					new_word.SetId(rand() % 100000);
				cout << "输入新文本的难度(一个两位正整数），十位数（1，2，3，4）代表大致难度（easy,normal,hard,expert)，个位数代变大致难度下细分的难度\n";
				cin >> new_text_level;
				new_word.SetLevel(new_text_level);
				fout.open("new_text.txt");
				fout.close();
				cout << "请在同目录的new_text.txt输入新文本，空格分割单词，输入完成" << kick_to_continue, _getch();
				fin.open("new_text.txt");
				while (fin >> new_text_input)
					new_word.AddWord(new_text_input);
				fin.close();
				new_word.Print();
				word.push_back(new_word);
				cout << "新增文本完成\n";
			}
			else//句子
			{
				new_text.SetId(rand() % 100000);
				while (new_text.GetId() % 2 == 0)
					new_text.SetId(rand() % 100000);
				cout << "输入新文本的难度(一个两位正整数），十位数（1，2，3，4）代表大致难度（easy,normal,hard,expert)，个位数代变大致难度下细分的难度\n";
				cin >> new_text_level;
				new_text.SetLevel(new_text_level);
				fout.open("new_text.txt");
				fout.close();
				cout << "请在同目录的new_text.txt输入新文本，换行分割句子，输入完成" << kick_to_continue, _getch();
				fin.open("new_text.txt");
				while (getline(fin, new_text_input))
					new_text.AddSentence(new_text_input);
				fin.close();
				new_text.Print();
				text.push_back(new_text);
				cout << "新增文本完成\n";
			}
			cout << kick_to_continue, _getch();
			break;
		case 9:
			cout << "输入要删除的文本的id:\n";
			cin >> delete_text_id;
			if (delete_text_id % 2)
			{
				for (auto i = text.begin(); i != text.end() and !delete_text; i++)
					if (i->GetId() == delete_text_id)
					{
						text.erase(i);
						cout << "删除成功\n" << kick_to_continue, _getch();
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
						cout << "删除成功\n" << kick_to_continue, _getch();
						delete_text = 1;
						break;
					}
			}
			if(!delete_text)
				cout << "删除失败\n" << kick_to_continue, _getch();
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
	if (!fin)//无配置且无默认配置，新初始化游戏
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
	fin.close();

	cout << "打字游戏Typing Game初始化完成\n\n";

	int login_user_id;
	bool already_login = 0;
	while (!already_login)
	{
		cout << "按下相应按键执行操作:\n1.用户登录\n2.用户注册\nESC.退出程序\n";
		bool game_exit = 0;
		if (_kbhit)
		{
			char ch = _getch();
			User_Info new_user;//如果注册的话
			string login_user_name;
			string login_user_password;
			string admin_password;
			switch (ch)
			{
			case '1'://log in
				cout << "请输入你的昵称：\n";
				cin >> login_user_name;
				if (login_user_name == "admin" or login_user_name == "Admin")
				{
					cout << "输入管理员密码以验证身份:\n";
					cin >> admin_password;
					if (admin.CheckPassword(admin_password))
					{
						AdminControl();
						cout << "\n退出管理员身份\n" << kick_to_continue;
						_getch();
						break;
					}
					else
					{
						cout << "管理员密码错误\n" << kick_to_continue;
						_getch();
						break;
					}
				}
				login_user_id = user.GetId(login_user_name);
				if (login_user_id == -1)//不存在
				{
					cout << "看起来系统并不存在昵称为" << login_user_name << "的用户\n需要注册一个昵称为" << login_user_name << "的用户吗？\n" << ask_for_check;
					if (_getch() == 'y')
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
				cout << "注册成功，请重新登录\n" << kick_to_continue;
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

	cout << "\n给DEBUG的自己小小鼓励\n";

	return 0;
}