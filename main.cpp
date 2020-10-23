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
#include <algorithm>
using namespace std;

const string ask_for_check = "（按y确认，按其他按键取消）\n";
const string kick_to_continue = "按任意按键继续\n";

Admin admin;
User user;
vector <Text> text;
vector <Words> word;
vector <Record> record;
bool easy = 1;
bool normal = 1;
bool hard = 1;
bool expert = 1;

void AdminControl()
{
	bool admin_logout = 0;
	while (!admin_logout)
	{
		system("cls");
		cout << "管理员操作:\n1.查看所有用户\n2.新增用户\n3.修改用户信息\n4.删除用户\n5.修改管理员密码\n6.查看所有文本\n7.修改文本\n8.新增文本\n9.删除文本\n10.查看难度开放情况\n11.修改难度开放情况\n12.查看所有游戏记录\n13.删除指定游戏记录\n0.退出\n";
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
		int record_count;
		int record_to_delete;
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
			while (user.GetName(new_user.id_) != "")
				new_user.id_ = rand() % 100000;
			new_user.privacy_ = 1;
			cin >> new_user.name_ >> new_user.password_;
			user.AddUser(new_user);
			cout << "添加完成\n" << kick_to_continue;
			_getch();
			break;
		case 3:
			user.PrintAllUser();
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
			cout << "是否修改隐私设置？该用户原隐私状态为:" << (edit_user.privacy_ ? "私密" : "社交") << endl << ask_for_check;
			if (_getch() == 'y')
			{
				cout << "已将其隐私设置取反\n";
				edit_user.privacy_ = !edit_user.privacy_;
			}
			user.AddUser(edit_user);
			cout << "修改完成\n" << kick_to_continue;
			_getch();
			break;
		case 4:
			user.PrintAllUser();
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
			cout << "输出所有文本，多句子文本以“~~END~~”结尾\n";
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
				cout << "输入新文本的难度(一个两位正整数），十位数（1，2，3，4）代表大致难度（easy,normal,hard,expert)，个位数代表大致难度下细分的难度\n";
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
		case 10:
			cout << "Easy:" << (easy ? "开放" : "关闭") << endl;
			cout << "Normal:" << (normal ? "开放" : "关闭") << endl;
			cout << "Hard:" << (hard ? "开放" : "关闭") << endl;
			cout << "Expert:" << (expert ? "开放" : "关闭") << endl;
			cout << kick_to_continue, _getch();
			break;
		case 11:
			cout << "Easy:" << (easy ? "开放" : "关闭") << "是否修改，按y确认修改，按其他按键不进行修改\n";
			if (_getch() == 'y')
				easy = !easy, cout << "修改成功\n";
			cout << "Normal:" << (normal ? "开放" : "关闭") << "是否修改，按y确认修改，按其他按键不进行修改\n";
			if (_getch() == 'y')
				normal = !normal, cout << "修改成功\n";
			cout << "Hard:" << (hard ? "开放" : "关闭") << "是否修改，按y确认修改，按其他按键不进行修改\n";
			if (_getch() == 'y')
				hard = !hard, cout << "修改成功\n";
			cout << "Expert:" << (expert ? "开放" : "关闭") << "是否修改，按y确认修改，按其他按键不进行修改\n";
			if (_getch() == 'y')
				expert = !expert, cout << "修改成功\n";
			cout << kick_to_continue, _getch();
			break;
		case 12:
			for (auto i : record)
			{
				if (i.text_id % 2)
				{
					for (auto j : text)
						if (j.GetId() == i.text_id)
							j.Print();
				}
				else
				{
					for (auto j : word)
						if (j.GetId() == i.text_id)
							j.Print();
				}
				user.PrintUser(i.user_id);
				cout << "UTC +0 游戏时间：" << asctime(&i.time);
				cout << "用时：" << i.used_time << "秒	正确率：" << i.right_percent << "%\n\n";
			}
			cout << kick_to_continue, _getch();
			break;
		case 13:
			record_count = 0;
			for (auto i : record)
			{
				cout << "<" << record_count++ << ">\n";
				if (i.text_id % 2)
				{
					for (auto j : text)
						if (j.GetId() == i.text_id)
							j.Print();
				}
				else
				{
					for (auto j : word)
						if (j.GetId() == i.text_id)
							j.Print();
				}
				user.PrintUser(i.user_id);
				cout << "UTC +0 游戏时间：" << asctime(&i.time);
				cout << "用时：" << i.used_time << "秒	正确率：" << i.right_percent << "%\n\n";
			}
			record_count = 0;
			cout << "请输入想要删除的记录的某条记录尖括号内的数字，不进行删除请输入-1\n";
			cin >> record_to_delete;
			if (record_to_delete == -1)
			{
				cout << "删除失败\n" << kick_to_continue, _getch();
				break;
			}
			record.erase(record.begin() + record_to_delete);
			cout << "删除成功\n" << kick_to_continue, _getch();
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
			int user_privacy;
			fin >> user_id >> user_name >> user_password >> user_privacy;
			user.AddUser({ user_id,user_name,user_password,(bool)user_privacy });
		}
		int num_of_follow;
		fin >> num_of_follow;
		for (int i = 0; i < num_of_follow; i++)
		{
			int user_follow;
			int user_followed;
			fin >> user_follow >> user_followed;
			user.AddFollow(user_follow, user_followed);
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
			fin >> new_record.time.tm_sec >> new_record.time.tm_min >> new_record.time.tm_hour >> new_record.time.tm_mday >> new_record.time.tm_mon >> new_record.time.tm_year >> new_record.time.tm_wday >> new_record.time.tm_yday >> new_record.time.tm_isdst >> new_record.used_time >> new_record.text_id >> new_record.user_id >> new_record.right_percent;
			record.push_back(new_record);
		}
	}
	fin.close();

	cout << "打字游戏Typing Game初始化完成\n\n";

	int login_user_id;
	bool already_login = 0;
	bool game_exit = 0;
	while (!already_login)
	{
		cout << "按下相应按键执行操作:\n1.用户登录\n2.用户注册\nESC.退出程序\n";
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
						while (user.GetName(new_user.id_) != "")
							new_user.id_ = rand() % 100000;
						new_user.name_ = login_user_name;
						new_user.privacy_ = 1;
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
				while (user.GetName(new_user.id_) != "")
					new_user.id_ = rand() % 100000;
				new_user.name_ = login_user_name;
				new_user.privacy_ = 1;
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

	while (!game_exit)
	{
		system("cls");
		fflush(stdin);
		cout << "当前登录用户：" << user.GetName(login_user_id) << endl;
		cout << "希望做些什么呢？按下操作前对应的键盘按键吧\n1.开始新游戏\n2.进入社交系统\n3.查看自己的游戏记录\nESC.退出游戏\n";
		char ch;
		ch = _getch();
		char level_choose = ' ';
		char friend_system_choose = ' ';
		vector <int> text_able_to_choose;
		int text_choose;
		Record new_record;
		switch (ch)
		{
		case '1':
			cout << "要开始新游戏啦\n游戏的要求是尽可能快地、尽可能正确地键入给定的英文单词、英文句子，用时和正确率都是评判游戏的标准\n准备好了吗\n" << kick_to_continue, _getch();
			system("cls");
			cout << "先选择一下想要试一试的难度吧\nEasy最为简单，只有单词的输入，输入过程中可以退格修改，每个单词输入完成都需要回车\nNormal较为简单，只有单词的输入，但是输入过程中按下按键就不能修改，每个单词输入完之后不需要手动回车\nHard小有难度，只有句子的输入，输入过程中可以退格修改，每个句子输入完成都需要回车\nExpert最具挑战性，只有句子的输入，但是输入过程中按下按键就不能修改，每个句子输入完之后不需要手动回车\n温馨提示：游戏过程中大小写不严格，但是按下大小写锁定键可能会被判为失误哦\n";
			cout << "按下数字按键选择难度：\n1.Easy\n2.Normal\n3.Hard\n4.Expert\n";
			while (level_choose == ' ')
			{
				level_choose = _getch();
				switch (level_choose)
				{
				case '1':
					system("cls");
					text_able_to_choose.clear();
					for (auto i : word)
						if (i.GetLevel() / 10 == 1)
							text_able_to_choose.push_back(i.GetId());
					if (text_able_to_choose.size() == 0)
					{
						cout << "该难度目前没有对你开放的文本呢\n试试别的难度？\n";
						level_choose = ' ';
						break;
					}
					for (auto i : word)
						if (i.GetLevel() / 10 == 1)
							i.Print();
					cout << "打算挑战哪个文本呢？输入想要挑战的文本的id并回车吧\n";
					cin >> text_choose;
					if (find(text_able_to_choose.begin(), text_able_to_choose.end(), text_choose) == text_able_to_choose.end())
					{
						cout << "好像没有id为" << text_choose << "的可选文本呢\n试试别的难度？\n";
						level_choose = ' ';
						break;
					}
					for (auto i : word)
						if (i.GetId() == text_choose)
							new_record = NewEasyGame(login_user_id, i);
					record.push_back(new_record);
					cout << kick_to_continue, _getch();
					break;
				case '2':
					system("cls");
					text_able_to_choose.clear();
					for (auto i : word)
						if (i.GetLevel() / 10 == 2)
							text_able_to_choose.push_back(i.GetId());
					if (text_able_to_choose.size() == 0)
					{
						cout << "该难度目前没有对你开放的文本呢\n试试别的难度？\n";
						level_choose = ' ';
						break;
					}
					for (auto i : word)
						if (i.GetLevel() / 10 == 2)
							i.Print();
					cout << "打算挑战哪个文本呢？输入想要挑战的文本的id并回车吧\n";
					cin >> text_choose;
					if (find(text_able_to_choose.begin(), text_able_to_choose.end(), text_choose) == text_able_to_choose.end())
					{
						cout << "好像没有id为" << text_choose << "的可选文本呢\n试试别的难度？\n";
						level_choose = ' ';
						break;
					}
					for (auto i : word)
						if (i.GetId() == text_choose)
							new_record = NewNormalGame(login_user_id, i);
					record.push_back(new_record);
					cout << kick_to_continue, _getch();
					break;
				case '3':
					system("cls");
					text_able_to_choose.clear();
					for (auto i : text)
						if (i.GetLevel() / 10 == 3)
							text_able_to_choose.push_back(i.GetId());
					if (text_able_to_choose.size() == 0)
					{
						cout << "该难度目前没有对你开放的文本呢\n试试别的难度？\n";
						level_choose = ' ';
						break;
					}
					for (auto i : text)
						if (i.GetLevel() / 10 == 3)
							i.Print();
					cout << "打算挑战哪个文本呢？输入想要挑战的文本的id并回车吧\n";
					cin >> text_choose;
					if (find(text_able_to_choose.begin(), text_able_to_choose.end(), text_choose) == text_able_to_choose.end())
					{
						cout << "好像没有id为" << text_choose << "的可选文本呢\n试试别的难度？\n";
						level_choose = ' ';
						break;
					}
					for (auto i : text)
						if (i.GetId() == text_choose)
							new_record = NewHardGame(login_user_id, i);
					record.push_back(new_record);
					cout << kick_to_continue, _getch();
					break;
				case '4':
					system("cls");
					text_able_to_choose.clear();
					for (auto i : text)
						if (i.GetLevel() / 10 == 4)
							text_able_to_choose.push_back(i.GetId());
					if (text_able_to_choose.size() == 0)
					{
						cout << "该难度目前没有对你开放的文本呢\n试试别的难度？\n";
						level_choose = ' ';
						break;
					}
					for (auto i : text)
						if (i.GetLevel() / 10 == 4)
							i.Print();
					cout << "打算挑战哪个文本呢？输入想要挑战的文本的id并回车吧\n";
					cin >> text_choose;
					if (find(text_able_to_choose.begin(), text_able_to_choose.end(), text_choose) == text_able_to_choose.end())
					{
						cout << "好像没有id为" << text_choose << "的可选文本呢\n试试别的难度？\n";
						level_choose = ' ';
						break;
					}
					for (auto i : text)
						if (i.GetId() == text_choose)
							new_record = NewExpertGame(login_user_id, i);
					record.push_back(new_record);
					cout << kick_to_continue, _getch();
					break;
				default:
					cout << "无法理解的输入呢\n按下数字按键选择难度：\n1.Easy\n2.Normal\n3.Hard\n4.Expert\n";
					level_choose = ' ';
					break;
				}
			}
			break;
		case '2':
			system("cls");
			cout << "欢迎进入本游特色的社交系统，在这里和其他玩家一起贴贴吧\n";
			if (user.GetPrivacy(login_user_id))
			{
				cout << "你当前的隐私设置为私密，这意味着你不能与他人社交、他人也无法在社交列表找到你，你希望修改隐私设置为社交吗？\n" << ask_for_check;
				if (_getch() == 'y')
				{
					user.ChangePrivacySetting(login_user_id);
					cout << "隐私设置修改完成\n请重新进入社交系统\n" << kick_to_continue, _getch();
					break;
				}
				else
				{
					cout << "隐私设置未修改\n" << kick_to_continue, _getch();
					break;
				}
			}
			break;
		case '3':
			cout << endl;
			for (auto i : record)
				if (i.user_id == login_user_id)
				{
					if (i.text_id % 2)
					{
						for (auto j : text)
							if (j.GetId() == i.text_id)
								j.Print();
					}
					else
					{
						for (auto j : word)
							if (j.GetId() == i.text_id)
								j.Print();
					}
					cout << "UTC +0 游戏时间：" << asctime(&i.time);
					cout << "用时：" << i.used_time << "秒	正确率：" << i.right_percent << "%\n\n";
				}
			cout << kick_to_continue, _getch();
			break;
		case 27://ESC
			game_exit = 1;
			break;
		default:
			break;
		}
	}

	ofstream fout;
	fout.open("game.data", ios::out | ios::trunc);
	fout << admin.password_ << endl;
	fout << user.all_user_.size() << endl;
	for (auto i : user.all_user_)
		fout << i.id_ << " " << i.name_ << " " << i.password_ << " " << i.privacy_ << endl;
	fout << user.follow_list_.size() << endl;
	for (auto i : user.follow_list_)
		fout << i.first << " " << i.second << endl;
	fout << text.size() + word.size() << endl;
	for (auto i : text)
	{
		fout << i.id_ << " " << i.sentences_.size() << " " << i.level_ << endl;
		for (auto j : i.sentences_)
			fout << j << endl;
	}
	for (auto i : word)
	{
		fout << i.id_ << " " << i.words_.size() << " " << i.level_ << endl;
		for (auto j : i.words_)
			fout << j << " ";
		fout << endl;
	}
	fout << record.size() << endl;
	for (auto i : record)
		fout << i.time.tm_sec << " " << i.time.tm_min << " " << i.time.tm_hour << " " << i.time.tm_mday << " " << i.time.tm_mon << " " << i.time.tm_year << " " << i.time.tm_wday << " " << i.time.tm_yday << " " << i.time.tm_isdst << " " << i.used_time << " " << i.text_id << " " << i.user_id << " " << i.right_percent << endl;
	fout.close();

	cout << "\n给DEBUG的自己小小鼓励\n";//DEBUG

	return 0;
}