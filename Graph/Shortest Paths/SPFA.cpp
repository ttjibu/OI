#include<queue>
#include<cstdio>
#define re register
#define INF 0x7fffffff
using namespace std;
const int M1=1e4+5,M2=5e5+5;
int n,m,start,dis[M1],
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
	scanf("%d%d%d",&n,&m,&start);
	re int i,x,y,z;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);	//build the graph
	}	
}
void SPFA()
{
	for(re int i=1;i<=n;i++)dis[i]=INF;	//ini for update
	re int u=start,e,v;
	queue<int> que;
	vis[u]=1;
	dis[u]=0;	//initialize the start point
	que.push(u);
	while(!que.empty())
	{
		u=que.front();
		que.pop();
		vis[u]=0;	//pop u of the queue
		for(e=fir[u];e;e=nxt[e])	//use u to update dis[]
		{
			v=to[e];
			if(dis[v]>dis[u]+wei[e]) //able to be updated
			{
				dis[v]=dis[u]+wei[e];
				if(!vis[v])	//not in queue
				{
					vis[v]=1;
					que.push(v);	//push it into the queue
				}
			}
		}
	}
}
int main()
{
	readin();
	SPFA();
	for(re int i=1;i<=n;i++)
		printf("%d ",dis[i]);
	return 0;
}
