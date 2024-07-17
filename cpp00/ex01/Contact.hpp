#pragma once

#include <string>

class Contact {
private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

public:
    Contact();
    ~Contact();

    void            setContact();
    std::string     getFirstName() const;
    std::string     getLastName() const;
    std::string     getNickname() const;
    std::string     getPhoneNumber() const;
    std::string     getDarkestSecret() const;
    void            display(int index) const;
	std::string		truncate(std::string str);

};
