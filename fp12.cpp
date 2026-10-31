#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;

int countProjectsWithTag(const std::string &filename,
                         const std::string &targetTag) {

  ifstream ifile(filename);
  if (!ifile) {
    throw runtime_error("couldn't find the file " + filename);
  }

  int count = 0;
  string line;
  while (getline(ifile, line)) {
    if (line.empty()) {
      continue;
    }

    stringstream ss(line);
    string token;
    while (getline(ss, token, '|')) {

      stringstream ss2(token);
      string token2;
      while (getline(ss2, token2, ',')) {
        if (token2 == targetTag) {
          count++;
          break;
        }
      }
    }
  }

  return count;
}

/*
Treating Every Field as Tags:
By running while (getline(ss, token, '|')), your code runs the comma-splitting
logic on every column (id, name, tags, and budget). If a project's name or
description contains the target tag, it gets treated as a tag.

Double-Counting the Same Row:
The break; statement only terminates the inner loop (while (getline(ss2, token2,
','))). The outer loop (while (getline(ss, token, '|'))) continues running for
the remaining columns. If project_name matched and tags also matched, count
would increment twice for a single project.*/

/*
string idStr, name, tagsString, budgetStr;
getline(ss, idStr, '|');
getline(ss, name, '|');
getline(ss, tagsString, '|');
getline(ss, budgetStr, '|');

// Now parse ONLY the tags field
stringstream ssTags(tagsString);
string tag;
while (getline(ssTags, tag, ',')) {
  if (tag == targetTag) {
    count++;
    break; // Safe: only one match per project row
  }
}*/
