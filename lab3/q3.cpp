#include <iostream>
using namespace std;
class serialNum{
   int serialNumber;
   static int objectCount;
public:
serialNum(){
    serialNumber =++objectCount;

}
void report()const{
cout<< " I am object number "<< serialNumber <<endl;

}
static int getobjectcount(){
    return objectCount;
}
};
int serialNum::objectCount=0;

int main (){
serialNum s1; // everytime an obj is made costructor is called and count is incremented 
serialNum s2;
serialNum s3;

s1.report();
s2.report();
s3.report();

    return 0;
}
