#pragma once

#include <string>

struct Error{
    std::string message;
};

struct OutOfBounds : public Error{
    OutOfBounds():
        Error{"out of bounds"}
    {}
};
