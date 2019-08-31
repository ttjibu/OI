#include<iostream>
#define re register
using namespace std;
const int M=105;
int n,m,a[M][M],b[M][M],c[M][M];
int main()
{
	cin>>n>>m;
	for(re int i=1;i<=n;i++)
		for(re int j=1;j<=m;j++)
	cin>>a[i][j];
	
	for(re int i=1;i<=n;i++)
	{
		for(re int j=1;j<=m;j++)
		{
	    	cin>>b[i][j];
	  		c[i][j]=b[i][j]+a[i][j];
	  	}
	}
	cout<<endl<<c[1][1];
	for(re int i=2;i<=m;i++)
		cout<<" "<<c[1][i];
	for(re int i=2;i<=n;i++)
	{
		cout<<endl<<c[i][1];
		for(re int j=2;j<=m;j++)
	  		cout<<" "<<c[i][j];
	} 
	return 0;
 } 
