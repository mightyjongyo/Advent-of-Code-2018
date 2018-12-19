#include <string>
#include <iostream>

#ifndef __CLAIM_CPP__
#define __CLAIM_CPP__

class Claim {
  public:
    Claim(std::string claim);
    Claim(int claim_id, int left_offset, int top_offset, int rect_width, int rect_height);
    const std::string to_string();
    int getTopOffset() { return _top_offset; }
    int getLeftOffset() { return _left_offset; }
    int getRectWidth() { return _rect_width; }
    int getRectHeight() { return _rect_height; }
    int getClaimID() { return _claim_id; }
  private:
    int _claim_id;
    int _left_offset;
    int _top_offset;
    int _rect_width;
    int _rect_height;
    int _area;
};

#endif
