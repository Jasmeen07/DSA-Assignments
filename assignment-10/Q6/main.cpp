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
void dijkstraMST(int start){
    vector<int>dist(v,INT_MAX);
    vector<bool>inMST(v,false);
    dist[start]=0;
    for(int count=0;count<v-1;count++){
        int u=-1;
        int minKey=INT_MAX;
        for(int i=0;i<v;i++){
            if(!inMST[i] && dist[i]<minKey){
                minKey=dist[i];
                u=i;
            }
        }
        if(u==-1) break;
        inMST[u]=true;
        for(int i=0;i<v;i++){
            if(!(inMST[i]) && mat[u][i]!=0 && dist[u]+mat[u][i]<dist[i]){
                dist[i]=mat[u][i]+dist[u];
            }
        }
    }
    cout << "\nShortest distances from source " << start << ":\n";
        for (int i = 0; i < v; i++) {
            cout << "Node " << i << " → " << dist[i] << endl;
        }
}
};

int main()
{
	int vertices=5;
	graph g(vertices);
	g.addedges(0, 1, 10);
    g.addedges(0, 4, 5);
    g.addedges(1, 2, 1);
    g.addedges(4, 1, 3);
    g.addedges(4, 2, 9);
    g.addedges(4, 3, 2);
    g.addedges(2, 3, 4);

	g.printmat();
	g.dijkstraMST(0);
	return 0;
}