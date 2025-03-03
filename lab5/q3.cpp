/*Create a class called ValidateString. The purpose of this class will be to check if the given characters in a
string are alphabet only. Numbers and symbols will mean that the string is invalid. By using a
parameterized constructor, create multiple objects for your class that accept different strings. Create a
constant function that checks whether the string variable is valid or not.
What happens if you do not make your function constant? Add a comment right above your function
explaining why we make a function constant.*/

#include <iostream>
#include <cctype> //for isalpah to check for only alphabets
using namespace std;

class ValidateString
{
    string inputString;

public:
    ValidateString(string inputStr)
    {
        inputString = inputStr;
    }
    /*We make this function constant because it does not modify any member variables.
           A constant function ensures that the function does not accidentally alter class data,
           making it safe to call on constant objects.*/

    bool isValid() const
    {
        for (char ch : inputString)
        {
            if (!isalpha(ch))
            {
                return false;
            }
        }

        return true;
    }
    void displayResult() const
    {
        if (isValid())
        {
            cout << "string is valid" << endl;
        }
        else
        {
            cout << "the string has other charecters, it is invalid" << endl;
        }
    }
};
int main (){
    ValidateString v1("helloworld");
    ValidateString v2("abeehaisinbscs2f");
    ValidateString v3("1234@fastnuces");

    v1.displayResult();
    v2.displayResult();
    v3.displayResult();
    
    return 0;

}
