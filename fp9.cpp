#include <fstream>
#include <stdexcept>

using namespace std;

double calculateTotalInventoryValue(const std::string &filename) {
  ifstream ifile(filename);
  if (!ifile) {
    throw runtime_error("couldn't open the file " + filename);
  }

  string line;
  double total = 0.0;
  while (getline(ifile, line)) {
    if (line.empty()) {
      continue;
    }

    double totalP = 0.0;
    string token;
    string name;
    int q;
    double price;
    name = line;
    getline(ifile, token);
    q = stoi(token);
    getline(ifile, token);
    price = stod(token);
    totalP = q * price;
    total += totalP;
  }
  return total;
}