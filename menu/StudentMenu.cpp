void Commands::studentMenu(School* s) {
  cout << "To view a directory of all the students, type 'dir'" << endl
  << "To view, edit or remove data for a specific student, type 'find'" << endl
  << "To add a student to the school directory, type 'add'" << endl
  << "To return to the main menu, type 'exit'" << endl;
  string message2;
  getline(cin, message2);
  if (message2 == "find") {
    system("cls");
    return findStudent(s);
  } else if (message2 == "add") {
    system("cls");
    return addStudents(s);
  } else if (message2 == "dir") {
    system("cls");
    return studentDirectory(s);
  } else if (message2 == "exit") {
    system("cls");
    return mainmenu(s);
  } else {
    system("cls");
    cout << "You didn't enter a valid command. Please try again" << endl;
    return studentMenu(s);
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
    return addStudents(s);
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
  cout << "To add another student, press enter, otherwise type 'exit' to return to the Student Menu" << endl;
  string message;
  getline(cin, message);
  if (message == "exit") {
    system("cls");
    return studentMenu(s);
  } else {
    system("cls");
    return addStudents(s);
  }
}
void Commands::findStudent(School* s) {
  if (s->studentsEmpty()) {
    cout << "You have no students in your directory." << endl;
    cout << "Let's add your first student!" << endl;
    return addStudents(s);
    return;
  }
  cout << "Please enter the ID number of the student you are looking for" << endl;
  string id;
  getline(cin, id);
  std::string::const_iterator it = id.begin();
  while (it != id.end() && std::isdigit(*it)) ++it;
  bool isInt = !id.empty() && it == id.end();
  if (isInt) {
    system("cls");
    Student* student = s->printSchedule(stoi(id));
    if (student == nullptr) {
      return findStudent(s);
    }
    string command;
    cout << "To edit info about this student, type 'edit'" << endl
    << "To remove this student from the database, type 'remove'" << endl
    << "To go back to the student menu, press enter" << endl;
    getline(cin, command);
    if (command == "edit") {

    } else if (command == "remove") {

    } else {
      system("cls");
      return studentMenu(s);
    }
  } else {
    system("cls");
    cout << "Not a valid ID number. Please try again." << endl;
    return findStudent(s);
  }
  cout << "To look up another student, press enter, otherwise type 'exit' to return to the Student Menu" << endl;
  string message;
  getline(cin, message);
  if (message == "exit") {
    system("cls");
    return mainmenu(s);
  } else {
    system("cls");
    return findStudent(s);
  }
}
void Commands::studentDirectory(School* s) {
  s->printDirectory();
  cout << "Press enter to go to the main menu" << endl;
  cin.ignore();
  return mainmenu(s);
}
void Commands::removeStudent(School *s) {
  cout << "Please enter the ID of the student you want to remove" << endl;
  string id;
  getline(cin, id);
}
