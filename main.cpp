#include <bits/stdc++.h>
using namespace std;
class Person
{
protected:
    string name;
    int age;
    static int totalCount;
public:
    Person() : name(""), age(0)
    {
        totalCount++;
    }
    Person(string name, int age) : name(name), age(age)
    {
        totalCount++;
    }
    virtual ~Person()
    {
        totalCount--;
    }
    void setName(const string &name)
    {
        this->name = name;
    }

    void setAge(int age)
    {
        this->age = age;
    }
    string getName() const
    {
        return name;
    }

    int getAge() const
    {
        return age;
    }
    virtual void displayInfo() const
    {
        cout << "name: " << name << endl;
        cout << "age: " << age << endl;
    }
    static int getTotalCount()
    {
        return totalCount;
    }
};
int Person::totalCount = 0;
class Student : public Person
{
private:
    string studentId;
    char grade;
public:
    Student() : Person(), studentId(""), grade('F') {}
    Student(string name, int age, string studentId, char grade)
        : Person(name, age), studentId(studentId), grade(grade) {}
    ~Student() {}
    void setStudentId(const string &studentId)
    {
        this->studentId = studentId;
    }

    void setGrade(char grade)
    {
        this->grade = grade;
    }
    string getStudentId() const
    {
        return studentId;
    }

    char getGrade() const
    {
        return grade;
    }
    void displayInfo() const
    {
        Person::displayInfo();
        cout << "student id: " << studentId << endl;
        cout << "grade: " << grade << endl;
    }
};
class Teacher : public Person
{
private:
    string employeeId;
    string subject;
public:
    Teacher() : Person(), employeeId(""), subject("") {}
    Teacher(string name, int age, string employeeId, string subject)
        : Person(name, age), employeeId(employeeId), subject(subject) {}
    ~Teacher() {}
    void setEmployeeId(const string &employeeId)
    {
        this->employeeId = employeeId;
    }

    void setSubject(const string &subject)
    {
        this->subject = subject;
    }
    string getEmployeeId() const
    {
        return employeeId;
    }

    string getSubject() const
    {
        return subject;
    }
    void displayInfo() const
    {
        Person::displayInfo();
        cout << "employee id: " << employeeId << endl;
        cout << "subject: " << subject << endl;
    }
};

int main()
{
    Student student1("ahmed", 21, "a1", 'A');
    Teacher teacher1("samo", 21, "s1", "art");
    cout << "student information:" << endl;
    student1.displayInfo();
    cout << endl;

    cout << "teacher information:" << endl;
    teacher1.displayInfo();
    cout << endl;
    cout << "total person count: " << Person::getTotalCount() << endl;

    return 0;
}
