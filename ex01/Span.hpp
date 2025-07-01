#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <stdexcept>
#include <vector>

class Span {
 private:
  // Orthodox Canonical Form members
  Span();

  // Member variables
  std::vector<int> numbers;
  unsigned int maxSize;

 public:
 // Orthodox Canonical Form
  ~Span();
  Span(const Span& other);
  Span& operator=(const Span& other);
  Span(unsigned int n);

  // Member functions
  void addNumber(int number);
  unsigned int shortestSpan(void) const;
  unsigned int longestSpan(void) const;

  // Exception classes
  class SpanFullException : public std::exception {
    public:
      virtual const char* what() const throw();
  };
  class NoSpanException : public std::exception {
    public:
      virtual const char* what() const throw();
  };
};

#endif  // SPAN_HPP
