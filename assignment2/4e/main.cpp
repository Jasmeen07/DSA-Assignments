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
    cout<<"Enter a string having uppercase letters: ";
    cin>>str;
    for(int i=0;i<str.length();i++){
        str[i]=(int)str[i]+32;
    }

    cout<<str;

    return 0;
}