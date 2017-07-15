#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

const int N=100010,INF=1<<30;
int a[N],sum[N];

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF) {
        int ans=0;
        for (int i=1;i<=n;i++) {
            scanf("%d",a+i);
            ans+=a[i];
        }
        for (int i=1;i<=n;i++) {
            if (a[i]) {
                sum[i]=sum[i-1]-1;
            } else {
                sum[i]=sum[i-1]+1;
            }
        }
        int mm=0,res=-INF;
        for (int i=1;i<=n;i++) {
            if (sum[i]-mm>res) {
                res=sum[i]-mm;
            }
            mm=min(mm,sum[i]);
        }
        printf("%d\n",ans+res);
    }
    return 0;
}
