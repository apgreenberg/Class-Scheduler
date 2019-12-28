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
    cout << "You didn't enter a valid command. Please try again" << endl;
    mainmenu(s);
  }
}
void Commands::studentMenu(School* s) {
  cout << "To look at a directory of all the students, type 'dir'" << endl << "To look up student information including class schedules, type 'find'" << endl << "To add a student to the school directory, type 'add'" << endl;
  string message2;
  getline(cin, message2);
  if (message2 == "find") {
    system("cls");
    findStudent(s);
  } else if (message2 == "add") {
    system("cls");
    addStudents(s);
  } else if (message2 == "dir") {
    system("cls");
    studentDirectory(s);
  } else {
    cout << "You didn't enter a valid command. Please try again" << endl;
    studentMenu(s);
  }
}
void Commands::addStudents(School *s) {
  cout << "Please enter the student's full name:" << endl;
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
  if (fullName.size() < 2) {
    cout << "Not a valid name. Try again" << endl;
    addStudents(s);
  }
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
  cout << "Student successfully added!" << endl;
  cout << "To add another student, press enter, otherwise type 'exit' to return to the Main Menu" << endl;
  string message;
  getline(cin, message);
  if (message == "exit") {
    system("cls");
    mainmenu(s);
  } else {
    system("cls");
    addStudents(s);
  }
}
void Commands::findStudent(School* s) {
  cout << "Please enter the ID number of the student you are looking for" << endl;
  string id;
  getline(cin, id);
  std::string::const_iterator it = id.begin();
  while (it != id.end() && std::isdigit(*it)) ++it;
  bool isInt = !id.empty() && it == id.end();
  if (isInt) {
    s->printSchedule(stoi(id));
  } else {
    cout << "Not a valid ID number. Please try again." << endl;
    system("cls");
    findStudent(s);
  }
  cout << "To look up another student, press enter, otherwise type 'exit' to return to the Main Menu" << endl;
  string message;
  getline(cin, message);
  if (message == "exit") {
    system("cls");
    mainmenu(s);
  } else {
    system("cls");
    findStudent(s);
  }
}
void Commands::studentDirectory(School* s) {
  s->printDirectory();
  cout << "Press enter to go to the main menu" << endl;
  cin.ignore();
  mainmenu(s);
}
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
