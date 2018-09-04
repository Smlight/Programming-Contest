#include <bits/stdc++.h>
using namespace std;
using PII = pair<int,int>;

const int N=9;
const int inf=2e9;
int a[N],b[N];
PII va[2],vb[2];

int sgn()
{
    if (va[0]<vb[0]) return 1;
    if (va[0]>vb[0]) return -1;
    if (va[1]<vb[1]) return 1;
    if (va[1]>vb[1]) return -1;
    return 0;
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=0;i<n;i++) {
            scanf("%d",&a[i]);
        }
        for (int i=0;i<m;i++) {
            scanf("%d",&b[i]);
        }
        if (n==3) {
            va[0]={a[2],a[1]+1};
            if (va[0].first>va[0].second) swap(va[0].first,va[0].second);
            va[1]={a[0]+2,inf};
        } else if (n==2) {
            va[0]={a[0]+2,inf};
            va[1]={a[1]+1,inf};
        } else {
            va[0]={a[0]+2,inf};
            va[1]={inf,inf};
        }
        if (m==3) {
            vb[0]={b[2],b[1]+1};
            if (vb[0].first>vb[0].second) swap(vb[0].first,vb[0].second);
            vb[1]={b[0]+2,inf};
        } else if (m==2) {
            vb[0]={b[0]+2,inf};
            vb[1]={b[1]+1,inf};
        } else {
            vb[0]={b[0]+2,inf};
            vb[1]={inf,inf};
        }
        sort(va,va+2);
        sort(vb,vb+2);
        printf("%d\n",sgn());
    }
    return 0;
}