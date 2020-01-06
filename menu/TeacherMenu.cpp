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
