#include <iostream>

#include "physics.h"
#include "ramp.h"

using namespace physics;

int main() {
  std::cout << "Hello, world!" << std::endl;

  Surface s = Surface {5.0 * DEGREE_TO_RAD, 2.0};
  Body b = Body {5.0, 3.1, 2.4};
  b.setNormalForce(s);

  Force fNormal = b.getNormalForce();
  Acceleration aNet = b.getNetAcceleration();

  std::cout << s.toString() << std::endl;
  std::cout << b.toString() << std::endl;

  std::cout << "Normal force: " << fNormal.toString() << std::endl;
  std::cout << "Net acceleration: " << aNet.toString() << std::endl;

  float t = b.travel(s);
  std::cout << "Took " << t << " secs to travel." << std::endl;
  std::cout << b.toString() << std::endl;

  Ramp ramp = Ramp {10, 2.0};
  std::cout << ramp.toString() << std::endl;

  return 0;
}
