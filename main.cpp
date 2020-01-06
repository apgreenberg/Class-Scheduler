#include <iostream>
#include <string>
#include <iterator>
#include "school/School.cpp"
#include "menu/Commands.cpp"
using std::cout;
using std::cin;
using std::endl;
int main() {
  cout << "Hi there. Welcome to my school schedule generator and optomizer." << endl;
  Commands c;
  c.schoolSetup();
  return 0;
}
