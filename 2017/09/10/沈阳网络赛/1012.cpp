#include <bits/stdc++.h>
using namespace std;

const int N=1e6+5;
int a[N<<1],sum[N<<1];

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF) {
        for (int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
            a[n+i]=a[i];
        }
        for (int i=1;i<=n;i++) {
            scanf("%d",&sum[i]);
            sum[i]=a[i]-sum[i];
            sum[n+i]=sum[i];
        }
        for (int i=1;i<=n+n;i++) {
            sum[i]=sum[i]+sum[i-1];
        }
        int ans=0,mx=0;
        int i=0,j=0;
        while (i<n) {
            int now=0;
            while (j-i<=n&&j<=n+n&&sum[j]-sum[i]>=0)  {
                now+=a[j++];
            }
            if (now>mx) {
                mx=now;
                ans=i;
                if (mx==sum[n]) break;
            }
            while (j-i>n) i++;
            while (i<j&&sum[j]-sum[i]<0) {
                i++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
