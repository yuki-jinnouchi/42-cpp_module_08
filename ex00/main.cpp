#include <deque>
#include <iostream>
#include <list>
#include <vector>

#include "easyfind.hpp"





int main() {
  std::cout << "=== Exercise 00: Easy find ===" << std::endl;

  // Test 1: std::vector - found case
  std::cout << "\n--- Test 1: std::vector ---" << std::endl;
  std::vector<int> vec;
  vec.push_back(1);
  vec.push_back(42);
  vec.push_back(3);

  std::cout << "Vector: ";
  for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  try {
    std::vector<int>::iterator found = easyfind(vec, 42);
    std::cout << "Found 42: " << *found << std::endl;
  } catch (const ElementNotFoundException& e) {
    std::cout << "Error: " << e.what() << std::endl;
  }

  // Test 2: std::list - not found case
  std::cout << "\n--- Test 2: std::list ---" << std::endl;
  std::list<int> lst;
  lst.push_back(10);
  lst.push_back(20);
  lst.push_back(30);

  std::cout << "List: ";
  for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  try {
    std::list<int>::iterator found = easyfind(lst, 99);
    std::cout << "Found 99: " << *found << std::endl;
  } catch (const ElementNotFoundException& e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }

  // Test 3: std::deque - found case
  std::cout << "\n--- Test 3: std::deque ---" << std::endl;
  std::deque<int> deq;
  deq.push_back(100);
  deq.push_back(200);

  std::cout << "Deque: ";
  for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  try {
    std::deque<int>::iterator found = easyfind(deq, 200);
    std::cout << "Found 200: " << *found << std::endl;
  } catch (const ElementNotFoundException& e) {
    std::cout << "Error: " << e.what() << std::endl;
  }

  // Test 4: Empty container
  std::cout << "\n--- Test 4: Empty container ---" << std::endl;
  std::vector<int> empty_vec;

  try {
    easyfind(empty_vec, 1);
    std::cout << "Should not reach here!" << std::endl;
  } catch (const ElementNotFoundException& e) {
    std::cout << "Empty container test passed: " << e.what() << std::endl;
  }

  std::cout << "\n=== Tests completed ===" << std::endl;
  return 0;
}
