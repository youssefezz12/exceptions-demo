#include <iostream>
#include "utils.hpp"

int main() {
    std::string email;

 while (true) {
        std::cout << "Enter you email ";
        std::cin >> email;

        try {
            check_email(email);
            std::cout << "Valid email en.\n";
            break;
        }
        catch (const std::invalid_argument& e) {
            std::cout << "Error: " << e.what() << "\n";
            std::cout << "Please try again.\n";
        }
    }

    return 0;
}
