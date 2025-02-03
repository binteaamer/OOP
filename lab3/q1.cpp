/*Create a class called time that has separate int member data for hours, minutes, and seconds. One constructor
should initialize this data to 0, and another should initialize it to fixed values. Another member function should
display it, in 11:59:59 format. The final member function should add two objects of type time passed as
arguments.*/

#include <iostream>
#include<iomanip>
using namespace std;
class Time{
 private: 
    int hours;
    int minutes;
    int seconds;
public:
   Time():hours(0), minutes(0), seconds(0){}// default
   Time (int h, int m, int s): hours(h), minutes(m), seconds(s) {}//parametrized 
  
   void displayTime()const {
    cout << setw(2) << setfill('0') << hours << ":"// setw is used for formatting iomanip , setfill fills any empty space with 0 
         << setw(2) << setfill('0') << minutes << ":"
         << setw(2) << setfill('0') << seconds << endl;
   }
 
     static Time addTime(const Time& t1, const Time& t2) {
        int tsec = (t1.hours * 3600 + t1.minutes * 60 + t1.seconds) +(t2.hours * 3600 + t2.minutes * 60 + t2.seconds);
        int h= (tsec/3600) %24; //%24 helps to keep hours within 0-23
        tsec%=3600; // removes seconds counted in hours above 
        int m=(tsec/60);
        int s =tsec%60;
   return Time(h,m,s);
    }


};
int main(){
    Time t1(5,32,50);
    Time t2(16,45,20);
cout<<"time 1:"<<endl;
t1.displayTime();
cout<<"time 1:"<<endl;
t2.displayTime();
Time result= Time::addTime(t1, t2); //:: tells to call this function from Time class
cout<<"result after adding two time : ";
result.displayTime();

return 0;
}

