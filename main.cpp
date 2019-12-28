#include <iostream>
#include <string>
#include <iterator>
#include "School.cpp"
#include "Commands.cpp"
int main() {
  School *s = new School();
  cout << "Hi there! You just made a new school. What would you like to do now?" << endl;
  Commands c;
  c.mainmenu(s);
  return 0;
}
