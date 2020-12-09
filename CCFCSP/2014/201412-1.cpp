#include <bits/stdc++.h>
using namespace std;

map<int,int> mp;

int main()
{
    int n,x;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        scanf("%d",&x);
        printf("%d%c",++mp[x]," \n"[i==n]);
    }
    return 0;
}
