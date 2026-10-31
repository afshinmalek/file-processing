#include <fstream>
#include <limits>
#include <sstream>
#include <stdexcept>

using namespace std;
void setInfo(int &maxScore, int &score, int &total, string &name,
             string &maxName) {
  if (!name.empty()) {
    if (total > maxScore) {
      maxScore = total;
      maxName = name;
    }
    name = "";
    total = 0;
    score = 0;
  }
}

std::string findLongestSession(const std::string &filename) {
  ifstream ifile(filename);
  if (!ifile) {
    throw runtime_error("couldn't open the file " + filename);
  }

  string line, tag, name;
  int maxScore = numeric_limits<int>::lowest();
  string maxName = "";
  int score = 0;
  int total = 0;

  while (getline(ifile, line)) {
    if (line.empty()) {
      setInfo(maxScore, score, total, name, maxName);

      continue;
    }

    stringstream ss(line);
    ss >> tag;
    if (tag == "SESSION") {
      setInfo(maxScore, score, total, name, maxName);

      ss >> name;
    } else {
      score = stoi(tag);
      total += score;
    }
  }
  setInfo(maxScore, score, total, name, maxName);

  return maxName;
}
