/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector> 
using namespace std;

vector<vector<int>> createGraph(int V,vector<vector<int>>&edges){
    vector<vector<int>> mat(V,vector<int>(V,0));
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        mat[u][v]=1; //mark edges in the matrix
    }
    return mat;
}

int main()
{
    int V=5;
    vector<vector<int>> edges{
        {0, 1},
        {0, 2},
        {1, 3},
        {2, 4},
    };
    
    vector<vector<int>> graph = createGraph(V,edges);
    
    cout<<"Adjacency Matrix:\n";
    for(int i=0;i<V;i++){
        for(int j=0; j<V; j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}