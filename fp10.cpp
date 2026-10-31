#include <fstream>
#include <stdexcept>

using namespace std;

void trim(string &line) {
  size_t ind = line.find_last_not_of(' ');
  if (ind == std::string::npos) {
    line = "";
  } else {
    line = line.substr(0, ind + 1);
  }
}

double totalDepartmentSalary(const std::string &filename,
                             const std::string &targetDept) {
  ifstream ifile(filename);
  if (!ifile) {
    throw runtime_error("couldn't open the file " + filename);
  }

  string line;
  double total = 0.0;
  while (getline(ifile, line)) {
    if (line.empty() || line.length() < 37) {
      continue;
    }
    string dep;
    string salary;
    dep = line.substr(24, 12);
    trim(dep);
    salary = line.substr(36);
    trim(salary);
    if (dep == targetDept) {
      double s;
      s = stod(salary);
      total += s;
    }
  }
  return total;
}