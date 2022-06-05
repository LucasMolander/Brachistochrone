#pragma once

#include <string>
#include <vector>
#include <cmath>

#include "force.h"

namespace physics {

// --------------------------------------------------
//               Basic mechanics stuff
// --------------------------------------------------
struct Pos {
  float x;
  float y;

  float mag() { return sqrt(x*x + y*y); };

  Pos operator + (const Pos& o) { return Pos{x + o.x, y + o.y}; };

  void operator += (const Pos& o) { x += o.x; y += o.y; };

  std::string toString();
};

struct Velocity {
  float x;
  float y;

  float mag() { return sqrt(x*x + y*y); };

  /** Displacement = Velocity * Time */
  Pos getDisplacement(float t) { return Pos {x*t, y*t}; };

  Velocity operator + (const Velocity& o) { return Velocity{ x + o.x, y + o.y }; };

  void operator += (const Velocity& o) { x += o.x; y += o.y; };

  std::string toString();
};

struct Acceleration {
  float x;
  float y;

  float mag() { return sqrt(x*x + y*y); };

  /** Displacement = (1/2)at^2 */
  Pos getDisplacement(float t) { return Pos{0.5f*x*t*t, 0.5f*y*t*t}; };

  /** Velocity = Acceleration * Time */
  Velocity getVelocity(float t) { return Velocity{x*t, y*t}; };

  std::string toString();

  Force getForce(float mass) const;
};

const static Acceleration GRAVITY {0.0, -9.80665};


const static float PI = 3.141'592'653'589'793'238;

const static float DEGREE_TO_RAD = PI / 180.0;


struct Surface;

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
    Force m_force_normal;
    Force m_force_gravity;

  public:
    Body(float mass, float x, float y) : m_mass{mass}, m_pos{x, y} {
      m_force_gravity = GRAVITY.getForce(mass);
    };

    Force getNetForce();

    Acceleration getNetAcceleration();

    /** Force of gravity, in Newtons */
    Force getFg();

    /** Newtons */
    Force getNormalForce();

    void setNormalForce(Surface& s);

    /** Updates position and velocity. @return Time taken */
    float travel(Surface& s);

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

    float m_length;

  public:
    Surface(float angle, float length) : m_angle{angle}, m_length{length} {};

    Force getNormalForce(Body& b);

    float getLength();

    std::string toString();
};

} // namespace physics
