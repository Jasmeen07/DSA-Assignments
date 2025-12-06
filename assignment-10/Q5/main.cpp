/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <climits>
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
void addedges(int u,int v,int w) {
	mat[u][v]=w;
	mat[v][u]=w;
}
void printmat() {
	for(int i=0; i<v; i++) {
		for(int j=0; j<v; j++) {
			cout<<mat[i][j]<<" ";
		}
		cout<<"\n";
	}
}	
void primMST(){
    vector<int>key(v,INT_MAX);
    vector<int>parent(v,-1);
    vector<bool>inMST(v,false);
    key[0]=0;
    for(int count=0;count<v-1;count++){
        int u=-1;
        int minKey=INT_MAX;
        for(int i=0;i<v;i++){
            if(!inMST[i] && key[i]<minKey){
                minKey=key[i];
                u=i;
            }
        }
        inMST[u]=true;
        for(int i=0;i<v;i++){
            if(!(inMST[i]) && mat[u][i]!=0 && mat[u][i]<key[i]){
                key[i]=mat[u][i];
                parent[i]=u;
            }
        }
    }
    cout<<"\nEdge\tWeight\n";
     int totalWeight = 0;
    for(int i=0;i<v;i++){
        cout<<parent[i]<<" - "<<i<<"\t"<<mat[i][parent[i]]<<"\n";
        totalWeight+=mat[i][parent[i]];
    }
    cout<<"total cost of MST is: "<<totalWeight;
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
	 cout<<"Enter edges (u v weight):\n";
    for(int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addedges(u, v, w);
    }
	g.printmat();
	g.primMST();
	return 0;
}