#include <iostream>

#include "physics.h"

using namespace physics;

int main() {
  std::cout << "Hello, world!" << std::endl;

  Surface s = Surface {5.0 * DEGREE_TO_RAD};
  Body b = Body {5.0, 3.1, 2.4};
  b.setNormalForce(s);

  Force fNormal = b.getNormalForce();
  Acceleration aNet = b.getNetAcceleration();

  std::cout << s.toString() << std::endl;
  std::cout << b.toString() << std::endl;

  std::cout << "Normal force: " << fNormal.toString() << std::endl;
  std::cout << "Net acceleration: " << aNet.toString() << std::endl;

  return 0;
}
