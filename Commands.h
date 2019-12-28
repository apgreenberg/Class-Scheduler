#include <iostream>
#include <string>
#include <iterator>
#include <cstdlib>
#include "School.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::begin;
using std::end;
using std::getline;
class Commands {
public:
  void mainmenu(School* s);
  void studentMenu(School *s);
  void addStudents(School* s);
  void findStudent(School *s);
  void studentDirectory(School* s);
  void addTeachers(School* s);
  void findTeacher(School* s);
  void addClasses(School* s);
  void findClass(School* s);
  void addRooms(School* s);
  void findRoom(School* s);
};
