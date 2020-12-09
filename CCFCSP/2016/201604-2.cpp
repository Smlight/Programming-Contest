#include <bits/stdc++.h>
using namespace std;

const int N=20;
const int n=15,m=10,k=4;
int mp[N][N],a[N][N];

bool ok(int x,int y)
{
    for (int i=1;i<=k;i++) {
        for (int j=1;j<=k;j++) {
            if (a[i][j]) {
                if (x+i-1>n) return false;
                if (mp[x+i-1][y+j-1]) return false;
            }
        }
    }
    return true;
}

int main()
{
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            scanf("%d",&mp[i][j]);
        }
    }
    for (int i=1;i<=k;i++) {
        for (int j=1;j<=k;j++) {
            scanf("%d",&a[i][j]);
        }
    }
    int col;
    scanf("%d",&col);
    int ans=1;
    while (ok(ans,col)) ++ans;
    --ans;
    for (int i=1;i<=k;i++) {
        for (int j=1;j<=k;j++) {
            mp[i+ans-1][j+col-1]|=a[i][j];
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            printf("%d%c",mp[i][j]," \n"[j==m]);
        }
    }
    return 0;
}
