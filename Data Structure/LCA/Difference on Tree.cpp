/*
Using Difference on Tree,we can calculate the edges'value of one node's sons in O(n).
It includes dfs,lca.
Here is a program of a test.
https://loj.ac/problem/10131
*/
#include<cstdio>
#define re register
const int M=1e5+5;
int n,m,ans,
	fir[M],nxt[M<<1],to[M<<1],cnt,
	fa[M][20],dep[M],val[M];
					//val[i] -> edge(i,its father) is covered val[i] times
bool vis[M];
inline void add(const int &x,const int &y){
	to[++cnt]=y;
	nxt[cnt]=fir[x];
	fir[x]=cnt;
}
void dfs1(re int u,re int father)
{
	dep[u]=dep[father]+1;
	fa[u][0]=father;
	re int e,v,i;
	for(i=0;i<18;i++)	fa[u][i+1]=fa[fa[u][i]][i];
	for(e=fir[u];e;e=nxt[e])
	{
		v=to[e];
		if(dep[v])continue;
		dfs1(v,u);
	}
}
int lca(re int x,re int y)
{
	if(dep[x]<dep[y]) return lca(y,x);	//x must be deeper
	re int i;
	for(i=18;i>=0;i--)
	{
		if(dep[fa[x][i]]>=dep[y]) x=fa[x][i];
		if(x==y) return x;
	}
	for(i=18;i>=0;i--)
	{
		if(fa[x][i]!=fa[y][i])
		{
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[x][0];
}
void dfs2(re int u)
{
	vis[u]=1;
	re int e,v;
	for(e=fir[u];e;e=nxt[e])
	{
		v=to[e];
		if(!vis[v])
		{
			dfs2(v);
			val[u]+=val[v];	
		}
	}
}
int main()
{
  scanf("%d%d",&n,&m);
	re int i,x,y;
	for(i=1;i<n;i++)
	{
    scanf("%d%d",&x,&y);
		add(x,y),add(y,x);
	}
	
	dfs1(1,0);		//to comfirm their father
	
	for(i=1;i<=m;i++)
	{
    scanf("%d%d",&x,&y);
		val[x]++,val[y]++,val[lca(x,y)]-=2;	//particular algorithm DT
	}
	
	dfs2(1);		//calculate their value
	
	for(re int i=2;i<=n;i++)
	{
		switch(val[i])
		{
			case 0: ans+=m;break;	//covered by 0 edges
			case 1: ans++; break;	//covered by 1 edges
			default: break;
		}
	}
	printf("%d",ans);
	return 0;
}
