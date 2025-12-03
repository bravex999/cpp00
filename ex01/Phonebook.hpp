#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class Phonebook
{
    private:
        Contact _contacts[8];
        int     _index;

        void    print(const Contact &contact) const;

    public:
        Phonebook(void);
        ~Phonebook(void);

        void    add(void);
        void    search(void);
};

#endif
