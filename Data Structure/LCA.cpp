#include<cstdio>
#define re register
const int M=5e5+5;
int n,m,root,f[M][22],dep[M],
	fir[M],to[M<<1],nxt[M<<1],cnt;
	//f[i][k] refers to the 2^k(th) ancestor of i
inline void add(const int &x,const int &y)
{
	to[++cnt]=y;
	nxt[cnt]=fir[x];
	fir[x]=cnt;
}
void readin()
{
	re int i,x,y;
	scanf("%d%d%d",&n,&m,&root);
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		add(x,y),add(y,x);
	}
}
void deal_first(int u,int fa)	//build the tree
{
	re int i,e,v;
	dep[u]=dep[fa]+1;
	for(i=0;i<=19;i++)	//transmit the ancestor
		f[u][i+1]=f[f[u][i]][i];
	for(e=fir[u];e;e=nxt[e])
	{
		v=to[e];
		if(dep[v])continue;
		f[v][0]=u;
		deal_first(v,u);
	}
}
int lca(int x,int y)
{
	if(dep[x]<dep[y])	return lca(y,x);//keep x as the deepest
	re int i;
	for(i=20;i>=0;i--)	//run in reverse order so not to skip the point
	{
		if(dep[f[x][i]]>=dep[y])	//using the binary stuffs
			x=f[x][i];
		if(x==y)	//spj when x and y are on the same branch
			return x;
	}
	for(i=20;i>=0;i--)	//now x and y are at the same deepth
	{					//using reverse order as above
		if(f[x][i]!=f[y][i])	//hop!
		{
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];	//their latest common ancestor
}
void query()
{	
	for(re int i=1,x,y;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		printf("%d\n",lca(x,y));
	}
}
int main()
{
	readin();
	deal_first(root,0);	//make up a fake father of the root
	query();
	return 0;
}
