#include<iostream>
#include<string>
using namespace std;

class person {
protected:
    string name;
    int ID;
    string address;
    string phoneNumber;
    string email;
public:
    person(string n, int id, string addr, string pnum, string mail)
        : name(n), ID(id), address(addr), phoneNumber(pnum), email(mail) {}

    virtual void displayInfo() {
        cout << "Name: " << name << "\nID: " << ID << "\nAddress: "
             << address << "\nPhone: " << phoneNumber << "\nEmail: " << email << endl;
    }

    virtual void updateInfo(string addr, string phone, string mail) {
        address = addr;
        phoneNumber = phone;
        email = mail;
    }
};

class students : public person {
    string coursesEnrolled[3];
    float GPA;
    int enrollmentYear;
public:
    students(string n, int id, string addr, string pnum, string mail,
        float gpa, int e_year) : GPA(gpa), enrollmentYear(e_year),
        person(n, id, addr, pnum, mail) {}

    void enrollCourses() {
        cout << "Enter 3 courses for " << name << ": ";
        for (int i = 0; i < 3; i++) {
            cin >> coursesEnrolled[i];
        }
    }

    void displayInfo() override {
        person::displayInfo();
        cout << "GPA: " << GPA << "\nEnrollment Year: " << enrollmentYear << "\nCourses Enrolled: ";
        for (int i = 0; i < 3; i++) {
            cout << coursesEnrolled[i] << " ";
        }
        cout << endl;
    }
};

class professor : public person {
    string department;
    string coursesTaught[3];
    double salary;
public:
    professor(string n, int id, string addr, string pnum, string mail,
        string dept, double sal) : department(dept), salary(sal),
        person(n, id, addr, pnum, mail) {}

    void assignCourses() {
        cout << "Enter 3 courses taught by " << name << ": ";
        for (int i = 0; i < 3; i++) {
            cin >> coursesTaught[i];
        }
    }

    void displayInfo() override {
        person::displayInfo();
        cout << "Department: " << department << "\nCourses Taught: ";
        for (int i = 0; i < 3; i++) {
            cout << coursesTaught[i] << " ";
        }
        cout << "\nSalary: " << salary << endl;
    }
};

class staff : public person {
    string department;
    string position;
    double salary;
public:
    staff(string n, int id, string addr, string pnum, string mail, string dep, string pos, double sal)
        : department(dep), position(pos), salary(sal), person(n, id, addr, pnum, mail) {}

    void displayInfo() override {
        person::displayInfo();
        cout << "Department of Staff: " << department << "\nPosition: " << position << "\nSalary: " << salary << endl;
    }
};

class course {
    int courseID;
    string courseName;
    int credits;
    string instructor;
    string schedule;
public:
    course(int id, string name, int cred, string prof, string sched)
        : courseID(id), courseName(name), credits(cred), instructor(prof), schedule(sched) {}

    void displayCourse() {
        cout << "Course ID: " << courseID << "\nCourse Name: " << courseName << "\nCredits: " << credits
             << "\nInstructor: " << instructor << "\nSchedule: " << schedule << endl;
    }
};

int main() {
    students s1("Abeeha", 940, "BTKT21", "03152617787", "abeehakhan50@gmail.com", 3.15, 2024);
    s1.enrollCourses();
    s1.displayInfo();
    person *p;
    p=&s1;
    p->displayInfo();


  
    professor p1("Dr. Ali", 102, "University Road", "03456789012", "ali@university.edu", "CS", 80000);
    p1.assignCourses();
    p1.displayInfo();

    staff st1("Sara Khan", 305, "Admin Block", "03001234567", "sara@university.edu", "HR", "Manager", 50000);
    st1.displayInfo();

    course c1(101, "Object-Oriented Programming", 3, "Dr. Ali", "MWF 10:00-11:30 AM");
    c1.displayCourse();

    return 0;
}
