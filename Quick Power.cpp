#include<iostream>
typedef long long ll;
using namespace std;
ll f(int p,int q)
{
	ll ans=1;
	
	while(q>0)
	{
		if(q&1)ans*=p;
		q>>=1;
		p*=p;
	}
	return ans;
}
int main()
{
	int n,m;
	cin>>n>>m;
	cout<<f(n,m);
	return 0;
 } 
