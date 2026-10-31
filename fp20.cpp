#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

vector<string> parseLine(string &line) {
  vector<string> field;
  bool flag = false;
  size_t len = line.length();
  string current;
  for (size_t i = 0; i < len; i++) {
    char c = line[i];
    if (c == '"') {
      flag = !flag;
    } else if (c == ',' && !flag) {
      field.push_back(current);
      current.clear();
    } else {
      current += c;
    }
  }
  field.push_back(current);
  return field;
}

double calculateCategoryTotal(const std::string &filename,
                              const std::string &targetCategory) {
  ifstream ifile(filename);
  if (!ifile) {
    throw runtime_error("couldn't open the file " + filename);
  }

  string line;
  while (getline(ifile, line)) {
    if (line.empty()) {
      continue;
    }
    // discard the first line
    break;
  }
  vector<string> field;
  double total = 0.0;
  while (getline(ifile, line)) {
    if (line.empty()) {
      continue;
    }
    field = parseLine(line);
    if (field.size() < 4) {
      continue;
    }
    if (field[2] == targetCategory) {
      total += stod(field[3]);
    }
  }
  return total;
}

/*

id,name,category,price
101,"Monitor, 27-inch 4K",Electronics,349.99
102,Mechanical Keyboard,Electronics,89.50
103,"Desk, Standing, Electric",Furniture,420.00
104,"Chair, Ergonomic Lumbar",Furniture,180.25
105,"Mouse, Ergonomic, Wireless",Electronics,45.00

*/