//modify a range
//query a point
#include<cstdio>
#define lowbit(a) a&(-a)
#define re register
const int M=5e5+5;
int n,m,c[M];// c[i] refers to a[i]-a[i-1]
void update(re int i,re int data)
{
	for(;i<=500000;i+=lowbit(i)) c[i]+=data;
}
int sum(re int i)
{
	re int res=0;
	for(;i;i-=lowbit(i))	res+=c[i];
	return res;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(re int i=1,x,tmp=0;i<=n;i++)
	{
		scanf("%d",&x);
		update(i,x-tmp);	//add the difference
		tmp=x;
	}
	for(re int i=1,x,y,z;i<=m;i++)
	{
		scanf("%d",&x);
		if(x&1)	//-> x==1,add data_z on range[x,y]
		{
			scanf("%d%d%d",&x,&y,&z);
			update(x,z);	
			update(y+1,-z);	//attention on the edge
		}
		else
		{
			scanf("%d",&y);
			printf("%d\n",sum(y));
		}
	}
	return 0;
}
