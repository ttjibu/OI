#include<cstdio>
#include<cstring>
using namespace std;
const int M=1e6+5;
char s1[M],s2[M];
int p[M],len1,len2;
int main()
{
	scanf("%s%s",s1,s2);
	len1=strlen(s1),len2=strlen(s2);
	for(int i=1,j=0;i<len2;i++)   //预处理 p数组 
	{
		while(j&&s2[i]!=s2[j])  //若 s2[i]==s2[j],即找到前缀与后缀相同的位置，跳出循环 
			j=p[j];             //另外，当 j==0 ,即当前子串不存在前后缀相等的情况，也跳出 
		if(s2[i]==s2[j])   //若能够匹配，下一位的 p值可沿用这一位 
			p[i+1]=++j;
	}
	for(int i=0,j=0;i<len1;i++)
	{
		while(j&&s1[i]!=s2[j]) //s2前后缀不为 0，且暂时未找到新的匹配起点，就继续循环 
			j=p[j];
		if(s1[i]==s2[j])    //若当前相等，则s2的指针后移 
			j++;
		if(j==len2)        //子串被匹配完了，则输出其起始点位置 
			printf("%d\n",i-j+2);
	}
	for(int i=1;i<=len2;i++)    //打印 p数组 
		printf("%d ",p[i]);
	return 0;
 } 
