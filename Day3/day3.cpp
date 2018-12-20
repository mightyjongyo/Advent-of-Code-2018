#include <iostream>
#include <fstream>
#include <string>
#include "claim.hpp"
#include "fabric.hpp"

int main(int argc, char**argv) {

  if (argc != 2) {
    std::cout << "Usage: " << argv[0] << " <input file>" << std::endl;
    return 1;
  }

  // basic test of claim class
  Claim c("#123 @ 3,2: 5x4");
  std::cout << c.to_string() << std::endl;

  std::ifstream infile;
  infile.open(argv[1], std::ifstream::in);

  // The approach we're gonna take here - we map out a 1000x1000 array.
  // If square is unoccupied, mark it with the claim ID.
  // If the square is non-zero, mark it as -1 instead.
  // I think it's maybe inefficient but I think it's still necessary
  // since we need to be able to track the fabric iteratively over all claims

  Fabric* fab = new Fabric();

  char claimline[256];
  while(infile.getline(claimline, 256)) {
    Claim c(claimline);
    fab->processClaim(c);
  }
  std::cout << "Number of collisions: " << fab->getCollisions() << std::endl;
  std::cout << "Untouched claim: " << fab->getGoodClaim() << std::endl;
}
