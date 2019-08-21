#include<cstdio>
#include<cstring>
using namespace std;
const int M=1000005;
int n,m,tot=1;  //tot is to record the number of node
int ch[M][26];  //the smart TRIE(small letter only)
bool vis[M]; //to record a class of words
void make_tree(char *s)  //transmit the pointer type to make it faster
{
	int len=strlen(s),u=1;//u is just like the pointer
	for(int i=0;i<len;i++)
	{
		int c=s[i]-'a'; //this works when small letters only
		if(!ch[u][c])   //which means the word has never appeared before
			ch[u][c]=++tot;   //give it a rank
		u=ch[u][c];   //transmitting
	}
	vis[u]++;     //this word has appeared
}
int find(char *s)//find whether the word has appear
{
	int len=strlen(s),u=1;
	for(int i=0;i<len;i++)
	{
		int c=s[i]-'a';
		if(ch[u][c]) u=ch[u][c];  //the same principle as above
		else    return 0;
	}
	if(vis[u]) return 1;
	else  return 0;
}
int main()
{
	scanf("%d",&n);  //read the quantity of words
	char str[M];
	for(int i=1;i<=n;i++)
	{
		scanf("%s",str);
		make_tree(str);
	}
	scanf("%d",&m);  //read the times to query
	for(int i=1;i<=m;i++)
	{
		scanf("%s",str);
		if(find(str)) printf("Yes\n");
		else   printf("No\n");
	}
	return 0;
}
