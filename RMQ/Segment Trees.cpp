#include<cstdio>
#define max(a,b) a>b?a:b
const int M=100005;
int n,m;
int a[M],maxx[M<<2];
void build(int k,int l,int r) //k -> node
{
	if(l==r)    //the edge
	{
		maxx[k]=a[l];
		return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build((k<<1)+1,mid+1,r);
	maxx[k]=max(maxx[(k<<1)+1],maxx[k<<1]); //this node's maxx comes from its two sons' maxxs
	return;
}
int query(int k,int l,int r,int x,int y)
{  
	if(x<=l&&r<=y) 
		return maxx[k];
	int res=0;  //inl
	int mid=l+r>>1;
	if(x<=mid) res=max(res,query(k<<1,l,mid,x,y)); //reset
	if(mid<y)  res=max(res,query((k<<1)+1,mid+1,r,x,y));
	return res;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(register int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	build(1,1,n);    //build the segment tree
	for(register int i=1,x,y;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		printf("%d\n",query(1,1,n,x,y));
	}
	return 0;
} 
