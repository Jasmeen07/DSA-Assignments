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
int priority(char ch){
    if(ch=='^') return 3;
    else if(ch=='/'||ch=='*') return 2;
    else if(ch=='+'|| ch=='-') return 1; 
    else return 0;
}
int main(){
    string s;
    cout<<"enter the expression";
    getline(cin,s);
int it=0;
stack<char> st;
string ans="";

     for(char ch : s){
         if(((ch>='a')&&(ch<='z'))||((ch>='A')&&(ch<='Z'))||((ch>='0')&&(ch<='9'))){
            ans+=ch;
        }
        else if(ch=='('){
            st.push(ch);
        }
        else if(ch==')'){
            while(!st.empty() && st.top()!='('){
            ans+=st.top();
            st.pop();
        }
            st.pop();
    }
      else{
            while(!st.empty() && priority(st.top())>=priority(ch)){
                ans+=st.top();
                st.pop();
            }
           st.push(ch);
        }
     }
     while(!st.empty()){
        ans+=st.top();
        st.pop();
     }
cout<<"The postfix expression is:"<<ans;
return 0;
}