#include "Doctor.h"
#include <pqxx/pqxx> 
#include <iostream>

Doctor::Doctor(const std::string& name) : name(name) {}

bool Doctor::saveToDatabase(const std::string& connectionString) {
    try {
        pqxx::connection conn(connectionString);
        pqxx::work txn(conn);

        txn.exec0("INSERT INTO Doctor (name) VALUES (" + txn.quote(name) + ")");
        txn.commit();

        std::cout << "Doctor added successfully.\n";
        return true;
    } catch (const std::exception &e) {
        std::cerr << "Error adding doctor: " << e.what() << '\n';
        return false;
    }
}
