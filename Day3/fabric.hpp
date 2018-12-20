#include "claim.hpp"
#include <map>

#define FABRIC_X 1000
#define FABRIC_Y 1000

#ifndef __FABRIC_CPP__
#define __FABRIC_CPP__

class Fabric {
  public:
    Fabric();
    ~Fabric(){}
    void processClaim(Claim&);
    int getCollisions();
    int getGoodClaim();
  private:
    int _fabric[FABRIC_X][FABRIC_Y];
    std::map<int, bool> _claim_status;
};

#endif
