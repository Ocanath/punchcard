//_CRT_SERCURE_NO_WARNINGS 
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <time.h>
#include <sstream>
#include <Windows.h>
using namespace std;


int main()
{
	SYSTEMTIME st;
	GetLocalTime(&st);
	WORD m_st = st.wMinute;
	ifstream punch_card_in;
	punch_card_in.open("punch_card.txt");
	string cur_line,prev_line;
	while (1)
	{
		getline(punch_card_in, cur_line);
		cout << cur_line << endl;
		if (punch_card_in.eof() == 1)
			break;
		prev_line = cur_line;
	}
	punch_card_in.close();

	ofstream punch_card;
	punch_card.open("punch_card.txt", fstream::app);

	string am_pm = "AM";
	int hour = st.wHour;
	if (hour > 12)
	{
		hour -= 12;
		am_pm = "PM";
	}
	if (!prev_line.empty())
	{
		if (prev_line[0] == 'o')
		{
			cout << "in :";
			punch_card << "in: ";
		}
		else if (prev_line[0] == 'i')
		{
			cout << "out :";
			punch_card << "out: ";
		}
	}
	else
	{
		cout << "in :";
		punch_card << "in: ";
	}
	cout << hour << ":" << st.wMinute << ":" << st.wSecond << " " << am_pm << ", " << st.wMonth << "/" << st.wDay << "/" << st.wYear << endl;
	punch_card << hour << ":" << st.wMinute << ":" << st.wSecond << " " << am_pm << ", " << st.wMonth << "/" << st.wDay << "/" << st.wYear << endl;

	//int valid_input = 0;
	//while (!valid_input)
	//{
	//	cout << "in or out?" << endl;
	//	string in_out = "";
	//	getline(cin, in_out);
	//	if (in_out == "i" || in_out == "in")
	//	{
	//		cout << "in: ";
	//		punch_card << "in: ";
	//		valid_input = 1;
	//	}
	//	else if (in_out == "o" || in_out == "out")
	//	{
	//		cout << "out: ";
	//		punch_card << "out: ";
	//		valid_input = 1;
	//	}
	//	else
	//		cout << "invalid input" << endl;
	//	
	//	if (valid_input)
	//	{
	//		cout << hour << ":" << st.wMinute << ":" << st.wSecond << " " << am_pm << ", " << st.wMonth << "/" << st.wDay << "/" << st.wYear << endl;
	//		punch_card << hour << ":" << st.wMinute << ":" << st.wSecond << " " << am_pm << ", " << st.wMonth << "/" << st.wDay << "/" << st.wYear << endl;
	//	}
	//}
	punch_card.close();
}