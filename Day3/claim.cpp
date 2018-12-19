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
  _claim_id = atoi(claim.substr(1, at_pos-1).c_str());
  _left_offset = atoi(claim.substr(at_pos+2, comma_pos).c_str());
  _top_offset = atoi(claim.substr(comma_pos+1, col_pos).c_str());
  _rect_width = atoi(claim.substr(col_pos+2, x_pos).c_str());
  _rect_height = atoi(claim.substr(x_pos+1, claim.length()-1).c_str());

  _area = _rect_width * _rect_height;
}

Claim::Claim(int claim_id, int left_offset, int top_offset, int rect_width, int rect_height):
  _claim_id(claim_id),
  _left_offset(left_offset),
  _top_offset(top_offset),
  _rect_width(rect_width),
  _rect_height(rect_height)
{
  _area = rect_width * rect_height;
}

const std::string Claim::to_string() {
  return "Claim #" + std::to_string(_claim_id) + " " + \
         std::to_string(_left_offset) + "," + std::to_string(_top_offset) + ": " + \
         std::to_string(_rect_width) + "x" + std::to_string(_rect_height);
}
