/*Create an exception hierarchy:

Base class: FileException (with what()).

Derived classes: FileNotFoundException, PermissionDeniedException.

Write a function readFile(const string& filename) that throws these exceptions based on file issues.

Requirements:
Use polymorphism to catch the base class FileException.

Handle specific exceptions in separate catch blocks.*/


#include<iostream>
#include<exception>
#include<string>
using namespace std;

class fileException :public exception{
protected:
string message;
public:
fileException(string msg):message(msg){}
    const char*what() const noexcept override{
    return message.c_str();}
};

class filenotfoundException:public fileException{
    public:
    filenotfoundException(const string& filename):fileException("file not found"+ filename){}
};

class permissiondeniedException: public fileException{
public:
permissiondeniedException(const string& filename): fileException("permission denied "+ filename){}

};

void readfile(const string& filename){
    if(filename=="missing.txt"){
        throw filenotfoundException(filename);
    }
    else if(filename=="secret.txt"){
        throw permissiondeniedException(filename);
    }
    else{
        cout<<"Reading file: "<<filename<<endl;
    }
    }

int main (){
    string filename;
    cout<<"enter file name"<<endl;
    cin>>filename;
    try{
        readfile(filename);
    cout<<"file read successfully"<<endl;
    }

    catch(const filenotfoundException& e){
        cerr<<"error: "<<e.what()<<endl; 
    }
    
    catch(const permissiondeniedException& e){
        cerr<<"error"<<e.what()<<endl;
    }
    
    catch (const fileException&e){
        cerr<<"generic error: "<<e.what()<<endl;

    }
    catch(...){
        cout<<"unkown error has occcured"<<endl;
    }
    return 0;
    }
