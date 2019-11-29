#include "User.h"

void User::setId(int newId)
{
    if (newId > 0)
        id = newId;
}

void User::setName(string newName)
{
    name = newName;
}

void User::setSurname(string newSurname)
{
    surname = newSurname;
}

void User::setLogin(string newLogin)
{
    login = newLogin;
}

void User::setPassword(string newPassword)
{
    password = newPassword;
}

int User::getId()
{
    return id;
}

string User::getName()
{
    return name;
}

string User::getSurname()
{
    return surname;
}

string User::getLogin()
{
    return login;
}

string User::getPassword()
{
    return password;
}
