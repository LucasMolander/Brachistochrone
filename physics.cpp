#include <string>
#include <cstdio>
#include <cmath>

#include "physics.h"

namespace physics {

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
    m_mass, m_pos.toString().c_str(), fg.toString().c_str(), nf.toString().c_str()
  );
  return std::string(buf);
}

Force Body::getNetForce() {
  Force out {};
  for (const Force& f : m_forces) {
    out += f;
  }
  out += getFg();
  return out;
}

Acceleration Body::getNetAcceleration() {
  Force fNet = getNetForce();
  return fNet.getAcceleration(m_mass);
}

Force Body::getFg() {
  return GRAVITY.getForce(m_mass);
}

void Body::setForces(std::vector<Force>& forces) {
  m_forces = forces;
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
