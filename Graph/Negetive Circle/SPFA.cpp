#include<queue>
#include<cstdio>
#define re register
#define INF 0x7fffffff
using namespace std;
const int M1=2e3+5,M2=6e3+5;
int n,m,dis[M1],t[M1],	//t -> times
	fir[M1],nxt[M2],to[M2],wei[M2],cnt;
bool vis[M1];
inline void add(const int &x,const int &y,const int &z)
{
	to[++cnt]=y;
	wei[cnt]=z;
	nxt[cnt]=fir[x];
	fir[x]=cnt;
}
void readin()
{
	scanf("%d%d",&n,&m);
	re int i,x,y,z;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);	//build the graph(directive)
		//add(y,x,z)	//undirective
	}
}
bool SPFA()
{
	for(re int i=1;i<=n;i++) dis[i]=INF;
	re int u=1,e,v;
	queue<int> que;
	vis[u]=1;
	dis[u]=0;
	t[u]++;		//ini ,almost the same
	que.push(u);
	while(!que.empty())
	{
		u=que.front();
		que.pop();
		vis[u]=0;
		for(e=fir[u];e;e=nxt[e])
		{
			v=to[e];
			if(dis[v]>dis[u]+wei[e])
			{
				dis[v]=dis[u]+wei[e];
				if(vis[v])continue;
        vis[v]=1;
        que.push(v);
        t[v]++; //the only difference is record the times of a point entering the queue
        if(t[v]>n) return true;
        //more than n times,must have negetive circle
			}
		}
	}
	return false;
}
int main()
{
	readin();
	if(SPFA()) printf("YES\n");
	else  printf("NO\n");
	return 0;
}
