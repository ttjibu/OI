#include<iostream>
typedef long long ll;
using namespace std;
ll pow(int x,int y) //the key is binary stuffs
{
	ll ans=1;
	while(y)
	{
		if(y&1)ans*=x;
		y>>=1;
		x*=x;
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
