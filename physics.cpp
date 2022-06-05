#include <string>
#include <cstdio>
#include <cmath>

#include "physics.h"

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

std::string Pos::toString() {
  char buf[512];
  sprintf(
    buf,
    "<%.2f, %.2f>",
    x, y
  );
  return std::string(buf);
}

std::string Velocity::toString() {
  char buf[512];
  sprintf(
    buf,
    "<%.2f, %.2f>",
    x, y
  );
  return std::string(buf);
}


/**
 * Body stuff.
 */
std::string Body::toString() {
  Force fg = getFg();
  Force nf = getNetForce();
  char buf[512];
  sprintf(
    buf,
    "Body {mass=%.2f, pos=%s, velocity=%s, Fg=%s, Fnet=%s}",
    m_mass,
    m_pos.toString().c_str(),
    m_velocity.toString().c_str(),
    fg.toString().c_str(),
    nf.toString().c_str()
  );
  return std::string(buf);
}

Force Body::getNetForce() {
  Force out {};
  out += getNormalForce();
  out += getFg();
  return out;
}

Acceleration Body::getNetAcceleration() {
  return getNetForce().getAcceleration(m_mass);
}

Force Body::getFg() {
  return m_force_gravity;
}

Force Body::getNormalForce() {
  return m_force_normal;
}

void Body::setNormalForce(Surface& s) {
  m_force_normal = s.getNormalForce(*this);
}

float Body::travel(Surface& s) {
  // Time (t) taken to travel a distance (d) given
  // initial velocity (v) and constant acceleration (a):
  // t = (-v + sqrt(v^2 + 2ad)) / a
  float d = s.getLength();
  float v = m_velocity.mag();
  Acceleration aNet = getNetAcceleration();
  float a = aNet.mag();

  float t = (-v + sqrt(v*v + (2*a*d))) / a;

  // Update position (which uses velocity) before we update velocity
  // d = d0 + v0t + (1/2)at^2
  m_pos += m_velocity.getDisplacement(t) + aNet.getDisplacement(t);

  // v = v0 + at
  m_velocity += aNet.getVelocity(t);

  return t;
}



/**
 * Surface stuff
 */
std::string Surface::toString() {
  char buf[512];
  sprintf(buf, "Surface {angle=%.2f, length=%.2f}", m_angle, m_length);
  return std::string(buf);
}

float Surface::getLength() {
  return m_length;
}

Force Surface::getNormalForce(Body& b) {
  float cosTheta = cos(m_angle);
  float sinTheta = sin(m_angle);
  Force out {
    cosTheta * sinTheta,
    cosTheta * cosTheta
  };

  float magFg = b.getFg().magnitude();
  out *= magFg;
  return out;
}


} // namespace physics
