#include "Phonebook.hpp"
#include <iostream>
#include <iomanip>
#include <cctype>

static bool hasAlnum(const std::string &s)
{
    std::size_t i;

    if (s.empty())
        return false;
    i = 0;
    while (i < s.size())
    {
        if (!std::isalnum(static_cast<unsigned char>(s[i])))
            return false;
        i++;
    }
    return true;
}

static bool isAllDigits(const std::string &s)
{
    std::size_t i = 0;

    if (s.empty())
        return false;
    while (i < s.size())
    {
        if (!std::isdigit(s[i]))
            return false;
        i++;
    }
    return true;
}

static std::string formatField(const std::string &s)
{
    std::string r = s;

    if (r.size() > 10)
    {
        r = r.substr(0, 10);
        r[9] = '.';
    }
    return r;
}

Phonebook::Phonebook(void) : _index(0)
{
}

Phonebook::~Phonebook(void)
{
}

void Phonebook::add(void)
{
    std::string first;
    std::string last;
    std::string nick;
    std::string phone;
    std::string secret;
    int         pos;

    while (true)
    {
        std::cout << "Enter first name: ";
        if (!std::getline(std::cin, first))
            return;
        if (hasAlnum(first))
            break;
        std::cout << "Field must be an alphanumeric character\n";
    }
    while (true)
    {
        std::cout << "Enter last name: ";
        if (!std::getline(std::cin, last))
            return;
        if (hasAlnum(last))
            break;
        std::cout << "Field cannot be empty.\n";
    }
    while (true)
    {
        std::cout << "Enter nickname: ";
        if (!std::getline(std::cin, nick))
            return;
        if (hasAlnum(nick))
            break;
        std::cout << "Field cannot be empty.\n";
    }
    while (true)
    {
        std::cout << "Enter phone number: ";
        if (!std::getline(std::cin, phone))
            return;
        if (isAllDigits(phone))
            break;
        std::cout << "Phone number must be numeric and not empty.\n";
    }
    while (true)
    {
        std::cout << "Enter darkest secret: ";
        if (!std::getline(std::cin, secret))
            return;
        if (hasAlnum(secret))
            break;
        std::cout << "Field cannot be empty.\n";
    }
    pos = _index % 8;
    if (_index >= 8)
        std::cout << "Warning: overwriting oldest contact at slot "
                  << (pos + 1) << "/8\n";
    _contacts[pos].setFirstName(first);
    _contacts[pos].setLastName(last);
    _contacts[pos].setNickname(nick);
    _contacts[pos].setPhoneNumber(phone);
    _contacts[pos].setSecret(secret);
    _index++;
}

void Phonebook::search(void)
{
    int         count;
    int         i;
    std::string input;

    if (_index < 8)
        count = _index;
    else
        count = 8;    
    if (count == 0)
    {
        std::cout << "Phonebook is empty.\n";
        return;
    }
    std::cout << "--------------------------------------------\n";
    std::cout << "|" << std::setw(10) << "Index"
              << "|" << std::setw(10) << "First name"
              << "|" << std::setw(10) << "Last name"
              << "|" << std::setw(10) << "Nickname" << "|\n";
    std::cout << "--------------------------------------------\n";
    i = 0;
    while (i < count)
    {
        std::cout << "|" << std::setw(10) << (i + 1)
                  << "|" << std::setw(10) << formatField(_contacts[i].getFirstName())
                  << "|" << std::setw(10) << formatField(_contacts[i].getLastName())
                  << "|" << std::setw(10) << formatField(_contacts[i].getNickname())
                  << "|\n";
        i++;
    }
    std::cout << "--------------------------------------------\n";
    while (true)
    {
        std::cout << "Select index (1-" << count << "): ";
        if (!std::getline(std::cin, input))
            return;
        if (input.size() == 1 &&
            input[0] >= '1' &&
            input[0] <= '0' + count)
        {
            int idx = input[0] - '1';
            print(_contacts[idx]);
            return;
        }
        std::cout << "Invalid index.\n";
    }
}

void Phonebook::print(const Contact &contact) const
{
    std::cout << "First name:   " << contact.getFirstName() << "\n";
    std::cout << "Last name:    " << contact.getLastName() << "\n";
    std::cout << "Nickname:     " << contact.getNickname() << "\n";
    std::cout << "Phone number: " << contact.getPhoneNumber() << "\n";
    std::cout << "Darkest secret: " << contact.getSecret() << "\n";
}
