#include "functions.hpp"

int main(){
    short choose;
    
    std::cout << "Choose what you wanna do:\n";
    std::cout << "1) Login\n";
    std::cout << "2) Registration\n";

    std::cin >> choose;
    if(choose == 1)
    {
        login();
    }
    else if(choose == 2)
    {
        registration();
    }
    else
    {
        std::cout << "WTF?!";
    }
}

