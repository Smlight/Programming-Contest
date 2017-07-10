#include <bits/stdc++.h>
using namespace std;

const int MAXN=10000;
int prime[MAXN+1];
int ptot=0;
int vis[505];
int sg[505][505];

void getPrime()
{
    memset(prime,0,sizeof(prime));
    for(int i=2;i<=MAXN;i++) {
        if(!prime[i])prime[++ptot]=i;
        for(int j=1;j<=ptot&&prime[j]<=MAXN/i;j++) {
            prime[prime[j]*i]=1;
            if(i%prime[j]==0) break;
        }
    }
}

int main()
{
    getPrime();
    int n=500,m=500;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            memset(vis,0,sizeof(vis));
            for (int x=1;prime[x]<min(i,j);x++) {
                vis[sg[i-prime[x]][j-prime[x]]]=1;
            }
            for (int x=1;prime[x]<i;x++) {
                vis[sg[i-prime[x]][j]]=1;
            }
            for (int y=1;prime[y]<j;y++) {
                vis[sg[i][j-prime[y]]]=1;
            }
            int x=0;
            while (vis[x]) x++;
            sg[i][j]=x;
        }
    }
    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&n,&m);
        puts(sg[n][m]?"Sora":"Shiro");
    }
    return 0;
}
