#include <iostream>
#include <string>
#include <fstream>
#include "boyer.h"

int main() {
	using namespace std;
	string mainString{""};
	string subStr{ "" };
	ifstream fin("input.txt");
	string readString{""};
	while (!fin.eof()) {
		getline(fin, readString);
		mainString += "\n" + readString;
	}
	for (int i{ 0 }; i < mainString.length(); ++i) {
		if (mainString[i + 1] == '\n') {
			if (mainString[i] == '-') {
				mainString.erase(i, 2);
			}
			else {
				mainString[i + 1] = ' ';
			}
		}
	}
	fin.close();
	cout << mainString << "\n\nEnter the string you want to search: ";
	getline(cin, subStr);
	seeekSubStr(mainString, subStr);
	return 0;
}
