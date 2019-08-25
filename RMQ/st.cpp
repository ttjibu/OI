#include<cstdio>
const int M=1e5+5;
int n,m,a[M],f[M][35],log[M];
inline int max(const int &x,const int &y)
 {return x>y?x:y;}     //handmade compared function
int main()
{
	log[0]=-1; //in attemp to achieve log[1]=0;
	scanf("%d%d",&n,&m);
	for(register int i=1;i<=n;i++){  //initialazation
		scanf("%d",&a[i]);
		f[i][0]=a[i];    //f[i][j] refers to the max on [i,i+2^j-1]
		log[i]=log[i>>1]+1; //log[] should adapt to the quantity of the data
	}
	for(register int j=1;j<=20;j++)
	{
		for(register int i=1;i+(1<<j)-1<=n;i++)
		{
			f[i][j]=max(f[i][j-1],f[i+(1<<j-1)][j-1]);  //dynamic program
		}
	}
	int x,y,s;
	for(register int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);  //input the left and the right
		s=log[y-x+1];    //s is according to the equation
		printf("%d\n",max(f[x][s],f[y-(1<<s)+1][s]));
	}
	return 0;
}
