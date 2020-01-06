#include <iostream>
#include "schoolClass.h"
using std::cout;
using std::endl;
using std::pair;

class School {
public:
  School(int periods_) {
    students = vector<Student*>();
    teachers = vector<Teacher*>();
    rooms = vector<Room*>();
    classes = vector<schoolClass*>();
    requests = vector<vector<pair<schoolClass*, Student*>>>();
    results = vector<vector<pair<schoolClass*, Student*>>>();
    periods = periods_;
  }
  School(vector<Student*> students_, vector<Teacher*> teachers_, vector<Room*> rooms_, vector<schoolClass*> classes_, int periods_) :
    students(students_), teachers(teachers_), rooms(rooms_), classes(classes_), periods(periods_) {
      requests = vector<vector<pair<schoolClass*, Student*>>>();
      results = vector<vector<pair<schoolClass*, Student*>>>();
  }
  ~School() {
    for (auto s: students) {
      delete s;
    }
    students.clear();
    for (auto t: teachers) {
      delete t;
    }
    teachers.clear();
    for (auto c: classes) {
      delete c;
    }
    classes.clear();
    for (auto r: rooms) {
      delete r;
    }
    rooms.clear();
    for (auto req: requests) {
      req.clear();
    }
    requests.clear();
    for (auto res: requests) {
      res.clear();
    }
    results.clear();
  }
  void addStudent(string firstName_, string middleName_, string lastName_) {
    Student* s = new Student(firstName_, middleName_, lastName_);
    s->setId(setNextId());
    students.push_back(s);
    cout << "Student successfully added!" << endl;
    if (middleName_ == "") {
      cout << firstName_ << " " << lastName_ << " has been assigned ID #" << s->getId() << endl;
    } else {
      cout << firstName_ << " " << middleName_ << " " << lastName_ << " has been assigned ID #" << s->getId() << endl;
    }
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
  bool studentsEmpty() {
    if (students.size() == 0) {
      return true;
    }
    return false;
  }
  Student* getStudent(int id) {
    if (students.size() == 0) {
      cout << "You don't have any students in your database." << endl;
      return nullptr;
    }
    for (size_t i = 0; i < students.size(); i++) {
      if (students[i]->getId() == id) {
        cout << "Student Found!" << endl;
        cout << "ID " << students[i]->getId() << ": " << students[i]->getLastName() << ", " << students[i]->getFirstName() << " " << students[i]->getMiddleName() << " has schedule:" << endl;
        return students[i];
      }
      if (i == students.size() - 1) {
        cout << "No student with ID " << id << " exists!" << endl;
        return nullptr;
      }
    }
    return nullptr;
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
  Student* printSchedule(int id) {
    if (students.size() == 0) {
      cout << "You don't have any students in your database." << endl;
      return nullptr;
    }
    Student* find = getStudent(id);
    if (find == nullptr) {
      return find;
    }
    if (!find->getClassSchedule().size()) {
      cout << "NO SCHEDULE GENERATED!" << endl;
      return find;
    }
    for (size_t i = 0; i < find->getClassSchedule().size(); i++) {
      cout << "Period " << i << ": " << find->getClassSchedule()[i]->getClassName() << " with " << find->getClassSchedule()[i]->getTeacher()->getTeacherName() << endl;
    }
    return find;
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
