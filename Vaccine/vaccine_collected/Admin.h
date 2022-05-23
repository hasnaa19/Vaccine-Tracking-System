#pragma once
#include<iostream>
#include <string>
#include "User.h"
using namespace std;

class Admin
{
public:
	const string  name = "ADMINISTRATOR";
private:

	const string pw = "Adminp_1";

public:
	Admin();
	bool Admin_signIn();
	void Delete_Admin(LinkedList<User>& usersList, LinkedList<User>& waitinglist);
	void Delete_all_records(LinkedList<User>& usersList, LinkedList<User>& waitinglist);
	void Delete_one_user(LinkedList<User>& usersList, LinkedList<User>& waitinglist);
	void Browse_a_User(LinkedList<User>&);
	void Display_all(LinkedList<User>&);
	
	void general_Statistics(int Length);
	void accordingToGender_stat(LinkedList<User>& list);
	void accordingToAge_stat(LinkedList<User>& list);
	void accordingToRegion_stat(LinkedList<User>& list);
};


