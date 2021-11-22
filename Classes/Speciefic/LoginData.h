//
// Created by bulba on 23.11.2021.
//

#ifndef KURSACH_OOP_LOGINDATA_H
#define KURSACH_OOP_LOGINDATA_H


#include <string>
class LoginData {
public: std::string login;
    std::string pass;
    LoginData(std::string _login, std::string _pass){
        login=_login;
        pass = _pass;
    }
};


#endif //KURSACH_OOP_LOGINDATA_H
