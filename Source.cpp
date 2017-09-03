#pragma warning(disable : 4996);
#include <fstream>
#include <cstdio>
#include <string>
#include <Windows.h>

std::string encryptDecrypt(std::string pw) {
	char key[5] = { 'H', 'F', 'L' , 'A', 'U' };
	std::string output = pw;
 
	for (int i = 0; i < pw.length(); i++) {
		output[i] = (pw[i] ^ key[i % (sizeof(key) / sizeof(key[0]))]);
	}
	return output;
}

void createNewUser(std::string userName, std::string password) {
	//create a directory
	CreateDirectory("C:/UserAccount", NULL);

	std::string user = "C:/UserAccount/" + userName + ".txt";
	std::fstream newUser(user);

	if (newUser.is_open()) {
		printf("Sorry this user already exists!\n");
		newUser.close();
	}
	else{
		newUser.open(user, std::fstream::app);
		std::string  encrypt = encryptDecrypt(password);
		newUser << encrypt << std::endl;
		newUser.close();
	}
}

void readUsers(std::string name) {
	std::string password;
	std::string decrypted;
	std::string location = "C:/UserAccount/"+name+".txt";
	std::ifstream findUser(location);

	if (findUser.is_open()) {
		getline(findUser, password);
	}
	else {
		printf("This user does not exist.");
	}
	findUser.close();
	decrypted = encryptDecrypt(password);
	printf("%s", decrypted.c_str());
}


int main() {
	createNewUser("test", "test");
	readUsers("test");
	getchar();
	return 0;
}