#include<cstdio>
#define ll long long
const int M=100005;
int n,m;
ll a[M],sum[M<<2],add[M<<2];  //eyes on the datas
inline int max(const int &x,const int &y)
  {return x>y?x:y;}
inline int min(const int &x,const int &y)
  {return x<y?x:y;}
void build(int k,int l,int r) //k -> node
{
	if(l==r)    //the edge
	{
		sum[k]=a[l];
		return;
	}
	int mid=l+r>>1;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	sum[k]=sum[k*2+1]+sum[k*2]; //this node's sum comes from its two sons' sums
	return;
}
void modify(int k,ll v,int l,int r,int x,int y)
{
	if(x<=l&&r<=y)//if this node is contained in the segment[x,y]
	{             //no need to go on modifying,for the mark 'add' has marked it
		add[k]+=v;
		return; 
	}
	sum[k]+=(min(r,y)-max(x,l)+1)*v;//this node has no node to cover it,so it has to plus v
	int mid=l+r>>1;
	if(x<=mid) modify(k*2,v,l,mid,x,y);//if the segment doesn't cover its left_son,there is no need to modify this son
	if(mid<y) modify(k*2+1,v,mid+1,r,x,y);// the same theory
}
ll query(int k,int l,int r,int x,int y)
{  
    /*don't worry that every step contain plusing add[],
      if this node is covered,its sum hasn't plused the add[]
      else its sum has plused the add[],while the add[] is empty
   */
	if(x<=l&&r<=y) 
		return sum[k]+(r-l+1)*add[k];
	ll res=(min(r,y)-max(l,x)+1)*add[k];
	int mid=l+r>>1;                         //almost the same
	if(x<=mid) res+=query(k*2,l,mid,x,y);
	if(mid<y)  res+=query(k*2+1,mid+1,r,x,y);
	return res;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(register int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	build(1,1,n);    //build the segment tree
	for(register int i=1,x,y;i<=m;i++)
	{
		scanf("%d",&x);
		if(x==1)
		{
			ll z;
			scanf("%d%d%lld",&x,&y,&z);
			modify(1,z,1,n,x,y);
		}
		else
		{
			scanf("%d%d",&x,&y);
			printf("%lld\n",query(1,1,n,x,y));
		}
	}
	return 0;
 } 
