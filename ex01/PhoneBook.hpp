/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnaranj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 12:50:29 by chnaranj          #+#    #+#             */
/*   Updated: 2026/01/28 12:50:34 by chnaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact _contacts[8];
        int     _index;

        void    print(const Contact &contact) const;

    public:
        PhoneBook(void);
        ~PhoneBook(void);

        void    add(void);
        void    search(void);
};

#endif
