//
// Created by qiu19 on 2024/4/5.
//
class Employee{
private:
    char*name;
    char *address;
    char *city;
    char *postcode;
public:
    char *getName() const {
        return name;
    }

    bool operator==(const Employee &rhs) const {
        return name == rhs.name &&
               address == rhs.address &&
               city == rhs.city &&
               postcode == rhs.postcode;
    }

    bool operator!=(const Employee &rhs) const {
        return !(rhs == *this);
    }
};