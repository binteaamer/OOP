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
*/

#include <iostream>
#include <string>

using namespace std;

class Calendar {
private:
    string tasks[12][31];
    int year;

public:
    Calendar(int y) { year = y; }

    void addTask(string task, int day, int month) {
        tasks[month - 1][day - 1] = task;
    }

    void removeTask(int day, int month) {
        tasks[month - 1][day - 1] = "";
    }

    void showTasks() {
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 31; j++) {
                if (!tasks[i][j].empty()) {
                    cout << "Month " << i + 1 << ", Day " << j + 1 << ": " << tasks[i][j] << endl;
                }
            }
        }
    }
};

int main() {
    Calendar cal(2025);
    cal.addTask("Meeting", 5, 2);
    cal.addTask("Doctor", 10, 3);
    cal.addTask("Shopping", 15, 4);
    cal.addTask("Trip", 20, 5);
    cal.addTask("Dinner", 25, 6);

    cout << "Tasks before removal:" << endl;
    cal.showTasks();
    
    cal.removeTask(10, 3);

    cout << "Tasks after removal:" << endl;
    cal.showTasks();
    
    return 0;
}

