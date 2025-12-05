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
    int n;
    cout<<"enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"enter the elements of array:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<=n/2;i++){
        int max=i;
        int min=i;
        for(int j=i+1;j<n-i;j++){
            if(arr[j]<arr[min])
            min=j;
            else if(arr[j]>arr[max])
            max=j;
        }
        if(min!=i){
            swap(arr[i],arr[min]);
        }
        if(max==i){
            max=min;
        }
        if(max!=n-1-i){
            swap(arr[n-i-1],arr[max]);
        }
    }
    cout<<"sorted array is:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}