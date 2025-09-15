/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;
int main() {
	int n;
	cout<<"Enter the number of rows and columns in 2D matrix: ";
	cin>>n;

	int sym[n*(n+1)/2];
	cout<<"Enter "<< n*(n+1)/2 <<" upper triangle elements: ";
	for(int i=0; i<n*(n+1)/2; i++) {
		cin>>sym[i];
	}
    int ind=0;
    int matrix[n][n];
    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            if(i<=j){
                matrix[i][j]=sym[ind++];
            }
        }
    }
    
    for(int i=0; i<n;i++){
        for(int j=0; j<i;j++){
            matrix[i][j]=matrix[j][i];
        }
    }
	int k=1;
	int sparsematrix[n*n+1][3];
	sparsematrix[0][0]=n;
	sparsematrix[0][1]=n;
	sparsematrix[0][2]=n*n;


	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			
				sparsematrix[k][0]=i;
				sparsematrix[k][1]=j;
				sparsematrix[k][2]=matrix[i][j];
				k++;
			
		}
	}
	
	cout<<"The sparsematrix is: "<<endl;
	for(int i=0; i<n*n+1; i++) {
		for(int j=0; j<3; j++) {
			cout<<sparsematrix[i][j]<<" ";
		}
		cout<<endl;
	}

}