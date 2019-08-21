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
	cin>>n>>m;
	for(register int i=1,o,t=0;i<=n;i++)
	{
		cin>>o;
		update(i,o-t);
		t=o;
	}
	for(register int i=1,o,l,r,k;i<=m;i++)
	{
		cin>>o;
		if(o==1)
		{
			cin>>l>>r>>k;
			update(l,k);
			update(r+1,0-k);   //modify the distinction
		}
		else
		{
			cin>>k;
			cout<<sum(k)<<endl;
		}
	}
	return 0;
}
