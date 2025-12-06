/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector> 
using namespace std;

class Graph{
  int V;
  vector<vector<int>> mat;
  public:
  Graph(int vertices){
      V=vertices;
      mat=vector<vector<int>>(V,vector<int>(V,0));
  }
  
  void addEdges(int u,int v){
      mat[u][v]=1;
  }
  
  void printValue(){
    cout<<"Adjacency Matrix:\n";
    for(int i=0;i<V;i++){
        for(int j=0; j<V; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }  
  }
};

int main()
{
    Graph g(5);
    g.addEdges(0,1);
    g.addEdges(2,3);
    g.addEdges(1,1);
    g.addEdges(3,0);
    g.addEdges(4,4);
    
    g.printValue();
    return 0;
}