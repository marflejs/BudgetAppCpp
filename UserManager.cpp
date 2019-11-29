#include "UserManager.h"
#include "AuxiliaryMethods.h"

User UserManager::getNewUserData()
{
    user.setId(getNewUserId());

    string name, surname, login, password;

    cout << "Podaj imie: ";
    cin >> name;
    user.setName(name);

    cout << "Podaj nazwisko: ";
    cin >> surname;
    user.setSurname(surname);

    do
    {
        cout << "Podaj login: ";
        cin >> login;
        user.setLogin(login);

    } while (doesLoginExist(user.getLogin()) == true);

    cout << "Podaj haslo: ";
    cin >> password;

    user.setPassword(password);

    return user;
}

int UserManager::getNewUserId()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager::doesLoginExist(string login)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UserManager::signInUser()
{
    user = getNewUserData();

    users.push_back(user);

    usersFile.addUserToFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

int UserManager::logInUser()
{
    User user;
    string login = "", password = "";

    cout << endl << "Podaj login: ";
    login = AuxiliaryMethods::getLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getLogin() == login)
        {
            for (int numberOfChances = 3; numberOfChances > 0; numberOfChances--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << numberOfChances << ": ";
                password = AuxiliaryMethods::getLine();

                if (itr -> getPassword() == password)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;

                    system("pause");
                    idOfLoggedInUser = itr -> getId();
                    return idOfLoggedInUser;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return 0;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;
}

void UserManager::changePasswordOfLoggedInUser()
{
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    newPassword = AuxiliaryMethods::getLine();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        if (itr -> getId() == idOfLoggedInUser)
        {
            itr -> setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    usersFile.changeUserPasswordInFile(newPassword, idOfLoggedInUser);
}

void UserManager::logOffUser()
{
    idOfLoggedInUser = 0;
}

bool UserManager::isUserLoggedIn()
{
    if (idOfLoggedInUser > 0)
        return true;
    else
        return false;
}

int UserManager::getIdOfLoggedInUser()
{
    return idOfLoggedInUser;
}

void UserManager::setIdOfLoggedInUser(int newId)
{
    idOfLoggedInUser = newId;
}
