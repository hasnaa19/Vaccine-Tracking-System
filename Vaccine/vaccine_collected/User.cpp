#include "User.h"
#include<iostream>
#include <string>
#include "LinkedList.cpp"
#include<queue>
#include <map>
using namespace std;


float User::unvaccinatedCount = 2;
float User::fullyVaccinatedCount = 2;
float User::oneDoseCount = 2;

User::User(string fname, string password, string vstate, string id, string gov, char gender, int age) {
	full_name = fname;
	PW = password;
	Vaccination_State = vstate;
	ID = id;
	Govenorate = gov;
	Gender = gender;
	Age = age;
	Country = "Egypt";
}

User::User()
{
}

bool User::Login(LinkedList<User> userList, User& AU, string id) {

	bool userEXISTS = false, idCHECK = false;;
	string  pw;
	char choice = 'x';
	int flag = -1;


	for (int i = 0; i < userList.Length(); i++) {
		if (id == userList.At(i).ID)
		{
			flag = i;
			idCHECK = true;
		}
	}
	if (idCHECK == true) {
		while (true) {
			cout << "Please, enter your pw: " << endl;
			cin >> pw;
			if (pw == userList.At(flag).PW) {
				cout << "Successfully logged in" << endl;
				userEXISTS = true;
				AU = userList.At(flag);
				break;
			}
			else {
				cout << "Incorrect password, Would you like to Re-enter your password?[Y/N]" << endl;
				cin >> choice;
				if (choice == 'y') { continue; }
				else { break; }
			}

		}
	}



	return userEXISTS;
}

void User::DisplayMyRecord(User AU) {
	cout << "Name: " << AU.full_name << "\t\t";
	cout << "ID: " << AU.ID << "\t\t";
	cout << "Age: " << AU.Age << "\t\t";
	cout << "Gender: " << AU.Gender << endl;
	cout << "Country: " << AU.Country << "\t\t";
	cout << "Govenorate: " << AU.Govenorate << "\t\t";
	cout << "Vaccination state: " << AU.Vaccination_State << "\n";

}

bool User::Register(LinkedList<User>& usersList, LinkedList<User>& waitinglist) {
	cout << "----------------------Register-----------------------" << endl;
	cout << "ENTER YOUR FULL NAME:";
	getline(cin.ignore(), full_name);
	string password;
	cout << "ENTER YOUR Password(at least 8 characters,containing a lowercase,uppercase letter & a special character'$','@','#','/','#')" << endl;
	while (true) {
		cin >> password;
		if (Pw_validation(password) == true) {
			PW = password;
			break;
		}

	}
	string id;

	cout << "ENTER YOUR ID:";
	while (true) {
		cin >> id;
		if (ID_validation(id) == true) {
			for (int i = 0; i < usersList.Length(); i++) {
				if (id == usersList.At(i).ID) {
					cout << "You already registered before" << endl;
					return false;
				}
			}
			ID = id;
			break;
		}
	}

	int a;
	cout << "ENTER YOUR Age:";
	cin >> a;
	if (a < 16) {
		cout << "Sorry you must be 16 or older" << endl;
		return false;
	}
	else Age = a;

	char g;
	while (true)
	{
		cout << "ENTER YOUR Gender(M/F): ";
		cin >> g;
		if (g != 'M' && g != 'F') {
			cout << "Invalid Entry" << endl;
		}
		else {
			Gender = g;
			break;
		}
	}

	string Gov[27] = { "Alexandria","Aswan","Asyut","Beheira","Beni Suef","Cairo","Dakahlia","Damietta","Faiyum","Gharbia","Giza", "Ismailia", "Kafr El Sheikh", "Luxor","Matruh", "Minya", "Monufia", "New Valley", "North Sinai", "Port Said", "Qalyubia", "Qena", "Red Sea", "Sharqia","Sohag", "South Sinai", "Suez" };
	int choice;
	while (true)
	{
		cout << "CHOOSE YOUR Governorate:" << endl;
		for (int i = 0; i < 27; i++) {
			cout << i + 1 << "-" << Gov[i] << endl;
		}
		cin >> choice;
		if (choice > 0 && choice < 28) {
			Govenorate = Gov[choice - 1];
			break;
		}
		else {
			cout << "Invalid entry,";
		}
	}
	while (true)
	{
		cout << "CHOOSE YOUR Vaccination State:" << endl;
		cout << "1-Fully" << endl << "2-Partially" << endl << "3-Not vaccinated" << endl;
		cin >> choice;
		if (choice > 0 && choice < 4) {

			if (choice == 1) {
				Vaccination_State = "Fully";
			}
			else	 if (choice == 2) {
				Vaccination_State = "Partially";
			}

			else if (choice == 3) {
				Vaccination_State = "Not vaccinated";
			}
			break;
		}
		else {
			cout << "Invalid entry,";
		}
	}
	ADDUSER(usersList, waitinglist);

	return true;
}

bool User::Pw_validation(string password) {
	bool pw_length_valid = true;
	bool pw_specialchar_valid = true;
	bool pw_Uppercase_valid = true;
	bool pw_Lowercase_valid = true;
	if (password.length() < 8) {
		pw_length_valid = false;
		cout << "Password should have at least 8 char" << endl;
	}
	int count = 0;
	for (int i = 0; i < password.length(); i++) {
		if (password[i] == '_' || password[i] == '$' || password[i] == '@' || password[i] == '#' || password[i] == '/') {
			count++;
		}
	}
	if (count == 0) {
		pw_specialchar_valid = false;
		cout << "Password should contain a special char" << endl;

	}
	count = 0;
	for (int i = 0; i < password.length(); i++) {
		if ((password[i] >= 'a' && password[i] <= 'z')) {
			count++;
		}
	}
	if (count == 0) {
		pw_Lowercase_valid = false;
		cout << "Password should contain a lowercase letter" << endl;

	}
	count = 0;
	for (int i = 0; i < password.length(); i++) {
		if ((password[i] >= 'A' && password[i] <= 'Z')) {
			count++;
		}
	}
	if (count == 0) {
		pw_Uppercase_valid = false;
		cout << "Password should contain uppercase letter" << endl;

	}

	if (pw_length_valid == false || pw_specialchar_valid == false || pw_Lowercase_valid == false || pw_Uppercase_valid == false) {
		return false;
	}
	else return true;
}

bool User::ID_validation(string id) {
	bool id_length_validation = true;
	bool id_digits_validation = true;
	int count = 0;
	for (int i = 0; i < id.length(); i++)
	{
		if (id[i] >= '0' && id[i] <= '9')
		{
			count++;
		}
	}
	if (count != id.length()) {
		id_digits_validation = false;
		cout << "ID should contain digits only." << endl;
	}
	if (id.length() != 13) {
		id_length_validation = false;
		cout << "ID should contain 13 digits only." << endl;
	}
	if (id_digits_validation == false || id_length_validation == false) {
		return false;
	}
	else return true;
}
void User::ADDUSER(LinkedList<User>& usersList, LinkedList <User>& waitinglist) {
	User dummy_user(full_name, PW, Vaccination_State, ID, Govenorate, Gender, Age);
	usersList.Append(dummy_user);
	if (dummy_user.Vaccination_State == "Fully") {
		User::fullyVaccinatedCount++;      //for hasnaa
	}
	else if (dummy_user.Vaccination_State == "Partially") {
		//waitinglist.Append(dummy_user);
		User::oneDoseCount++;              // for hasnaa
	}
	else if (dummy_user.Vaccination_State == "Not vaccinated") {
		waitinglist.Append(dummy_user);
		User::unvaccinatedCount++;          // for hasnaa
	}
}
void User::Delete_MyACC(LinkedList<User>& usersList, User AU, LinkedList <User>& waitinglist)
{
	for (int i = 0; i < usersList.Length(); i++)
	{
		if (AU.ID == usersList.At(i).ID) {

			//3shan khatr sanson, mn hna
			if (usersList.At(i).Vaccination_State == "Fully")
				User::fullyVaccinatedCount--;
			else if (usersList.At(i).Vaccination_State == "Partially")
				User::oneDoseCount--;
			else
				User::unvaccinatedCount--;
			//le hna
			usersList.DeleteAt(i);
		}
	}
	for (int j = 0; j < waitinglist.Length(); j++)
	{
		if (AU.ID == waitinglist.At(j).ID) {
			waitinglist.DeleteAt(j);
		}
	}
}
void User::edit_user_data(LinkedList<User>& usersList, User& AU, LinkedList<User>& waitinglist)
{
	char  newGender, repeat = 'y';
	int  newAge, flag;
	string pw, newName, newID, newPw, newGov, newVacc;
	int choice;


	int f = 0, j = 0;
	for (int i = 0; i < usersList.Length(); i++)
	{
		if (AU.ID == usersList.At(i).ID) {
			f = i;
		}

	}
	for (int i = 0; i < waitinglist.Length(); i++)
	{
		if (AU.ID == waitinglist.At(i).ID) {
			j = i;
		}

	}

	cout << "please choose the data you want to edit [1/2/3/4/5/6/7]: \n 1)Name \n 2)National ID \n 3)Password \n  4)Governorate \n 5)Vaccination state \n : ";
	cin >> choice;

	if (choice == 1)
	{

		cout << "please enter your new name: ";
		getline(cin.ignore(), newName);
		User newuser(newName, usersList.At(f).PW, usersList.At(f).Vaccination_State, usersList.At(f).ID, usersList.At(f).Govenorate, usersList.At(f).Gender, usersList.At(f).Age);
		AU = newuser;
		usersList.DeleteAt(f);
		usersList.InsertAt(f, newuser);

		User newuserW(newName, waitinglist.At(j).PW, waitinglist.At(j).Vaccination_State, waitinglist.At(j).ID, waitinglist.At(j).Govenorate, waitinglist.At(j).Gender, waitinglist.At(j).Age);
		waitinglist.DeleteAt(j);
		waitinglist.InsertAt(j, newuser);
	}
	else if (choice == 2) {
		while (true)
		{
			cout << "please enter your new national ID: ";
			cin >> newID;
			if (ID_validation(newID) == true)
			{
				User newuser(usersList.At(f).full_name, usersList.At(f).PW, usersList.At(f).Vaccination_State, newID, usersList.At(f).Govenorate, usersList.At(f).Gender, usersList.At(f).Age);
				AU = newuser;
				usersList.DeleteAt(f);
				usersList.InsertAt(f, newuser);

				User newuserW(waitinglist.At(j).full_name, waitinglist.At(j).PW, waitinglist.At(j).Vaccination_State, newID, waitinglist.At(j).Govenorate, waitinglist.At(j).Gender, waitinglist.At(j).Age);
				waitinglist.DeleteAt(j);
				waitinglist.InsertAt(j, newuser);
				break;
			}
		}
	}
	if (choice == 3)
	{
		while (true)
		{
			cout << "please enter your new password: ";
			cin >> newPw;

			if (Pw_validation(newPw) == true)
			{

				User newuser(usersList.At(f).full_name, newPw, usersList.At(f).Vaccination_State, usersList.At(f).ID, usersList.At(f).Govenorate, usersList.At(f).Gender, usersList.At(f).Age);
				AU = newuser;
				usersList.DeleteAt(f);
				usersList.InsertAt(f, newuser);

				User newuserW(waitinglist.At(j).full_name, newPw, waitinglist.At(j).Vaccination_State, waitinglist.At(j).ID, waitinglist.At(j).Govenorate, waitinglist.At(j).Gender, waitinglist.At(j).Age);
				waitinglist.DeleteAt(j);
				waitinglist.InsertAt(j, newuser);
				break;
			}

		}
	}
	/*	 else if(choice==4)
	 {

		 while (true)
		 {
			 cout << "ENTER YOUR Gender(M/F): ";
			 cin >> newGender;
			 if (newGender != 'M' && newGender != 'F') {
				 cout << "Invalid Entry" << endl;
			 }
			 else {
				 User newuser(usersList.At(i).full_name, usersList.At(i).PW, usersList.At(i).Vaccination_State, usersList.At(i).ID, usersList.At(i).Govenorate, newGender, usersList.At(i).Age);
				 usersList.DeleteAt(i);
				 usersList.InsertAt(i, newuser);
				 break;
			 }
		 }
	 }
		 else if(choice ==5)
		  {
		 cout << "ENTER YOUR Age:";
		 cin >> newAge;
		 if (newAge < 16) {
			 cout << "Sorry you must be 16 or older" << endl;
			 break;
		 }
		 else
		 {
			 User newuser(usersList.At(i).full_name, usersList.At(i).PW, usersList.At(i).Vaccination_State, usersList.At(i).ID, usersList.At(i).Govenorate, usersList.At(i).Gender, newAge);
			 usersList.DeleteAt(i);
			 usersList.InsertAt(i, newuser);
		 }
		 break;
		 }
		 */





	else if (choice == 4)
	{
		string Gov[27] = { "Alexandria","Aswan","Asyut","Beheira","Beni Suef","Cairo","Dakahlia","Damietta","Faiyum","Gharbia","Giza", "Ismailia", "Kafr El Sheikh", "Luxor","Matruh", "Minya", "Monufia", "New Valley", "North Sinai", "Port Said", "Qalyubia", "Qena", "Red Sea", "Sharqia","Sohag", "South Sinai", "Suez" };
		int choicegov;
		while (true)
		{
			cout << "Please enter your new governrate: ";
			for (int i = 0; i < 27; i++)
			{
				cout << i + 1 << "-" << Gov[i] << endl;
			}
			cin >> choicegov;
			if (choicegov > 0 && choicegov < 28)
			{
				newGov = Gov[choicegov - 1];
				User newuser(usersList.At(f).full_name, usersList.At(f).PW, usersList.At(f).Vaccination_State, usersList.At(f).ID, newGov, usersList.At(f).Gender, usersList.At(f).Age);
				AU = newuser;
				usersList.DeleteAt(f);
				usersList.InsertAt(f, newuser);

				User newuserW(waitinglist.At(j).full_name, waitinglist.At(j).PW, waitinglist.At(j).Vaccination_State, waitinglist.At(j).ID, newGov, waitinglist.At(j).Gender, waitinglist.At(j).Age);
				waitinglist.DeleteAt(j);
				waitinglist.InsertAt(j, newuser);
				break;
			}
			else
			{
				cout << "Invalid entry,";
			}
		}
	}
	else if (choice == 5)
	{
		char test;
		if (usersList.At(f).Vaccination_State == "Not vaccinated")
		{
			cout << "have you taken the first dose? [y/n]: ";
			cin >> test;
			if (test == 'y')
			{
				newVacc = "Partially";
				User::unvaccinatedCount--;   //for hasnaa
				User::oneDoseCount++;        //for hasnaa
			}
		}
		else if (usersList.At(f).Vaccination_State == "Partially")
		{
			cout << "have you taken the second dose? [y/n]: ";
			cin >> test;
			if (test == 'y')
			{
				newVacc = "Fully";
				User::oneDoseCount--;     //for hasnaa
				User::fullyVaccinatedCount++;   //for hasnaa
			}

		}
		if (newVacc == "Fully" || newVacc == "Partially") {
			User newuser(usersList.At(f).full_name, usersList.At(f).PW, newVacc, usersList.At(f).ID, usersList.At(f).Govenorate, usersList.At(f).Gender, usersList.At(f).Age);
			AU = newuser;
			usersList.DeleteAt(f);
			usersList.InsertAt(f, newuser);

			User newuserW(waitinglist.At(j).full_name, waitinglist.At(j).PW, newVacc, waitinglist.At(j).ID, waitinglist.At(j).Govenorate, waitinglist.At(j).Gender, waitinglist.At(j).Age);
			waitinglist.DeleteAt(j);
			waitinglist.InsertAt(j, newuser);
		}
	}
}

//state = Partially or Fully or not Vaccinated
//numOfPeople = unvaccinatedCount OR oneDoseCount OR fullyVaccinatedCount
void User::vaccinationState_stat(LinkedList<User>& list, string state, float numOfPeople)
{
	if (numOfPeople == 0) {
		cout << "THERE ARE NO USERS IN OUR SYSTEM WITH THIS VACCINATION STATE." << endl;
	}
	else {
		int dosesNum;
		if (state == "Fully")
			dosesNum = numOfPeople * 2;
		else if (state == "Partially")
			dosesNum = numOfPeople;
		else
			dosesNum = 0;
		int listLength = list.Length();
		cout << "		" << "COUNT" << "		" << "% PERCENTAGE" << "		" << "DOSES GIVEN" << endl;
		cout << "		" << "-----" << "		" << "-------------" << "		" << "-----------" << endl;
		cout << "		  " << numOfPeople << "		  " << (numOfPeople / listLength) * 100 << "%	 	   " << dosesNum << endl;

		float maleCount = 0, femaleCount = 0;
		float youthCount = 0, adultsCount = 0, seniorsCount = 0;
		map <string, float> regionsCount;
		map<string, float>::iterator itr;

		Node<User>* temp = list.head;
		for (int i = 0; i < listLength; i++) {
			if (temp->value.Gender == 'M' && temp->value.Vaccination_State == state)
				maleCount++;
			else if (temp->value.Gender == 'F' && temp->value.Vaccination_State == state)
				femaleCount++;
			if (temp->value.Age >= 16 && temp->value.Age <= 24 && temp->value.Vaccination_State == state)
				youthCount++;
			else if (temp->value.Age >= 25 && temp->value.Age <= 64 && temp->value.Vaccination_State == state)
				adultsCount++;
			else if (temp->value.Age >= 65 && temp->value.Vaccination_State == state)
				seniorsCount++;
			if (temp->value.Vaccination_State == state) {
				itr = regionsCount.find(temp->value.Govenorate);  //find (primary key), find the element whose primary key is..
				if (itr == regionsCount.end()) {
					regionsCount.insert(pair<string, float>(temp->value.Govenorate, 1));
				}
				else
					itr->second += 1;
			}
			temp = temp->next;
		}
		cout << endl << "from this percentage," << endl << endl;
		cout << "--------" << endl;
		cout << "GENDER :	 " << endl;
		cout << "--------" << endl;
		cout << (femaleCount / numOfPeople) * 100 << "% are Females		" << (maleCount / numOfPeople) * 100 << "% are Males" << endl << endl;
		cout << "--------" << endl;
		cout << "AGE : " << endl;
		cout << "--------" << endl;
		cout << (youthCount / numOfPeople) * 100 << "% are Youth(16< age< 24)	" << (adultsCount / numOfPeople) * 100 << "% are Adults(24< age< 64)	" << (seniorsCount / numOfPeople) * 100 << "% are Seniors(age> 64)" << endl << endl;
		cout << "--------" << endl;
		cout << "REGION :  " << endl;
		cout << "--------" << endl;
		for (itr = regionsCount.begin(); itr != regionsCount.end(); ++itr) {
			cout << (itr->second / numOfPeople) * 100.0 << "% are from " << itr->first << endl;
		}
	}
	cout << "_____________________________________________________" << endl << endl;
}