#include <cmath>

#include "physics.h"
#include "force.h"

namespace physics {

std::string Force::toString() {
  char buf[512];
  sprintf(
    buf,
    "<%.2f, %.2f>",
    x, y
  );
  return std::string(buf);
}

float Force::magnitude() {
  return sqrt(x*x + y*y);
}

Acceleration Force::getAcceleration(float mass) const {
  return Acceleration {x / mass, y / mass};
};

} // namespace physics
