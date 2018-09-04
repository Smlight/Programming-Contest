#include <bits/stdc++.h>
using namespace std;
using ll = long long;

namespace AC_DFA {
    const int Csize=26,AN=111;
    int tot,son[AN][Csize],sum[AN],fail[AN],q[AN],dph[AN],vis[AN];
    int dp[100010][AN];
    void Initialize() {
        memset(dph,0,sizeof(int)*(tot+1));
        memset(fail,0,sizeof(int)*(tot+1));
        memset(sum,0,sizeof(int)*(tot+1));
        for (int i=0;i<=tot;i++) {
            for (int j=0;j<Csize;j++) {
                son[i][j]=0;
            }
        }
        tot=0; fail[0]=-1;
    }
    inline int Tr(char ch) {
        return ch-'a';
    }
    int Insert(char *s) {
        int x=0;
        for (int l=strlen(s),i=0,w;i<l;i++) {
            if (!son[x][w=Tr(s[i])]) {
                son[x][w]=++tot;
                dph[tot]=i+1;
            }
            x=son[x][w];
        }
        sum[x]++;
        return x;
    }
    void MakeFail() {
        int h=1,t=0,i,j,x;
        for (i=0;i<Csize;i++) {
            if (son[0][i]) q[++t]=son[0][i];
        }
        while (h<=t) {
            for (x=q[h++],i=0;i<Csize;i++) {
                if (son[x][i]) {
                    fail[son[x][i]]=son[fail[x]][i];
                    q[++t]=son[x][i];
                } else {
                    son[x][i]=son[fail[x]][i];
                }
            }
        }
    }
    void Cal(int m) {
        int INF=0x3f3f3f3f;
        memset(dp,-INF,sizeof(dp));
        dp[0][0]=0;
        for (int i=0;i<m;i++) {
            for (int j=0;j<=tot;j++) {
                for (int c=0;c<Csize;c++) {
                    dp[i+1][son[j][c]]=max(dp[i+1][son[j][c]],dp[i][j]+sum[son[j][c]]);
                }
            }
        }
        printf("%d\n",*max_element(dp[m],dp[m]+tot+1));
    }
}

char s[111];
int main()
{
    int n;
    ll m;
    scanf("%d%lld",&n,&m);
    AC_DFA::Initialize();
    for (int i=1;i<=n;i++) {
        scanf("%s",s);
        AC_DFA::Insert(s);
    }
    AC_DFA::MakeFail();
    AC_DFA::Cal(m);
    return 0;
}
