#include <fstream>
#include <sstream>
using std::ifstream;
using std::stringstream;
bool School::openSchool(string name) {
  ifstream fin;
  fin.open(name+"_overview.csv");
  vector<string> row;
  string line, word;
  int count = 0;
  if (fin.is_open()) {
    while (getline(fin, line)) {
      std::stringstream s(line);
      while (getline(s, word, ',')) {
        // add all the column data
        // of a row to a vector
        row.push_back(word);
      }
      if (count != 0) {
        setPeriods(stoi(row[0]));
      }
      count++;
      row.clear();
    }
  } else {
    return false;
  }
  return openStudents(name);
}
bool School::openStudents(string name) { // returns true if successful, false otherwise
  ifstream fin;
  fin.open(name+"_students.csv");
  vector<string> row;
  string line, word;
  int count = 0;
  if (fin.is_open()) {
    while (getline(fin, line)) {
      std::stringstream s(line);
      while (getline(s, word, ',')) {
        // add all the column data
        // of a row to a vector
        row.push_back(word);
      }
      if (count != 0) {
        addStudentFromFile(stoi(row[0]), row[1], row[2], row[3]);
      }
      count++;
      row.clear();
    }
    return true;
  } else {
    return false;
  }
}
