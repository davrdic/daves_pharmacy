#ifndef DOCTOR_H
#define DOCTOR_H

#include <string>

class Doctor {
public:
    Doctor(const std::string& name);

    bool saveToDatabase(const std::string& connectionString);

private:
    std::string name;
};

#endif // DOCTOR_H
