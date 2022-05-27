#pragma once

#include <string>

namespace physics {

struct Pos {
  float x;
  float y;
};


/**
 * In order to keep track of the state of an object, we'll just store all of
 * that in a class.
*/
class Body {

  private:
    Pos m_pos;

  public:
    Body(float x, float y) : m_pos{x, y} {};

    std::string toString();
};


} // namespace physics
