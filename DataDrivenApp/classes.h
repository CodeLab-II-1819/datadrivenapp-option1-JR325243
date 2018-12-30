#pragma once
#include <string>
#include <iostream>
using namespace std;

class Tweet {
public:
	string date;
	string time;
	string text;


	Tweet(string data);
};

Tweet::Tweet(string data) {
	cout << endl;

}