#include <bits/stdc++.h>
using namespace std;

const int N=100010;
const int MO=998244353;
int fac[N*2],inv[N*2],fnv[N*2];

inline void add(int&a,int b){a=a+b<MO?a+b:a+b-MO;}
inline void sub(int&a,int b){a=a-b>=0?a-b:a-b+MO;}

int C(int n,int m)
{
    return 1LL*fac[n]*fnv[m]%MO*fnv[n-m]%MO;
}

int main()
{
    inv[0]=inv[1]=1;
    for (int i=2;i<N*2;i++) {
        inv[i]=MO-1LL*MO/i*inv[MO%i]%MO;
    }
    fac[0]=fnv[0]=1;
    for (int i=1;i<N*2;i++) {
        fac[i]=1LL*fac[i-1]*i%MO;
        fnv[i]=1LL*fnv[i-1]*inv[i]%MO;
    }
    int T;
    scanf("%d",&T);
    while (T--) {
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        int ans=0,d=1;
        for (int i=0;i<=m;i++) {
            if (d>0) add(ans,1LL*C(m,i)*C(k+m-1,m-1)%MO);
            else sub(ans,1LL*C(m,i)*C(k+m-1,m-1)%MO);
            if ((k-=n)<0) break;
            d=-d;
        }
        printf("%d\n",ans);
    }
    return 0;
}