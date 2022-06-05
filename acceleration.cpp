#include "acceleration.h"

namespace physics {

Force Acceleration::getForce(float mass) const {
  return Force {x * mass, y * mass};
}

std::string Acceleration::toString() {
  char buf[512];
  sprintf(
    buf,
    "<%.2f, %.2f>",
    x, y
  );
  return std::string(buf);
}

} // namespace physics
