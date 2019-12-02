#ifndef USERSFILE_H
#define USERSFILE_H

#include <iostream>
#include <vector>
#include <fstream>

#include "User.h"
#include "AuxiliaryMethods.h"

using namespace std;

class UsersFile
{
    const string FILE_NAME;
public:
    UsersFile(string fileName) : FILE_NAME(fileName) {};

    void addUserToFile(User user);
    vector<User> getUsersFromFile();
    void changeUserPasswordInFile(string newPassword, int idOfLoggedInUser);
};

#endif
