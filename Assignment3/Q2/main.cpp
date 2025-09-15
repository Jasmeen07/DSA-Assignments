/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>
#include <stack>
using namespace std;
void reverse(string s){
    stack <char> st;
    for(int i=0;i<s.length();i++){
        st.push(s[i]);
    }
    string rev="";
    for(int i=0;i<s.length();i++){
      rev+=st.top();
      st.pop();
    }
    cout<<"reversed string is : "<<rev;
}
int main(){
  string s;
  cout<<"enter a string";
  getline(cin,s);
  reverse(s);
}