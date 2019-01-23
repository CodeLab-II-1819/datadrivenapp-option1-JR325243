#include <iostream>
#include <fstream>
#include <string>
#include "Tweet.h"

using namespace std;

int main() {

	ifstream infile;
	int count = 0, restart = 0, offset = 0;
	string line, searchTerm, searchTermUpper;

	//list of all search options for easier repeating
	string queries[12] = { "Count Total", "Count tweets that mention money", "Count tweets that mention politics", "Count tweets that @ JLo", "Count by custom date", "Print tweets mentioning Paris", "Print tweets mentioning Dreamworks", "Print tweets mentioning Uber", "Print by custom Search", "Print all			<- this one takes like 20 minutes lol", "Exit app"};

	//checks file is good before running program
	

		//do loop keeps user running through menu until a valid option has been selected and carried out
		bool escape = false;
		do {
			//print list of query options
			Tweet::clearScreen();
			cout << "Select query:" << endl;
			for (int i = 0; i < 10; i++) {
				cout << i + 1 << ". " << queries[i] << endl;
			}
			Tweet::dashPrint();
			cout << "0." << queries[10] << endl;

			//user input + cin.fail: user selects their query choice and is stopped from inputting incorrect data types
			int userInput;
			cin >> userInput;
			while (cin.fail()) {
				cout << "Invalid input, try again" << endl;
				cin.clear();
				cin.ignore(1000, '\n');
				cin >> userInput;
			}

			//switch to determine which search to carry out
			switch (userInput) {

			/*============================================================================*/
			case 1:
				Tweet::clearScreen();
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
				Tweet::Count(infile, count, offset, "money", "Money", line);

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
				Tweet::Count(infile, count, offset, "politics", "Politics", line);

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
				Tweet::Count(infile, count, offset, "@JLo", "@JLo", line);
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
				cout << "Please enter a date to search using the DD/MM/YYYY" << endl;
				cin >> searchTerm;

				Tweet::Date(infile, count, offset, searchTerm, line);

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
			case 7:
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
			case 8:
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
			case 9:

				cout << "Please enter a word to be searched" << endl;
				cin >> searchTerm;

				Tweet::Print(infile, offset, searchTerm, searchTerm, line);

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
			case 10:
				infile.open("sampleTweets.csv");
				cout << "Printing all tweets:" << endl;
				while (!infile.eof()) {
					getline(infile, line);
					cout << line << endl;
					Tweet::dashPrint();
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

		Tweet::dashPrint();
		//cout << "Thank you for using this app!" << endl; //temporary line to test loop functions correctly
	
	
	system("pause");
	return 0;
}