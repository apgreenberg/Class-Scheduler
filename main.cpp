#include <iostream>
#include <string>
#include <iterator>
#include "School.cpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::begin;
using std::end;
using std::getline;
int main() {
  School *s = new School();
  string name;
  string testing;
  cout << "Hi new student!" << endl;
  cout << "Please enter your full name" << endl;
  getline(cin,name);
  vector<string> fullName;
  string str;
  for (char x:name) {
    if (x == ' ') {
        fullName.push_back(str);
        str.erase();
      } else {
        str=str+x;
      }
  }
  fullName.push_back(str);
  string firstName = fullName[0];
  string middleName = "";
  string lastName = "";
  if (fullName.size() == 2) {
    lastName = fullName[1];
  } else {
    middleName = fullName[1];
    lastName = fullName[fullName.size()-1];
  }
  s->addStudent(firstName, middleName, lastName);
  s->addTeacher("Lauren", "", "O'Malley", vector<int>{100});
  s->addRoom(230, 1, 32);
  s->addClass(100, "AP Research");
  s->printSchedule(1);
  return 0;
}
