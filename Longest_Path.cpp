#include <iostream>
#include <vector>

using namespace std;

const int MaxN=1e5+100;

int n,X,MX[MaxN][3],MaxDis;
vector < int > adj [MaxN];
bool mark [MaxN];

void input()
{
	 cin>> n;
	 for (int i=1;i<n;i++)
	 {
	 	int u,v;
	 	cin>> u>>v;
	 	adj[v].push_back(u);
	 	adj[u].push_back(v);
	 }
}

void DFS(int y,int parent)
{
	mark[y]=true;
	for(int i=0;i<adj[y].size();i++)
		if(mark[adj[y][i]]==0)	
			DFS(adj[y][i],y);
	X=0;
	for(int i=0;i<adj[y].size();i++)
		if(adj[y][i]!=parent)
			if(MX[adj[y][i]][1]+1>MX[y][1])
			{
				X=i;
				MX[y][1]=MX[adj[y][i]][1]+1;
			}
	for(int i=0;i<adj[y].size();i++)
		if(i!=X && adj[y][i]!=parent)
				if(MX[adj[y][i]][1]+1>MX[y][2])
					MX[y][2]=MX[adj[y][i]][1]+1;
		
}

int main()
{
	input();
	DFS(1,0);
	cout<< endl;
	for(int i=1;i<=n;i++)
		if(MX[i][1]+MX[i][2]>MaxDis)
			MaxDis=MX[i][1]+MX[i][2];
	cout<< MaxDis;
	return 0;
}
