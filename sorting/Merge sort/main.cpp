/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<iostream>
using namespace std;

void Merge(int A[],int p,int q,int r){
    int n1=q-p+1;
    int n2=r-q;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++){
        L[i]=A[p+i];
    }
    for(int i=0;i<n2;i++){
        R[i]=A[q+1+i];
    }
    int i=0,j=0,k=p;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
           A[k]=L[i];
           i++;
        }
        else{
           A[k]=R[j];
           j++;
    } 
    k++;
}
    
    while(i<n1){
        A[k]=L[i];
        i++;
        k++;
    }
    while(j<n2){
        A[k]=R[i];
        j++;
        k++;
    }
}
void MergeSort(int A[],int p,int r){
    if(p<r){
        int q=(p+r)/2;
        MergeSort(A,p,q);
        MergeSort(A,q+1,r);
        Merge(A,p,q,r);
    }
}

int main(){
    int A[]={10, 7, 8, 9, 1, 5};
    int n=sizeof(A)/sizeof(A[0]);

    MergeSort(A,0,n-1);

    cout<<"Sorted array: ";
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
    return 0;
}