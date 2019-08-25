//priotiry queue is suitable in the MPQ problem only
//while it is less effective .
//but it is still worth to learn
#include<cstdio>
#include<queue>
#include<vector>
#define re register
using namespace std;
const int M=1e6+5;
int n,k;
struct node1{
	int rank,value;
}a1[M];
bool operator <(const node1 &x,const node1 &y)
  {return x.value>y.value;}
//hand-made cmp function(killing me nearly)
struct node2{
	int rank,value;
}a2[M];
bool operator <(const node2 &x,const node2 &y)
  {return x.value<y.value;}
priority_queue<node1> que_min;
priority_queue<node2> que_max;//no asking why I don't use the 'less'

int main()
{
	scanf("%d%d",&n,&k);
	for(re int i=1;i<=n;i++)
	{
		scanf("%d",&a1[i].value);
		a2[i].value=a1[i].value;
		a1[i].rank=a2[i].rank=i;
	}
	for(re int i=1;i<=n;i++)  //cal the min
	{
		que_min.push(a1[i]);
		node1 now=que_min.top();
		while(now.rank<i-k+1)
		{
			que_min.pop();
			now=que_min.top();
		}
		if(i>=k)
		printf("%d ",now.value);
	}
	printf("\n");
	for(re int i=1;i<=n;i++)  //cal the max
	{
		que_max.push(a2[i]);
		node2 now=que_max.top();
		while(now.rank<i-k+1)
		{
			que_max.pop();
			now=que_max.top();
		}
		if(i>=k)
		printf("%d ",now.value);
	}
	return 0;
}
