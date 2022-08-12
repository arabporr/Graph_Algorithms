#include <bits/stdc++.h>

using namespace std;

const int MaxN=1e2+100;
int SP[MaxN][MaxN],n,m;

void input()
{
	cin>> n>> m;
	for (int i=1;i<=n;i++)
		fill(SP[i],SP[i]+n+1,INT_MAX/2);
	for (int i=1;i<=m ; i++)
	{
		int v,u;
		cin>> v>>u;
		cin>>SP[v][u];
		SP[u][v]=SP[v][u];
	}
}

void Floid_Warshal()
{
	for (int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				SP[k][j]=min(SP[k][j],SP[k][i]+SP[j][i]);
}

int main()
{
	input();
	Floid_Warshal();
	int k=1;
	while (k)
	{
		int y,x;
		cin>>x>>y;
		cout<<SP[x][y]<<endl;
	}
	return 0;
}
