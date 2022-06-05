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
    "Body {mass=%.2f, pos=%s, Fg=%s, Fnet=%s}",
    m_mass,
    m_pos.toString().c_str(),
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
  Force fNet = getNetForce();
  return fNet.getAcceleration(m_mass);
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




/**
 * Surface stuff
 */
std::string Surface::toString() {
  char buf[512];
  sprintf(buf, "Surface {angle=%.2f}", m_angle);
  return std::string(buf);
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
