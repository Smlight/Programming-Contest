#include <bits/stdc++.h>
using namespace std;

const int N=100010;
int sta[N],dp[N],nxt[N],lft[N];
bool on[N];
int h[N];

struct ST {
    //1 base, query O(1)
    int dp[N][20];
    int n;

    void make(int _n) {
        n = _n;
        for(int i = 1; i <= n; ++i) {
            dp[i][0] = h[i];
        }
        for(int j = 1; (1 << j) <= n; ++j) {
            for(int i = 1; (i + (1 << (j - 1))) <= n; ++i) {
                dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int query(int l, int r) {
        int k = 31 - __builtin_clz(r - l + 1);
        return max(dp[l][k], dp[r - (1 << k) + 1][k]);
    }
} st;

int bs(int l,int r,int x)
{
    int res=-1;
    int a=l,b=r;
    while (l<=r) {
        int m=(l+r)>>1;
        if (st.query(a,m)>x) {
            res=m;
            r=m-1;
        } else {
            l=m+1;
        }
    }
    return res;
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        int n,m;
        scanf("%d%d",&n,&m);
        int t=0;
        for (int i=1;i<=n;i++) {
            scanf("%d",&h[i]);
//            q[++t]=h[i];
        }
        memset(on,0,sizeof on);
        memset(dp,0,sizeof dp);
        memset(nxt,0,sizeof nxt);
        memset(lft,0,sizeof lft);
        int top=0;
        sta[++top]=n+1;
        h[n+1]=2e9;
        dp[n+1]=0;
        st.make(n+1);
        for (int i=n;i>=1;i--) {
            while (h[sta[top]]<=h[i]) {
                --top;
            }
            nxt[i]=sta[top];
            dp[i]=dp[nxt[i]]+1;
            sta[++top]=i;
        }
//        puts("NXT: ");
//        for (int i=1;i<=n;i++) {
//            printf("%d ",nxt[i]);
//        }
//        puts("");
//        puts("DP: ");
//        for (int i=1;i<=n;i++) {
//            printf("%d ",dp[i]);
//        }
//        puts("");
        for (int i=1;i<=n;i=nxt[i]) {
            on[i]=true;
        }
        int pre=0;
        for (int i=1;i<=n;i++) {
            lft[i]=pre;
            if (on[i]) pre=i;
        }
//        puts("LEFT: ");
//        for (int i=1;i<=n;i++) {
//            printf("%d ",lft[i]);
//        }
//        puts("");
        for (int i=1;i<=m;i++) {
            int x,y;
            scanf("%d%d",&x,&y);
            if (!on[x]) {
                if (y<=h[lft[x]]) {
                    printf("%d\n",dp[1]);
                } else {
                    int np=bs(x+1,n+1,y);
                    assert(np!=-1);
                    printf("%d\n",dp[1]-dp[lft[x]]+1+dp[np]+1);
                }
            } else {
                if (y>h[x]) {
                    int np=bs(x+1,n+1,y);
                    assert(np!=-1);
                    printf("%d\n",dp[1]-dp[x]+1+dp[np]);
                } else {
                    if (x==1) {
                        int np=bs(x+1,n+1,y);
                        assert(np!=-1);
                        printf("%d\n",1+dp[np]);
                    } else if (y>h[lft[x]]) {
                        int np=bs(x+1,n+1,y);
                        assert(np!=-1);
                        printf("%d\n",dp[1]-dp[x]+1+dp[np]);
                    } else {
                        int np=bs(x+1,n+1,h[lft[x]]);
                        assert(np!=-1);
                        printf("%d\n",dp[1]-dp[lft[x]]+1+dp[np]);
                    }
                }
            }
        }
//        sort(q+1,q+t+1);
//        t=unique(q+1,q+t+1)-q-1;
    }
    return 0;
}