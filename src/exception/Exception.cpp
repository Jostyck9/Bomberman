/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Exception.cpp
*/

#include "Exception.hpp"

bomberException::bomberException(const std::string &message, const std::string &part)
{
    this->message = message;
    this->part = part;
}

const char *bomberException::what() const noexcept
{
    return (this->message.data());
}

std::string const &bomberException::getPart() const
{
    return (this->part);
}