#include "physics.h"
#include <string>
#include <cstdio>


namespace physics {

std::string Body::toString() {
  char buf[512];
  sprintf(buf, "Body <pos=%.2f,%.2f>", m_pos.x, m_pos.y);
  return std::string(buf);
}

} // namespace physics
