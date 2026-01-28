/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnaranj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 12:46:23 by chnaranj          #+#    #+#             */
/*   Updated: 2026/01/28 12:46:25 by chnaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact
{
    private:
        std::string _firstName;
        std::string _lastName;
        std::string _nickname;
        std::string _phoneNumber;
        std::string _secret;

    public:
        Contact(void);
        ~Contact(void);

        void        setFirstName(const std::string &firstName);
        void        setLastName(const std::string &lastName);
        void        setNickname(const std::string &nickname);
        void        setPhoneNumber(const std::string &phoneNumber);
        void        setSecret(const std::string &secret);

        std::string getFirstName(void) const;
        std::string getLastName(void) const;
        std::string getNickname(void) const;
        std::string getPhoneNumber(void) const;
        std::string getSecret(void) const;
};

#endif
