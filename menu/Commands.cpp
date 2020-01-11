#include "Commands.h"
void Commands::schoolSetup() {
  cout << "To open existing school data from CSV, type 'open'" << endl
  << "To make a new school, type 'new'" << endl;
  string command;
  getline(cin, command);
  if (command == "open") {
    system("cls");
    cout << "Enter the name of your school. Please make sure all the necessary files are in this folder." << endl;
    string name;
    getline(cin, name);
    string nameWithSpaces = name;
    name.erase(remove(name.begin(), name.end(), ' '), name.end());
    School *s = new School(name); // fix number of periods later
    system("cls");
    if (s->openSchool(name)) {
      cout << nameWithSpaces << " successfully imported!" << endl;
      mainmenu(s);
      delete s;
      s = nullptr;
    } else {
      cout << nameWithSpaces << " not found (or some files were missing)!" << endl;
      return schoolSetup();
    }
  } else if (command == "new") {
    system("cls");
    cout << "You will be making a new school!" << endl;
    cout << "Please enter a name for your new school" << endl;
    string name;
    getline(cin, name);
    string nameWithSpaces = name;
    name.erase(remove(name.begin(), name.end(), ' '), name.end());
    cout << "How many class periods does your school have per day (must be between 2-10). Include lunch periods." << endl;
    string periods;
    getline(cin, periods);
    std::string::const_iterator it = periods.begin();
    while (it != periods.end() && std::isdigit(*it)) ++it;
    bool isValid = !periods.empty() && it == periods.end() && stoi(periods) > 1 && stoi(periods) <= 10;
    if (isValid) {
      School *s = new School(name, stoi(periods));
      system("cls");
      cout << nameWithSpaces << " successfully created!" << endl;
      mainmenu(s);
      delete s;
      s = nullptr;
    } else {
      cout << "Number of class periods not valid" << endl;
      cout << "Press enter to try again" << endl;
      cin.ignore();
      system("cls");
      return schoolSetup();
    }
  } else {
    system("cls");
    cout << "Not a valid command. Try again." << endl;
    schoolSetup();
  }
}
void Commands::mainmenu(School* s) {
  cout << "To manage students, type 'students' (partly functional)" << endl
  << "To manage teachers, type 'teachers' (coming soon)" << endl
  << "To manage classes, type 'classes' (coming soon)" << endl
  << "To manage rooms, type 'rooms' (coming soon)" << endl
  << "To save your school, type 'save'" << endl
  << "To exit the program, type 'exit'" << endl;
  string message;
  getline(cin, message);
  if (message == "students") {
    system("cls");
    return studentMenu(s);
  } else if (message == "teachers") {
    findTeacher(s);
    return addTeachers(s);
  } else if (message == "classes") {
    findClass(s);
    return addClasses(s);
  } else if (message == "rooms") {
    findRoom(s);
    return addRooms(s);
  } else if (message == "save") {
    return s->saveSchool();
  } else if (message == "exit") {
    return;
  } else {
    system("cls");
    cout << "You didn't enter a valid command. Please try again" << endl;
    return mainmenu(s);
  }
}
#include "StudentMenu.cpp"
#include "TeacherMenu.cpp"
#include "ClassMenu.cpp"
#include "RoomMenu.cpp"
