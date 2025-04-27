#include "Doctor.h"
#include <iostream>
#include <cstdlib>

int main() {
    const char* connStr = std::getenv("DB_CONNECTION_STRING");

    std::string doctorName;
    std::cout << "Enter doctor's name: ";
    std::getline(std::cin, doctorName);

    Doctor newDoctor(doctorName);
    if (newDoctor.saveToDatabase(connStr)) {
        std::cout << "Doctor saved.\n";
    } else {
        std::cout << "Failed to save doctor.\n";
    }

    return 0;
}