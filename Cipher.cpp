#include <iostream>
#include <fstream>
#include <sstream>
#include <Windows.h>



using namespace std;

int main()
{
	char message[100], ch;
	int i, key;

	cout << "Enter a message to encrypt: ";
	cin.getline(message, 100);
	cout << "Enter key: ";
	cin >> key;

	ofstream myfile;
	myfile.open("My Ciphered Text.txt");

	for (i = 0; message[i] != '\0'; ++i) {
		ch = message[i];

		if (ch >= 'a' && ch <= 'z') {
			ch = ch + key;

			if (ch > 'z') {
				ch = ch - 'z' + 'a' - 1;
			}
			
			message[i] = ch;
		}
		else if (ch >= 'A' && ch <= 'Z') {
			ch = ch + key;

			if (ch > 'Z') {
				ch = ch - 'Z' + 'A' - 1;
			}
			
			message[i] = ch;
		}
	}
	int barl = 70;
	cout << "\nWait Patiently As We Encrypt Your Message!\n" << endl;
	cout << "[";
	for (int i = 0; i < barl; i++) {
		Sleep(50);
		cout << ":";
	}
	cout << "]";
	myfile << "Encrypted Message: " << message << "\t Key: " << key;
	cout << "\n\n\nEncrypted message: " << message << "\n\n\n";

	return 0;
}
