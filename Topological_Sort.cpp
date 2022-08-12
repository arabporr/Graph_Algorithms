#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int maxN=1e5+100;

int deg[maxN];
int n,m;
vector<int> g[maxN],topol;

void input()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int k1,k2;
		cin>>k1>>k2;
		g[k1].push_back(k2);
		deg[k2]++;
	}
}

void topological()
{
	queue<int> zero;
	for(int i=1;i<=n;i++)
		if(deg[i]==0)
			zero.push(i);
	while(zero.empty()==false)
	{
		int v=zero.front();
		topol.push_back(v);
		zero.pop();
		for(int i=0;i<g[v].size();i++)
		{
			deg[g[v][i]]--;
			if(deg[g[v][i]]==0)
				zero.push(g[v][i]);	
		}
	}

}

void show()
{
	for(int i=0;i<topol.size();i++)
		cout<<topol[i]<<" ";
}

int main()
{
   input();
   topological();
   show();
}
