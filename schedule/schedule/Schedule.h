#include "iostream"
using namespace std;
class Schedule
{
private:
    string faculty;
    string department;
    string group;
    string subject;
    string classroom;
    string date;
    string time;
    string teacher;

public:
    Schedule(string faculty, string department, string group, string subject,
        string classroom, string date, string time, string teacher) {
        this->faculty = faculty;
        this->department = department;
        this->group = group;
        this->subject = subject;
        this->classroom = classroom;
        this->date = date;
        this->time = time;
        this->teacher = teacher;
    }

    void setFaculty(string faculty) {
        this->faculty = faculty;
    }

    void setDepartment(string department) {
        this->department = department;
    }

    void setGroup(string group) {
        this->group = group;
    }

    void setSubject(string subject) {
        this->subject = subject;
    }

    void setClassroom(string classroom) {
        this->classroom = classroom;
    }

    void setDate(string date) {
        this->date = date;
    }

    void setTime(string time) {
        this->time = time;
    }

    void setTeacher(string teacher) {
        this->teacher = teacher;
    }

    string getFaculty() const {
        return faculty;
    }

    string getDepartment() const {
        return department;
    }

    string getGroup() const {
        return group;
    }

    string getSubject() const {
        return subject;
    }

    string getClassroom() const {
        return classroom;
    }

    string getDate() const {
        return date;
    }

    string getTime() const {
        return time;
    }

    string getTeacher() const {
        return teacher;
    }
};
