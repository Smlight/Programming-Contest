#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;
set<ll> alls;
int n;
int a[30];

void dfs(int k,ll s)
{
    if (k>n) {
        alls.insert(s);
        return;
    }
    dfs(k+1,s+a[k]);
    dfs(k+1,s-a[k]);
}

int main()
{
    while (scanf("%d",&n)!=EOF) {
        alls.clear();
        for (int i=1;i<=n;i++) {
            scanf("%d",a+i);
        }
        dfs(1,0);
        printf("%d\n",alls.size());
    }
    return 0;
}
