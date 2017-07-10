#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;
const int N=100010;
PII a[N];
int T,n,m;

int cnt(int w)
{
    int sum=0,res=0;
    for (int i=1;i<=n;i++) {
        if (a[i].second>=w) {
            sum+=a[i].first;
            if (sum<=m) {
                res++;
            } else {
                break;
            }
        }
    }
    return res;
}

int bs(int l,int r,int t)
{
    int res=-1;
    while (l<=r) {
        int m=(l+r)>>1;
        if (cnt(m)>=t) {
            res=m;l=m+1;
        } else {
            r=m-1;
        }
    }
    return res;
}

int main()
{
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++) {
            int x,y;
            scanf("%d%d",&x,&y);
            a[i]=PII(y,x);
        }
        sort(a+1,a+n+1);
        int tot=cnt(0);
        printf("%d %d\n",tot,bs(1,10000,tot));
    }
    return 0;
}
