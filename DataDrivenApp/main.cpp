#include <iostream>
#include <fstream>
#include <string>
#include "Tweet.h"

using namespace std;

void clearScreen() {
	for (int i = 0; i < 1000; i++) {
		cout << endl;
	}
}

/*
void dashPrint() {
	cout << endl;
	for (int i = 0; i < 100; i++) {
		cout << "-";
	}
	cout << endl;
}
*/

//this function doesn't correctly redirect the user to the menu or out of the app if a char value is entered before an int
//I may need to look into "templates" or "union" according to stackoverflow, for now the function is not in use
void wipe(int input) {
	cout << "Invalid input, try again" << endl;
	cin.clear();
	cin.ignore(1000, '\n');
	cin >> input;
}

/*
void searchPrint(ifstream &infile, int offset, string lower, string upper, string line) {

	infile.open("sampleTweets.csv");
	if (infile.good()) {
		cout << "Printing tweets that mention " << lower << ":" << endl;
		while (!infile.eof()) {
			while (getline(infile, line)) {
				if ((offset = line.find(" " + lower + " ", 0)) != string::npos || (offset = line.find(" " + upper + " ", 0)) != string::npos) {
					cout << line << endl;
					dashPrint();
				}
			}
		}
	}
	else {
		cout << "Error occured while reading file, please try again" << endl;
	}
	infile.close();
}
*/




int main() {

	ifstream infile;
	int count = 0, restart, offset = 0;
	string line, searchTerm, searchTermUpper;

	//list of all search options for easier repeating
	string queries[12] = { "Count Total", "Count tweets that mention money", "Count tweets that mention politics", "Print tweets mentioning Paris", "Print tweets mentioning Dreamworks", "Print tweets mentioning Uber", "Print by custom Search", "Count by custom Search", "Count by custom date", "Print by custom date", "Print all", "Exit app"};

	//checks file is good before running program
	

		//do loop keeps user running through menu until a valid option has been selected and carried out
		bool escape = false;
		do {
			//print list of query options
			clearScreen();
			cout << "Select query:" << endl;
			for (int i = 0; i < 10; i++) {
				cout << i + 1 << ". " << queries[i] << endl;
			}
			cout << "0." << queries[11] << endl;

			//user input + cin.fail: user selects their query choice and is stopped from inputting incorrect data types
			int userInput;
			cin >> userInput;
			while (cin.fail()) {
				cout << "Invalid input, try again" << endl;
				cin.clear();
				cin.ignore(1000, '\n');
				cin >> restart;
			}

			//switch to determine which search to carry out
			switch (userInput) {
			/*============================================================================*/
			case 1:
				clearScreen();
				
				count = 0;

				infile.open("sampleTweets.csv");
				if (infile.good()) {
					cout << "Counting tweets in file:" << endl;
					while (!infile.eof()) {
						getline(infile, line);
						count++;
					}
					cout << count - 1 << " tweets in total." << endl;
					cout << "Press 0 to search again or any other number to exit." << endl;
					cin >> restart;
					while (cin.fail()) {
						cout << "Invalid input, try again" << endl;
						cin.clear();
						cin.ignore(1000, '\n');
						cin >> restart;
					}
				}
				else {
					cout << "Error occured while reading file, please try again" << endl;
				}

				infile.close();
				
				escape = restart;
				break;

			/*============================================================================*/
			case 2:
				
				clearScreen();
				cout << Tweet::Count(infile, count, offset, "money", "Money", line) << " tweets mention money" << endl;

				cout << "Press 0 to search again or any other number to exit." << endl;
				cin >> restart;
				while (cin.fail()) {
					cout << "Invalid input, try again" << endl;
					cin.clear();
					cin.ignore(1000, '\n');
					cin >> restart;
				}

				escape = restart;
				break;

			/*============================================================================*/
			case 3:
				clearScreen();
				cout << Tweet::Count(infile, count, offset, "politics", "Politics", line) << " tweets mention politics." << endl;

				cout << "Press 0 to search again or any other number to exit." << endl;
				cin >> restart;
				while (cin.fail()) {
					cout << "Invalid input, try again" << endl;
					cin.clear();
					cin.ignore(1000, '\n');
					cin >> restart;
				}

				escape = restart;
				break;

			/*============================================================================*/
			case 4:
				clearScreen();
				Tweet::Print(infile, offset, "paris", "Paris", line);

				cout << "Press 0 to search again or any other number to exit." << endl;
				cin >> restart;
				while (cin.fail()) {
					cout << "Invalid input, try again" << endl;
					cin.clear();
					cin.ignore(1000, '\n');
					cin >> restart;
				}

				escape = restart;
				break;

			/*============================================================================*/
			case 5:
				clearScreen();

				Tweet::Print(infile, offset, "dreamworks", "Dreamworks", line);

				cout << "Press 0 to search again or any other number to exit." << endl;
				cin >> restart;
				while (cin.fail()) {
					cout << "Invalid input, try again" << endl;
					cin.clear();
					cin.ignore(1000, '\n');
					cin >> restart;
				}

				escape = restart;
				break;

			/*============================================================================*/
			case 6:
				clearScreen();
				Tweet::Print(infile, offset, "uber", "Uber", line);

				cout << "Press 0 to search again or any other number to exit." << endl;
				cin >> restart;
				while (cin.fail()) {
					cout << "Invalid input, try again" << endl;
					cin.clear();
					cin.ignore(1000, '\n');
					cin >> restart;
				}

				escape = restart;
				break;

			/*============================================================================*/
			case 7:
				clearScreen();

				cout << "Please enter a word to be searched" << endl;
				cin >> searchTerm;

				infile.open("sampleTweets.csv");
				cout << "Printing tweets that mention " << searchTerm << ":" << endl;
				while (!infile.eof()) {
					while (getline(infile, line)) {
						if ((offset = line.find(" " + searchTerm + " ", 0)) != string::npos) {
							cout << line << endl;
							Tweet::dashPrint();
						}
					}
				}

				cout << "Press 0 to search again or any other number to exit." << endl;
				cin >> restart;
				while (cin.fail()) {
					cout << "Invalid input, try again" << endl;
					cin.clear();
					cin.ignore(1000, '\n');
					cin >> restart;
				}

				infile.close();
				escape = restart;
				break;

			/*============================================================================*/
			case 8:
				clearScreen();
				count = 0;

				cout << "Please enter a word to be searched" << endl;
				cin >> searchTerm;
				//searchTermUpper = (searchTerm[0] = toupper(searchTerm[0])); <- should capitalise first letter, effectiveness questionable
				
				cout << Tweet::Count(infile, count, offset, searchTerm, searchTerm, line) << " tweets that mention " << searchTerm << "." << endl;
				cout << "Press 0 to search again or any other number to exit." << endl;
				cin >> restart;
				while (cin.fail()) {
					cout << "Invalid input, try again" << endl;
					cin.clear();
					cin.ignore(1000, '\n');
					cin >> restart;
				}

				escape = restart;
				break;

			/*============================================================================*/
			case 9:
				clearScreen();
				count = 0;

				cout << "Please enter a date to search using the DD/MM/YYYY" << endl;
				cin >> searchTerm;

				Tweet::Print(infile, offset, searchTerm, searchTerm, line);

				cout << count << " tweets from " << searchTerm << "." << endl;
				cout << "Press 0 to search again or any other number to exit." << endl;
				cin >> restart;
				while (cin.fail()) {
					cout << "Invalid input, try again" << endl;
					cin.clear();
					cin.ignore(1000, '\n');
					cin >> restart;
				}

				escape = restart;
				break;

			/*============================================================================*/
			case 10:
				clearScreen();
				count = 0;

				cout << "Please enter a date to search using the DD/MM/YYYY" << endl;
				cin >> searchTerm;

				cout << Tweet::Count(infile, count, offset, searchTerm, searchTerm, line) << " tweets from " << searchTerm << endl;

				cout << "Press 0 to search again or any other number to exit." << endl;
				cin >> restart;
				while (cin.fail()) {
					cout << "Invalid input, try again" << endl;
					cin.clear();
					cin.ignore(1000, '\n');
					cin >> restart;
				}

				escape = restart;
				break;

			/*============================================================================*/

			case 11:
				clearScreen();
				cout << "Printing all tweets:" << endl;
				while (!infile.eof()) {
					getline(infile, line);
					cout << line << endl;
					Tweet::dashPrint();
				}
				cout << "Press 0 to search again or any other number to exit." << endl;
				cin >> restart;
				while (cin.fail()) {
					wipe(restart);
				}
				infile.close();
				escape = restart;
				break;

			/*============================================================================*/

			case 0:
				escape = true;
				break;

			/*============================================================================*/

			default:
				cout << "Invalid input" << endl;
				escape = false;
				break;

			}
		} while (!escape);

		cout << "Thank you for using this app!" << endl; //temporary line to test loop functions correctly
	
	
	system("pause");
	return 0;
}