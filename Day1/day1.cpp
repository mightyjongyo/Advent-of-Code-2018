#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char** argv) {

  if (argc != 2) {
    std::cout << "usage: " << argv[0] << " <input file>" << std::endl;
  }

  std::ifstream input_file;
  input_file.open(argv[1], std::ifstream::in);

  int freq = 0;

  char  in_buff[256];
  while(input_file.getline(in_buff, 256)) {
    if (in_buff[0] == '+') { freq += atoi(in_buff+1); }
    else if (in_buff[0] == '-') { freq -= atoi(in_buff+1); }
    std::cout << freq << std::endl;
  }

  input_file.close();
}
