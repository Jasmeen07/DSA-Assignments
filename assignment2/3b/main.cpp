/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

int main() {
    int size;
    cout<<"Enter the size of the array:";
    cin>>size;
    
    int arr[size-1];
    cout<<"Enter "<< size-1<<" elements of the array in the range of 1 to "<< size;
    for (int i = 0; i < size-1; i++) {
        cin >> arr[i];
    }
    int temp;
    int count=0;
       for(int i=0; i<size-1; i++){
           for(int j=0; j<size-1-i; j++){
               if(arr[j]>arr[j+1]){
                   temp= arr[j];
                   arr[j]=arr[j+1];
                   arr[j+1]=temp;
               }
           }
       }

    int start = 0, end = size-2;
    int missing = -1; 
    while (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid] == mid + 1) {
            start = mid + 1;
        } 
        else {
            missing = mid + 1;
            end = mid - 1;
        }
    }
    cout << "Missing element is: " << missing << endl;
    return 0;
}