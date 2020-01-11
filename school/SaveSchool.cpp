#include <fstream>
using std::ofstream;
string School::getClassScheduleCSV(Student *student) {
    return "";
}
string School::getPeriodsCSV() {
  string toReturn;
  for (int i = 0; i < periods; i++) {
    toReturn += std::to_string(i+1) + ",";
  }
  return toReturn;
}
void School::saveSchool() {
  ofstream schoolFile;
  schoolFile.open(getName() + "_overview.csv");
  schoolFile << "# of class periods/day,# of students enrolled,# of teachers,# of classes,# of rooms\n";
  schoolFile << getPeriods() << "," << getStudents().size() << "," << getTeachers().size() << "," << getClasses().size() << "," << getRooms().size() << "\n" << endl;
  schoolFile.close();
  saveStudents();
}
void School::saveStudents() {
  ofstream studentFile;
  studentFile.open(getName() + "_students.csv");
  studentFile << "ID,First Name,Middle Name,Last Name,Period:" << getPeriodsCSV() << "Class Requests\n";
  for (auto student : students) {
    studentFile << student->getId() << "," << student->getFirstName() << "," << student->getMiddleName() << "," << student->getLastName() << ",," << getClassScheduleCSV(student) << "\n";
  }
  studentFile.close();
}
