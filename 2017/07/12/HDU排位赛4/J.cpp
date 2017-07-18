#include <bits/stdc++.h>
using namespace std;

const int N=1001;
int sg[N];
int vis[110];
char s[1010];
int a[1010];

void init()
{
    sg[1]=0;
    sg[0]=0;
    for (int i=2;i<N;i++) {
        memset(vis,0,sizeof(vis));
        for (int j=0;j+j<=i-2;j++) {
            vis[sg[j]^sg[i-2-j]]=1;
        }
        int x=0;
        while (vis[x]) x++;
        sg[i]=x;
    }
}

int main()
{
    init();
    int T,n;
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        scanf("%s",s);
        int top=0,now=0;
        for (int i=0;s[i];i++) {
            if (s[i]=='1') now++;
            else {
                a[top++]=now;
                now=0;
            }
        }
        if (now) a[top++]=now;
        int ans=0;
        for (int i=0;i<top;i++) {
            ans^=sg[a[i]];
        }
        puts(ans?"Alice":"Bob");
    }
    return 0;
}
