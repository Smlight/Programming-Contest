#include <bits/stdc++.h>
using namespace std;

const int N=1010;
int a[N],cnt[N];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        for (int j=1;j<=m;j++) {
            int x;
            scanf("%d",&x);
            cnt[i]-=x;
        }
    }
    int sum=0;
    int p=1;
    for (int i=1;i<=n;i++) {
        sum+=a[i]-cnt[i];
        if (cnt[i]>cnt[p]) {
            p=i;
        }
    }
    printf("%d %d %d\n",sum,p,cnt[p]);
    return 0;
}
