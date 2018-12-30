#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void clearScreen() {
	for (int i = 0; i < 1000; i++) {
		cout << endl;
	}
}

void wipe(int input) {
	cout << "Invalid input, try again" << endl;
	cin.clear();
	cin.ignore(1000, '\n');
	cin >> input;
}

int main() {

	string line;
	int count;
	ifstream infile;
	string searchTerm;
	int restart;

	//list of all search options for easier repeating
	string queries[9] = { "Count Total", "Count tweets that mention money", "Count tweets that mention politics", "Print tweets mentioning Paris", "Print tweets mentioning Dreamworks", "Print tweets mentioning Uber", "Unique search", "Search by date", "Print all"};

	//checks file is good before running program
	if (infile.good()) {

		//do loop keeps user running through menu until a valid option has been selected and carried out
		bool escape = false;
		do {
			//print list of query options
			clearScreen();
			cout << "Select query:" << endl;
			for (int i = 0; i < 9; i++) {
				cout << i + 1 << ". " << queries[i] << endl;
			}

			//user input + cin.fail: user selects their query choice and is stopped from inputting incorrect data types
			int userInput;
			cin >> userInput;
			while (cin.fail()) {
				wipe(userInput);
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
					wipe(restart);
				}

				infile.close();
				escape = restart;
				break;

			/*============================================================================*/
			case 2:
				
				clearScreen();
				searchTerm = "money";
				count = 0;

				infile.open("sampleTweets.csv");
				cout << "Counting tweets that mention money:" << endl;
				while (!infile.eof()) {
					while (getline(infile, line)) {
						if ((offset = line.find(searchTerm, 0)) != string::npos) {
							count++;
						}
					}
				}

				cout << count << " tweets in total." << endl;
				cout << "Press 0 to search again or any other number to exit." << endl;
				cin >> restart;
				while (cin.fail()) {
					wipe(restart);
				}

				infile.close();
				escape = restart;
				break;

			/*============================================================================*/
			case 3:
				cout << "politics" << endl;
				escape = true;
				break;

			/*============================================================================*/
			case 4:
				cout << "paris" << endl;
				escape = true;
				break;

			/*============================================================================*/
			case 5:
				cout << "dreamworks" << endl;
				escape = true;
				break;

			/*============================================================================*/
			case 6:
				cout << "uber" << endl;
				escape = true;
				break;

			/*============================================================================*/
			case 7:
				cout << "custom search" << endl;
				escape = true;
				break;

			/*============================================================================*/
			case 8:
				cout << "date" << endl;
				escape = true;
				break;

			/*============================================================================*/
			case 9:
				clearScreen();
				infile.open("sampleTweets.csv");
				cout << "Printing all tweets:" << endl;
				while (!infile.eof()) {
					getline(infile, line);
					cout << line << endl;
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