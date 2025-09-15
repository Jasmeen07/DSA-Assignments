/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;
int main(){
    int row;
    cout<<"Enter the number of rows in 2D matrix: ";
    cin>>row;
    
    int col;
    cout<<"Enter the number of cols in 2D matrix: ";
    cin>>col;
    
    int diag[row];
    cout<<"Enter the diagnol elements: ";
    for(int i=0; i<row;i++){
        cin>>diag[i];
    }
    
   int k=1;
   int sparsematrix[row+1][3];
   sparsematrix[0][0]=row;
   sparsematrix[0][1]=col;
   sparsematrix[0][2]=row; 


   for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
        if(i==j){
            sparsematrix[k][0]=i;
            sparsematrix[k][1]=j;
            sparsematrix[k][2]=diag[i];  
            k++;
        }
    }
   }
   cout<<"The sparsematrix is: "<<endl;
   for(int i=0;i<row+1;i++){
    for(int j=0;j<3;j++){
        cout<<sparsematrix[i][j]<<" ";
    }
       cout<<endl;
   }

}