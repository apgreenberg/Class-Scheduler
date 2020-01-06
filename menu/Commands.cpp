#include "Commands.h"
void Commands::mainmenu(School* s) {
  cout << "To manage students, type 'students' " << endl << "To manage teachers, type 'teachers'" << endl << "To manage classes, type 'classes'" << endl << "To manage rooms, type 'rooms'" << endl << "To exit the program, type 'exit'" << endl;
  string message;
  getline(cin, message);
  if (message == "students") {
    system("cls");
    studentMenu(s);
  } else if (message == "teachers") {
    findTeacher(s);
    addTeachers(s);
  } else if (message == "classes") {
    findClass(s);
    addClasses(s);
  } else if (message == "rooms") {
    findRoom(s);
    addRooms(s);
  } else if (message == "exit") {
    return;
  } else {
    system("cls");
    cout << "You didn't enter a valid command. Please try again" << endl;
    mainmenu(s);
  }
}
#include "StudentMenu.cpp"
#include "TeacherMenu.cpp"
#include "ClassMenu.cpp"
#include "RoomMenu.cpp"
#include "SaveSchool.cpp"
void Commands::addTeachers(School *s) {
  cout << "Please enter the teacher's full name:" << endl;
  string name;
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
  cout << "Here is a list of the current classes at this school:" << endl;
  /** s->printClasses();
  cout << "Please enter the class codes of the classes that this teacher can teach" << endl;
  */
  s->addTeacher(firstName, middleName, lastName, vector<int>{100});
  cout << "Teacher successfully added!" << endl;
  cout << "To add another teacher, press enter, otherwise type 'exit' to return to the Main Menu" << endl;
  string message;
  getline(cin, message);
  if (message == "exit") {
    mainmenu(s);
  } else {
    addTeachers(s);
  }
}
void Commands::findTeacher(School* s) {

}
void Commands::addClasses(School *s) {}
void Commands::findClass(School* s) {

}
void Commands::addRooms(School *s) {}
void Commands::findRoom(School* s) {

}
