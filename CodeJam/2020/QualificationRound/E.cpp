#include <bits/stdc++.h>
using namespace std;

const int N=55;
int a[N][N];

int uN,vN;
int g[N][N];
int linker[N];
bool used[N];
bool dfs(int u)
{
    for(int v = 1; v <= vN; v++)
        if(g[u][v] && !used[v]) {
            used[v] = true;
            if(linker[v] == -1 || dfs(linker[v])) {
                linker[v] = u;
                return true;
            }
        }
    return false;
}
int hungary()
{
    int res = 0;
    memset(linker,-1,sizeof(linker));
    for(int u = 1; u <= uN; u++) {
        memset(used,false,sizeof(used));
        if(dfs(u))res++;
    }
    return res;
}
void output(int n)
{
    puts("POSSIBLE");
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            printf("%d%c",a[i][j]," \n"[j==n]);
        }
    }
}

int main()
{
    int T,cas=0;
    scanf("%d",&T);
    while (T--) {
        memset(a,0,sizeof(a));
        int n,k;
        scanf("%d%d",&n,&k);
        printf("Case #%d: ",++cas);
        if (k%n==0) {
            k/=n;
            for (int i=1;i<=n;i++) {
                for (int j=1;j<=n;j++) {
                    a[i][(i+j-1)%n+1]=(k+j-1)%n+1;
                }
            }
            output(n);
            continue;
        }
        if (n<=3) {
            puts("IMPOSSIBLE");
        } else {
            int A,B,C;
            bool ok=false;
            for (A=1;A<=n;A++) if (A*(n-2)<=k) {
                int m=k-A*(n-2);
                for (B=1;B<=n;B++) if (A!=B) {
                    C=m-B;
                    if (1<=C && C<=n && A!=C) {
                        ok=true;
                        break;
                    }
                }
                if (ok) break;
            }
            if (!ok) {
                puts("IMPOSSIBLE");
                continue;
            }
            a[1][1]=B; a[2][2]=C;
            for (int i=3;i<=n;i++) a[i][i]=A;
            // output(n);
            uN=vN=n;
            for (int i=1;i<=n;i++) {
                memset(g,0,sizeof(g));
                g[a[i][i]][i]=1;
                for (int j=1;j<=n;j++) if (j!=i) {
                    for (int r=1;r<=n;r++) g[r][j]=1;
                    g[a[i][i]][j]=0;
                    for (int r=1;r<=n;r++) g[a[r][j]][j]=0;
                }
                int m=hungary();
                assert(m==n);
                for (int j=1;j<=n;j++) a[i][j]=linker[j];
                // output(n);
            }
            output(n);
        }
    }
    return 0;
}