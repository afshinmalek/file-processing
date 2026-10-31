#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;

int countServersWithService(const std::string &filename,
                            const std::string &targetService) {
  ifstream ifile(filename);
  if (!ifile) {
    throw runtime_error("couldn't open the file " + filename);
  }

  string line;
  int count = 0;
  while (getline(ifile, line)) {
    if (line.empty()) {
      continue;
    }

    stringstream ss(line);
    string id, ip, services, uptime;

    getline(ss, id, '#');
    getline(ss, ip, '#');
    getline(ss, services, '#');
    getline(ss, uptime, '#');

    stringstream ss2(services);
    string token;
    while (getline(ss2, token, '/')) {
      if (token == targetService) {
        count++;
        break;
      }
    }
  }
  return count;
}