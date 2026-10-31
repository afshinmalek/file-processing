
#include <fstream>
#include <stdexcept>
#include <string>

using namespace std;

int getConfigValue(const std::string &filename, const std::string &targetKey) {
  ifstream ifile(filename);
  if (!ifile) {
    throw runtime_error("couldn't open the file " + filename);
  }

  string line;
  while (getline(ifile, line)) {
    if (line.empty() || line[0] == '#')
      continue;

    size_t ind;
    ind = line.find('=');
    if (ind == std::string::npos) {
      continue;
    }
    string key;
    string strvalue;
    int value;
    key = line.substr(0, ind);

    if (key == targetKey) {
      strvalue = line.substr(ind + 1);
      value = stoi(strvalue);
      return value;
    }
  }
  return -1;
}