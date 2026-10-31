#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;
int countStudentsInCourse(const std::string &filename,
                          const std::string &targetCourse) {

  ifstream ifile(filename);
  if (!ifile) {
    throw runtime_error("couldn't open the file " + filename);
  }

  int count = 0;
  string line;
  while (getline(ifile, line)) {
    if (line.empty())
      continue;

    stringstream ss(line);
    string id, name, course, gpa;

    getline(ss, id, ':');
    getline(ss, name, ':');
    getline(ss, course, ':');
    getline(ss, gpa, ':');

    stringstream ss2(course);
    string token;
    while (getline(ss2, token, ';')) {
      if (token == targetCourse) {
        count++;
        break;
      }
    }
  }
  return count;
}