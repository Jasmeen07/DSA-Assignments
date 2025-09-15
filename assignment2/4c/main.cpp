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
    cout<<"Enter a string: ";
    cin>>str;

    int size=0;
    int k=0;
    while(str[k]!='\0'){
        size++;
        k++;
    }
    
    int i=0;
    while(i<k){
        if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'){
            str.erase(i,1);
        }
        else{
            i++;
        }
    }
    
    cout<<"The string is: "<<str;
    return 0;
}