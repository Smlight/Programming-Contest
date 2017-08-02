#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=5e5+5;
int p[N],L[N],R[N];
int lq[99],rq[99];

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        int n,k;
        scanf("%d%d",&n,&k);
        for (int i=1;i<=n;++i) {
            int x;
            scanf("%d",&x);
            p[x]=i;
            L[i]=i-1;
            R[i]=i+1;
        }
        L[0]=0;
        R[n+1]=n+1;
        ll ans=0;
        for (int i=1;i<=n;i++) {
            int ltop=0,rtop=0;
            for (int pos=p[i];ltop<=k;pos=L[pos]) {
                lq[++ltop]=pos-L[pos];
            }
            for (int pos=p[i];rtop<=k;pos=R[pos]) {
                rq[++rtop]=R[pos]-pos;
            }
            for (int j=1;j<=ltop;j++) {
                if (k+1-j<=rtop) {
                    ans+=1LL*i*lq[j]*rq[k+1-j];
                }
            }
            R[L[p[i]]]=R[p[i]];
            L[R[p[i]]]=L[p[i]];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
