#include <bits/stdc++.h>
using namespace std;

const int N=1010;
int a[N];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) a[i]=i;
    while (m--) {
        int x,y;
        scanf("%d%d",&x,&y);
        int p=1;
        while (a[p]!=x) ++p;
        if (y<0) {
            for (int i=p;i>p+y;i--) {
                a[i]=a[i-1];
            }
            a[p+y]=x;
        } else if (y>0) {
            for (int i=p;i<p+y;i++) {
                a[i]=a[i+1];
            }
            a[p+y]=x;
        }
    }
    for (int i=1;i<=n;i++) {
        printf("%d%c",a[i]," \n"[i==n]);
    }
    return 0;
}
