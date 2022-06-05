#pragma once

#include <cstdlib>
#include <ctime>

#include "physics.h"
#include "util.h"

using namespace physics;

class Ramp {
  private:
    std::vector<Surface> m_surfaces;

  public:
    Ramp(int n, float lengths) {
      std::srand(std::time(nullptr));

      m_surfaces.reserve(n);
      for (int i = 0; i < n; i++) {
        float deg = Util::lerp(std::rand(), 0, RAND_MAX, 0.0, 90.0);
        m_surfaces.push_back(Surface {deg * DEGREE_TO_RAD, lengths});
      }
    }

    std::string toString();

};
