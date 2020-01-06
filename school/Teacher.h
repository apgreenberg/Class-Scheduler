#include <string>
#include <vector>

using std::vector;
using std::string;
class Teacher {
public:
  Teacher(string firstName_, string middleName_, string lastName_, vector<int> classCodes_)
    : firstName(firstName_), middleName(middleName_), lastName(lastName_), classCodes(classCodes_) {}
  string getTeacherName() {return lastName + ", " + firstName;}
private:
  string firstName;
  string middleName;
  string lastName;
  vector<int> classCodes;
};
