#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool IsLoggedIn() {
	string username, password, un, pw;

	cout << "Enter username: "; cin >> username;
	cout << "Enter password: "; cin >> password;

	ifstream read(username + ".txt");
	getline(read, un);
	getline(read, pw);

	if (un == username && pw == password) {
		return true;
	}
	else {
		return false;
	}
}

int main(){  
   int choice;

	cout << "1: Register\n2: Login\nYour choice: "; cin >> choice;
	if (choice == 1) {
		string username, password;
		cout << "Select a username: "; cin >> username;
		cout << "Select a password: "; cin >> password;

		ofstream file;
		file.open(username + ".txt");
		file << username << endl << password;
		file.close();

		main();
	}
	else if(choice == 2){
		bool status = IsLoggedIn();

		if (!status) {
			cout << "Login failed" << endl;
			system("pause");

			return 0;
		}
		else {
			cout << "Login succesful" << endl;
			system("Pause");
			return 1;
		}
	}
}