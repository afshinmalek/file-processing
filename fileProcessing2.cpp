#include <fstream>
#include <iostream>
#include <stdexcept>

int countNegative(const std::string &filename) {
  std::ifstream ifile(filename);
  if (!ifile) {
    throw std::runtime_error("couldn't open the file " + filename);
  }
  int count = 0;
  int num;
  while (ifile >> num) {
    if (num < 0) {
      count++;
    }
  }

  return count;
}