#include <iostream>
#include <fstream>
#include <string>
#include "claim.hpp"

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

  char claimline[256];
  while(infile.getline(claimline, 256)) {
    Claim c(claimline);
    std::cout << c.to_string() << std::endl;
  }
}
