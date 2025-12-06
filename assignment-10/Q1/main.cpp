/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include<vector>
using namespace std;
class graph{
  int v;
  vector<vector<int>> mat;
  public:
  graph(int n){
      v=n;
      mat=vector<vector<int>>(v,vector<int>(v,0));
  }
  void addedges(int u,int v ,bool directed = false){
      mat[u][v]=1;
     if(!directed) mat[v][u]=1;
  }
  void printmat(){
      for(int i=0;i<v;i++){
          for(int j=0;j<v;j++){
              cout<<mat[i][j]<<" ";
          }
          cout<<"\n";
      }
  }
  int indegree(int x){
      int count=0;
      for(int i=0;i<v;i++){
              count+=mat[i][x];
        }
        return count;
    }
  int outdegree(int x){
      int count=0;
      for(int i=0;i<v;i++){
              count+=mat[x][i];
        }
        return count;
    }
  int numberofedges(bool directed){
      int count=0;
      for(int i=0;i<v;i++){
          for(int j=0;j<v;j++){
              if(mat[i][j]==1){
                  count++;
              }
          }
     }
     return directed ? count : count / 2;
  }
  void adjacentVertices(int x){
      for(int i=0;i<v;i++){
          if(mat[x][i]==1)cout<<i<<" ";
      }
       cout<<endl;
  }
};

int main()
{
    int n,e;
    bool directed;
    cout<<"enter the no. of vertices of graph: ";
    cin>>n;
    graph g(n);
    cout<<"enter the no. of edges of graph: ";
    cin>>e;
    cout << "Directed graph? (1-Yes, 0-No): ";
    cin >> directed;
    int v,u;
    for(int i=0;i<e;i++){
        cout<<"enter first vertex of edge"<<i+1<<": ";
        cin>>u;
        cout<<"enter second vertex of edge"<<i+1<<": ";
        cin>>v;
        g.addedges(u,v,directed);
    }
    g.printmat();
    int v1;
    cout<<"Enter the vertex of which you want to find adjacent vertices: ";
    cin>>v1;
    cout<<"adjacent vertices are: ";
    g.adjacentVertices(v1);
    cout<<"In degree of v: "<<g.indegree(v1)<<endl;
    cout<<"Out degree of v: "<<g.outdegree(v1)<<endl;
    cout<<"total edges: "<<g.numberofedges(directed);
    return 0;
}