/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <algorithm>
using namespace std;

int heapsize=0;
int PARENT(int i) { return i/2; }
int LEFT(int i)   { return 2*i; }
int RIGHT(int i)  { return 2*i + 1; }

void MAX_HEAPIFY(int A[],int i){
    int l=LEFT(i);
    int r=RIGHT(i);
    int largest = i;

    if(l<=heapsize && A[l]>A[largest])
        largest = l;

    if(r<=heapsize && A[r]>A[largest])
        largest = r;

    if(largest != i){
        swap(A[i], A[largest]);
        MAX_HEAPIFY(A, largest);
    }
}
void heap_insert(int A[],int key){
    heapsize++;
    A[heapsize]=-99999; //give -infinty value to the element to be inserted
    
    int i=heapsize;
    A[i]=key;
    
    while(i>1 && A[i]>A[PARENT(i)]){
        swap(A[i],A[PARENT(i)]);
        i=PARENT(i);
    }
}
int heap_extract_max(int A[]){
    if(heapsize < 1) {
        cout << "Heap Underflow!\n";
        return -1;
    }
    int max=A[1];
    A[1]=A[heapsize];
    heapsize--;
    MAX_HEAPIFY(A,1);
    return max;
}
void HEAP_INCREASE_KEY(int A[],int i ,int newKey) {
    if(newKey<A[i]){
        cout<<"New key is smaller than current key!\n";
        return;
    }

    A[i]=newKey;
    while(i>1 && A[PARENT(i)]<A[i]){
        swap(A[i], A[PARENT(i)]);
        i=PARENT(i);
    }
}
int main() {
    int A[100]; // heap array

    heap_insert(A, 20);
    heap_insert(A, 15);
    heap_insert(A, 30);
    heap_insert(A, 40);
    heap_insert(A, 10);

    cout << "Extracted max: " << heap_extract_max(A) << endl;
    cout << "Extracted max: " << heap_extract_max(A) << endl;

    cout << "Current heap: ";
    for(int i = 1; i <= heapsize; i++)
        cout << A[i] << " ";

    return 0;
}
