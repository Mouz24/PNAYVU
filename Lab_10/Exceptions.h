#pragma once
#include <stdexcept>
#include <iostream>
#include <string>

using namespace std;

class ExceptionHandler : public std::logic_error
{
public:
    explicit ExceptionHandler(string message) : std::logic_error(message) {}
};

class FileOpeningException : public ExceptionHandler
{
public:
    explicit FileOpeningException() : ExceptionHandler("Error opening file!") {}
};
