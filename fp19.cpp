#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;

double getColumnAverage(const std::string &filename,
                        const std::string &targetColumn) {
  ifstream ifile(filename);
  if (!ifile) {
    throw runtime_error("couldn't open the file " + filename);
  }

  string line;
  while (getline(ifile, line)) {
    if (line.empty()) {
      continue;
    }
    break;
  }

  stringstream ss(line);
  string token;
  int i = 0;
  bool found = false;

  while (getline(ss, token, ',')) {
    if (!token.empty() && token.back() == '\r') {
      token.pop_back();
    }

    if (token != targetColumn) {
      i++;
    } else if (token == targetColumn) {
      found = true;
      break;
    }
  }

  if (!found) {
    throw runtime_error("Column not found: " + targetColumn);
  }

  double curTotal = 0.0;
  int k = 0;
  double ave;
  while (getline(ifile, line)) {
    if (line.empty()) {
      continue;
    }
    k++;
    stringstream ss2(line);
    string token2;
    int j = 0;
    while (getline(ss2, token2, ',')) {
      if (i == j) {
        curTotal += stod(token2);
        break;
      }
      j++;
    }
  }
  if (k != 0) {
    ave = curTotal / k;
  } else {
    ave = 0.0;
  }
  return ave;
}

/*
warehouse,quantity,item_code,reorder_threshold
North,45,W-10,10
East,120,W-12,25
West,80,W-14,15
South,15,W-20,5
*/