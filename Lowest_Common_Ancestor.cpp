#include <bits/stdc++.h>

using namespace std;

const int maxn=505*1001;
const int K=32;

#define F first
#define S second
#define pb push_back
#define mp make_pair
#define Right(x) (x*2+1)
#define Left(x) (2*x)
#define all(x) x.begin(),x.end()

int n,m,q,par[maxn][K],h[maxn];
vector<int> adj[maxn];

inline void input()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		adj[v].pb(u);
		adj[u].pb(v);
	}
}

void DFS(int v,int high)
{
	for(int i=1;i<K;i++)
		par[v][i]=par[par[v][i-1]][i-1];
	
	h[v]=high;
	
	for(auto i: adj[v])
		if(i!=par[v][0])
			par[i][0]=v,DFS(i,high+1);
}

int LCA(int v1,int v2)
{
	if(h[v1]>h[v2])
		swap(v1,v2);

	for(int i=K-1;i>=0;i--)
		if( ((1<<i)&(h[v2]-h[v1])) )
			v2=par[v2][i];

	if(v1==v2)
		return v1;

	for(int i=K-1;i>=0;i--)
		if(par[v1][i]!=par[v2][i])
			v1=par[v1][i],v2=par[v2][i];

	return par[v1][0];
}

int main()
{
	input();
	DFS(1,1);
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		int u,v;
		cin>>u>>v;
		cout<<"LCA is: "<<LCA(u,v)<<endl;
	}
	return 0;
}
