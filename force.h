#pragma once

#include <string>


namespace physics {

struct Acceleration;

struct Force {
  float x;
  float y;

  float magnitude();

  std::string toString();

  void operator *= (float mul) { x *= mul; y *= mul; }

  void operator += (const Force& o) { x += o.x; y += o.y; }

  Acceleration getAcceleration(float mass) const;
};

} // namespace physics
