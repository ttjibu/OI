#include<iostream>
#define re register
using namespace std;
int main()
{
	const int M=105;
	int n,m,p,q,a[M][M],b[M][M],c[M][M];
	cin>>n>>m;
	for(re int i=1;i<=n;i++)
		for(re int j=1;j<=m;j++)
			cin>>a[i][j];
	cin>>p>>q;
	if(m!=p)
	{
		cout<<"error";
		return 0;
	}
	for(re int i=1;i<=p;i++)
		for(re int j=1;j<=q;j++)
	    	cin>>b[i][j];
	for(re int i=1;i<=n;i++)
		for(re int j=1;j<=q;j++)
			for(re int k=1;k<=m;k++)
		c[i][j]+=a[i][k]*b[k][j];
	
	cout<<endl<<c[1][1];
	for(re int i=2;i<=q;i++)
	cout<<" "<<c[1][i];
	for(re int i=2;i<=n;i++)
	{
		cout<<endl<<c[i][1];
		for(re int j=2;j<=q;j++)
	  		cout<<" "<<c[i][j];
	} 
	return 0;
 } 
