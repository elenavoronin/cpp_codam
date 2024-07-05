#ifndef CONTACT_HPP
#define CONTACT_HPP


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
    void    getInfo(std::string info);
    void    set_first(std::string info);
    void    set_last(std::string info);
    void    set_nickname(std::string info);
    void    set_phone(std::string info);
    void    set_secret(std::string info);

};

#endif