#include <iostream>
#include <string>

using namespace std;
char getLetter(char letter);
string encrypt(string keyword);
string decrypt(string keyword);

int main()
{
	int option; string text;
	cout << "1.Encrypt\n2.Decrypt\nSelect an option: ";
	cin >> option;
	switch (option)
	{
	case 1: 
		cout << "Enter the text to encrypt: ";
		cin >> text;
		cout << encrypt(text);
		break;
	case 2:
		cout << "Enter the text to decrypt: ";
		cin >> text;
		cout << decrypt(text);
		break;
	default:
		cout << "Invalid option.";
		break;
	}
}


char getLetter(char letter) {
	//this function get the proper letter if the ASCII value is out of the range of 26 capital letters
	while (letter > 90) letter -= 26;
	while (letter < 65) letter += 26;
	return letter;
}

string encrypt(string keyword) {
	string result;
	for (int i = 0; i < keyword.length(); i++) {

		char temp;
		switch (i % 5)
		{
		case 0:
			temp = keyword[i] + 'T' - 'A';
			break;
		case 1:
			temp = keyword[i] + 'I' - 'A';
			break;
		case 2:
			temp = keyword[i] + 'G' - 'A';
			break;
		case 3:
			temp = keyword[i] + 'E' - 'A';
			break;
		case 4:
			temp = keyword[i] + 'R' - 'A';
			break;
		}
		result.push_back(getLetter(temp));
	}
	return result;
}

string decrypt(string keyword) {
	string result;
	for (int i = 0; i < keyword.length(); i++) {

		char temp;
		switch (i % 5)
		{
		case 0:
			temp = keyword[i] - 'T' + 'A';
			break;
		case 1:
			temp = keyword[i] - 'I' + 'A';
			break;
		case 2:
			temp = keyword[i] - 'G' + 'A';
			break;
		case 3:
			temp = keyword[i] - 'E' + 'A';
			break;
		case 4:
			temp = keyword[i] - 'R' + 'A';
			break;
		}
		result.push_back(getLetter(temp));
	}
	return result;
}