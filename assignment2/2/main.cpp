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
    int arr[]={64,34,25,12,22,11,90};
    int size=7;
    int temp;
    int count=0;
   
   
       for(int i=0; i<size-1; i++){
           for(int j=0; j<size-1-i; j++){
               if(arr[j]>arr[j+1]){
                   temp= arr[j];
                   arr[j]=arr[j+1];
                   arr[j+1]=temp;
                   
                   count++;
               }
           }
       }
       
       printf("The sorted array is: ");
       for(int i=0; i<size; i++){
           printf("%d ",arr[i]);
       }
       
       printf("\nThe number of times the array is swaped is %d ",count);

    return 0;
}