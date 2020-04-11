#include <bits/stdc++.h>
using namespace std;

const int N=105;
int a[N][N];

bool check_row(int a[][N],int n,int r)
{
    bool vis[n+1]={0};
    for (int i=1;i<=n;i++) {
        if (vis[a[r][i]]) return 1;
        vis[a[r][i]]=1;
    }
    return 0;
}
bool check_col(int a[][N],int n,int c)
{
    bool vis[n+1]={0};
    for (int i=1;i<=n;i++) {
        if (vis[a[i][c]]) return 1;
        vis[a[i][c]]=1;
    }
    return 0;
}

int main()
{
    int T,cas=0;
    scanf("%d",&T);
    while (T--) {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                scanf("%d",&a[i][j]);
            }
        }
        int ans1=0,ans2=0,ans3=0;
        for (int i=1;i<=n;i++) {
            ans1+=a[i][i];
            ans2+=check_row(a,n,i);
            ans3+=check_col(a,n,i);
        }
        printf("Case #%d: %d %d %d\n",++cas,ans1,ans2,ans3);
    }
    return 0;
}