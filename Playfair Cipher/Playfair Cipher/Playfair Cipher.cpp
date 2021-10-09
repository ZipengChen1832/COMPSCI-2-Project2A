#include <iostream>
#include <string>
#include <map>

using namespace std;

string encrypt(char a, char b);
	
string keyword = "PLAYFIRBCDEGHKMNOQSTUVWXZ";
map<char,int> cipherIndex;

int main()
{
	//char table[5][5] = { 'P','L','A','Y','F','I','R','B','C','D','E','G','H','K','M','N','O','Q','S','T','U','V','W','X','Z' };
	//char table[5][5];
	/*int index=0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			table[i][j] = keyword[index++];
		}
	}*/

	//This seciton makes it faster to get a letter's index through the key of a map
	for (int i = 0;i<keyword.length();i++) {
		cipherIndex.insert(pair<char, int>(keyword[i],i));
	}


	string text, encryptedText;
	int textLength=2;
	cout << "Enter the text to encrypt: ";
	cin >> text;
	while (text.length() < 2) {
		cout << "The text must be longer than two letters" << endl;
		cout << "Enter again: ";
		cin >> text;
	}
	while (text.length() % 2 == 1) {
		cout << "The text length must be even" << endl << "Enter again: ";
		cin >> text;
	}

	for (int i = 0; i < text.length(); i+=2) {
		encryptedText += encrypt(text[i], text[i + 1]);
	}

	cout << encryptedText;
}

string encrypt(char a, char b) {
	string result;
	int x = cipherIndex[a], y = cipherIndex[b];
	if (x % 5 == y % 5 || x / 5 == y / 5) {
		//checks if two letters are on the same column or row
		return result + b + a;
	}
	else {
		// find the two letters at the corner of the rectangle
		int X = x - x % 5 + y % 5;
		int Y = y - y % 5 + x % 5;
		
		//letter that comes first comes first
		result = x < y ? result + keyword[X] + keyword[Y] : result + keyword[Y] + keyword[X];
		return result;
	}
}