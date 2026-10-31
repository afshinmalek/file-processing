#include <fstream>
#include <iostream>

int sumFile(const std::string &filename) {
  std::ifstream ifile(filename);
  if (!ifile) {
    std::cout << "couldn't open the file" << std::endl;
    return 1;
  }
  int num;
  int sum = 0;
  while (ifile >> num) {
    sum += num;
  }
  std::cout << "sum: " << sum << std::endl;
  ifile.close();
  return sum;
}