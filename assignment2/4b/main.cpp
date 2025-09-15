/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cout<<"Enter the string ";
    getline(cin, str);
    
    int size=0;
    int k=0;
    while(str[k]!='\0'){
        size++;
        k++;
    }
    
    for(int i=0, j=size-1;i<=j; i++,j--){
        char temp=str[i];
        str[i]=str[j];
        str[j]=temp;
    }
    cout<<"the reverse string is: "<<str;
    

    return 0;
}