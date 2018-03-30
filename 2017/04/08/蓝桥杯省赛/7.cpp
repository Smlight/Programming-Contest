#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N=110;
char s[N];
int a[N][N],now[N],len[N];

int main()
{
	scanf("%s",s);
	int n=strlen(s),cnt=0;
	for (int i=0;i<n;i++) {
		if (s[i]=='(') {
			cnt++;
			memset(a[cnt],0,sizeof(a[cnt]));
			len[cnt]=now[cnt]=0;
		} else if (s[i]==')') {
			for (int i=0;i<=now[cnt];i++)
				len[cnt]=max(len[cnt],a[cnt][i]);
			cnt--;
			a[cnt][now[cnt]]+=len[cnt+1];
		} else if (s[i]=='|') {
			now[cnt]++;
		} else if (s[i]=='x') {
			a[cnt][now[cnt]]++;
		}
	}
	for (int i=0;i<=now[0];i++)
		len[0]=max(len[0],a[0][i]);
	printf("%d\n",len[0]);
	return 0;
}
