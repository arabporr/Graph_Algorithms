#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int maxN=1e5+100;

int n,v,m;
int dist[maxN];
bool mark[maxN];
vector<int> g[maxN];

void input()
{
	cin>>n>>m>>v;
	for(int i=1;i<=m;i++)
	{
		int k1,k2;
		cin>>k1>>k2;
		g[k1].push_back(k2);
		g[k2].push_back(k1);
	}
}

void BFS(int v)
{
	queue<int> q;
	q.push(v);
	dist[v]=0;
	mark[v]=1;
	while(q.empty()==false)
	{
		int u=q.front();
		q.pop();
		for(int i=0;i<g[u].size();i++)
			if(!mark[g[u][i]])
			{
				q.push(g[u][i]);
				dist[g[u][i]]=dist[u]+1;
				mark[g[u][i]]=true;
			}
	}
}

void show()
{
	for(int i=1;i<=n;i++)
		cout<<dist[i]<<" ";
	cout<<endl;
}

int main()
{
	input();
	BFS(v);
	show();
	return 0;
}
