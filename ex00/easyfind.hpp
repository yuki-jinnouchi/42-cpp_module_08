#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iterator>
#include <stdexcept>

// Exception class for when element is not found
class ElementNotFoundException : public std::exception {
 public:
  virtual const char* what() const throw() {
    return "Element not found in container";
  }
};

// Function template declarations
template <typename T>
typename T::iterator easyfind(T& container, int value);
template <typename T>
typename T::const_iterator easyfind(const T& container, int value);

// Include template implementation
#include "easyfind.tpp"

#endif  // EASYFIND_HPP
