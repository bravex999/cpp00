/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnaranj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 12:46:11 by chnaranj          #+#    #+#             */
/*   Updated: 2026/01/28 12:46:13 by chnaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}
//setters----------------------------------------------------
void Contact::setFirstName(const std::string &firstName)
{
    this->_firstName = firstName;
}

void Contact::setLastName(const std::string &lastName)
{
    this->_lastName = lastName;
}

void Contact::setNickname(const std::string &nickname)
{
    this->_nickname = nickname;
}

void Contact::setPhoneNumber(const std::string &phoneNumber)
{
    this->_phoneNumber = phoneNumber;
}

void Contact::setSecret(const std::string &secret)
{
    this->_secret = secret;
}
// getters-----------------------------------------------------
std::string Contact::getFirstName(void) const
{
    return this->_firstName;
}

std::string Contact::getLastName(void) const
{
    return this->_lastName;
}

std::string Contact::getNickname(void) const
{
    return this->_nickname;
}

std::string Contact::getPhoneNumber(void) const
{
    return this->_phoneNumber;
}

std::string Contact::getSecret(void) const
{
    return this->_secret;
}
