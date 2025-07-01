#include <iostream>
#include <vector>

#include "Span.hpp"

int given_main(void){
  Span sp = Span(5);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;
  return 0;
}

void testBasicFunctionality(){
  Span sp(5);
  sp.addNumber(1);
  sp.addNumber(3);
  sp.addNumber(7);
  sp.addNumber(9);
  sp.addNumber(11);

  std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
  std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
}

void testExceptionHandling(){
  Span sp(3);
  try {
    sp.addNumber(1);
    sp.addNumber(2);
    sp.addNumber(3);
    sp.addNumber(4);
  } catch (const Span::SpanFullException& e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }

  try {
    Span emptySpan(1);
    emptySpan.shortestSpan();
  } catch (const Span::NoSpanException& e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }

  try {
    Span oneSpan(1);
    oneSpan.addNumber(42);
    oneSpan.longestSpan();
  } catch (const Span::NoSpanException& e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }

}

void testLargeDataSet(){
  Span sp(100000);
  for (int i = 0; i < 100000; ++i) {
    sp.addNumber(i);
  }

  std::cout << "Shortest Span in large data set: " << sp.shortestSpan() << std::endl;
  std::cout << "Longest Span in large data set: " << sp.longestSpan() << std::endl;
}

int main(void) {
  std::cout << "=== Given Main ===" << std::endl;
  given_main();
  std::cout << "\n=== Basic Functionality Test ===" << std::endl;
  testBasicFunctionality();
  std::cout << "\n=== Exception Handling Test ===" << std::endl;
  testExceptionHandling();
  std::cout << "\n=== Large Data Set Test ===" << std::endl;
  testLargeDataSet();
  return 0;
}
