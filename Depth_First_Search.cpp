#include <iostream>
#include <vector>

using namespace std;
 
const int MaxN = 1e3+100;
vector<int> adj [MaxN];
int parent [MaxN];
bool mark[MaxN];
bool leaves [MaxN];
int n,m,com;

void input()
{

	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>v>>u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
}

void DFS(int v)
{
	mark[v]=1;
	for (int i=0;i<adj[v].size();i++)
		if(mark[adj[v][i]]==0)
			{
				parent[adj[v][i]]=v;
				leaves[v]=1;
				DFS(adj[v][i]);
			}
}

int main()
{
	input();
	for(int i=1;i<=n;i++)
		if(!mark[i])
			{
				DFS(i);
				com++;
			}
	int t;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		int Q;
		int v;
		cin>>Q;
		if (Q==1)
		{
			cin>>v;
			cout<<parent[v]<<endl;
		}
		if(Q==2)
		{
			cin>>v;
			cout<<!leaves[v]<<endl;
		}
		if(Q==3)
			cout<<com<<endl;
	}
	return 0;
}
