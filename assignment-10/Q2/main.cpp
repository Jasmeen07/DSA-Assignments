/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include<queue>
#include<vector>
using namespace std;
class graph {
	int v;
	vector<vector<int>> mat;
public:
graph(int n) {
	v=n;
	mat=vector<vector<int>>(v,vector<int>(v,0));
}
void addedges(int u,int v,bool directed = false) {
	mat[u][v]=1;
	if(!directed) mat[v][u]=1;
}
void printmat() {
	for(int i=0; i<v; i++) {
		for(int j=0; j<v; j++) {
			cout<<mat[i][j]<<" ";
		}
		cout<<"\n";
	}
}	
void bfs(int start) {
	vector<bool> visited(v,false);
	queue<int> q;
	visited[start]=true;
	q.push(start);
	while(!q.empty()) {
		int node=q.front();
		q.pop();
		cout<<node<<" ";
		for(int i=0; i<v; i++) {
			if(mat[node][i]==1 && !visited[i]) {
				visited[i]=true;
				q.push(i);
			}
		}
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
	for(int i=0; i<e; i++) {
		cout<<"enter first vertex of edge"<<i+1<<": ";
		cin>>u;
		cout<<"enter second vertex of edge"<<i+1<<": ";
		cin>>v;
		g.addedges(u,v,directed);
	}
	g.printmat();
	int start;
    cout << "Enter starting vertex for BFS: ";
    cin >> start;
	g.bfs(start);
	return 0;
}