/*Write a C++ program that:
 Reads n strings from the user and stores them in a dynamically allocated array of char*.
 Prints the strings in reverse order using pointer arithmetic.
 Finds and prints the string with the most vowels (a, e, i, o, u).
 Calculates and prints the average length of all the strings.
Note: Use pointer notation wherever possible.
If there are multiple strings with the same number of vowels, print the first one encountered*/

/*#include <iostream>
#include <cstring>
using namespace std;

int Vowels(char *ptr){
    int count=0;
    while(*ptr){
    char ch = tolower(*ptr);  // Convert to lowercase for easy comparison
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
    }
    ptr++;
    }
return count;
}

int main(){
string input;
int n;
cout<<"enter number of strings you want to input"<<endl;
cin>> n;
cout<<"enter "<<n<<" strings";

char** strings= new char*[n];

cin.ignore();
for(int i =0;i<n;i++){
 strings[i] = new char[100];
 cout<<"enter string "<< (i+1)<< ":"<<endl;
 cin.get(strings[i], 100); 
}
// for each word to be reversed 
/* cout << "\nStrings with reversed letters:" << endl;
    for (int i = 0; i < n; i++) {
        // Reverse the string by swapping characters
        int len = strlen(strings[i]);
        for (int j = 0; j < len / 2; j++) {
            // Swap characters
            char temp = strings[i][j];
            strings[i][j] = strings[i][len - j - 1];
            strings[i][len - j - 1] = temp;
        }
        cout << strings[i] << endl;
    }*/
cout<<"strings in reverse order"<<endl;
for(int i=n-1; i>=0;i--)
{
cout<<*(strings+i)<< endl;}

int max=0;
for (int i=0;i<n;i++){
    int vowelcount= Vowels(*(strings+i));
    if(vowelcount>max){
      max=i;
    }
    cout<<*(strings[i]);
}


int lenght=0;
int totalLength;
for(int i=0; i<n;i++){
    totalLength= totalLength + strlen(*(strings+i));
}
double average = static_cast<double>(totalLength) /n;
cout<<"average lenght of strings "<< average <<endl;


for (int i=0;i<n;i++){
    delete[] strings[i];
}
}
*/
#include <iostream>
#include <cstring>
using namespace std;


int Vowels(char *ptr) {
    int count = 0; 
    while (*ptr) {
        char ch = tolower(*ptr); 
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
        ptr++;
    }
    return count;
}

int main() {
    int n;
    cout << "Enter the number of strings you want to input: ";
    cin >> n;

    char **strings = new char *[n];
    cin.ignore(); 
   
    for (int i = 0; i < n; i++) {
        strings[i] = new char[100]; 
        cout << "Enter string " << (i + 1) << ": ";
        cin.getline(strings[i], 100);
    }

  
    cout << "\nStrings in reverse order:" << endl;
    for (int i = n - 1; i >= 0; i--) {
        cout << *(strings + i) << endl; }
    int maxVowels = 0, maxIndex = 0;
    for (int i = 0; i < n; i++) {
        int vowelCount = Vowels(*(strings + i)); 
        if (vowelCount > maxVowels) {
            maxVowels = vowelCount; 
            maxIndex = i;           
        }
    }
    cout << "\nString with the most vowels: " << *(strings + maxIndex) << endl;

   
    int totalLength = 0; 
    for (int i = 0; i < n; i++) {
        totalLength += strlen(*(strings + i));
    }
    double averageLength = static_cast<double>(totalLength) / n;
    cout << "Average length of all strings: " << averageLength << endl;

    
    for (int i = 0; i < n; i++) {
        delete[] strings[i];
    delete[] strings; 

    return 0;
}
    }
