#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;

int countUsersWithPermission(const std::string &filename,
                             const std::string &targetPermission) {
  ifstream ifile(filename);
  if (!ifile) {
    throw runtime_error("couldn't open the file " + filename);
  }

  string line;
  int total = 0;
  while (getline(ifile, line)) {
    if (line.empty()) {
      continue;
    }

    stringstream ss(line);
    string name;
    getline(ss, name, ';');
    string role;
    getline(ss, role, ';');
    string token;
    while (getline(ss, token, ',')) {
      if (token == targetPermission) {
        total++;
      }
    }
  }
  return total;
}