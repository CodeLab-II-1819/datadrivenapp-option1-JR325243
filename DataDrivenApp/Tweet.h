#pragma once
#include <string>
#include <iostream>
using namespace std;

class Tweet {
public:

	static void Count(ifstream &infile, int count, int offset, string lower, string upper, string line) {

		system("cls");
		infile.open("sampleTweets.csv");
		count = 0;
		cout << "Counting tweets... " << endl;
		if (infile.good()) {
			while (!infile.eof()) {
				while (getline(infile, line)) {
					if ((offset = line.find(" " + lower + " ", 0)) != string::npos || (offset = line.find(" " + upper + " ", 0)) != string::npos) {
						count++;
					}
				}
			}
			cout << count << " Tweets mention " << lower << endl;
			DashPrint();
		}
		else {
			cout << "Error occured while reading file, please try again" << endl;
		}
		infile.close();
	}

	static void Print(ifstream &infile, int offset, string lower, string upper, string line) {

		system("cls");
		infile.open("sampleTweets.csv");
		if (infile.good()) {
			cout << "Printing tweets that mention " << lower << ":" << endl;
			while (!infile.eof()) {
				while (getline(infile, line)) {
					if ((offset = line.find(" " + lower + " ", 0)) != string::npos || (offset = line.find(" " + upper + " ", 0)) != string::npos) {
						cout << line << endl;
						Tweet::DashPrint();
					}
				}
			}
		}
		else {
			cout << "Error occured while reading file, please try again" << endl;
		}
		infile.close();
	}

	static void Date(ifstream &infile, int count, int offset, string searchTerm, string line) {

		//check for valid input length
		while (searchTerm.length() > 10 || searchTerm.length() < 10) {
			cout << "Date entered is not valid, please try again (DD/MM/YYYY)" << endl;
			cin >> searchTerm;
		}

		//check for invalid characters
		for (int i = 0; i < searchTerm.length(); i++) {
			if (isalpha(searchTerm[i])) {
				cout << "Date entered is not valid, please try again (DD/MM/YYYY)" << endl;
				cin >> searchTerm;
			}
		}

		system("cls");
		infile.open("sampleTweets.csv");
		count = 0;
		cout << "Counting tweets... " << endl;
		if (infile.good()) {
			while (!infile.eof()) {
				while (getline(infile, line)) {
					if ((offset = line.find("" + searchTerm + "", 0)) != string::npos) {
						count++;
					}
				}
			}
			cout << count << " Tweets from " << searchTerm << endl;
			DashPrint();
		}
		else {
			cout << "Error occured while reading file, please try again" << endl;
		}
		infile.close();
	}

	static void DashPrint() {
		cout << endl;
		for (int i = 0; i < 100; i++) {
			cout << "-";
		}
		cout << endl;
	}


};