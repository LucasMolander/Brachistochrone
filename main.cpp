#include <iostream>

#include "physics.h"

int main() {
  std::cout << "Hello, world!" << std::endl;

  auto b = physics::Body {3.1, 2.4};
  std::cout << b.toString() << std::endl;

  return 0;
}
