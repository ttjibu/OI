//Monotonous priority queue is lack for the flexibility.
//While it is really fast up to O(n).
#include<cstdio>
#define re register
const int M=1e6+5;
int n,m,a[M],maxx[M],minn[M],
	head,tail,que[M],num[M];
void dp_min()
{
	head=1,tail=0;
//this setting is to deal with the front elements which are in ranges that shorter than 'm'
	que[tail]=num[head]=0; //inlitialazation
	for(re int i=1;i<=n;i++)
	{
		while(num[head]<i-m+1&&head<=tail)	head++; //the first element isn't in the range,pop it
		while(que[tail]>=a[i]&&head<=tail)	tail--; //dealing the present element 
//if it is fixed(not smaller than the last one),pop the last one by dealing the pointer'tail'
		num[++tail]=i;
		que[tail]=a[i];//enter the queue
		minn[i]=que[head];//record
	}
}
void dp_max() //almost the same
{
	head=1,tail=0;
	que[tail]=num[head]=0;
	for(re int i=1;i<=n;i++)
	{
		while(num[head]<i-m+1&&head<=tail)	head++;
		while(que[tail]<=a[i]&&head<=tail)	tail--;
		num[++tail]=i;
		que[tail]=a[i];
		maxx[i]=que[head];
	}
}
int main()
{
	scanf("%d%d",&n,&m); //m refers to the length of the range
	for(re int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	dp_min();
	dp_max();
	
	for(re int i=1;i<=n;i++)
		printf("%d ",minn[i]); //print them
	printf("\n");
	for(re int i=1;i<=n;i++)
		printf("%d ",maxx[i]);
	return 0;
}
