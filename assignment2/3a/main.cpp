/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

int main()
{
    int size;
    cout<<"Enter the size of the array:";
    cin>>size;
    
    int arr[size];
    cout<<"Enter "<< size-1<<" elements of the array in the range of 1 to "<< size;
    
    cout<<"The array is:";
    for(int i=0; i<size-1; i++){
        cin>>arr[i];
    }
    
    for(int i=0; i<size-1;i++){
        if(arr[i+1]-arr[i]!=1){
            cout<<"The missing element is "<<arr[i]+1;
            break;
        }
    }
    return 0;
}