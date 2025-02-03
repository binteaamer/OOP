/*Create a class called calendar. The calendar should have 12 arrays for each month of the year, and a variable that
stores information about the current year. The user is allowed to store their tasks to do against each day. Assume
only one entry is needed per day.
Create the following methods for your class:
 Add a task. Thisfunction accepts three parameters: task details, date and month. It should add
 a task on the day specified.
 Remove a task. Accepts the date and month as a parameter to remove the task from.
 Show tasks. This method should go through all of your months and print all the tasks allocated.
Your task is to create one calendar object, then hardcode 5-6 tasks for your calendar. Then demonstrate how
you’ll remove a task, and display the updated task list.
Task 6:
Create a class called Smartphone with the following attributes:
 Company
 Model
 Display Resolution
 RAM
 ROM
 Storage
Create getter and setter methods for your attributes. A smartphone has some specific actions that it can perform.
For example:
1. Make a phone call
2. Send a message
3. Connect to the wifi
4. Browse the internet*/

#include<iostream>
#include <string>
using namespace std ;
class calender{
private:
   string month[12][31];
   int year;
public:
calender (int y):year(y){}

void addTask(const string&task, int date, int month){

}
void remove(int date, int month){

}

void show()const{
cout << "\nTasks for the year " << year << ":\n"; 
}


};


int main(){
    calender c1(2025);
    c1.addTask("Meeting with John", 12, 2);
    c1.addTask("Doctor's appointment", 15, 4);
    c1.addTask("Project deadline", 25, 6);
    c1.addTask("Birthday party", 5, 7);
    c1.addTask("Team lunch", 19, 9);
    c1.addTask("Annual conference", 10, 11);

c1.show();
c1.remove(5,7);
cout << "\nUpdated Task List:" << endl;
    c1.showTasks();

}
