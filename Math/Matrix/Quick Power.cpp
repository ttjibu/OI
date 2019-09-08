#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
struct Mat
{
	ll g[101][101];
	ll n,m;
	void clear()
	{
		memset(g,0,sizeof(g));
		n=m=0;
	} 
}a,e,ans; //e is identity matrix
ll n,p;
Mat Mul(Mat x,Mat y)  //multiplication
{
	Mat c;
	c.clear();
	for(int i=1;i<=x.n;i++)
		for(int j=1;j<=y.m;j++)
			for(int k=1;k<=x.m;k++)
				c.g[i][j]+=x.g[i][k]*y.g[k][j];
	c.n=x.n,c.m=y.m;
	return c;
}
Mat pow(Mat x,ll y) //quick power on matrix
{
	for(int i=1;i<=n;i++)
		e.g[i][i]=1; //create the identity matrix
	e.n=e.m=n;
	Mat res=e; //initialization
	while(y) //the same as quick power on number
	{
		if(y&1)
		res=Mul(res,x);
		x=Mul(x,x);
		y>>=1;
	}
	return res;
}
void read()
{
	scanf("%lld%lld",&n,&p) ;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%lld",&a.g[i][j]);
	a.n=a.m=n;
}
void print()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%lld ",ans.g[i][j]);
		printf("\n");
	}
}
int main()
{
	read();
	ans=pow(a,p);
	print();
	return 0;
}
