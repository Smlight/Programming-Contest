#include <bits/stdc++.h>
using namespace std;

const int N=110000,INF=1<<29;
int q[N],a[N],L[N],R[N];
int T,n;

inline void del(int x)
{
    L[R[x]]=L[x];
    R[L[x]]=R[x];
    L[x]=0;R[x]=n+1;
}

int main()
{
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
            L[i]=i-1;
            R[i]=i+1;
        }
        L[0]=0;
        R[0]=1;
        L[n+1]=n;
        R[n+1]=n+1;
        a[0]=-INF;
        a[n+1]=INF;
        int r=0;
        for (int i=1;i<=n;) {
            while (i<=n&&a[i]<=a[i+1]) i++;
            if (i>n) break;
            q[++r]=i;
            while (i<=n&&a[i]>a[i+1]) i++;
        }
        for (int l=1;l<=r;l++) {
            int i=q[l];
            while (i<=n&&a[i]>a[R[i]]) i=R[i];
            if (i==q[l]) continue;//要删除的位置已经不成立
            while (i>=q[l]) {
                i=L[i];
                del(R[i]);
            }
            if (i&&a[i]>a[R[i]]) q[++r]=i;
        }
        r=0;
        for (int i=R[0];i<=n;i=R[i]) {
            q[++r]=a[i];
        }
        printf("%d\n",r);
        for (int i=1;i<=r;i++) {
            printf("%d ",q[i]);
        }
        puts("");
    }
    return 0;
}
