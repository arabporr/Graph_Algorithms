#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MaxN=1e5+100;
int n,m,AvEd[MaxN];
bool mark[MaxN];
vector < pair<int, int> > adj [MaxN];

void input ()
{
	cin>> n>> m;
	for (int i=1;i<=m;i++)
	{
		int v,u,w;
		cin>> v>> u>> w;
		adj[v].push_back(make_pair(u,w));
		adj[u].push_back(make_pair(v,w));
	}
}

void expand(int v)
{
	mark[v]=true;
	for (int i=0;i<adj[v].size();i++)
		if(AvEd[v]+adj[v][i].second<AvEd[adj[v][i].first])
			AvEd[adj[v][i].first]=AvEd[v]+adj[v][i].second;
}

int extract_min()
{
	int ret=0;
	for (int i=1;i<=n;i++)
		if(mark [i]==0 && AvEd[i]<=AvEd[ret])
			ret=i;
	return ret;
}

void Dijkstra(int v)
{
	fill(AvEd,AvEd+n+1,INT_MAX/2);
	AvEd[v]=0;
	for(int i=1;i<=n;i++)
		expand(extract_min());
}

int main()
{
	input();
	int u;
	cin>>u;
	Dijkstra(u);
	for (int i=1;i<=n;i++)
		cout<<AvEd[i]<<"   ";
	return 0;
}
