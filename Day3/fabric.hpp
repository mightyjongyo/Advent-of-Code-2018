#include "claim.hpp"

#define FABRIC_X 1000
#define FABRIC_Y 1000

#ifndef __FABRIC_CPP__
#define __FABRIC_CPP__

class Fabric {
  public:
    Fabric();
    ~Fabric(){}
    bool processClaim(Claim&);
    int getCollisions();
  private:
    int _fabric[FABRIC_X][FABRIC_Y];
};

#endif
