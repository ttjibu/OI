//directed graph
#include<cstdio>
#include<iostream>
#define re register
using namespace std;
const int M1=1e4+5,M2=5e4+5;
int n,m,ans,edge[M2][2],	//edge[i][0] -> edge[i][1]
	fir[M1],nxt[M2],to[M2],cnt,
	low[M1],dfn[M1],dfstime,
	co[M1],col,val[M1],
	sta[M1],top;
inline void add(const int &x,const int &y)
{
	to[++cnt]=y;
	nxt[cnt]=fir[x];
	fir[x]=cnt;
}
void readin()
{
	scanf("%d%d",&n,&m);
	for(re int i=1;i<=m;i++)
	{
		scanf("%d%d",&edge[i][0],&edge[i][1]);
		add(edge[i][0],edge[i][1]);
	}
}
void tarjan(int u)
{
	dfn[u]=low[u]=++dfstime;	//particular low[i]
	sta[++top]=u;	//enter the stack
	re int e,v;
	for(e=fir[u];e;e=nxt[e])
	{
		v=to[e];
		if(!dfn[v])	//not yet searched
		{
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(!co[v])	//not in the stack
			low[u]=min(low[u],dfn[v]);	//low[v] may not yet reset
	}
	if(low[u]==dfn[u])	//root of a strongly connected
	{
		co[u]=++col;	//new stco
		val[col]++;		//the element'population of the stco
		while(sta[top]!=u)	//in the co
		{
			co[sta[top]]=col;
			val[col]++;
			top--;	//pop it
		}
		top--;	//or sta[top]=u
	}
}
int main()
{
	readin();
	for(re int i=1;i<=n;i++)
		if(!dfn[i])tarjan(i);
   //Here is your showtime...
	return 0;
}
