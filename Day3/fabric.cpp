#include "fabric.hpp"
#include <cstring>
#include <iostream>

Fabric::Fabric() {
  // make sure that the fabric array is init'd to 0
  memset(_fabric, 0, sizeof(int)*1000*1000);
}

// Process a claim
void Fabric::processClaim(Claim& claim) {
  // mark it as true since it's the first time
  _claim_status[claim.getClaimID()] = true;
  for(int x = claim.getTopOffset()-1; x < claim.getTopOffset()-1 + claim.getRectHeight(); ++x) {
    for(int y = claim.getLeftOffset()-1; y <claim.getLeftOffset()-1 + claim.getRectWidth(); ++y) {
      if (_fabric[x][y] == 0) {
        _fabric[x][y] = claim.getClaimID();
      } else {
        // mark both this current claim and the overlapping claim as false
        _claim_status[claim.getClaimID()] = false;
        if (_fabric[x][y] != -1) _claim_status[_fabric[x][y]] = false;
        // if it's non-zero then we already have something here. It's ok if we re-assign it to -1.
        _fabric[x][y] = -1;
      }
    }
  }
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

int Fabric::getGoodClaim()
{
  for (auto it = _claim_status.begin(); it != _claim_status.end(); ++it) {
    if (it->second) return it->first;
  }
  return -1;
}
