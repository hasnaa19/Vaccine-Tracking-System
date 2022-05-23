#include "Admin.h"
#include <iostream> 
#include <string>
#include "LinkedList.cpp"
#include "User.h"
#include<queue>
#include <map>
using namespace std;


Admin::Admin() {}
bool Admin::Admin_signIn() {
	string p;  bool isADMIN = false;
	int attempts = 3, counter = 0;
	cout << "Please enter the Adminstrator password: " << endl;
	do
	{
		cin >> p;
		if (p == pw) {
			cout << "Successfully logged in" << endl;
			isADMIN = true;
			break;

		}
		else {
			if (counter < attempts - 1)
			{
				cout << "Failed to log in" << endl << "Please, Re-enter your password: " << endl;
				continue;
			}
			else {
				cout << "You reached the maximum number of attempts" << endl
					<< "Please, Go back to the main menu and Re-enter your choice!" << endl;
			}
		}

	} while (++counter < attempts);
	return isADMIN;
}
void Admin::Display_all(LinkedList<User>& usersList) {
	User temp;
	if (usersList.Length() == 0) {
		cout << "There is no users, Check again later!\n";
	}
	else {
		for (int i = 0; i < usersList.Length(); i++) {
			temp.DisplayMyRecord(usersList.At(i));
			cout << "\n___________________________________________________________________________________________" << endl;
		}
	}
}
void Admin::Delete_Admin(LinkedList<User>& usersList, LinkedList<User>& waitinglist) {
	int choice = 0; char check = 0;
	if (usersList.Length() == 0) {
		cout << "There is no users, Check again later!\n";
	}
	else {
		while (true) {
			cout << "------------------------------------------------------------------------" << endl;
			cout << endl;
			cout << "1) Delete all users " << endl;
			cout << "2) Delete a user " << endl;
			cin >> choice;

			if (choice < 1 || choice > 2) {
				cout << "Invalid entry" << "\t Please, type a number between 1 and 2 \n ";
				cout << "would you like to try again [Y/N]" << endl;
				while (true) {
					cin >> check;
					if (check == 'Y' || check == 'y' || check == 'N' || check == 'n') {
						break;
					}
					else {
						cout << "Invalid Entry,Please Enter [Y/N]" << endl;
						continue;
					}
				}
				if (check == 'Y' || check == 'y') {
					continue;
				}

				else if (check == 'N' || check == 'n') {
					break;

				}
			}
			else {

				if (choice == 1) {
					Delete_all_records(usersList, waitinglist);

				}
				else if (choice == 2) {
					Delete_one_user(usersList, waitinglist);

				}

				cout << "Want to delete again?[Y/N]: " << endl;
				while (true) {
					cin >> check;
					if (check == 'Y' || check == 'y' || check == 'N' || check == 'n') {
						break;
					}
					else {
						cout << "Invalid Entry,Please Enter [Y/N]" << endl;
						continue;
					}
				}
				if (check == 'Y' || check == 'y') {
					continue;
				}

				else if (check == 'N' || check == 'n') {
					break;

				}
			}
		}
	}
}
void  Admin::Delete_all_records(LinkedList<User>& usersList, LinkedList<User>& waitinglist)
{
	int choice_delete;
	while (true) {
		cout << "Do you want to delete : " << endl;
		cout << "1) FullyVaccinated users. " << endl;
		cout << "2) Partially vaccinated users." << endl;
		cout << "3) Unvacinated users." << endl;
		cout << "4) All users." << endl;
		char check = 0;
		cin >> choice_delete;

		if (choice_delete < 1 || choice_delete > 4) {
			cout << "Invalid entry" << "\t Please, type a number between 1 and 4 \n ";
			cout << "would you like to try again [Y/N]" << endl;
			while (true) {
				cin >> check;
				if (check == 'Y' || check == 'y' || check == 'N' || check == 'n') {
					break;
				}
				else {
					cout << "Invalid Entry,Please Enter [Y/N]" << endl;
					continue;
				}
			}
			if (check == 'Y' || check == 'y') {
				continue;
			}

			else if (check == 'N' || check == 'n') {
				break;

			}
		}
		else {
			if (choice_delete == 1)
			{
				int i = usersList.Length() - 1;

				while (i >= 0) {

					if (usersList.At(i).Vaccination_State == "Fully") {
						usersList.DeleteAt(i);
					}
					i--;
				}
				User::fullyVaccinatedCount = 0;   //for hasnaa

			}
			else if (choice_delete == 2)
			{
				int i = usersList.Length() - 1;

				while (i >= 0) {
					if (usersList.At(i).Vaccination_State == "Partially") {
						usersList.DeleteAt(i);
					}
					i--;
				}
				cout << "Users are succesfully deleted." << endl;
				User::oneDoseCount = 0;           //for hasnaa
			}

			else if (choice_delete == 3)
			{
				int i = usersList.Length() - 1;


				while (i >= 0) {
					if (usersList.At(i).Vaccination_State == "Not vaccinated") {
						usersList.DeleteAt(i);
					}

					i--;



					//pop queue 
				}
				int j = waitinglist.Length() - 1;
				while (j >= 0) {
					waitinglist.DeleteAt(j);
					j--;
				}

				cout << "Users are succesfully deleted." << endl;
				User::unvaccinatedCount = 0;      //for hasnaa
			}


			else if (choice_delete == 4)
			{
				int i = usersList.Length() - 1;
				int j = waitinglist.Length() - 1;
				while (i >= 0) {
					usersList.DeleteAt(i);
					i--;
				}
				while (j >= 0) {
					waitinglist.DeleteAt(j);
					j--;
				}
				//pop queue

				User::fullyVaccinatedCount = 0; //for hasnaa
				User::unvaccinatedCount = 0;    //for hasnaa
				User::oneDoseCount = 0;         //for hasnaa
				cout << "Users are succesfully deleted." << endl;

			}
			break;
		}
	}
}
void Admin::Delete_one_user(LinkedList<User>& usersList, LinkedList<User>& waitinglist) {
	string N_id;
	bool test_case = false;
	char check = 0;
	while (true)
	{
		cout << "Enter National ID : " << endl;
		cin >> N_id;
		for (int i = 0; i < usersList.Length(); i++) {
			if (N_id == usersList.At(i).ID) {
				test_case = true;
			}
		}
		if (test_case == true) {
			break;
		}
		else {
			cout << "This ID doesn't exist" << endl;
		}
	}

	for (int i = 0; i < usersList.Length(); i++)
	{
		if (N_id == usersList.At(i).ID)
		{
			cout << usersList.At(i).full_name << endl;
			cout << usersList.At(i).Govenorate << endl;
			cout << usersList.At(i).ID << endl;
			cout << usersList.At(i).Age << endl;

			//3shan khatr sanson, mn hna
			if (usersList.At(i).Vaccination_State == "Fully")
				User::fullyVaccinatedCount--;
			else if (usersList.At(i).Vaccination_State == "Partially")
				User::oneDoseCount--;
			else
				User::unvaccinatedCount--;
			//le hna
			usersList.DeleteAt(i);
			cout << endl;
			cout << "Record selected is successfully deleted." << endl;
			//test_case = true;
			break;
		}
		//if (test_case == false)
		//{
		//	cout << "Incorrect ID, please re-enter it :" << endl;

		//}
	}
	for (int j = 0; j < waitinglist.Length(); j++) {
		if (N_id == waitinglist.At(j).ID) {
			waitinglist.DeleteAt(j);
		}
	}
}
void Admin::Browse_a_User(LinkedList<User>& usersList)
{
	if (usersList.Length() == 0) {
		cout << "There is no users, Check again later!\n";
	}
	else {
		while (true) {
			bool Exists = false;
			int flag;
			char tryagain = 0;
			string ID;
			cout << "Enter the ID of user you want to display his/her record" << endl;
			cin >> ID;
			for (int i = 0; i < usersList.Length(); i++) {
				if (ID == usersList.At(i).ID)
				{
					flag = i;
					Exists = true;
				}
			}

			if (Exists == true) {
				User Exist;
				Exist.DisplayMyRecord(usersList.At(flag));
			}
			else {
				cout << "\n Wrong Id, would you like to try again?[y/n]" << endl;
				cin >> tryagain;
				if (tryagain == 'y' || tryagain == 'Y') {
					continue;
				}
				else if (tryagain == 'N' || tryagain == 'n') {
					break;
				}
				else {
					cout << "Invalid entry" << endl;
					break;
				}
			}
			cout << "\n \n \t \t Would you like to try again ? [y / n]" << endl;
			cin >> tryagain;
			if (tryagain == 'y' || tryagain == 'Y') {
				continue;
			}
			else if (tryagain == 'N' || tryagain == 'n') {
				break;
			}
			else {
				cout << "\n Invalid entry" << endl;
				break;
			}
		}
	}
}
void Admin::general_Statistics(int Length)
{
	if (Length == 0) {
		cout << "THERE ARE NO USERS IN THE SYSTEM CURRENTLY." << endl;
	}
	else {
		float result1, result2, result3;
		result1 = (User::fullyVaccinatedCount / Length) * 100;
		result2 = (User::oneDoseCount / Length) * 100;
		result3 = (User::unvaccinatedCount / Length) * 100;
		cout << "		FULLY VACCINATED			AT LEAST 1 DOSE			UNVACCINATED" << endl;
		cout << "		----------------			----------------		-------------" << endl;
		cout << "COUNT			" << User::fullyVaccinatedCount << "					" << User::oneDoseCount << "   			       " << User::unvaccinatedCount << endl;
		cout << "PERCENTAGE	    " << result1 << "%				   " << result2 << "%			    " << result3 << "%" << endl;

	}
}
void Admin::accordingToGender_stat(LinkedList<User>& list)
{
	if (list.Length() == 0) {
		cout << "THERE ARE NO USERS IN THE SYSTEM CURRENTLY." << endl;
	}
	else {
		float maleCount = 0, femaleCount = 0;

		Node<User>* temp = list.head;
		for (int i = 0; i < list.Length(); i++) {
			if (temp->value.Gender == 'M') {
				maleCount++;
			}
			else {
				femaleCount++;
			}
			temp = temp->next;
		}
		float malePercentage;
		float femalePercentage;

		malePercentage = (maleCount / list.Length()) * 100;
		femalePercentage = (femaleCount / list.Length()) * 100;
		cout << "				" << "COUNT" << "			" << "% PERCENTAGE" << endl;
		cout << "				" << "------" << "			" << "-------------" << endl;
		cout << "FEMALES				  " << femaleCount << "			     " << femalePercentage << "%" << endl;
		cout << "MALES	  			  " << maleCount << "			     " << malePercentage << "%" << endl;
	}
}
void Admin::accordingToAge_stat(LinkedList<User>& list)
{
	if (list.Length() == 0) {
		cout << "THERE ARE NO USERS IN THE SYSTEM CURRENTLY." << endl;
	}
	else {
		float youthCount = 0, adultsCount = 0, seniorsCount = 0;
		Node<User>* temp = list.head;
		for (int i = 0; i < list.Length(); i++) {
			if (temp->value.Age >= 16 && temp->value.Age <= 24)
				youthCount++;
			else if (temp->value.Age >= 25 && temp->value.Age <= 64)
				adultsCount++;
			else if (temp->value.Age >= 65)
				seniorsCount++;
			temp = temp->next;
		}
		float youthPercentage, adultsPercentage, seniorsPercentage;
		youthPercentage = (youthCount / list.Length()) * 100;
		adultsPercentage = (adultsCount / list.Length()) * 100;
		seniorsPercentage = (seniorsCount / list.Length()) * 100;

		cout << "				" << "COUNT" << "			" << "% PERCENTAGE" << endl;
		cout << "				" << "------" << "			" << "-------------" << endl;
		cout << "YOUTH				  " << youthCount << "			     " << youthPercentage << "%" << endl;
		cout << "ADULTS	  			  " << adultsCount << "			     " << adultsPercentage << "%" << endl;
		cout << "SENIORS	  			  " << seniorsCount << "			     " << seniorsPercentage << "%" << endl;
	}
	
}
void Admin::accordingToRegion_stat(LinkedList<User>& list)
{
	if (list.Length() == 0) {
		cout << "THERE ARE NO USERS IN THE SYSTEM CURRENTLY." << endl;
	}
	else {
		//map <dataType1 "primary key", dataType2> map_name;
		//pair <data_type1, data_type2> Pair_name;
		//pair <data_type1, data_type2> Pair_name (value1, value2);
		//Data_type :: iterater iterator_name;

		map <string, float> regionsCount;
		map<string, float>::iterator itr;
		Node<User>* temp = list.head;

		for (int i = 0; i < list.Length(); i++) {
			itr = regionsCount.find(temp->value.Govenorate);  //find (primary key), find the element whose primary key is..
			if (itr == regionsCount.end()) {
				regionsCount.insert(pair<string, float>(temp->value.Govenorate, 1));
			}
			else
				itr->second += 1;
			temp = temp->next;
		}

		for (itr = regionsCount.begin(); itr != regionsCount.end(); ++itr) {
			cout << itr->first << endl;
			cout << "------------" << endl;
			cout << "COUNT : " << itr->second << "	" << "PERCENTAGE % : " << (itr->second / list.Length()) * 100.0 << endl;

			cout << "____________________________________" << endl;
			cout << endl;
		}
		cout << endl << "**Those percentages are calculated with respect to the total number of people applied" << endl;
	}
}