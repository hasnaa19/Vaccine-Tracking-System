#pragma once
#include<iostream>
#include <string.h>
#include "LinkedList.h"
#include<queue>

using namespace std;
class User
{
public:
	string full_name, PW, Country, Vaccination_State, ID, Govenorate;
	char Gender;
	int Age;
	float static unvaccinatedCount;
	float static oneDoseCount;
	float static fullyVaccinatedCount;

public:
	User(string, string, string, string, string, char, int);
	User();

	bool Register(LinkedList<User>&, LinkedList <User>&);
	bool Login(LinkedList<User>, User&, string);
	void DisplayMyRecord(User);
	void Delete_MyACC(LinkedList<User>&, User, LinkedList<User>&);
	void edit_user_data(LinkedList<User>&, User&, LinkedList<User>&);
	void vaccinationState_stat(LinkedList<User>&, string, float);
private:
	void ADDUSER(LinkedList<User>&, LinkedList <User>&);
	bool Pw_validation(string);
	bool ID_validation(string);

};





