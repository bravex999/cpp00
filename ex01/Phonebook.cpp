#include "Phonebook.hpp"
#include <iostream>
#include <iomanip>
#include <cctype>

static bool isAlphaOnly(const std::string &s)
{
    std::size_t i;

    if (s.empty())
        return false;
    i = 0;
    while (i < s.size())
    {
        if (!std::isalpha(static_cast<unsigned char>(s[i])))
            return false;
        i++;
    }
    return true;
}


static bool specialForDark(const std::string &s)
{
    std::size_t i;

    if (s.empty())
        return false;
    i = 0;
    while (i < s.size())
    {
        if (!std::isalnum(static_cast<unsigned char>(s[i])) && s[i] != ' ')
            return false;
        i++;
    }
    return true;
}

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

    if (_index >= 8)
	{
		std::cout << "Warning: Memory is full. The oldest contact (index " 
			      << (_index % 8) + 1 
				  << ") will be overwritten if you proceed.\n";
	}
	while (true)
    {
        std::cout << "Enter first name: ";
        if (!std::getline(std::cin, first))
		{
		    std::cout << std::endl;
		    return;
		}
        if (isAlphaOnly(first))
            break;
        std::cout << "Field must be an alpha. character\n";
    }
    while (true)
    {
        std::cout << "Enter last name: ";
        if (!std::getline(std::cin, last))
        {
			std::cout << std::endl;
			return;
		}
        if (isAlphaOnly(last))
            break;
        std::cout << "Field must be an alpha. character\n";
    }
    while (true)
    {
        std::cout << "Enter nickname: ";
        if (!std::getline(std::cin, nick))
		{
			std::cout << std::endl;
            return;
		}
        if (hasAlnum(nick))
            break;
        std::cout << "Field must be an alphanumeric character\n";
    }
    while (true)
    {
        std::cout << "Enter phone number: ";
        if (!std::getline(std::cin, phone))
		{
			std::cout << std::endl;
            return;
		}
        if (isAllDigits(phone))
            break;
        std::cout << "Phone number must be numeric and not empty.\n";
    }
    while (true)
    {
        std::cout << "Enter dark secret: ";
        if (!std::getline(std::cin, secret))
		{
			std::cout << std::endl;
            return;
		}
        if (specialForDark(secret))
            break;
        std::cout << "Field must be an alphanumeric character\n";
    }
    pos = _index % 8;
    if (_index >= 8)
        std::cout << "Contact at slot "
                  << (pos + 1) << " has been successfully overwritten.\n";
    _contacts[pos].setFirstName(first);
    _contacts[pos].setLastName(last);
    _contacts[pos].setNickname(nick);
    _contacts[pos].setPhoneNumber(phone);
    _contacts[pos].setSecret(secret);
    _index++;
}

void Phonebook::search(void)
{
    int         n;
    int         i;
    std::string input;

    if (_index < 8)
        n = _index;
    else
        n = 8;
    if (n == 0)
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
    while (i < n)
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
        std::cout << "Select index (1-" << n << "): ";
        if (!std::getline(std::cin, input))
		{
			std::cout << std::endl;
			return;
		}
        
        if (input.size() == 1 &&
            input[0] >= '1' &&
            input[0] <= '0' + n)
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
