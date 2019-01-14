#pragma once
#include <string>
#include <iostream>
using namespace std;

class Tweet {
public:
	
	static int Count(ifstream &infile, int count, int offset, string lower, string upper, string line) {

		infile.open("sampleTweets.csv");
		count = 0;
		cout << "Counting tweets that mention " << lower << ":" << endl;
		if (infile.good()) {
			while (!infile.eof()) {
				while (getline(infile, line)) {
					if ((offset = line.find(" " + lower + " ", 0)) != string::npos || (offset = line.find(" " + upper + " ", 0)) != string::npos) {
						count++;
					}
				}
			}
			return count;
		}
		else {
			cout << "Error occured while reading file, please try again" << endl;
		}
		infile.close();
	}

	static void Print(ifstream &infile, int offset, string lower, string upper, string line) {

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

	static void dashPrint() {
		cout << endl;
		for (int i = 0; i < 100; i++) {
			cout << "-";
		}
		cout << endl;
	}

};