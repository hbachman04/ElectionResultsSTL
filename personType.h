
#ifndef personType_H
#define personType_H

#include <iostream>
#include <string>

using namespace std;

class personType
{
    friend istream& operator>>(istream&, personType&);
    friend ostream& operator<<(ostream&, const personType&);

public:
    void setName(string first, string last);

    string getFirstName() const;
    string getLastName() const;

    personType(string first = "", string last = "");

    bool operator==(const personType& right) const;
    bool operator!=(const personType& right) const;
    bool operator<=(const personType& right) const;
    bool operator<(const personType& right) const;
    bool operator>=(const personType& right) const;
    bool operator>(const personType& right) const;

protected:
    string firstName;
    string lastName;
};

#endif
