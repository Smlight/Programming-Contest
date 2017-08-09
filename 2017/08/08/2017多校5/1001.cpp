#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=50005;
int a[N],b[N],k[N],ans[N];
bool bb[N],isk[N];
bitset<N> mul,A;

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        mul.reset();
        A.reset();
        memset(bb,0,sizeof(bb));
        memset(isk,0,sizeof(isk));
        int n,m,q,mm=0;
        scanf("%d%d%d",&n,&m,&q);
        for (int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
            A.set(a[i]);
        }
        for (int i=1;i<=m;i++) {
            scanf("%d",&b[i]);
            mm=max(b[i],mm);
            bb[b[i]]=true;
        }
        for (int i=1;i<=q;i++) {
            scanf("%d",&k[i]);
            isk[k[i]]=true;
        }
        for (int i=mm;i>=0;i--) {
            if (isk[i]) {
                ans[i]=(mul&(A>>i)).count()&1;
            }
            if (bb[i]) {
                for (int j=0;j<=mm;j+=i) {
                    mul.flip(j);
                }
            }
        }
        for (int i=1;i<=q;i++) {
            printf("%d\n",ans[k[i]]);
        }
    }
    return 0;
}
