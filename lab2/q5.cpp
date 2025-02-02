/*You are required to write a c++ function swap_string that shifts the last n characters of a string to the
front n times. It will take str and int as parameters. And will return the new string after shifting.*/
#include <iostream>
#include <cstring>
using namespace std;

    char* swap_string(const char* str ,int n){
          int len= strlen(str);
          
          if (n <= 0 || n > len) {
          char*copy=new char[len +1];
          strcpy(copy, str);
          return copy;
           }
    char* result = new char[len + 1]; 
    strncpy(result, str+(len-n), n);
    strncpy(result + n, str, len - n);
    result[len] = '\0';
    return result;
    }
int main (){
    char str[100];
    cout<<"enter a string"<<endl;
    cin.getline(str,100);
    int n;
    cout<<"enter n"<<endl;
    cin>>n;
    char* modifiedStr = swap_string(str, n);
 
    cout << "Modified string: " << modifiedStr << endl;
    delete[] modifiedStr;

    return 0;
}
