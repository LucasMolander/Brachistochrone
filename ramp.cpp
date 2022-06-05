#include "ramp.h"

#include "surface.h"

Ramp::toString() {
  char buf[2048];
  for (const Surface& s : m_surfaces) {

  }

  sprintf(
    buf,
    "Ramp {n=%d, pos=%s, velocity=%s, Fg=%s, Fnet=%s}",
    m_surfaces.size(),
    m_pos.toString().c_str(),
    m_velocity.toString().c_str(),
    fg.toString().c_str(),
    nf.toString().c_str()
  );
  return std::string(buf);
}
