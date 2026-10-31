#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;

double getColumnSum(const std::string &filename,
                    const std::string &targetColumnName) {
  ifstream ifile(filename);
  if (!ifile) {
    throw runtime_error("couldn't open the file " + filename);
  }

  string line;
  getline(ifile, line);

  stringstream ss(line);
  string token;
  int ind = 0;
  bool found = false;
  while (getline(ss, token, ',')) {
    if (token != targetColumnName) {
      ind++;
      continue;
    } else if (token == targetColumnName) {
      found = true;
      break;
    }
  }
  if (!found) {
    throw runtime_error("Column not found: " + targetColumnName);
  }
  double salary = 0.0;
  double total = 0.0;

  while (getline(ifile, line)) {
    if (line.empty()) {
      continue;
    }

    stringstream ss2(line);
    int i = 0;
    string token2;
    while (getline(ss2, token2, ',') && i < ind) {
      i++;
    }
    salary = stod(token2);
    total += salary;
  }
  return total;
}

/*

id,department,name,salary
101,Sales,Alice,65000.00
102,Engineering,Bob,92000.50
103,Engineering,Charlie,88000.00
104,HR,Diana,71000.25

*/