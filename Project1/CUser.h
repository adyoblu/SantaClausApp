#pragma once
#include "IUser.h"
#include "Logger.h"
#include <iostream>

using namespace std;
class CUser : public IUser
{
    Logger* logger;
    int id;
	string username;
	string password;
public:
    //constructori
    CUser() : username(""), password(""), id(1) { logger = Logger::getInstance(); }
    //destructori
    virtual ~CUser() { id = 0; username.clear(); password.clear(); }
    //getteri
    string getUsername() {
        return username;
    }
    string getPassword() {
        return password;
    }
    int getId() {
        return id;
    }
    Logger* getLogger() { return logger; }
    //setteri
    void setId(int x) {
        id = x;
    }
    void setUsername(string x) {
        username.assign(x);
    }
    void setPassword(string x) {
        password.assign(x);
    }
};

