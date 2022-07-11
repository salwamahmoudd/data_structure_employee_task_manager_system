#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include <string>
#include"emp_task.h"
#include<ctime>
#include<algorithm>
#include "employee.h"
using namespace std;

int main() {

	task t;

	int choice;
	cout << "Do you want to to sign up or login? enter\n 1-for login \n 2-sign up\n ";
	cin >> choice;
	cout << "enter your name " << endl;
	string name;
	cin >> name;
	cout << "enter your id" << endl;
	int idd;
	cin >> idd;
	if (choice == 1) {

		t.login(idd, name);
	}
	else
	{

		t.sign_up(idd, name);
	}
	int c;
	bool exit = false;
	while (!exit) {
		cout << "1-Reading tasks" << endl;
		cout << "2-Display tasks" << endl;
		cout << "3-Update tasks" << endl;
		cout << "4-exit" << endl;
		cin >> c;
		switch (c)
		{
		case(1):t.reading_tasks(idd);
			t.sort_task(idd);
			break;

		case(2):t.display(idd);
			break;
		case(3):t.update(idd);
			break;
		case(4):exit = true;
			break;
		default:
			break;
		}
	}
	t.reminder(idd);
	t.qoute(idd);
	return 0;

}