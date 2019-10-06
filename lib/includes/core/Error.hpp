#pragma once

#include <string>

namespace core {
    struct Error{
        std::string message;
    };

    struct OutOfBounds : public Error{
        OutOfBounds():
            Error{"out of bounds"}
        {}
    };
}
