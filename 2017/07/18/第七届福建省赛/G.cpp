#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;

typedef long long ll;

int main()
{
    int T,cas=0;
    scanf("%d",&T);
    while (T--) {
        int n,ans=1;
        scanf("%d",&n);
        ll now=1;
        while (now<n) {
            now+=now+1;
            ans++;
        }
        printf("Case %d: %d\n",++cas,ans);
    }
    return 0;
}
