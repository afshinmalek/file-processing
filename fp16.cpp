#include <fstream>
#include <limits>
#include <sstream>
#include <stdexcept>

using namespace std;

std::string findHighestScoringTeam(const std::string &filename) {
  ifstream ifile(filename);
  if (!ifile) {
    throw runtime_error("couldn't open the file " + filename);
  }
  double maxTotal = numeric_limits<double>::lowest();
  string maxName = "";

  string tag, name;
  double price = 0.0;
  double total = 0.0;

  string line;
  while (getline(ifile, line)) {
    if (line.empty()) {
      if (!name.empty()) {
        if (maxTotal < total) {
          maxTotal = total;
          maxName = name;
        }
      }

      tag = "";
      name = "";
      price = 0.0;
      total = 0.0;
      continue;
    }

    stringstream ss(line);
    ss >> tag;
    if (tag == "TEAM") {
      ss >> name;
    } else {
      price = stod(tag);
      total += price;
    }
  }
  if (maxTotal < total) {
    maxTotal = total;
    maxName = name;
  }
  return maxName;
}
