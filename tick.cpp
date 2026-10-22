#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <filesystem>

std::string exitMessage[] = {"bye", "Bye", "exit", "Exit", "Bye-Bye", "bye-bye", "bye bye", "Bye Bye"};
int size = sizeof(exitMessage)  / sizeof(exitMessage);
std::string *exitMessagePtr = &exitMessage[size];
bool operator==(const std::string & lhs, std::string * rhs);

void writeFile() {
    std::string userInput;
    std::cout << "Enter any text you want to save to the file : ";
    std::getline(std::cin, userInput);
    std::cin.ignore();
    std::fflush(stdin);
    if (userInput == *exitMessagePtr) {
        std::cout << &exitMessage[size] << std::endl;
        exit(0);
    }
    std::cout <<"[ " << userInput << " ]" << " Text stored successfully" << std::endl;
    std::fstream myFile("userInfo.txt", std::ios::out | std::ios::app);
    if (myFile.is_open()) {
        myFile << userInput << std::endl;
    }else {
        std::cout << "Failed to write on the file" << std::endl;
    }
    myFile.close();
}

void readFile() {
    std::fstream myFile("userInfo.txt", std::ios::in);
    if (myFile.is_open()) {
        std::string line;
        while (std::getline(myFile, line)) {
            std::cout << line << std::endl;
        }
    }else {
        std::cout << "Couldn't open the file" << std::endl;
    }
    myFile.close();
}
int main() {
    int choice;
    do {
        std::cout << "[1] Write into a file" << std::endl;
        std::cout << "[2] Read from a file" << std::endl;
        std::cout << "[3] Exit" << std::endl;
        std::cout << "Choice : ";
        std::cin >> choice;
        std::cin.ignore();
        std::fflush(stdin);

        switch (choice) {
            case 1:
                writeFile();
                break;
            case 2:
                readFile();
                break;
            case 3:
                std::cout << "Bye-Bye" << std::endl;
                exit(0);
            default:
                std::cout << "Invalid choice" << std::endl;
                std::cout << "Please choose from between 1 - 3" << std::endl;
        }

    }while (choice != 3);
    return 0;
}