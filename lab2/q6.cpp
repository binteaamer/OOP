/*You are tasked with implementing a simple Student Registration System in C++. Define two structures,
Register and Student, where Register contains attributes courseId and courseName, and Student inherits
from Register while having additional attributes such as studentId, firstName, lastName, cellNo, and
email. Your goal is to create an array of Student structures to store information for five students. Write a
C++ program that accomplishes the following tasks:
 Implement the Register and Student structures.
 Inherit the Register structure in the Student structure.
 Create an array of Student structures to store information for 5 students.
 Take input for each student, including their courseId, courseName, studentId, firstName,
lastName, cellNo, and email.
 Display the information for all 5 students.*/

#include <iostream>
#include <cstring>
using namespace std;
struct Register {
    int courseId;
    string courseName;
};

struct student: Register{
    string studentId;
    string firstName;
    string lastName;
    string cellNo;
    string email;
};

void inputInfo( student& std){
    cout << "Enter Course ID: ";
    cin >> std.courseId;
    cout << "Enter Course Name: ";
    cin.ignore(); // To consume the leftover newline character
    getline(cin, std.courseName);
    cout << "Enter Student ID: ";
    cin >> std.studentId;
    cout << "Enter First Name: ";
    cin >> std.firstName;
    cout << "Enter Last Name: ";
    cin >> std.lastName;
    cout << "Enter Cell Number: ";
    cin >> std.cellNo;
    cout << "Enter Email: ";
    cin >> std.email;
}

void display(student& std){
    cout << "\nCourse ID: " << std.courseId
         << "\nCourse Name: " << std.courseName
         << "\nStudent ID: " << std.studentId
         << "\nFirst Name: " << std.firstName
         << "\nLast Name: " << std.lastName
         << "\nCell Number: " << std.cellNo
         << "\nEmail: " << std.email << endl;

}


int main(){
    student std[5];

    for(int i=0; i<5;i++){
     cout << "\nEnter details for Student " << (i + 1) << ":\n";
    inputInfo(std[i]);
    }
cout << "\nDisplaying details of all students:\n";
 for(int i=0; i<5;i++){
    display(std[i]);
 }
}
