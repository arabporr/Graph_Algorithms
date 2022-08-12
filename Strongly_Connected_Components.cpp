#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define mp make_pair

const int maxn=505*1001;

int n,m,Time;
vector <int> Color[maxn],in[maxn],out[maxn],V;
bool mark[maxn];

inline void input()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int v,u;
		cin>>u>>v;
		out[u].pb(v);
		in[v].pb(u);
	}
}

void DFS(int v)
{
	mark[v]=true;
	for(auto i:out[v])
		if(!mark[i])
			DFS(i);
	V.pb(v);
}

void SFD(int v)
{
	mark[v]=true;
	Color[Time].pb(v);
	for(auto i: in[v])
		if(!mark[i])
			SFD(i);
}

inline void SCC()
{
	for(int i=1;i<=n;i++)
		if(!mark[i])
			DFS(i);

	reverse(V.begin(),V.end());
	memset(mark,0,sizeof(mark));
	
	for(auto i : V)
		if(!mark[i])
			Time++,SFD(i);
}

inline void Print_Ans()
{
	cout << "This graph has "<<Time<<" Strongly Conected Components"<<endl<<endl;
	for(int i=1;i<=Time;i++)
	{
		cout<<"Strongly Conected Component "<<i<<" contains "<<Color[i].size()<<" vertices"<<endl<<"They are : ";
		sort(Color[i].begin(),Color[i].end());
		for(auto j: Color[i])
			cout<<j<<" ";
		cout<<endl;
	}
}
int32_t main()
{
	input();
	SCC();
	Print_Ans();
	return 0;
}
