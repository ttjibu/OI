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
	for(int i=1,j=0;i<len2;i++)   //Ԥ���� p���� 
	{
		while(j&&s2[i]!=s2[j])  //�� s2[i]==s2[j],���ҵ�ǰ׺���׺��ͬ��λ�ã�����ѭ�� 
			j=p[j];             //���⣬�� j==0 ,����ǰ�Ӵ�������ǰ��׺��ȵ������Ҳ���� 
		if(s2[i]==s2[j])   //���ܹ�ƥ�䣬��һλ�� pֵ��������һλ 
			p[i+1]=++j;
	}
	for(int i=0,j=0;i<len1;i++)
	{
		while(j&&s1[i]!=s2[j]) //s2ǰ��׺��Ϊ 0������ʱδ�ҵ��µ�ƥ����㣬�ͼ���ѭ�� 
			j=p[j];
		if(s1[i]==s2[j])    //����ǰ��ȣ���s2��ָ����� 
			j++;
		if(j==len2)        //�Ӵ���ƥ�����ˣ����������ʼ��λ�� 
			printf("%d\n",i-j+2);
	}
	for(int i=1;i<=len2;i++)    //��ӡ p���� 
		printf("%d ",p[i]);
	return 0;
 } 
