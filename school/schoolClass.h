#include "Student.h"
#include "Teacher.h"
#include "Room.h"

#include <string>
#include <vector>

using std::vector;
using std::string;
class schoolClass {
public:
  schoolClass(int classCode_, string className_) : classCode(classCode_), className(className_) {
    room = nullptr;
    students = vector<Student*>();
    teacher = nullptr;
    period = 0;
    classCapacity = 0;
  }
  schoolClass(Room* room_, vector<Student*> students_, Teacher* teacher_,  int classCode_, string className_, int period_) : room(room_), students(students_), teacher(teacher_), classCode(classCode_), className(className_), period(period_) {
      classCapacity = room->getCapacity();
    };
  void addStudent(Student* s); //adds students while keeping list alphabetized by last name
  vector<Student*> getStudents() {return students;}
  int getNumStudents() {return (int) students.size();}
  int getRemainingSeats() {return classCapacity - (int) students.size();}
  bool hasRemainingSeats() {
    if (classCapacity - (int) students.size() == 0) {
      return false;
    }
    return true;
  }
  void setRoom(Room* r) {room = r;}
  Room* getRoom() {return room;}
  void setTeacher(Teacher* t) {teacher = t;}
  Teacher* getTeacher() {return teacher;}
  void setPeriod(int period_) {period = period_;}
  int getPeriod() {return period;}
  void setClassCode(int code_) {classCode = code_;}
  int getClassCode() {return classCode;}
  void setClassName(string name_) {className = name_;}
  string getClassName() {return className;}
  void setClassCapacity (int capacity_) {classCapacity = capacity_;}
  int getClassCapacity() {return classCapacity;}
private:
  Room* room;
  vector<Student*> students;
  Teacher* teacher;
  int classCode;
  string className;
  int period;
  int classCapacity;
};
