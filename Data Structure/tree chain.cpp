//first of all ,eyes on the datas's type(ll available only)
#include<cstdio>
#define re register
#define ll long long
const int M=2e5+5;
int n,m,root,
	top[M],son[M],siz[M],dep[M],fa[M],seg[M],rev[M],
	fir[M],next[M<<1],to[M<<1],cnt;
ll mod,a[M],sum[M<<2],add[M<<2],ans;//emphasize it again:the datas's type
inline void swap(int &x,int &y)
  {int t=x;x=y;y=t;}
inline int max(const int &x,const int &y)
  {return x>y?x:y;}
inline int min(const int &x,const int &y)
  {return x<y?x:y;}
void add_edge(int x,int y)
{
	to[++cnt]=y;
	next[cnt]=fir[x];
	fir[x]=cnt;
}
void dfs1(int u,int father)//first dfs for the siz[],fa[],dep[],son[](the node's heaviest son(no heaviest son is possible))
{
	siz[u]=1;  //initialization
	fa[u]=father;
	dep[u]=dep[father]+1;
	int v,e;
	for(e=fir[u];e;e=next[e])
	{
		v=to[e];
		if(v!=father)  //don't offend your papa
		{
			dfs1(v,u);
			if(siz[son[u]]<siz[v])
				son[u]=v;
			siz[u]+=siz[v];  //searching its heavier son
		}
	}
}
void dfs2(int u) //second dfs for the top[],seg[],rev[]
{
	int e,v=son[u];
	if(v)   //run its h-son firstly for keep the heavy road consecutive
	{
		seg[v]=++seg[0]; //seg[x] refers that the subscripted of the node(x is its subscripted in the original tree) in the segment tree
		rev[seg[0]]=v;  //rev[x] refers that the subscripted of the node(x is its subscripted in the segment tree) in the original tree
		top[v]=top[u]; //top[x] refers to the root of the h-road the node belongs to
		              //the nodes of the same h-road has the same top[]
		dfs2(v);  //dfs its h-son at once if available
	}
	for(e=fir[u];e;e=next[e])
	{
		v=to[e];
		if(!top[v])//top[] isn't set,which means this node is the root of a new h-road
		{
			seg[v]=++seg[0];//set the information
			rev[seg[0]]=v;
			top[v]=v;  //itself is the top[]
			dfs2(v);
		}
	}
}
void build(int k,int l,int r)
{
	if(l==r)
	{
		sum[k]=a[rev[l]];//rev[] connect the original tree and the segment tree
		return ;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build((k<<1)+1,mid+1,r);
	sum[k]=sum[k<<1]+sum[(k<<1)+1];//nothing various
}
void modify(int k,ll v,int l,int r,int x,int y)
{
	if(x<=l&&r<=y)
	{
		add[k]+=v;  //mark the target
		return ;
	}
	sum[k]+=(min(r,y)-max(x,l)+1)*v;  //for more explanations please go through the chapter of 'segment tree'
	int mid=l+r>>1;
 	if(x<=mid) modify(k<<1,v,l,mid,x,y);
	if(mid<y)  modify((k<<1)+1,v,mid+1,r,x,y);
}
void query(int k,int l,int r,int x,int y) //I have to type it 'void' 'cause the datas are too too large
{
	if(x<=l&&r<=y)
	{
		ans+=sum[k]+add[k]*(r-l+1);
		ans%=mod;     //even it is moded
		return;
	}
	int mid=l+r>>1;
	ans+=(min(r,y)-max(x,l)+1)*add[k];
	ans%=mod;  // keke,mod
	if(x<=mid) query(k<<1,l,mid,x,y);
	if(mid<y)  query((k<<1)+1,mid+1,r,x,y);
	return ;
}
void ask1(int x,int y)    //!point!
{
	int fx=top[x],fy=top[y];//interact the original tree in segment tree's way
	if(dep[fx]<dep[fy])swap(x,y),swap(fx,fy); //remain the x as the deepest
											  //clearly that the deeper must be calculated
	while(fx!=fy)     //the two node is not on the same h-road,which means at least the deeper h-road(from this node to its top[]) is part of the asked part
	{
		query(1,1,n,seg[fx],seg[x]);   //don't forget function query's type is void
		x=fa[fx];      //jump to the last h-road(so rapid,isn't it)
		fx=top[x];
		if(dep[fx]<dep[fy])swap(x,y),swap(fx,fy); //remain...
	 } 
	if(dep[y]>dep[x]) swap(x,y); //up to this step, the two node are on the same h-road
								//and don't forget remain...
	query(1,1,n,seg[y],seg[x]);
}
void change1(int x,int y,ll v) //nearly the same
{
	int fx=top[x],fy=top[y];
	if(dep[fx]<dep[fy])swap(x,y),swap(fx,fy);
	while(fx!=fy)
	{
		modify(1,v,1,n,seg[fx],seg[x]);
		x=fa[fx];
		fx=top[x];
		if(dep[fx]<dep[fy]) swap(x,y),swap(fx,fy);
	}
	if(dep[y]>dep[x]) swap(x,y);
	modify(1,v,1,n,seg[y],seg[x]);
	return ;
}
int main()
{
	int p,q;
	ll o;
	scanf("%d%d%d%lld",&n,&m,&root,&mod);
	for(re int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(re int i=1;i<n;i++)
	{
		scanf("%d%d",&p,&q);
		add_edge(q,p);add_edge(p,q);
	}
	dfs1(root,0);//step by step
	seg[root]=++seg[0];//these three steps are points too
	top[root]=root;
	rev[1]=root;
	dfs2(root);
	build(1,1,seg[0]);
	for(re int i=1;i<=m;i++)
	{
		scanf("%d",&p);
		switch(p)   //according to the requests
		{
			case 1:{
				scanf("%d%d%lld",&p,&q,&o);
				change1(p,q,o);
				break;
			}
			case 2:{
				scanf("%d%d",&p,&q);
				ans=0;
				ask1(p,q);
				printf("%lld\n",ans);
				break;
			}
			case 3:{
				scanf("%d%lld",&p,&o);
				modify(1,o,1,n,seg[p],seg[p]+siz[p]-1);
				break;
			}
			case 4:{
				scanf("%d",&p);
				ans=0;
				query(1,1,n,seg[p],seg[p]+siz[p]-1);
				printf("%lld\n",ans);
				break;
			}
		}
	}
	return 0;
 } 
