//Write a C++ program to check whether a given number is prime or not. Allow
//the user to input a number and display whether it's prime or not?
#include<iostream>
using namespace std;
int main(){
    int num;
    int isprime=0;// 0 is yes
cout << "Enter an Integer value: "; 
cin >>num; 
for (int i=2; i<=num/2; i++){
    if(num%i==0){
        isprime=1;
    }
   /* if(num<=1){
    return 1;
    }*/
}
if (isprime==0)
{
    cout<<"entered integer is prime";
}
else cout<<"not prime integer";

}
