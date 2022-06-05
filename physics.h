#pragma once

#include <string>
#include <vector>
#include <cmath>

#include "force.h"
#include "acceleration.h"

namespace physics {

struct Pos {
  float x;
  float y;

  std::string toString();
};

struct Velocity {
  float x;
  float y;

  std::string toString();
};


const static float PI = 3.141'592'653'589'793'238;

const static float DEGREE_TO_RAD = PI / 180.0;



/**
 * In order to keep track of the state of an object, we'll just store all of
 * that in a class.
 */
class Body {

  private:
    /** In Kilograms */
    float m_mass;
    Pos m_pos;
    Velocity m_velocity;
    /** In Newtons */
    std::vector<Force> m_forces;

  public:
    Body(float mass, float x, float y) : m_mass{mass}, m_pos{x, y} {};

    Force getNetForce();

    Acceleration getNetAcceleration();

    /** Force of gravity, in Newtons */
    Force getFg();

    /** Force of gravity already accounted for in `getFg()` */
    void setForces(std::vector<Force>& forces);

    std::string toString();
};

class Surface {
  private:
    /**
     * In radians.
     * 0 is the positive X direction, Pi/2 is the negative Y direction.
     * 0 <= `m_angle` <= Pi/2
     */
    float m_angle;

  public:
    Surface(float angle) : m_angle{angle} {};

    Force getNormalForce(Body& b);

    std::string toString();
};

} // namespace physics
