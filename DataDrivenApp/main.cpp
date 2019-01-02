#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void clearScreen() {
	for (int i = 0; i < 1000; i++) {
		cout << endl;
	}
}

void dashPrint() {
	cout << endl;
	for (int i = 0; i < 100; i++) {
		cout << "-";
	}
	cout << endl;
}

//this function doesn't correctly redirect the user to the menu or out of the app if a char value is entered before an int
//I may need to look into "templates" or "union" according to stackoverflow, for now the function is not in use
void wipe(int input) {
	cout << "Invalid input, try again" << endl;
	cin.clear();
	cin.ignore(1000, '\n');
	cin >> input;
}

/* NON FUNCTIONAL, NO IDEA WHY
void searchCount(int count, string lower, string upper) {
	cout << "Counting tweets that mention "<< lower << ":" << endl;
	while (!infile.eof()) {
		while (getline(infile, line)) {
			if ((offset = line.find(lower, 0)) != string::npos) {
				count++;
			}
			else if ((offset = line.find(upper, 0)) != string::npos) {
				count++;
			}
		}
	}
	cout << count << " tweets mention" << lower << "." << endl;
}
*/



int main() {

	ifstream infile;
	string line, searchTerm;
	int count, restart, offset;

	//list of all search options for easier repeating
	string queries[12] = { "Count Total", "Count tweets that mention money", "Count tweets that mention politics", "Print tweets mentioning Paris", "Print tweets mentioning Dreamworks", "Print tweets mentioning Uber", "Print by custom Search", "Count by custom Search", "Count by custom date", "Print by custom date", "Print all", "Exit app"};

	//checks file is good before running program
	if (infile.good()) {

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
				cout << "Counting tweets in file:" << endl;
				while (!infile.eof()) {
					getline(infile, line);
					count++;
				}
				cout << count << " tweets in total." << endl;
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
			case 2:
				
				clearScreen();
				count = 0;

				infile.open("sampleTweets.csv");
				while (!infile.eof()) {
					while (getline(infile, line)) {
						if ((offset = line.find("money", 0)) != string::npos) {
							count++;
						}
						else if ((offset = line.find("Money", 0)) != string::npos) {
							count++;
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
			case 3:
				clearScreen();
				count = 0;

				infile.open("sampleTweets.csv");
				cout << "Counting tweets that mention money:" << endl;
				while (!infile.eof()) {
					while (getline(infile, line)) {
						if ((offset = line.find("politics", 0)) != string::npos) {
							count++;
						}
						else if ((offset = line.find("Politics", 0)) != string::npos) {
							count++;
						}
					}
				}

				cout << count << " tweets mention politics." << endl;
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
			case 4:
				clearScreen();

				infile.open("sampleTweets.csv");
				cout << "Printing tweets that mention Paris:" << endl;
				while (!infile.eof()) {
					while (getline(infile, line)) {
						if ((offset = line.find("paris", 0)) != string::npos) {
							cout << line << endl;
							dashPrint();
						}
						else if ((offset = line.find("Paris", 0)) != string::npos) {
							cout << line << endl;
							dashPrint();
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
			case 5:
				clearScreen();

				infile.open("sampleTweets.csv");
				cout << "Printing tweets that mention Dreamworks:" << endl;
				while (!infile.eof()) {
					while (getline(infile, line)) {
						if ((offset = line.find("dreamworks", 0)) != string::npos) {
							cout << line << endl;
							dashPrint();
						}
						else if ((offset = line.find("Dreamworks", 0)) != string::npos) {
							cout << line << endl;
							dashPrint();
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
			case 6:
				clearScreen();

				infile.open("sampleTweets.csv");
				cout << "Printing tweets that mention Uber:" << endl;
				while (!infile.eof()) {
					while (getline(infile, line)) {
						if ((offset = line.find("uber", 0)) != string::npos) {
							cout << line << endl;
							dashPrint();
						}
						else if ((offset = line.find("Uber", 0)) != string::npos) {
							cout << line << endl;
							dashPrint();
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
			case 7:
				clearScreen();

				cout << "Please enter a word to be searched" << endl;
				cin >> searchTerm;

				infile.open("sampleTweets.csv");
				cout << "Printing tweets that mention " << searchTerm << ":" << endl;
				while (!infile.eof()) {
					while (getline(infile, line)) {
						if ((offset = line.find(searchTerm, 0)) != string::npos) {
							cout << line << endl;
							dashPrint();
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

				infile.open("sampleTweets.csv");
				cout << "Counting tweets that mention " << searchTerm << ":" << endl;
				while (!infile.eof()) {
					while (getline(infile, line)) {
						if ((offset = line.find(searchTerm, 0)) != string::npos) {
							count++;
						}
					}
				}

				cout << count << " tweets that mention " << searchTerm << "." << endl;
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
			case 9:
				clearScreen();
				count = 0;

				cout << "Please enter a date to search using the DD/MM/YYYY" << endl;
				cin >> searchTerm;

				infile.open("sampleTweets.csv");
				cout << "Counting tweets that mention " << searchTerm << ":" << endl;
				while (!infile.eof()) {
					while (getline(infile, line)) {
						if ((offset = line.find(searchTerm, 0)) != string::npos) {
							count++;
						}
					}
				}

				cout << count << " tweets that mention " << searchTerm << "." << endl;
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
				clearScreen();
				count = 0;

				cout << "Please enter a date to search using the DD/MM/YYYY" << endl;
				cin >> searchTerm;

				infile.open("sampleTweets.csv");
				cout << "Counting tweets tweets from " << searchTerm << ":" << endl;
				while (!infile.eof()) {
					while (getline(infile, line)) {
						if ((offset = line.find(searchTerm, 0)) != string::npos) {
							cout << line << endl;
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

			case 11:
				clearScreen();
				infile.open("sampleTweets.csv");
				cout << "Printing all tweets:" << endl;
				while (!infile.eof()) {
					getline(infile, line);
					cout << line << endl;
					dashPrint();
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

		cout << "successfully exited loop" << endl; //temporary line to test loop functions correctly


		
	}
	else {
		cout << "Error reading file, that's your problem" << endl; //error for bad files
	}
	
	
	system("pause");
	return 0;
}