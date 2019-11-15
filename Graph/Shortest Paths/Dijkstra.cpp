#include<queue>
#include<cstdio>
#define re register
#define INF 0x7fffffff
using namespace std;
const int M1=1e5+5,M2=5e5+5;
int n,m,start,dis[M1],
	fir[M1],nxt[M2],to[M2],wei[M2],cnt;
bool vis[M1];
struct node{
	int to,dis;
	bool operator <(const node &x)const {	//hand-make cmp
		return dis>x.dis;
	}	//priority is a less heep,so we should reverse cmp
};
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
void Dj()
{
	for(re int i=1;i<=n;i++)dis[i]=INF;	//ini dis for update
	priority_queue<node> heep;
	re int u=start,e,v;
	dis[u]=0;
	heep.push((node){u,0});
/*
(node){i,j}  ->  node x; x.first=i,x.second=j; x
first and second must based on the order of struct node's defination
in this case 
first -> to, second -> dis
*/
	while(!heep.empty())
	{
		u=heep.top().to;
		heep.pop();	//pick out the shortest path's point
		if(vis[u])continue;	//skip when it's visited
		vis[u]=1;		//don't reset it until it is used for update
		for(e=fir[u];e;e=nxt[e])
		{
			v=to[e];
			if(dis[v]>dis[u]+wei[e])	//able to update
			{
				dis[v]=dis[u]+wei[e];
				if(!vis[v])		//not yet used to update
					heep.push((node){v,dis[v]});
						//don't reset vis[v] at once
						//or a shorter path may be missed
			}
		}
	}
}
int main()
{
	readin();
	Dj();
	for(re int i=1;i<=n;i++)
		printf("%d ",dis[i]);
	return 0;
}
