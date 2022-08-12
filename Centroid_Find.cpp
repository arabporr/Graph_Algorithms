#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MaxN=1e5+100;

int n;
int deg[MaxN];
vector < int > adj [MaxN];
bool mark [MaxN];
queue <int> step [MaxN],New,Old;

void input()
{
	 cin>> n;
	 for (int i=1;i<n;i++)
	 {
	 	int u,v;
	 	cin>> u>>v;
	 	adj[v].push_back(u);
	 	adj[u].push_back(v);
	 	deg[v]++;
	 	deg[u]++;
	 }
}

void show(queue<int> q)
{
	while(q.empty()==false){
		cout<<q.front();
		q.pop();
	}
}

void Find_Cent()
{
	for(int i=1;i<=n;i++)
	{
		if(deg[i]==1)
			{
				New.push(i);
				step[1].push(i);
			}
	}

	int j=0;
	int cnt=0;

	while(cnt<n-2)
	{
		j++;
		Old=New;
		queue<int> q;
		New=q;
		while (!Old.empty())
		{
			int v=Old.front();
			Old.pop();
			step[j].push(v);
			cnt++;
			for(int i=0;i<adj[v].size();i++)
			{
				deg[adj[v][i]]--;
				if( deg [adj[v][i]]==1)
				{
					New.push(adj[v][i]);
				}
			}
		}
	}
	show(New);
}

int main()
{
	input();
	Find_Cent();
	return 0;
}
