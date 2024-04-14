
// #include "zlasdtest/test.hpp"

// #include "zlasdtest/test.hpp"

// /* ************************************************************************** */

// #include <iostream>

// /* ************************************************************************** */

// int main() {
//   std::cout << "Lasd Libraries 2024" << std::endl;
//   lasdtest();
//   return 0;
// }



#include "zlasdtest/test.hpp"

#include "zmytest/test.hpp"

/* ************************************************************************** */

#include <iostream>

/* ************************************************************************** */

int main() {
  std::cout << "Lasd Libraries 2024" << std::endl;
  unsigned long errors{0};
  try {
    lasdtest();
  } catch (unsigned int e) {
    errors = e;
  }
  try {
    mytest();
  } catch (unsigned int e) {
    errors = e;
  }
  return errors;
}