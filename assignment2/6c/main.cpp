/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

int main() {
    int rows1, cols1;
    cout<<"Enter rows and cols of matrix 1: ";
    cin>>rows1>>cols1;

    int mat1[20][20];
    cout<<"Enter matrix 1:\n";
    for (int i=0; i<rows1; i++)
        for (int j=0; j<cols1; j++)
            cin>>mat1[i][j];

    cout<<"\nSparse matrix of matrix 1:\n";
    int sparsematrix1[100][3], k=0;
    for (int i=0; i<rows1; i++)
        for (int j=0; j<cols1; j++)
            if (mat1[i][j] != 0) {
                sparsematrix1[k][0] = i;
                sparsematrix1[k][1] = j;
                sparsematrix1[k][2] = mat1[i][j];
                cout<<i<<" "<<j<<" "<<mat1[i][j]<<endl;
                k++;
            }

    int rows2, cols2;
    cout<<"Enter rows and cols of matrix 2: ";
    cin>>rows2>>cols2;

    int mat2[20][20];
    cout<<"Enter matrix 2:\n";
    for (int i=0; i<rows2; i++)
        for (int j=0; j<cols2; j++)
            cin>>mat2[i][j];

    cout<<"\nSparse Matrix of matrix 2 (row col val):\n";
    int sparsematrix2[100][3];
    int m=0;
    for (int i=0; i<rows2; i++)
        for (int j=0; j<cols2; j++)
            if (mat2[i][j] != 0) {
                sparsematrix2[m][0] = i;
                sparsematrix2[m][1] = j;
                sparsematrix2[m][2] = mat2[i][j];
                cout<<i<<" "<<j<<" "<<mat2[i][j]<<endl;
                m++;
            }
    
    if (cols1!=rows2) {
        cout<<"Multiplication not possible!";
        return 0;
    }
    
    int result[200][3], r=0;

    for (int i=0; i<k; i++) {
        for (int j=0; j<m; j++) {
            if (sparsematrix1[i][1] == sparsematrix2[j][0]) {
                int row = sparsematrix1[i][0];
                int col = sparsematrix2[j][1];
                int val = sparsematrix1[i][2] * sparsematrix2[j][2];

                //check if this (row,col) already exists
                bool found = false;
                for (int x=0; x<r; x++) {
                    if (result[x][0]==row && result[x][1]==col) {
                        result[x][2]+=val;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    result[r][0]=row;
                    result[r][1]=col;
                    result[r][2]=val;
                    r++;
                }
            }
        }
    }

    cout<<endl<<"Resultant Matrix in Triplet form (row col val):"<<endl;
    for (int i=0; i<r; i++) {
        if (result[i][2]!=0)
            cout<<result[i][0]<<" "<<result[i][1]<<" "<<result[i][2]<<endl;
    }

    return 0;
}