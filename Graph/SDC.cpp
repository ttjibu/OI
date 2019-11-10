//system of difference constraints
//https://www.luogu.org/problem/P1250
#include<cstdio>
#include<cstring>
#include<queue>
#define re register
using namespace std;
const int M=3e4+5;
int n,m,dis[M],
	fir[M],nxt[M<<2],to[M<<2],wei[M<<2],cnt;
bool vis[M];
queue<int> que;
inline void add(const int &x,const int &y,const int &z){
	to[++cnt]=y;
	wei[cnt]=z;
	nxt[cnt]=fir[x];
	fir[x]=cnt;
}
void SPFA()		//run the furthest distance
{
	memset(dis,-1,sizeof(dis));	//ini [dis] so that 0 can be and do update(d)
	int u,e,v;
	u=0;		//start from 0
	dis[u]=0;
	vis[u]=1;
	que.push(u);
	while(!que.empty())
	{
		u=que.front();
		que.pop();
		vis[u]=0;	//reset into false ( not like dfs )
		for(e=fir[u];e;e=nxt[e])
		{
			v=to[e];
			if(dis[v]<dis[u]+wei[e])	//don't forget the model of SPFA
			{
				dis[v]=dis[u]+wei[e];	//update
				if(!vis[v])
				{
					que.push(v);		//push into
					vis[v]=1;
				}
			}
		}
	}
	return;
}
int main()
{
	freopen("a.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for(re int i=1,x,y,z;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		add(x-1,y,z);	//make edges
	}
/*
	attention!!!!!	
	s[i]-s[j]>=c  --->	add(j,i,c)
*/	
	for(re int i=0;i<n;i++)
	{
		add(i+1,i,-1);
		add(i,i+1,0);
		//attention again	!!!
	}
	SPFA();
	printf("%d",dis[n]);
	return 0;
}
