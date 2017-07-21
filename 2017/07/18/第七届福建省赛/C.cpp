#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;

const int N=10010;
int a[N*2];

int main()
{
    int T,cas=0;
    scanf("%d",&T);
    while (T--) {
        int n;
        scanf("%d",&n);
        n<<=1;
        for (int i=0;i<n;i++) {
            scanf("%d",a+i);
        }
//        sort(a,a+n);
        double ans=0;
        for (int i=0;i<n;i++) {
            ans+=0.5*i/(n-1);
        }
        printf("Case %d: %.2f\n",++cas,ans);
    }
    return 0;
}
