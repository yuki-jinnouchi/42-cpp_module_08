#include <iostream>
#include <list>
#include <stack>

#include "MutantStack.hpp"

int given_main(void);
int given_main_list(void);

void testStackOperations();
void testIteratorFunctionality();
void testStdStackCompatibility();
void runRequiredExample();

int main() {
  std::cout << "=== Given Main Function ===" << std::endl;
  given_main();
  std::cout << "\n=== Given Main Function with std::list ===" << std::endl;
  given_main_list();
  std::cout << "\n=== Stack Operations Tests ===" << std::endl;
  testStackOperations();
  std::cout << "\n=== Iterator Functionality Tests ===" << std::endl;
  testIteratorFunctionality();
  std::cout << "\n=== std::stack Compatibility Tests ===" << std::endl;
  testStdStackCompatibility();
  std::cout << "\n=== Required Example from Subject ===" << std::endl;
  runRequiredExample();
  return 0;
}

int given_main(void) {
  MutantStack<int> mstack;

  mstack.push(5);
  mstack.push(17);

  std::cout << mstack.top() << std::endl;

  mstack.pop();

  std::cout << mstack.size() << std::endl;

  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  // [...]
  mstack.push(0);

  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();

  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
  std::stack<int> s(mstack);
  return 0;
}

int given_main_list(void) {
  std::list<int> mstack;

  mstack.push_back(5);
  mstack.push_back(17);

  std::cout << mstack.back() << std::endl;

  mstack.pop_back();

  std::cout << mstack.size() << std::endl;

  mstack.push_back(3);
  mstack.push_back(5);
  mstack.push_back(737);
  // [...]
  mstack.push_back(0);

  std::list<int>::iterator it = mstack.begin();
  std::list<int>::iterator ite = mstack.end();

  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
  std::list<int> lst(mstack.begin(), mstack.end());
  return 0;
}

void testStackOperations() {
  std::cout << "Testing basic stack operations..." << std::endl;

  MutantStack<int> mstack;
  std::cout << "Empty stack size: " << mstack.size() << std::endl;
  std::cout << "Is empty: " << (mstack.empty() ? "Yes" : "No") << std::endl;

  mstack.push(10);
  mstack.push(20);
  mstack.push(30);

  std::cout << "Stack size after pushing 3 elements: " << mstack.size()
            << std::endl;
  std::cout << "Top element: " << mstack.top() << std::endl;

  mstack.pop();
  std::cout << "Top element after pop: " << mstack.top() << std::endl;
  std::cout << "Size after pop: " << mstack.size() << std::endl;
}

void testIteratorFunctionality() {
  std::cout << "Testing iterator functionality..." << std::endl;

  MutantStack<int> mstack;
  for (int i = 1; i <= 5; ++i) {
    mstack.push(i * 10);
  }

  std::cout << "Forward iteration: ";
  for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end();
       ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  std::cout << "Reverse iteration: ";
  for (MutantStack<int>::reverse_iterator rit = mstack.rbegin();
       rit != mstack.rend(); ++rit) {
    std::cout << *rit << " ";
  }
  std::cout << std::endl;

  // Test const iterators
  const MutantStack<int>& const_ref = mstack;
  std::cout << "Const iterator: ";
  for (MutantStack<int>::const_iterator cit = const_ref.begin();
       cit != const_ref.end(); ++cit) {
    std::cout << *cit << " ";
  }
  std::cout << std::endl;
}

void testStdStackCompatibility() {
  std::cout << "Testing std::stack compatibility..." << std::endl;

  MutantStack<int> mstack;
  mstack.push(100);
  mstack.push(200);
  mstack.push(300);

  // Should be able to copy construct a std::stack from MutantStack
  std::stack<int> regular_stack(mstack);

  std::cout << "Original MutantStack size: " << mstack.size() << std::endl;
  std::cout << "Copied std::stack size: " << regular_stack.size() << std::endl;
  std::cout << "Top of regular_stack: " << regular_stack.top() << std::endl;

  // Test assignment
  MutantStack<int> another_mstack;
  another_mstack = mstack;
  std::cout << "Assigned MutantStack size: " << another_mstack.size()
            << std::endl;
}

void runRequiredExample() {
  std::cout << "Running required example from subject..." << std::endl;
  std::cout << "--- MutantStack output ---" << std::endl;
  given_main();

  std::cout << "\n--- std::list equivalent output ---" << std::endl;
  given_main_list();
}
