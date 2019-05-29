/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Exception.hpp
*/

#ifndef _EXCEPTION_HPP
#define _EXCEPTION_HPP

#include <exception>
#include <string>

class Exception : public std::exception
{
private:
    std::string message;
    std::string part;

public:
    Exception(std::string const &message, std::string const &part = "Unknown");

    std::string const &getComponent() const;
    const char *what() const noexcept override;
};

#endif //_EXCEPTION_HPP