#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MaxN=1e3+100;

vector<int> adj [MaxN],topological;
int m,n,min_way [MaxN],how[MaxN],start,end1,deg[MaxN];

void input()
{
	cin>> n >> m;
	for(int i=1;i<=m;i++)
	{
		int v,u;
		cin>>v>>u;
		adj[v].push_back(u);
		deg[u]++;
	}
	cin>>start>>end1;
}

void topological_sort()
{
	queue<int> zero;
	for(int i=1;i<=n;i++)
		if(deg[i]==0)
			zero.push(i);
	while(zero.empty()==false)
	{
		int top=zero.front();
		topological.push_back(top);
		zero.pop();
		for (int i=0;i<adj[top].size();i++)
		{
			deg[adj[top][i]]--;
			if(deg[adj[top][i]]==0)
				zero.push(adj[top][i]);
		}
	}
}

void dynamic()
{
	fill(min_way ,min_way +n+1,INT_MAX/2);
	int i=0;
	while(topological[i]!=start)
		i++;
	min_way [start]=1;
	how[start]=start;
	while(i<n)
	{
		for(int j=0;j<adj[topological[i]].size();j++)
			if(min_way [topological[i]]+1<min_way [adj[topological[i]][j]])
			{
				min_way [adj[topological[i]][j]]=min_way [topological[i]]+1;
				how[adj[topological[i]][j]]=topological[i];
			}
		i++;
	}
}

void show(int k)
{
	if(k==0)
	{
		cout<<"NO WAY"<<endl;
		return;
	}
	if(k==start)
	{
		cout<<start<<"  ";
		return;
	}
	show( how [k]);
	cout<<k<<" ";
	return;
}

int main()
{
	input();
	topological_sort();
	dynamic();
	cout<<endl<<min_way [end1]-1<<endl;
	show(end1);
	return 0;
}
