#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

int main(int argc, char** argv) {

  if (argc != 2) {
    std::cout << "usage: " << argv[0] << " <input file>" << std::endl;
  }

  std::ifstream input_file;
  input_file.open(argv[1], std::ifstream::in);

  int freq = 0;

  std::unordered_set<int> freq_list;
  //we start with 0
  freq_list.insert(0);

  char  in_buff[256];

  while(1) {
    std::cerr << "IsEOF: " << input_file.eof() << std::endl;
    if (input_file.getline(in_buff, 256)) {
      if (in_buff[0] == '+') { freq += atoi(in_buff+1); }
      else if (in_buff[0] == '-') { freq -= atoi(in_buff+1); }
      std::cout << "Freq: " << freq << std::endl;

      if (freq_list.count(freq) == 1) {
        std::cout << "Found repeat freq: " << freq << std::endl;
        return 0;
      } else {
        freq_list.insert(freq);
      }
    }
    else {
      std::cerr << "EOF, repeating" << std::endl;
      input_file.clear();
      input_file.seekg(0, input_file.beg);
    }
  }
}
