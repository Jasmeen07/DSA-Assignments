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
    string str1,str2;
    cout<<"Enter string1: ";
    cin>>str1;
    
    cout<<"Enter string2: ";
    cin>>str2;
    
    string str3;
    str3=str1+" "+str2;
    cout<<"The concatenated string is: "<<str3;

    return 0;
}