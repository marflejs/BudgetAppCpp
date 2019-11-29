#include "UsersFile.h"
#include "Markup.h"

void UsersFile::addUserToFile(User user)
{
    CMarkup xml_users;

    bool usersFileExists = xml_users.Load( "users.xml" );

    if (!usersFileExists)
    {
        xml_users.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml_users.AddElem("Users");
    }

    xml_users.FindElem();
    xml_users.IntoElem();
    xml_users.AddElem("User");
    xml_users.IntoElem();
    xml_users.AddElem("UserId", user.getId());
    xml_users.AddElem("Name", user.getName());
    xml_users.AddElem("Surname", user.getSurname());
    xml_users.AddElem("Login", user.getLogin());
    xml_users.AddElem("Password", user.getPassword());

    xml_users.Save("users.xml");
}

void UsersFile::changeUserPasswordInFile(string newPassword, int idOfLoggedInUser)
{
    CMarkup xml_users;
    bool usersFileExists = xml_users.Load( "users.xml" );
    xml_users.FindElem();
    xml_users.IntoElem();

    while (xml_users.FindElem("User"))
    {
        xml_users.FindChildElem("UserId");

        if (atoi(MCD_2PCSZ(xml_users.GetChildData())) == idOfLoggedInUser)
        {
            xml_users.FindChildElem("Password");
            xml_users.SetChildData(newPassword);
        }
    }
    xml_users.Save("users.xml");
}

vector<User> UsersFile::getUsersFromFile()
{
    User user;
    vector<User> users;
    string informationFromFile = "";
    int numberOfInformationFromFile = 1;

    CMarkup xml_users;

    bool usersFileExists = xml_users.Load( "users.xml" );
    xml_users.FindElem();
    xml_users.IntoElem();

    while (xml_users.FindElem("User"))  //tak dlugo, jak ma userow w pliku
    {
        while (xml_users.FindChildElem())   //tak dlugo, jak dlugo znajduje dzieci danego usera
        {
            informationFromFile = xml_users.GetChildData();

            switch(numberOfInformationFromFile)
            {
            case 1:
                user.setId(atoi(informationFromFile.c_str()));
                break;
            case 2:
                user.setName(informationFromFile);
                break;
            case 3:
                user.setSurname(informationFromFile);
                break;
            case 4:
                user.setLogin(informationFromFile);
                break;
            case 5:
                user.setPassword(informationFromFile);
                break;
            }
            informationFromFile = "";
            numberOfInformationFromFile++;
        }
        numberOfInformationFromFile = 1;
        users.push_back(user);
    }
    return users;
}
