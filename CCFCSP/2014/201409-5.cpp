#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int lim=1<<m;
    for (int S=0;S<lim;S++) dfs(S,S,0);
    return 0;
}
