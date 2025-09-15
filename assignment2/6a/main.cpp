/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout<<"Enter rows and cols: ";
    cin>>rows>>cols;

    int mat[rows][cols];
    cout<<"Enter matrix:\n";
    for (int i=0; i<rows; i++)
        for (int j=0; j<cols; j++)
            cin>>mat[i][j];

    cout<<"\nSparse Matrix:\n";
    int sparsematrix[100][3], k=0;
    for (int i=0; i<rows; i++)
        for (int j=0; j<cols; j++)
            if (mat[i][j] != 0) {
                sparsematrix[k][0] = i;
                sparsematrix[k][1] = j;
                sparsematrix[k][2] = mat[i][j];
                cout<<i<<" "<<j<<" "<<mat[i][j]<<endl;
                k++;
            }

    cout<<"\nTranspose is:\n";
    for (int i=0; i<k; i++)
        cout<<sparsematrix[i][1]<<" "<<sparsematrix[i][0]<<" "<<sparsematrix[i][2]<<endl;

    return 0;
}