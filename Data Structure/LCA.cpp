#include<cstdio>

const int M=500005;
int n,m,root,fir[M],cnt,dep[M],f[M][22];
struct edge{
	int to,next;
}a[M<<1];
inline void add_edge(int x,int y)
{
	a[++cnt].to=y;
	a[cnt].next=fir[x];
	fir[x]=cnt;
	return ;
}
void Deal_first(int u,int father)
{
	dep[u]=dep[father]+1;
	f[u][0]=father;
	for(int i=1;f[u][i-1]!=0;i++)//
	{
		f[u][i]=f[f[u][i-1]][i-1];
	}
	for(int i=fir[u];i;i=a[i].next)
	{
		int v=a[i].to;
		if(v==father)continue;
		Deal_first(v,u);
	}
	return ;
}
int lca(int x,int y)
{
	if(dep[x]<dep[y])return lca(y,x);
	for(int i=20;i>=0;i--)
	{
		if(dep[f[x][i]]>=dep[y])
			x=f[x][i];
		if(x==y)
			return x;
	}
	for(int i=20;i>=0;i--)
	{
		if(f[x][i]!=f[y][i])
		{
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
	
}
int main()
{
	scanf("%d%d%d",&n,&m,&root);
	for(int I=1,x,y;I<n;I++)
	{
		scanf("%d%d",&x,&y);
		add_edge(x,y);
		add_edge(y,x);
	}
	Deal_first(root,0);
	for(int I=1,p,q;I<=m;I++)
	{
		scanf("%d%d",&p,&q);
		printf("%d\n",lca(p,q));
	}
	return 0;
 } 
