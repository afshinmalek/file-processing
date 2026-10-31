#include <fstream>
#include <limits>
#include <sstream>
#include <stdexcept>

using namespace std;

std::string findHighestTotalSensor(const std::string &filename) {
  ifstream ifile(filename);
  if (!ifile) {
    throw runtime_error("couldn't open the file " + filename);
  }

  int max = numeric_limits<int>::lowest();
  string maxName = "";

  string line;
  while (getline(ifile, line)) {
    if (line.empty())
      continue;

    stringstream ss(line);
    string name;
    ss >> name;

    int data;
    int sum = 0;
    while (ss >> data) {
      sum += data;
    }
    if (sum > max) {
      max = sum;
      maxName = name;
    }
  }
  return maxName;
}