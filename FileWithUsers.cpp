#include "FileWithUsers.h"

vector <User> FileWithUsers::loadUsersFromTheFile() {
    CMarkup xml;
    User user;
    vector <User> users;

    bool fileExist = xml.Load("users.xml");

    if (!fileExist)
        cout << "No users exist.";
    else {
        /*MCD_STR strXML = xml.GetDoc();
        xml.SetDoc(strXML);
        //xml.SetDoc(csXML);
        //xml.ResetPos();
        xml.FindElem();
        xml.IntoElem();
        while ( xml.FindElem("User")) {
            xml.IntoElem();
            xml.FindElem( "UserId" );
            int nUserId = atoi(MCD_2PCSZ(xml.GetData()));
            xml.FindElem( "Name" );
            MCD_STR strName = xml.GetChildData();
            users.push_back(user);
            xml.OutOfElem();
        }*/
        MCD_STR strXML = xml.GetDoc();
        xml.SetDoc(strXML);

        xml.FindElem(); // root Users element
        xml.IntoElem(); // inside Users

        int userId;
        while ( xml.FindElem("User") ) {
            xml.IntoElem();
            xml.FindElem("UserId");
            user.setUserId(atoi(MCD_2PCSZ(xml.GetData())));
            xml.FindElem( "Name" );
            MCD_STR strName = xml.GetData();
            user.setName(strName);
            xml.FindElem( "Surname" );
            MCD_STR strSurname = xml.GetData();
            user.setSurname(strSurname);
            xml.FindElem( "Login" );
            MCD_STR strLogin = xml.GetData();
            user.setLogin(strLogin);
            xml.FindElem( "Password" );
            MCD_STR strPassword = xml.GetData();
            user.setPassword(strPassword);

            users.push_back(user);
            xml.OutOfElem();
        }
    }
    return users;
}

void FileWithUsers::saveNewUserToTheFile(User user) {
    CMarkup xml;

    bool fileExist = xml.Load("users.xml");

    if (!fileExist) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem( "Users" );
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.getUserId());
    xml.AddElem("Name", user.getName());
    xml.AddElem("Surname", user.getSurname());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());

    xml.Save("users.xml"); //plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);
}

void FileWithUsers::saveAllUsersToTheFile(vector <User> &users) {
    User user;
    CMarkup xml;
    bool fileExist = xml.Load("users.xml");

    int userId;
    string name, surname, login, password;

    if (fileExist) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem( "Users" );
    }

    for (vector <User>:: iterator itr = users.begin(); itr != users.end(); itr++) {

        xml.FindElem();
        xml.IntoElem();
        xml.AddElem("User");
        xml.IntoElem();
        userId = itr -> getUserId();
        xml.AddElem("UserId", userId);
        name = itr -> getName();
        xml.AddElem("Name", name);
        surname = itr -> getSurname();
        xml.AddElem("Surname", surname);
        login = itr -> getLogin();
        xml.AddElem("Login", login);
        password = itr -> getPassword();
        xml.AddElem("Password", password);

        xml.OutOfElem();
        xml.OutOfElem();
    }
    xml.Save("users.xml");
}
