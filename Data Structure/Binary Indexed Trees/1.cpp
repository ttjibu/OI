//modify a point
//query the sum of a range
#include<cstdio>
#define lowbit(a) a&(-a)
#define re register
const int M=5e5+5;
int n,m,c[M];
void update(re int rank,re int data)
{
	for(;rank<=500000;rank+=lowbit(rank))
		c[rank]+=data;
}
int sum(re int rank)
{
	re int res=0;
	for(;rank;rank-=lowbit(rank))
		res+=c[rank];
	return res;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(re int i=1,x;i<=n;i++)
	{
		scanf("%d",&x);	//add data_x at rank_i
		update(i,x);
	}
	for(re int i=1,x,y,z;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		if(x&1)	//-> x==1,  add data_z at rank_y
			update(y,z);
		else	//-> x==2,	cal sum of the range [y,z]
			printf("%d\n",sum(z)-sum(y-1));
	}
	return 0;
}
