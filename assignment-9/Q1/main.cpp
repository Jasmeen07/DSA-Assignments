/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <algorithm>
using namespace std;
int heapsize;

int LEFT(int i){
    return 2*i;
}
int RIGHT(int i){
    return 2*i+1;
}
//Max heapify
void Max_heapify(int A[],int i){
    int l=LEFT(i);
    int r=RIGHT(i);
    int largest;
    
    if(l<=heapsize && A[l]>A[i]){
        largest=l;
    }
    else
        largest=i;
    
    if(r<=heapsize && A[r]>A[largest]){
        largest=r;
    }    
    if(largest!=i){
        swap(A[i],A[largest]);
        Max_heapify(A,largest);
    }
}
//build max heap
void build_Max_heap(int A[],int n){
    heapsize=n;
    for(int i=n/2;i>=1;i--){
        Max_heapify(A,i);
    }
}
//Min heapify
void Min_heapify(int A[],int i){
    int l=LEFT(i);
    int r=RIGHT(i);
    int smallest;
    
    if(l<=heapsize && A[l]<A[i]){
        smallest=l;
    }
    else smallest=i;
    
    if(r<=heapsize && A[r]<A[smallest]){
        smallest=r;
    }
    
    if(i!=smallest){
        swap(A[i],A[smallest]);
        Min_heapify(A,smallest);
    }
}
//buid min heap
void build_Min_heap(int A[],int n){
    heapsize=n;
    for(int i=n/2;i>=1;i--){
        Min_heapify(A,i);
    }
}

//Heapsort increasing
void HeapsortIncresing(int A[],int n){
    build_Max_heap(A,n);
    for(int i=n;i>=2;i--){
        swap(A[1],A[i]);
        heapsize--;
        Max_heapify(A,1);
    }
}
//heapsort decreasing
void HeapsortDecreasing(int A[],int n){
    build_Min_heap(A,n);
    for(int i=n;i>=2;i--){
        swap(A[1],A[i]);
        heapsize--;
        Min_heapify(A,1);
    }
}

int main()
{
    int A1[10]={0, 12, 5, 20, 7, 15, 3};
    int A2[10]={0, 12, 5, 20, 7, 15, 3};
    int n=6;

    HeapsortIncresing(A1,n);
    HeapsortDecreasing(A2,n);

    cout<<"Increasing order: ";
    for(int i=1;i<=n;i++)
        cout<<A1[i]<<" ";

    cout<<"\nDecreasing order: ";
    for(int i=1;i<=n;i++)
        cout<<A2[i]<<" ";

    return 0;
}
