#include "Span.hpp"

#include <limits>

// Orthodox Canonical Form implementation
Span::Span() {
  maxSize = 0;
  numbers = std::vector<int>();
}

Span::~Span() {}

Span::Span(const Span& other) {
  maxSize = other.maxSize;
  numbers = other.numbers;
}

Span& Span::operator=(const Span& other) {
  if (this != &other) {
    maxSize = other.maxSize;
    numbers = other.numbers;
  }
  return *this;
}

Span::Span(unsigned int n) {
  maxSize = n;
  numbers = std::vector<int>();
}


// Member function implementations
void Span::addNumber(int number) {
  if (numbers.size() >= maxSize) {
    throw SpanFullException();
  }
  numbers.push_back(number);
  return;
}

unsigned int Span::shortestSpan(void) const {
  if (numbers.size() < 2) {
    throw NoSpanException();
  }
  // Calculate the shortest span
  std::vector<int> sorted(numbers.begin(), numbers.end());
  std::sort(sorted.begin(), sorted.end());
  unsigned int shortestSpan = std::numeric_limits<unsigned int>::max();
  for (size_t i = 1; i < sorted.size(); ++i) {
    unsigned int span = sorted[i] - sorted[i - 1];
    if (span < shortestSpan)
      shortestSpan = span;
    if (shortestSpan == 0)
      break;
  }
  return shortestSpan;
}

unsigned int Span::longestSpan(void) const {
  if (numbers.size() < 2) {
    throw NoSpanException();
  }
  // Calculate the shortest span
  int maxSpan = *std::max_element(numbers.begin(), numbers.end());
  int minSpan = *std::min_element(numbers.begin(), numbers.end());
  unsigned int longestSpan = maxSpan - minSpan;
  return longestSpan;
}

// Exception implementations
const char* Span::SpanFullException::what() const throw() {
  return "Span is full, cannot add more numbers";
}

const char* Span::NoSpanException::what() const throw() {
  return "No span can be found (need at least 2 numbers)";
}
