#include "fabric.hpp"
#include <cstring>
#include <iostream>

Fabric::Fabric() {
  // make sure that the fabric array is init'd to 0
  memset(_fabric, 0, sizeof(int)*1000*1000);
}

// Process a claim
bool Fabric::processClaim(Claim& claim) {
  std::cout << (claim.to_string()) << std::endl;
  for(int x = claim.getTopOffset()-1; x < claim.getTopOffset()-1 + claim.getRectHeight(); ++x) {
    for(int y = claim.getLeftOffset()-1; y <claim.getLeftOffset()-1 + claim.getRectWidth(); ++y) {
      if (_fabric[x][y] == 0) {
        _fabric[x][y] = claim.getClaimID();
      } else {
        // if it's non-zero then we already have something here. It's ok if we re-assign it to -1.
        _fabric[x][y] = -1;
      }
    }
  }
  return true;
}

int Fabric::getCollisions() {
  int collision_count = 0;
  for (int x = 0; x < FABRIC_X; ++x) {
    for (int y = 0; y < FABRIC_Y; ++y) {
      if (_fabric[x][y] == -1) collision_count++;
    }
  }
  return collision_count;
}
