/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<iostream>
using namespace std;

int Partition(int A[],int p,int r){
    int x=A[r];
    int i=p-1;
    
    for(int j=p;j<=r-1;j++){
        if(A[j]<=x){
            i=i+1;
            swap(A[i],A[j]);
        }
    }
        swap(A[i+1],A[r]);
        return i+1;
}
void QuickSort(int A[],int p,int r){
    if(p<r){
        int q=Partition(A,p,r);
        QuickSort(A,p,q-1);
        QuickSort(A,q+1,r);
    }
}
int main(){
    int A[]={10, 7, 8, 9, 1, 5};
    int n=sizeof(A)/sizeof(A[0]);

    QuickSort(A,0,n-1);

    cout<<"Sorted array: ";
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
    return 0;
}