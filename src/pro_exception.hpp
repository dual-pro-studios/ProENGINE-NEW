#ifndef PRO_EXCEPTION_HPP
#define PRO_EXCEPTION_HPP

namespace pro {

    class Exception{};
    class MinorException : public Exception{};
    class FatalException : public Exception{};

}

#endif