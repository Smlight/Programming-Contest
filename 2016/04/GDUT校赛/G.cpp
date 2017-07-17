#include <iostream> 
#include <cstdio>
#include <cstring>

int main()
{
	int T,i;
	scanf("%d\n",&T);
	while (T--)
	{
		char s[3500];
		gets(s);
		bool ch[26];
		memset(ch,0,sizeof(ch));
		for (i=0;s[i];i++)
		{
			if (s[i]>='a'&&s[i]<='z') ch[s[i]-'a']=1;
			
		}
		int ans=0;
		for (i=0;i<26;i++)
			ans+=ch[i];
		printf("%d\n",ans);
	}
	return 0;
}
