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

std::string rot13(std::string source)
{
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
