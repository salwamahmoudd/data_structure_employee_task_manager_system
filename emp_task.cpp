#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <sstream>
#include<vector>
#include"emp_task.h"
#include<algorithm>
#include<ctime>
#include "employee.h"
#include<time.h>
using namespace std;
employee emp[30];
bool v = false;
task::task(string t, string tdesc, int assdayy, int assmonthh, int assyearr, int enddayy, int endmonthh, int endyearr, int pv) {
	title = t;
	tdescription = tdesc;
	assdate.day = assdayy;
	assdate.month = assmonthh;
	assdate.year = assyearr;
	deadlinedate.day = enddayy;
	deadlinedate.month = endmonthh;
	deadlinedate.year = endyearr;
	priorityval = pv;

}


task::task() {
	if (v == false)
	{
		//task(string t, string tdesc, int assdayy, int assmonthh, int assyearr, int enddayy, int endmonthh, int endyearr, int pv)
		emp[0].name = "JOE";
		emp[0].id = 1;
		task t01("java_project", "black_jack_game", 1, 2, 2022, 5, 3, 2022, 10);
		emp[0].alltasks.push_back(t01);
		task t02("c++_project", "course_managemet_system", 1, 2, 2022, 5, 3, 2022, 10);
		emp[0].alltasks.push_back(t02);

		emp[1].name = "mai";
		emp[1].id = 2;
		task t1("database_project", "stackoverflow_project", 10, 2, 2022, 10, 3, 2022, 8);
		emp[1].alltasks.push_back(t1);

		emp[2].name = "salma";
		emp[2].id = 3;
		task t2("oop_project", "class_room_system", 5, 5, 2022, 30, 5, 2022, 9);
		emp[2].alltasks.push_back(t2);
		v = true;
	}
	title = "";
	tdescription = "";
	assdate.day = 0;
	assdate.month = 0;
	assdate.year = 0;
	deadlinedate.day = 0;
	deadlinedate.month = 0;
	deadlinedate.year = 0;
	priorityval = 0;
}
void task::sign_up(int idd, string name) {

	int count = 3;
	bool found = false;
	for (int i = 0; i < count; i++) {
		if (idd == emp[i].id)
		{
			found = true;

		}
	}
	if (found == true)
		cout << "id already exist";
	else
	{
		employee newemp;
		newemp.id = idd;
		newemp.name = name;
		emp[count] = newemp;
		count++;
	}
}


void task::login(int idd, string name) {
	bool found = false;
	for (int i = 0; i < 30; i++) {

		if (idd == emp[i].id)
		{
			found = true;
			cout << " You loged in successfully" << endl;
			break;
		}

	}
	if (found == false)
	{
		cout << " This id doesnot exist" << endl;
		cout << "press {s} to sign up" << endl;
		char c;
	label1:
		cin >> c;
		if (c == 's' || c == 'S')
		{
			sign_up(idd, name);
		}
		else {

			cout << "Wrong char,try again" << endl;
			goto label1;
		}

	}
}

void task::reading_tasks(int idd)
{
	task t;
	bool f = false;
	char c;
label:
	while (!f)
	{
		cout << "Do you want to enter new task? if yes enter 'y' if no enter'n'\n";
		cin >> c;
		if (c == 'y' || c == 'Y')
		{

			cout << "enter your task title without spaces please enter '_' to creat a space" << endl;
			cin >> t.title;
			cout << "enter your task description without spaces please enter '_' to creat a space" << endl;
			cin >> t.tdescription;
			cout << "enter the assining date and the deadline date in the form dd/mm/yyyy" << endl;
			cout << "enter the day of assining date" << endl;
			cin >> t.assdate.day;
			cout << "enter the month of assining date" << endl;
			cin >> t.assdate.month;
			cout << "enter the year of assining date" << endl;
			cin >> t.assdate.year;
			cout << "enter the day of ending date" << endl;
			cin >> t.deadlinedate.day;
			cout << "enter the month of ending date" << endl;
			cin >> t.deadlinedate.month;
			cout << "enter the year of ending date" << endl;
			cin >> t.deadlinedate.year;
			cout << "enter the priority value of your task from 1 to 10 as the highest priority is 10" << endl;
			cin >> t.priorityval;
			if (t.priorityval < 1 || t.priorityval>10)
			{
				cout << "error,please enter a value between 1 and 10" << endl;
				goto label;
			}
			for (int i = 0; i < 30; i++)
			{
				if (idd == emp[i].id) {
					emp[i].alltasks.push_back(t);
				}
			}

		}
		else
		{

			f = true;
			break;

		}
	}
}

void task::sort_task(int idd)
{
	for (int i = 0; i < 30; i++)
	{
		if (idd == emp[i].id) {
			sort(emp[i].alltasks.begin(), emp[i].alltasks.end(), [](const task& lhs, const task& rhs)
				{
					return lhs.priorityval > rhs.priorityval;
				});
		}
	}
}
void task::display(int idd) {

	for (int i = 0; i < 30; i++)
	{
		if (idd == emp[i].id) {
			
			for (int m = 0; m < emp[i].alltasks.size(); m++)
			{
				cout << "title of the task: " << emp[i].alltasks[m].title << endl;
				cout << "description is: " << emp[i].alltasks[m].tdescription << endl;
				cout << "the assignment date of the task is: " << emp[i].alltasks[m].assdate.day << "/" << emp[i].alltasks[m].assdate.month << "/" << emp[i].alltasks[m].assdate.year << endl;
				cout << "the deadline of the task is: " << emp[i].alltasks[m].deadlinedate.day << "/" << emp[i].alltasks[m].deadlinedate.month << "/" << emp[i].alltasks[m].deadlinedate.year << endl;
				cout << "the employee assigned to the task is: " << emp[i].name << endl;
				cout << "the priority value is: " << emp[i].alltasks[m].priorityval << endl;
				cout << "the task is not done yet"<< endl;
				cout << "-------------------------------------------------------" << endl;
			}
		}
	}
}


void task::update(int idd) {
	string tasktitle;
	for (int i = 0; i < 30; i++)
	{
		if (idd == emp[i].id)
		{
			cout << "enter the title of the task you want to update to be done" << endl;
			cin >> tasktitle;
			for (size_t j = 0; j < emp[i].alltasks.size(); j++)
			{
				if (tasktitle == emp[i].alltasks[j].title)
				{
					emp[i].alltasks.erase(emp[i].alltasks.begin() + j);
					cout << "thank you the task is deleted now" << endl;
				}
			}
		}
	}

	/*cout << "enter the title of the task you want to update to be done" << endl;
label1:
	cin >> t.title;
	getline(cin, t.title);
	vector<task>::iterator q;
	vector<task>::iterator p;
	for (size_t i = 0; i < 30; i++)
	{

		for (size_t j = 0; j < emp[i].alltasks.size(); j++)
		{
			q = emp[i].alltasks.begin();
			if (t.title == emp[i].alltasks[j].title)
			{

				p = emp[i].alltasks.erase(q);

			}
			else
				goto label1;
		}
	}*/
			
}
void task::reminder(int idd)
{
	time_t now = time(0);   //to get the current system time as seconds
	char* dt = ctime(&now);  //to convert the current system time to string 
	tm* localTime = localtime(&now); //to convert string to day/month/year form as integers
	int d = localTime->tm_mday;

	int m = 1 + localTime->tm_mon;

	int y = 1900 + localTime->tm_year;

	if (d == 31 && (m == 1 || m == 2 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)) {
		if (m == 12) {
			d = 0;
			m = 1;
			y++;
		}
		else {
			d = 0;
			m++;
		}

	}

	if (d == 30 && (m == 4 || m == 6 || m == 9 || m == 11))
	{
		d = 0;
		m++;
	}
	if (d == 29 && m == 2) {
		d = 0;
		m++;
	}
	if (d == 28 && m == 2) {

		if (y % 400 == 0 || y % 100 != 0 || y % 4 == 0) {

			d++;



		}

		else {
			d = 0;
			m++;
		}
	}
	else {
		d = d + 1;

	}
	for (int i = 0; i < 30; i++)
	{
		if (idd == emp[i].id) {
			for (size_t j = 0; j < emp[i].alltasks.size(); j++)
			{
				if (y == emp[i].alltasks[j].assdate.year && m == emp[i].alltasks[j].assdate.month) {

					if (emp[i].alltasks[j].assdate.day == d)
					{
						cout << "Reminder that you should start that task(s) tommorow and heres the details" << endl;
						cout << "title of the task :" << emp[i].alltasks[j].title << endl;
						cout << "description  :" << emp[i].alltasks[j].tdescription << endl;
						cout << "the deadline date of the task is :" << emp[i].alltasks[j].deadlinedate.day << "/" << emp[i].alltasks[j].deadlinedate.month << "/" << emp[i].alltasks[j].deadlinedate.year << endl;
						cout << "the priority value is :" << emp[i].alltasks[j].priorityval << endl;
						cout << "the task is not done yet" << endl;

					}
				}
				else {

					continue;

				}
			}
		}
	}
}

void quotes() {
	vector<string>v;
	std::string s = "quotes.txt";
	std::ifstream MF;
	MF.open(s, std::ios::in);
	if (MF.is_open()) {

		while (!MF.eof())
		{

			getline(MF, s);
			v.push_back(s);

		}
	}
	MF.close();
	srand(time(NULL));
	if (v.size())
	{
		cout << v[rand() % v.size()] << "\n";
	}
	else
	{
		cout << "good job,don't forget to Encourage yourself, believe in yourself, and love yourself. Never doubt who you are." <<endl;
	}

}

void task::qoute(int idd)
{
	task t;
	for (int i = 0; i < 30; i++)
	{
		if (idd == emp[i].id)
		{

			if (emp[i].alltasks.size() == 0)
			{
				quotes();
			}


		}
	}
}


