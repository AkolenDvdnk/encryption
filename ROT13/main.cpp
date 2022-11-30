#include <limits>
#include <iostream>

std::string rot13(std::string text);

int main(){
    int option;
    std::string message;

    std::cout << "Select an option:\n 1. Entering a string manually.\n 2. Read from a file.\n";
    std::cin >> option; 
    std::cin.ignore();
    switch (option)
    {
    case 1:
        std::getline(std::cin, message);
        std::cout << rot13(message) << std::endl;
        break;
    default:
        
        break;
    }
    
    return 0;
}

std::string rot13(std::string text){
    int i = 0;
    std::string encrypt = "";

    while (text[i]){
        if (isupper(text[i])){
            encrypt += (text[i] - 'A' + 13) % 26 + 'A';
            i++;
        } else if (islower(text[i])){
            encrypt += (text[i] - 'a' + 13) % 26 + 'a';
            i++;
        } else if (text[i] == ' '){
            encrypt += text[i];
        } else{
            encrypt += text[i];
        }
    }
    
    return encrypt;
}