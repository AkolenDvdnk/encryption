#include <iostream>
#include <fstream>
#include <sstream>

bool fileOpen(std::string, std::ifstream&);
void filePrint(std::ifstream&);
void fileClose(std::ifstream&);
std::string rot13(std::string);

int main(){
    int option;
    std::string message;
    bool isOpen;
    std::ifstream file;

    isOpen = fileOpen("file.txt", file);

    std::cout << "Select an option:\n 1. Entering a string manually.\n 2. Read from a file.\n";
    std::cin >> option; 
    std::cin.ignore();
    switch (option)
    {
    case 1:
        std::getline(std::cin, message);
        std::cout << rot13(message) << std::endl;
        break;
    case 2:
        if (isOpen){
            filePrint(file);

            fileClose(file);
        } else {
            std::cout << "Error!\n";
        }
    default:
        
        break;
    }

    return 0;
}

bool fileOpen(std::string s, std::ifstream& f){
    f.open(s);
    if (f.is_open())
        return true;
    else 
        return false;
}

void filePrint(std::ifstream& f){
    // std::string s;
    // while (f >> s)
    // std::cout << s;
    std::stringstream buffer;
    buffer << f.rdbuf();

    std::string file_contents;
    file_contents = buffer.str();

    std::cout << file_contents << std::endl;
}

void fileClose(std::ifstream& f){
    f.close();
}

std::string rot13(std::string source){
	std::string transformed;
	for (size_t i = 0; i < source.size(); i++) {
		if (isalpha(source[i])) {
			if ((tolower(source[i]) - 'a') < 14)
				transformed.append(1, source[i] + 13);
			else
				transformed.append(1, source[i] - 13);
		} else {
			transformed.append(1, source[i]);
		}
	}
	return transformed;
}