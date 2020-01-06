#pragma once
#include <string>
#include <vector>
using std::string;
using std::vector;
class schoolClass;
class Student {
public:
  Student() : firstName(""), middleName(""), lastName(""), id(0) {
    classSchedule = vector<schoolClass*>();
  }
  Student(string firstName_, string middleName_, string lastName_) :
    firstName(firstName_), middleName(middleName_), lastName(lastName_) {
    id = 0;
    classRequests = vector<schoolClass*>();
    classSchedule = vector<schoolClass*>();
  }
  Student(string firstName_, string middleName_, string lastName_, int id_) :
    firstName(firstName_), middleName(middleName_), lastName(lastName_), id(id_) {
    classRequests = vector<schoolClass*>();
    classSchedule = vector<schoolClass*>();
  }
  Student(string firstName_, string middleName_, string lastName_, int id_, vector<schoolClass*> classRequests_) :
    firstName(firstName_), middleName(middleName_), lastName(lastName_), id(id_), classRequests(classRequests_) {
    classSchedule = vector<schoolClass*>();
  };
  void setFirstName(string firstName_) {
    firstName = firstName_;
  }
  string getFirstName() {return firstName;}
  void setMiddleName(string middleName_) {
    middleName = middleName_;
  }
  string getMiddleName() {return middleName;}
  void setLastName(string lastName_) {
    lastName = lastName_;
  }
  string getLastName() {return lastName;}
  void setId(int id_) {
    id = id_;
  }
  int getId() {return id;}
  void setClassSchedule(vector<schoolClass*> classSchedule_) {
    classSchedule = classSchedule_;
  }
  vector<schoolClass*> getClassSchedule() {return classSchedule;}
  vector<schoolClass*> getClassRequests() {return classRequests;}
  void addClassRequest(schoolClass* classToAdd) {return;}
  void removeClassRequest(schoolClass* classToRemove) {return;}
private:
  string firstName;
  string middleName;
  string lastName;
  int id;
  vector<schoolClass*> classRequests;
  vector<schoolClass*> classSchedule;
};
