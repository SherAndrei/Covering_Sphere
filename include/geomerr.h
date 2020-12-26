#pragma once
#include <string>
#include <stdexcept>

namespace geom {

class Error : public std::runtime_error {
 public:
    using std::runtime_error::runtime_error;
};

class IntersectionError : public Error {
 public:
    using Error::Error;
};

}  // namespace geom
