#include <bits/stdc++.h>
using namespace std;

const int N=100010;
struct Node {
    int v,id;
} a[N];
int b[N];

bool cmp1(const Node &a,const Node &b)
{
    return a.v>b.v;
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++) {
            scanf("%d",&a[i].v);
            a[i].id=i;
        }
        sort(a+1,a+1+n,cmp1);
        memset(b,0,sizeof(b));
        for (int j=1;j<=n;j++) {
            int f=0;
            for (int i=2;i<=n;i++) {
                if (i==2) {
                    while (i<=n&&b[i]) i++;
                    if (i>n) {
                        f=1;
                        break;
                    }
                } else {
                    while (i<=n&&b[i]) i++;
                    if (i>n) {
                        break;
                    }
                }
                if (a[j].id%i) {
                    b[i]=a[j].v;
                }
            }
            if (f) break;
        }
        for (int i=2;i<=n;i++) {
            printf("%d%c",b[i],(i==n)?'\n':' ');
        }
    }
    return 0;
}
