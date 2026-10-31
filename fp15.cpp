#include <fstream>
#include <limits>
#include <sstream>
#include <stdexcept>

using namespace std;

std::string findTopSpender(const std::string &filename) {
  ifstream ifile(filename);
  if (!ifile) {
    throw runtime_error("couldn't open the file " + filename);
  }

  string line;
  double maxTotal = std::numeric_limits<double>::lowest();
  string maxName = "";
  while (getline(ifile, line)) {
    if (line.empty()) {
      continue;
    }
    string name;
    string c = "customer";
    size_t len = c.length();
    if (line.substr(0, len) == "CUSTOMER") {
      name = line.substr(len + 1);

      double price = 0.0;
      double total = 0.0;
      while (getline(ifile, line)) {
        if (line.empty()) {
          break;
        }
        price = stod(line);
        total += price;
      }
      if (maxTotal < total) {
        maxTotal = total;
        maxName = name;
      }
    }
  }
  return maxName;
}