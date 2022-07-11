#pragma once
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include <string>
#include<algorithm>
#include<ctime>



using namespace std;
struct date {
	int day;
	int month;
	int year;
};
class task
{

public:
	string title;
	string tdescription;
	date assdate;
	date deadlinedate;
	int priorityval;


	task(string t, string tdesc, int assdayy, int assmonthh, int assyearr, int enddayy, int endmonthh, int endyearr, int pv);
	task();
	void sign_up(int idd, string name);
	void login(int idd, string name);
	void reading_tasks(int idd);
	void sort_task(int idd);
	void display(int idd);
	void update(int idd);
	void reminder(int idd);
	void qoute(int idd);

};


