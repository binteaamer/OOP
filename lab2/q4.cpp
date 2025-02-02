/*You are required to write a C++ program that will creates a function named unique that will take array
as input . the array may contains the duplicates values but you have to process on the array and have to
return the array which must contains only unique values not duplicates.*/
#include<iostream>
using namespace std;
int unique(int arr[], int size, int uniquearr[]){
    int uniqueCount = 0;

 for (int i = 0; i < size; i++) {
        bool isDuplicate = false;

        for (int j = 0; j < uniqueCount; j++) {
            if (arr[i] == uniquearr[j]) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {
            uniquearr[uniqueCount] = arr[i];
            uniqueCount++;
        }
    }
    return uniqueCount;
}


int main(){
    int n;
 int arr[] = {1, 2, 2, 3, 4, 4, 5};
n = sizeof(arr) / sizeof(arr[0]);
 int uniquearr[n];
int uniqueSize= unique(arr, n , uniquearr);
   cout << "Array with unique values: ";
    for (int i = 0; i < uniqueSize; i++) {
        cout << uniquearr[i] << " ";
    }
    cout << endl;

    return 0;
}
