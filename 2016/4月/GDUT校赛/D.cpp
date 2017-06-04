#include <iostream> 
#include <cstdio>
#include <cstring>

char s[100010];

bool check(char *s)
{
	int l=strlen(s),i;
	int sh=(s[0]=='#');
	for (i=1;i<l;i++)
	{
		if (s[i-1]=='#'&&s[i]=='#') return false;
		if (s[i]=='#') sh++;
	}
	if (sh>l-sh+1) return false;
	return true;
}

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%s",s);
		if (check(s)) puts("yes");
		else puts("no");
	}
}
