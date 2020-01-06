#include <iostream>
#include <string>
#include <iterator>
#include "School.cpp"
#include "Commands.cpp"
#include "openSchool.cpp"
using std::cout;
using std::cin;
using std::endl;
int main() {
  cout << "Hi there. Welcome to my school schedule generator and optomizer." << endl;
  /** cout << "To open existing school data, enter the name of the school with no spaces." << endl;
  cout << "To make a new school type new." << endl;
  string command;
  cin >> command;
  cout << "Please enter a name for your new school with no spaces." << endl;
  string name;
  cin >> name; */
  School *s = new School();
  Commands c;
  c.mainmenu(s);
  return 0;
}
