#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>

double calculateActiveAverage(const std::string &filename) {
  std::ifstream ifile(filename);
  if (!ifile) {
    throw std::runtime_error("couldn't open the file " + filename);
  }
  std::string line;
  int count = 0;
  double sum = 0;
  double average = 0;
  while (getline(ifile, line)) {
    if (line.empty()) {
      continue;
    }
    std::stringstream ss(line);
    std::string token;
    int id;
    std::string name;
    double score;
    std::string status;
    getline(ss, token, ',');
    id = stoi(token);
    getline(ss, name, ',');
    getline(ss, token, ',');
    score = stod(token);
    getline(ss, status, ',');
    if (status == "ACTIVE") {
      count++;
      sum += score;
    }
  }
  if (count == 0) {
    return 0.0;
  }
  average = sum / count;
  return average;
}