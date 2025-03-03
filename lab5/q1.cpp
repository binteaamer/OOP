/*Create a class called Square with the following attributes:
• sideLength – float variable
• area – float variable
• allareas – static float variable
Create the following methods for your class:
• Constructors (default and parameterized (only takes sideLength as input))
• Function to calculate area, the calculated area should always be added to the allareas
variable each time an area is calculated. (assume it’s called only once for each object)
• Getters and Setters for all variables
In your main functions create 3 Squares with different sideLength. Call the area method for each of
those Square objects. After each time the area method is called, call that square’s getters for area and
allareas to display the updated values.*/


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
 
