#include<iostream>
using namespace std;
int n,m,c[500010];
inline int lowbit(int x)
{
	return x&(-x);
}
inline void update(int rank,int data)
{
	for(register int i=rank;i<=n;i+=lowbit(i))
		c[i]+=data;
}
inline int sum(int rank)
{
	int ans=0;
	for(register int i=rank;i>0;i-=lowbit(i))
		ans+=c[i];
	return ans;
}
int main()
{
	int o,p,q;
	cin>>n>>m;
	for(register int i=1;i<=n;i++)
	{
		cin>>o;
		update(i,o);
	}
	for(register int i=1;i<=m;i++)
	{
		cin>>o>>p>>q;
		if(o==1)
			update(p,q);
		else
			cout<<(sum(q)-sum(p-1))<<endl;
	}
	return 0;
}
