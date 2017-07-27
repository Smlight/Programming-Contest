#include <bits/stdc++.h>
using namespace std;

const int N=80010;
char a[N],b[N];

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        int n,x,y;
        scanf("%d%d%d",&n,&x,&y);
        scanf("%s",a);
        scanf("%s",b);
        int same=0;
        for (int i=0;i<n;i++) {
            same+=(a[i]==b[i]);
        }
        int z=abs(y-x);
        if (z<=n-same&&x+y<=n+same) {
            puts("Not lying");
        } else {
            puts("Lying");
        }
    }
    return 0;
}
