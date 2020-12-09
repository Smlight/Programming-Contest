#include <bits/stdc++.h>
using namespace std;

const int MO=1000000007;
long long C[1010][1010];

int main()
{
    for (int i=0;i<=1000;i++) {
        C[i][0]=1;
        for (int j=1;j<=i;j++) {
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%MO;
        }
    }
    int n;
    scanf("%d",&n);
    long long ans=0;
    for (int i=2;i<=n-2;i++) {
        ans+=C[n-1][i]*(i-1)%MO*(n-i-1)%MO;
        ans%=MO;
    }
    printf("%lld\n",ans);
    return 0;
}
