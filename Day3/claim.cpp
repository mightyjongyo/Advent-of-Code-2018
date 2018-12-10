#include "claim.hpp"


Claim::Claim(std::string claim) {
  //We need to parse the string now. Format is:
  // "#123 @ 3,2: 5x4"
  
  // We're assuming well-defined inputs here
  int at_pos = claim.find('@');
  int comma_pos = claim.find(',');
  int col_pos = claim.find(':');
  int x_pos = claim.find('x');
  // More assumptions on well-formed input. Ignore the #, subtract 1 for the space between @ and last digit
  claim_id = atoi(claim.substr(1, at_pos-1).c_str());
  left_offset = atoi(claim.substr(at_pos+2, comma_pos).c_str());
  top_offset = atoi(claim.substr(comma_pos+1, col_pos).c_str());
  rect_width = atoi(claim.substr(col_pos+2, x_pos).c_str());
  rect_height = atoi(claim.substr(x_pos+1, claim.length()-1).c_str());

  area = rect_width * rect_height;
}

Claim::Claim(int claim_id, int left_offset, int top_offset, int rect_width, int rect_height):
  claim_id(claim_id),
  left_offset(left_offset),
  top_offset(top_offset),
  rect_width(rect_width),
  rect_height(rect_height)
{
  this->area = rect_width * rect_height;
}

std::string Claim::to_string() {
  return "Claim #" + std::to_string(this->claim_id) + " " + \
         std::to_string(this->left_offset) + "," + std::to_string(this->top_offset) + ": " + \
         std::to_string(rect_width) + "x" + std::to_string(rect_height);
}
