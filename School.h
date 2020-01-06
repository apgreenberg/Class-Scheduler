#include <iostream>
#include "schoolClass.h"
using std::cout;
using std::endl;
using std::pair;

class School {
public:
  School() {
    students = vector<Student*>();
    teachers = vector<Teacher*>();
    rooms = vector<Room*>();
    classes = vector<schoolClass*>();
    requests = vector<vector<pair<schoolClass*, Student*>>>();
    results = vector<vector<pair<schoolClass*, Student*>>>();
    periods = 0;
  }
  School(vector<Student*> students_, vector<Teacher*> teachers_, vector<Room*> rooms_, vector<schoolClass*> classes_, int periods_) :
    students(students_), teachers(teachers_), rooms(rooms_), classes(classes_), periods(periods_) {
      requests = vector<vector<pair<schoolClass*, Student*>>>();
      results = vector<vector<pair<schoolClass*, Student*>>>();
  }
  void addStudent(string firstName_, string middleName_, string lastName_) {
    Student* s = new Student(firstName_, middleName_, lastName_);
    s->setId(setNextId());
    students.push_back(s);
  }
  void addTeacher(string firstName_, string middleName_, string lastName_, vector<int> classCodes_) {
    Teacher *t = new Teacher(firstName_, middleName_, lastName_, classCodes_);
    teachers.push_back(t);
  }
  void addRoom(int number, int type, int capacity) {
    Room *r = new Room(number, type, capacity);
    rooms.push_back(r);
  }
  void addClass(int classCode_, string className_) {
    schoolClass *c = new schoolClass(classCode_, className_);
    classes.push_back(c);
  }
  int setNextId() {
    return (int) students.size() + 1;
  }
  Student* getStudent(int id) {
    for (size_t i = 0; i < students.size(); i++) {
      if (students[i]->getId() == id) {
        return students[i];
      }
      if (i == students.size() - 1) {
        cout << "No student with ID " << id << " exists!" << endl;
        return nullptr;
      }
    }
  }
  void generateSchedules();
  void assignStudentSchedules();
  void assignTeacherSchedules();
  void printDirectory() {
    cout << "There are " << students.size() << " students in your database" << endl;
    for (size_t i = 0; i < students.size(); i++) {
      cout << "ID " << students[i]->getId() << ": " << students[i]->getLastName() << ", " << students[i]->getFirstName() << " " << students[i]->getMiddleName() << endl;
    }
  }
  void printSchedule(int id) {
  Student* find = nullptr;
    for (size_t i = 0; i < students.size(); i++) {
      if (students[i]->getId() == id) {
        find = students[i];
        break;
      }
      if (i == students.size() - 1) {
        cout << "No student with ID " << id << " exists!" << endl;
        return;
      }
    }
    cout << find->getFirstName() << " " << find->getLastName() << " has schedule:" << endl;
    if (!find->getClassSchedule().size()) {
      cout << "NO SCHEDULE GENERATED!" << endl;
      return;
    }
    for (size_t i = 0; i < find->getClassSchedule().size(); i++) {
      cout << "Period " << i << ": " << find->getClassSchedule()[i]->getClassName() << " with " << find->getClassSchedule()[i]->getTeacher()->getTeacherName() << endl;
    }
  }
private:
  vector<Student*> students;
  vector<Teacher*> teachers;
  vector<Room*> rooms;
  vector<schoolClass*> classes;
  vector<vector<pair<schoolClass*, Student*>>> requests;
  vector<vector<pair<schoolClass*, Student*>>> results;
  int periods;
};
