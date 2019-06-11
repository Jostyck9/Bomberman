/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Exception.hpp
*/

#ifndef _BOMBER_EXCEPTION_HPP
#define _BOMBER_EXCEPTION_HPP

#include <exception>
#include <string>

class bomberException : public std::exception
{
private:
    std::string message;
    std::string part;

public:
    bomberException(std::string const &message, std::string const &part = "Unknown");

    std::string const &getPart() const;
    const char *what() const noexcept override;
};

#endif //_BOMBER_EXCEPTION_HPP