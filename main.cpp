//main.cppʵ�ֶ���Ϸȫ�ֵĿ���

#include "game.h"
#include "admin.h"
#include "user.h"
#include "text.h"
#include "record.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
	system("cls");
	Admin admin;
	User user;
	Text text;
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
			string text_longtext;
			fin >> text_id >> text_level;
			fin.get();
			getline(fin, text_longtext);
			text.AddText({ text_id,text_level,text_longtext });
		}
		//����¼
		int num_of_records;
		fin >> num_of_records;
		for (int i = 0; i < num_of_records; i++)
		{
			Record new_record;
			fin >> new_record.time.tm_sec >> new_record.time.tm_min >> new_record.time.tm_hour >> new_record.time.tm_mday >> new_record.time.tm_mon >> new_record.time.tm_year >> new_record.time.tm_wday >> new_record.time.tm_yday >> new_record.time.tm_isdst >> new_record.UsedTime >> new_record.TextId >> new_record.UserId;
			record.push_back(new_record);
		}
	}

	cout << "����OK��\n";
	return 0;
}