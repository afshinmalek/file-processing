#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>

using namespace std;

double averageInStockPrice(const std::string &filename) {
  ifstream ifile(filename);
  if (!ifile) {
    throw runtime_error("couldn't open the file " + filename);
  }

  string line;
  double sum = 0.0;
  int count = 0;
  double average = 0.0;
  while (getline(ifile, line)) {
    if (line.empty())
      continue;

    stringstream ss(line);
    string token;
    int id;
    string name;
    double price;
    string in;
    getline(ss, token, ',');
    id = stoi(token);
    getline(ss, name, ',');
    getline(ss, token, ',');
    price = stod(token);
    getline(ss, in, ',');
    if (in == "TRUE") {
      count++;
      sum += price;
    }
  }
  if (count == 0) {
    return 0.0;
  }
  average = sum / count;
  return average;
}