#pragma once
#include <string>
#include <iostream>
using namespace std;

class Tweet {
public:

	static void Count(ifstream &infile, int count, int offset, string lower, string upper, string line) {

		clearScreen();
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
			dashPrint();
		}
		else {
			cout << "Error occured while reading file, please try again" << endl;
		}
		infile.close();
	}

	static void Print(ifstream &infile, int offset, string lower, string upper, string line) {

		clearScreen();
		infile.open("sampleTweets.csv");
		if (infile.good()) {
			cout << "Printing tweets that mention " << lower << ":" << endl;
			while (!infile.eof()) {
				while (getline(infile, line)) {
					if ((offset = line.find(" " + lower + " ", 0)) != string::npos || (offset = line.find(" " + upper + " ", 0)) != string::npos) {
						cout << line << endl;
						Tweet::dashPrint();
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


		clearScreen();
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
			dashPrint();
		}
		else {
			cout << "Error occured while reading file, please try again" << endl;
		}
		infile.close();
	}

	static void clearScreen() {
		for (int i = 0; i < 1000; i++) {
			cout << endl;
		}
	}

	static void dashPrint() {
		cout << endl;
		for (int i = 0; i < 100; i++) {
			cout << "-";
		}
		cout << endl;
	}

	/*

	functions for date searching usingthe to_string method (they don't work right now), get jake's input

	static void Date(ifstream &infile, int count, int offset, int day, int month, int year, string line) {


		clearScreen();
		infile.open("sampleTweets.csv");
		count = 0;
		cout << "Counting tweets... " << endl;
		if (infile.good()) {
			while (!infile.eof()) {
				while (getline(infile, line)) {
					if ((offset = line.find(dateGet(day) + "/" + dateGet(month) + "/" + dateGet(year), 0)) != string::npos) {
						count++;
					}
				}
			}
			cout << count << " Tweets from " << "" + dateGet(day) + "/" + dateGet(month) + "/" + dateGet(year) + "" << endl;
			dashPrint();
		}
		else {
			cout << "Error occured while reading file, please try again" << endl;
		}
		infile.close();
	}

	static string dateGet(int num) {
		return to_string(num);
	}
	*/

};