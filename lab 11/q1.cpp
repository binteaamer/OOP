#include<iostream>
#include<exception>
#include<string>

using namespace std;
class invalidValueException: public exception{
private :
    string message;

public:
invalidValueException(const string& msg): message(msg){}

const char* what() const noexcept override{
    
return message.c_str();}
};

void validateAge(int age) {
    if (age < 0) {
        throw invalidValueException("Age cannot be negative or exceed 120.");
    }
    else if (age > 120) {
        throw invalidValueException("Age cannot be negative or exceed 120.");
    }
}

int main (){
int age;
cout<<"Enter your age: "<<endl;
cin>> age;
try{
    validateAge(age);
    cout<<"valid"<<endl<<"your age is: "<<age<<endl;
}
catch (const invalidValueException& e) {
    cout << "Invalid age: " << e.what() << endl;

}
catch (...) {
    cerr << "Unknown exception occurred" << endl;
}

return 0;
}

