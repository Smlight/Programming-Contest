#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,ans=0;
    scanf("%d",&n);
    n/=10;
    ans+=n/5*7;
    n%=5;
    ans+=n/3*4;
    n%=3;
    ans+=n;
    printf("%d\n",ans);
    return 0;
}
