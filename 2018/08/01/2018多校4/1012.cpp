#include <bits/stdc++.h>
using namespace std;

const int N=100010;
int w[N];

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++) {
            scanf("%d",&w[i]);
        }
        int ans=sqrt(abs(w[1]-w[n]));
        printf("%d\n",ans);
    }
    return 0;
}