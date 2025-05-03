/*Create a template class Stack<T> with a fixed capacity. Implement methods push() and pop(). Throw:

StackOverflowException (class) if pushing to a full stack.

StackUnderflowException (class) if popping from an empty stack.

Requirements:
Both exceptions inherit from std::exception and override what().

Include error details (e.g., "Stack is full!").

Demonstrate exceptions in main().

Sample Input/Output:
Pushing to a full stack:
StackOverflowException - Stack is full!

Popping from an empty stack:
StackUnderflowException - Stack is empty!*/



#include<iostream>
#include<exception>
#include<string>
using namespace std;


class stackOverflowexception :public exception{
private  :
string message;
public:
stackOverflowexception(const string& msg):message(msg){}
const char*what()const noexcept override{
    return message.c_str();}
};

class stackUnderflowException: public exception{
private:
string message;
public:
stackUnderflowException(string msg):message(msg){}
const char* what() const noexcept override{
    return message.c_str();

} 
};

template<typename t>
class stack{
t* data;
int capacity;
int topindex;
public:
stack(int size): capacity(size), topindex(-1){
    data=new t[capacity];}
    ~stack(){
        delete[]data;

    }
void push(const t& item){
    if(topindex==capacity-1){
        throw stackOverflowexception("stack is full");
    }
    data[++topindex]=item;

}
t pop(){
    if(topindex==-1){
        throw stackUnderflowException("stack is empty");

    }
    return data[topindex--];

}
bool isEmpty() const {
    return topindex == -1;
}

bool isFull() const {
    return topindex == capacity - 1;
}
};

int main(){
    try{
        stack<int> instack(3);
        instack.push(1);
        instack.push(2);
        instack.push(3);
        instack.push(4);//gives exception

    }
    catch(const stackOverflowexception& e ){
        cerr<<"stackoverflowexception "<<e.what()<<endl;
    }
    catch (const exception& e) {
        cerr << "Standard exception: " << e.what() << endl;
    }
    try {//trying underflow exception
        stack<string> stringstack(2);
        stringstack.pop();
    }
    catch(const stackUnderflowException& e){
        cerr<<"stackunderflowexception "<<e.what()<<endl;

    }
    return 0;

}
