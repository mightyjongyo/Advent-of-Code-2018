#include <string>
#include <iostream>

class Claim {
  public:
    Claim(std::string claim);
    Claim(int claim_id, int left_offset, int top_offset, int rect_width, int rect_height);
    std::string to_string();
  private:
    int claim_id;
    int left_offset;
    int top_offset;
    int rect_width;
    int rect_height;
    int area;
};
