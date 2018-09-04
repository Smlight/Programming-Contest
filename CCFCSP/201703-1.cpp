#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,x,y=0,ans=0;
    scanf("%d%d",&n,&k);
    for (int i=0;i<n;i++) {
        scanf("%d",&x);
        y+=x;
        if (y>=k) {
            ++ans;
            y=0;
        }
    }
    ans+=y>0;
    printf("%d\n",ans);
}
