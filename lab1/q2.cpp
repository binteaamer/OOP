/*Q2: Design a C++ program to manage student marks. Allow the user to input
marks for students in three subjects (Mathematics, English, and Science). The
program should calculate the total marks, average marks, and display the grade
for each student. The user can specify the number of students and then input
the marks for each subject for each student. Finally, display the marks, total,
average, and grade for each student. Assume a grading system with the
following criteria:
90 or above: Grade A
80-89: Grade B
70-79: Grade C
60-69: Grade D
Below 60: Grade F*/


#include <iostream>
using namespace std;

int main() {
    int marks; 
    int students, eng, math, sci, total, avg;
    char grade;

    cout << "Enter number of students: ";
    cin >> students;

    for (int i = 0; i < students; i++) {
        cout << "Enter marks for English: ";
        cin >> eng;
        cout << "Enter marks for Math: ";
        cin >> math;
        cout << "Enter marks for Science: ";
        cin >> sci;

        total = eng + math + sci;
        float per = (total / 300.0) * 100; // Correct percentage calculation
        avg = total / 3;

        if (per < 60)
            grade = 'F';
        else if (per >= 60 && per < 70)
            grade = 'D';
        else if (per >= 70 && per < 80)
            grade = 'C';
        else if (per >= 80 && per < 90)
            grade = 'B';
        else
            grade = 'A';

        cout << "Total marks: " << total << endl;
        cout << "Average marks: " << avg << endl;
        cout << "Grade: " << grade << endl;
    }

    return 0;
}



    


