#include<iostream>
using namespace std;

class square{
    float sideLength;
    float area;
    static float allareas;

    public:
    square(){

        sideLength=0.0;
        area=0.0;

    }
    square(float sL) : sideLength(sL){
     calculateArea();
    }

    void calculateArea(){
           area = sideLength * sideLength;
        allareas+=area; 
        cout<< "area for square is: "<<area<< endl; 
    }

    void setSideLength(float s){
        sideLength=s;
        calculateArea();
    }

    void setArea(float a){
        area=a;
    }
    float getSideLength (){
    return sideLength;
    }

    static float getAllareas(){
        cout<<"total of all areas is : "<<allareas<<endl;
        return allareas;

    }

};

float square::allareas = 0.0;

int main (){

square s1(5); 
square s2(6);
square s3(10); 

square::getAllareas();
return 0;

}
 
