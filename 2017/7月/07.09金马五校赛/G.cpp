#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> PII;
const int N=10;
int a_h[N],a_a[N],b_h[N],b_a[N];
int c[N],d[N],e[N];

int main()
{
    int T,n;
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (int i=0;i<n;i++) {
            scanf("%d%d",&a_h[i],&a_a[i]);
        }
        for (int i=0;i<n;i++) {
            scanf("%d%d",&b_h[i],&b_a[i]);
            c[i]=i;
        }
        int ans=0;
        do {
            int i=0,j=0;
            int h1=a_h[i],h2=b_h[c[j]];
            while (i<n&&j<n) {
                int c1=(h1-1)/b_a[c[j]]+1;
                int c2=(h2-1)/a_a[i]+1;
                if (c1==c2) {
                    h1=a_h[++i];
                    h2=b_h[c[++j]];
                } else if (c1<c2) {
                    h2-=c1*a_a[i];
                    h1=a_h[++i];
                } else {
                    h1-=c2*b_a[c[j]];
                    h2=b_h[c[++j]];
                }
            }
            if (j<n) {
                ans=1;
                break;
            }
        } while (next_permutation(c,c+n));
        puts(ans?"YES":"NO");
    }
    return 0;
}
