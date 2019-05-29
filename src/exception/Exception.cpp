/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Exception.cpp
*/

#include "Exception.hpp"

Exception::Exception(const std::string &message, const std::string &part)
{
    this->message = message;
    this->part = part;
}

const char *Exception::what() const noexcept
{
    return (this->message.data());
}

std::string const &Exception::getComponent() const
{
    return (this->part);
}