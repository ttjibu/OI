#include<iostream>
typedef long long ll;
using namespace std;
ll pow(int p,int q) //the key is binary stuffs
{
	ll ans=1;
	while(q)
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
	cout<<pow(n,m);
	return 0;
 } 
