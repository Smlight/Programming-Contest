#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN=666;
int M[MAXN][MAXN],cols[MAXN],rows[MAXN];
int A[105];
int T, L, S;

ll query(int xa, int ya, int xb, int yb)
{
    ll res=0;
//    for (int i=xa;i<=xb;i++) {
//        for (int j=ya;j<=yb;j++) {
//            res+=M[i%L][j%L];
//        }
//    }
    ll BlockRows=0,BlockCols=0;
    if (ya/L==yb/L) {
        for (int j=(ya%L);j<=(yb%L);j++) {
            BlockRows+=cols[j];
        }
    } else {
        for (int j=(ya%L);j<L;j++) {
            BlockRows+=cols[j];
        }
        for (int j=0;j<=(yb%L);j++) {
            BlockRows+=cols[j];
        }
        if (ya/L+1<yb/L) {
            BlockRows+=(ll)(yb/L-ya/L-1)*S;
        }
    }
    res+=max(xb/L-xa/L-1,0)*BlockRows;
//    printf("%lld\n",res);
    if (xa/L==xb/L) {
        for (int i=(xa%L);i<=(xb%L);i++) {
            BlockCols+=rows[i];
        }
    } else {
        for (int i=(xa%L);i<L;i++) {
            BlockCols+=rows[i];
        }
        for (int i=0;i<=(xb%L);i++) {
            BlockCols+=rows[i];
        }
    }
    res+=max(yb/L-ya/L-1,0)*BlockCols;
//    printf("%lld\n",res);
    if (xa/L==xb/L) {
        if (ya/L==yb/L) {
            for (int i=xa%L;i<=xb%L;i++) {
                for (int j=ya%L;j<=yb%L;j++) {
                    res+=M[i][j];
                }
            }
        } else {
            for (int i=xa%L;i<=xb%L;i++) {
                for (int j=ya%L;j<L;j++) {
                    res+=M[i][j];
                }
                for (int j=0;j<=yb%L;j++) {
                    res+=M[i][j];
                }
            }
        }
    } else {
        if (ya/L==yb/L) {
            for (int i=xa%L;i<L;i++) {
                for (int j=ya%L;j<=yb%L;j++) {
                    res+=M[i][j];
                }
            }
            for (int i=0;i<=xb%L;i++) {
                for (int j=ya%L;j<=yb%L;j++) {
                    res+=M[i][j];
                }
            }
        } else {
            for (int i=xa%L;i<L;i++) {
                for (int j=ya%L;j<L;j++) {
                    res+=M[i][j];
                }
                for (int j=0;j<=yb%L;j++) {
                    res+=M[i][j];
                }
            }
            for (int i=0;i<=xb%L;i++) {
                for (int j=ya%L;j<L;j++) {
                    res+=M[i][j];
                }
                for (int j=0;j<=yb%L;j++) {
                    res+=M[i][j];
                }
            }
        }
    }
    return res;
}

int main()
{
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &L);
        for(int i = 0; i < L; ++i) {
            //A[i] = i + 1;
            scanf("%d", &A[i]);
        }
        int cursor = 0;
        for (int i = 0; i < 600; ++i) {
            for (int j = 0; j <= i; ++j) {
                M[j][i - j] = A[cursor];
                cursor = (cursor + 1) % L;
            }
        }
        L*=2;
        S=0;
        memset(rows,0,sizeof(rows));
        memset(cols,0,sizeof(cols));
        for (int i=0;i<L;i++) {
            for (int j=0;j<L;j++) {
                S+=M[i][j];
                rows[i]+=M[i][j];
                cols[j]+=M[i][j];
            }
        }
        int q;
        scanf("%d",&q);
        while (q--) {
            int a,b,c,d;
            scanf("%d%d%d%d",&a,&b,&c,&d);
            printf("%lld\n",query(a,b,c,d));
        }
    }
    return 0;
}