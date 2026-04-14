#include <iostream>
#include <map>
#include "utils.hpp"

int main() {
    std::map<std::string, std::string> users;
    bool isLoggedIn = false;
    std::string currentUser;

    while (true) {
        int choice;

        if (!isLoggedIn) {
        std::cout << "\n--   MENU   --\n";
          std::cout << "1.sSign Up\n";
         std::cout << "2. Login\n";
            std::cout << "0. Exit\n";
        } else {
         std::cout << "\n--- MENU ---\n";
            std::cout << "3. Logout\n";
          std::cout << "0. Exit\n";
        }

      std::cout << "Enter choice: ";
     std::cin >> choice;

        if (choice == 1 && !isLoggedIn) {
            std::string email, password;

            std::cout << "Enter email: ";
            std::cin >> email; 
            try {
                check_email(email);
            } catch (const std::invalid_argument& e) {
                std::cout << "Error: " << e.what() << "\n";
                continue;
            }

            std::map<std::string, std::string>::iterator it = users.find(email);

            if (it != users.end()) {
                std::cout << "Email already exists.\n";
                continue;
            }

            std::cout << "Enter password: ";
            std::cin >> password;

           users[email] = password;
          std::cout << "Sign up successful.\n";
        }

        else if (choice == 2 && !isLoggedIn) {
            std::string email, password;

            std::cout << "Enter email: ";
            std::cin >> email;
            std::cout << "Enter password: ";
            std::cin >> password;
            std::map<std::string, std::string>::iterator it = users.find(email);

            if (it != users.end() && it->second == password) {
                isLoggedIn = true;
                currentUser = email;
                std::cout << "Login successful.\n";
            } else {
                std::cout << "Invalid email or password.\n";
            }
        }

        else if (choice == 3 && isLoggedIn) {
            isLoggedIn = false;
            currentUser.clear();
            std::cout << "Logged out successfully.\n";
        }

        else if (choice == 0) {
            std::cout << "Exiting program.\n";
            break;
        }

        else {
            std::cout << "Invalid option.\n";
        }
    }

    return 0;
}
