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



    


