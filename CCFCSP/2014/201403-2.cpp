#include <bits/stdc++.h>
using namespace std;

int a[22],b[22],c[22],d[22],id[22];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=n-1;i>=0;i--) {
        scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
        id[i]=n-i;
    }
    while (m--) {
        int p=-1,x,y;
        scanf("%d%d",&x,&y);
        for (int i=0;i<n;i++) {
            if (a[i]<=x&&x<=c[i]&&b[i]<=y&&y<=d[i]) {
                p=i;
                break;
            }
        }
        if (p==-1) {
            puts("IGNORED");
        } else {
            printf("%d\n",id[p]);
            int x=a[p],y=b[p],z=c[p],w=d[p],u=id[p];
            for (int i=p;i>0;i--) {
                a[i]=a[i-1];
                b[i]=b[i-1];
                c[i]=c[i-1];
                d[i]=d[i-1];
                id[i]=id[i-1];
            }
            a[0]=x;b[0]=y;c[0]=z;d[0]=w;id[0]=u;
        }
    }
    return 0;
}
