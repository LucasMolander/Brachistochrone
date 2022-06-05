#pragma once

#include <string>

#include "force.h"


namespace physics {

struct Force;

struct Acceleration {
  float x;
  float y;

  std::string toString();

  Force getForce(float mass) const;
};

const static Acceleration GRAVITY {0.0, -9.80665};

} // namespace physics
