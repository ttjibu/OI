#include<cstdio>
int gcd(int x,int y)
{
	if(y>x)return gcd(y,x);
	int z;
	while(y!=0)
	{
		z=x%y;
		x=y;
		y=z;
	}
	return x;
}
/*
int gcd(int x,int y)
{
	if(y>x)return gcd(y,x);
	if(y==0)return x;
	return gcd(y,x%y);
}
*/
int main()
{
	int p,q;
	scanf("%d%d",&p,&q);
	printf("%d",gcd(p,q));
	return 0;
}
