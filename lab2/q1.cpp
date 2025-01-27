/*Write a C++ program that reads a group of n numbers from the user and stores them in a dynamically
allocated array of type float. Then, the program should:
 Calculate the average of the numbers.
 Find the number closest to the average.
 Print the average and the number closest to it.
 Use pointer notation wherever possible.*/

#include <iostream>
using namespace std;

int main (){
int number;
cout<< "enter number of intergers you want to enter"<< endl;
cin>> number;

   float *ptr= new float [number]; 
   cout<<"enter "<<number<<" 5integers"<<endl;
   for(int i=0;i<number;i++){
    cin>> *(ptr+i);
   }
float sum;
for(int i=0;i<number;i++)
{sum+=*(ptr+i);}
float average = sum/number;

float closest= *(ptr);
for(int i=1;i<number;i++){
  if (abs(*(ptr + i) - average) < abs(closest - average)){
    closest=*(ptr+i);}

}
cout<<"average of the intergers entered is"<<average<<endl;
cout<<"closet interger to the average is"<<closest<<endl;
delete ptr;
return 0; 
}

