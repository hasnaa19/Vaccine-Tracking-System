#include <iostream>
#include "LinkedList.cpp"
#include "User.h"
#include "Admin.h"
#include<queue>
using namespace std;



int main() {

	LinkedList<User> usersList;

	User user1("Hakim Amir", "h", "Partially", "1", "Cairo", 'M', 39);
	User user2("Rafik Hamdy", "Rafik_hamdy1", "Partially", "1990047394011", "Asyut", 'M', 31);
	User user3("Wissam Rizk", "Wissam_rizk1", "Fully", "1985047394011", "Aswan", 'F', 35);
	User user4("Azah Alam", "Azah_alam1", "Fully", "1977047394022", "Alexandria", 'F', 44);
	User user5("Basma Mahmoud", "Basma_mahmoud1", "Not vaccinated", "1977047394011", "Cairo", 'F', 44);
	User user6("Nader Abdo", "Nader_abdo1", "Not vaccinated", "1966047394022", "Alexandria", 'M', 55);

	usersList.Append(user1);
	usersList.Append(user2);
	usersList.Append(user3);
	usersList.Append(user4);
	usersList.Append(user5);
	usersList.Append(user6);

	LinkedList<User> waitinglist;
	/*queue <User>fullyvaccinatedusers;
	queue <User>partiallyvaccinatedusers;
	queue <User>unvaccinatedusers;*/

	for (int i = 0; i < usersList.Length(); i++) {

		if (usersList.At(i).Vaccination_State == "Not vaccinated"/*|| usersList.At(i).Vaccination_State == "Partially"*/) {
			waitinglist.Append(usersList.At(i));
		}
	}

	User activeuser; Admin ActiveAdmin;
	int mainCHOICE = 0;
	char goBACK = 0;
	string ActiveNOW = "undefined";
	bool R;
	cout << "\n \t \t \t \t  Welcome to Vaccine tracking system" << endl;


	while (true) {
		cout << "1-Register" << endl << "\t Already have an account? Type 2 to login instead \n";
		cout << "2-Login \n" << "\t Please, Type your choice in the form of number[1 / 2] \n";
		cin >> mainCHOICE;

		if (mainCHOICE == 1) {
			R = activeuser.Register(usersList, waitinglist);
			if (R) {
				cout << "Successfully Registered " << activeuser.full_name << endl;
				ActiveNOW = "User";
			}
			else {
				continue;
			}
		}
		else if (mainCHOICE == 2) {
			string ID; char choice = 0;
			while (true) {
				cout << "Enter your ID: " << endl;
				cin >> ID;
				transform(ID.begin(), ID.end(), ID.begin(), ::toupper);
				if (ID == ActiveAdmin.name) {
					if (ActiveAdmin.Admin_signIn()) {
						ActiveNOW = "Admin";
						break;
					}
				}
				else if (activeuser.Login(usersList, activeuser, ID)) {

					ActiveNOW = "User";
					break;
				}
				else {
					cout << "Failed to login , Would you like to try again?[Y/N]" << endl;
					while (true)
					{
						cin >> choice;
						if (choice == 'Y' || choice == 'y' || choice == 'N' || choice == 'n') { break; }
						else {
							cout << "Invalid entry,please enter [Y/N]" << endl;
						}
					}
					if (choice == 'Y' || choice == 'y') { continue; }
					else if (choice == 'N' || choice == 'n') { break; }
				}

			}
			if (choice == 'N' || choice == 'n') {
				continue;
			}
		}




		else {
			cout << "Invalid entry" << "\n Please type either 1 or 2 \n Try again?[Y/N]" << endl;
			while (true)
			{
				cin >> goBACK;
				if (goBACK == 'Y' || goBACK == 'y' || goBACK == 'N' || goBACK == 'n') {
					break;
				}
				else {
					cout << "Invalid entry,Please enter [Y/N]" << endl;
				}
			}

			if (goBACK == 'Y' || goBACK == 'y') {
				continue;
			}
			else if ((goBACK == 'n' || goBACK == 'N')) {
				cout << "\n Thanks for using vaccine tracking system!\n" << endl;
				break;
			}


		}
		if (ActiveNOW == "User") {
			int homeCHOICE = 0;
			char homeBACK = 0;
			cout << "\t \t Welcome, " << activeuser.full_name << endl;

			while (true) {

				cout << "1.View my info \n"
					<< "2.Edit/update my info \n"
					<< "3.Delete my account \n"
					<< "4.Show vaccination statistics \n"
					<< "5.Logout \n";
				cout << "_________________________________________________\n";
				cin >> homeCHOICE;
				if (homeCHOICE < 1 || homeCHOICE > 5) {
					cout << "Invalid entry" << "\t Please, type a number between 1 and 5 \n ";
					cout << "would you like to try again [Y/N]" << endl;
					while (true) {
						cin >> homeBACK;
						if (homeBACK == 'Y' || homeBACK == 'y' || homeBACK == 'N' || homeBACK == 'n') {
							break;
						}
						else {
							cout << "Invalid Entry,Please Enter [Y/N]" << endl;
						}
					}
					goBACK = homeBACK;
					if (homeBACK == 'Y' || homeBACK == 'y') {
						continue;
					}

					else if (homeBACK == 'N' || homeBACK == 'n') {
						break;

					}

				}
				else {
					if (homeCHOICE == 1) {
						activeuser.DisplayMyRecord(activeuser);

						cout << "\nBack to home page?[Y/N]" << endl;
						while (true) {
							cin >> homeBACK;
							if (homeBACK == 'Y' || homeBACK == 'y' || homeBACK == 'N' || homeBACK == 'n') {
								break;
							}
							else {
								cout << "Invalid Entry,Please Enter [Y/N]" << endl;
							}
						}						goBACK = homeBACK;
						if (homeBACK == 'Y' || homeBACK == 'y') {
							continue;
						}

						else if (homeBACK == 'N' || homeBACK == 'n') {

							break;

						}


					}
					else if (homeCHOICE == 2) {
						char edit = 0;
						while (true) {
							activeuser.edit_user_data(usersList, activeuser, waitinglist);
							cout << "Edit another info?[y/n]" << endl;
							while (true)
							{
								cin >> edit;
								if (edit == 'y' || edit == 'Y' || edit == 'N' || edit == 'n') {
									break;
								}
								else {
									cout << "Invalid Entry,Please Enter [Y/N]" << endl;
								}
							}
							if (edit == 'y' || edit == 'Y') {
								continue;
							}
							else if (edit == 'n' || edit == 'N') {
								break;
							}

						}
						cout << "\nBack to home page?[Y/N]" << endl;
						while (true) {
							cin >> homeBACK;
							if (homeBACK == 'Y' || homeBACK == 'y' || homeBACK == 'N' || homeBACK == 'n') {
								break;
							}
							else {
								cout << "Invalid Entry,Please Enter [Y/N]" << endl;
							}
						}
						goBACK = homeBACK;
						if (homeBACK == 'Y' || homeBACK == 'y') {
							continue;
						}

						else if (homeBACK == 'N' || homeBACK == 'n') {

							break;

						}


					}
					else if (homeCHOICE == 3) {
						char d = 0;
						cout << "By deleting your account, the system will no longer save your info and you will be automatically disabled?\n"
							<< "\t\t \t Confirm deleting[Y/N]" << endl;
						while (true)
						{
							cin >> d;
							if (d == 'y' || d == 'Y' || d == 'N' || d == 'n') {
								break;
							}
							else {
								cout << "Invalid Entry,Please Enter [Y/N]" << endl;
							}
						}
						if (d == 'y' || d == 'Y') {
							activeuser.Delete_MyACC(usersList, activeuser, waitinglist);
							cout << "\t \t \t Your account have been disabled!\n \t \t \t Thanks for using Vaccine tracking system\n";
							goBACK = 'y';
							break;
						}
						else if (d == 'n' || d == 'N') {
							cout << "Back to home page?" << endl;
							while (true) {
								cin >> homeBACK;
								if (homeBACK == 'Y' || homeBACK == 'y' || homeBACK == 'N' || homeBACK == 'n') {
									break;
								}
								else {
									cout << "Invalid Entry,Please Enter [Y/N]" << endl;
								}
							}									goBACK = homeBACK;
							if (homeBACK == 'Y' || homeBACK == 'y') {
								continue;
							}

							else if (homeBACK == 'N' || homeBACK == 'n') {

								break;

							}

						}


					}
					else if (homeCHOICE == 4) {
						int choice;
						cout << " -For Our Statistics Regarding Fully Vaccinated People Only (Press 1)." << endl;
						cout << " -For Our Statistics Regarding The People Who Took 1 Dose Only (Press 2)." << endl;
						cout << " -For Our Statistics Regarding Unvaccinated People Only (Press 3)." << endl;
						cout << " -If You Want To Display All Of Them (Press 4)." << endl;
						while (true)
						{
							cin >> choice;
							if (choice > 0 && choice < 5) {
								break;
							}
							else {
								cout << "Invalid Entry ,Please re-enter your choice (1~4)" << endl;
							}
						}
						if (choice == 1) {
							cout << "			" << "FULLY VACCINATED PEOPLE STATISTICS" << endl;
							cout << "			" << "***********************************" << endl << endl;
							activeuser.vaccinationState_stat(usersList, "Fully", User::fullyVaccinatedCount);
						}
						else if (choice == 2) {
							cout << "			" << "PARTIALLY VACCINATED PEOPLE STATISTICS" << endl;
							cout << "			" << "**************************************" << endl << endl;
							activeuser.vaccinationState_stat(usersList, "Partially", User::oneDoseCount);
						}
						else if (choice == 3) {
							cout << "			" << "UNVACCINATED PEOPLE STATISTICS" << endl;
							cout << "			" << "******************************" << endl << endl;
							activeuser.vaccinationState_stat(usersList, "Not vaccinated", User::unvaccinatedCount);
						}
						else {
							cout << "			" << "FULLY VACCINATED PEOPLE STATISTICS" << endl;
							cout << "			" << "***********************************" << endl << endl;
							activeuser.vaccinationState_stat(usersList, "Fully", User::fullyVaccinatedCount);

							cout << "			" << "PARTIALLY VACCINATED PEOPLE STATISTICS" << endl;
							cout << "			" << "**************************************" << endl << endl;
							activeuser.vaccinationState_stat(usersList, "Partially", User::oneDoseCount);

							cout << "				" << "UNVACCINATED PEOPLE STATISTICS" << endl;
							cout << "				" << "******************************" << endl << endl;
							activeuser.vaccinationState_stat(usersList, "Not vaccinated", User::unvaccinatedCount);
						}

						cout << "\nBack to home page?[Y/N]" << endl;
						while (true) {
							cin >> homeBACK;
							if (homeBACK == 'Y' || homeBACK == 'y' || homeBACK == 'N' || homeBACK == 'n') {
								break;
							}
							else {
								cout << "Invalid Entry,Please Enter [Y/N]" << endl;
							}
						}
						goBACK = homeBACK;
						if (homeBACK == 'Y' || homeBACK == 'y') {
							continue;
						}

						else if (homeBACK == 'N' || homeBACK == 'n') {

							break;

						}

						return homeBACK;

					}
					else if (homeCHOICE == 5) {
						goBACK = 'y';
						ActiveNOW = "undefined";

						cout << "\t \tSuccessfully logged out\n\n";
						break;

					}
				}


			}
		}
		else if (ActiveNOW == "Admin") {
			int homeCHOICE = 0;
			char homeBACK = 0;
			cout << "\t \t Welcome, Adminstrator" << endl;
			while (true) {
				cout << "1.Browse/ View a specific user \n"
					<< "2.View all User's  \n"
					<< "3.Delete User\n"
					<< "4.Show vaccination statistics \n"
					<< "5.Display waitinglist \n"
					<< "6.Logout\n";
				cout << "_________________________________________________\n";

				cin >> homeCHOICE;
				if (homeCHOICE < 1 || homeCHOICE > 6) {
					cout << "Invalid entry" << "\t Please, type a number between 1 and 5 \n ";
					cout << "would you like to try again [Y/N]" << endl;
					while (true) {
						cin >> homeBACK;
						if (homeBACK == 'Y' || homeBACK == 'y' || homeBACK == 'N' || homeBACK == 'n') {
							break;
						}
						else {
							cout << "Invalid Entry,Please Enter [Y/N]" << endl;
						}
					}
					goBACK = homeBACK;
					if (homeBACK == 'Y' || homeBACK == 'y') {
						continue;
					}

					else if (homeBACK == 'N' || homeBACK == 'n') {
						break;

					}

				}
				else
				{
					if (homeCHOICE == 1) {

						ActiveAdmin.Browse_a_User(usersList);

						cout << "\nBack to home page?[Y/N]" << endl;
						while (true) {
							cin >> homeBACK;
							if (homeBACK == 'Y' || homeBACK == 'y' || homeBACK == 'N' || homeBACK == 'n') {
								break;
							}
							else {
								cout << "Invalid Entry,Please Enter [Y/N]" << endl;
							}
						}						goBACK = homeBACK;
						if (homeBACK == 'Y' || homeBACK == 'y') {
							continue;
						}

						else if (homeBACK == 'N' || homeBACK == 'n') {
							break;

						}

					}
					else if (homeCHOICE == 2) {
						ActiveAdmin.Display_all(usersList);
						cout << "\nBack to home page?[Y/N]" << endl;
						while (true) {
							cin >> homeBACK;
							if (homeBACK == 'Y' || homeBACK == 'y' || homeBACK == 'N' || homeBACK == 'n') {
								break;
							}
							else {
								cout << "Invalid Entry,Please Enter [Y/N]" << endl;
							}
						}
						goBACK = homeBACK;
						if (homeBACK == 'Y' || homeBACK == 'y') {
							continue;
						}

						else if (homeBACK == 'N' || homeBACK == 'n') {
							break;

						}


					}
					else if (homeCHOICE == 3) {
						ActiveAdmin.Delete_Admin(usersList, waitinglist);

						cout << "\nBack to home page?[Y/N]" << endl;
						while (true) {
							cin >> homeBACK;
							if (homeBACK == 'Y' || homeBACK == 'y' || homeBACK == 'N' || homeBACK == 'n') {
								break;
							}
							else {
								cout << "Invalid Entry,Please Enter [Y/N]" << endl;
							}
						}						goBACK = homeBACK;
						if (homeBACK == 'Y' || homeBACK == 'y') {
							continue;
						}

						else if (homeBACK == 'N' || homeBACK == 'n') {
							break;

						}

					}
					else if (homeCHOICE == 4) {
						int choice;
						cout << " -Statistics Concerning Users On The System.(press 1)" << endl;
						cout << " -Statistics Concerning each Vaccination State.(press 2)" << endl;
						while (true)
						{
							cin >> choice;
							if (choice == 1 || choice == 2) {
								break;
							}
							else {
								cout << "Invalid Entry ,Please re-enter your choice (1 or 2)" << endl;
							}
						}
						if (choice == 1) {
							cout << endl << " - CLASSIFICATION BASED ON VACCINATION STATE :-" << endl;
							cout << "***********************************************" << endl << endl;
							ActiveAdmin.general_Statistics(usersList.Length());
							cout << endl << " - GENDER BASED CLASSIFICATION :- " << endl;
							cout << "*********************************" << endl << endl;
							ActiveAdmin.accordingToGender_stat(usersList);
							cout << endl << " - AGE BASED CLASSIFICATION :- " << endl;
							cout << "*******************************" << endl << endl;
							ActiveAdmin.accordingToAge_stat(usersList);
							cout << endl << " - GEOGRAPHICAL BASED CLASSIFICATION :- " << endl;
							cout << "****************************************" << endl << endl;
							ActiveAdmin.accordingToRegion_stat(usersList);
							cout << "------------------------------------------------------------------------" << endl << endl;
						}
						else {
							User temp;
							cout << "			" << "FULLY VACCINATED PEOPLE STATISTICS" << endl;
							cout << "			" << "***********************************" << endl << endl;
							temp.vaccinationState_stat(usersList, "Fully", User::fullyVaccinatedCount);

							cout << "			" << "PARTIALLY VACCINATED PEOPLE STATISTICS" << endl;
							cout << "			" << "**************************************" << endl << endl;
							temp.vaccinationState_stat(usersList, "Partially", User::oneDoseCount);

							cout << "				" << "UNVACCINATED PEOPLE STATISTICS" << endl;
							cout << "				" << "******************************" << endl << endl;
							temp.vaccinationState_stat(usersList, "Not vaccinated", User::unvaccinatedCount);
						}
						cout << "\nBack to home page?[Y/N]" << endl;
						while (true) {
							cin >> homeBACK;
							if (homeBACK == 'Y' || homeBACK == 'y' || homeBACK == 'N' || homeBACK == 'n') {
								break;
							}
							else {
								cout << "Invalid Entry,Please Enter [Y/N]" << endl;
							}
						}						goBACK = homeBACK;
						if (homeBACK == 'Y' || homeBACK == 'y') {
							continue;
						}

						else if (homeBACK == 'N' || homeBACK == 'n') {
							break;

						}

					}
					else if (homeCHOICE == 5) {
						ActiveAdmin.Display_all(waitinglist);
						cout << "\nBack to home page?[Y/N]" << endl;
						while (true) {
							cin >> homeBACK;
							if (homeBACK == 'Y' || homeBACK == 'y' || homeBACK == 'N' || homeBACK == 'n') {
								break;
							}
							else {
								cout << "Invalid Entry,Please Enter [Y/N]" << endl;
							}
						}
						goBACK = homeBACK;
						if (homeBACK == 'Y' || homeBACK == 'y') {
							continue;
						}

						else if (homeBACK == 'N' || homeBACK == 'n') {
							break;

						}
					}
					else if (homeCHOICE == 6) {
						goBACK = 'Y';
						ActiveNOW = "undefined";
						cout << "\t \tSuccessfully logged out\n\n";
						break;
					}
				}
			}
		}

		if (goBACK == 'Y' || goBACK == 'y') {
			continue;
		}
		else if (goBACK == 'n' || goBACK == 'N') {
			cout << "Would you like to logout and go back to mainmenu?[Y/N]\n";
			while (true)
			{
				cin >> goBACK;
				if (goBACK == 'Y' || goBACK == 'y' || goBACK == 'N' || goBACK == 'n') {
					break;
				}
				else {
					cout << "Invalid entry,Please enter[Y/N]" << endl;
				}
			}
			if (goBACK == 'Y' || goBACK == 'y') {
				continue;
			}
			else if (goBACK == 'n' || goBACK == 'N') {
				cout << "\n Thanks for using vaccine tracking system!\n" << endl;
				break;
			}

		}

	}

	system("pause");
	return 0;

}

