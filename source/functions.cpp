#include "functions.hpp"


void login(){   // Read Welcome.txt and print in console
    std::string word, login, password = "";
    std::ifstream welcomeFile;

    welcomeFile.open("../data/welcome.txt");
    if(!welcomeFile.is_open())
    {
        std::cout << "Plik welcome.txt nie istnieje";
        exit(EXIT_FAILURE);
    }
    else
    {
        while(!welcomeFile.eof())
        {
            getline(welcomeFile, word);
            if(word.find("Login:") != std::string::npos)
            {
                std::cout << word;
                std::cin >> login;
            }
            else if(word.find("Password:") != std::string::npos)
            {
                char a;

                std::cout << word;
                // When you start typing password istead of seeing what you are typing you will see *
                // You can also use backspace to correct your char
                
                while(1)
                {
                    a = getch();
                    if((a >= 'a' && a <= 'z') || (a >='A' && a <= 'Z') || (a >= '0' && a <= '9'))
                    {
                        password += a;
                        std::cout << "*";
                    }
                    else if(a == '\b')
                    {
                        std::cout << "\b \b";
                    }
                    else if(a == '\r')
                    {
                        std::cout << '\n';
                        break;
                    }
                }

                if(check_user_password(login, password) == true)
                {
                    std::cout << "\nYour login and password are correct\n";
                }
                else
                {
                    std::cout << "\nIncorrect login or password\n";
                }
            }
            else
            {
            std::cout << word << std::endl;
            }
        }
        welcomeFile.close();
    }

} 

// Registration new user and check if exist in file
void registration(){
    std::ifstream welcomeFile;
    std::string sword, slogin, spassword;

    welcomeFile.open("../data/welcome.txt");
    if(!welcomeFile.is_open())
    {
        std::cout << "Plik userdata.txt nie istnieje";
        exit(EXIT_FAILURE);
    }
    else
    {
        while(!welcomeFile.eof())
        {
            getline(welcomeFile, sword);
            if(sword.find("Login:") != std::string::npos)
            {
                std::cout << sword;
                std::cin >> slogin;
                if(check_user_name(slogin))
                {
                    std::cout << "Press any key to continue.\n";
                    std::cin.ignore();
                    std::cin.ignore();
                    system("cls");
                    login();
                    return;
                }
            }
            else if(sword.find("Password:") != std::string::npos)
            {
                std::cout << sword;
                std::cin >> spassword;
            }
            else
            {
                std::cout << sword << std::endl;
            }
        }
        write_to_file(slogin, spassword);
        welcomeFile.close();
    }

}

void write_to_file(const std::string &login, const std::string &password){    // Writing user data to file
    std::fstream userdataFile;

    userdataFile.open("../data/userdata.txt", std::fstream::app);
    if(!userdataFile.is_open())
    {
        std::cout << "Plik userdata.txt nie istnieje";
        exit(EXIT_FAILURE);
    }else
    {
        userdataFile << "Login:" << login << '\n';
        userdataFile << "Password:" << password << '\n';

    }

    userdataFile.close();
}

bool check_user_name(const std::string &login){    // Checking if username exist in file as a login
    std::ifstream userdataFile;
    std::string word;

    userdataFile.open("../data/userdata.txt");
    if(!userdataFile.is_open())
    {
        std::cout << "Plik userdata.txt nie istnieje";
        exit(EXIT_FAILURE);
    }
    else
    {
        while(!userdataFile.eof())
        {
            getline(userdataFile, word);
            if(word == "Login:" + login)
            {
                std::cout << "Username " << login << " exist, please log in\n";
                return true;

            }
        }
        return false;
    }
    userdataFile.close();
}

bool check_user_password(const std::string &login, const std::string &password){    // Checking if user write correct password depending on login
    std::ifstream userdataFile;
    std::string word, pwd;

    userdataFile.open("../data/userdata.txt");
    if(!userdataFile.is_open())
    {
        std::cout << "Plik userdata.txt nie istnieje";
        exit(EXIT_FAILURE);
    }
    else
    {
        do
        {
            getline(userdataFile, word);

        } while (!userdataFile.eof() && word != "Login:" + login);

        if(word == "Login:" + login)
        {
            getline(userdataFile, pwd);
            for(int i = 9; i < pwd.length(); i++)
            {
                if(pwd[i] != password[i-9])
                {
                    return false;           //  If password is diffrent 
                }
            }
            return true;                    //  If password are match
        }

        return false;                       //  If login is incorrect

    }
    userdataFile.close();
}