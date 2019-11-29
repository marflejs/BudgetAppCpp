#ifndef USERSFILE_H
#define USERSFILE_H

#include <iostream>
#include <vector>
#include <fstream>

#include "User.h"
#include "AuxiliaryMethods.h"
#include "XMLFile.h"

using namespace std;

class UsersFile : public XMLFile
{

public:
    UsersFile(string fileName) : XMLFile(fileName) {};

    void addUserToFile(User user);
    vector<User> getUsersFromFile();
    void saveAllUsersInFile(vector<User> users);
    void changeUserPasswordInFile(string newPassword, int idOfLoggedInUser);
};

#endif
