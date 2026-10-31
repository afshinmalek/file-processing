#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;

std::string findTopStudent(const std::string &filename) {
  ifstream ifile(filename);
  if (!ifile) {
    throw runtime_error("couldn't open the file " + filename);
  }

  string line;
  double max = std::numeric_limits<double>::lowest();
  string maxName = "";

  while (getline(ifile, line)) {
    if (line.empty())
      continue;

    stringstream ss(line);
    string token;
    string name;
    ss >> name;
    double score;
    int count = 0;
    double sum = 0.0;
    double average = 0.0;
    while (ss >> score) {
      count++;
      sum += score;
    }
    if (count == 0) {
      average = 0.0;
    } else {
      average = sum / count;
    }
    if (average > max) {
      max = average;
      maxName = name;
    }
  }
  return maxName;
}