#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m,cas=0;
    while (scanf("%d",&m)!=EOF) {
        int ans=m*log(2)/log(10);
        printf("Case #%d: %d\n",++cas,ans);
    }
    return 0;
}
