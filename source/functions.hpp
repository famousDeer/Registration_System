#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <Windows.h>


void login();
void registration();
void write_to_file(const std::string &login, const std::string &password);
bool check_user_name(const std::string &login);
bool check_user_password(const std::string &login, const std::string &password);