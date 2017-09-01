#include <vector>
#include <fstream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <string>
#include <iostream>

std::string fileName = "Users.txt";

std::vector<std::string> newUser(std::string username, std::string password) {
	std::vector<std::string> v;
	v.push_back(username + " " + password);
	return v;
}

void saveUser(std::string username, std::string password) {
	std::fstream users;
	users.open(fileName.c_str(), std::fstream::app);
	std::vector<std::string> vecUsers = newUser(username, password);
	if (users.is_open()) {
		for (auto i : vecUsers) {
			users << i;
		}
		printf("User successfully saved");
		users.close();
	}
	else {
		printf("Failed to save user");
		users.close();
	}
}

void checkUserLists() {
	std::string line;
	char text[500];
	for (int i = 0; i < strlen(text); i++)
		text[i] = 0;
	
	std::ifstream userList;

	userList.open(fileName.c_str());
	if (userList.is_open()) {
		while (getline(userList, line)) {
			strcpy_s(text, line.c_str());
		}
		userList.close();
	}

	for (int i = 0; i < strlen(text); i++)
		printf("User: %s \n", text);
}

int main() {
	getchar();
	return 0;
}