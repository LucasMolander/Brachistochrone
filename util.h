#pragma once

class Util {
  private:
    // None right now
  public:
    static float lerp(float val, float dLo, float dHi, float rLo, float rHi) {
      // float pct = ((float)val - (float)dLo) / ((float)dHi - (float)dLo);
      float ratio = (val - dLo) / (dHi - dLo);
      return rLo + ((rHi - rLo) * ratio);
    }
};
