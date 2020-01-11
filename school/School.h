#include <iostream>
#include "schoolClass.h"
using std::cout;
using std::endl;
using std::pair;

class School {
public:
  School(string name_) {
    name = name_;
    students = vector<Student*>();
    teachers = vector<Teacher*>();
    rooms = vector<Room*>();
    classes = vector<schoolClass*>();
    requests = vector<vector<pair<schoolClass*, Student*>>>();
    results = vector<vector<pair<schoolClass*, Student*>>>();
    periods = 8;
  }
  School(string name_, int periods_) {
    name = name_;
    students = vector<Student*>();
    teachers = vector<Teacher*>();
    rooms = vector<Room*>();
    classes = vector<schoolClass*>();
    requests = vector<vector<pair<schoolClass*, Student*>>>();
    results = vector<vector<pair<schoolClass*, Student*>>>();
    periods = periods_;
  }
  School(string name_, vector<Student*> students_, vector<Teacher*> teachers_, vector<Room*> rooms_, vector<schoolClass*> classes_, int periods_) :
    name(name_), students(students_), teachers(teachers_), rooms(rooms_), classes(classes_), periods(periods_) {
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
  void addStudentFromFile(int id_, string firstName_, string middleName_, string lastName_) {
    Student* s = new Student(firstName_, middleName_, lastName_, id_);
    students.push_back(s);
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
  void setPeriods(int periods_) {periods = periods_;}
  int getPeriods() {return periods;}
  vector<Student*> getStudents() {return students;}
  vector<Teacher*> getTeachers() {return teachers;}
  vector<schoolClass*> getClasses() {return classes;}
  vector<Room*> getRooms() {return rooms;}
  string getName() {return name;}
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
  schoolClass* getClass(int id) {
    if (classes.size() == 0) {
      cout << "You don't have any classes in your database." << endl;
      return nullptr;
    }
    for (size_t i = 0; i < classes.size(); i++) {
      if (classes[i]->getClassCode() == id) {
        return classes[i];
      }
      if (i == classes.size() - 1) {
        cout << "Class " << id<< " not found!. Try again." << endl;
        return nullptr;
      }
    }
    return nullptr;
  }
  void generateSchedules();
  void assignStudentSchedules();
  void assignTeacherSchedules();
  void saveSchool();
  void saveStudents();
  string getClassScheduleCSV(Student *student);
  string getPeriodsCSV();
  bool openSchool(string name);
  bool openStudents(string name);
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
  string name;
  vector<Student*> students;
  vector<Teacher*> teachers;
  vector<Room*> rooms;
  vector<schoolClass*> classes;
  vector<vector<pair<schoolClass*, Student*>>> requests;
  vector<vector<pair<schoolClass*, Student*>>> results;
  int periods;
};
