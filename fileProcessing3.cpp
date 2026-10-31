#include <fstream>
#include <iostream>
#include <stdexcept>

int countEvens(const std::string &filename) {
  std::ifstream ifile(filename);
  if (!ifile) {
    throw std::runtime_error("couldn't open the file" + filename);
  }

  int num;
  int count = 0;
  while (ifile >> num) {
    if (num % 2 == 0) {
      count++;
    }
  }
  return count;
}