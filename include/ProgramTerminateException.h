//
// Created by January on 8/22/2018.
//

#ifndef AMC_PROGRAMTERMINATEEXCEPTION_H
#define AMC_PROGRAMTERMINATEEXCEPTION_H

#include <exception>

namespace AMC {
    class ProgramTerminateException : public std::exception {
    public:
        ProgramTerminateException();
    };
}

#endif //AMC_PROGRAMTERMINATEEXCEPTION_H
