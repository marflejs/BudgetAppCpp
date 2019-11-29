#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "User.h"
#include "UsersFile.h"
#include "AuxiliaryMethods.h"

using namespace std;

class UserManager
{
    int idOfLoggedInUser;
    vector<User> users;
    UsersFile usersFile;
    User user;

    User getNewUserData();
    int getNewUserId();
    bool doesLoginExist(string login);

public:
    UserManager(string usersFileName) : usersFile(usersFileName) {
        idOfLoggedInUser = 0;
        users = usersFile.getUsersFromFile();
    }
    void signInUser();
    int logInUser();
    void changePasswordOfLoggedInUser();
    void logOffUser();
    bool isUserLoggedIn();
    int getIdOfLoggedInUser();
    void setIdOfLoggedInUser(int newId);
};

#endif
